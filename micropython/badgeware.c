

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

#include "badgeware.h"
#include "modsimulator.h"


#ifndef NO_QSTR
#define DMON_IMPL
#include "dmon/dmon.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"

// posix dirname/basename?
#include <libgen.h>

#include <inttypes.h>
#include <time.h>
#endif


// Buttons for io.pressed / io.changed
// These are included in src/micropython/input.hpp using extern
uint8_t picovector_buttons;
uint8_t picovector_last_buttons;
uint8_t picovector_changed_buttons;

// Value for io.ticks
// These are included in src/micropython/input.hpp using extern
double picovector_ticks;
double picovector_last_ticks;

// MicroPython heap and stack
// #define heap_size (1024 * 1024 * (sizeof(mp_uint_t) / 4))
#define heap_size (246912) // (270 * 1024)  // 246912 = actual heap measured from device
static char heap[heap_size] = {0};
mp_obj_t pystack[1024];

// Memory allocation wizard magic
uint64_t mp_allocator_allocs = 0;

// Hot reloading
static bool hot_reload = false;
static char* path_screenshots;
static char* path_root;
static char* dmon_watch_path;
static mp_obj_t update_callback_obj = mp_const_none;

#define LEX_SRC_STR (1)
#define LEX_SRC_VSTR (2)
#define LEX_SRC_FILENAME (3)
#define LEX_SRC_STDIN (4)



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


static mp_obj_t _mp_load_global(qstr qst) {
    mp_map_t map = mp_globals_get()->map;
    mp_map_elem_t *elem = mp_map_lookup(&map, MP_OBJ_NEW_QSTR(qst), MP_MAP_LOOKUP);
    if (elem == NULL) {
        return mp_const_none;
    }
    return elem->value;
}

/*
static const mp_rom_map_elem_t vfs_mount_readonly_table[] = {
    { MP_ROM_QSTR(MP_QSTR_readonly), MP_ROM_TRUE },
};
static MP_DEFINE_CONST_MAP(vfs_mount_readonly_map, vfs_mount_readonly_table);
*/

void badgeware_preinit(void) {
    // Define a reasonable stack limit to detect stack overflow.
    mp_uint_t stack_size = 40000 * (sizeof(void *) / 4);
    #if defined(__arm__) && !defined(__thumb2__)
    // ARM (non-Thumb) architectures require more stack.
    stack_size *= 2;
    #endif

    mp_cstack_init_with_sp_here(stack_size);
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

int badgeware_init(const char *root_path, const char *watch_path, const char *screenshot_path) {
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

    path_screenshots = realpath(screenshot_path, NULL);
    path_root = realpath(root_path, NULL);
    dmon_watch_path = realpath(watch_path, NULL);


    if(access(path_screenshots, R_OK) != 0) {
        printf("badgeware_init: Could not open screenshot dir: %s\n", screenshot_path);
        return 1;
    }
    if(access(path_root, R_OK) != 0) {
        printf("badgeware_init: Could not open root dir: %s\n", root_path);
        return 1;
    }
    if(access(dmon_watch_path, R_OK) != 0) {
        printf("badgeware_init: Could not open watch dir: %s\n", watch_path);
        return 1;
    }

    dmon_init();

    debug_printf("badgeware_init: Hello BadgeWare!\n"); 
    if(access(dmon_watch_path, R_OK) == 0) {
        dmon_watch(dmon_watch_path, dmon_watch_callback, DMON_WATCHFLAGS_RECURSIVE, NULL);
        hot_reload = true;
        return 0;
    } else {
        debug_printf("badgeware_init: Could not open %s\n", dmon_watch_path);
        return -1;
    }

    return 0;
}

static void micropython_reinit(void) {
    /*char path[2048];
    getcwd(path, sizeof(path));
    printf("micropython_init: %s\n", path);*/

    // vfs_posix calls chdir and messes things up
    int result = chdir(path_root);
    (void)result;
    printf("micropython_init: mp_deinit\n");
    mp_deinit();

    #if MICROPY_PY_THREAD
    //mp_thread_init();
    #endif

    #if MICROPY_ENABLE_GC
    memset(heap, 0, sizeof(heap));
    debug_printf("micropython_init: gc_init\n");
    gc_init(heap, heap + sizeof(heap));
    #endif

    #if MICROPY_ENABLE_PYSTACK
    debug_printf("micropython_init: mp_pystack_init\n");
    mp_pystack_init(pystack, &pystack[MP_ARRAY_SIZE(pystack)]);
    #endif

    debug_printf("micropython_init: mp_init\n");
    mp_init();

    #if MICROPY_EMIT_NATIVE
    // Set default emitter options
    MP_STATE_VM(default_emit_opt) = MP_EMIT_OPT_NONE;
    #endif

    debug_printf("micropython_init: mp_vfs_mount(\"/\", vfs_posix(\"%s\"))\n", path_root);

    debug_printf("micropython_init: MP_STATE_VM(vfs_cur) = %p\n", MP_STATE_VM(vfs_cur));

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

void badgeware_deinit() {
    mp_deinit();
}

void badgeware_input(uint8_t mask, bool set) {
    if(set) {
        picovector_buttons |= mask;
    } else {
        picovector_buttons &= ~mask;
    }
}

int badgeware_screenshot(void *buffer, const char *fn) {
    char filename[PATH_MAX];
    memcpy(filename, path_screenshots, strlen(path_screenshots));
    if(fn && strlen(fn)) {
        snprintf(filename + strlen(path_screenshots), PATH_MAX, "/%s.png", fn);
    } else {
        struct timeval tv;
        gettimeofday(&tv, NULL);
        unsigned long long time_ms = (unsigned long long)(tv.tv_sec) * 1000 + (unsigned long long)(tv.tv_usec) / 1000;
        snprintf(filename + strlen(path_screenshots), PATH_MAX, "/screenshot-%llu.png", time_ms);
    }
    if(access(filename, R_OK) == 0) {
        debug_printf("badgeware_screenshot: Refusing to overwrite %s\n", filename);
        return -1;
    }
    debug_printf("badgeware_screenshot: Saving to %s\n", filename);
    return stbi_write_png((const char*)filename, 160, 120, 4, buffer, 0);
}

void badgeware_trigger_hot_reload(void) {
    hot_reload = true;
}

bool badgeware_will_hot_reload(void) {
    return hot_reload;
}

void badgeware_update(int ticks) {
    mp_handle_pending(true);

    static bool first_run = true;

    if(hot_reload || first_run) {
        if(!first_run) {
            gc_sweep_all();
        }
        first_run = false;
        micropython_reinit();
        picovector_last_ticks = 0;
        picovector_ticks = ticks;
        run_file("boot.py");
        run_file("main.py");
        fetch_badgeware_update_callback();
        hot_reload = false;
    }

    picovector_last_ticks = picovector_ticks;
    picovector_ticks = ticks;
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
            if(debug_show_alloc_count) {
                debug_printf("main: %" PRIu64 " MPAllocator allocs this frame.\n", mp_allocator_allocs);
            }
            mp_allocator_allocs = 0;
        } else {
            update_callback_obj = mp_const_none;
            (void)handle_uncaught_exception_and_forced_exit(nlr.ret_val);
        }
    }
}

void nlr_jump_fail(void *val) {
    #if MICROPY_USE_READLINE == 1
    mp_hal_stdio_mode_orig();
    #endif
    fprintf(stderr, "FATAL: uncaught NLR (You probably raised a MicroPython exception, dummy!) %p\n", val);
    exit(1);
}
