#include <stdint.h>
#include <algorithm>

using namespace std;

class point {
public:  
  int x;
  int y;

  point() : x(0), y(0) {}
  point(int x, int y) : x(x), y(y) {}

  bool operator==(const point &rhs) const {
    return x == rhs.x && y == rhs.y;
  }
};

class rect {
public:
  int x;
  int y;
  int w;
  int h;
  
  rect() {}
  
  rect(int x, int y, int w, int h) : x(x), y(y), w(w), h(h) {

  }

  rect(const point &p1, const point &p2) {
    x = p1.x; y = p1. y; w = p2.x - p1.x; h = p2.y - p1.y;
  }

  point tl() {return point(x, y);}
  point br() {return point(x + w, y + h);}

  void offset(point p) {
    x += p.x;
    y += p.y;
  }

  void offset(int ox, int oy) {
    x += ox;
    y += oy;
  }

  bool operator==(const rect &rhs) const {
    return x == rhs.x && y == rhs.y && w == rhs.w && h == rhs.h;
  }

  bool empty() {
    return w <= 0 || h <= 0;
  }

  bool contains(const point &p) {
    return p.x >= x && p.x <= x + w && p.y >= y && p.y <= y + h;
  }

  rect intersection(const rect &r) {
    return rect(
      max(x, r.x),
      max(y, r.y),
      min(x + w, r.x + r.w) - max(x, r.x),
      min(y + h, r.y + r.h) - max(y, r.y)
    );
  }

  bool intersects(const rect &r) {
    rect i = this->intersection(r);
    return !i.empty();
  }

  void shrink(int a) {
    x += a;
    y += a;
    w -= a + a;
    h -= a + a;
  }

  void shrink(int left, int top, int right, int bottom) {
    x += left;
    y += top;
    w -= left + right;
    h -= top + bottom;
  }

  void debug(std::string l = "?") {
    printf("%s: %d, %d (%d x %d)\n", l.c_str(), x, y, w, h);
  }
};