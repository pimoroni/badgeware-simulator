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
#define debug_printf(fmt, ...)
//#define debug_printf(fmt, ...) fprintf(stdout, fmt, ##__VA_ARGS__)

#define warning_printf(fmt, ...) fprintf(stdout, fmt, ##__VA_ARGS__)



// Command line options, with their defaults
static bool compile_only = false;
static uint emit_opt = MP_EMIT_OPT_NONE;

extern bool micropython_gc_enabled;

#if MICROPY_ENABLE_GC
// Heap size of GC heap (if enabled)
// Make it larger on a 64 bit machine, because pointers are larger.
long heap_size = 1024 * 1024 * (sizeof(mp_uint_t) / 4);
#endif

// Number of heaps to assign by default if MICROPY_GC_SPLIT_HEAP=1
#ifndef MICROPY_GC_SPLIT_HEAP_N_HEAPS
#define MICROPY_GC_SPLIT_HEAP_N_HEAPS (1)
#endif

#if !MICROPY_PY_SYS_PATH
#error "The unix port requires MICROPY_PY_SYS_PATH=1"
#endif

#if !MICROPY_PY_SYS_ARGV
#error "The unix port requires MICROPY_PY_SYS_ARGV=1"
#endif

static void stderr_print_strn(void *env, const char *str, size_t len);

const mp_print_t mp_stderr_print = {NULL, stderr_print_strn};

#define FORCED_EXIT (0x100)
// If exc is SystemExit, return value where FORCED_EXIT bit set,
// and lower 8 bits are SystemExit value. For all other exceptions,
// return 1.
static int handle_uncaught_exception(mp_obj_base_t *exc) {
    debug_printf("handle_uncaught_exception(...\n");
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
    mp_obj_print_exception(&mp_stderr_print, MP_OBJ_FROM_PTR(exc));
    return 1;
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
    debug_printf("nlr_push()\n");
    if (nlr_push(&nlr) == 0) {
        micropython_gc_enabled = true;
        // create lexer based on source kind
        debug_printf("create lexer...\n");
        mp_lexer_t *lex;
        if (source_kind == LEX_SRC_STR) {
            debug_printf("LEX_SRC_STR...\n");
            const char *line = source;
            lex = mp_lexer_new_from_str_len(MP_QSTR__lt_stdin_gt_, line, strlen(line), false);
        } else if (source_kind == LEX_SRC_VSTR) {
            debug_printf("LEX_SRC_VSTR...\n");
            const vstr_t *vstr = source;
            lex = mp_lexer_new_from_str_len(MP_QSTR__lt_stdin_gt_, vstr->buf, vstr->len, false);
        } else if (source_kind == LEX_SRC_FILENAME) {
            debug_printf("LEX_SRC_FILENAME...\n");
            const char *filename = (const char *)source;
            debug_printf("qstr_from_str(%s)...\n", filename);
            qstr qfilename = qstr_from_str(filename);
            debug_printf("mp_lexer_new_from_file(qfilename)...\n");
            lex = mp_lexer_new_from_file(qfilename);
        } else { // LEX_SRC_STDIN
            debug_printf("LEX_SRC_STDIN...\n");
            lex = mp_lexer_new_from_fd(MP_QSTR__lt_stdin_gt_, 0, false);
        }
        debug_printf("lexer ok...\n");

        qstr source_name = lex->source_name;

        #if MICROPY_PY___FILE__
        if (input_kind == MP_PARSE_FILE_INPUT) {
            debug_printf("set __file__..\n");
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

        debug_printf("mp_compile\n");
        mp_obj_t module_fun = mp_compile(&parse_tree, source_name, is_repl);

        if (!compile_only) {
            // execute it
            debug_printf("mp_call_function_0\n");
            mp_call_function_0(module_fun);
            debug_printf("hello?\n");
        }

        debug_printf("mp_hal_set_interrupt_char(-1)\n");
        mp_hal_set_interrupt_char(-1);
        debug_printf("mp_handle_pending\n");
        mp_handle_pending(true);
        nlr_pop();
        micropython_gc_enabled = false;
        return 0;

    } else {
        // uncaught exception
        mp_hal_set_interrupt_char(-1);
        mp_handle_pending(false);
        return handle_uncaught_exception(nlr.ret_val);
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

extern uint32_t buffer[320 * 240];

void* smemtrack_alloc(size_t size, void* user_data) {
    return malloc(size);
}
void smemtrack_free(void* ptr, void* user_data) {
    free(ptr);
}

static int run_file(const char* path) {
    debug_printf("Running....%s?\n", path);
    // Set base dir of the script as first entry in sys.path.
    
    debug_printf("do_file\n");
    gc_collect();

    int ret = execute_from_lexer(LEX_SRC_FILENAME, path, MP_PARSE_FILE_INPUT, true);

    debug_printf("done?\n");

    debug_printf("fetching update callback...\n");
    update_callback_obj = _mp_load_global(qstr_from_str("update"));
    if(update_callback_obj == mp_const_none) {
        //TODO switch out this URL for the final one
        warning_printf("WARNING: a function named 'update(ticks)' is not defined\n");
        //mp_raise_msg(&mp_type_NameError, MP_ERROR_TEXT("a function named 'update(ticks)' is not defined"));
    }

    return ret;
}

volatile bool hot_reload = false;
char *hot_reload_code;

static void watch_callback(dmon_watch_id watch_id, dmon_action action, const char* rootdir,
                           const char* filepath, const char* oldfilepath, void* user)
{
    // receive change events. type of event is stored in 'action' variable
    char *watch_path = (char*)user;
    char path[PATH_MAX] = {};
    switch(action) {
        case DMON_ACTION_MODIFY:
            memcpy(path, rootdir, strlen(rootdir));
            memcpy(path + strlen(rootdir), filepath, strlen(filepath));
            path[strlen(rootdir) + strlen(filepath)] = '\0';
            if(strcmp(path, watch_path) == 0) {
                //run_file(path);
                warning_printf("WARNING: Hot reload triggered by %s\n", path);
                hot_reload = true;
            } else {
                warning_printf("WARNING: Ignored change in %s\n", path);
            }
            break;
        default:
            break;
    }
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
    /*sgl_setup(&(sgl_desc_t){
        .logger.func = slog_func,
    });*/

    for(int i = 0; i < sizeof(buffer) / 4; i++) {
        buffer[i] = 0xFF0000FF;
    }
    state.color_img = sg_make_image(&(sg_image_desc){
        .width = 320,
        .height = 240,
        .pixel_format = SG_PIXELFORMAT_RGBA8,
        .data.subimage[0][0] = SG_RANGE(buffer)
    });

    for(int i = 0; i < sizeof(buffer) / 4; i++) {
        buffer[i] = 0xFF00FF00;
    }

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

    #if MICROPY_ENABLE_GC
    #if !MICROPY_GC_SPLIT_HEAP
    char *heap = malloc(heap_size);
    gc_init(heap, heap + heap_size);
    #else
    assert(MICROPY_GC_SPLIT_HEAP_N_HEAPS > 0);
    char *heaps[MICROPY_GC_SPLIT_HEAP_N_HEAPS];
    long multi_heap_size = heap_size / MICROPY_GC_SPLIT_HEAP_N_HEAPS;
    for (size_t i = 0; i < MICROPY_GC_SPLIT_HEAP_N_HEAPS; i++) {
        heaps[i] = malloc(multi_heap_size);
        if (i == 0) {
            gc_init(heaps[i], heaps[i] + multi_heap_size);
        } else {
            gc_add(heaps[i], heaps[i] + multi_heap_size);
        }
    }
    #endif
    #endif

    #if MICROPY_ENABLE_PYSTACK
    static mp_obj_t pystack[1024];
    mp_pystack_init(pystack, &pystack[MP_ARRAY_SIZE(pystack)]);
    #endif

    debug_printf("mp_init\n");
    mp_init();

    #if MICROPY_EMIT_NATIVE
    // Set default emitter options
    MP_STATE_VM(default_emit_opt) = emit_opt;
    #else
    (void)emit_opt;
    #endif

    #if MICROPY_VFS_POSIX
    {
        // Mount the host FS at the root of our internal VFS
        mp_obj_t args[2] = {
            MP_OBJ_TYPE_GET_SLOT(&mp_type_vfs_posix, make_new)(&mp_type_vfs_posix, 0, 0, NULL),
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
    }
    #endif

    mp_sys_path = mp_obj_new_list(0, NULL);
    mp_obj_list_append(mp_sys_path, MP_OBJ_NEW_QSTR(MP_QSTR_));

    const char *path = sargs_value("code");
    debug_printf("Running code: %s\n", path);
    hot_reload_code = realpath(path, NULL);

    if (hot_reload_code == NULL) {
        mp_printf(&mp_stderr_print, "MicroPython: can't open file '%s': [Errno %d]\n", hot_reload_code, errno, strerror(errno));
        // TODO: Exit
    }

    char *p = strrchr(hot_reload_code, '/');

    debug_printf("mp_obj_list_store....?\n");
    mp_obj_list_store(mp_sys_path, MP_OBJ_NEW_SMALL_INT(0), mp_obj_new_str_via_qstr(hot_reload_code, p - hot_reload_code));
    
    char *dname = dirname(hot_reload_code);
    int ret = -1;
    //while (ret != 255) {

        debug_printf("Watching directory %s\n", dname);
        dmon_watch(dname, watch_callback, DMON_WATCHFLAGS_RECURSIVE, (void*)hot_reload_code);
        hot_reload = true;
    //}
    (void)ret;

    debug_printf("free(abspath)\n");
    //free(abspath); // TODO: using this in userdata uh don't worrry abooout it
    free(dname);
}

// from https://github.com/floooh/sokol-samples/blob/master/sapp/imgui-images-sapp.c#L52
// helper function to construct ImTextureRef from ImTextureID
// FIXME: remove when Dear Bindings offers such helper
static ImTextureRef imtexref(ImTextureID tex_id) {
    return (ImTextureRef){ ._TexID = tex_id };
}

static void _igWindowMaintainAspect(ImGuiSizeCallbackData* data)
{
    ImVec2 *aspect = (ImVec2 *)data->UserData;
    data->DesiredSize.x = (data->DesiredSize.y / aspect->y) * aspect->x;
}


int bw_repl_cursor_pos = 0;
int bw_repl_last_cursor_pos = -1;
int bw_repl_last_linebreak_pos = 0;
#define BW_REPL_SIZE (1024 * 50)
static char bw_repl_buf[BW_REPL_SIZE] = {};
char bw_repl_continuation_buffer[8192];
int bw_repl_continuation_ptr = 0;
const char* BW_REPL_TAB = "    ";
bool bw_repl_exec = false;


ImGuiInputTextCallbackData* active_callback = NULL;

static void bw_repl_print_strn(const char *str, size_t len) {
    /*if(active_callback) {
        ImGuiInputTextCallbackData_InsertChars(active_callback, active_callback->CursorPos, str, str + len);
    }*/
    memcpy(bw_repl_buf + bw_repl_cursor_pos, str, len);
    bw_repl_cursor_pos += len;
}

/*
static void bw_repl_print_str(const char *str) {
    bw_repl_print_strn(str, strlen(str));
}
*/
static void stderr_print_strn(void *env, const char *str, size_t len) {
    (void)env;
    warning_printf("%s", str);
    bw_repl_print_strn(str, len);
}

mp_uint_t mp_hal_stdout_tx_strn(const char *str, size_t len) {
    warning_printf("%s", str);
    bw_repl_print_strn(str, len);
    return len;
}

// cooked is same as uncooked because the terminal does some postprocessing
void mp_hal_stdout_tx_strn_cooked(const char *str, size_t len) {
    mp_hal_stdout_tx_strn(str, len);
}

void mp_hal_stdout_tx_str(const char *str) {
    mp_hal_stdout_tx_strn(str, strlen(str));
}


static int _igReplCallback(ImGuiInputTextCallbackData* data) {
    if(bw_repl_exec) {
        ImGuiInputTextCallbackData_SelectAll(data);
        ImGuiInputTextCallbackData_ClearSelection(data);
        memset(data->Buf, 0, data->BufSize);
        memset(bw_repl_continuation_buffer, 0, sizeof(bw_repl_continuation_buffer));
        data->CursorPos = 0;
        data->BufTextLen = 0;
        bw_repl_exec = false;
    }

    if(data->EventFlag == ImGuiInputTextFlags_CallbackCompletion) {
        ImGuiInputTextCallbackData_InsertChars(data, data->CursorPos, BW_REPL_TAB, BW_REPL_TAB + 4);
        //bw_repl_print_str(BW_REPL_TAB);
    }
    if(data->EventFlag == ImGuiInputTextFlags_CallbackAlways) {
        char last = data->Buf[data->CursorPos - 1];
        if (last == '\n') {
            data->Buf[data->CursorPos - 1] = '\0';
            bool cont = mp_repl_continue_with_input(data->Buf);
            data->Buf[data->CursorPos - 1] = '\n';
            if(!cont) {
                bw_repl_exec = true;
                return 1;
            }
        }
        return 0;
    }

    /*
    if(data->EventFlag == ImGuiInputTextFlags_CallbackAlways) {
        if(bw_repl_last_cursor_pos == bw_repl_cursor_pos) {
            return 0;
        }
        bw_repl_last_cursor_pos = bw_repl_cursor_pos;
        if (bw_repl_cursor_pos == 0) {
            //strncpy(&data->Buf[data->CursorPos], pr, 1024);
            //data->CursorPos += strnlen(pr, 1024);
            char *pr = (char *)mp_repl_get_ps1();
            //ImGuiInputTextCallbackData_InsertChars(data, bw_repl_cursor_pos, pr, pr + strnlen(pr, 1024));
            //bw_repl_cursor_pos = data->CursorPos;
            bw_repl_print_str(pr);
            bw_repl_last_linebreak_pos = bw_repl_cursor_pos;
        }
        char last = bw_repl_buf[data->CursorPos - 1];
        //printf("Last: %c\n", last);
        if(last == '\n') {
            char *line = &bw_repl_buf[bw_repl_last_linebreak_pos];
            int endline = bw_repl_cursor_pos - 1 - bw_repl_last_linebreak_pos;
            //printf("line: %s\n", line);
            bw_repl_last_linebreak_pos = bw_repl_cursor_pos - 1;

            line[endline] = '\0';
            size_t line_len = strlen(line) + 1;
            line[endline] = '\n';
    
            memcpy(bw_repl_continuation_buffer + bw_repl_continuation_ptr, line, line_len);
            bw_repl_continuation_ptr += line_len;

            bw_repl_continuation_buffer[bw_repl_continuation_ptr - 1] = '\0';
            bool continuation = mp_repl_continue_with_input(bw_repl_continuation_buffer);
            bw_repl_continuation_buffer[bw_repl_continuation_ptr - 1] = '\n';

            warning_printf("cont buf: %s\n", bw_repl_continuation_buffer);
            warning_printf("repl buf: %s\n", bw_repl_buf);
            
            if (continuation) {
                char *pr = (char *)mp_repl_get_ps2();
                ImGuiInputTextCallbackData_InsertChars(data, data->CursorPos, pr, pr + strnlen(pr, 1024));
                bw_repl_print_str(pr);
                bw_repl_last_linebreak_pos = bw_repl_cursor_pos;
            } else {
                //active_callback = data;
                int ret = execute_from_lexer(LEX_SRC_STR, bw_repl_continuation_buffer, MP_PARSE_SINGLE_INPUT, true);
                memset(bw_repl_continuation_buffer, 0, bw_repl_continuation_ptr);
                bw_repl_continuation_ptr = 0;
                (void)ret;
                //active_callback = NULL;

                char *pr = (char *)mp_repl_get_ps1();
                ImGuiInputTextCallbackData_InsertChars(data, data->CursorPos, pr, pr + strnlen(pr, 1024));
                //bw_repl_cursor_pos = data->CursorPos;
                //bw_repl_print_str(pr);
                //bw_repl_last_linebreak_pos = bw_repl_cursor_pos;
            }
        }
    }
        */
    return 0;
}

static void sokol_frame(void) {
    simgui_new_frame(&(simgui_frame_desc_t){
        .width = sapp_width(),
        .height = sapp_height(),
        .delta_time = sapp_frame_duration(),
        .dpi_scale = sapp_dpi_scale(),
    });

    if(hot_reload) {
        run_file(hot_reload_code);
        hot_reload = false;
    }

    //sgl_defaults();
    sg_update_image(state.color_img, &(sg_image_data){
        .subimage[0][0] = SG_RANGE(buffer)
    });

    /*sgl_enable_texture();
    sgl_matrix_mode_projection();
    const float aspect = sapp_heightf() / sapp_widthf();
    sgl_ortho(-1.0f, +1.0f, aspect, -aspect, -1.0f, +1.0f);
    sgl_matrix_mode_modelview();*/

    //sg_color color = { 0.0f, 0.0f, 0.0f };
    mp_handle_pending(true);

    if(update_callback_obj != mp_const_none) {
        nlr_buf_t nlr;
        // We need to be able to handle any exception
        if (nlr_push(&nlr) == 0) {
            mp_obj_t result = mp_call_function_1(update_callback_obj, mp_obj_new_int_from_ull(stm_ms(stm_now())));
            // If the update function returns false, stop calling it... I dunno why. Useful, maybe?
            if(result == mp_const_false) {
                update_callback_obj = mp_const_none;
            }
            nlr_pop();
        } else {
            update_callback_obj = mp_const_none;
            handle_uncaught_exception(nlr.ret_val);
        }
    }

    /*=== UI CODE STARTS HERE ===*/
    igSetNextWindowPos((ImVec2){0, 480}, ImGuiCond_Once);
    igSetNextWindowSize((ImVec2){640, 120}, ImGuiCond_Once);

    //igPushStyleVarImVec2(ImGuiStyleVar_WindowPadding, (ImVec2){0.0f, 0.0f});
    if (igBegin("MicroPython Output", 0, ImGuiWindowFlags_NoTitleBar )) {
        igText("%s", bw_repl_buf);
    }
    igEnd();

    igSetNextWindowPos((ImVec2){0, 600}, ImGuiCond_Once);
    igSetNextWindowSize((ImVec2){640, 120}, ImGuiCond_Once);
    if (igBegin("MicroPython Input", 0, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar )) {
        const ImVec2 size = igGetWindowContentRegionMax();
        if(igInputTextMultilineEx("", bw_repl_continuation_buffer, BW_REPL_SIZE, size, ImGuiInputTextFlags_CallbackCompletion | ImGuiInputTextFlags_CallbackHistory | ImGuiInputTextFlags_CallbackAlways, _igReplCallback, NULL)){
            if(bw_repl_exec) {
                int ret = execute_from_lexer(LEX_SRC_STR, bw_repl_continuation_buffer, MP_PARSE_SINGLE_INPUT, true);
                (void)ret;
            }
        }
    }
    igEnd();
    //igPopStyleVar(); // ImGuiStyleVar_WindowPadding

    igSetNextWindowPos((ImVec2){0, 0}, ImGuiCond_Once);
    igSetNextWindowSize((ImVec2){640, 480}, ImGuiCond_Once);
    igSetNextWindowSizeConstraints((ImVec2){320, 240}, (ImVec2){1280, 960}, _igWindowMaintainAspect, &(ImVec2){4, 3});

    igPushStyleVarImVec2(ImGuiStyleVar_WindowPadding, (ImVec2){0.0f, 0.0f});
    if (igBegin("PicoVector Output", 0, ImGuiWindowFlags_NoScrollbar)) {
        const ImVec2 size = igGetWindowSize();
        const ImVec2 uv0 = { 0, 0 };
        const ImVec2 uv1 = { 1, 1 };
        sg_image img = state.color_img;
        ImTextureID texid0 = simgui_imtextureid_with_sampler(img, state.smp.nearest_clamp);
        igImageEx(imtexref(texid0), size, uv0, uv1);
    }
    igEnd();
    igPopStyleVar(); // ImGuiStyleVar_WindowPadding

  
    /*=== UI CODE ENDS HERE ===*/

    //printf("%f\n", color.r);

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
    simgui_handle_event(ev);
}
sapp_desc sokol_main(int argc, char* argv[]) {
    // Define a reasonable stack limit to detect stack overflow.
    mp_uint_t stack_size = 40000 * (sizeof(void *) / 4);
    #if defined(__arm__) && !defined(__thumb2__)
    // ARM (non-Thumb) architectures require more stack.
    stack_size *= 2;
    #endif

    #if MICROPY_PY_THREAD
    mp_thread_init();
    #endif

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
        .width = 800,
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