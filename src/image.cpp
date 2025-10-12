#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>

#include "image.hpp"
#include "span.hpp"
#include "brush.hpp"
#include "shape.hpp"

using std::vector;

namespace picovector {

  color_brush _default_image_brush(255, 255, 255, 255);

  image_t::image_t(int w, int h) : managed_buffer(true) {
    _bounds = rect_t(0, 0, w, h);
    _brush = &_default_image_brush;
    p = (uint32_t *)PV_MALLOC(sizeof(uint32_t) * w * h);
    _rowstride = w * sizeof(uint32_t);
  }

  image_t::image_t(uint32_t *p, int w, int h) : p(p), managed_buffer(false) {
    _bounds = rect_t(0, 0, w, h);    
    _brush = &_default_image_brush;
    _rowstride = w * sizeof(uint32_t);
  }

  image_t::~image_t() {
    if(managed_buffer) {
      //PV_FREE(p);
    }
  }

  rect_t image_t::bounds() {
    return this->_bounds;
  }

  uint8_t image_t::alpha() {
    return this->_alpha;
  }

  void image_t::alpha(uint8_t alpha) {
    // TODO: check if pixel format and palette mode supports alpha
    this->_alpha = alpha;
  }

  antialias_t image_t::antialias() {
    return this->_antialias;
  }

  void image_t::antialias(antialias_t antialias) {
    // TODO: check if pixel format and palette mode supports alpha
    this->_antialias = antialias;
  }

  pixel_format_t image_t::pixel_format() {
    return this->_pixel_format;
  }

  void image_t::pixel_format(pixel_format_t pixel_format) {
    this->_pixel_format = pixel_format;
  }

  mat3_t* image_t::transform() {
    return this->_transform;
  }

  void image_t::transform(mat3_t *transform) {
    this->_transform = transform;
  }

  brush_t* image_t::brush() {
    return this->_brush;
  }

  void image_t::brush(brush_t *brush) {
    this->_brush = brush;
  }

  font_t* image_t::font() {
    return this->_font;
  }

  void image_t::font(font_t *font) {
    this->_font = font;
  }

  image_t image_t::window(rect_t r) {
    rect_t i = _bounds.intersection(r);
    image_t window = image_t(ptr(r.x, r.y), i.w, i.h);
    window._rowstride = _rowstride;
    return window;
  }

  void image_t::window(image_t *source, rect_t r) {
    rect_t i = _bounds.intersection(r);
    this->p = source->ptr(i.x, i.y);
    this->_bounds = i;
    this->_rowstride = source->_rowstride;
  }

  void image_t::clear() {
    rectangle(_bounds);
  }

  void image_t::blit(image_t *t, const point_t p) {
    rect_t tr(p.x, p.y, _bounds.w, _bounds.h); // target rect
    tr = tr.intersection(t->_bounds); // clip to target image bounds

    if(tr.empty()) {return;}

    int sxo = p.x < 0 ? -p.x : 0;
    int syo = p.y < 0 ? -p.y : 0;    

    for(int i = 0; i < tr.h; i++) {
      uint32_t *src = this->ptr(sxo, syo + i);
      uint32_t *dst = t->ptr(tr.x, tr.y + i);
      span_blit_argb8(src, dst, tr.w, this->alpha());
    }
  }

  void image_t::blit(image_t *target, rect_t tr) {
    // clip the target rect to the target bounds
    rect_t ctr = tr.intersection(target->bounds());
    if(ctr.empty()) {return;}

    // calculate the source step
    float srcstepx = this->_bounds.w / tr.w;
    float srcstepy = this->_bounds.h / tr.h;

    // calculate the source offset
    float srcx = ctr.w < 0 ? this->_bounds.w : 0;
    float srcy = ctr.h < 0 ? this->_bounds.h : 0;
    srcx += (ctr.x - tr.x) * srcstepx;
    srcy += (ctr.y - tr.y) * srcstepy;

    int sy = min(ctr.y, ctr.y + ctr.h);
    int ey = max(ctr.y, ctr.y + ctr.h);


    for(int y = sy; y != ey; y++) {
      uint32_t *dst = target->ptr(ctr.x, y);
      span_blit_scale(this->ptr(0, int(srcy)), dst, int(srcx * 65536.0f), int(srcstepx * 65536.0f), abs(ctr.w), this->alpha());
      srcy += srcstepy;
    }
  }

  uint32_t* image_t::ptr(int x, int y) {
    return this->p + x + (y * (this->_rowstride / sizeof(uint32_t)));
  }

  void image_t::draw(shape_t *shape) {
    render(shape, this, &shape->transform, _brush);
  }

  void image_t::rectangle(const rect_t &r) {
    for(int y = 0; y < r.h; y++) {
      this->_brush->render_span(this, r.x, y, r.w);
    }
  }


  void image_t::circle(const point_t &p, const int &r) {
    // int sy = max(p.y - r, 0);
    // int ey = min(p.y + r, bounds.h);
    // for(int y = sy; y < ey; y++) {
    //   int w = sqrt((r * r) - ((y - p.y) * (y - p.y)));
    //   int sx = p.x - w;
    //   int ex = p.x + w;
    //   if(ex < 0 || sx >= bounds.h) {continue;}
    //   sx = max(sx, 0);
    //   ex = min(ex, bounds.w);

    //   //printf("c: %d -> %d @ %d\n", sx, ex, y);
    //   span_argb8(ptr(sx, y), ex - sx, c);
    // }
  }


  uint32_t image_t::pixel_unsafe(int x, int y) {
    return *ptr(x, y);    
  }

  uint32_t image_t::pixel(int x, int y) {
    x = max(int(_bounds.x), min(x, int(_bounds.x + _bounds.w - 1)));
    y = max(int(_bounds.y), min(y, int(_bounds.y + _bounds.h - 1)));
    return *ptr(x, y);    
  }

}