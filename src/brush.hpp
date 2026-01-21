#pragma once

#include "picovector.hpp"
#include "mat3.hpp"
#include "image.hpp"
#include "blend.hpp"
#include "color.hpp"

namespace picovector {

  // empty implementations for unsupported modes
  //void span_func_nop(image_t *target, brush_t *brush, int x, int y, int w);

  struct brush_t {
    virtual span_func_t span_func() = 0;
    virtual masked_span_func_t masked_span_func() = 0;
  };

  void color_brush_span_func(image_t *target, brush_t *brush, int x, int y, int w);
  void color_brush_masked_span_func(image_t *target, brush_t *brush, int x, int y, int w, uint8_t *mask);
  struct color_brush_t : public brush_t {
    color_t c;

    color_brush_t(const color_t& c) : c(c) {};
    span_func_t span_func() {return color_brush_span_func;}
    masked_span_func_t masked_span_func() {return color_brush_masked_span_func;}
  };

  extern const uint8_t patterns[38][8];
  void pattern_brush_span_func(image_t *target, brush_t *brush, int x, int y, int w);
  void pattern_brush_masked_span_func(image_t *target, brush_t *brush, int x, int y, int w, uint8_t *mask);
  struct pattern_brush_t : public brush_t {
  public:
    uint8_t p[8];
    color_t c1;
    color_t c2;

    pattern_brush_t(const color_t& c1, const color_t& c2, uint8_t pattern_index);
    pattern_brush_t(const color_t& c1, const color_t& c2, uint8_t *pattern);

    span_func_t span_func() {return pattern_brush_span_func;}
    masked_span_func_t masked_span_func() {return pattern_brush_masked_span_func;}
  };

  void image_brush_span_func(image_t *target, brush_t *brush, int x, int y, int w);
  void image_brush_masked_span_func(image_t *target, brush_t *brush, int x, int y, int w, uint8_t *mask);
  struct image_brush_t : public brush_t {
  public:
    image_t *src;
    mat3_t inverse_transform;

    image_brush_t(image_t *src);
    image_brush_t(image_t *src, mat3_t *transform);

    span_func_t span_func() {return pattern_brush_span_func;}
    masked_span_func_t masked_span_func() {return pattern_brush_masked_span_func;}
  };

  // class brighten_brush : public brush_t {
  // public:
  //   int amount;
  //   brighten_brush(int amount) : amount(amount) {}
  //   void render_span(int x, int y, int w);
  //   void render_span_buffer(int x, int y, int w, uint8_t *sb) {};
  // };

  // class xor_brush : public brush_t {
  // public:
  //   uint32_t color;
  //   xor_brush(uint32_t color) : color(color) {}
  //   void render_span(int x, int y, int w);
  //   void render_span_buffer(int x, int y, int w, uint8_t *sb);
  // };

}