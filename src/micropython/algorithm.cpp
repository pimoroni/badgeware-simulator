#include "mp_helpers.hpp"
#include "picovector.hpp"

#include "../algorithms/algorithms.hpp"

extern "C" {
  #include "py/runtime.h"

  MPY_BIND_STATICMETHOD_VAR(3, clip_line, {
    point_obj_t *p1 = (point_obj_t *)MP_OBJ_TO_PTR(args[0]);
    point_obj_t *p2 = (point_obj_t *)MP_OBJ_TO_PTR(args[1]);
    const rect_obj_t *r = (rect_obj_t *)MP_OBJ_TO_PTR(args[2]);

    bool result = clip_line(p1->point, p2->point, r->rect);
    return mp_obj_new_bool(result);
  })

  MPY_BIND_LOCALS_DICT(algorithm,
    MPY_BIND_ROM_PTR_STATIC(clip_line),
  )


  MP_DEFINE_CONST_OBJ_TYPE(
      type_algorithm,
      MP_QSTR_algorithm,
      MP_TYPE_FLAG_NONE,
      locals_dict, &algorithm_locals_dict
  );


}


