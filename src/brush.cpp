#include "brush.hpp"
#include "span.hpp"

using namespace std;

namespace picovector {

  #define debug_printf(fmt, ...) fprintf(stdout, fmt, ##__VA_ARGS__)

  color_brush::color_brush(int r, int g, int b, int a) {
    this->color = (r << 24) | (g << 16) | (b << 8) | a;
  }

  void color_brush::render_spans(image *target, _rspan *spans, int count) {
    while(count--) {
      uint32_t *dst = target->ptr(spans->x, spans->y);
      span_argb8(dst, spans->w, color);      
      spans++;
    }
  }

  void blur_brush::render_spans(image *target, _rspan *spans, int count) {
    // debug_printf("render colour\n");
    // while(count--) {
    //   debug_printf("%d, %d (%d)\n", spans->x, spans->y, spans->w);

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

  brighten_brush::brighten_brush(int amount) : amount(amount) {}

  void brighten_brush::render_spans(image *target, _rspan *spans, int count) {
    while(count--) {
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

  xor_brush::xor_brush(int r, int g, int b) {
    this->color = (r << 24) | (g << 16) | (b << 8);
  }

  void xor_brush::render_spans(image *target, _rspan *spans, int count) {
    while(count--) {
      uint32_t *dst = target->ptr(spans->x, spans->y);

      uint8_t *src = (uint8_t*)&color;
      for(int i = 0; i < spans->w; i++) {
        uint8_t *pd = (uint8_t *)dst;

        pd[1] ^= src[1];
        pd[2] ^= src[2];
        pd[3] ^= src[3];

        dst++;
      }
    }
  }  

  // void xor::render_spans(image *target, shape *shape, render_span *spans, int count) {
  //   while(count--) {
  //     debug_printf("%d, %d (%d)\n", spans->x, spans->y, spans->w);

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