#include <algorithm>

#include "pixel_font.hpp"
#include "image.hpp"
#include "picovector.hpp"
#include "brush.hpp"
#include "matrix.hpp"

using std::min;
using std::max;

namespace picovector {

  int pixel_font_t::glyph_index(int codepoint) {
    for(int i = 0; i < this->glyph_count; i++) {
      if(this->glyphs[i].codepoint == codepoint) {
        return i;
      }
    }
    return -1;
  }

  rect_t pixel_font_t::measure(image_t *target, const char *text) {
    rect_t tb = target->bounds();
    rect_t b(tb.x + tb.w, tb.y + tb.h, 0, this->height);

    point_t caret(0, 0);
    while(*text != '\0') {
      int glyph_index = this->glyph_index(*text);
      if(glyph_index != -1) {
        pixel_font_glyph_t *glyph = &this->glyphs[glyph_index];
        caret.x += glyph->width + 1;

        b.x = min(caret.x, b.x);
        b.w = max(caret.x, b.w);
      }
      text++;
    }
    return b;
  }

  void pixel_font_t::draw_glyph(image_t *target, const pixel_font_glyph_t *glyph, uint8_t *data, brush_t *brush, const rect_t &bounds, int x, int y) {
    // calculate the number of bytes per glyph pixel data row
    uint32_t bytes_per_row = (this->width + 7) >> 3;

    // clip the x and y ranges to within bounds
    int yoff = max(0, int(bounds.y - y));
    int yf = y + yoff;
    int yc = this->height - yoff;
    yc = min(yc, (int)bounds.h);

    int xoff = max(0, int(bounds.x - x));
    int xf = x + xoff;
    int xc = glyph->width - xoff;
    xc = min(xc, (int)bounds.w);

    uint32_t *dst = (uint32_t *)target->ptr(0, yf);
    uint32_t row_stride = target->row_stride() / 4;

    for(int yo = yf; yo < yf + yc; yo++) {

      for(int xo = xf; xo < xf + xc; xo++) {
        int bit = xo - x;
        uint8_t b = data[bit >> 3];
        if(b & (0b1 << (7 - (bit & 0b111)))) {
          brush->pixel(&dst[xo]);
        }
      }

      dst += row_stride;
      data += bytes_per_row;
    }
  }

  void pixel_font_t::draw(image_t *target, const char *text, int x, int y) {
    // check if text is within clipping area
    rect_t text_bounds = this->measure(target, text);
    text_bounds.x = x;
    text_bounds.y = y;

    // text isn't within the target bounds at all, escape early
    if(!text_bounds.intersects(target->bounds())) {
      return;
    }

    rect_t bounds = target->bounds();

    brush_t *brush = target->brush();

    while(*text != '\0') {
      // special case for "space"
      if(*text == 32) {
        x += this->width / 3;
        text++;
        continue;
      }

      int glyph_index = this->glyph_index(*text);
      if(glyph_index != -1) {
        pixel_font_glyph_t *glyph = &this->glyphs[glyph_index];
        uint8_t *data = &this->glyph_data[this->glyph_data_size * glyph_index];

        draw_glyph(target, glyph, data, brush, bounds, x, y);

        x += glyph->width + 1;
      }

      text++;
    }

  }

}