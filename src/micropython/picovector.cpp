#include "mp_tracked_allocator.hpp"
// #include "../picovector.hpp"
// #include "../primitive.hpp"
// #include "../image.hpp"


#include "brush.hpp"
#include "shape.hpp"
#include "font.hpp"
#include "pixel_font.hpp"
#include "image.hpp"
#include "input.hpp"
#include "matrix.hpp"

#include "mp_helpers.hpp"

using namespace picovector;

extern "C" {

  #include "py/runtime.h"

  int screen_width = 160;
  int screen_height = 120;
  uint32_t framebuffer[160 * 120];

#ifndef PICO
  int debug_width = 300;
  int debug_height = 360;
  uint32_t debug_buffer[300 * 360];
#endif

  mp_obj_t modpicovector___init__(void) {
      return mp_const_none;
  }


  mp_obj_t modpicovector_dda(size_t n_args, const mp_obj_t *pos_args) {
    float x = mp_obj_get_float(pos_args[0]);
    float y = mp_obj_get_float(pos_args[1]);
    float dx = mp_obj_get_float(pos_args[2]);
    float dy = mp_obj_get_float(pos_args[3]);
    int max = mp_obj_get_int(pos_args[4]);

    int ix = floor(x);
    int iy = floor(y);

    const float eps = 1e-30f;
    float inv_dx = fabs(dx) > eps ? 1.0f / dx : 1e30f;
    float inv_dy = fabs(dy) > eps ? 1.0f / dy : 1e30f;

    int step_x = (dx > 0.0f) ? 1 : (dx < 0.0f ? -1 : 0);
    int step_y = (dy > 0.0f) ? 1 : (dy < 0.0f ? -1 : 0);

    float t_delta_x = fabs(inv_dx);
    float t_delta_y = fabs(inv_dy);

    float t_max_x = 1e30f;
    float t_max_y = 1e30f;

    if(step_x > 0) {
      t_max_x = ((float(ix) + 1.0f) - x) * inv_dx;
    } else if(step_x < 0) {
      t_max_x = ((float(ix) - x)) * inv_dx;
    }

    if(step_y > 0) {
      t_max_y = ((float(iy) + 1.0f) - y) * inv_dy;
    } else if(step_y < 0) {
      t_max_y = ((float(iy) - y)) * inv_dy;
    }

    float t_enter = 0.0f;

    mp_obj_list_t *result = (mp_obj_list_t*)MP_OBJ_TO_PTR(mp_obj_new_list(max, NULL));

    //mp_obj_t result = mp_obj_new_list(0, NULL);

    int i = 0;
    while (t_enter <= max) {
      float t_exit = std::min(t_max_x, t_max_y);
      if (t_exit > max) t_exit = max;

      // if (!visit(ix, iy, t_enter, t_exit)) {
      //   break; // caller says "stop" (e.g. hit something)
      // }
      // add position to tuple

      float hit_x = x + dx * t_exit;
      float hit_y = y + dy * t_exit;
      mp_obj_tuple_t *t = (mp_obj_tuple_t*)MP_OBJ_TO_PTR(mp_obj_new_tuple(2, NULL));
      t->items[0] = mp_obj_new_float(hit_x);
      t->items[1] = mp_obj_new_float(hit_y);

      // mp_obj_t items[2];
      // items[0] = mp_obj_new_float(hit_x);
      // items[1] = mp_obj_new_float(hit_y);
      // mp_obj_t tuple = mp_obj_new_tuple(2, items);
      result->items[i] = MP_OBJ_FROM_PTR(t);
      ///mp_obj_list_append(result, MP_OBJ_FROM_PTR(t));
      i++;
      if(i >= max) {
        break;
      }
      // if (t_exit >= max) {
      //   break;
      // }

      // Step to the next cell: whichever boundary we hit first
      if (t_max_x < t_max_y) {
        ix += step_x;
        t_enter = t_max_x;
        t_max_x += t_delta_x; // next vertical boundary
      } else {
        iy += step_y;
        t_enter = t_max_y;
        t_max_y += t_delta_y; // next horizontal boundary
      }
    }

    return MP_OBJ_FROM_PTR(result);
  }


  void modpicovector_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest) {
    if (dest[0] == MP_OBJ_NULL) {
      if (attr == MP_QSTR_screen) {
        image_obj_t *image = mp_obj_malloc_with_finaliser(image_obj_t, &type_Image);
        image->image = new(m_malloc(sizeof(image_t))) image_t(framebuffer, screen_width, screen_height);
        dest[0] = MP_OBJ_FROM_PTR(image);
      }
#ifndef PICO
      if (attr == MP_QSTR_debug) {
        image_obj_t *image = mp_obj_malloc_with_finaliser(image_obj_t, &type_Image);
        image->image = new(m_malloc(sizeof(image_t))) image_t(debug_buffer, debug_width, debug_height);
        dest[0] = MP_OBJ_FROM_PTR(image);
      }
#endif
    }
  }

}
