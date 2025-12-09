#pragma once

extern "C" {
  #include "py/runtime.h"
  #include "py/stream.h"
}

// Binding shortcuts

#define MPY_BIND_CLASSMETHOD_ARGS1(var_min_args, fn_name, arg1, fn_body) static mp_obj_t fn_name(mp_obj_t self_in, mp_obj_t arg1) fn_body\
  static MP_DEFINE_CONST_FUN_OBJ_VAR(fn_name##_obj, var_min_args, fn_name);

// Var args with lower bounds, static class method
#define MPY_BIND_STATICMETHOD_VAR(var_min_args, fn_name, fn_body) static mp_obj_t fn_name(size_t n_args, const mp_obj_t *args) fn_body\
  static MP_DEFINE_CONST_FUN_OBJ_VAR(fn_name##_obj, var_min_args, fn_name);\
  static MP_DEFINE_CONST_STATICMETHOD_OBJ(fn_name##_static_obj, MP_ROM_PTR(&fn_name##_obj));

// Var args with lower bounds
#define MPY_BIND_VAR(var_min_args, fn_name, fn_body) static mp_obj_t fn_name(size_t n_args, const mp_obj_t *args) fn_body\
  static MP_DEFINE_CONST_FUN_OBJ_VAR(fn_name##_obj, var_min_args, fn_name);

// "new" / class constructor
#define MPY_BIND_NEW(fn_name, fn_body) static mp_obj_t fn_name##_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *args) fn_body

#define MPY_BIND_ROM_PTR(name) { MP_ROM_QSTR(MP_QSTR_##name), MP_ROM_PTR(&name##_obj) }
#define MPY_BIND_ROM_PTR_STATIC(name) { MP_ROM_QSTR(MP_QSTR_##name), MP_ROM_PTR(&name##_static_obj) }

#define MPY_BIND_LOCALS_DICT(prefix, ...) \
  static const mp_rom_map_elem_t prefix##_locals_dict_table[] = {\
    __VA_ARGS__\
  };\
  static MP_DEFINE_CONST_DICT(prefix##_locals_dict, prefix##_locals_dict_table);


#define self(self_in, T) T *self = (T *)MP_OBJ_TO_PTR(self_in)
#define m_new_class(cls, ...) new(m_new(cls, 1)) cls(__VA_ARGS__)
#define m_del_class(cls, ptr) ptr->~cls(); m_del(cls, ptr, 1)

typedef enum {GET = 0b1 << 31, SET = 0b1 << 30, DELETE = 0b1 << 29} action_t;
action_t m_attr_action(mp_obj_t *dest) {
  if(dest[0] == MP_OBJ_NULL && dest[1] == MP_OBJ_NULL) {return GET;}
  if(dest[0] == MP_OBJ_NULL && dest[1] != MP_OBJ_NULL) {return DELETE;}
  return SET;
}

// file reading helpers
uint32_t ru32(mp_obj_t file) {
  int error;
  uint32_t result;
  mp_stream_read_exactly(file, &result, 4, &error);
  return __builtin_bswap32(result);
}

uint16_t ru16(mp_obj_t file) {
  int error;
  uint16_t result;
  mp_stream_read_exactly(file, &result, 2, &error);
  return __builtin_bswap16(result);
}

uint8_t ru8(mp_obj_t file) {
  int error;
  uint8_t result;
  mp_stream_read_exactly(file, &result, 1, &error);
  return result;
}

int8_t rs8(mp_obj_t file) {
  int error;
  int8_t result;
  mp_stream_read_exactly(file, &result, 1, &error);
  return result;
}
