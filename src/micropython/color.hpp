#pragma once

#include "mp_tracked_allocator.hpp"
#include "../picovector.hpp"
#include "../blend.hpp"
#include "mp_helpers.hpp"

using namespace picovector;

extern "C" {

  #include "py/runtime.h"

  extern const mp_obj_type_t type_color;

  typedef struct _color_obj_t {
    mp_obj_base_t base;
    uint32_t c;
  } color_obj_t;

  mp_obj_t color_rgb(size_t n_args, const mp_obj_t *args) {
    int r = mp_obj_get_int(args[0]);
    int g = mp_obj_get_int(args[1]);
    int b = mp_obj_get_int(args[2]);
    int a = n_args > 3 ? mp_obj_get_int(args[3]) : 255;
    color_obj_t *color = mp_obj_malloc(color_obj_t, &type_color);
    color->c = _make_col(r, g, b, a);
    return MP_OBJ_FROM_PTR(color);
  }

  mp_obj_t color_hsv(size_t n_args, const mp_obj_t *args) {
    int h = mp_obj_get_int(args[0]);
    int s = mp_obj_get_int(args[1]);
    int v = mp_obj_get_int(args[2]);
    int a = n_args > 3 ? mp_obj_get_int(args[3]) : 255;
    color_obj_t *color = mp_obj_malloc(color_obj_t, &type_color);
    color->c = _make_col_hsv(h, s, v, a);
    return MP_OBJ_FROM_PTR(color);
  }

  mp_obj_t color_oklch(size_t n_args, const mp_obj_t *args) {
    int l = mp_obj_get_float(args[0]);
    int c = mp_obj_get_float(args[1]);
    int h = mp_obj_get_float(args[2]);
    int a = n_args > 3 ? mp_obj_get_int(args[3]) : 255;
    color_obj_t *color = mp_obj_malloc(color_obj_t, &type_color);
    color->c = _make_col_oklch(l, c, h, a);
    return MP_OBJ_FROM_PTR(color);
  }

  mp_obj_t color_blend(size_t n_args, const mp_obj_t *args) {
    const color_obj_t *self = (color_obj_t *)MP_OBJ_TO_PTR(args[0]);
    const color_obj_t *other = (color_obj_t *)MP_OBJ_TO_PTR(args[1]);
    _blend_rgba_rgba((uint8_t*)&self->c, (uint8_t*)&other->c);
    return MP_OBJ_NULL;
  }

  static inline uint8_t darken_u8(uint8_t c, uint8_t factor) {
    return (uint8_t)((c * factor) >> 8);
  }

  mp_obj_t color_darken(size_t n_args, const mp_obj_t *args) {
    const color_obj_t *self = (color_obj_t *)MP_OBJ_TO_PTR(args[0]);
    int v = 255 - mp_obj_get_int(args[1]);
    _r(&self->c, darken_u8(_r(&self->c), v));
    _g(&self->c, darken_u8(_g(&self->c), v));
    _b(&self->c, darken_u8(_b(&self->c), v));
    return MP_OBJ_NULL;
  }

  static inline uint8_t lighten_u8(uint8_t c, uint factor) {
    // factor >= 256 (1.0x)
    uint16_t v = (c * factor) >> 8;
    return v > 255 ? 255 : (uint8_t)v;
  }

  mp_obj_t color_lighten(size_t n_args, const mp_obj_t *args) {
    const color_obj_t *self = (color_obj_t *)MP_OBJ_TO_PTR(args[0]);
    int v = 256 + mp_obj_get_int(args[1]);
    _r(&self->c, lighten_u8(_r(&self->c), v));
    _g(&self->c, lighten_u8(_g(&self->c), v));
    _b(&self->c, lighten_u8(_b(&self->c), v));
    return MP_OBJ_NULL;
  }

  static void color_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest) {
    self(self_in, color_obj_t);

    action_t action = m_attr_action(dest);

    switch(attr) {
      case MP_QSTR_r: {
        if(action == GET) {
          dest[0] = mp_obj_new_int(_r(&self->c));
          return;
        }

        if(action == SET) {
          _r(&self->c, mp_obj_get_int(dest[1]));
          dest[0] = MP_OBJ_NULL;
          return;
        }
      };

      case MP_QSTR_g: {
        if(action == GET) {
          dest[0] = mp_obj_new_int(_g(&self->c));
          return;
        }

        if(action == SET) {
          _g(&self->c, mp_obj_get_int(dest[1]));
          dest[0] = MP_OBJ_NULL;
          return;
        }
      };


      case MP_QSTR_b: {
        if(action == GET) {
          dest[0] = mp_obj_new_int(_b(&self->c));
          return;
        }

        if(action == SET) {
          _b(&self->c, mp_obj_get_int(dest[1]));
          dest[0] = MP_OBJ_NULL;
          return;
        }
      };


      case MP_QSTR_a: {
        if(action == GET) {
          dest[0] = mp_obj_new_int(_a(&self->c));
          return;
        }

        if(action == SET) {
          _a(&self->c, mp_obj_get_int(dest[1]));
          dest[0] = MP_OBJ_NULL;
          return;
        }
      };

    }

    dest[1] = MP_OBJ_SENTINEL;
  }

  static MP_DEFINE_CONST_FUN_OBJ_VAR(color_rgb_obj, 3, color_rgb);
  static MP_DEFINE_CONST_STATICMETHOD_OBJ(color_rgb_static_obj, MP_ROM_PTR(&color_rgb_obj));

  static MP_DEFINE_CONST_FUN_OBJ_VAR(color_hsv_obj, 3, color_hsv);
  static MP_DEFINE_CONST_STATICMETHOD_OBJ(color_hsv_static_obj, MP_ROM_PTR(&color_hsv_obj));

  static MP_DEFINE_CONST_FUN_OBJ_VAR(color_oklch_obj, 3, color_oklch);
  static MP_DEFINE_CONST_STATICMETHOD_OBJ(color_oklch_static_obj, MP_ROM_PTR(&color_oklch_obj));

  static MP_DEFINE_CONST_FUN_OBJ_VAR(color_darken_obj, 2, color_darken);
  static MP_DEFINE_CONST_FUN_OBJ_VAR(color_lighten_obj, 2, color_lighten);
  static MP_DEFINE_CONST_FUN_OBJ_VAR(color_blend_obj, 2, color_blend);


  static const mp_rom_map_elem_t color_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_rgb), MP_ROM_PTR(&color_rgb_static_obj) },
    { MP_ROM_QSTR(MP_QSTR_hsv), MP_ROM_PTR(&color_hsv_static_obj) },
    { MP_ROM_QSTR(MP_QSTR_oklch), MP_ROM_PTR(&color_oklch_static_obj) },
    { MP_ROM_QSTR(MP_QSTR_darken), MP_ROM_PTR(&color_darken_obj) },
    { MP_ROM_QSTR(MP_QSTR_lighten), MP_ROM_PTR(&color_lighten_obj) },
    { MP_ROM_QSTR(MP_QSTR_blend), MP_ROM_PTR(&color_blend_obj) },
  };
  static MP_DEFINE_CONST_DICT(color_locals_dict, color_locals_dict_table);

  MP_DEFINE_CONST_OBJ_TYPE(
      type_color,
      MP_QSTR_color,
      MP_TYPE_FLAG_NONE,
      attr, (const void *)color_attr,
      locals_dict, &color_locals_dict
  );

}


