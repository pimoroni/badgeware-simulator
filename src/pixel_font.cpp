#include <algorithm>

#include "pixel_font.hpp"
#include "image.hpp"
#include "picovector.hpp"
#include "brush.hpp"
#include "matrix.hpp"


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

  void pixel_font_t::draw(image_t *target, const char *text, int x, int y) {
    // check if text is within clipping area
    rect_t tb = this->measure(target, text);
    tb.x = x;
    tb.y = y;

    if(!tb.intersects(target->bounds())) {
      return;
    }

    uint32_t bpr = 1;
    if(this->width > 8) {bpr = 2;}
    if(this->width > 16) {bpr = 3;}

    int len = strlen(text);

    rect_t bounds = target->bounds();

    while(*text != '\0') {
      if(*text == 32) {
        x += this->width / 3;
        text++;
        continue;
      }

      int glyph_index = this->glyph_index(*text);
      if(glyph_index != -1) {
        pixel_font_glyph_t *glyph = &this->glyphs[glyph_index];

        uint8_t *data = &this->glyph_data[this->glyph_data_size * glyph_index];
        for(int yo = 0; yo < this->height; yo++) {
          if((y + yo) >= bounds.y && (y + yo) < bounds.y + bounds.h) {
            int xo = 0;
            for(int byte = 0; byte < bpr; byte++) {
              uint8_t b = *data;
              for(int bit = 0; bit < 8; bit++) {
                if(b & 0x80) {
                  if((x + xo) >= bounds.x && (x + xo) < bounds.x + bounds.w) {
                    target->brush()->render_span(target, x + xo, y + yo, 1);
                  }
                }
                b <<= 1;
                xo++;
              }
              data++;
            }
          } else {
            data += bpr;
          }
        }

        x += glyph->width + 1;

      }

      text++;
    }

  }

}