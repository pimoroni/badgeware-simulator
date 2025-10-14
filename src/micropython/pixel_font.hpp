#include "mp_tracked_allocator.hpp"
#include "../pixel_font.hpp"
#include "../span.hpp"

#include "mp_helpers.hpp"

using namespace picovector;

extern "C" {

  #include "py/stream.h"
  #include "py/reader.h"
  #include "py/runtime.h"
  #include "extmod/vfs.h"

  extern const mp_obj_type_t type_PixelFont;

  typedef struct _pixel_font_obj_t {
    mp_obj_base_t base;
    pixel_font_t font;
    uint8_t *buffer;
    uint32_t buffer_size;
  } pixel_font_obj_t;

  mp_obj_t pixel_font__del__(mp_obj_t self_in) {
    self(self_in, pixel_font_obj_t);
#if PICO
    m_free(self->buffer);
#else
    m_free(self->buffer, self->buffer_size);
#endif
    return mp_const_none;
  }

  mp_obj_t pixel_font_load(mp_obj_t path) {
    pixel_font_obj_t *result = mp_obj_malloc_with_finaliser(pixel_font_obj_t, &type_PixelFont);

    mp_obj_t args[2] = {path, MP_ROM_QSTR(MP_QSTR_r)};
    mp_obj_t file = mp_vfs_open(MP_ARRAY_SIZE(args), args, (mp_map_t *)&mp_const_empty_map);

    int error;

    char marker[4];
    mp_stream_read_exactly(file, &marker, sizeof(marker), &error);

    if(memcmp(marker, "ppf!", 4) != 0) {
      mp_raise_msg_varg(&mp_type_OSError, MP_ERROR_TEXT("failed to load font, missing PPF header"));
    }

    uint16_t glyph_count = ru32(file);
    uint16_t width       = ru16(file);
    uint16_t height      = ru16(file);
    uint16_t flags       = ru16(file);

    // load codepoints

    uint8_t bpr = (width + 1) / 8;

    // allocate buffer to store glyph data
    result->buffer_size = glyph_count * bpr * height;
    result->buffer = (uint8_t*)m_malloc(result->buffer_size);

    if(!result->buffer) {
      mp_raise_msg_varg(&mp_type_OSError, MP_ERROR_TEXT("couldn't allocate buffer for font data"));
    }

    // read glyph data into buffer
    mp_stream_read_exactly(file, result->buffer, result->buffer_size, &error);

    for(int i = 0; i < glyph_count; i++) {
      pixel_glyph_t glyph;
      uint32_t codepoint = ru32(file);
      glyph.width = ru16(file);
      glyph.data = (void*)&result->buffer[bpr * height * i];

      //result->font.glyphs.emplace(codepoint, glyph);
    }

    mp_stream_close(file);

    return MP_OBJ_FROM_PTR(result);
  }

  static MP_DEFINE_CONST_FUN_OBJ_1(pixel_font__del___obj, pixel_font__del__);

  static MP_DEFINE_CONST_FUN_OBJ_1(pixel_font_load_obj, pixel_font_load);
  static MP_DEFINE_CONST_STATICMETHOD_OBJ(pixel_font_load_static_obj, MP_ROM_PTR(&pixel_font_load_obj));

  static const mp_rom_map_elem_t pixel_font_locals_dict_table[] = {
      { MP_ROM_QSTR(MP_QSTR___del__), MP_ROM_PTR(&pixel_font__del___obj) },
      { MP_ROM_QSTR(MP_QSTR_load), MP_ROM_PTR(&pixel_font_load_static_obj) },

  };
  static MP_DEFINE_CONST_DICT(pixel_font_locals_dict, pixel_font_locals_dict_table);

  MP_DEFINE_CONST_OBJ_TYPE(
      type_PixelFont,
      MP_QSTR_PixelFont,
      MP_TYPE_FLAG_NONE,
      locals_dict, &pixel_font_locals_dict
  );

}