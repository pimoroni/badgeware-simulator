// sokol implementation library on non-Apple platforms
#define SOKOL_IMPL

#if defined(__MINGW32__)
#define SOKOL_GLCORE
#elif defined(_WIN32)
#define SOKOL_D3D11
#elif defined(__EMSCRIPTEN__)
#define SOKOL_GLES3
#elif defined(__APPLE__)
// NOTE: on macOS, sokol.c is compiled explicitly as ObjC
#define SOKOL_METAL
#else
#define SOKOL_GLCORE
#endif

#define CIMGUI_DEFINE_ENUMS_AND_STRUCTS
#define SOKOL_ARGS_IMPL
#define SOKOL_TIME_IMPL
#define SOKOL_GL_IMPL
#define SOKOL_IMGUI_IMPL

#include "sokol.h"
