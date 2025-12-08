#pragma once

#include <vector>
#include "picovector.hpp"

namespace picovector {

  class image_t;

  class brush_t {
  public:
    virtual ~brush_t() {};
    void render_spans(image_t *target, _rspan *spans, int count);
    virtual void render_span(image_t *target, int x, int y, int w) = 0;
    virtual void render_span_buffer(image_t *target, int x, int y, int w, uint8_t *sb) = 0;
    virtual void pixel(uint32_t *dst) = 0;
  };

  class color_brush : public brush_t {
  public:
    uint32_t color;
    color_brush(int r, int g, int b, int a = 255);

    void render_span(image_t *target, int x, int y, int w);
    void pixel(uint32_t *dst);
    void render_span_buffer(image_t *target, int x, int y, int w, uint8_t *sb);
  };


  class brighten_brush : public brush_t {
  public:
    int amount;
    brighten_brush(int amount);

    void render_span(image_t *target, int x, int y, int w);
    void pixel(uint32_t *dst);
    void render_span_buffer(image_t *target, int x, int y, int w, uint8_t *sb) {};
  };

  class xor_brush : public brush_t {
  public:
    uint32_t color;
    xor_brush(int r, int g, int b);

    void render_span(image_t *target, int x, int y, int w);
    void pixel(uint32_t *dst);
    void render_span_buffer(image_t *target, int x, int y, int w, uint8_t *sb);
  };


  // class pattern_brush : public brush_t {
  // public:
  //   uint8_t pattern[8];
  //   uint32_t color1;
  //   uint32_t color2;

  //   pattern_brush(uint32_t color1, uint32_t color2, uint8_t[8] pattern);

  //   void render_span(image_t *target, int x, int y, int w);
  //   void pixel(uint32_t *dst);
  //   void render_span_buffer(image_t *target, int x, int y, int w, uint8_t *sb);
  // };


}