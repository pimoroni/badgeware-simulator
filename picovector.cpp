#include "picovector.hpp"

namespace picovector {
  struct _edgeinterp {
    point s;
    point e;
    float step;
    
    _edgeinterp() {

    }
    
    _edgeinterp(point p1, point p2) {
      if(p1.y < p2.y) { s = p1; e = p2; }else{ s = p2; e = p1; }
      step = (e.x - s.x) / (e.y - s.y);
    }

    void next(int y, int *nodes, int &node_count) {
      if(y < s.y || y >= e.y) return;
      nodes[node_count++] = s.x + ((y - s.y) * step);
    }
  };

  inline void render(shape &shape, image &target, brush *mat) {
    if(!shape.polygons.size()) {return;};    

    // determine the intersection between transformed polygon and target image
    rect b = shape.bounds();

    // setup interpolators for each edge of the polygon
    static _edgeinterp edge_interpolators[256];
    int edge_interpolator_count = 0;
    for(polygon &path : shape.polygons) {
      point last = path.points.back(); // start with last point to close loop
      last = last.transform(&shape.transform);
      for(point next : path.points) {
        next = next.transform(&shape.transform);
        // add new edge interpolator
        edge_interpolators[edge_interpolator_count] = _edgeinterp(last, next);
        edge_interpolator_count++;
        last = next;
      }
    }

    // for each scanline we step the interpolators and build the list of
    // intersecting nodes for that scaline
    static int nodes[128]; // up to 128 nodes (64 spans) per scanline   
    static render_span spans[256];
    int span_count = 0;
    int sy = max(b.y, 0);
    int ey = min(b.y + b.h, target.b.h);
    for(int y = sy; y <= ey; y++) {  
      int node_count = 0;
      for(int i = 0; i < edge_interpolator_count; i++) {
        edge_interpolators[i].next(y, nodes, node_count);
      }

      // sort the nodes so that neighouring pairs represent render spans
      sort(nodes, nodes + node_count); 

      // convert nodes into spans
      for(int i = 0; i < node_count; i += 2) {
        int x1 = min(max(0, nodes[i + 0]), target.b.w);
        int x2 = min(max(0, nodes[i + 1]), target.b.w);

        spans[span_count].x = x1;
        spans[span_count].y = y;
        spans[span_count].w = x2 - x1;
        span_count++;        
      }

      // if span buffer full, or this is the final scanline then render
      if(span_count > 256 - 64 || y == ey) {
        printf("render spans %d\n", span_count);
        mat->render_spans(&target, &shape, spans, span_count);
        span_count = 0;
      }
    }
  }

  mat3::mat3() {
    memset(this, 0, sizeof(mat3));
    v00 = v11 = v22 = 1.0f;
  }

  mat3& mat3::rotate(float a) {
    return this->rotate_radians(a * M_PI / 180.0f);
  }

  mat3& mat3::rotate_radians(float a) {
    mat3 rotation;
    float c = cosf(a);
    float s = sinf(a);
    rotation.v00 = c; rotation.v01 = -s; rotation.v10 = s; rotation.v11 = c;
    return this->multiply(rotation);
  }

  mat3& mat3::translate(float x, float y) {
    mat3 translation;
    translation.v02 = x; translation.v12 = y;
    return this->multiply(translation);
  }

  mat3& mat3::scale(float v) {
    return this->scale(v, v);
  }

  mat3& mat3::scale(float x, float y) {
    mat3 scale;
    scale.v00 = x; scale.v11 = y;
    return this->multiply(scale);
  }

  mat3& mat3::multiply(const mat3 &m) {
    mat3 r;
    r.v00 = v00 * m.v00 + v01 * m.v10 + v02 * m.v20;
    r.v01 = v00 * m.v01 + v01 * m.v11 + v02 * m.v21;
    r.v02 = v00 * m.v02 + v01 * m.v12 + v02 * m.v22;
    r.v10 = v10 * m.v00 + v11 * m.v10 + v12 * m.v20;
    r.v11 = v10 * m.v01 + v11 * m.v11 + v12 * m.v21;
    r.v12 = v10 * m.v02 + v11 * m.v12 + v12 * m.v22;
    r.v20 = v20 * m.v00 + v21 * m.v10 + v22 * m.v20;
    r.v21 = v20 * m.v01 + v21 * m.v11 + v22 * m.v21;
    r.v22 = v20 * m.v02 + v21 * m.v12 + v22 * m.v22;    
    memcpy(this, &r, sizeof(mat3));
    return *this;
  }



  /* ==========================================================================

  POLYGON - polygon class
  
  ========================================================================== */

  point::point() {}
  point::point(float x, float y) : x(x), y(y) {}

  point point::transform(mat3 *t) {
    if(!t) {return *this;}
    return point(
      t->v00 * x + t->v01 * y + t->v02,
      t->v10 * x + t->v11 * y + t->v12
    );
  }

  shape::shape(int path_count) {
    polygons.reserve(path_count);
  }

  void shape::add_polygon(const polygon &path) {
    polygons.push_back(path);
  }

  rect shape::bounds() {
    float minx = FLT_MAX, miny = FLT_MAX, maxx = -FLT_MAX, maxy = -FLT_MAX;
    for(const polygon &path : polygons) {
      for(point point : path.points) {
        point = point.transform(&transform);
        minx = min(minx, point.x);
        miny = min(miny, point.y);
        maxx = max(maxx, point.x);
        maxy = max(maxy, point.y);
      }
    }
    return rect(minx, miny, ceil(maxx) - minx, ceil(maxy) - miny);
  }

  void shape::draw(image &img) {
    if(style) {
      render(*this, img, style);
    }    
  }

  void shape::stroke(float thickness) {
    for(int i = 0; i < this->polygons.size(); i++) {
      this->polygons[i].stroke(thickness);
    }

    // std::vector<polygon> new_polygons(this->paths.size());

    // for(int i = 0; i < this->paths.size(); i++) {
    //   new_polygons[i].points = this->paths[i].points;
    //   new_polygons[i].inflate(thickness);
    // }

    // this->paths.insert(this->paths.end(), new_polygons.begin(), new_polygons.end());
  }



  polygon::polygon(int point_count) {
    points.reserve(point_count);
  }

  void polygon::add_point(const point &point) {
    points.push_back(point);
  }

  void polygon::add_point(float x, float y) {
    points.push_back(point(x, y));
  }

  void polygon::edge_points(int edge, point &s, point &e) {
    // return the two points that make up an edge
    s = edge == -1 ? points.back() : points[edge];
    e = edge == points.size() - 1 ? points.front() : points[edge + 1];
  }    

  void polygon::stroke(float offset) {
    int c = points.size();
    vector<point> new_points(c);

    if(c == 2) {
        point p1, p2; // edge 1 start and end                
        edge_points(0, p1, p2);
        offset_line_segment(p1, p2, offset);
        points.push_back(p2);
        points.push_back(p1);
    }else{
      for(int i = 0; i < c; i++) {
        point p1, p2; // edge 1 start and end                
        edge_points(i - 1, p1, p2);
        offset_line_segment(p1, p2, offset);
        
        point p3, p4; // edge 2 start and end
        edge_points(i, p3, p4);
        offset_line_segment(p3, p4, offset);

        // find intersection of the edges
        point pi;
        bool ok = intersection(p1, p2, p3, p4, pi);
        new_points[i] = pi;
      }

      points.push_back(points.front());
      points.insert(points.end(), new_points.begin(), new_points.end());
      points.push_back(new_points.front());
    }
  }

  void polygon::inflate(float offset) {
    vector<point> new_points(points.size());

    int edge_count = points.size();
    for(int i = 0; i < edge_count; i++) {
      point p1, p2; // edge 1 start and end                
      edge_points(i, p1, p2);
      offset_line_segment(p1, p2, offset);
      
      point p3, p4; // edge 2 start and end
      edge_points(i + 1, p3, p4);
      offset_line_segment(p3, p4, offset);

      // find intersection of the edges
      point pi;
      bool ok = intersection(p1, p2, p3, p4, pi);
      new_points[i] = pi;
    }

    points = new_points;
  }

  /* ==========================================================================

  HELPERS
  
  ========================================================================== */
  void offset_line_segment(point &s, point &e, float offset) {
    // calculate normal of edge
    float nx = -(e.y - s.y);
    float ny = e.x - s.x;
    float l = sqrt(nx * nx + ny * ny);
    nx /= l;
    ny /= l;

    // scale normal to requested offset
    float ox = nx * offset;
    float oy = ny * offset;

    // offset supplied edge points
    s.x += ox;
    s.y += oy;
    e.x += ox;
    e.y += oy;
  }

  bool intersection(point p1, point p2, point p3, point p4, point &i) {
    float a1 = p2.y - p1.y;
    float b1 = p1.x - p2.x;
    float c1 = a1 * p1.x + b1 * p1.y;

    float a2 = p4.y - p3.y;
    float b2 = p3.x - p4.x;
    float c2 = a2 * p3.x + b2 * p3.y;

    float determinant = a1 * b2 - a2 * b1;

    if(determinant == 0) {        
      return false; // lines parallel or coincident
    }

    i.x = (b2 * c1 - b1 * c2) / determinant;
    i.y = (a1 * c2 - a2 * c1) / determinant;
    return true;
  }

  /* ==========================================================================

  PRIMITIVES

  helper functions for making primitive shapes
  
  ========================================================================== */

  namespace shapes {
    shape regular_polygon(float x, float y, float sides, float radius) {
      shape result;
      polygon poly(sides);  
      for(int i = 0; i < sides; i++) {
        float theta = ((M_PI * 2.0f) / (float)sides) * (float)i;
        poly.add_point(sin(theta) * radius + x, cos(theta) * radius + y);
      }
      result.add_polygon(poly);  
      return result;    
    }

    shape circle(float x, float y, float radius) {
      int sides = 32;
      return regular_polygon(x, y, sides, radius);
    }

    shape rectangle(float x1, float y1, float x2, float y2) {
      shape result;
      polygon poly(4);
      poly.add_point(x1, y2);
      poly.add_point(x2, y2);
      poly.add_point(x2, y1);
      poly.add_point(x1, y1);
      result.add_polygon(poly);
      return result;
    }

    // void _ppp_rrect_corner(pp_path_t *path, PP_COORD_TYPE cx, PP_COORD_TYPE cy, PP_COORD_TYPE r, int q) {
    //   float quality = 5; // higher the number, lower the quality - selected by experiment
    //   int steps = ceil(r / quality) + 2; // + 2 to include start and end
    //   float delta = -(M_PI / 2) / steps;
    //   float theta = (M_PI / 2) * q; // select start theta for this quadrant
    //   for(int i = 0; i <= steps; i++) {
    //     PP_COORD_TYPE xo = sin(theta) * r, yo = cos(theta) * r;
    //     pp_path_add_point(path, (pp_point_t){cx + xo, cy + yo});
    //     theta += delta;
    //   }
    // }

    // void _ppp_rrect_path(pp_path_t *path, ppp_rect_def d) {
    //   d.r1 == 0 ? pp_path_add_point(path, (pp_point_t){d.x, d.y})             : _ppp_rrect_corner(path, d.x + d.r1, d.y + d.r1, d.r1, 3);
    //   d.r2 == 0 ? pp_path_add_point(path, (pp_point_t){d.x + d.w, d.y})       : _ppp_rrect_corner(path, d.x + d.w - d.r2, d.y + d.r2, d.r2, 2);
    //   d.r3 == 0 ? pp_path_add_point(path, (pp_point_t){d.x + d.w, d.y + d.h}) : _ppp_rrect_corner(path, d.x + d.w - d.r3, d.y + d.h - d.r3, d.r3, 1);
    //   d.r4 == 0 ? pp_path_add_point(path, (pp_point_t){d.x, d.y + d.h})       : _ppp_rrect_corner(path, d.x + d.r4, d.y + d.h - d.r4, d.r4, 0);
    // }

    // pp_poly_t* ppp_rect(ppp_rect_def d) {
    //   pp_poly_t *shape = pp_poly_new();
    //   pp_path_t *path = pp_poly_add_path(shape);
    //   if(d.r1 == 0.0f && d.r2 ==  0.0f && d.r3 ==  0.0f && d.r4 == 0.0f) { // non rounded rect
    //     pp_point_t points[] = {{d.x, d.y}, {d.x + d.w, d.y}, {d.x + d.w, d.y + d.h}, {d.x, d.y + d.h}};
    //     pp_path_add_points(path, points, 4);
    //     if(d.s != 0) { // stroked, not filled
    //       d.x += d.s; d.y += d.s; d.w -= 2 * d.s; d.h -= 2 * d.s;
    //       pp_path_t *inner = pp_poly_add_path(shape);
    //         pp_point_t points[] = {{d.x, d.y}, {d.x + d.w, d.y}, {d.x + d.w, d.y + d.h}, {d.x, d.y + d.h}};
    //       pp_path_add_points(inner, points, 4);
    //     }
    //   }else{ // rounded rect
    //     _ppp_rrect_path(path, d);
    //     if(d.s != 0) { // stroked, not filled
    //       d.x += d.s; d.y += d.s; d.w -= 2 * d.s; d.h -= 2 * d.s;
    //       d.r1 = _pp_max(0, d.r1 - d.s);
    //       d.r2 = _pp_max(0, d.r2 - d.s);
    //       d.r3 = _pp_max(0, d.r3 - d.s);
    //       d.r4 = _pp_max(0, d.r4 - d.s);
    //       pp_path_t *inner = pp_poly_add_path(shape);
    //       _ppp_rrect_path(inner, d);
    //     }
    //   }
    //   return shape;
    // }


      // static shape rounded_rectangle(float x1, float y1, float x2, float y2, float r1, float r2, float r3, float r4, float stroke=0.0f) {
      // }

    shape squircle(float x, float y, float size, float n) {
      shape result;
      int points = 32;
      polygon poly(points);
      for(int i = 0; i < points; i++) {
          float t = 2 * M_PI * (points - i) / points;
          float ct = cos(t);
          float st = sin(t);
          
          poly.add_point(
            x + copysign(pow(abs(ct), 2.0 / n), ct) * size, 
            y + copysign(pow(abs(st), 2.0 / n), st) * size
          );        
      }
      result.add_polygon(poly);
      return result;
    }

    shape arc(float x, float y, float from, float to, float radius) {
      shape result;    

      from = fmod(from, 360.0f);
      to = fmod(to, 360.0f);
      float delta = fabs(to - from);
      int steps = (int)(32.0f * (delta / 360.0f));
      from *= (M_PI / 180.0f);
      to *= (M_PI / 180.0f);
      
      polygon outline;

      float astep = (to - from) / (float)steps;
      float a = from;

      for(int i = 0; i <= steps; i++) {
        outline.add_point(sin(a) * radius + x, cos(a) * radius + y);
        a += astep;
      }    

      result.add_polygon(outline);

      return result;
    }

    shape pie(float x, float y, float from, float to, float radius) {
      shape result;    

      from = fmod(from, 360.0f);
      to = fmod(to, 360.0f);
      float delta = fabs(to - from);
      int steps = (int)(32.0f * (delta / 360.0f));
      from *= (M_PI / 180.0f);
      to *= (M_PI / 180.0f);
      
      polygon outline;

      float astep = (to - from) / (float)steps;
      float a = from;

      for(int i = 0; i <= steps; i++) {
        outline.add_point(sin(a) * radius + x, cos(a) * radius + y);
        a += astep;
      }    

      outline.add_point(x, y);

      result.add_polygon(outline);

      return result;
    }


    shape star(float x, float y, int spikes, float outer_radius, float inner_radius) {
      shape result;
      polygon poly(spikes * 2);  
      for(int i = 0; i < spikes * 2; i++) {
        float step = ((M_PI * 2) / (float)(spikes * 2)) * (float)i;
        float r = i % 2 == 0 ? outer_radius : inner_radius; 
        poly.add_point(sin(step) * r + x, cos(step) * r + y);
      }
      result.add_polygon(poly);
      return result;
    }

    shape line(float x1, float y1, float x2, float y2) {
      shape result;
      polygon poly(2);  

      poly.add_point(x1, y1);
      poly.add_point(x2, y2);
      result.add_polygon(poly);

      return result;
    }
  }


  namespace brushes {

    void colour::render_spans(image *target, shape *shape, render_span *spans, int count) {      
      printf("render colour\n");
      while(count--) {
        printf("%d, %d (%d)\n", spans->x, spans->y, spans->w);

        uint32_t *dst = target->ptr(spans->x, spans->y);
        span_argb8(dst, spans->w, col);
        spans++;
      }
    }

    void blur::render_spans(image *target, shape *shape, render_span *spans, int count) {
      // printf("render colour\n");
      // while(count--) {
      //   printf("%d, %d (%d)\n", spans->x, spans->y, spans->w);

      //   uint32_t *dst = target->ptr(spans->x, spans->y);
      //   for(int i = 0; i < spans->w; i++) {
      //     uint8_t *pd = (uint8_t *)dst;  
    
      //     int r = pd[1];
        
      //     int g = pd[2] + amount;

      //     int b = pd[3] + amount;
        
      //     dst++;
      //   }
      //   spans++;
      // }
    }

    void brightness::render_spans(image *target, shape *shape, render_span *spans, int count) {
      while(count--) {
        printf("%d, %d (%d)\n", spans->x, spans->y, spans->w);

        uint32_t *dst = target->ptr(spans->x, spans->y);
        for(int i = 0; i < spans->w; i++) {
          uint8_t *pd = (uint8_t *)dst;  
    
          int r = pd[1] + amount;
          r = max(0, min(r, 255));
          pd[1] = r;
        
          int g = pd[2] + amount;
          g = max(0, min(g, 255));
          pd[2] = g;

          int b = pd[3] + amount;
          b = max(0, min(b, 255));
          pd[3] = b;
        
          dst++;
        }
        spans++;
      }
    }

    // void xor::render_spans(image *target, shape *shape, render_span *spans, int count) {
    //   while(count--) {
    //     printf("%d, %d (%d)\n", spans->x, spans->y, spans->w);

    //     uint32_t *dst = target->ptr(spans->x, spans->y);
    //     for(int i = 0; i < spans->w; i++) {
    //       uint8_t *pd = (uint8_t *)dst;  
    //       pd[1] = ^pd[1];
    //       pd[2] = ^pd[2];
    //       pd[3] = ^pd[3];
        
    //       dst++;
    //     }
    //     spans++;
    //   }
    // }
  }
}