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
    pixel_font_t *font;
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

    result->font = m_new_class(pixel_font_t);

    uint16_t flags       = ru16(file);
    result->font->glyph_count = ru32(file);
    result->font->width       = ru16(file);
    result->font->height      = ru16(file);

    uint8_t bpr = result->font->width > 8 ? 2 : 1;

    size_t glyph_buffer_size = sizeof(pixel_font_glyph_t) * result->font->glyph_count;
    size_t glyph_data_buffer_size = bpr * result->font->height;

    // allocate buffer to store font glyph, path, and point data
    result->buffer_size = glyph_buffer_size + glyph_data_buffer_size;
    result->buffer = (uint8_t*)m_malloc(result->buffer_size);

    if(!result->buffer) {
      mp_raise_msg_varg(&mp_type_OSError, MP_ERROR_TEXT("couldn't allocate buffer for font data"));
    }

    pixel_font_glyph_t *glyphs = (pixel_font_glyph_t*)result->buffer;
    uint8_t *glyph_data = (uint8_t*)(result->buffer + glyph_buffer_size);

    // read codepoint list
    result->font->glyphs       = glyphs;
    result->font->glyph_data   = glyph_data;

    for(uint32_t i = 0; i < result->font->glyph_count; i++) {
      pixel_font_glyph_t *glyph = &result->font->glyphs[i];
      glyph->codepoint = ru32(file);
      glyph->width = ru16(file);
    }

    // read glyph data into buffer
    mp_stream_read_exactly(file, result->buffer + glyph_buffer_size, result->buffer_size - glyph_buffer_size, &error);
    result->font->glyph_data = result->buffer + glyph_buffer_size;

    debug_printf("glyph_data = %p\n", result->font->glyph_data);


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