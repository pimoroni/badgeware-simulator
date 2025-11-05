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

void modsim_set_hot_reload(void) {
    is_hot_reload = true;
}

mp_obj_t modsimulator_screenshot(size_t n_args, const mp_obj_t *args) {
    // If we're taking a screenshot with `None`
    if(n_args == 0) {
        return mp_obj_new_int(badgeware_screenshot(framebuffer, NULL));
    }
    // Else we've provided a filename
    GET_STR_DATA_LEN(args[1], str, str_len);
    int result = badgeware_screenshot(framebuffer, (const char *)str);
    return mp_obj_new_int(result);
}
MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(modsimulator_screenshot_obj, 0, 1, modsimulator_screenshot);

void modsimulator_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest) {

    action_t action = m_attr_action(dest);

    switch(attr) {
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
    }
    dest[1] = MP_OBJ_SENTINEL;
}


static const mp_rom_map_elem_t modsimulator_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_modsimulator) },
    { MP_ROM_QSTR(MP_QSTR_screenshot), MP_ROM_PTR(&modsimulator_screenshot_obj) },
};
static MP_DEFINE_CONST_DICT(modsimulator_globals, modsimulator_globals_table);


// Define module object.
const mp_obj_module_t modsimulator = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&modsimulator_globals,
};

MP_REGISTER_MODULE(MP_QSTR_simulator, modsimulator);
MP_REGISTER_MODULE_DELEGATION(modsimulator, modsimulator_attr);