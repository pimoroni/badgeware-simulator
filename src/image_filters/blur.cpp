

#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#include "../image.hpp"


namespace picovector {

// ---- Packed RGBA helpers (little-endian, bytes in memory are R,G,B,A) ----
static inline uint8_t R(uint32_t p){ return (uint8_t)(p & 0xFF); }
static inline uint8_t G(uint32_t p){ return (uint8_t)((p >> 8) & 0xFF); }
static inline uint8_t B(uint32_t p){ return (uint8_t)((p >> 16) & 0xFF); }
static inline uint8_t A(uint32_t p){ return (uint8_t)((p >> 24) & 0xFF); }
static inline uint32_t packRGBA(uint8_t r,uint8_t g,uint8_t b,uint8_t a){
    return (uint32_t)r | ((uint32_t)g<<8) | ((uint32_t)b<<16) | ((uint32_t)a<<24);
}
static inline int clampi(int v, int lo, int hi){ return v < lo ? lo : (v > hi ? hi : v); }

// Fixed-point reciprocal: out = sum / N  =>  out ≈ (sum * invN + 0x8000) >> 16
static inline uint8_t div_u32_by_u16_round(uint32_t sum, uint32_t invN_q16) {
    return (uint8_t)((sum * invN_q16 + 0x8000u) >> 16);
}

// Horizontal 1D box blur of a single row (RGBA packed), using sliding window.
// srcRow and dstRow may be different. radius >= 1.
static void blur_row_box_rgba(
    const uint32_t* srcRow, uint32_t* dstRow, int width, int radius, uint32_t invN_q16, bool blur_alpha)
{
    const int N = radius * 2 + 1;

    // init window centered at x=0 with clamp
    uint32_t sumR=0,sumG=0,sumB=0,sumA=0;
    for (int i = -radius; i <= radius; ++i) {
        int xi = clampi(i, 0, width - 1);
        uint32_t p = srcRow[xi];
        sumR += R(p); sumG += G(p); sumB += B(p); sumA += A(p);
    }

    // x = 0
    {
        uint32_t p0 = srcRow[0];
        uint8_t r = div_u32_by_u16_round(sumR, invN_q16);
        uint8_t g = div_u32_by_u16_round(sumG, invN_q16);
        uint8_t b = div_u32_by_u16_round(sumB, invN_q16);
        uint8_t a = blur_alpha ? div_u32_by_u16_round(sumA, invN_q16) : A(p0);
        dstRow[0] = packRGBA(r,g,b,a);
    }

    // slide
    for (int x = 1; x < width; ++x) {
        int x_add = clampi(x + radius,     0, width - 1);
        int x_sub = clampi(x - radius - 1, 0, width - 1);

        uint32_t pAdd = srcRow[x_add];
        uint32_t pSub = srcRow[x_sub];

        sumR += (uint32_t)R(pAdd) - (uint32_t)R(pSub);
        sumG += (uint32_t)G(pAdd) - (uint32_t)G(pSub);
        sumB += (uint32_t)B(pAdd) - (uint32_t)B(pSub);
        sumA += (uint32_t)A(pAdd) - (uint32_t)A(pSub);

        uint32_t pSrc = srcRow[x];
        uint8_t r = div_u32_by_u16_round(sumR, invN_q16);
        uint8_t g = div_u32_by_u16_round(sumG, invN_q16);
        uint8_t b = div_u32_by_u16_round(sumB, invN_q16);
        uint8_t a = blur_alpha ? div_u32_by_u16_round(sumA, invN_q16) : A(pSrc);

        dstRow[x] = packRGBA(r,g,b,a);
    }
}

// In-place separable box blur using:
// - 1 row scratch for horizontal
// - (radius+1) row ring buffer for vertical output (needed to avoid corrupting input)
// - per-column running sums for vertical
//
// Memory roughly:
//   rowScratch: width*4
//   ring: (radius+1)*width*4
//   colSums: width * 4 * 4 bytes  (R,G,B,A sums as u32)
// If blur_alpha=false, A sum still computed cheaply here; you can remove it if you want.
void image_t::blur(int radius, bool blur_alpha) {
    if (radius <= 0) return;

    int width = _bounds.w;
    int height = _bounds.w;
    uint8_t *pixels = (uint8_t*)_buffer;
    int stride = _row_stride;

    const int N = radius * 2 + 1;
    // Q16 reciprocal of N (rounded)
    const uint32_t invN_q16 = (uint32_t)(( (1u << 16) + (uint32_t)(N/2) ) / (uint32_t)N);

    // --- Allocate scratch ---
    uint32_t* rowScratch = (uint32_t*)std::malloc((size_t)width * sizeof(uint32_t));
    uint32_t* ring = (uint32_t*)std::malloc((size_t)(radius + 1) * (size_t)width * sizeof(uint32_t));
    uint32_t* sumR = (uint32_t*)std::malloc((size_t)width * sizeof(uint32_t));
    uint32_t* sumG = (uint32_t*)std::malloc((size_t)width * sizeof(uint32_t));
    uint32_t* sumB = (uint32_t*)std::malloc((size_t)width * sizeof(uint32_t));
    uint32_t* sumA = (uint32_t*)std::malloc((size_t)width * sizeof(uint32_t));

    if (!rowScratch || !ring || !sumR || !sumG || !sumB || !sumA) {
        std::free(rowScratch); std::free(ring);
        std::free(sumR); std::free(sumG); std::free(sumB); std::free(sumA);
        return;
    }

    // --- Pass 1: Horizontal (in-place via 1 row scratch) ---
    for (int y = 0; y < height; ++y) {
        uint32_t* row = (uint32_t*)(pixels + (size_t)y * (size_t)stride);
        blur_row_box_rgba(row, rowScratch, width, radius, invN_q16, blur_alpha);
        std::memcpy(row, rowScratch, (size_t)width * sizeof(uint32_t));
    }

    // --- Pass 2: Vertical (needs delayed writeback) ---
    // Initialize column sums for center y=0: sum rows [-r..+r] clamped
    std::memset(sumR, 0, (size_t)width * sizeof(uint32_t));
    std::memset(sumG, 0, (size_t)width * sizeof(uint32_t));
    std::memset(sumB, 0, (size_t)width * sizeof(uint32_t));
    std::memset(sumA, 0, (size_t)width * sizeof(uint32_t));

    for (int ky = -radius; ky <= radius; ++ky) {
        int yi = clampi(ky, 0, height - 1);
        const uint32_t* row = (const uint32_t*)(pixels + (size_t)yi * (size_t)stride);
        for (int x = 0; x < width; ++x) {
            uint32_t p = row[x];
            sumR[x] += R(p); sumG[x] += G(p); sumB[x] += B(p); sumA[x] += A(p);
        }
    }

    // Process each output row y
    for (int y = 0; y < height; ++y) {
        // Write output row y into ring slot
        uint32_t* outRow = ring + (size_t)(y % (radius + 1)) * (size_t)width;

        // Compute blurred row from current column sums
        const uint32_t* srcRowForAlpha = (const uint32_t*)(pixels + (size_t)y * (size_t)stride);
        for (int x = 0; x < width; ++x) {
            uint8_t r = div_u32_by_u16_round(sumR[x], invN_q16);
            uint8_t g = div_u32_by_u16_round(sumG[x], invN_q16);
            uint8_t b = div_u32_by_u16_round(sumB[x], invN_q16);
            uint8_t a = blur_alpha ? div_u32_by_u16_round(sumA[x], invN_q16) : A(srcRowForAlpha[x]);
            outRow[x] = packRGBA(r,g,b,a);
        }

        // Update sums to move center to y+1
        // Add row (y + r + 1), subtract row (y - r)
        int y_add = clampi(y + radius + 1, 0, height - 1);
        int y_sub = clampi(y - radius,     0, height - 1);

        const uint32_t* rowAdd = (const uint32_t*)(pixels + (size_t)y_add * (size_t)stride);
        const uint32_t* rowSub = (const uint32_t*)(pixels + (size_t)y_sub * (size_t)stride);

        for (int x = 0; x < width; ++x) {
            uint32_t pa = rowAdd[x];
            uint32_t ps = rowSub[x];
            sumR[x] += (uint32_t)R(pa) - (uint32_t)R(ps);
            sumG[x] += (uint32_t)G(pa) - (uint32_t)G(ps);
            sumB[x] += (uint32_t)B(pa) - (uint32_t)B(ps);
            sumA[x] += (uint32_t)A(pa) - (uint32_t)A(ps);
        }

        // Safe writeback: after updating sums, row (y - radius) will never be needed again as input
        if (y >= radius) {
            int y_write = y - radius;
            uint32_t* dst = (uint32_t*)(pixels + (size_t)y_write * (size_t)stride);
            uint32_t* src = ring + (size_t)(y_write % (radius + 1)) * (size_t)width;
            std::memcpy(dst, src, (size_t)width * sizeof(uint32_t));
        }
    }

    // Flush remaining rows (height - radius .. height-1)
    for (int y_write = std::max(0, height - radius); y_write < height; ++y_write) {
        uint32_t* dst = (uint32_t*)(pixels + (size_t)y_write * (size_t)stride);
        uint32_t* src = ring + (size_t)(y_write % (radius + 1)) * (size_t)width;
        std::memcpy(dst, src, (size_t)width * sizeof(uint32_t));
    }

    std::free(rowScratch); std::free(ring);
    std::free(sumR); std::free(sumG); std::free(sumB); std::free(sumA);
}








  // // One-pole lowpass step: y += (x - y) * k
  // // k is Q16: 0..65535 ~ 0..(almost 1.0)
  // static inline int iir_step_q16(int y, int x, uint32_t k_q16) {
  //     int diff = x - y;
  //     // y += diff * k
  //     y += (int)((diff * (int32_t)k_q16) >> 16);
  //     return y;
  // }

  // // Compute k in Q16 from a "radius"/strength parameter.
  // // radius <= 0 => no blur.
  // static inline uint32_t blur_k_from_radius_q16(float radius) {
  //     if (radius <= 0) return 0;

  //     // Mapping: a = exp(-1/(r+1)), k = 1-a
  //     // Bigger radius => smaller k => stronger smoothing.
  //     float r = (float)radius;
  //     float a = std::exp(-1.0f / (r + 1.0f));
  //     float k = 1.0f - a;

  //     // Clamp to [0, 0.9999] to avoid weirdness at extremes
  //     if (k < 0.0f) k = 0.0f;
  //     if (k > 0.9999f) k = 0.9999f;

  //     return (uint32_t)std::lround(k * 65536.0f);
  // }


  // void image_t::blur(float radius) {
  //   if (radius <= 0) return;

  //   const uint32_t k = blur_k_from_radius_q16(radius);
  //   if (k == 0) return;

  //   int width = int(_bounds.w);
  //   int height = int(_bounds.h);

  //   // ---- Horizontal pass: forward + backward (symmetric-ish) ----
  //   for (int y = 0; y < height; ++y) {
  //       uint8_t* row = (uint8_t*)_buffer + (size_t)y * (size_t)_row_stride;

  //       // Forward: left -> right
  //       int r = row[0], g = row[1], b = row[2], a = row[3];
  //       for (int x = 1; x < width; ++x) {
  //           uint8_t* p = row + x * 4;
  //           r = iir_step_q16(r, p[0], k);
  //           g = iir_step_q16(g, p[1], k);
  //           b = iir_step_q16(b, p[2], k);
  //           a = iir_step_q16(a, p[3], k);
  //           p[0] = (uint8_t)r;
  //           p[1] = (uint8_t)g;
  //           p[2] = (uint8_t)b;
  //           p[3] = (uint8_t)a;
  //       }

  //       // Backward: right -> left
  //       uint8_t* pr = row + (width - 1) * 4;
  //       r = pr[0]; g = pr[1]; b = pr[2]; a = pr[3];
  //       for (int x = width - 2; x >= 0; --x) {
  //           uint8_t* p = row + x * 4;
  //           r = iir_step_q16(r, p[0], k);
  //           g = iir_step_q16(g, p[1], k);
  //           b = iir_step_q16(b, p[2], k);
  //           a = iir_step_q16(a, p[3], k);
  //           p[0] = (uint8_t)r;
  //           p[1] = (uint8_t)g;
  //           p[2] = (uint8_t)b;
  //           p[3] = (uint8_t)a;
  //       }
  //   }

  //   // ---- Vertical pass: forward + backward (in-place, per column) ----
  //   for (int x = 0; x < width; ++x) {
  //       uint8_t* p0 = (uint8_t*)_buffer + x * 4;

  //       // Forward: top -> bottom
  //       int r = p0[0], g = p0[1], b = p0[2], a = p0[3];
  //       for (int y = 1; y < height; ++y) {
  //           uint8_t* p = (uint8_t*)_buffer + (size_t)y * (size_t)_row_stride + x * 4;
  //           r = iir_step_q16(r, p[0], k);
  //           g = iir_step_q16(g, p[1], k);
  //           b = iir_step_q16(b, p[2], k);
  //           a = iir_step_q16(a, p[3], k);
  //           p[0] = (uint8_t)r;
  //           p[1] = (uint8_t)g;
  //           p[2] = (uint8_t)b;
  //           p[3] = (uint8_t)a;
  //       }

  //       // Backward: bottom -> top
  //       uint8_t* pb = (uint8_t*)_buffer + (size_t)(height - 1) * (size_t)_row_stride + x * 4;
  //       r = pb[0]; g = pb[1]; b = pb[2]; a = pb[3];
  //       for (int y = height - 2; y >= 0; --y) {
  //           uint8_t* p = (uint8_t*)_buffer + (size_t)y * (size_t)_row_stride + x * 4;
  //           r = iir_step_q16(r, p[0], k);
  //           g = iir_step_q16(g, p[1], k);
  //           b = iir_step_q16(b, p[2], k);
  //           a = iir_step_q16(a, p[3], k);
  //           p[0] = (uint8_t)r;
  //           p[1] = (uint8_t)g;
  //           p[2] = (uint8_t)b;
  //           p[3] = (uint8_t)a;
  //       }
  //   }
  // }

}