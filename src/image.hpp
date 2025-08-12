#pragma once

#include <stdint.h>
#include <string>

#include "rect.hpp"

class image {
  public:
    uint32_t *p = nullptr;
    bool managed_buffer = false;

    rect b;
    
    size_t rs; // row stride

    image();
    image(int w, int h);
    image(uint32_t *p, int w, int h);
    ~image();

    image window(rect r);

    void clear(uint32_t c = 0);
    void blit(image &t, const point &p, int alpha = 255);
    void blit(image &t, rect tr, int alpha = 255);

    uint32_t* ptr(int x, int y);
    
    void rectangle(rect r, uint32_t c);
    void circle(point p, int r, uint32_t c);

    uint32_t pen(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255);
};
