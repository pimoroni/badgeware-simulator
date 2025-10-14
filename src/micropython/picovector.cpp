#include "mp_tracked_allocator.hpp"
// #include "../picovector.hpp"
// #include "../primitive.hpp"
// #include "../image.hpp"


extern int PicoVector_working_buffer[];

#include "brush.hpp"
#include "shape.hpp"
#include "font.hpp"
#include "image.hpp"
#include "input.hpp"
#include "matrix.hpp"

#include "mp_helpers.hpp"

using namespace picovector;

extern "C" {

  #include "py/runtime.h"

  extern const mp_obj_type_t type_PicoVector;

  typedef struct _modpicovector_obj_t {
      mp_obj_base_t base;
  } modpicovector_obj_t;

  input_obj_t *mp_input;
  image_obj_t *mp_image;
  int screen_width = 160;
  int screen_height = 120;
  uint32_t framebuffer[160 * 120];
  image_t screen(framebuffer, screen_width, screen_height);

  void modpicovector_deinit() {
    debug_printf("modpicovector_deinit: Cleaning up...\n");
    mp_image = nullptr;
    mp_input = nullptr;
  }

  void modpicovector_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest) {
    if (dest[0] == MP_OBJ_NULL) {
      if (attr == MP_QSTR_screen) {
        if(!mp_image) {
          // Don't use mp_obj_malloc_with_finalizer here, since the __del__
          // method will try to delete our `screen` and explode.
          mp_image = mp_obj_malloc(image_obj_t, &type_Image);
          mp_image->image = &screen;
        }
        dest[0] = MP_OBJ_FROM_PTR(mp_image);
      }
      if (attr == MP_QSTR_io) {
        if(!mp_input) {
          mp_input = mp_obj_malloc(input_obj_t, &type_Input);
        }
        dest[0] = MP_OBJ_FROM_PTR(mp_input);
      }
    }
  }

}
