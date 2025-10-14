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
    bool initialised;
    image_obj_t *image;
    input_obj_t *input;
  } modpicovector_obj_t;
  

  int screen_width = 160;
  int screen_height = 120;
  uint32_t framebuffer[160 * 120];
  image_t screen(framebuffer, screen_width, screen_height);

  mp_obj_t modpicovector___init__(void) {
    modpicovector_obj_t *state = (modpicovector_obj_t *)MP_STATE_VM(modpicovector_state);

    if(state && state->initialised && mp_obj_is_type(state->image, &type_Image) && mp_obj_is_type(state->input, &type_Input)) return mp_const_none;

    state = (modpicovector_obj_t *)m_malloc(sizeof(modpicovector_obj_t));

    state->initialised = true;
  
    // Don't use mp_obj_malloc_with_finalizer here, since the __del__
    // method will try to delete our `screen` and explode.
    state->image =  mp_obj_malloc(image_obj_t, &type_Image);
    state->image->image = &screen;
    state->input = mp_obj_malloc(input_obj_t, &type_Input);

    MP_STATE_VM(modpicovector_state) = state;

    return mp_const_none;
  }
  MP_REGISTER_ROOT_POINTER(void* modpicovector_state);
  
  void modpicovector_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest) {
    modpicovector_obj_t *state = (modpicovector_obj_t *)MP_STATE_VM(modpicovector_state);

    if (dest[0] == MP_OBJ_NULL) {
      if (attr == MP_QSTR_screen) {
        dest[0] = MP_OBJ_FROM_PTR(state->image);
      }
      if (attr == MP_QSTR_io) {
        dest[0] = MP_OBJ_FROM_PTR(state->input);
      }
    }
  }

}
