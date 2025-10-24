#include "py/runtime.h"
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
};
static MP_DEFINE_CONST_DICT(modsimulator_globals, modsimulator_globals_table);


// Define module object.
const mp_obj_module_t modsimulator = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&modsimulator_globals,
};

MP_REGISTER_MODULE(MP_QSTR_simulator, modsimulator);
MP_REGISTER_MODULE_DELEGATION(modsimulator, modsimulator_attr);