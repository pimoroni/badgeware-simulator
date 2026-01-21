#include "../brush.hpp"

namespace picovector {


  void color_brush_span_func(image_t *target, brush_t *brush, int x, int y, int w) {
    color_brush_t *p = (color_brush_t*)brush;
    uint32_t *dst = (uint32_t*)target->ptr(x, y);
    uint32_t src = p->c._p;
    uint32_t r = _r(src); uint32_t g = _g(src); uint32_t b = _b(src); uint32_t a = _a(src);

    blend_func_t fn = target->_blend_func;
    while(w--) {
      *dst = fn(*dst, r, g, b, a);
      dst++;
    }
  }

  void color_brush_masked_span_func(image_t *target, brush_t *brush, int x, int y, int w, uint8_t *mask) {
    color_brush_t *p = (color_brush_t*)brush;
    uint32_t *dst = (uint32_t*)target->ptr(x, y);
    uint32_t src = p->c._p;
    uint32_t r = _r(src); uint32_t g = _g(src); uint32_t b = _b(src); uint32_t a = _a(src);

    blend_func_t fn = target->_blend_func;
    while(w--) {
      uint32_t m = *mask;
      uint32_t sr = (r * m + 128) >> 8;
      uint32_t sg = (g * m + 128) >> 8;
      uint32_t sb = (b * m + 128) >> 8;
      uint32_t sa = (a * m + 128) >> 8;
      *dst = fn(*dst, sr, sg, sb, sa);
      dst++;
      mask++;
    }
  }

  color_brush_t::color_brush_t(const color_t& c) : c(c) {
  }

  span_func_t color_brush_t::span_func() {
    return color_brush_span_func;
  }

  masked_span_func_t color_brush_t::masked_span_func() {
    return color_brush_masked_span_func;
  }

}