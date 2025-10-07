#include "font.hpp"
#include "primitive.hpp"

namespace picovector {

  void font::draw(image *target, const char *text, float x, float y) {
    shape *c = circle(x, y, 5);
    target->draw(c);
    delete c;
  }

}