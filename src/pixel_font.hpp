#pragma once

#include <stdint.h>
#include <map>
#include <string>

#include "brush.hpp"
#include "shape.hpp"
#include "rect.hpp"
#include "point.hpp"
#include "matrix.hpp"

using std::map;
using std::pair;

namespace picovector {

  class image_t;

  class pixel_glyph_t {
  public:
    uint16_t width;
    void *data;
  };

  typedef std::map<uint32_t, pixel_glyph_t, PV_STD_ALLOCATOR<pair<uint32_t, pixel_glyph_t>>> glyphs_t;

  class pixel_font_t {
  public:
    int glyph_count;
    int width;
    int height;

    glyphs_t glyphs;

    void draw(image_t *target, const char *text, int x, int y);
    rect_t measure(image_t *target, const char *text);
  };

}