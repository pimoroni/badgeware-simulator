#include "py/runtime.h"
#include "py/objstr.h"
#include "badgeware.h"

/* ModSimulator - Control over the simulator settings from Python code */
typedef enum {GET, SET, DELETE} action_t;
action_t m_attr_action(mp_obj_t *dest) {
  if(dest[0] == MP_OBJ_NULL && dest[1] == MP_OBJ_NULL) {return GET;}
  if(dest[0] == MP_OBJ_NULL && dest[1] != MP_OBJ_NULL) {return DELETE;}
  return SET;
}

bool is_hot_reload = false;
bool debug_show_alloc_count = false;
bool debug_show_individual_allocs = false;
int simulator_realtime = true;

int screen_width = 160;
int screen_height = 120;
uint32_t framebuffer[320 * 240];

int debug_width = 300;
int debug_height = 360;
uint32_t debug_buffer[300 * 360];

#ifdef HEADLESS
const bool is_headless = true;
#else
const bool is_headless = false;
#endif

void modsim_set_hot_reload(void) {
    is_hot_reload = true;
}

mp_obj_t modsimulator_realtime(mp_obj_t realtime_in) {
    simulator_realtime = realtime_in == mp_const_true;
    return mp_const_none;
}
static MP_DEFINE_CONST_FUN_OBJ_1(modsimulator_realtime_obj, modsimulator_realtime);

mp_obj_t modsimulator_screenshot(size_t n_args, const mp_obj_t *args) {
    // If we're taking a screenshot with `None`
    if(n_args == 0) {
        return mp_obj_new_int(badgeware_screenshot(framebuffer, NULL));
    }
    // Else we've provided a filename
    GET_STR_DATA_LEN(args[0], str, str_len);
    int result = badgeware_screenshot(framebuffer, (const char *)str);
    return mp_obj_new_int(result);
}
static MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(modsimulator_screenshot_obj, 0, 1, modsimulator_screenshot);

mp_obj_t modsimulator_resolution(mp_obj_t width_in, mp_obj_t height_in) {
    screen_width = mp_obj_get_int(width_in);
    screen_height = mp_obj_get_int(height_in);
    return mp_const_none;
}
static MP_DEFINE_CONST_FUN_OBJ_2(modsimulator_resolution_obj, modsimulator_resolution);

void modsimulator_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest) {

    action_t action = m_attr_action(dest);

    switch(attr) {
        case MP_QSTR_framebuffer:
            if(action == GET) {
                // Always return the full-sized framebuffer here, since
                // screen_width and screen_height are updated on the fly to
                // display lores/hires modes correctly.
                dest[0] = mp_obj_new_bytearray_by_ref(320 * 240 * 4, framebuffer);
            } break;
        case MP_QSTR_debug_framebuffer:
            if(action == GET) {
                dest[0] = mp_obj_new_bytearray_by_ref(debug_width * debug_height * 4, debug_buffer);
            } break;
        case MP_QSTR_width:
            if(action == GET) {
                dest[0] = mp_obj_new_int(screen_width);
            } break;
        case MP_QSTR_height:
            if(action == GET) {
                dest[0] = mp_obj_new_int(screen_height);
            } break;
        case MP_QSTR_debug_width:
            if(action == GET) {
                dest[0] = mp_obj_new_int(debug_width);
            } break;
        case MP_QSTR_debug_height:
            if(action == GET) {
                dest[0] = mp_obj_new_int(debug_height);
            } break;
        case MP_QSTR_show_individual_allocs:
            if(action == GET) {
                dest[0] = mp_obj_new_bool(debug_show_individual_allocs);
            } else {
                debug_show_individual_allocs = mp_obj_is_true(dest[1]);
                dest[0] = MP_OBJ_NULL;
            } break;
        case MP_QSTR_show_alloc_count:
            if(action == GET) {
                dest[0] = mp_obj_new_bool(debug_show_alloc_count);
            } else {
                debug_show_alloc_count = mp_obj_is_true(dest[1]);
                dest[0] = MP_OBJ_NULL;
            } break;
        case MP_QSTR_hot_reload:
            if(action == GET) {
                dest[0] = mp_obj_new_bool(is_hot_reload);
            } break;
        case MP_QSTR_headless:
            if(action == GET) {
                dest[0] = mp_obj_new_bool(is_headless);
            } break;
    }
    dest[1] = MP_OBJ_SENTINEL;
}


static const mp_rom_map_elem_t modsimulator_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_modsimulator) },
    { MP_ROM_QSTR(MP_QSTR_screenshot), MP_ROM_PTR(&modsimulator_screenshot_obj) },
    { MP_ROM_QSTR(MP_QSTR_realtime), MP_ROM_PTR(&modsimulator_realtime_obj) },
    { MP_ROM_QSTR(MP_QSTR_resolution), MP_ROM_PTR(&modsimulator_resolution_obj) },
};
static MP_DEFINE_CONST_DICT(modsimulator_globals, modsimulator_globals_table);


// Define module object.
const mp_obj_module_t modsimulator = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&modsimulator_globals,
};

MP_REGISTER_MODULE(MP_QSTR_simulator, modsimulator);
MP_REGISTER_MODULE_DELEGATION(modsimulator, modsimulator_attr);
