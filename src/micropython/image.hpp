#include "mp_tracked_allocator.hpp"
#include "../picovector.hpp"
#include "../image.hpp"

#define self(self_in, T) T *self = (T *)MP_OBJ_TO_PTR(self_in)
#define m_new_class(cls, ...) new(m_new(cls, 1)) cls(__VA_ARGS__)
#define m_del_class(cls, ptr) ptr->~cls(); m_del(cls, ptr, 1)

using namespace picovector;

extern "C" {

  #include "py/runtime.h"

  extern const mp_obj_type_t type_Image;
  struct _shape_obj_t;

  typedef struct _image_obj_t {
    mp_obj_base_t base;
    image *image;
  } image_obj_t;

  mp_obj_t image__del__(mp_obj_t self_in) {
    self(self_in, image_obj_t);
    m_del_class(image, self->image);
    return mp_const_none;
  }

  mp_obj_t image_draw(size_t n_args, const mp_obj_t *pos_args) {
    const image_obj_t *self = (image_obj_t *)MP_OBJ_TO_PTR(pos_args[0]);
    const shape_obj_t *shape = (shape_obj_t *)MP_OBJ_TO_PTR(pos_args[1]);
    self->image->draw(shape->shape);
    return mp_const_none;
  }

  mp_obj_t image_clear(mp_obj_t self_in) {
    self(self_in, image_obj_t);
    self->image->clear();
    return mp_const_none;
  }


  mp_obj_t image_brush(size_t n_args, const mp_obj_t *pos_args) {
    const image_obj_t *self = (image_obj_t *)MP_OBJ_TO_PTR(pos_args[0]);
    const brush_obj_t *brush = (brush_obj_t *)MP_OBJ_TO_PTR(pos_args[1]);
    self->image->brush = brush->brush;
    return mp_const_none;
  }


  /*
    micropython bindings
  */
  static MP_DEFINE_CONST_FUN_OBJ_1(image__del___obj, image__del__);
  static MP_DEFINE_CONST_FUN_OBJ_VAR(image_draw_obj, 2, image_draw);
  static MP_DEFINE_CONST_FUN_OBJ_1(image_clear_obj, image_clear);
  static MP_DEFINE_CONST_FUN_OBJ_VAR(image_brush_obj, 2, image_brush);

  static const mp_rom_map_elem_t image_locals_dict_table[] = {
      { MP_ROM_QSTR(MP_QSTR___del__), MP_ROM_PTR(&image__del___obj) },
      { MP_ROM_QSTR(MP_QSTR_draw), MP_ROM_PTR(&image_draw_obj) },
      { MP_ROM_QSTR(MP_QSTR_clear), MP_ROM_PTR(&image_clear_obj) },
      { MP_ROM_QSTR(MP_QSTR_brush), MP_ROM_PTR(&image_brush_obj) },
      
  };
  static MP_DEFINE_CONST_DICT(image_locals_dict, image_locals_dict_table);

  MP_DEFINE_CONST_OBJ_TYPE(
      type_Image,
      MP_QSTR_Image,
      MP_TYPE_FLAG_NONE,
      locals_dict, &image_locals_dict
  );

}
