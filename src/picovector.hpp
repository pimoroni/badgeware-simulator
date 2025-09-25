#pragma once 

#include <stdint.h>
#include <cassert>
#include <string.h>
#include <float.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <optional>

#ifndef PICOVECTOR_STD_ALLOCATOR
#define PICOVECTOR_STD_ALLOCATOR std::allocator
#endif


// TODO: bring back AA support

namespace picovector {
  
  struct brush;
  class image;
  class shape;
  class mat3;

  struct _rspan {
    int x; // span start x
    int y; // span y
    int w; // span width in pixels
    int o; // opacity of the span for blending (used for AA only)

    _rspan() : x(0), y(0), w(0), o(0) {}
    _rspan(int x, int y, int w, int o = 255) : x(x), y(y), w(w), o(o) {}
  };

  void render(shape *shape, image *target, mat3 *transform, brush *brush);

}