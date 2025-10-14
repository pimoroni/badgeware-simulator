
#include "py/runtime.h"

extern void modpicovector_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest);
extern mp_obj_t modpicovector___init__(void);

extern const mp_obj_type_t type_Shapes;
extern const mp_obj_type_t type_Brushes;
extern const mp_obj_type_t type_Image;
extern const mp_obj_type_t type_Font;
extern const mp_obj_type_t type_PixelFont;
extern const mp_obj_type_t type_Matrix;

static MP_DEFINE_CONST_FUN_OBJ_0(modpicovector___init___obj, modpicovector___init__);

static const mp_rom_map_elem_t modpicovector_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_modpicovector) },
    { MP_ROM_QSTR(MP_QSTR___init__), MP_ROM_PTR(&modpicovector___init___obj) },
    { MP_ROM_QSTR(MP_QSTR_brushes),  MP_ROM_PTR(&type_Brushes) },
    { MP_ROM_QSTR(MP_QSTR_shapes),  MP_ROM_PTR(&type_Shapes) },
    { MP_ROM_QSTR(MP_QSTR_Image),  MP_ROM_PTR(&type_Image) },
    { MP_ROM_QSTR(MP_QSTR_Font),  MP_ROM_PTR(&type_Font) },
    { MP_ROM_QSTR(MP_QSTR_PixelFont),  MP_ROM_PTR(&type_PixelFont) },
    { MP_ROM_QSTR(MP_QSTR_Matrix),  MP_ROM_PTR(&type_Matrix) },
};
static MP_DEFINE_CONST_DICT(modpicovector_globals, modpicovector_globals_table);

// Define module object.
const mp_obj_module_t modpicovector = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&modpicovector_globals,
};

MP_REGISTER_MODULE(MP_QSTR_picovector, modpicovector);
MP_REGISTER_MODULE_DELEGATION(modpicovector, modpicovector_attr);