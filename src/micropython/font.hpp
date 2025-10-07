#include "mp_tracked_allocator.hpp"
#include "../picovector.hpp"
#include "../font.hpp"
#include "../span.hpp"

#define self(self_in, T) T *self = (T *)MP_OBJ_TO_PTR(self_in)
#define m_new_class(cls, ...) new(m_new(cls, 1)) cls(__VA_ARGS__)
#define m_del_class(cls, ptr) ptr->~cls(); m_del(cls, ptr, 1)

using namespace picovector;

extern "C" {

  #include "py/stream.h"
  #include "py/reader.h"
  #include "py/runtime.h"
  #include "extmod/vfs.h"

  extern const mp_obj_type_t type_Font;

  typedef struct _font_obj_t {
    mp_obj_base_t base;
    font font;
  } font_obj_t;

  mp_obj_t font__del__(mp_obj_t self_in) {
    self(self_in, font_obj_t);
    // if(self->font) {
    //   m_del_class(font, self->font);
    // }
    return mp_const_none;
  }

  // file reading helpers
  uint16_t ru16(mp_obj_t fhandle) {
    int error;
    uint16_t result;
    mp_stream_read_exactly(fhandle, &result, 2, &error);
    return result;
  }

  mp_obj_t font_load(mp_obj_t path) {
    //const char *s = mp_obj_str_get_str(path);    
    font_obj_t *result = mp_obj_malloc_with_finaliser(font_obj_t, &type_Font);

    // PNG *png = new(m_malloc(sizeof(PNG))) PNG();
    // int status = png->open(mp_obj_str_get_str(path), pngdec_open_callback, pngdec_close_callback, pngdec_read_callback, pngdec_seek_callback, pngdec_decode_callback);
    // result->image = new(m_malloc(sizeof(image))) image(png->getWidth(), png->getHeight());
    // png->decode((void *)result->image, 0);
    // m_free(png, sizeof(png));
    //mp_obj_t fn = mp_obj_new_str(s, (mp_uint_t)strlen(s));

    // get file size (maybe not needed?)
    // mp_obj_t stat = mp_vfs_stat(path);
    // mp_obj_tuple_t *tuple = (mp_obj_tuple_t*)MP_OBJ_TO_PTR(stat);
    // mp_int_t size = mp_obj_get_int(tuple->items[6]);

    // open the file for binary reading
    mp_obj_t args[2] = {path, MP_ROM_QSTR(MP_QSTR_r)};
    mp_obj_t file = mp_vfs_open(MP_ARRAY_SIZE(args), args, (mp_map_t *)&mp_const_empty_map);
    
    int error;

    debug_printf("loading font...\n");

    char marker[5];
    mp_stream_read_exactly(file, &marker, sizeof(marker), &error);
    marker[4] = 0;
    debug_printf("%s\n", marker);
    // result->font->glyphs = (glyph_t *)m_malloc(size);

    

    // int error;
    // mp_stream_read_exactly(fhandle, p, size, &error)
    mp_stream_close(file);

    return MP_OBJ_FROM_PTR(result);
  }

  static MP_DEFINE_CONST_FUN_OBJ_1(font__del___obj, font__del__);

  static MP_DEFINE_CONST_FUN_OBJ_1(font_load_obj, font_load);
  static MP_DEFINE_CONST_STATICMETHOD_OBJ(font_load_static_obj, MP_ROM_PTR(&font_load_obj));

  static const mp_rom_map_elem_t font_locals_dict_table[] = {
      { MP_ROM_QSTR(MP_QSTR___del__), MP_ROM_PTR(&font__del___obj) },
      { MP_ROM_QSTR(MP_QSTR_load), MP_ROM_PTR(&font_load_static_obj) },
      
  };
  static MP_DEFINE_CONST_DICT(font_locals_dict, font_locals_dict_table);

  MP_DEFINE_CONST_OBJ_TYPE(
      type_Font,
      MP_QSTR_Font,
      MP_TYPE_FLAG_NONE,
      locals_dict, &font_locals_dict
  );

}