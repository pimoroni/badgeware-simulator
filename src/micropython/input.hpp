
#include "../picovector.hpp"

#define self(self_in, T) T *self = (T *)MP_OBJ_TO_PTR(self_in)

using namespace picovector;

extern "C" {
  #include "py/stream.h"
  #include "py/reader.h"
  #include "py/runtime.h"
  #include "extmod/vfs.h"

  extern const mp_obj_type_t type_Input;
  extern uint8_t picovector_buttons;
  extern uint8_t picovector_changed_buttons;
  extern double picovector_ticks;

  enum BUTTON : uint8_t {
    HOME = 0b100000,
    A    = 0b010000,
    B    = 0b001000,
    C    = 0b000100,
    UP   = 0b000010,
    DOWN = 0b000001
  };

  typedef struct _Input_obj_t {
    mp_obj_base_t base;
  } input_obj_t;

  static mp_obj_t input_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *args) {
    input_obj_t *self = m_new_obj(input_obj_t);
    self->base.type = type;
    return MP_OBJ_FROM_PTR(self);
  }

  static void input_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest) {
    self(self_in, input_obj_t);

    if(attr == MP_QSTR_ticks && dest[0] == MP_OBJ_NULL) {      
      dest[0] = mp_obj_new_int_from_ll(picovector_ticks);
      return;
    }

    if((attr == MP_QSTR_pressed || attr == MP_QSTR_changed) && dest[0] == MP_OBJ_NULL) {
      mp_obj_t t_items[6];
      uint8_t buttons = attr == MP_QSTR_pressed ? picovector_buttons : picovector_changed_buttons;
      int n = 0;
      if(buttons & BUTTON::HOME) {
        t_items[n] = mp_obj_new_int(BUTTON::HOME);
        n++;
      }
      if(buttons & BUTTON::A) {
        t_items[n] = mp_obj_new_int(BUTTON::A);
        n++;
      }
      if(buttons & BUTTON::B) {
        t_items[n] = mp_obj_new_int(BUTTON::B);
        n++;
      }
      if(buttons & BUTTON::C) {
        t_items[n] = mp_obj_new_int(BUTTON::C);
        n++;
      }
      if(buttons & BUTTON::UP) {
        t_items[n] = mp_obj_new_int(BUTTON::UP);
        n++;
      }
      if(buttons & BUTTON::DOWN) {
        t_items[n] = mp_obj_new_int(BUTTON::DOWN);
        n++;
      }
      dest[0] = mp_obj_new_tuple(n, t_items);
      return;
    }

    dest[1] = MP_OBJ_SENTINEL;
  }

  /*mp_obj_t input_pressed(mp_obj_t self_in, mp_obj_t button_in) {
    self(self_in, input_obj_t);
    return mp_obj_new_bool(picovector_buttons & mp_obj_get_int(button_in));
  }
  static MP_DEFINE_CONST_FUN_OBJ_2(input_pressed_obj, input_pressed);*/

  static const mp_rom_map_elem_t input_locals_dict_table[] = {
      // TODO ... v How does it know!?!? v
      //{ MP_ROM_QSTR(MP_QSTR_pressed),     MP_ROM_PTR(&input_pressed_obj) },
      //{ MP_ROM_QSTR(MP_QSTR_ticks),       MP_OBJ_SENTINEL },
      { MP_ROM_QSTR(MP_QSTR_BUTTON_HOME), MP_ROM_INT(BUTTON::HOME) },
      { MP_ROM_QSTR(MP_QSTR_BUTTON_A),    MP_ROM_INT(BUTTON::A) },
      { MP_ROM_QSTR(MP_QSTR_BUTTON_B),    MP_ROM_INT(BUTTON::B) },
      { MP_ROM_QSTR(MP_QSTR_BUTTON_C),    MP_ROM_INT(BUTTON::C) },
      { MP_ROM_QSTR(MP_QSTR_BUTTON_UP),   MP_ROM_INT(BUTTON::UP) },
      { MP_ROM_QSTR(MP_QSTR_BUTTON_DOWN), MP_ROM_INT(BUTTON::DOWN) },
      
  };
  static MP_DEFINE_CONST_DICT(input_locals_dict, input_locals_dict_table);

  MP_DEFINE_CONST_OBJ_TYPE(
      type_Input,
      MP_QSTR_Input,
      MP_TYPE_FLAG_NONE,
      make_new, (const void *)input_new,
      attr, (const void *)input_attr,
      locals_dict, &input_locals_dict
  );

}
