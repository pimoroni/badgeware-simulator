
#include "picovector.hpp"
#include "primitive.hpp"
#include "image.hpp"

#define self(self_in, T) T *self = (T *)MP_OBJ_TO_PTR(self_in)

using namespace picovector;

extern "C" {

#include "py/runtime.h"

extern const mp_obj_type_t type_PicoVector;
extern const mp_obj_type_t type_Shape;
extern const mp_obj_type_t type_Brush;
//extern const mp_obj_type_t type_XORBrush;

typedef struct _shape_obt_t {
    mp_obj_base_t base;
    shape *shape;
} shape_obj_t;

typedef struct _brush_obt_t {
    mp_obj_base_t base;
    brush *brush;
} brush_obj_t;

typedef struct _modpicovector_obj_t {
    mp_obj_base_t base;
    image *fb;
    void *buffer;
    int width;
    int height;
} modpicovector_obj_t;


void *picovector_buffer;
int picovector_width = 0;
int picovector_height = 0;

mp_obj_t modpicovector_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *all_args) {
    enum {
        ARG_width, ARG_height
    };
    static const mp_arg_t allowed_args[] = {
        {MP_QSTR_width, MP_ARG_REQUIRED | MP_ARG_INT },
        {MP_QSTR_height, MP_ARG_REQUIRED | MP_ARG_INT }
    };
    mp_arg_val_t args[MP_ARRAY_SIZE(allowed_args)];
    mp_arg_parse_all_kw_array(n_args, n_kw, all_args, MP_ARRAY_SIZE(allowed_args), allowed_args, args);

    //mp_buffer_info_t bufinfo;
    //mp_get_buffer_raise(args[ARG_fb].u_obj, &bufinfo, MP_BUFFER_RW);

    modpicovector_obj_t *self = mp_obj_malloc_with_finaliser(modpicovector_obj_t, type);

    self->width = args[ARG_width].u_int;
    self->height = args[ARG_height].u_int;

    self->buffer = m_tracked_calloc(self->width * self->height, sizeof(uint32_t));

    picovector_width = self->width;
    picovector_height = self->height;
    picovector_buffer = self->buffer;

    //self->fb = new image((uint32_t *)(bufinfo.buf), 320, 240);
    self->fb = new(m_tracked_calloc(sizeof(image), 1)) image((uint32_t *)self->buffer, self->width, self->height);

    //self->fb->clear(self->fb->pen(20, 30, 40));

    return MP_OBJ_FROM_PTR(self);
}

#define m_new_class(cls, ...) new(m_new(cls, 1)) cls(__VA_ARGS__)

mp_obj_t modpicovector_regular_polygon(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args) {
    enum { ARG_self, ARG_x, ARG_y, ARG_radius, ARG_sides, ARG_stroke };
    static const mp_arg_t allowed_args[] = {
        { MP_QSTR_, MP_ARG_REQUIRED | MP_ARG_OBJ },
        { MP_QSTR_x, MP_ARG_REQUIRED | MP_ARG_OBJ },
        { MP_QSTR_y, MP_ARG_REQUIRED | MP_ARG_OBJ },
        { MP_QSTR_radius, MP_ARG_REQUIRED | MP_ARG_OBJ },
        { MP_QSTR_sides, MP_ARG_REQUIRED | MP_ARG_INT },
        { MP_QSTR_stroke, MP_ARG_OBJ, { .u_obj = mp_const_none }},
    };

    mp_arg_val_t args[MP_ARRAY_SIZE(allowed_args)];
    mp_arg_parse_all(n_args, pos_args, kw_args, MP_ARRAY_SIZE(allowed_args), allowed_args, args);

    self(args[ARG_self].u_obj, modpicovector_obj_t);

    float x = mp_obj_get_float(args[ARG_x].u_obj);
    float y = mp_obj_get_float(args[ARG_y].u_obj);
    float r = mp_obj_get_float(args[ARG_radius].u_obj);
    int e = args[ARG_sides].u_int;
    float s = args[ARG_stroke].u_obj == mp_const_none ? 0 : mp_obj_get_float(args[ARG_stroke].u_obj);

    //std::cerr << "mp_obj_malloc(shape" << std::endl;
    shape_obj_t *shape = mp_obj_malloc(shape_obj_t, &type_Shape);
    //std::cerr << "regular_polygon" << std::endl;
    shape->shape = regular_polygon(x, y, e, r);
    //std::cerr << "return MP_OBJ_FROM_PTR(..." << std::endl;
    return MP_OBJ_FROM_PTR(shape);
}

mp_obj_t modpicovector_circle(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args) {
    enum { ARG_self, ARG_x, ARG_y, ARG_radius };
    static const mp_arg_t allowed_args[] = {
        { MP_QSTR_, MP_ARG_REQUIRED | MP_ARG_OBJ },
        { MP_QSTR_x, MP_ARG_REQUIRED | MP_ARG_OBJ },
        { MP_QSTR_y, MP_ARG_REQUIRED | MP_ARG_OBJ },
        { MP_QSTR_radius, MP_ARG_REQUIRED | MP_ARG_OBJ },
    };

    mp_arg_val_t args[MP_ARRAY_SIZE(allowed_args)];
    mp_arg_parse_all(n_args, pos_args, kw_args, MP_ARRAY_SIZE(allowed_args), allowed_args, args);

    self(args[ARG_self].u_obj, modpicovector_obj_t);

    float x = mp_obj_get_float(args[ARG_x].u_obj);
    float y = mp_obj_get_float(args[ARG_y].u_obj);
    float radius = mp_obj_get_float(args[ARG_radius].u_obj);

    //std::cerr << "mp_obj_malloc(shape" << std::endl;
    shape_obj_t *shape = mp_obj_malloc(shape_obj_t, &type_Shape);
    //std::cerr << "circle" << std::endl;
    shape->shape = circle(x, y, radius);
    //std::cerr << "return MP_OBJ_FROM_PTR(..." << std::endl;
    return MP_OBJ_FROM_PTR(shape);
}

mp_obj_t modpicovector_rectangle(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args) {
    enum { ARG_self, ARG_x1, ARG_y1, ARG_x2, ARG_y2 };
    static const mp_arg_t allowed_args[] = {
        { MP_QSTR_, MP_ARG_REQUIRED | MP_ARG_OBJ },
        { MP_QSTR_x1, MP_ARG_REQUIRED | MP_ARG_OBJ },
        { MP_QSTR_y1, MP_ARG_REQUIRED | MP_ARG_OBJ },
        { MP_QSTR_x2, MP_ARG_REQUIRED | MP_ARG_OBJ },
        { MP_QSTR_y2, MP_ARG_REQUIRED | MP_ARG_OBJ },
    };

    mp_arg_val_t args[MP_ARRAY_SIZE(allowed_args)];
    mp_arg_parse_all(n_args, pos_args, kw_args, MP_ARRAY_SIZE(allowed_args), allowed_args, args);

    self(args[ARG_self].u_obj, modpicovector_obj_t);

    float x1 = mp_obj_get_float(args[ARG_x1].u_obj);
    float y1 = mp_obj_get_float(args[ARG_y1].u_obj);
    float x2 = mp_obj_get_float(args[ARG_x2].u_obj);
    float y2 = mp_obj_get_float(args[ARG_y2].u_obj);

    //std::cerr << "mp_obj_malloc(shape" << std::endl;
    shape_obj_t *shape = mp_obj_malloc(shape_obj_t, &type_Shape);
    //std::cerr << "rectangle" << std::endl;
    shape->shape = rectangle(x1, y1, x2, y2);
    //std::cerr << "return MP_OBJ_FROM_PTR(..." << std::endl;
    return MP_OBJ_FROM_PTR(shape);
}

mp_obj_t modpicovector_squircle(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args) {
    enum { ARG_self, ARG_x, ARG_y, ARG_size, ARG_n };
    static const mp_arg_t allowed_args[] = {
        { MP_QSTR_, MP_ARG_REQUIRED | MP_ARG_OBJ },
        { MP_QSTR_x, MP_ARG_REQUIRED | MP_ARG_OBJ },
        { MP_QSTR_y, MP_ARG_REQUIRED | MP_ARG_OBJ },
        { MP_QSTR_size, MP_ARG_REQUIRED | MP_ARG_OBJ },
        { MP_QSTR_n, MP_ARG_REQUIRED | MP_ARG_OBJ }
    };

    mp_arg_val_t args[MP_ARRAY_SIZE(allowed_args)];
    mp_arg_parse_all(n_args, pos_args, kw_args, MP_ARRAY_SIZE(allowed_args), allowed_args, args);

    self(args[ARG_self].u_obj, modpicovector_obj_t);

    float x = mp_obj_get_float(args[ARG_x].u_obj);
    float y = mp_obj_get_float(args[ARG_y].u_obj);
    float size = mp_obj_get_float(args[ARG_size].u_obj);
    float n = mp_obj_get_float(args[ARG_n].u_obj);

    //std::cerr << "mp_obj_malloc(shape" << std::endl;
    shape_obj_t *shape = mp_obj_malloc(shape_obj_t, &type_Shape);
    //std::cerr << "squircle" << std::endl;
    shape->shape = squircle(x, y, size, n);
    //std::cerr << "return MP_OBJ_FROM_PTR(..." << std::endl;
    return MP_OBJ_FROM_PTR(shape);
}

mp_obj_t modpicovector_arc(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args) {
    enum { ARG_self, ARG_x, ARG_y, ARG_from, ARG_to, ARG_radius };
    static const mp_arg_t allowed_args[] = {
        { MP_QSTR_, MP_ARG_REQUIRED | MP_ARG_OBJ },
        { MP_QSTR_x, MP_ARG_REQUIRED | MP_ARG_OBJ },
        { MP_QSTR_y, MP_ARG_REQUIRED | MP_ARG_OBJ },
        { MP_QSTR_from, MP_ARG_REQUIRED | MP_ARG_OBJ },
        { MP_QSTR_to, MP_ARG_REQUIRED | MP_ARG_OBJ },
        { MP_QSTR_radius, MP_ARG_REQUIRED | MP_ARG_OBJ },
    };

    mp_arg_val_t args[MP_ARRAY_SIZE(allowed_args)];
    mp_arg_parse_all(n_args, pos_args, kw_args, MP_ARRAY_SIZE(allowed_args), allowed_args, args);

    self(args[ARG_self].u_obj, modpicovector_obj_t);

    float x = mp_obj_get_float(args[ARG_x].u_obj);
    float y = mp_obj_get_float(args[ARG_y].u_obj);
    float from = mp_obj_get_float(args[ARG_from].u_obj);
    float to = mp_obj_get_float(args[ARG_to].u_obj);
    float radius = mp_obj_get_float(args[ARG_radius].u_obj);

    //std::cerr << "mp_obj_malloc(shape" << std::endl;
    shape_obj_t *shape = mp_obj_malloc(shape_obj_t, &type_Shape);
    //std::cerr << "arc" << std::endl;
    shape->shape = arc(x, y, from, to, radius);
    //std::cerr << "return MP_OBJ_FROM_PTR(..." << std::endl;
    return MP_OBJ_FROM_PTR(shape);
}

mp_obj_t modpicovector_pie(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args) {
    enum { ARG_self, ARG_x, ARG_y, ARG_from, ARG_to, ARG_radius };
    static const mp_arg_t allowed_args[] = {
        { MP_QSTR_, MP_ARG_REQUIRED | MP_ARG_OBJ },
        { MP_QSTR_x, MP_ARG_REQUIRED | MP_ARG_OBJ },
        { MP_QSTR_y, MP_ARG_REQUIRED | MP_ARG_OBJ },
        { MP_QSTR_from, MP_ARG_REQUIRED | MP_ARG_OBJ },
        { MP_QSTR_to, MP_ARG_REQUIRED | MP_ARG_OBJ },
        { MP_QSTR_radius, MP_ARG_REQUIRED | MP_ARG_OBJ },
    };

    mp_arg_val_t args[MP_ARRAY_SIZE(allowed_args)];
    mp_arg_parse_all(n_args, pos_args, kw_args, MP_ARRAY_SIZE(allowed_args), allowed_args, args);

    self(args[ARG_self].u_obj, modpicovector_obj_t);

    float x = mp_obj_get_float(args[ARG_x].u_obj);
    float y = mp_obj_get_float(args[ARG_y].u_obj);
    float from = mp_obj_get_float(args[ARG_from].u_obj);
    float to = mp_obj_get_float(args[ARG_to].u_obj);
    float radius = mp_obj_get_float(args[ARG_radius].u_obj);

    //std::cerr << "mp_obj_malloc(shape" << std::endl;
    shape_obj_t *shape = mp_obj_malloc(shape_obj_t, &type_Shape);
    //std::cerr << "pie" << std::endl;
    shape->shape = pie(x, y, from, to, radius);
    //std::cerr << "return MP_OBJ_FROM_PTR(..." << std::endl;
    return MP_OBJ_FROM_PTR(shape);
}

mp_obj_t modpicovector_star(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args) {
    enum { ARG_self, ARG_x, ARG_y, ARG_spikes, ARG_outer_radius, ARG_inner_radius };
    static const mp_arg_t allowed_args[] = {
        { MP_QSTR_, MP_ARG_REQUIRED | MP_ARG_OBJ },
        { MP_QSTR_x, MP_ARG_REQUIRED | MP_ARG_OBJ },
        { MP_QSTR_y, MP_ARG_REQUIRED | MP_ARG_OBJ },
        { MP_QSTR_spikes, MP_ARG_REQUIRED | MP_ARG_INT },
        { MP_QSTR_outer_radius, MP_ARG_REQUIRED | MP_ARG_OBJ },
        { MP_QSTR_inner_radius, MP_ARG_REQUIRED | MP_ARG_OBJ },
    };

    mp_arg_val_t args[MP_ARRAY_SIZE(allowed_args)];
    mp_arg_parse_all(n_args, pos_args, kw_args, MP_ARRAY_SIZE(allowed_args), allowed_args, args);

    self(args[ARG_self].u_obj, modpicovector_obj_t);

    float x = mp_obj_get_float(args[ARG_x].u_obj);
    float y = mp_obj_get_float(args[ARG_y].u_obj);
    int spikes = args[ARG_spikes].u_int;
    float outer_radius = mp_obj_get_float(args[ARG_outer_radius].u_obj);
    float inner_radius = mp_obj_get_float(args[ARG_inner_radius].u_obj);

    //std::cerr << "mp_obj_malloc(shape" << std::endl;
    shape_obj_t *shape = mp_obj_malloc(shape_obj_t, &type_Shape);
    //std::cerr << "star" << std::endl;
    shape->shape = star(x, y, spikes, outer_radius, inner_radius);
    //std::cerr << "return MP_OBJ_FROM_PTR(..." << std::endl;
    return MP_OBJ_FROM_PTR(shape);
}

mp_obj_t modpicovector_line(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args) {
    enum { ARG_self, ARG_x1, ARG_y1, ARG_x2, ARG_y2 };
    static const mp_arg_t allowed_args[] = {
        { MP_QSTR_, MP_ARG_REQUIRED | MP_ARG_OBJ },
        { MP_QSTR_x1, MP_ARG_REQUIRED | MP_ARG_OBJ },
        { MP_QSTR_y1, MP_ARG_REQUIRED | MP_ARG_OBJ },
        { MP_QSTR_x2, MP_ARG_REQUIRED | MP_ARG_OBJ },
        { MP_QSTR_y2, MP_ARG_REQUIRED | MP_ARG_OBJ },
    };

    mp_arg_val_t args[MP_ARRAY_SIZE(allowed_args)];
    mp_arg_parse_all(n_args, pos_args, kw_args, MP_ARRAY_SIZE(allowed_args), allowed_args, args);

    self(args[ARG_self].u_obj, modpicovector_obj_t);

    float x1 = mp_obj_get_float(args[ARG_x1].u_obj);
    float y1 = mp_obj_get_float(args[ARG_y1].u_obj);
    float x2 = mp_obj_get_float(args[ARG_x2].u_obj);
    float y2 = mp_obj_get_float(args[ARG_y2].u_obj);

    //std::cerr << "mp_obj_malloc(shape" << std::endl;
    shape_obj_t *shape = mp_obj_malloc(shape_obj_t, &type_Shape);
    //std::cerr << "line" << std::endl;
    shape->shape = line(x1, y1, x2, y2);
    //std::cerr << "return MP_OBJ_FROM_PTR(..." << std::endl;
    return MP_OBJ_FROM_PTR(shape);
}

mp_obj_t modpicovector_clear(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args) {
    enum { ARG_self };
    static const mp_arg_t allowed_args[] = {
        { MP_QSTR_, MP_ARG_REQUIRED | MP_ARG_OBJ }
    };

    mp_arg_val_t args[MP_ARRAY_SIZE(allowed_args)];
    mp_arg_parse_all(n_args, pos_args, kw_args, MP_ARRAY_SIZE(allowed_args), allowed_args, args);

    self(args[ARG_self].u_obj, modpicovector_obj_t);

    self->fb->clear();
    //std::cerr << "return MP_OBJ_FROM_PTR(..." << std::endl;
    return mp_const_none;
}


mp_obj_t modpicovector_brush(mp_obj_t self_in, mp_obj_t brush_in) {
    self(brush_in, modpicovector_obj_t);
    brush_obj_t *brush = (brush_obj_t *)MP_OBJ_TO_PTR(brush_in);

    self->fb->brush = brush->brush;

    return mp_const_none; // It took fifteen years to figure out this was missing.
}

mp_obj_t modpicovector_color_brush(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args) {
    enum { ARG_self, ARG_r, ARG_g, ARG_b, ARG_a };
    static const mp_arg_t allowed_args[] = {
        { MP_QSTR_, MP_ARG_REQUIRED | MP_ARG_OBJ },
        { MP_QSTR_r, MP_ARG_REQUIRED | MP_ARG_OBJ },
        { MP_QSTR_g, MP_ARG_REQUIRED | MP_ARG_OBJ },
        { MP_QSTR_b, MP_ARG_REQUIRED | MP_ARG_OBJ },
        { MP_QSTR_a, MP_ARG_REQUIRED | MP_ARG_OBJ },
    };

    mp_arg_val_t args[MP_ARRAY_SIZE(allowed_args)];
    mp_arg_parse_all(n_args, pos_args, kw_args, MP_ARRAY_SIZE(allowed_args), allowed_args, args);

    self(args[ARG_self].u_obj, modpicovector_obj_t);

    int r = mp_obj_get_float(args[ARG_r].u_obj);
    int g = mp_obj_get_float(args[ARG_g].u_obj);
    int b = mp_obj_get_float(args[ARG_b].u_obj);
    int a = mp_obj_get_float(args[ARG_a].u_obj);

    //std::cerr << "mp_obj_malloc(shape" << std::endl;
    brush_obj_t *brush = mp_obj_malloc(brush_obj_t, &type_Brush);

    brush->brush = m_new_class(color_brush, r, g, b, a);

    self->fb->brush = brush->brush;
    // shape_obj_t *shape = mp_obj_malloc(shape_obj_t, &type_Shape);
    // //std::cerr << "line" << std::endl;
    // shape->shape = line(x1, y1, x2, y2);
    //std::cerr << "return MP_OBJ_FROM_PTR(..." << std::endl;
    return MP_OBJ_FROM_PTR(brush);
}

mp_obj_t modpicovector_xor_brush(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args) {
    enum { ARG_self, ARG_r, ARG_g, ARG_b };
    static const mp_arg_t allowed_args[] = {
        { MP_QSTR_, MP_ARG_REQUIRED | MP_ARG_OBJ },
        { MP_QSTR_r, MP_ARG_REQUIRED | MP_ARG_OBJ },
        { MP_QSTR_g, MP_ARG_REQUIRED | MP_ARG_OBJ },
        { MP_QSTR_b, MP_ARG_REQUIRED | MP_ARG_OBJ },
    };

    mp_arg_val_t args[MP_ARRAY_SIZE(allowed_args)];
    mp_arg_parse_all(n_args, pos_args, kw_args, MP_ARRAY_SIZE(allowed_args), allowed_args, args);

    self(args[ARG_self].u_obj, modpicovector_obj_t);

    int r = mp_obj_get_float(args[ARG_r].u_obj);
    int g = mp_obj_get_float(args[ARG_g].u_obj);
    int b = mp_obj_get_float(args[ARG_b].u_obj);

    //std::cerr << "mp_obj_malloc(shape" << std::endl;
    brush_obj_t *brush = mp_obj_malloc(brush_obj_t, &type_Brush);

    brush->brush = m_new_class(xor_brush, r, g, b);

    self->fb->brush = brush->brush;
    // shape_obj_t *shape = mp_obj_malloc(shape_obj_t, &type_Shape);
    // //std::cerr << "line" << std::endl;
    // shape->shape = line(x1, y1, x2, y2);
    //std::cerr << "return MP_OBJ_FROM_PTR(..." << std::endl;
    return MP_OBJ_FROM_PTR(brush);
}


mp_obj_t modpicovector_brighten_brush(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args) {
    enum { ARG_self, ARG_amount };
    static const mp_arg_t allowed_args[] = {
        { MP_QSTR_, MP_ARG_REQUIRED | MP_ARG_OBJ },
        { ARG_amount, MP_ARG_REQUIRED | MP_ARG_OBJ },
    };

    mp_arg_val_t args[MP_ARRAY_SIZE(allowed_args)];
    mp_arg_parse_all(n_args, pos_args, kw_args, MP_ARRAY_SIZE(allowed_args), allowed_args, args);

    self(args[ARG_self].u_obj, modpicovector_obj_t);

    int amount = mp_obj_get_float(args[ARG_amount].u_obj);

    //std::cerr << "mp_obj_malloc(shape" << std::endl;
    brush_obj_t *brush = mp_obj_malloc(brush_obj_t, &type_Brush);

    brush->brush = m_new_class(brighten_brush, amount);

    self->fb->brush = brush->brush;
    // shape_obj_t *shape = mp_obj_malloc(shape_obj_t, &type_Shape);
    // //std::cerr << "line" << std::endl;
    // shape->shape = line(x1, y1, x2, y2);
    //std::cerr << "return MP_OBJ_FROM_PTR(..." << std::endl;
    return MP_OBJ_FROM_PTR(brush);
}

mp_obj_t modpicovector_draw(mp_obj_t self_in, mp_obj_t shape_in) {
    self(self_in, modpicovector_obj_t);
    shape_obj_t *shape = (shape_obj_t *)MP_OBJ_TO_PTR(shape_in);

    self->fb->draw(shape->shape);

    return mp_const_none; // It took fifteen years to figure out this was missing.
}

mp_obj_t modpicovector_loop(mp_obj_t self_in) {
    self(self_in, modpicovector_obj_t);
    //self->fb->clear();

    return mp_const_none;
}

mp_obj_t modpicovector__del__(mp_obj_t self_in) {
    self(self_in, modpicovector_obj_t);
    (void)self;
    return mp_const_none;
}



}