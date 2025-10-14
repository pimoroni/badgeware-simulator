#include "mp_tracked_allocator.hpp"
// #include "../picovector.hpp"
// #include "../primitive.hpp"
// #include "../image.hpp"


extern int PicoVector_working_buffer[];

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

  typedef struct _modpicovector_obj_t {
    bool initialised;
    image_obj_t *image;
  } modpicovector_obj_t;
  

  int screen_width = 160;
  int screen_height = 120;
  uint32_t framebuffer[160 * 120];

  mp_obj_t modpicovector___init__(void) {
    modpicovector_obj_t *state = (modpicovector_obj_t *)MP_STATE_VM(modpicovector_state);

    if(state && state->initialised && mp_obj_is_type(state->image, &type_Image)) return mp_const_none;

    state = (modpicovector_obj_t *)m_malloc(sizeof(modpicovector_obj_t));

    state->initialised = true;
  
    // Don't use mp_obj_malloc_with_finalizer here, since the __del__
    // method will try to delete our `screen` and explode.
    state->image =  mp_obj_malloc_with_finaliser(image_obj_t, &type_Image);
    state->image->image = new(m_malloc(sizeof(image_t))) image_t(framebuffer, screen_width, screen_height);

  #ifdef PICO
    // we need a way to set this up, but if the user wants to use the
    // interpolators in their own code they might modify the configuration..
    // do we have to do this everytime we're about to render something to be
    // sure or do we just say that this interpolator is out of bounds if you're
    // using pico graphics 2?
    interp_config cfg = interp_default_config();
    interp_config_set_blend(&cfg, true);
    interp_set_config(interp0, 0, &cfg);
    cfg = interp_default_config();
    interp_set_config(interp0, 1, &cfg);
  #endif

    MP_STATE_VM(modpicovector_state) = state;

    // Load and modify our module to add the "screen" attribute
    // this doesn't work - sadly - because imports happen before __init__
    //mp_obj_t module = mp_obj_new_module(MP_QSTR_picovector);
    //mp_store_attr(module, MP_QSTR_screen, MP_OBJ_FROM_PTR(state->image));

    return mp_const_none;
  }
  MP_REGISTER_ROOT_POINTER(void* modpicovector_state);
  
  void modpicovector_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest) {
    modpicovector_obj_t *state = (modpicovector_obj_t *)MP_STATE_VM(modpicovector_state);

    if (dest[0] == MP_OBJ_NULL) {
      if (attr == MP_QSTR_screen) {
        dest[0] = MP_OBJ_FROM_PTR(state->image);
      }
    }
  }

}
