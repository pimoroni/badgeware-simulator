#pragma once

#include <vector>
#include "mmallocator.hpp"
#include "picovector.hpp"
#include "image.hpp"

namespace picovector {

  struct brush {
    virtual void render_spans(image *target, const std::vector<_rspan, MPAllocator<_rspan>> &spans);
  };
  
  struct color_brush : public brush {
    uint32_t color;    
    color_brush(int r, int g, int b, int a = 255);
    void render_spans(image *target, const std::vector<_rspan, MPAllocator<_rspan>> &spans);
  };

  struct blur_brush : public brush {
    int strength;
    void render_spans(image *target, const std::vector<_rspan, MPAllocator<_rspan>> &spans);
  };

  struct brighten_brush : public brush {
    int amount;
    brighten_brush(int amount);
    void render_spans(image *target, const std::vector<_rspan, MPAllocator<_rspan>> &spans);
  };

  struct xor_brush : public brush {
    uint32_t color;    
    xor_brush(int r, int g, int b);
    void render_spans(image *target, const std::vector<_rspan, MPAllocator<_rspan>> &spans);
  };

}