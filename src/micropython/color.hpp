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

  mp_obj_t color__del__(mp_obj_t self_in) {
    self(self_in, color_obj_t);
    return mp_const_none;
  }

  mp_obj_t color_rgb(size_t n_args, const mp_obj_t *args) {
    int r = mp_obj_get_int(args[0]);
    int g = mp_obj_get_int(args[1]);
    int b = mp_obj_get_int(args[2]);

    int a = 255;
    if (n_args > 3) {
      a = mp_obj_get_int(args[3]);
    }

    color_obj_t *color = mp_obj_malloc(color_obj_t, &type_color);
    color->c = _make_col(r, g, b, a);
    return MP_OBJ_FROM_PTR(color);
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


  // static MP_DEFINE_CONST_FUN_OBJ_1(color__del___obj, color__del__);

  static MP_DEFINE_CONST_FUN_OBJ_VAR(color_rgb_obj, 3, color_rgb);
  static MP_DEFINE_CONST_STATICMETHOD_OBJ(color_rgb_static_obj, MP_ROM_PTR(&color_rgb_obj));

  static const mp_rom_map_elem_t color_locals_dict_table[] = {
    // { MP_ROM_QSTR(MP_QSTR___del__), MP_ROM_PTR(&color__del___obj) },
    { MP_ROM_QSTR(MP_QSTR_rgb), MP_ROM_PTR(&color_rgb_static_obj) },
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


