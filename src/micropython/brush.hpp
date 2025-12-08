#pragma once

#include "mp_tracked_allocator.hpp"
#include "../picovector.hpp"
#include "../primitive.hpp"
#include "../shape.hpp"
#include "../image.hpp"
#include "../brush.hpp"

#include "mp_helpers.hpp"

using namespace picovector;

extern "C" {

  #include "py/runtime.h"

  extern const mp_obj_type_t type_brush;

  typedef struct _brush_obj_t {
    mp_obj_base_t base;
    brush_t *brush;
  } brush_obj_t;

  mp_obj_t brush__del__(mp_obj_t self_in) {
    self(self_in, brush_obj_t);
    m_del_class(brush_t, self->brush);
    return mp_const_none;
  }
  static MP_DEFINE_CONST_FUN_OBJ_1(brush__del___obj, brush__del__);

  mp_obj_t brush_color(size_t n_args, const mp_obj_t *pos_args) {
    int r = mp_obj_get_float(pos_args[0]);
    int g = mp_obj_get_float(pos_args[1]);
    int b = mp_obj_get_float(pos_args[2]);
    int a = n_args == 4 ? mp_obj_get_float(pos_args[3]) : 255;
    brush_obj_t *brush = mp_obj_malloc(brush_obj_t, &type_brush);
    brush->brush = m_new_class(color_brush, r, g, b, a);
    return MP_OBJ_FROM_PTR(brush);
  }
  static MP_DEFINE_CONST_FUN_OBJ_VAR(brush_color_obj, 3, brush_color);
  static MP_DEFINE_CONST_STATICMETHOD_OBJ(brush_color_static_obj, MP_ROM_PTR(&brush_color_obj));

  mp_obj_t brush_xor(size_t n_args, const mp_obj_t *pos_args) {
    int r = mp_obj_get_float(pos_args[0]);
    int g = mp_obj_get_float(pos_args[1]);
    int b = mp_obj_get_float(pos_args[2]);
    brush_obj_t *brush = mp_obj_malloc(brush_obj_t, &type_brush);
    brush->brush = m_new_class(xor_brush, r, g, b);
    return MP_OBJ_FROM_PTR(brush);
  }
  static MP_DEFINE_CONST_FUN_OBJ_VAR(brush_xor_obj, 3, brush_xor);
  static MP_DEFINE_CONST_STATICMETHOD_OBJ(brush_xor_static_obj, MP_ROM_PTR(&brush_xor_obj));

  mp_obj_t brush_brighten(size_t n_args, const mp_obj_t *pos_args) {
    int amount = mp_obj_get_float(pos_args[0]);
    brush_obj_t *brush = mp_obj_malloc(brush_obj_t, &type_brush);
    brush->brush = m_new_class(brighten_brush, amount);
    return MP_OBJ_FROM_PTR(brush);
  }
  static MP_DEFINE_CONST_FUN_OBJ_VAR(brush_brighten_obj, 1, brush_brighten);
  static MP_DEFINE_CONST_STATICMETHOD_OBJ(brush_brighten_static_obj, MP_ROM_PTR(&brush_brighten_obj));


  mp_obj_t brush_pattern(size_t n_args, const mp_obj_t *pos_args) {
    uint32_t c1 = mp_obj_get_int(pos_args[0]);
    uint32_t c2 = mp_obj_get_int(pos_args[1]);

    brush_obj_t *brush = mp_obj_malloc(brush_obj_t, &type_brush);
    if(mp_obj_is_int(pos_args[2])) {
      // brush index supplied, use pre-baked brush
      int i = mp_obj_is_int(pos_args[2]);

      if(i < 0 || i > 37) {
        mp_raise_TypeError(MP_ERROR_TEXT("pattern index must be a number between 0 and 37"));
      }

      brush->brush = m_new_class(pattern_brush, c1, c2, i);
    }else if(mp_obj_is_type(pos_args[2], &mp_type_tuple)) {
      size_t len;
      mp_obj_t *items;
      mp_obj_get_array(pos_args[2], &len, &items);

      if(len != 8) {
        mp_raise_TypeError(MP_ERROR_TEXT("pattern must be a tuple with 8 elements"));
      }

      uint8_t p[8];
      for(int i = 0; i < 8; i++) {
        p[i] = mp_obj_get_int(items[i]);
      }
      brush->brush = m_new_class(pattern_brush, c1, c2, p);
    }


    return MP_OBJ_FROM_PTR(brush);
  }
  static MP_DEFINE_CONST_FUN_OBJ_VAR(brush_pattern_obj, 1, brush_pattern);
  static MP_DEFINE_CONST_STATICMETHOD_OBJ(brush_pattern_static_obj, MP_ROM_PTR(&brush_pattern_obj));


  static const mp_rom_map_elem_t brush_locals_dict_table[] = {
      { MP_ROM_QSTR(MP_QSTR___del__), MP_ROM_PTR(&brush__del___obj) },
      { MP_ROM_QSTR(MP_QSTR_color), MP_ROM_PTR(&brush_color_static_obj) },
      { MP_ROM_QSTR(MP_QSTR_xor), MP_ROM_PTR(&brush_xor_static_obj) },
      { MP_ROM_QSTR(MP_QSTR_brighten), MP_ROM_PTR(&brush_brighten_static_obj) },
      { MP_ROM_QSTR(MP_QSTR_pattern), MP_ROM_PTR(&brush_pattern_static_obj) },
  };
  static MP_DEFINE_CONST_DICT(brush_locals_dict, brush_locals_dict_table);

  MP_DEFINE_CONST_OBJ_TYPE(
      type_brush,
      MP_QSTR_brush,
      MP_TYPE_FLAG_NONE,
      locals_dict, &brush_locals_dict
  );


}
