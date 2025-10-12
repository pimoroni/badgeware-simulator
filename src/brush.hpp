#pragma once

#include <vector>
#include "picovector.hpp"

namespace picovector {

  class image_t;

  class brush_t {
  public:
    virtual ~brush_t() {
      debug_printf("brush destructed\n");      
    }
    
    void render_spans(image_t *target, _rspan *spans, int count);
    virtual void render_span(image_t *target, int x, int y, int w) = 0;
    virtual void render_mask(image_t *target);
    virtual void render_span_buffer(image_t *target, int x, int y, int w, uint8_t *sb) = 0;
  };
  
  class color_brush : public brush_t {
  public:
    uint32_t color;    
    color_brush(int r, int g, int b, int a = 255);
    ~color_brush() {
      debug_printf("color brush destructed\n");      
    }
    
    void render_span(image_t *target, int x, int y, int w);
    void render_span_buffer(image_t *target, int x, int y, int w, uint8_t *sb);
    //void render_mask(image *target);
  };

  class blur_brush : public brush_t {
  public:
    int passes;
    blur_brush(int passes = 1);
    
    void render_span(image_t *target, int x, int y, int w);
    void render_span_buffer(image_t *target, int x, int y, int w, uint8_t *sb) {};
    void render_mask(image_t *target);
  };

  class brighten_brush : public brush_t {
  public:
    int amount;
    brighten_brush(int amount);
    
    void render_span(image_t *target, int x, int y, int w);
    void render_span_buffer(image_t *target, int x, int y, int w, uint8_t *sb) {};
    //void render_mask(image *target);
  };

  class xor_brush : public brush_t {
  public:
    uint32_t color;    
    xor_brush(int r, int g, int b);
    
    void render_span(image_t *target, int x, int y, int w);
    void render_span_buffer(image_t *target, int x, int y, int w, uint8_t *sb);
    //void render_mask(image *target);
  };

}