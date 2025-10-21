/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2013, 2014 Damien P. George
 * Copyright (c) 2014-2017 Paul Sokolovsky
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>

#include "py/compile.h"
#include "py/runtime.h"
#include "py/builtin.h"
#include "py/repl.h"
#include "py/gc.h"
#include "py/objstr.h"
#include "py/cstack.h"
#include "py/mperrno.h"
#include "py/mphal.h"
#include "py/mpthread.h"
#include "extmod/misc.h"
#include "extmod/modplatform.h"
#include "extmod/vfs.h"
#include "extmod/vfs_posix.h"
#include "genhdr/mpversion.h"
#include "input.h"
#include "mpthreadport.h"

// posix dirname/basename?
#include <libgen.h>

#ifndef NO_QSTR
#define SOKOL_ARGS_IMPL
#define SOKOL_TIME_IMPL
#define SOKOL_GL_IMPL

#include "sokol_app.h"
#include "sokol_args.h"
#include "sokol_gfx.h"
//#include "sokol_gl.h"
#include "sokol_log.h"
#include "sokol_glue.h"
#include "sokol_time.h"
#include "cimgui.h"
#include "sokol_imgui.h"

#define DMON_IMPL
#include "dmon/dmon.h"
#endif


// TODO: I think normal `printf` is overriden *somewhere* so we must explicitly print to stdout
//#define debug_printf(fmt, ...)
#define debug_printf(fmt, ...) fprintf(stdout, fmt, ##__VA_ARGS__)

#define warning_printf(fmt, ...) fprintf(stdout, fmt, ##__VA_ARGS__)


// Framebuffer and "emulator" state
extern uint32_t framebuffer[];
extern int screen_width;
extern int screen_height;

// Buttons for io.pressed / io.changed
uint8_t picovector_buttons;
uint8_t picovector_last_buttons;
uint8_t picovector_changed_buttons;

// Value for io.ticks
double picovector_ticks;
double picovector_last_ticks;

// MicroPython heap and stack
// #define heap_size (1024 * 1024 * (sizeof(mp_uint_t) / 4))
#define heap_size (246912) // (270 * 1024)  // 246912 = actual heap measured from device
static char heap[heap_size] = {0};
mp_obj_t pystack[1024];

// Hot reloading
volatile bool hot_reload = false;
volatile bool skip_intro = false;
char* path_root;
char *dmon_watch_path = "root/system";

static void stderr_print_strn(void *env, const char *str, size_t len) {
    (void)env;
    warning_printf("%s", str);
}

mp_uint_t mp_hal_stdout_tx_strn(const char *str, size_t len) {
    ssize_t ret;
    MP_HAL_RETRY_SYSCALL(ret, write(STDOUT_FILENO, str, len), {});
    mp_uint_t written = ret < 0 ? 0 : ret;
    int dupterm_res = mp_os_dupterm_tx_strn(str, len);
    if (dupterm_res >= 0) {
        written = MIN((mp_uint_t)dupterm_res, written);
    }
    return written;
}

// cooked is same as uncooked because the terminal does some postprocessing
void mp_hal_stdout_tx_strn_cooked(const char *str, size_t len) {
    mp_hal_stdout_tx_strn(str, len);
}

void mp_hal_stdout_tx_str(const char *str) {
    mp_hal_stdout_tx_strn(str, strlen(str));
}

const mp_print_t mp_stderr_print = {NULL, stderr_print_strn};

#define FORCED_EXIT (0x100)
// If exc is SystemExit, return value where FORCED_EXIT bit set,
// and lower 8 bits are SystemExit value. For all other exceptions,
// return 1.
static int handle_uncaught_exception(mp_obj_base_t *exc) {
    // check for SystemExit
    if (mp_obj_is_subclass_fast(MP_OBJ_FROM_PTR(exc->type), MP_OBJ_FROM_PTR(&mp_type_SystemExit))) {
        // None is an exit value of 0; an int is its value; anything else is 1
        mp_obj_t exit_val = mp_obj_exception_get_value(MP_OBJ_FROM_PTR(exc));
        mp_int_t val = 0;
        if (exit_val != mp_const_none && !mp_obj_get_int_maybe(exit_val, &val)) {
            val = 1;
        }
        return FORCED_EXIT | (val & 255);
    }

    // Report all other exceptions
    mp_obj_print_exception(&mp_plat_print, MP_OBJ_FROM_PTR(exc));
    return 1;
}

static int handle_uncaught_exception_and_forced_exit(mp_obj_base_t *exc) {
    int result = handle_uncaught_exception(exc);

    if(result & FORCED_EXIT) {
        int status_code = result & ~FORCED_EXIT;
        printf("Forced exit: %d - triggering hot reload\n", status_code);
        hot_reload = true;
    }

    return result;
}

#define LEX_SRC_STR (1)
#define LEX_SRC_VSTR (2)
#define LEX_SRC_FILENAME (3)
#define LEX_SRC_STDIN (4)

// Returns standard error codes: 0 for success, 1 for all other errors,
// except if FORCED_EXIT bit is set then script raised SystemExit and the
// value of the exit is in the lower 8 bits of the return value
static int execute_from_lexer(int source_kind, const void *source, mp_parse_input_kind_t input_kind, bool is_repl) {
    mp_hal_set_interrupt_char(CHAR_CTRL_C);

    nlr_buf_t nlr;
    if (nlr_push(&nlr) == 0) {
        //micropython_gc_enabled = true;
        // create lexer based on source kind
        mp_lexer_t *lex;
        if (source_kind == LEX_SRC_STR) {
            const char *line = source;
            lex = mp_lexer_new_from_str_len(MP_QSTR__lt_stdin_gt_, line, strlen(line), false);
        } else if (source_kind == LEX_SRC_VSTR) {
            const vstr_t *vstr = source;
            lex = mp_lexer_new_from_str_len(MP_QSTR__lt_stdin_gt_, vstr->buf, vstr->len, false);
        } else if (source_kind == LEX_SRC_FILENAME) {
            const char *filename = (const char *)source;
            qstr qfilename = qstr_from_str(filename);
            lex = mp_lexer_new_from_file(qfilename);
        } else { // LEX_SRC_STDIN
            lex = mp_lexer_new_from_fd(MP_QSTR__lt_stdin_gt_, 0, false);
        }

        qstr source_name = lex->source_name;

        #if MICROPY_PY___FILE__
        if (input_kind == MP_PARSE_FILE_INPUT) {
            mp_store_global(MP_QSTR___file__, MP_OBJ_NEW_QSTR(source_name));
        }
        #endif

        mp_parse_tree_t parse_tree = mp_parse(lex, input_kind);

        #if defined(MICROPY_UNIX_COVERAGE)
        // allow to print the parse tree in the coverage build
        if (mp_verbose_flag >= 3) {
            printf("----------------\n");
            mp_parse_node_print(&mp_plat_print, parse_tree.root, 0);
            printf("----------------\n");
        }
        #endif

        mp_obj_t module_fun = mp_compile(&parse_tree, source_name, is_repl);

        // execute it
        mp_call_function_0(module_fun);

        mp_hal_set_interrupt_char(-1);
        mp_handle_pending(true);
        nlr_pop();
        //micropython_gc_enabled = false;
        return 0;

    } else {
        // uncaught exception
        mp_hal_set_interrupt_char(-1);
        mp_handle_pending(false);
        return handle_uncaught_exception_and_forced_exit(nlr.ret_val);
    }
}

#ifdef _WIN32
#define PATHLIST_SEP_CHAR ';'
#else
#define PATHLIST_SEP_CHAR ':'
#endif

static struct {
    sg_pass_action pass_action;
    sg_image color_img;
    sg_view color_img_view;
    struct {
        sg_sampler nearest_clamp;
        sg_sampler linear_clamp;
    } smp;
} state;

mp_obj_t update_callback_obj = mp_const_none;
mp_obj_t draw_callback_obj = mp_const_none;

mp_obj_t _mp_load_global(qstr qst) {
    mp_map_t map = mp_globals_get()->map;
    mp_map_elem_t *elem = mp_map_lookup(&map, MP_OBJ_NEW_QSTR(qst), MP_MAP_LOOKUP);
    if (elem == NULL) {
        return mp_const_none;
    }
    return elem->value;
}

void* smemtrack_alloc(size_t size, void* user_data) {
    return malloc(size);
}

void smemtrack_free(void* ptr, void* user_data) {
    free(ptr);
}

/*
static const mp_rom_map_elem_t vfs_mount_readonly_table[] = {
    { MP_ROM_QSTR(MP_QSTR_readonly), MP_ROM_TRUE },
};
static MP_DEFINE_CONST_MAP(vfs_mount_readonly_map, vfs_mount_readonly_table);
*/

static void micropython_init(void) {
    /*char path[2048];
    getcwd(path, sizeof(path));
    printf("micropython_init: %s\n", path);*/

    // vfs_posix calls chdir and messes things up
    chdir(path_root);
    printf("micropython_init: mp_deinit\n");
    mp_deinit();

    #if MICROPY_PY_THREAD
    //mp_thread_init();
    #endif

    #if MICROPY_ENABLE_GC
    memset(heap, 0, sizeof(heap));
    printf("micropython_init: gc_init\n");
    gc_init(heap, heap + sizeof(heap));
    #endif

    #if MICROPY_ENABLE_PYSTACK
    printf("micropython_init: mp_pystack_init\n");
    mp_pystack_init(pystack, &pystack[MP_ARRAY_SIZE(pystack)]);
    #endif

    printf("micropython_init: mp_init\n");
    mp_init();

    #if MICROPY_EMIT_NATIVE
    // Set default emitter options
    MP_STATE_VM(default_emit_opt) = MP_EMIT_OPT_NONE;
    #endif

    printf("micropython_init mp_vfs_mount(\"/\", vfs_posix(\"%s\"))\n", path_root);

    printf("micropython_init MP_STATE_VM(vfs_cur) = %p\n", MP_STATE_VM(vfs_cur));

    mp_obj_t vfs_posix_args[1] = {
        MP_OBJ_NEW_QSTR(qstr_from_str(path_root))
    };

    // Mount the host FS at the root of our internal VFS
    mp_obj_t args[2] = {
        MP_OBJ_TYPE_GET_SLOT(&mp_type_vfs_posix, make_new)(&mp_type_vfs_posix, 1, 0, vfs_posix_args),
        MP_OBJ_NEW_QSTR(MP_QSTR__slash_),
    }; 
    mp_vfs_mount(2, args, (mp_map_t *)&mp_const_empty_map);

    // Make sure the root that was just mounted is the current VFS (it's always at
    // the end of the linked list).  Can't use chdir('/') because that will change
    // the current path within the VfsPosix object.
    MP_STATE_VM(vfs_cur) = MP_STATE_VM(vfs_mount_table);
    while (MP_STATE_VM(vfs_cur)->next != NULL) {
        MP_STATE_VM(vfs_cur) = MP_STATE_VM(vfs_cur)->next;
    }

    // It would be nice to mount system as readonly inside the writeable root filesystem
    // but this confuses vfs_posix, leaving it unable to locate modules.
    mp_sys_path = mp_obj_new_list(0, NULL);
    mp_obj_list_append(mp_sys_path, MP_OBJ_NEW_QSTR(MP_QSTR__slash_));
    mp_obj_list_append(mp_sys_path, MP_OBJ_NEW_QSTR(qstr_from_str(".frozen")));
}

static void dmon_watch_callback(dmon_watch_id watch_id, dmon_action action, const char* rootdir,
                           const char* filepath, const char* oldfilepath, void* user)
{
    switch(action) {
        case DMON_ACTION_MODIFY:
            warning_printf("Hot reload: triggered by %s\n", filepath);
            hot_reload = true;
            break;
        default:
            break;
    }
}

static int badgeware_init(void) {
    debug_printf("badgeware_init: Hello BadgeWare!\n"); 
    if(access(dmon_watch_path, R_OK) == 0) {
        dmon_watch(dmon_watch_path, dmon_watch_callback, DMON_WATCHFLAGS_RECURSIVE, NULL);
        hot_reload = true;
        return 0;
    } else {
        debug_printf("badgeware_init: Could not open %s\n", dmon_watch_path);
        return -1;
    }
}

void fetch_badgeware_update_callback() {
    debug_printf("Hot reload: Fetching update callback...\n");
    update_callback_obj = _mp_load_global(qstr_from_str("update"));
    if(update_callback_obj == mp_const_none) {
        warning_printf("WARNING: Hot reload: a function named 'update()' is not defined\n");
    }
}

static int run_file(const char* path) {
    debug_printf("Running \"%s\"\n\n", path);
    return execute_from_lexer(LEX_SRC_FILENAME, path, MP_PARSE_FILE_INPUT, true);
}

static void sokol_init(void) {
    dmon_init();
    stm_setup(); // sokol_time.h
    sg_setup(&(sg_desc){
        .environment = sglue_environment(),
        .logger.func = slog_func,
        .allocator = (sg_allocator) {
            .alloc_fn = smemtrack_alloc,
            .free_fn = smemtrack_free
        }
    });
    simgui_setup(&(simgui_desc_t){ .allocator = (simgui_allocator_t) {
        .alloc_fn = smemtrack_alloc,
        .free_fn = smemtrack_free
    }});

    state.smp.nearest_clamp = sg_make_sampler(&(sg_sampler_desc){
        .min_filter = SG_FILTER_NEAREST,
        .mag_filter = SG_FILTER_NEAREST,
        .wrap_u = SG_WRAP_CLAMP_TO_EDGE,
        .wrap_v = SG_WRAP_CLAMP_TO_EDGE,
    });

    state.smp.linear_clamp = sg_make_sampler(&(sg_sampler_desc){
        .min_filter = SG_FILTER_LINEAR,
        .mag_filter = SG_FILTER_LINEAR,
        .wrap_u = SG_WRAP_CLAMP_TO_EDGE,
        .wrap_v = SG_WRAP_CLAMP_TO_EDGE,
    });

    // initial clear color
    state.pass_action = (sg_pass_action) {
        .colors[0] = { .load_action = SG_LOADACTION_CLEAR, .clear_value = { 0.0f, 0.5f, 1.0f, 1.0 } }
    };

    state.color_img = sg_alloc_image();

    // MICROPYTHON INIT
    #ifdef SIGPIPE
    // Do not raise SIGPIPE, instead return EPIPE. Otherwise, e.g. writing
    // to peer-closed socket will lead to sudden termination of MicroPython
    // process. SIGPIPE is particularly nasty, because unix shell doesn't
    // print anything for it, so the above looks like completely sudden and
    // silent termination for unknown reason. Ignoring SIGPIPE is also what
    // CPython does. Note that this may lead to problems using MicroPython
    // scripts as pipe filters, but again, that's what CPython does. So,
    // scripts which want to follow unix shell pipe semantics (where SIGPIPE
    // means "pipe was requested to terminate, it's not an error"), should
    // catch EPIPE themselves.
    signal(SIGPIPE, SIG_IGN);
    #endif
    if(badgeware_init() != 0) {
        exit(EXIT_FAILURE);
    }
}

// from https://github.com/floooh/sokol-samples/blob/master/sapp/imgui-images-sapp.c#L52
// helper function to construct ImTextureRef from ImTextureID
// FIXME: remove when Dear Bindings offers such helper
static ImTextureRef imtexref(ImTextureID tex_id) {
    return (ImTextureRef){ ._TexID = tex_id };
}

bool first_run = true;
static void sokol_frame(void) {

    if(hot_reload) {
        if(!first_run) {
            gc_sweep_all();
        }
        first_run = false;
        micropython_init();
        stm_setup();
        picovector_last_ticks = 0;
        picovector_ticks = stm_ms(stm_now());
        run_file("boot.py");
        run_file("main.py");
        fetch_badgeware_update_callback();
        hot_reload = false;
    }

    simgui_new_frame(&(simgui_frame_desc_t){
        .width = sapp_width(),
        .height = sapp_height(),
        .delta_time = sapp_frame_duration(),
        .dpi_scale = sapp_dpi_scale(),
    });

    mp_handle_pending(true);

    igSetNextWindowPos((ImVec2){0, 0}, ImGuiCond_Once);
    igSetNextWindowSize((ImVec2){960,  720}, ImGuiCond_Once);

    // Create the image just in time... sokol was not happy about me trying to update an existing image!?
    if(screen_width && screen_height) {
        // If we ever change the output side we need to deinit state.color_img
        if(sg_query_image_width(state.color_img) != screen_width || sg_query_image_height(state.color_img) != screen_height) {
            sg_resource_state img_state = sg_query_image_state(state.color_img);
            if(img_state == SG_RESOURCESTATE_VALID || img_state == SG_RESOURCESTATE_FAILED) {
                sg_uninit_image(state.color_img);
                sg_destroy_view(state.color_img_view);
            }
        }

        if(sg_query_image_state(state.color_img) == SG_RESOURCESTATE_ALLOC) {
            sg_init_image(state.color_img, &(sg_image_desc){
                .width = screen_width,
                .height = screen_height,
                .pixel_format = SG_PIXELFORMAT_RGBA8,
                .usage.dynamic_update = true
            });
            state.color_img_view = sg_make_view(&(sg_view_desc){ .texture.image = state.color_img });
        }

        sg_update_image(state.color_img, &(sg_image_data){
            .mip_levels[0] = {
                .ptr = framebuffer,
                .size = screen_width * screen_height * sizeof(uint32_t),
            }
        });

        igPushStyleVarImVec2(ImGuiStyleVar_WindowPadding, (ImVec2){0.0f, 0.0f});
        if (igBegin("PicoVector Output", 0, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize)) {
            const ImVec2 size = {960, 960 / screen_width * screen_height};
            const ImVec2 uv0 = { 0, 0 };
            const ImVec2 uv1 = { 1, 1 };

            ImTextureID texid0 = simgui_imtextureid_with_sampler(state.color_img_view, state.smp.nearest_clamp);
            igImageEx(imtexref(texid0), size, uv0, uv1);
        }
        igEnd();
        igPopStyleVar(); // ImGuiStyleVar_WindowPadding
    }

    picovector_last_ticks = picovector_ticks;
    picovector_ticks = stm_ms(stm_now());
    picovector_changed_buttons = picovector_buttons ^ picovector_last_buttons;
    picovector_last_buttons = picovector_buttons;

    if(update_callback_obj != mp_const_none) {
        nlr_buf_t nlr;
        // We need to be able to handle any exception
        if (nlr_push(&nlr) == 0) {
            mp_obj_t result = mp_call_function_0(update_callback_obj);
            // If the update function returns false, stop calling it... I dunno why. Useful, maybe?
            if(result == mp_const_false) {
                update_callback_obj = mp_const_none;
            }
            nlr_pop();
        } else {
            update_callback_obj = mp_const_none;
            (void)handle_uncaught_exception_and_forced_exit(nlr.ret_val);
        }
    }

    sg_begin_pass(&(sg_pass){ .action = state.pass_action, .swapchain = sglue_swapchain() });
    simgui_render();
    sg_end_pass();
    sg_commit();
}

static void sokol_cleanup(void) {
    mp_deinit();
    simgui_shutdown();
    sg_shutdown();
}

static void sokol_event(const sapp_event* ev) {
    if(ev->type == SAPP_EVENTTYPE_KEY_DOWN || ev->type == SAPP_EVENTTYPE_KEY_UP) {
        bool clear = ev->type == SAPP_EVENTTYPE_KEY_UP;
        uint8_t mask = 0;
        switch (ev->key_code) {
            case SAPP_KEYCODE_H: // Home
                mask = 0b100000;
                break;
            case SAPP_KEYCODE_LEFT: // A
                mask = 0b010000;
                break;
            case SAPP_KEYCODE_SPACE: // B
                mask = 0b001000;
                break;
            case SAPP_KEYCODE_RIGHT: // C
                mask = 0b000100;
                break;
            case SAPP_KEYCODE_UP: // Up
                mask = 0b000010;
                break;
            case SAPP_KEYCODE_DOWN: // Down
                mask = 0b000001;
                break;
            case SAPP_KEYCODE_ESCAPE: // Home
                skip_intro = true;  // TODO: make this work
                hot_reload = true;
                break;
            default:
                simgui_handle_event(ev);
                return;
        }
        if (clear) {
            picovector_buttons &= ~mask;
        } else {
            picovector_buttons |= mask;
        }
    }
    simgui_handle_event(ev);
}


sapp_desc sokol_main(int argc, char* argv[]) {
    // Define a reasonable stack limit to detect stack overflow.
    mp_uint_t stack_size = 40000 * (sizeof(void *) / 4);
    #if defined(__arm__) && !defined(__thumb2__)
    // ARM (non-Thumb) architectures require more stack.
    stack_size *= 2;
    #endif

    path_root = realpath("root", NULL);

    mp_cstack_init_with_sp_here(stack_size);

    sargs_setup(&(sargs_desc){
        .argc = argc,
        .argv = argv 
    });

    return (sapp_desc){
        .init_cb = sokol_init,
        .frame_cb = sokol_frame,
        .cleanup_cb = sokol_cleanup,
        .event_cb = sokol_event,
        .window_title = "Badgeware Desktop",
        .width = 960,
        .height = 720,
        .icon.sokol_default = true,
        .logger.func = slog_func,
    };
}

void nlr_jump_fail(void *val) {
    #if MICROPY_USE_READLINE == 1
    mp_hal_stdio_mode_orig();
    #endif
    fprintf(stderr, "FATAL: uncaught NLR (You probably raised a MicroPython exception, dummy!) %p\n", val);
    exit(1);
}
