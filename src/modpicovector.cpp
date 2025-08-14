
#include "picovector.hpp"

#define self(self_in, T) T *self = (T *)MP_OBJ_TO_PTR(self_in)

using namespace picovector;
using namespace picovector::brushes;
using namespace picovector::shapes;

extern "C" {

#include "py/runtime.h"

extern const mp_obj_type_t type_PicoVector;
extern const mp_obj_type_t type_Shape;

typedef struct _shape_obt_t {
    mp_obj_base_t base;
    shape *shape;
} shape_obj_t;

typedef struct _modpicovector_obj_t {
    mp_obj_base_t base;
    image *fb;
    float j;
} modpicovector_obj_t;

//std::vector<shape> shapelist(25);

uint32_t buffer[320 * 240] = {0};

mp_obj_t modpicovector_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *all_args) {
    enum {
        ARG_fb
    };
    static const mp_arg_t allowed_args[] = {
        { MP_QSTR_fb, MP_ARG_REQUIRED | MP_ARG_OBJ }
    };
    mp_arg_val_t args[MP_ARRAY_SIZE(allowed_args)];
    mp_arg_parse_all_kw_array(n_args, n_kw, all_args, MP_ARRAY_SIZE(allowed_args), allowed_args, args);

    mp_buffer_info_t bufinfo;
    mp_get_buffer_raise(args[ARG_fb].u_obj, &bufinfo, MP_BUFFER_RW);

    modpicovector_obj_t *self = mp_obj_malloc_with_finaliser(modpicovector_obj_t, type);

    //self->fb = new image((uint32_t *)(bufinfo.buf), 320, 240);
    self->fb = new(m_tracked_calloc(sizeof(image), 1)) image(buffer, 320, 240);
    self->j = 0;

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

mp_obj_t modpicovector_draw(mp_obj_t self_in, mp_obj_t shape_in) {
    self(self_in, modpicovector_obj_t);
    shape_obj_t *shape = (shape_obj_t *)MP_OBJ_TO_PTR(shape_in);

    //std::cerr << "white = colour()" << std::endl;
    colour white = colour();
    //std::cerr << "white.col = ..." << std::endl;
    white.col = self->fb->pen(255, 255, 255, 32);

    shape->shape->style = &white;

    //std::cerr << "shape->shape->draw(..." << std::endl;
    //std::cerr << "shape->shape = " << reinterpret_cast<void*>(shape->shape) << std::hex << std::endl;
    //std::cerr << "self->fb = " << reinterpret_cast<void*>(self->fb) << std::hex << std::endl;
    shape->shape->draw(*self->fb); // :/
}

mp_obj_t modpicovector_loop(mp_obj_t self_in) {
    self(self_in, modpicovector_obj_t);
    self->fb->clear(self->fb->pen(20, 30, 40));
    /*
    float stroke = sin(self->j / 50.0f) * 0.1f + 0.15f;

    colour white = colour();
    brightness lighten = brightness();
    lighten.amount = 30;
    white.col = self->fb->pen(255, 255, 255, 100);
    shapelist[0] = circle(0.0f, 0.0f, 1.0f);      
    shapelist[0].style = &white;
    shapelist[1] = circle(0.0f, 0.0f, 1.0f);      
    shapelist[1].style = &lighten;
    shapelist[1].stroke(-stroke);

    shapelist[2] = regular_polygon(0.0f, 0.0f, 3, 1.0f);
    shapelist[2].style = &white;
    shapelist[3] = regular_polygon(0.0f, 0.0f, 3, 1.0f);
    shapelist[3].style = &white;
    shapelist[3].stroke(-stroke);

    shapelist[4] = regular_polygon(0.0f, 0.0f, 4, 1.0f);
    shapelist[4].style = &white;
    shapelist[5] = regular_polygon(0.0f, 0.0f, 4, 1.0f);
    shapelist[5].style = &white;
    shapelist[5].stroke(-stroke);

    shapelist[6] = regular_polygon(0.0f, 0.0f, 5, 1.0f);
    shapelist[6].style = &white;
    shapelist[7] = regular_polygon(0.0f, 0.0f, 5, 1.0f);
    shapelist[7].style = &white;
    shapelist[7].stroke(-stroke);

    shapelist[8] = regular_polygon(0.0f, 0.0f, 6, 1.0f);
    shapelist[8].style = &white;
    shapelist[9] = regular_polygon(0.0f, 0.0f, 6, 1.0f);
    shapelist[9].style = &white;
    shapelist[9].stroke(-stroke);

    shapelist[10] = star(0.0f, 0.0f, 9.0f, 1.0f, 0.5f);      
    shapelist[10].style = &white;
    shapelist[11] = star(0.0f, 0.0f, 9.0f, 1.0f, 0.5f);      
    shapelist[11].style = &white;
    shapelist[11].stroke(-stroke);

    shapelist[12] = line(-0.5f, -0.5f, 0.5f, 0.5f);      
    shapelist[12].style = &white;
    shapelist[12].stroke(-stroke);

    shapelist[13] = squircle(0.0f, 0.0f, 0.75f, 4.0f);
    shapelist[13].style = &white;
    shapelist[14] = squircle(0.0f, 0.0f, 0.75f, 4.0f);
    shapelist[14].style = &white;
    shapelist[14].stroke(-stroke);

    shapelist[15] = pie(0.0f, 0.0f, 0.0f, 180.0f + (sin(self->j / 25.0f) * 75.0f), 1.0f);
    shapelist[15].style = &white;
    shapelist[16] = pie(0.0f, 0.0f, 0.0f, 180.0f + (sin(self->j / 25.0f) * 75.0f), 1.0f);
    shapelist[16].style = &white;
    shapelist[16].stroke(-stroke);

    shapelist[17] = rectangle(-0.75f, -0.75f, 0.75f, 0.75f);
    shapelist[17].style = &white;
    shapelist[18] = rectangle(-0.75f, -0.75f, 0.75f, 0.75f);
    shapelist[18].style = &white;
    shapelist[18].stroke(-stroke);

    self->fb->clear(self->fb->pen(20, 30, 40));

    for(int i = 0; i < shapelist.size(); i++) {
        shape shape = shapelist[i];

        int x = (i % 5) * 48 + 24;
        int y = (i / 5) * 48 + 24;

        mat3 transform;
        transform.translate(x, y).rotate(self->j / 5.0f).scale(20);
        shape.transform = transform;
        shape.draw(*self->fb);
    }

    self->j += 1.0f;
    */
    return mp_const_none;
}

mp_obj_t modpicovector__del__(mp_obj_t self_in) {
    self(self_in, modpicovector_obj_t);
    (void)self;
    return mp_const_none;
}



}