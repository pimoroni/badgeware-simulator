#pragma once

#include <stdint.h>
#include <string>

#include "picovector.config.hpp"
#include "rect.hpp"

using std::vector;

namespace picovector {

  typedef enum antialias_t {
    OFF   = 1,
    LOW   = 2,
    X2    = 2,
    HIGH  = 4,
    X4    = 4
  } antialias_t;

  typedef enum pixel_format_t {
    RGBA8888 = 1,
    RGBA4444 = 2,
  } pixel_format_t;

  class mat3_t;  
  class font_t;
  class shape_t;
  class brush_t;

  class image_t {
    private:
      uint32_t       *p = nullptr;
      bool            managed_buffer = false; // TODO: this is messy
      size_t          _rowstride; // row stride

      rect_t          _bounds;
      uint8_t         _alpha = 255;
      antialias_t     _antialias = OFF;
      pixel_format_t  _pixel_format = RGBA8888;
      brush_t        *_brush = nullptr;
      font_t         *_font = nullptr;
      mat3_t         *_transform = nullptr;
      std::vector<uint32_t, PV_STD_ALLOCATOR<uint32_t>> _palette;


    public:
      image_t(int w, int h);
      image_t(uint32_t *p, int w, int h);
      ~image_t();

      void window(image_t *source, rect_t viewport);
      image_t window(rect_t r);
      uint32_t* ptr(int x, int y);

      rect_t bounds();      

      uint8_t alpha();
      void alpha(uint8_t alpha);

      antialias_t antialias();
      void antialias(antialias_t antialias);

      pixel_format_t pixel_format();
      void pixel_format(pixel_format_t pixel_format);

      mat3_t *transform();
      void transform(mat3_t *transform);

      brush_t *brush();
      void brush(brush_t *brush);

      font_t *font();
      void font(font_t *font);

      uint32_t pixel_unsafe(int x, int y);
      uint32_t pixel(int x, int y);

      void clear();
      void rectangle(const rect_t &r);
      void circle(const point_t &p, const int &r);
      void draw(shape_t *shape);
      void blit(image_t *t, const point_t p);
      void blit(image_t *t, rect_t tr);
  };

}
