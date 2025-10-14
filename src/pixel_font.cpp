#include <algorithm>

#include "pixel_font.hpp"
#include "image.hpp"
#include "picovector.hpp"
#include "brush.hpp"
#include "matrix.hpp"

namespace picovector {

  rect_t pixel_font_t::measure(image_t *target, const char *text) {

    return rect_t(0, 0, 0, 0);
  }

  void pixel_font_t::draw(image_t *target, const char *text, int x, int y) {

  }

}