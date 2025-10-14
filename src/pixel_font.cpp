#include <algorithm>

#include "pixel_font.hpp"
#include "image.hpp"
#include "picovector.hpp"
#include "brush.hpp"
#include "matrix.hpp"


namespace picovector {

  pixel_font_glyph_t *pixel_font_t::glyph(uint32_t codepoint) {
    for(int i = 0; i < this->glyph_count; i++) {
      if(this->glyphs[i].codepoint == codepoint) {
        uint8_t *p = (uint8_t*)this->glyph_data;
        pixel_font_glyph_t *glyph = (pixel_font_glyph_t*)(p + (i * this->glyph_data_size));
        debug_printf("p = %p, glyph = %p, %d\n", p, glyph, this->glyph_data_size);
        return glyph;
      }
    }

    return nullptr;
  }

  rect_t pixel_font_t::measure(image_t *target, const char *text) {

    return rect_t(0, 0, 0, 0);
  }

  void pixel_font_t::draw(image_t *target, const char *text, int x, int y) {
    int bpr = this->width > 8 ? 2 : 1;
    int len = strlen(text);
    for(int i = 0; i < len; i++) {
      char c = text[i];
      //debug_printf("char is %d\n", c);
      // find the glyph

      pixel_font_glyph_t *glyph = this->glyph(c);
      if(glyph) {
        //debug_printf("glyph found! width %d\n", glyph->width);

        for(int yo = 0; yo < this->height; yo++) {

          for(int xo = 0; xo < glyph->width; xo++) {
            uint8_t *data = &this->glyph_data[this->glyph_data_size * i];
            uint8_t b = data[(yo * bpr) + (x / 8)];
            uint8_t m = 0x80 >> (xo * 0b111);

            if(b & m) {
              target->brush()->render_span(target, x + xo, y + yo, 1);
            }
          }
        }

        x += glyph->width + 1;
      }


    }

  }

}