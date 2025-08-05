#pragma once

#include <stdint.h>
#include "hardware/interp.h"
#include <cstring>

inline uint32_t span_pixels_drawn = 0;
inline uint32_t sb[512] = {0};

inline uint32_t* __not_in_flash_func(_buffer_span)(uint32_t *p, int w) {
  // take a copy of the source data from PSRAM as it's ~40% faster to render
  // if the data is held in SRAM even with the overhead of the block copy  
  if(w < 512) {
    return (uint32_t*)memcpy(sb, p, w * sizeof(uint32_t));
  }
  return p;
}

inline void __not_in_flash_func(span_argb8)(uint32_t *dst, int32_t w, uint32_t c) { 
  span_pixels_drawn += w;
  
  uint8_t *ps = (uint8_t *)&c;

  if(ps[0] == 0) {
    // zero alpha, skip span
  } else if (ps[0] == 255) {
    // full alpha copy pixel
    while(w--) {
      *dst++ = c;
    }
  } else {
    interp0->accum[1] = ps[0]; // alpha    
    while(w--) {
      uint8_t *pd = (uint8_t *)dst;  
    
      interp0->base[0] = pd[1];
      interp0->base[1] = ps[1]; // red
      pd[1] = (uint8_t)interp0->peek[1];
    
      interp0->base[0] = pd[2];
      interp0->base[1] = ps[2]; // green
      pd[2] = (uint8_t)interp0->peek[1];
    
      interp0->base[0] = pd[3];
      interp0->base[1] = ps[3]; // blue
      pd[3] = (uint8_t)interp0->peek[1];

      dst++;
    }
  }
}

inline void __not_in_flash_func(span_blit_argb8)(uint32_t *src, uint32_t *dst, int w, int a = 255) {     
  span_pixels_drawn += w;

  src = _buffer_span(src, w); // buffer span from psram to sram

  while(w--) {
    uint8_t *ps = (uint8_t *)src;  
    uint8_t *pd = (uint8_t *)dst;  

    int ca = (ps[0] * (a + 1)) / 256; // apply global alpha

    if(ca == 0) {
      // zero alpha, skip pixel                            
    } else if (ca == 255) {
      // full alpha copy pixel
      *dst = *src;
    } else {
      // alpha requires blending pixel
      interp0->accum[1] = ca;
    
      interp0->base[0] = pd[1];
      interp0->base[1] = ps[1]; // red
      pd[1] = (uint8_t)interp0->peek[1];
    
      interp0->base[0] = pd[2];
      interp0->base[1] = ps[2]; // green
      pd[2] = (uint8_t)interp0->peek[1];
    
      interp0->base[0] = pd[3];
      interp0->base[1] = ps[3]; // blue
      pd[3] = (uint8_t)interp0->peek[1];
    }

    src++;
    dst++;
  }  
}

inline void __not_in_flash_func(span_blit_scale)(uint32_t *src, uint32_t *dst, int sxfp, int swfp, int dw, int a) {
  span_pixels_drawn += dw;

  src = _buffer_span(src, (sxfp + swfp + 65536) >> 16); // buffer span from psram to sram
  
  int i = 0;
  while(i++ < dw) {    
    int so = (sxfp + ((i * swfp) / dw)) >> 16; // calculate offset of source pixel

    uint8_t *pd = (uint8_t *)dst;
    uint8_t *ps = (uint8_t *)(src + so);

    int ca = (ps[0] * (a + 1)) / 256; // apply global alpha

    if(ca == 0) {
      // zero alpha, skip pixel                            
    } else if (ca == 255) {
      // full alpha copy pixel
      *dst = src[so];
    } else {
      // alpha requires blending pixel
      interp0->accum[1] = ca;
    
      interp0->base[0] = pd[1];
      interp0->base[1] = ps[1]; // red
      pd[1] = (uint8_t)interp0->peek[1];
    
      interp0->base[0] = pd[2];
      interp0->base[1] = ps[2]; // green
      pd[2] = (uint8_t)interp0->peek[1];
    
      interp0->base[0] = pd[3];
      interp0->base[1] = ps[3]; // blue
      pd[3] = (uint8_t)interp0->peek[1];
    }
    
    dst++;
  }
}
