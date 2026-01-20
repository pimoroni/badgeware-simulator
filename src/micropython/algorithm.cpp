#include "mp_helpers.hpp"
#include "picovector.hpp"

#include "../algorithms/algorithms.hpp"

extern "C" {
  #include "py/runtime.h"

  MPY_BIND_STATICMETHOD_VAR(3, clip_line, {
    vec2_obj_t *p1 = (vec2_obj_t *)MP_OBJ_TO_PTR(args[0]);
    vec2_obj_t *p2 = (vec2_obj_t *)MP_OBJ_TO_PTR(args[1]);
    const rect_obj_t *r = (rect_obj_t *)MP_OBJ_TO_PTR(args[2]);

    bool result = clip_line(p1->v, p2->v, r->r);
    return mp_obj_new_bool(result);
  })

  MPY_BIND_STATICMETHOD_VAR(5, dda, {
    vec2_obj_t *p = (vec2_obj_t *)MP_OBJ_TO_PTR(args[0]);
    float angle = mp_obj_get_float(args[1]);
    float fov = mp_obj_get_float(args[2]);
    int rays = mp_obj_get_int(args[3]);
    int max = mp_obj_get_int(args[4]);

    mp_obj_t *result = new mp_obj_t[rays];
    //mp_obj_t result = mp_obj_new_list(rays, NULL);

    for(int i = 0; i < rays; i++) {
      float offset = float((i - (rays / 2.0f)) / (rays / 2.0f)) * fov / 2.0f;

      vec2_t v = vec2_t(cos((angle + offset) * (M_PI / 180.0f)), sin((angle + offset) * (M_PI / 180.0f)));

      int step = 0;

      mp_obj_t *ray = new mp_obj_t[max];
//      mp_obj_t ray = mp_obj_new_list(0, NULL);

      dda(p->v, v, [&step, &ray, &max](float hit_x, float hit_y, int gx, int gy, int edge, float offset, float distance) -> bool {
        // vec2_obj_t *cb_p = mp_obj_malloc(vec2_obj_t, &type_vec2);
        // vec2_obj_t *cb_g = mp_obj_malloc(vec2_obj_t, &type_vec2);

        // cb_p->v.x = hit_x;
        // cb_p->v.y = hit_y;

        // cb_g->v.x = gx;
        // cb_g->v.y = gy;

        mp_obj_t items[3] = {
          mp_obj_new_int(gx),
          mp_obj_new_int(gy),
          // MP_OBJ_FROM_PTR(cb_p),
          //MP_OBJ_FROM_PTR(cb_g),
          // mp_obj_new_int(edge),
          // mp_obj_new_float(offset),
          mp_obj_new_float(distance)
        };

        ray[step] = mp_obj_new_tuple(3, items);
        //mp_obj_t tup = mp_obj_new_tuple(6, items);

      //  mp_obj_list_append(ray, tup);

        step++;

        return step < max;
      });

      result[i] = mp_obj_new_tuple(max, ray);
      //mp_obj_list_append(result, ray);
    }

    return mp_obj_new_tuple(rays, result);
  })

  MPY_BIND_LOCALS_DICT(algorithm,
    MPY_BIND_ROM_PTR_STATIC(clip_line),
    MPY_BIND_ROM_PTR_STATIC(dda),
  )


  MP_DEFINE_CONST_OBJ_TYPE(
      type_algorithm,
      MP_QSTR_algorithm,
      MP_TYPE_FLAG_NONE,
      locals_dict, &algorithm_locals_dict
  );


}


