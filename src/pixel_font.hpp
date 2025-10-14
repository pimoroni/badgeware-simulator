#pragma once

#include <stdint.h>
#include <map>
#include <string>

#include "brush.hpp"
#include "shape.hpp"
#include "rect.hpp"
#include "point.hpp"
#include "matrix.hpp"

using std::unordered_map;
using std::vector;
using std::pair;
using std::less;

namespace picovector {

  class image_t;

  struct pixel_font_glyph_t {
    uint16_t width;
    void *data;
  };

  class pixel_font_t {
  public:
    uint32_t glyph_count;
    uint32_t glyph_data_size;
    uint16_t width;
    uint16_t height;

    std::vector<uint32_t, PV_STD_ALLOCATOR<uint32_t>> codepoints;
    void *glyph_data;

    uint32_t codepoint_index(uint32_t codepoint);
    pixel_font_glyph_t *glyph(uint32_t codepoint);

    void draw(image_t *target, const char *text, int x, int y);
    rect_t measure(image_t *target, const char *text);
  };

}