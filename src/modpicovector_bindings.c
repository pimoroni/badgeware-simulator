
#include "py/runtime.h"

extern mp_obj_t modpicovector_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *args);
extern mp_obj_t modpicovector_loop(mp_obj_t self_in);
extern mp_obj_t modpicovector__del__(mp_obj_t self_in);

static MP_DEFINE_CONST_FUN_OBJ_1(modpicovector_loop_obj, modpicovector_loop);
static MP_DEFINE_CONST_FUN_OBJ_1(modpicovector__del___obj, modpicovector__del__);


extern mp_obj_t modpicovector_draw(mp_obj_t self_in, mp_obj_t shape_in);
static MP_DEFINE_CONST_FUN_OBJ_2(modpicovector_draw_obj, modpicovector_draw);

extern mp_obj_t modpicovector_regular_polygon(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args);
static MP_DEFINE_CONST_FUN_OBJ_KW(modpicovector_regular_polygon_obj, 5, modpicovector_regular_polygon);

extern mp_obj_t modpicovector_circle(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args);
static MP_DEFINE_CONST_FUN_OBJ_KW(modpicovector_circle_obj, 4, modpicovector_circle);

extern mp_obj_t modpicovector_rectangle(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args);
static MP_DEFINE_CONST_FUN_OBJ_KW(modpicovector_rectangle_obj, 5, modpicovector_rectangle);

extern mp_obj_t modpicovector_squircle(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args);
static MP_DEFINE_CONST_FUN_OBJ_KW(modpicovector_squircle_obj, 5, modpicovector_squircle);

extern mp_obj_t modpicovector_arc(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args);
static MP_DEFINE_CONST_FUN_OBJ_KW(modpicovector_arc_obj, 6, modpicovector_arc);

extern mp_obj_t modpicovector_pie(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args);
static MP_DEFINE_CONST_FUN_OBJ_KW(modpicovector_pie_obj, 6, modpicovector_pie);

extern mp_obj_t modpicovector_star(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args);
static MP_DEFINE_CONST_FUN_OBJ_KW(modpicovector_star_obj, 6, modpicovector_star);

extern mp_obj_t modpicovector_line(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args);
static MP_DEFINE_CONST_FUN_OBJ_KW(modpicovector_line_obj, 5, modpicovector_line);

extern mp_obj_t modpicovector_color_brush(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args);
static MP_DEFINE_CONST_FUN_OBJ_KW(modpicovector_color_brush_obj, 5, modpicovector_color_brush);

extern mp_obj_t modpicovector_clear(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args);
static MP_DEFINE_CONST_FUN_OBJ_KW(modpicovector_clear_obj, 1, modpicovector_color_brush);


static const mp_rom_map_elem_t modpicovector_locals_dict_table[] = {
    { MP_ROM_QSTR(MP_QSTR_loop), MP_ROM_PTR(&modpicovector_loop_obj) },
    { MP_ROM_QSTR(MP_QSTR_draw), MP_ROM_PTR(&modpicovector_draw_obj) },
    { MP_ROM_QSTR(MP_QSTR_regular_polygon), MP_ROM_PTR(&modpicovector_regular_polygon_obj) },
    { MP_ROM_QSTR(MP_QSTR_circle), MP_ROM_PTR(&modpicovector_circle_obj) },
    { MP_ROM_QSTR(MP_QSTR_rectangle), MP_ROM_PTR(&modpicovector_rectangle_obj) },
    { MP_ROM_QSTR(MP_QSTR_squircle), MP_ROM_PTR(&modpicovector_squircle_obj) },
    { MP_ROM_QSTR(MP_QSTR_arc), MP_ROM_PTR(&modpicovector_arc_obj) },
    { MP_ROM_QSTR(MP_QSTR_pie), MP_ROM_PTR(&modpicovector_pie_obj) },
    { MP_ROM_QSTR(MP_QSTR_star), MP_ROM_PTR(&modpicovector_star_obj) },
    { MP_ROM_QSTR(MP_QSTR_line), MP_ROM_PTR(&modpicovector_line_obj) },
    { MP_ROM_QSTR(MP_QSTR_color_brush), MP_ROM_PTR(&modpicovector_color_brush_obj) },
    { MP_ROM_QSTR(MP_QSTR_clear), MP_ROM_PTR(&modpicovector_clear_obj) },
    { MP_ROM_QSTR(MP_QSTR___del__), MP_ROM_PTR(&modpicovector__del___obj) },
};
static MP_DEFINE_CONST_DICT(modpicovector_locals_dict, modpicovector_locals_dict_table);

MP_DEFINE_CONST_OBJ_TYPE(
    type_PicoVector,
    MP_QSTR_PicoVector,
    MP_TYPE_FLAG_NONE,
    make_new, modpicovector_make_new,
    locals_dict, &modpicovector_locals_dict
);

MP_DEFINE_CONST_OBJ_TYPE(
    type_Shape,
    MP_QSTR_Shape,
    MP_TYPE_FLAG_NONE
);

MP_DEFINE_CONST_OBJ_TYPE(
    type_ColorBrush,
    MP_QSTR_ColorBrush,
    MP_TYPE_FLAG_NONE
);

static const mp_rom_map_elem_t modpicovector_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_modpicovector) },
    { MP_ROM_QSTR(MP_QSTR_PicoVector),  MP_ROM_PTR(&type_PicoVector) },
};
static MP_DEFINE_CONST_DICT(modpicovector_globals, modpicovector_globals_table);

// Define module object.
const mp_obj_module_t modpicovector = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t *)&modpicovector_globals,
};

MP_REGISTER_MODULE(MP_QSTR_picovector, modpicovector);