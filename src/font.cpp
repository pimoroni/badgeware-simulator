#include <algorithm>

#include "font.hpp"
#include "image.hpp"
#include "picovector.hpp"
#include "brush.hpp"
#include "matrix.hpp"


using namespace std;

namespace picovector {
  struct _edgeinterp {
    point s;
    point e;
    float step;

    _edgeinterp() {

    }

    _edgeinterp(point p1, point p2) {
      if(p1.y < p2.y) { 
        s = p1; e = p2; 
      } else { 
        s = p2; e = p1; 
      }
      step = (e.x - s.x) / (e.y - s.y);
    }

    void next(float y, float *nodes, int &node_count) {
      if(y < s.y || y >= e.y) return;
      nodes[node_count++] = s.x + ((y - s.y) * step);
    }
  };

  void render_character(glyph *glyph, image *target, mat3 *transform, brush *brush) {    
    if(!glyph->path_count) {return;};
    
    rect b = glyph->bounds(transform);
    rect cb = b.intersection(target->bounds);

    // todo: can we pass in multiple glyphs to be processed together?
    
    
    // setup a node storage buffer that can do up to 32 sampling lines
    constexpr size_t NODE_BUFFER_HEIGHT = 32;
    static int16_t nodes[NODE_BUFFER_HEIGHT][64];
    static uint8_t node_counts[NODE_BUFFER_HEIGHT];

    // get the antialiasing factor (1 = none, 2 = 2x, 4 = 4x)
    int aa_level = target->antialias;

    // our node buffer has a fixed size so we can only render as many sample
    // lines as we can fit into it at a time. we split the overall job into
    // "strips" of scanlines and process each strip individually

    // strip height in pixels
    int strip_height = NODE_BUFFER_HEIGHT / aa_level;

    // calculate the subsample step for the aa current level 
    float subsample_step = (1.0f / float(aa_level));

    //debug_printf("render character = %c\n", glyph->codepoint);
    //debug_printf("strip_height = %d, subsample_step = %2f\n", strip_height, subsample_step);

    // step through the clipped bounding area one strip at a time
    for(int strip_y = floor(cb.y); strip_y < ceil(cb.y + cb.h); strip_y += strip_height) {

      //debug_printf("> render strip %d to %d\n", strip_y, strip_y + strip_height);

      // reset the node counts before rendering this strip
      memset(node_counts, 0, sizeof(node_counts));      

      // generate the sample nodes from the glyph edges
      for(int i = 0; i < glyph->path_count; i++) {
        //debug_printf("start of path %d\n", i);
        glyph_path *path = &glyph->paths[i];
        point last = path->points[path->point_count - 1].transform(transform);      
        for(int j = 0; j < path->point_count; j++) {        
          //debug_printf(" - interpolate edge %d\n", j);
          point next = path->points[j].transform(transform);
          //debug_printf("- %f, %f -> %f, %f\n", last.x, last.y, next.x, next.y);
          if(next.y != last.y) {        
            //debug_printf("- processing edge\n");              
            // get line start and end coordinates (start always above)
            float sx, sy, ex, ey;
            if(last.y < next.y) {
              sx = last.x; sy = last.y; ex = next.x; ey = next.y;
            } else {
              sx = next.x; sy = next.y; ex = last.x; ey = last.y;            
            }            

            if(ey >= strip_y && sy <= strip_y + strip_height) {
              // work out x delta step per node buffer
              float dx = ((ex - sx) / (ey - sy)) / aa_level;            
            
              // shift y coordinates into strip coordinates
              sy -= strip_y;
              ey -= strip_y;

              // clamp start y value and offset x position as needed
              float x = sx;
              if(sy < 0.0f) {
                x += dx * (abs(sy) * aa_level);
                sy = 0.0f;
              }

              // clamp end y
              ey = min(float(strip_height), ey);
                          
              float step_y = 1.0f / float(aa_level);
              float y = step_y / 2.0f;
              for(int k = 0; k < NODE_BUFFER_HEIGHT; k++) {
                //debug_printf("  > sample_y %f (%f -> %f)\n", sample_y, sy, ey);
                if(y >= sy && y < ey) {
                  nodes[k][node_counts[k]] = round(x * float(aa_level));
                  node_counts[k]++;            
                  //debug_printf("  > +node %d (%d)\n", k, nodes[k][node_counts[k]]);   
                  x += dx;                
                }
                y += step_y;
              }
            }
          } else {
            //debug_printf("- y coords the same, skipping\n");
          }

          last = next;
        }
      }

      
      //debug_printf("> render scanlines\n");

      // render out each scanline
      constexpr size_t SPAN_BUFFER_SIZE = 256;
      static uint8_t span_buffer[SPAN_BUFFER_SIZE];
      for(int y = 0; y < NODE_BUFFER_HEIGHT; y += aa_level) {
        memset(span_buffer, 0, sizeof(span_buffer));      

        for(int i = 0; i < aa_level; i++) {

          // sort the nodes so that neighbouring pairs represent render spans
          sort(&nodes[y + i][0], &nodes[y + i][0] + node_counts[y + i]);
          
          //debug_printf("> %d has %d nodes\n", y + i, node_counts[y + i]);

          for(int node_idx = 0; node_idx < node_counts[y + i]; node_idx += 2) {
            int x1 = nodes[y + i][node_idx + 0] - (cb.x * aa_level);
            int x2 = nodes[y + i][node_idx + 1] - (cb.x * aa_level);

            x1 = min(max(0, x1), int(cb.w * aa_level));
            x2 = min(max(0, x2), int(cb.w * aa_level));   

            uint8_t *p = span_buffer;
            for(int j = x1; j < x2; j++) {
              p[j >> (aa_level >> 1)]++;
            }        
          }
        }
        static uint8_t aa_none[2] = {0, 255};
        static uint8_t aa_x2[5] = {0, 64, 128, 192, 255};
        static uint8_t aa_x4[17] = {0, 16, 32, 48, 64, 80, 96, 112, 128, 144, 160, 176, 192, 208, 224, 240, 255};

        //debug_printf("> render scanline %d\n", y);

        uint8_t *aa_lut = aa_none;
        aa_lut = aa_level == 2 ? aa_x2 : aa_lut;
        aa_lut = aa_level == 4 ? aa_x4 : aa_lut;      

        // scale span buffer alpha values
        int c = SPAN_BUFFER_SIZE;
        uint8_t *psb = span_buffer;
        while(c--) {          
          *psb = aa_lut[*psb];
          psb++;
        }
      
        int ry = strip_y + (y / aa_level);

        if(ry < cb.y + cb.h) {
          //debug_printf("> render_span_buffer: cb.x=%f, ry=%d, cb.w=%f\n", cb.x, ry, cb.w);
          brush->render_span_buffer(target, cb.x, ry, cb.w, span_buffer);      
        }          
      }
    }
  }


  point glyph_path_point::transform(mat3 *transform) {
    return point(
      transform->v00 * float(x) + transform->v01 * float(y) + transform->v02,
      transform->v10 * float(x) + transform->v11 * float(y) + transform->v12
    );
  }

  rect glyph::bounds(mat3 *transform) {
    point p1(x, -y);
    point p2(x + w, -y);
    point p3(x + w, -y - h);
    point p4(x, -y);

    p1 = p1.transform(transform);
    p2 = p2.transform(transform);
    p3 = p3.transform(transform);
    p4 = p4.transform(transform);

    float minx = min(p1.x, min(p2.x, min(p3.x, p4.x)));
    float miny = min(p1.y, min(p2.y, min(p3.y, p4.y)));
    float maxx = max(p1.x, max(p2.x, max(p3.x, p4.x)));
    float maxy = max(p1.y, max(p2.y, max(p3.y, p4.y)));

    return rect(minx, miny, ceil(maxx) - minx, ceil(maxy) - miny);
  }

  rect font::measure(image *target, const char *text, float size) {
    rect r;

    mat3 transform;
    transform = transform.scale(size / 128.0f, size / 128.0f);    
    
    for(int i = 0; i < strlen(text); i++) {
      char c = text[i];
      // find the glyph
      for(int j = 0; j < this->glyph_count; j++) {
        if(this->glyphs[j].codepoint == uint16_t(c)) {
          float a = this->glyphs[j].advance;
          transform = transform.translate(a, 0);
          point caret(1, 1);
          caret = caret.transform(transform);
          r.w = max(r.w, caret.x);
          r.h = max(r.y, caret.y);
        }
      }
    }

    return r;
  }

  void font::draw(image *target, const char *text, float x, float y, float size) {    
    point caret(x, y);

    mat3 transform;
    transform = transform.translate(x, y);
    transform = transform.scale(size / 128.0f, size / 128.0f);    
    transform = transform.translate(0, size);

    for(int i = 0; i < strlen(text); i++) {
      char c = text[i];
      // find the glyph
      for(int j = 0; j < this->glyph_count; j++) {
        if(this->glyphs[j].codepoint == uint16_t(c)) {
          render_character(&this->glyphs[j], target, &transform, target->brush);
          float a = this->glyphs[j].advance;
          transform = transform.translate(a, 0);
        }
      }
    }
  }

}