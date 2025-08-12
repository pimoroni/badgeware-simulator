#include "image.hpp"

#include "span.hpp"

#include <string.h>
#include <math.h>

using namespace std;

image::image() {
}

image::image(int w, int h) : managed_buffer(true) {
  b = rect(0, 0, w, h);
  p = (uint32_t *)malloc(sizeof(uint32_t) * w * h);
  rs = w * sizeof(uint32_t);
}

image::image(uint32_t *p, int w, int h) : p(p), managed_buffer(false) {
  b = rect(0, 0, w, h);
  rs = w * sizeof(uint32_t);
}

image::~image() {
  if(managed_buffer) {
    free(p);
  }
}

image image::window(rect r) {
  image window = image();
  rect i = b.intersection(r);
  window.b = rect(0, 0, i.w, i.h);
  window.p = ptr(r.x, r.y);
  window.rs = rs;
  return window;
}

void image::clear(uint32_t c) {
  if(c == 0) {
    memset(p, 0, b.w * b.h * sizeof(uint32_t));
  }else{
    for(int y = 0; y < b.h; y++) {
      uint32_t *p = ptr(0, y);
      int i = b.w;
      while(i--) *p++ = c;
    }
  }
}

void image::blit(image &t, const point &p, int alpha) {
  rect tr(p.x, p.y, b.w, b.h); // target rect
  tr = tr.intersection(t.b); // clip to target image bounds

  if(tr.empty()) {return;}

  int sxo = p.x < 0 ? -p.x : 0;
  int syo = p.y < 0 ? -p.y : 0;

  for(int i = 0; i < tr.h; i++) {
    uint32_t *src = this->ptr(sxo, syo + i);
    uint32_t *dst = t.ptr(tr.x, tr.y + i);
    span_blit_argb8(src, dst, tr.w, alpha);
  }
}

void image::blit(image &t, rect r, int alpha) {
  rect cr = r.intersection(t.b); // get clipped target rect
  if(cr.empty()) {return;}

  // determine source bounds for clipped area in fp16:16 coordinates
  int fprw = (b.w << 16) / r.w;
  int fprh = (b.h << 16) / r.h;
  rect sr(
    -min(r.x, 0) * fprw,
    -min(r.y, 0) * fprh,
    cr.w * fprw,
    cr.h * fprh
  );

  for(int i = 0; i < cr.h; i++) {
    int so = (sr.y + (i * fprh)) >> 16;
    uint32_t *dst = t.ptr(cr.x, cr.y + i);
    span_blit_scale(this->ptr(0, so), dst, sr.x, sr.w, cr.w, alpha);
  }
}

uint32_t* image::ptr(int x, int y) {
  return this->p + x + (y * (this->rs / sizeof(uint32_t)));
}

void image::rectangle(rect r, uint32_t c) {
  r = r.intersection(b);
  for(int i = 0; i < r.h; i++) {
    uint32_t *p = ptr(r.x, r.y + i);
    span_argb8(p, r.w, c);
  }
}

void image::circle(point p, int r, uint32_t c) {
  int sy = max(p.y - r, 0);
  int ey = min(p.y + r, b.h);
  for(int y = sy; y < ey; y++) {
    int w = sqrt((r * r) - ((y - p.y) * (y - p.y)));
    int sx = p.x - w;
    int ex = p.x + w;
    if(ex < 0 || sx >= b.h) {continue;}
    sx = max(sx, 0);
    ex = min(ex, b.w);

    //printf("c: %d -> %d @ %d\n", sx, ex, y);
    span_argb8(ptr(sx, y), ex - sx, c);
  }
}

uint32_t image::pen(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
  uint32_t c;
  uint8_t *p = (uint8_t *)&c;
  p[0] = a; p[1] = r; p[2] = g; p[3] = b;
  return c;
}
