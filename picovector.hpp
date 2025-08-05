// very simply polygon rendering implementation

#include <stdint.h>
#include <cassert>
#include <string.h>
#include <float.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <optional>

using namespace std;
#include "image.hpp"
#include "span.hpp"


// TODO: bring back AA support

namespace picovector {

  struct mat3 {
    float v00, v10, v20, v01, v11, v21, v02, v12, v22;

    mat3();
    mat3& rotate(float a);
    mat3& rotate_radians(float a);
    mat3& translate(float x, float y);
    mat3& scale(float v);
    mat3& scale(float x, float y);
    mat3& multiply(const mat3 &m);
  };

  struct point {
    float x;
    float y;

    point();
    point(float x, float y);
    point transform(mat3 *t);
  };

  struct polygon {
    vector<point> points;

    polygon(int point_count = 0);
    void add_point(const point &point);
    void add_point(float x, float y);
    void edge_points(int edge, point &s, point &e); 
    void offset_edge(point &s, point &e, float offset);
    void stroke(float offset);
    void inflate(float offset);
  };

  struct shape;
  struct render_span;
  struct brush {
    virtual void render_spans(image *target, shape *shape, render_span *spans, int count) = 0;
  };

  struct shape {
    vector<polygon> polygons;
    mat3 transform;
    brush *style = nullptr;

    shape(int path_count = 1);
    void add_polygon(const polygon &path);
    rect bounds();
    void draw(image &img);
    void stroke(float thickness);
  };

  struct render_span {
    int x; // span start x
    int y; // span y
    int w; // span width in pixels
  };

  bool intersection(point p1, point p2, point p3, point p4, point &i);
  void offset_line_segment(point &s, point &e, float offset);
  inline void render(shape &shape, image &target, brush &mat);

  namespace shapes {
    shape regular_polygon(float x, float y, float sides, float radius);
    shape circle(float x, float y, float radius);
    shape rectangle(float x1, float y1, float x2, float y2);
    shape squircle(float x, float y, float size, float n=4.0f);
    shape arc(float x, float y, float from, float to, float radius);
    shape pie(float x, float y, float from, float to, float radius);
    shape star(float x, float y, int spikes, float outer_radius, float inner_radius);
    shape line(float x1, float y1, float x2, float y2);
  };
  
  namespace brushes {
    struct colour : brush {
      uint32_t col;
      void render_spans(image *target, shape *shape, render_span *spans, int count);
    };

    struct blur : brush {
      int strength;
      void render_spans(image *target, shape *shape, render_span *spans, int count);
    };

    struct brightness : brush {
      int amount;
      void render_spans(image *target, shape *shape, render_span *spans, int count);
    };

    // struct xor : brush {
    //   void render_spans(image *target, shape *shape, render_span *spans, int count);
    // };
  }


}