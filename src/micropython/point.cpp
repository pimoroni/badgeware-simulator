#include "mp_tracked_allocator.hpp"

#include "mp_helpers.hpp"
#include "picovector.hpp"

using namespace picovector;

bool mp_obj_is_point(mp_obj_t point_in) {
  return mp_obj_is_type(point_in, &type_point);
}

point_t mp_obj_get_point(mp_obj_t point_in) {
  if(mp_obj_is_point(point_in)) {
    point_obj_t *point = (point_obj_t *)MP_OBJ_TO_PTR(point_in);
    return point->point;
  }
  mp_raise_msg_varg(&mp_type_ValueError, MP_ERROR_TEXT("invalid parameters, expected point(x, y)"));
}

point_t mp_obj_get_point_from_xy(const mp_obj_t *args) {
    int x = mp_obj_get_float(args[0]);
    int y = mp_obj_get_float(args[1]);
    return point_t(x, y);
}

extern "C" {

  #include "py/runtime.h"

  MPY_BIND_NEW(point, {
    point_obj_t *self = mp_obj_malloc_with_finaliser(point_obj_t, type);
    if(n_args != 2 && n_args != 0) {
      mp_raise_msg_varg(&mp_type_OSError, MP_ERROR_TEXT("invalid parameters, expected point() or point(x, y)"));
    }
    if(n_args == 2) {
      self->point.x = mp_obj_get_float(args[0]);
      self->point.y = mp_obj_get_float(args[1]);
    }
    return MP_OBJ_FROM_PTR(self);
  })

  MPY_BIND_VAR(2, transform, {
    point_obj_t *self = (point_obj_t *)MP_OBJ_TO_PTR(args[0]);
    mat3_obj_t *t = (mat3_obj_t *)MP_OBJ_TO_PTR(args[1]);
    self->point = self->point.transform(t->m);
    return mp_const_none;
  })

  MPY_BIND_ATTR(point, {
    self(self_in, point_obj_t);

    action_t action = m_attr_action(dest);

    switch(attr | action) {
      case MP_QSTR_x | GET:
        dest[0] = mp_obj_new_float(self->point.x);
        return;

      case MP_QSTR_x | SET:
        self->point.x = mp_obj_get_float(dest[1]);
        dest[0] = MP_OBJ_NULL;
        return;

      case MP_QSTR_y | GET:
        dest[0] = mp_obj_new_float(self->point.y);
        return;

      case MP_QSTR_y | SET:
        self->point.y = mp_obj_get_float(dest[1]);
        dest[0] = MP_OBJ_NULL;
        return;
    };

    dest[1] = MP_OBJ_SENTINEL;
  })

  mp_obj_t make_point(point_t p) {
    point_obj_t *result = (point_obj_t*)mp_obj_malloc(point_obj_t, &type_point);
    result->point = p;
    return MP_OBJ_FROM_PTR(result);
  }

  static mp_obj_t point_binary_op(mp_binary_op_t op, mp_obj_t lhs_in, mp_obj_t rhs_in) {
    point_obj_t *lhs = (point_obj_t*)MP_OBJ_TO_PTR(lhs_in);

    switch (op) {
      case MP_BINARY_OP_ADD: {
        if(mp_obj_is_type(rhs_in, &type_point)) {
          point_obj_t *rhs = (point_obj_t*)MP_OBJ_TO_PTR(rhs_in);
          return make_point(lhs->point + rhs->point);
        }
      }break;

      case MP_BINARY_OP_SUBTRACT: {
        if(mp_obj_is_type(rhs_in, &type_point)) {
          point_obj_t *rhs = (point_obj_t*)MP_OBJ_TO_PTR(rhs_in);
          return make_point(lhs->point - rhs->point);
        }
      }break;

      case MP_BINARY_OP_MULTIPLY: {
        if(mp_obj_is_type(rhs_in, &type_point)) {
          point_obj_t *rhs = (point_obj_t*)MP_OBJ_TO_PTR(rhs_in);
          return make_point(lhs->point * rhs->point);
        }
        if (mp_obj_is_int(rhs_in) || mp_obj_is_float(rhs_in)) {
          float v = mp_obj_get_float(rhs_in);
          return make_point(lhs->point * v);
        }
      }break;

      case MP_BINARY_OP_TRUE_DIVIDE: {
        if(mp_obj_is_type(rhs_in, &type_point)) {
          point_obj_t *rhs = (point_obj_t*)MP_OBJ_TO_PTR(rhs_in);
          return make_point(lhs->point / rhs->point);
        }
        if (mp_obj_is_int(rhs_in) || mp_obj_is_float(rhs_in)) {
          float v = mp_obj_get_float(rhs_in);
          return make_point(lhs->point / v);
        }
      }break;

      case MP_BINARY_OP_EQUAL: {
        if(mp_obj_is_type(rhs_in, &type_point)) {
          point_obj_t *rhs = (point_obj_t*)MP_OBJ_TO_PTR(rhs_in);
          return mp_obj_new_bool(lhs->point == rhs->point);
        }
        return mp_const_false;
      }

      case MP_BINARY_OP_NOT_EQUAL: {
        if(mp_obj_is_type(rhs_in, &type_point)) {
          point_obj_t *rhs = (point_obj_t*)MP_OBJ_TO_PTR(rhs_in);
          return mp_obj_new_bool(lhs->point != rhs->point);
        }
        return mp_const_true;
      }

      default: {
        return MP_OBJ_NULL;
      }
    }

    return MP_OBJ_NULL;
  }

  MPY_BIND_LOCALS_DICT(point,
    MPY_BIND_ROM_PTR(transform),
  )

  MP_DEFINE_CONST_OBJ_TYPE(
      type_point,
      MP_QSTR_point,
      MP_TYPE_FLAG_NONE,
      make_new, (const void *)point_new,
      attr, (const void *)point_attr,
      binary_op, (const void *)point_binary_op,
      locals_dict, &point_locals_dict
  );

}


