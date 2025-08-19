//
// Content for MICROPY_MODULE_FROZEN_STR
//
#include <stdint.h>
#define MP_FROZEN_STR_NAMES \

const uint32_t mp_frozen_str_sizes[] = { 0 };
const char mp_frozen_str_content[] = {
"\0"
};

//
// Content for MICROPY_MODULE_FROZEN_MPY
//
#include "py/mpconfig.h"
#include "py/objint.h"
#include "py/objstr.h"
#include "py/emitglue.h"
#include "py/nativeglue.h"

#if MICROPY_LONGINT_IMPL != 2
#error "incompatible MICROPY_LONGINT_IMPL"
#endif

#if MPZ_DIG_SIZE != 16
#error "incompatible MPZ_DIG_SIZE"
#endif

#if MICROPY_PY_BUILTINS_FLOAT
typedef struct _mp_obj_float_t {
    mp_obj_base_t base;
    mp_float_t value;
} mp_obj_float_t;
#endif

#if MICROPY_PY_BUILTINS_COMPLEX
typedef struct _mp_obj_complex_t {
    mp_obj_base_t base;
    mp_float_t real;
    mp_float_t imag;
} mp_obj_complex_t;
#endif

enum {
    MP_QSTR__0x0a_optional_space_args_colon_ = MP_QSTRnumber_of,
    MP_QSTR__0x0a_positional_space_args_colon_,
    MP_QSTR__space__space__percent__hyphen_16s_percent_s,
    MP_QSTR__space__percent_s,
    MP_QSTR__space__percent_s_percent_s,
    MP_QSTR__space__percent_s_paren_open_x_percent_d_paren_close_,
    MP_QSTR__space__bracket_open__percent_s_percent_s_bracket_close_,
    MP_QSTR__plus_,
    MP_QSTR__comma__space_,
    MP_QSTR__hyphen_,
    MP_QSTR__hyphen__hyphen_,
    MP_QSTR__hyphen__hyphen_help,
    MP_QSTR__hyphen__hyphen_index,
    MP_QSTR__hyphen__hyphen_mpy,
    MP_QSTR__hyphen__hyphen_no_hyphen_mpy,
    MP_QSTR__hyphen__hyphen_target,
    MP_QSTR__hyphen_h,
    MP_QSTR__hyphen_i,
    MP_QSTR__hyphen_t,
    MP_QSTR__dot_json,
    MP_QSTR__dot_mpy,
    MP_QSTR__dot_py,
    MP_QSTR__slash__hyphen__slash_raw_slash_,
    MP_QSTR__slash_lib,
    MP_QSTR__slash_rom,
    MP_QSTR_0_0x0d__0x0a__0x0d__0x0a_,
    MP_QSTR_0_dot_1_dot_0,
    MP_QSTR_0_dot_10_dot_2,
    MP_QSTR_0_dot_2_dot_1,
    MP_QSTR_0_dot_4_dot_0,
    MP_QSTR_0_dot_4_dot_1,
    MP_QSTR__colon_,
    MP_QSTR__question_,
    MP_QSTR__at_sign_,
    MP_QSTR_ArgumentParser,
    MP_QSTR_Authorization,
    MP_QSTR_Basic_space__brace_open__brace_close_,
    MP_QSTR_CERT_NONE,
    MP_QSTR_Connection,
    MP_QSTR_Content_hyphen_Length,
    MP_QSTR_Content_hyphen_Type,
    MP_QSTR_Copying_colon_,
    MP_QSTR_DELETE,
    MP_QSTR_Done,
    MP_QSTR_Downloading_space__brace_open__brace_close__space_to_space__brace_open__brace_close_,
    MP_QSTR_Error,
    MP_QSTR_Event,
    MP_QSTR_Exists_colon_,
    MP_QSTR_File_space_not_space_found_colon__space__brace_open__brace_close__space__brace_open__brace_close_,
    MP_QSTR_GET,
    MP_QSTR_HEAD,
    MP_QSTR_Host,
    MP_QSTR_IOQueue,
    MP_QSTR_Installing_space__brace_open__brace_close__space_to_space__brace_open__brace_close_,
    MP_QSTR_Lock,
    MP_QSTR_Lock_space_not_space_acquired,
    MP_QSTR_Loop,
    MP_QSTR_PATCH,
    MP_QSTR_POST,
    MP_QSTR_PROTOCOL_TLS_CLIENT,
    MP_QSTR_PROTOCOL_TLS_SERVER,
    MP_QSTR_PUT,
    MP_QSTR_Package_space_not_space_found_colon_,
    MP_QSTR_Response,
    MP_QSTR_SOCK_STREAM,
    MP_QSTR_SOL_SOCKET,
    MP_QSTR_SO_REUSEADDR,
    MP_QSTR_SSLContext,
    MP_QSTR_Server,
    MP_QSTR_SingletonGenerator,
    MP_QSTR_Stream,
    MP_QSTR_StreamReader,
    MP_QSTR_StreamWriter,
    MP_QSTR_ThreadSafeFlag,
    MP_QSTR_TimeoutError,
    MP_QSTR_Transfer_hyphen_Encoding,
    MP_QSTR_Unsupported_space_,
    MP_QSTR_Unsupported_space_protocol_colon__space_,
    MP_QSTR__Arg,
    MP_QSTR__ArgError,
    MP_QSTR__CHUNK_SIZE,
    MP_QSTR__Remove,
    MP_QSTR___version__,
    MP_QSTR__attrs,
    MP_QSTR__cached,
    MP_QSTR__check_exists,
    MP_QSTR__chunk,
    MP_QSTR__context,
    MP_QSTR__dequeue,
    MP_QSTR__dest_from_optnames,
    MP_QSTR__download_file,
    MP_QSTR__enqueue,
    MP_QSTR__ensure_path_exists,
    MP_QSTR__exc_context,
    MP_QSTR__exc_handler,
    MP_QSTR__install_json,
    MP_QSTR__install_package,
    MP_QSTR__io_queue,
    MP_QSTR__parse_args,
    MP_QSTR__parse_args_impl,
    MP_QSTR__promote_to_task,
    MP_QSTR__rewrite_url,
    MP_QSTR__run,
    MP_QSTR__serve,
    MP_QSTR__stop_task,
    MP_QSTR__stopper,
    MP_QSTR_accept,
    MP_QSTR_aclose,
    MP_QSTR_acquire,
    MP_QSTR_action,
    MP_QSTR_add_argument,
    MP_QSTR_allowed_mip_url_prefixes,
    MP_QSTR_application_slash_json,
    MP_QSTR_arg,
    MP_QSTR_argparse,
    MP_QSTR_argparse_dot_py,
    MP_QSTR_ascii,
    MP_QSTR_asyncio,
    MP_QSTR_asyncio_slash___init___dot_py,
    MP_QSTR_asyncio_slash_core_dot_py,
    MP_QSTR_asyncio_slash_event_dot_py,
    MP_QSTR_asyncio_slash_funcs_dot_py,
    MP_QSTR_asyncio_slash_lock_dot_py,
    MP_QSTR_asyncio_slash_stream_dot_py,
    MP_QSTR_attr,
    MP_QSTR_auth,
    MP_QSTR_aw,
    MP_QSTR_awrite,
    MP_QSTR_awritestr,
    MP_QSTR_backlog,
    MP_QSTR_bind,
    MP_QSTR_branch,
    MP_QSTR_buf,
    MP_QSTR_cadata,
    MP_QSTR_cafile,
    MP_QSTR_call_exception_handler,
    MP_QSTR_can_squot_t_space_gather,
    MP_QSTR_cb,
    MP_QSTR_cert,
    MP_QSTR_cert_reqs,
    MP_QSTR_certfile,
    MP_QSTR_chunked,
    MP_QSTR_connect,
    MP_QSTR_consume_unknown,
    MP_QSTR_content,
    MP_QSTR_context,
    MP_QSTR_core,
    MP_QSTR_coro_equals_,
    MP_QSTR_coroutine_space_expected,
    MP_QSTR_create_task,
    MP_QSTR_current_task,
    MP_QSTR_default_exception_handler,
    MP_QSTR_delete,
    MP_QSTR_deps,
    MP_QSTR_description,
    MP_QSTR_dest,
    MP_QSTR_do_handshake,
    MP_QSTR_do_handshake_on_connect,
    MP_QSTR_do_install,
    MP_QSTR_drain,
    MP_QSTR_dt,
    MP_QSTR_er,
    MP_QSTR_error_colon_,
    MP_QSTR_event,
    MP_QSTR_exc,
    MP_QSTR_exc_type,
    MP_QSTR_exception,
    MP_QSTR_expecting_space_value_space_for_space__percent_s,
    MP_QSTR_extra_space_args_colon__space__percent_s,
    MP_QSTR_f,
    MP_QSTR_flags,
    MP_QSTR_full,
    MP_QSTR_funcs,
    MP_QSTR_future,
    MP_QSTR_future_colon_,
    MP_QSTR_gather,
    MP_QSTR_get_event_loop,
    MP_QSTR_get_exception_handler,
    MP_QSTR_get_extra_info,
    MP_QSTR_getaddrinfo,
    MP_QSTR_github_colon_,
    MP_QSTR_gitlab_colon_,
    MP_QSTR_handler,
    MP_QSTR_hashes,
    MP_QSTR_head,
    MP_QSTR_headers,
    MP_QSTR_host,
    MP_QSTR_http_colon_,
    MP_QSTR_http_colon__slash__slash_,
    MP_QSTR_https_colon_,
    MP_QSTR_https_colon__slash__slash_,
    MP_QSTR_https_colon__slash__slash_gitlab_dot_com_slash_,
    MP_QSTR_idx,
    MP_QSTR_install,
    MP_QSTR_is_set,
    MP_QSTR_keyfile,
    MP_QSTR_latest,
    MP_QSTR_listen,
    MP_QSTR_load_cert_chain,
    MP_QSTR_load_verify_locations,
    MP_QSTR_lock,
    MP_QSTR_locked,
    MP_QSTR_main_task,
    MP_QSTR_message,
    MP_QSTR_method,
    MP_QSTR_mip_slash___init___dot_py,
    MP_QSTR_mip_slash___main___dot_py,
    MP_QSTR_mpy,
    MP_QSTR_names,
    MP_QSTR_nargs,
    MP_QSTR_new_event_loop,
    MP_QSTR_no_space_running_space_event_space_loop,
    MP_QSTR_no_mpy,
    MP_QSTR_open_connection,
    MP_QSTR_opt,
    MP_QSTR_opt_names,
    MP_QSTR_optname,
    MP_QSTR_out_buf,
    MP_QSTR_package,
    MP_QSTR_package_dot_json,
    MP_QSTR_package_json_url,
    MP_QSTR_parse,
    MP_QSTR_parse_args,
    MP_QSTR_parse_headers,
    MP_QSTR_parse_known_args,
    MP_QSTR_patch,
    MP_QSTR_peername,
    MP_QSTR_poller,
    MP_QSTR_port,
    MP_QSTR_pos,
    MP_QSTR_post,
    MP_QSTR_put,
    MP_QSTR_py,
    MP_QSTR_queue_read,
    MP_QSTR_queue_write,
    MP_QSTR_raw,
    MP_QSTR_readexactly,
    MP_QSTR_reason,
    MP_QSTR_release,
    MP_QSTR_render_arg,
    MP_QSTR_req,
    MP_QSTR_request,
    MP_QSTR_requesting,
    MP_QSTR_requests,
    MP_QSTR_requests_slash___init___dot_py,
    MP_QSTR_return_exceptions,
    MP_QSTR_return_unknown,
    MP_QSTR_run,
    MP_QSTR_run_forever,
    MP_QSTR_run_until_complete,
    MP_QSTR_runq_len,
    MP_QSTR_s,
    MP_QSTR_server_hostname,
    MP_QSTR_server_side,
    MP_QSTR_set_exception_handler,
    MP_QSTR_setsockopt,
    MP_QSTR_settimeout,
    MP_QSTR_sgen,
    MP_QSTR_short_hash,
    MP_QSTR_sock,
    MP_QSTR_socket,
    MP_QSTR_src,
    MP_QSTR_ssl,
    MP_QSTR_ssl_dot_py,
    MP_QSTR_start_server,
    MP_QSTR_status_code,
    MP_QSTR_stderr,
    MP_QSTR_store,
    MP_QSTR_store_const,
    MP_QSTR_store_false,
    MP_QSTR_store_true,
    MP_QSTR_stream,
    MP_QSTR_stream_awrite,
    MP_QSTR_sz,
    MP_QSTR_t,
    MP_QSTR_target,
    MP_QSTR_task,
    MP_QSTR_tb,
    MP_QSTR_ticks,
    MP_QSTR_timeout,
    MP_QSTR_tls,
    MP_QSTR_uasyncio_dot_py,
    MP_QSTR_unknown_space_option_space__percent_s,
    MP_QSTR_url,
    MP_QSTR_urls,
    MP_QSTR_usage,
    MP_QSTR_usage_colon__space__percent_s_space__bracket_open__hyphen_h_bracket_close_,
    MP_QSTR_v,
    MP_QSTR_val,
    MP_QSTR_verify_mode,
    MP_QSTR_wait,
    MP_QSTR_wait_closed,
    MP_QSTR_wait_for,
    MP_QSTR_wait_for_ms,
    MP_QSTR_wait_io_event,
    MP_QSTR_waiter,
    MP_QSTR_waiting,
    MP_QSTR_waitq_len,
    MP_QSTR_wb,
    MP_QSTR_wrap_socket,
    MP_QSTR__brace_open__brace_close__slash_file_slash__brace_open__brace_close__slash__brace_open__brace_close_,
    MP_QSTR__brace_open__brace_close__slash_package_slash__brace_open__brace_close__slash__brace_open__brace_close__slash__brace_open__brace_close__dot_json,
    MP_QSTR__brace_open__brace_close__slash__brace_open__brace_close_,
};

const qstr_hash_t mp_qstr_frozen_const_hashes[] = {
    59644,
    24230,
    7247,
    9843,
    37829,
    52587,
    22307,
    46478,
    26249,
    46472,
    26277,
    28212,
    44763,
    43809,
    1293,
    18580,
    26336,
    26337,
    26364,
    16755,
    7567,
    14722,
    47299,
    40077,
    63706,
    1365,
    26900,
    58982,
    23830,
    29969,
    29968,
    46495,
    46490,
    46565,
    57873,
    40382,
    57753,
    19856,
    42451,
    45021,
    47385,
    31962,
    11292,
    51237,
    17354,
    4573,
    35561,
    1983,
    11802,
    48915,
    32237,
    64005,
    26002,
    40031,
    59534,
    43943,
    59673,
    55275,
    6461,
    10465,
    49597,
    3220,
    20518,
    5830,
    48690,
    57103,
    21281,
    48598,
    2976,
    12601,
    55353,
    39580,
    35638,
    9558,
    19302,
    53440,
    18832,
    38204,
    47534,
    13910,
    14203,
    37244,
    38975,
    24346,
    6226,
    7715,
    49025,
    7717,
    49770,
    33781,
    53815,
    26816,
    9133,
    13092,
    52355,
    55644,
    7934,
    43474,
    31351,
    38896,
    24914,
    37796,
    58803,
    55469,
    5648,
    12837,
    35205,
    24658,
    54045,
    60251,
    1000,
    57627,
    48680,
    13457,
    62724,
    40355,
    22356,
    44357,
    63415,
    61558,
    25345,
    46624,
    16486,
    35185,
    48310,
    47277,
    28211,
    49657,
    2796,
    43370,
    25732,
    22033,
    18804,
    26615,
    19745,
    19688,
    4535,
    28388,
    45349,
    15087,
    53475,
    3583,
    15835,
    23646,
    55724,
    55546,
    56254,
    21001,
    50473,
    21139,
    8734,
    45889,
    59292,
    60551,
    58819,
    60707,
    32646,
    8697,
    65168,
    18805,
    28053,
    28082,
    18791,
    27081,
    9435,
    52220,
    60370,
    12636,
    5236,
    46531,
    36858,
    26838,
    27400,
    14592,
    22842,
    2184,
    19971,
    60604,
    16583,
    6254,
    22202,
    31274,
    24029,
    34369,
    24045,
    43945,
    13605,
    3847,
    59623,
    63796,
    4820,
    1,
    21584,
    56068,
    58562,
    62580,
    27646,
    3788,
    54926,
    48890,
    9134,
    47631,
    31740,
    48238,
    22682,
    29955,
    56498,
    17857,
    10641,
    27404,
    3209,
    49107,
    16799,
    25560,
    24270,
    44869,
    32297,
    30085,
    51135,
    23177,
    21804,
    51728,
    25224,
    44963,
    16484,
    40587,
    8320,
    42221,
    55388,
    29481,
    55357,
    28788,
    28684,
    52601,
    8726,
    35809,
    23753,
    59329,
    36844,
    34980,
    35683,
    45172,
    56532,
    48775,
    26741,
    47572,
    9272,
    35180,
    25036,
    37871,
    52773,
    46550,
    61272,
    61284,
    5288,
    59448,
    35548,
    32154,
    17434,
    40913,
    52320,
    36103,
    36329,
    48942,
    63679,
    62819,
    22691,
    2586,
    14272,
    59416,
    35379,
    54361,
    59482,
    28908,
    46545,
    14068,
    40488,
    28563,
    2115,
    21566,
    25422,
    55575,
    57528,
    25486,
    54589,
    2304,
    38767,
    46547,
    31486,
    19054,
    21902,
    29411,
    40746,
    25035,
    6948,
    60665,
    31214,
    21895,
    28784,
    62411,
    38218,
    18473,
    60938,
};

const qstr_len_t mp_qstr_frozen_const_lengths[] = {
    15,
    17,
    9,
    3,
    5,
    8,
    7,
    1,
    2,
    1,
    2,
    6,
    7,
    5,
    8,
    8,
    2,
    2,
    2,
    5,
    4,
    3,
    7,
    4,
    4,
    5,
    5,
    6,
    5,
    5,
    5,
    1,
    1,
    1,
    14,
    13,
    8,
    9,
    10,
    14,
    12,
    8,
    6,
    4,
    20,
    5,
    5,
    7,
    21,
    3,
    4,
    4,
    7,
    19,
    4,
    17,
    4,
    5,
    4,
    19,
    19,
    3,
    18,
    8,
    11,
    10,
    12,
    10,
    6,
    18,
    6,
    12,
    12,
    14,
    12,
    17,
    12,
    22,
    4,
    9,
    11,
    7,
    11,
    6,
    7,
    13,
    6,
    8,
    8,
    19,
    14,
    8,
    19,
    12,
    12,
    13,
    16,
    9,
    11,
    16,
    16,
    12,
    4,
    6,
    10,
    8,
    6,
    6,
    7,
    6,
    12,
    24,
    16,
    3,
    8,
    11,
    5,
    7,
    19,
    15,
    16,
    16,
    15,
    17,
    4,
    4,
    2,
    6,
    9,
    7,
    4,
    6,
    3,
    6,
    6,
    22,
    12,
    2,
    4,
    9,
    8,
    7,
    7,
    15,
    7,
    7,
    4,
    5,
    18,
    11,
    12,
    25,
    6,
    4,
    11,
    4,
    12,
    23,
    10,
    5,
    2,
    2,
    6,
    5,
    3,
    8,
    9,
    22,
    14,
    1,
    5,
    4,
    5,
    6,
    7,
    6,
    14,
    21,
    14,
    11,
    7,
    7,
    7,
    6,
    4,
    7,
    4,
    5,
    7,
    6,
    8,
    19,
    3,
    7,
    6,
    7,
    6,
    6,
    15,
    21,
    4,
    6,
    9,
    7,
    6,
    15,
    15,
    3,
    5,
    5,
    14,
    21,
    6,
    15,
    3,
    9,
    7,
    7,
    7,
    12,
    16,
    5,
    10,
    13,
    16,
    5,
    8,
    6,
    4,
    3,
    4,
    3,
    2,
    10,
    11,
    3,
    11,
    6,
    7,
    10,
    3,
    7,
    10,
    8,
    20,
    17,
    14,
    3,
    11,
    18,
    8,
    1,
    15,
    11,
    21,
    10,
    10,
    4,
    10,
    4,
    6,
    3,
    3,
    6,
    12,
    11,
    6,
    5,
    11,
    11,
    10,
    6,
    13,
    2,
    1,
    6,
    4,
    2,
    5,
    7,
    3,
    11,
    17,
    3,
    4,
    5,
    14,
    1,
    3,
    11,
    4,
    11,
    8,
    11,
    13,
    6,
    7,
    9,
    2,
    11,
    13,
    24,
    5,
};

extern const qstr_pool_t mp_qstr_const_pool;
const qstr_pool_t mp_qstr_frozen_const_pool = {
    &mp_qstr_const_pool, // previous pool
    MP_QSTRnumber_of, // previous pool size
    true, // is_sorted
    10, // allocated entries
    303, // used entries
    (qstr_hash_t *)mp_qstr_frozen_const_hashes,
    (qstr_len_t *)mp_qstr_frozen_const_lengths,
    {
        "\x0a\x6f\x70\x74\x69\x6f\x6e\x61\x6c\x20\x61\x72\x67\x73\x3a",
        "\x0a\x70\x6f\x73\x69\x74\x69\x6f\x6e\x61\x6c\x20\x61\x72\x67\x73\x3a",
        "  %-16s%s",
        " %s",
        " %s%s",
        " %s(x%d)",
        " [%s%s]",
        "+",
        ", ",
        "-",
        "--",
        "--help",
        "--index",
        "--mpy",
        "--no-mpy",
        "--target",
        "-h",
        "-i",
        "-t",
        ".json",
        ".mpy",
        ".py",
        "/-/raw/",
        "/lib",
        "/rom",
        "\x30\x0d\x0a\x0d\x0a",
        "0.1.0",
        "0.10.2",
        "0.2.1",
        "0.4.0",
        "0.4.1",
        ":",
        "?",
        "@",
        "ArgumentParser",
        "Authorization",
        "Basic {}",
        "CERT_NONE",
        "Connection",
        "Content-Length",
        "Content-Type",
        "Copying:",
        "DELETE",
        "Done",
        "Downloading {} to {}",
        "Error",
        "Event",
        "Exists:",
        "File not found: {} {}",
        "GET",
        "HEAD",
        "Host",
        "IOQueue",
        "Installing {} to {}",
        "Lock",
        "Lock not acquired",
        "Loop",
        "PATCH",
        "POST",
        "PROTOCOL_TLS_CLIENT",
        "PROTOCOL_TLS_SERVER",
        "PUT",
        "Package not found:",
        "Response",
        "SOCK_STREAM",
        "SOL_SOCKET",
        "SO_REUSEADDR",
        "SSLContext",
        "Server",
        "SingletonGenerator",
        "Stream",
        "StreamReader",
        "StreamWriter",
        "ThreadSafeFlag",
        "TimeoutError",
        "Transfer-Encoding",
        "Unsupported ",
        "Unsupported protocol: ",
        "_Arg",
        "_ArgError",
        "_CHUNK_SIZE",
        "_Remove",
        "__version__",
        "_attrs",
        "_cached",
        "_check_exists",
        "_chunk",
        "_context",
        "_dequeue",
        "_dest_from_optnames",
        "_download_file",
        "_enqueue",
        "_ensure_path_exists",
        "_exc_context",
        "_exc_handler",
        "_install_json",
        "_install_package",
        "_io_queue",
        "_parse_args",
        "_parse_args_impl",
        "_promote_to_task",
        "_rewrite_url",
        "_run",
        "_serve",
        "_stop_task",
        "_stopper",
        "accept",
        "aclose",
        "acquire",
        "action",
        "add_argument",
        "allowed_mip_url_prefixes",
        "application/json",
        "arg",
        "argparse",
        "argparse.py",
        "ascii",
        "asyncio",
        "asyncio/__init__.py",
        "asyncio/core.py",
        "asyncio/event.py",
        "asyncio/funcs.py",
        "asyncio/lock.py",
        "asyncio/stream.py",
        "attr",
        "auth",
        "aw",
        "awrite",
        "awritestr",
        "backlog",
        "bind",
        "branch",
        "buf",
        "cadata",
        "cafile",
        "call_exception_handler",
        "can't gather",
        "cb",
        "cert",
        "cert_reqs",
        "certfile",
        "chunked",
        "connect",
        "consume_unknown",
        "content",
        "context",
        "core",
        "coro=",
        "coroutine expected",
        "create_task",
        "current_task",
        "default_exception_handler",
        "delete",
        "deps",
        "description",
        "dest",
        "do_handshake",
        "do_handshake_on_connect",
        "do_install",
        "drain",
        "dt",
        "er",
        "error:",
        "event",
        "exc",
        "exc_type",
        "exception",
        "expecting value for %s",
        "extra args: %s",
        "f",
        "flags",
        "full",
        "funcs",
        "future",
        "future:",
        "gather",
        "get_event_loop",
        "get_exception_handler",
        "get_extra_info",
        "getaddrinfo",
        "github:",
        "gitlab:",
        "handler",
        "hashes",
        "head",
        "headers",
        "host",
        "http:",
        "http://",
        "https:",
        "https://",
        "https://gitlab.com/",
        "idx",
        "install",
        "is_set",
        "keyfile",
        "latest",
        "listen",
        "load_cert_chain",
        "load_verify_locations",
        "lock",
        "locked",
        "main_task",
        "message",
        "method",
        "mip/__init__.py",
        "mip/__main__.py",
        "mpy",
        "names",
        "nargs",
        "new_event_loop",
        "no running event loop",
        "no_mpy",
        "open_connection",
        "opt",
        "opt_names",
        "optname",
        "out_buf",
        "package",
        "package.json",
        "package_json_url",
        "parse",
        "parse_args",
        "parse_headers",
        "parse_known_args",
        "patch",
        "peername",
        "poller",
        "port",
        "pos",
        "post",
        "put",
        "py",
        "queue_read",
        "queue_write",
        "raw",
        "readexactly",
        "reason",
        "release",
        "render_arg",
        "req",
        "request",
        "requesting",
        "requests",
        "requests/__init__.py",
        "return_exceptions",
        "return_unknown",
        "run",
        "run_forever",
        "run_until_complete",
        "runq_len",
        "s",
        "server_hostname",
        "server_side",
        "set_exception_handler",
        "setsockopt",
        "settimeout",
        "sgen",
        "short_hash",
        "sock",
        "socket",
        "src",
        "ssl",
        "ssl.py",
        "start_server",
        "status_code",
        "stderr",
        "store",
        "store_const",
        "store_false",
        "store_true",
        "stream",
        "stream_awrite",
        "sz",
        "t",
        "target",
        "task",
        "tb",
        "ticks",
        "timeout",
        "tls",
        "uasyncio.py",
        "unknown option %s",
        "url",
        "urls",
        "usage",
        "usage: %s [-h]",
        "v",
        "val",
        "verify_mode",
        "wait",
        "wait_closed",
        "wait_for",
        "wait_for_ms",
        "wait_io_event",
        "waiter",
        "waiting",
        "waitq_len",
        "wb",
        "wrap_socket",
        "{}/file/{}/{}",
        "{}/package/{}/{}/{}.json",
        "{}/{}",
    },
};

////////////////////////////////////////////////////////////////////////////////
// frozen module argparse
// - original source file: /Users/gadgetoid/Development/micropython-web/picovector/ports/sokol/build/frozen_mpy/argparse.mpy
// - frozen file name: argparse.py
// - .mpy header: 4d:06:00:1f

// frozen bytecode for file argparse.py, scope argparse__lt_module_gt_
static const byte fun_data_argparse__lt_module_gt_[72] = {
    0x18,0x1a, // prelude
    0x01, // names: <module>
    0x60,0x20,0x26,0x6c,0x6b,0x20,0x89,0x35,0x84,0x09,0x89,0x9a, // code info
    0x80, // LOAD_CONST_SMALL_INT 0
    0x51, // LOAD_CONST_NONE
    0x1b,0x02, // IMPORT_NAME 'sys'
    0x16,0x02, // STORE_NAME 'sys'
    0x80, // LOAD_CONST_SMALL_INT 0
    0x10,0x03, // LOAD_CONST_STRING 'namedtuple'
    0x2a,0x01, // BUILD_TUPLE 1
    0x1b,0x04, // IMPORT_NAME 'collections'
    0x1c,0x03, // IMPORT_FROM 'namedtuple'
    0x16,0x03, // STORE_NAME 'namedtuple'
    0x59, // POP_TOP
    0x54, // LOAD_BUILD_CLASS
    0x32,0x00, // MAKE_FUNCTION 0
    0x10,0x05, // LOAD_CONST_STRING '_ArgError'
    0x11,0x3b, // LOAD_NAME 'BaseException'
    0x34,0x03, // CALL_FUNCTION 3
    0x16,0x05, // STORE_NAME '_ArgError'
    0x54, // LOAD_BUILD_CLASS
    0x32,0x01, // MAKE_FUNCTION 1
    0x10,0x06, // LOAD_CONST_STRING '_Arg'
    0x34,0x02, // CALL_FUNCTION 2
    0x16,0x06, // STORE_NAME '_Arg'
    0x32,0x02, // MAKE_FUNCTION 2
    0x16,0x09, // STORE_NAME '_dest_from_optnames'
    0x54, // LOAD_BUILD_CLASS
    0x32,0x03, // MAKE_FUNCTION 3
    0x10,0x07, // LOAD_CONST_STRING 'ArgumentParser'
    0x34,0x02, // CALL_FUNCTION 2
    0x16,0x07, // STORE_NAME 'ArgumentParser'
    0x10,0x08, // LOAD_CONST_STRING '0.4.0'
    0x16,0x3c, // STORE_NAME '__version__'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
// child of argparse__lt_module_gt_
// frozen bytecode for file argparse.py, scope argparse__ArgError
static const byte fun_data_argparse__ArgError[15] = {
    0x00,0x06, // prelude
    0x05, // names: _ArgError
    0x88,0x09, // code info
    0x11,0x3d, // LOAD_NAME '__name__'
    0x16,0x3e, // STORE_NAME '__module__'
    0x10,0x05, // LOAD_CONST_STRING '_ArgError'
    0x16,0x3f, // STORE_NAME '__qualname__'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_argparse__ArgError = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_argparse__ArgError,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 15,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 1,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 5,
        .line_info = fun_data_argparse__ArgError + 3,
        .line_info_top = fun_data_argparse__ArgError + 5,
        .opcodes = fun_data_argparse__ArgError + 5,
    },
    #endif
    #endif
};
#else
#define proto_fun_argparse__ArgError fun_data_argparse__ArgError[0]
#endif

// child of argparse__lt_module_gt_
// frozen bytecode for file argparse.py, scope argparse__Arg
static const byte fun_data_argparse__Arg[25] = {
    0x00,0x0a, // prelude
    0x06, // names: _Arg
    0x88,0x0d,0x84,0x09, // code info
    0x11,0x3d, // LOAD_NAME '__name__'
    0x16,0x3e, // STORE_NAME '__module__'
    0x10,0x06, // LOAD_CONST_STRING '_Arg'
    0x16,0x3f, // STORE_NAME '__qualname__'
    0x32,0x00, // MAKE_FUNCTION 0
    0x16,0x12, // STORE_NAME '__init__'
    0x32,0x01, // MAKE_FUNCTION 1
    0x16,0x1a, // STORE_NAME 'parse'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
// child of argparse__Arg
// frozen bytecode for file argparse.py, scope argparse__Arg___init__
static const byte fun_data_argparse__Arg___init__[51] = {
    0xc8,0x80,0x04,0x22, // prelude
    0x12,0x41,0x13,0x14,0x15,0x16,0x17,0x18,0x19, // names: __init__, self, names, dest, action, nargs, const, default, help
    0x80,0x0e,0x24,0x24,0x24,0x24,0x24,0x24, // code info
    0xb1, // LOAD_FAST 1
    0xb0, // LOAD_FAST 0
    0x18,0x13, // STORE_ATTR 'names'
    0xb2, // LOAD_FAST 2
    0xb0, // LOAD_FAST 0
    0x18,0x14, // STORE_ATTR 'dest'
    0xb3, // LOAD_FAST 3
    0xb0, // LOAD_FAST 0
    0x18,0x15, // STORE_ATTR 'action'
    0xb4, // LOAD_FAST 4
    0xb0, // LOAD_FAST 0
    0x18,0x16, // STORE_ATTR 'nargs'
    0xb5, // LOAD_FAST 5
    0xb0, // LOAD_FAST 0
    0x18,0x17, // STORE_ATTR 'const'
    0xb6, // LOAD_FAST 6
    0xb0, // LOAD_FAST 0
    0x18,0x18, // STORE_ATTR 'default'
    0xb7, // LOAD_FAST 7
    0xb0, // LOAD_FAST 0
    0x18,0x19, // STORE_ATTR 'help'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_argparse__Arg___init__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_argparse__Arg___init__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 51,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 10,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 8,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 18,
        .line_info = fun_data_argparse__Arg___init__ + 13,
        .line_info_top = fun_data_argparse__Arg___init__ + 21,
        .opcodes = fun_data_argparse__Arg___init__ + 21,
    },
    #endif
    #endif
};
#else
#define proto_fun_argparse__Arg___init__ fun_data_argparse__Arg___init__[0]
#endif

// child of argparse__Arg
// frozen bytecode for file argparse.py, scope argparse__Arg_parse
static const byte fun_data_argparse__Arg_parse[258] = {
    0x53,0x4a, // prelude
    0x1a,0x41,0x42,0x35, // names: parse, self, optname, args
    0x80,0x18,0x29,0x27,0x23,0x47,0x2c,0x28,0x23,0x47,0x47,0x28,0x24,0x28,0x23,0x29,0x44,0x28,0x23,0x22,0x22,0x36,0x28,0x22,0x49,0x44,0x2c,0x2d,0x25,0x29,0x24,0x28,0x44, // code info
    0xb0, // LOAD_FAST 0
    0x13,0x15, // LOAD_ATTR 'action'
    0x10,0x1b, // LOAD_CONST_STRING 'store'
    0xd9, // BINARY_OP 2 __eq__
    0x44,0xc1,0x81, // POP_JUMP_IF_FALSE 193
    0xb0, // LOAD_FAST 0
    0x13,0x16, // LOAD_ATTR 'nargs'
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0x44,0x56, // POP_JUMP_IF_FALSE 22
    0xb2, // LOAD_FAST 2
    0x44,0x47, // POP_JUMP_IF_FALSE 7
    0xb2, // LOAD_FAST 2
    0x14,0x1c, // LOAD_METHOD 'pop'
    0x80, // LOAD_CONST_SMALL_INT 0
    0x36,0x01, // CALL_METHOD 1
    0x63, // RETURN_VALUE
    0x12,0x05, // LOAD_GLOBAL '_ArgError'
    0x23,0x00, // LOAD_CONST_OBJ 0
    0xb1, // LOAD_FAST 1
    0xf8, // BINARY_OP 33 __mod__
    0x34,0x01, // CALL_FUNCTION 1
    0x65, // RAISE_OBJ
    0x42,0xa2,0x81, // JUMP 162
    0xb0, // LOAD_FAST 0
    0x13,0x16, // LOAD_ATTR 'nargs'
    0x10,0x1d, // LOAD_CONST_STRING '?'
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x51, // POP_JUMP_IF_FALSE 17
    0xb2, // LOAD_FAST 2
    0x44,0x47, // POP_JUMP_IF_FALSE 7
    0xb2, // LOAD_FAST 2
    0x14,0x1c, // LOAD_METHOD 'pop'
    0x80, // LOAD_CONST_SMALL_INT 0
    0x36,0x01, // CALL_METHOD 1
    0x63, // RETURN_VALUE
    0xb0, // LOAD_FAST 0
    0x13,0x18, // LOAD_ATTR 'default'
    0x63, // RETURN_VALUE
    0x42,0x89,0x81, // JUMP 137
    0xb0, // LOAD_FAST 0
    0x13,0x16, // LOAD_ATTR 'nargs'
    0x10,0x1e, // LOAD_CONST_STRING '*'
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x44, // POP_JUMP_IF_FALSE 4
    0x7f, // LOAD_CONST_SMALL_INT -1
    0xc3, // STORE_FAST 3
    0x42,0x60, // JUMP 32
    0xb0, // LOAD_FAST 0
    0x13,0x16, // LOAD_ATTR 'nargs'
    0x10,0x1f, // LOAD_CONST_STRING '+'
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x50, // POP_JUMP_IF_FALSE 16
    0xb2, // LOAD_FAST 2
    0x43,0x49, // POP_JUMP_IF_TRUE 9
    0x12,0x05, // LOAD_GLOBAL '_ArgError'
    0x23,0x00, // LOAD_CONST_OBJ 0
    0xb1, // LOAD_FAST 1
    0xf8, // BINARY_OP 33 __mod__
    0x34,0x01, // CALL_FUNCTION 1
    0x65, // RAISE_OBJ
    0x7f, // LOAD_CONST_SMALL_INT -1
    0xc3, // STORE_FAST 3
    0x42,0x48, // JUMP 8
    0x12,0x43, // LOAD_GLOBAL 'int'
    0xb0, // LOAD_FAST 0
    0x13,0x16, // LOAD_ATTR 'nargs'
    0x34,0x01, // CALL_FUNCTION 1
    0xc3, // STORE_FAST 3
    0x2b,0x00, // BUILD_LIST 0
    0xc4, // STORE_FAST 4
    0x52, // LOAD_CONST_TRUE
    0xc5, // STORE_FAST 5
    0x42,0x7d, // JUMP 61
    0xb5, // LOAD_FAST 5
    0x44,0x6a, // POP_JUMP_IF_FALSE 42
    0xb2, // LOAD_FAST 2
    0x80, // LOAD_CONST_SMALL_INT 0
    0x55, // LOAD_SUBSCR
    0x14,0x0a, // LOAD_METHOD 'startswith'
    0x10,0x0d, // LOAD_CONST_STRING '-'
    0x36,0x01, // CALL_METHOD 1
    0x44,0x5f, // POP_JUMP_IF_FALSE 31
    0xb2, // LOAD_FAST 2
    0x80, // LOAD_CONST_SMALL_INT 0
    0x55, // LOAD_SUBSCR
    0x10,0x0d, // LOAD_CONST_STRING '-'
    0xdc, // BINARY_OP 5 __ne__
    0x44,0x57, // POP_JUMP_IF_FALSE 23
    0xb2, // LOAD_FAST 2
    0x80, // LOAD_CONST_SMALL_INT 0
    0x55, // LOAD_SUBSCR
    0x10,0x0b, // LOAD_CONST_STRING '--'
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x4b, // POP_JUMP_IF_FALSE 11
    0x50, // LOAD_CONST_FALSE
    0xc5, // STORE_FAST 5
    0xb2, // LOAD_FAST 2
    0x14,0x1c, // LOAD_METHOD 'pop'
    0x80, // LOAD_CONST_SMALL_INT 0
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x42,0x42, // JUMP 2
    0x42,0x5b, // JUMP 27
    0x42,0x50, // JUMP 16
    0xb4, // LOAD_FAST 4
    0x14,0x20, // LOAD_METHOD 'append'
    0xb2, // LOAD_FAST 2
    0x14,0x1c, // LOAD_METHOD 'pop'
    0x80, // LOAD_CONST_SMALL_INT 0
    0x36,0x01, // CALL_METHOD 1
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0xb3, // LOAD_FAST 3
    0x81, // LOAD_CONST_SMALL_INT 1
    0xe6, // BINARY_OP 15 __isub__
    0xc3, // STORE_FAST 3
    0xb2, // LOAD_FAST 2
    0x44,0x46, // POP_JUMP_IF_FALSE 6
    0xb3, // LOAD_FAST 3
    0x80, // LOAD_CONST_SMALL_INT 0
    0xdc, // BINARY_OP 5 __ne__
    0x43,0xba,0x7f, // POP_JUMP_IF_TRUE -70
    0xb3, // LOAD_FAST 3
    0x80, // LOAD_CONST_SMALL_INT 0
    0xd8, // BINARY_OP 1 __gt__
    0x44,0x49, // POP_JUMP_IF_FALSE 9
    0x12,0x05, // LOAD_GLOBAL '_ArgError'
    0x23,0x00, // LOAD_CONST_OBJ 0
    0xb1, // LOAD_FAST 1
    0xf8, // BINARY_OP 33 __mod__
    0x34,0x01, // CALL_FUNCTION 1
    0x65, // RAISE_OBJ
    0xb4, // LOAD_FAST 4
    0x63, // RETURN_VALUE
    0x42,0x4f, // JUMP 15
    0xb0, // LOAD_FAST 0
    0x13,0x15, // LOAD_ATTR 'action'
    0x23,0x01, // LOAD_CONST_OBJ 1
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x44, // POP_JUMP_IF_FALSE 4
    0xb0, // LOAD_FAST 0
    0x13,0x17, // LOAD_ATTR 'const'
    0x63, // RETURN_VALUE
    0x12,0x21, // LOAD_GLOBAL 'AssertionError'
    0x65, // RAISE_OBJ
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_argparse__Arg_parse = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_argparse__Arg_parse,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 258,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 11,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 3,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 26,
        .line_info = fun_data_argparse__Arg_parse + 6,
        .line_info_top = fun_data_argparse__Arg_parse + 39,
        .opcodes = fun_data_argparse__Arg_parse + 39,
    },
    #endif
    #endif
};
#else
#define proto_fun_argparse__Arg_parse fun_data_argparse__Arg_parse[0]
#endif

static const mp_raw_code_t *const children_argparse__Arg[] = {
    (const mp_raw_code_t *)&proto_fun_argparse__Arg___init__,
    (const mp_raw_code_t *)&proto_fun_argparse__Arg_parse,
};

static const mp_raw_code_truncated_t proto_fun_argparse__Arg = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_argparse__Arg,
    .children = (void *)&children_argparse__Arg,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 25,
    .n_children = 2,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 1,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 6,
        .line_info = fun_data_argparse__Arg + 3,
        .line_info_top = fun_data_argparse__Arg + 7,
        .opcodes = fun_data_argparse__Arg + 7,
    },
    #endif
    #endif
};

// child of argparse__lt_module_gt_
// frozen bytecode for file argparse.py, scope argparse__dest_from_optnames
static const byte fun_data_argparse__dest_from_optnames[55] = {
    0x49,0x12, // prelude
    0x09,0x40, // names: _dest_from_optnames, opt_names
    0x80,0x42,0x24,0x25,0x29,0x22,0x28, // code info
    0xb0, // LOAD_FAST 0
    0x80, // LOAD_CONST_SMALL_INT 0
    0x55, // LOAD_SUBSCR
    0xc1, // STORE_FAST 1
    0xb0, // LOAD_FAST 0
    0x5f, // GET_ITER_STACK
    0x4b,0x14, // FOR_ITER 20
    0xc2, // STORE_FAST 2
    0xb2, // LOAD_FAST 2
    0x14,0x0a, // LOAD_METHOD 'startswith'
    0x10,0x0b, // LOAD_CONST_STRING '--'
    0x36,0x01, // CALL_METHOD 1
    0x44,0x48, // POP_JUMP_IF_FALSE 8
    0xb2, // LOAD_FAST 2
    0xc1, // STORE_FAST 1
    0x59, // POP_TOP
    0x59, // POP_TOP
    0x59, // POP_TOP
    0x59, // POP_TOP
    0x42,0x42, // JUMP 2
    0x42,0x2a, // JUMP -22
    0xb1, // LOAD_FAST 1
    0x14,0x0c, // LOAD_METHOD 'lstrip'
    0x10,0x0d, // LOAD_CONST_STRING '-'
    0x36,0x01, // CALL_METHOD 1
    0x14,0x0e, // LOAD_METHOD 'replace'
    0x10,0x0d, // LOAD_CONST_STRING '-'
    0x10,0x0f, // LOAD_CONST_STRING '_'
    0x36,0x02, // CALL_METHOD 2
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_argparse__dest_from_optnames = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_argparse__dest_from_optnames,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 55,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 10,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 9,
        .line_info = fun_data_argparse__dest_from_optnames + 4,
        .line_info_top = fun_data_argparse__dest_from_optnames + 11,
        .opcodes = fun_data_argparse__dest_from_optnames + 11,
    },
    #endif
    #endif
};
#else
#define proto_fun_argparse__dest_from_optnames fun_data_argparse__dest_from_optnames[0]
#endif

// child of argparse__lt_module_gt_
// frozen bytecode for file argparse.py, scope argparse_ArgumentParser
static const byte fun_data_argparse_ArgumentParser[69] = {
    0x18,0x1a, // prelude
    0x07, // names: ArgumentParser
    0x88,0x4b,0x6c,0x40,0x84,0x25,0x84,0x25,0x68,0x68,0x84,0x0c, // code info
    0x11,0x3d, // LOAD_NAME '__name__'
    0x16,0x3e, // STORE_NAME '__module__'
    0x10,0x07, // LOAD_CONST_STRING 'ArgumentParser'
    0x16,0x3f, // STORE_NAME '__qualname__'
    0x53, // LOAD_NULL
    0x2c,0x00, // BUILD_MAP 0
    0x10,0x10, // LOAD_CONST_STRING ''
    0x10,0x11, // LOAD_CONST_STRING 'description'
    0x62, // STORE_MAP
    0x33,0x00, // MAKE_FUNCTION_DEFARGS 0
    0x16,0x12, // STORE_NAME '__init__'
    0x32,0x01, // MAKE_FUNCTION 1
    0x16,0x24, // STORE_NAME 'add_argument'
    0x32,0x02, // MAKE_FUNCTION 2
    0x16,0x27, // STORE_NAME 'usage'
    0x51, // LOAD_CONST_NONE
    0x2a,0x01, // BUILD_TUPLE 1
    0x53, // LOAD_NULL
    0x33,0x03, // MAKE_FUNCTION_DEFARGS 3
    0x16,0x2e, // STORE_NAME 'parse_args'
    0x51, // LOAD_CONST_NONE
    0x2a,0x01, // BUILD_TUPLE 1
    0x53, // LOAD_NULL
    0x33,0x04, // MAKE_FUNCTION_DEFARGS 4
    0x16,0x30, // STORE_NAME 'parse_known_args'
    0x32,0x05, // MAKE_FUNCTION 5
    0x16,0x2f, // STORE_NAME '_parse_args_impl'
    0x32,0x06, // MAKE_FUNCTION 6
    0x16,0x31, // STORE_NAME '_parse_args'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
// child of argparse_ArgumentParser
// frozen bytecode for file argparse.py, scope argparse_ArgumentParser___init__
static const byte fun_data_argparse_ArgumentParser___init__[29] = {
    0x99,0x88,0x80,0x80,0x40,0x0e, // prelude
    0x12,0x41,0x11, // names: __init__, self, description
    0x80,0x4c,0x24,0x25, // code info
    0xb1, // LOAD_FAST 1
    0xb0, // LOAD_FAST 0
    0x18,0x11, // STORE_ATTR 'description'
    0x2b,0x00, // BUILD_LIST 0
    0xb0, // LOAD_FAST 0
    0x18,0x22, // STORE_ATTR 'opt'
    0x2b,0x00, // BUILD_LIST 0
    0xb0, // LOAD_FAST 0
    0x18,0x23, // STORE_ATTR 'pos'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_argparse_ArgumentParser___init__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_argparse_ArgumentParser___init__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 29,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 8,
        .n_pos_args = 1,
        .n_kwonly_args = 1,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 18,
        .line_info = fun_data_argparse_ArgumentParser___init__ + 9,
        .line_info_top = fun_data_argparse_ArgumentParser___init__ + 13,
        .opcodes = fun_data_argparse_ArgumentParser___init__ + 13,
    },
    #endif
    #endif
};
#else
#define proto_fun_argparse_ArgumentParser___init__ fun_data_argparse_ArgumentParser___init__[0]
#endif

// child of argparse_ArgumentParser
// frozen bytecode for file argparse.py, scope argparse_ArgumentParser_add_argument
static const byte fun_data_argparse_ArgumentParser_add_argument[208] = {
    0xa1,0x90,0xc0,0x40,0x3c, // prelude
    0x24,0x41, // names: add_argument, self
    0x80,0x51,0x2a,0x26,0x23,0x22,0x2b,0x26,0x23,0x22,0x4b,0x29,0x29,0x2e,0x24,0x28,0x25,0x48,0x24,0x28,0x25,0x24,0x23,0x24,0x23,0x65,0x20,0x6a, // code info
    0xb2, // LOAD_FAST 2
    0x14,0x25, // LOAD_METHOD 'get'
    0x10,0x15, // LOAD_CONST_STRING 'action'
    0x10,0x1b, // LOAD_CONST_STRING 'store'
    0x36,0x02, // CALL_METHOD 2
    0xc3, // STORE_FAST 3
    0xb3, // LOAD_FAST 3
    0x10,0x26, // LOAD_CONST_STRING 'store_true'
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x50, // POP_JUMP_IF_FALSE 16
    0x23,0x01, // LOAD_CONST_OBJ 1
    0xc3, // STORE_FAST 3
    0x52, // LOAD_CONST_TRUE
    0xc4, // STORE_FAST 4
    0xb2, // LOAD_FAST 2
    0x14,0x25, // LOAD_METHOD 'get'
    0x10,0x18, // LOAD_CONST_STRING 'default'
    0x50, // LOAD_CONST_FALSE
    0x36,0x02, // CALL_METHOD 2
    0xc5, // STORE_FAST 5
    0x42,0x68, // JUMP 40
    0xb3, // LOAD_FAST 3
    0x23,0x02, // LOAD_CONST_OBJ 2
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x50, // POP_JUMP_IF_FALSE 16
    0x23,0x01, // LOAD_CONST_OBJ 1
    0xc3, // STORE_FAST 3
    0x50, // LOAD_CONST_FALSE
    0xc4, // STORE_FAST 4
    0xb2, // LOAD_FAST 2
    0x14,0x25, // LOAD_METHOD 'get'
    0x10,0x18, // LOAD_CONST_STRING 'default'
    0x52, // LOAD_CONST_TRUE
    0x36,0x02, // CALL_METHOD 2
    0xc5, // STORE_FAST 5
    0x42,0x52, // JUMP 18
    0xb2, // LOAD_FAST 2
    0x14,0x25, // LOAD_METHOD 'get'
    0x10,0x17, // LOAD_CONST_STRING 'const'
    0x51, // LOAD_CONST_NONE
    0x36,0x02, // CALL_METHOD 2
    0xc4, // STORE_FAST 4
    0xb2, // LOAD_FAST 2
    0x14,0x25, // LOAD_METHOD 'get'
    0x10,0x18, // LOAD_CONST_STRING 'default'
    0x51, // LOAD_CONST_NONE
    0x36,0x02, // CALL_METHOD 2
    0xc5, // STORE_FAST 5
    0xb1, // LOAD_FAST 1
    0x44,0x64, // POP_JUMP_IF_FALSE 36
    0xb1, // LOAD_FAST 1
    0x80, // LOAD_CONST_SMALL_INT 0
    0x55, // LOAD_SUBSCR
    0x14,0x0a, // LOAD_METHOD 'startswith'
    0x10,0x0d, // LOAD_CONST_STRING '-'
    0x36,0x01, // CALL_METHOD 1
    0x44,0x59, // POP_JUMP_IF_FALSE 25
    0xb0, // LOAD_FAST 0
    0x13,0x22, // LOAD_ATTR 'opt'
    0xc6, // STORE_FAST 6
    0xb2, // LOAD_FAST 2
    0x14,0x25, // LOAD_METHOD 'get'
    0x10,0x14, // LOAD_CONST_STRING 'dest'
    0x36,0x01, // CALL_METHOD 1
    0xc7, // STORE_FAST 7
    0xb7, // LOAD_FAST 7
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0x44,0x46, // POP_JUMP_IF_FALSE 6
    0x12,0x09, // LOAD_GLOBAL '_dest_from_optnames'
    0xb1, // LOAD_FAST 1
    0x34,0x01, // CALL_FUNCTION 1
    0xc7, // STORE_FAST 7
    0x42,0x5c, // JUMP 28
    0xb0, // LOAD_FAST 0
    0x13,0x23, // LOAD_ATTR 'pos'
    0xc6, // STORE_FAST 6
    0xb2, // LOAD_FAST 2
    0x14,0x25, // LOAD_METHOD 'get'
    0x10,0x14, // LOAD_CONST_STRING 'dest'
    0x36,0x01, // CALL_METHOD 1
    0xc7, // STORE_FAST 7
    0xb7, // LOAD_FAST 7
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0x44,0x44, // POP_JUMP_IF_FALSE 4
    0xb1, // LOAD_FAST 1
    0x80, // LOAD_CONST_SMALL_INT 0
    0x55, // LOAD_SUBSCR
    0xc7, // STORE_FAST 7
    0xb1, // LOAD_FAST 1
    0x43,0x44, // POP_JUMP_IF_TRUE 4
    0xb7, // LOAD_FAST 7
    0x2b,0x01, // BUILD_LIST 1
    0xc1, // STORE_FAST 1
    0xb6, // LOAD_FAST 6
    0x14,0x20, // LOAD_METHOD 'append'
    0x12,0x06, // LOAD_GLOBAL '_Arg'
    0xb1, // LOAD_FAST 1
    0xb7, // LOAD_FAST 7
    0xb3, // LOAD_FAST 3
    0xb2, // LOAD_FAST 2
    0x14,0x25, // LOAD_METHOD 'get'
    0x10,0x16, // LOAD_CONST_STRING 'nargs'
    0x51, // LOAD_CONST_NONE
    0x36,0x02, // CALL_METHOD 2
    0xb4, // LOAD_FAST 4
    0xb5, // LOAD_FAST 5
    0xb2, // LOAD_FAST 2
    0x14,0x25, // LOAD_METHOD 'get'
    0x10,0x19, // LOAD_CONST_STRING 'help'
    0x10,0x10, // LOAD_CONST_STRING ''
    0x36,0x02, // CALL_METHOD 2
    0x34,0x07, // CALL_FUNCTION 7
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_argparse_ArgumentParser_add_argument = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_argparse_ArgumentParser_add_argument,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 208,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 21,
        .n_exc_stack = 0,
        .scope_flags = 6,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 36,
        .line_info = fun_data_argparse_ArgumentParser_add_argument + 7,
        .line_info_top = fun_data_argparse_ArgumentParser_add_argument + 35,
        .opcodes = fun_data_argparse_ArgumentParser_add_argument + 35,
    },
    #endif
    #endif
};
#else
#define proto_fun_argparse_ArgumentParser_add_argument fun_data_argparse_ArgumentParser_add_argument[0]
#endif

// child of argparse_ArgumentParser
// frozen bytecode for file argparse.py, scope argparse_ArgumentParser_usage
static const byte fun_data_argparse_ArgumentParser_usage[228] = {
    0x6a,0x32, // prelude
    0x27,0x41,0x44, // names: usage, self, full
    0x80,0x77,0x53,0x83,0x0b,0x27,0x3e,0x27,0x30,0x45,0x23,0x62,0x25,0x25,0x28,0x25,0x27,0x27,0x34,0x27,0x27,0x27, // code info
    0x12,0x45, // LOAD_GLOBAL 'print'
    0x23,0x03, // LOAD_CONST_OBJ 3
    0x12,0x02, // LOAD_GLOBAL 'sys'
    0x13,0x28, // LOAD_ATTR 'argv'
    0x80, // LOAD_CONST_SMALL_INT 0
    0x55, // LOAD_SUBSCR
    0xf8, // BINARY_OP 33 __mod__
    0x10,0x29, // LOAD_CONST_STRING 'end'
    0x10,0x10, // LOAD_CONST_STRING ''
    0x34,0x82,0x01, // CALL_FUNCTION 257
    0x59, // POP_TOP
    0x32,0x00, // MAKE_FUNCTION 0
    0xc2, // STORE_FAST 2
    0xb0, // LOAD_FAST 0
    0x13,0x22, // LOAD_ATTR 'opt'
    0x5f, // GET_ITER_STACK
    0x4b,0x1f, // FOR_ITER 31
    0xc3, // STORE_FAST 3
    0x12,0x45, // LOAD_GLOBAL 'print'
    0x10,0x2a, // LOAD_CONST_STRING ' [%s%s]'
    0x10,0x2b, // LOAD_CONST_STRING ', '
    0x14,0x2c, // LOAD_METHOD 'join'
    0xb3, // LOAD_FAST 3
    0x13,0x13, // LOAD_ATTR 'names'
    0x36,0x01, // CALL_METHOD 1
    0xb2, // LOAD_FAST 2
    0xb3, // LOAD_FAST 3
    0x34,0x01, // CALL_FUNCTION 1
    0x2a,0x02, // BUILD_TUPLE 2
    0xf8, // BINARY_OP 33 __mod__
    0x10,0x29, // LOAD_CONST_STRING 'end'
    0x10,0x10, // LOAD_CONST_STRING ''
    0x34,0x82,0x01, // CALL_FUNCTION 257
    0x59, // POP_TOP
    0x42,0x1f, // JUMP -33
    0xb0, // LOAD_FAST 0
    0x13,0x23, // LOAD_ATTR 'pos'
    0x5f, // GET_ITER_STACK
    0x4b,0x11, // FOR_ITER 17
    0xc4, // STORE_FAST 4
    0x12,0x45, // LOAD_GLOBAL 'print'
    0xb2, // LOAD_FAST 2
    0xb4, // LOAD_FAST 4
    0x34,0x01, // CALL_FUNCTION 1
    0x10,0x29, // LOAD_CONST_STRING 'end'
    0x10,0x10, // LOAD_CONST_STRING ''
    0x34,0x82,0x01, // CALL_FUNCTION 257
    0x59, // POP_TOP
    0x42,0x2d, // JUMP -19
    0x12,0x45, // LOAD_GLOBAL 'print'
    0x34,0x00, // CALL_FUNCTION 0
    0x59, // POP_TOP
    0xb1, // LOAD_FAST 1
    0x43,0x42, // POP_JUMP_IF_TRUE 2
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
    0x12,0x45, // LOAD_GLOBAL 'print'
    0x34,0x00, // CALL_FUNCTION 0
    0x59, // POP_TOP
    0xb0, // LOAD_FAST 0
    0x13,0x11, // LOAD_ATTR 'description'
    0x44,0x48, // POP_JUMP_IF_FALSE 8
    0x12,0x45, // LOAD_GLOBAL 'print'
    0xb0, // LOAD_FAST 0
    0x13,0x11, // LOAD_ATTR 'description'
    0x34,0x01, // CALL_FUNCTION 1
    0x59, // POP_TOP
    0xb0, // LOAD_FAST 0
    0x13,0x23, // LOAD_ATTR 'pos'
    0x44,0x62, // POP_JUMP_IF_FALSE 34
    0x12,0x45, // LOAD_GLOBAL 'print'
    0x23,0x04, // LOAD_CONST_OBJ 4
    0x34,0x01, // CALL_FUNCTION 1
    0x59, // POP_TOP
    0xb0, // LOAD_FAST 0
    0x13,0x23, // LOAD_ATTR 'pos'
    0x5f, // GET_ITER_STACK
    0x4b,0x15, // FOR_ITER 21
    0xc4, // STORE_FAST 4
    0x12,0x45, // LOAD_GLOBAL 'print'
    0x10,0x2d, // LOAD_CONST_STRING '  %-16s%s'
    0xb4, // LOAD_FAST 4
    0x13,0x13, // LOAD_ATTR 'names'
    0x80, // LOAD_CONST_SMALL_INT 0
    0x55, // LOAD_SUBSCR
    0xb4, // LOAD_FAST 4
    0x13,0x19, // LOAD_ATTR 'help'
    0x2a,0x02, // BUILD_TUPLE 2
    0xf8, // BINARY_OP 33 __mod__
    0x34,0x01, // CALL_FUNCTION 1
    0x59, // POP_TOP
    0x42,0x29, // JUMP -23
    0x12,0x45, // LOAD_GLOBAL 'print'
    0x23,0x05, // LOAD_CONST_OBJ 5
    0x34,0x01, // CALL_FUNCTION 1
    0x59, // POP_TOP
    0x12,0x45, // LOAD_GLOBAL 'print'
    0x23,0x06, // LOAD_CONST_OBJ 6
    0x34,0x01, // CALL_FUNCTION 1
    0x59, // POP_TOP
    0xb0, // LOAD_FAST 0
    0x13,0x22, // LOAD_ATTR 'opt'
    0x5f, // GET_ITER_STACK
    0x4b,0x1e, // FOR_ITER 30
    0xc3, // STORE_FAST 3
    0x12,0x45, // LOAD_GLOBAL 'print'
    0x10,0x2d, // LOAD_CONST_STRING '  %-16s%s'
    0x10,0x2b, // LOAD_CONST_STRING ', '
    0x14,0x2c, // LOAD_METHOD 'join'
    0xb3, // LOAD_FAST 3
    0x13,0x13, // LOAD_ATTR 'names'
    0x36,0x01, // CALL_METHOD 1
    0xb2, // LOAD_FAST 2
    0xb3, // LOAD_FAST 3
    0x34,0x01, // CALL_FUNCTION 1
    0xf2, // BINARY_OP 27 __add__
    0xb3, // LOAD_FAST 3
    0x13,0x19, // LOAD_ATTR 'help'
    0x2a,0x02, // BUILD_TUPLE 2
    0xf8, // BINARY_OP 33 __mod__
    0x34,0x01, // CALL_FUNCTION 1
    0x59, // POP_TOP
    0x42,0x20, // JUMP -32
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
// child of argparse_ArgumentParser_usage
// frozen bytecode for file argparse.py, scope argparse_ArgumentParser_usage_render_arg
static const byte fun_data_argparse_ArgumentParser_usage_render_arg[76] = {
    0x19,0x14, // prelude
    0x36,0x48, // names: render_arg, arg
    0x80,0x7a,0x28,0x27,0x27,0x2b,0x4c,0x4e, // code info
    0xb0, // LOAD_FAST 0
    0x13,0x15, // LOAD_ATTR 'action'
    0x10,0x1b, // LOAD_CONST_STRING 'store'
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x73, // POP_JUMP_IF_FALSE 51
    0xb0, // LOAD_FAST 0
    0x13,0x16, // LOAD_ATTR 'nargs'
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0x44,0x47, // POP_JUMP_IF_FALSE 7
    0x10,0x37, // LOAD_CONST_STRING ' %s'
    0xb0, // LOAD_FAST 0
    0x13,0x14, // LOAD_ATTR 'dest'
    0xf8, // BINARY_OP 33 __mod__
    0x63, // RETURN_VALUE
    0x12,0x49, // LOAD_GLOBAL 'isinstance'
    0xb0, // LOAD_FAST 0
    0x13,0x16, // LOAD_ATTR 'nargs'
    0x12,0x43, // LOAD_GLOBAL 'int'
    0x34,0x02, // CALL_FUNCTION 2
    0x44,0x4c, // POP_JUMP_IF_FALSE 12
    0x10,0x38, // LOAD_CONST_STRING ' %s(x%d)'
    0xb0, // LOAD_FAST 0
    0x13,0x14, // LOAD_ATTR 'dest'
    0xb0, // LOAD_FAST 0
    0x13,0x16, // LOAD_ATTR 'nargs'
    0x2a,0x02, // BUILD_TUPLE 2
    0xf8, // BINARY_OP 33 __mod__
    0x63, // RETURN_VALUE
    0x10,0x39, // LOAD_CONST_STRING ' %s%s'
    0xb0, // LOAD_FAST 0
    0x13,0x14, // LOAD_ATTR 'dest'
    0xb0, // LOAD_FAST 0
    0x13,0x16, // LOAD_ATTR 'nargs'
    0x2a,0x02, // BUILD_TUPLE 2
    0xf8, // BINARY_OP 33 __mod__
    0x63, // RETURN_VALUE
    0x42,0x43, // JUMP 3
    0x10,0x10, // LOAD_CONST_STRING ''
    0x63, // RETURN_VALUE
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_argparse_ArgumentParser_usage_render_arg = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_argparse_ArgumentParser_usage_render_arg,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 76,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 54,
        .line_info = fun_data_argparse_ArgumentParser_usage_render_arg + 4,
        .line_info_top = fun_data_argparse_ArgumentParser_usage_render_arg + 12,
        .opcodes = fun_data_argparse_ArgumentParser_usage_render_arg + 12,
    },
    #endif
    #endif
};
#else
#define proto_fun_argparse_ArgumentParser_usage_render_arg fun_data_argparse_ArgumentParser_usage_render_arg[0]
#endif

static const mp_raw_code_t *const children_argparse_ArgumentParser_usage[] = {
    (const mp_raw_code_t *)&proto_fun_argparse_ArgumentParser_usage_render_arg,
};

static const mp_raw_code_truncated_t proto_fun_argparse_ArgumentParser_usage = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_argparse_ArgumentParser_usage,
    .children = (void *)&children_argparse_ArgumentParser_usage,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 228,
    .n_children = 1,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 14,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 39,
        .line_info = fun_data_argparse_ArgumentParser_usage + 5,
        .line_info_top = fun_data_argparse_ArgumentParser_usage + 27,
        .opcodes = fun_data_argparse_ArgumentParser_usage + 27,
    },
    #endif
    #endif
};

// child of argparse_ArgumentParser
// frozen bytecode for file argparse.py, scope argparse_ArgumentParser_parse_args
static const byte fun_data_argparse_ArgumentParser_parse_args[16] = {
    0xaa,0x01,0x0a, // prelude
    0x2e,0x41,0x35, // names: parse_args, self, args
    0x80,0x9b, // code info
    0xb0, // LOAD_FAST 0
    0x14,0x2f, // LOAD_METHOD '_parse_args_impl'
    0xb1, // LOAD_FAST 1
    0x50, // LOAD_CONST_FALSE
    0x36,0x02, // CALL_METHOD 2
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_argparse_ArgumentParser_parse_args = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_argparse_ArgumentParser_parse_args,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 16,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 6,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 1,
        .qstr_block_name_idx = 46,
        .line_info = fun_data_argparse_ArgumentParser_parse_args + 6,
        .line_info_top = fun_data_argparse_ArgumentParser_parse_args + 8,
        .opcodes = fun_data_argparse_ArgumentParser_parse_args + 8,
    },
    #endif
    #endif
};
#else
#define proto_fun_argparse_ArgumentParser_parse_args fun_data_argparse_ArgumentParser_parse_args[0]
#endif

// child of argparse_ArgumentParser
// frozen bytecode for file argparse.py, scope argparse_ArgumentParser_parse_known_args
static const byte fun_data_argparse_ArgumentParser_parse_known_args[16] = {
    0xaa,0x01,0x0a, // prelude
    0x30,0x41,0x35, // names: parse_known_args, self, args
    0x80,0x9e, // code info
    0xb0, // LOAD_FAST 0
    0x14,0x2f, // LOAD_METHOD '_parse_args_impl'
    0xb1, // LOAD_FAST 1
    0x52, // LOAD_CONST_TRUE
    0x36,0x02, // CALL_METHOD 2
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_argparse_ArgumentParser_parse_known_args = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_argparse_ArgumentParser_parse_known_args,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 16,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 6,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 1,
        .qstr_block_name_idx = 48,
        .line_info = fun_data_argparse_ArgumentParser_parse_known_args + 6,
        .line_info_top = fun_data_argparse_ArgumentParser_parse_known_args + 8,
        .opcodes = fun_data_argparse_ArgumentParser_parse_known_args + 8,
    },
    #endif
    #endif
};
#else
#define proto_fun_argparse_ArgumentParser_parse_known_args fun_data_argparse_ArgumentParser_parse_known_args[0]
#endif

// child of argparse_ArgumentParser
// frozen bytecode for file argparse.py, scope argparse_ArgumentParser__parse_args_impl
static const byte fun_data_argparse_ArgumentParser__parse_args_impl[93] = {
    0xcb,0x02,0x1a, // prelude
    0x2f,0x41,0x35,0x46, // names: _parse_args_impl, self, args, return_unknown
    0x80,0xa1,0x25,0x4c,0x27,0x22,0x51,0x27,0x28, // code info
    0xb1, // LOAD_FAST 1
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0x44,0x4c, // POP_JUMP_IF_FALSE 12
    0x12,0x02, // LOAD_GLOBAL 'sys'
    0x13,0x28, // LOAD_ATTR 'argv'
    0x81, // LOAD_CONST_SMALL_INT 1
    0x51, // LOAD_CONST_NONE
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0xc1, // STORE_FAST 1
    0x42,0x47, // JUMP 7
    0xb1, // LOAD_FAST 1
    0x51, // LOAD_CONST_NONE
    0x51, // LOAD_CONST_NONE
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0xc1, // STORE_FAST 1
    0x48,0x08, // SETUP_EXCEPT 8
    0xb0, // LOAD_FAST 0
    0x14,0x31, // LOAD_METHOD '_parse_args'
    0xb1, // LOAD_FAST 1
    0xb2, // LOAD_FAST 2
    0x36,0x02, // CALL_METHOD 2
    0x63, // RETURN_VALUE
    0x57, // DUP_TOP
    0x12,0x05, // LOAD_GLOBAL '_ArgError'
    0xdf, // BINARY_OP 8 <exception match>
    0x44,0x62, // POP_JUMP_IF_FALSE 34
    0xc3, // STORE_FAST 3
    0x49,0x18, // SETUP_FINALLY 24
    0xb0, // LOAD_FAST 0
    0x14,0x27, // LOAD_METHOD 'usage'
    0x50, // LOAD_CONST_FALSE
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x12,0x45, // LOAD_GLOBAL 'print'
    0x10,0x32, // LOAD_CONST_STRING 'error:'
    0xb3, // LOAD_FAST 3
    0x34,0x02, // CALL_FUNCTION 2
    0x59, // POP_TOP
    0x12,0x02, // LOAD_GLOBAL 'sys'
    0x14,0x33, // LOAD_METHOD 'exit'
    0x82, // LOAD_CONST_SMALL_INT 2
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x51, // LOAD_CONST_NONE
    0x51, // LOAD_CONST_NONE
    0xc3, // STORE_FAST 3
    0x28,0x03, // DELETE_FAST 3
    0x5d, // END_FINALLY
    0x4a,0x01, // POP_EXCEPT_JUMP 1
    0x5d, // END_FINALLY
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_argparse_ArgumentParser__parse_args_impl = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_argparse_ArgumentParser__parse_args_impl,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 93,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 10,
        .n_exc_stack = 2,
        .scope_flags = 0,
        .n_pos_args = 3,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 47,
        .line_info = fun_data_argparse_ArgumentParser__parse_args_impl + 7,
        .line_info_top = fun_data_argparse_ArgumentParser__parse_args_impl + 16,
        .opcodes = fun_data_argparse_ArgumentParser__parse_args_impl + 16,
    },
    #endif
    #endif
};
#else
#define proto_fun_argparse_ArgumentParser__parse_args_impl fun_data_argparse_ArgumentParser__parse_args_impl[0]
#endif

// child of argparse_ArgumentParser
// frozen bytecode for file argparse.py, scope argparse_ArgumentParser__parse_args
static const byte fun_data_argparse_ArgumentParser__parse_args[351] = {
    0xbb,0x10,0xda,0x01, // prelude
    0x31,0x41,0x35,0x46, // names: _parse_args, self, args, return_unknown
    0x80,0xae,0x23,0x23,0x27,0x29,0x6b,0x44,0x66,0x40,0x22,0x23,0x1f,0x47,0x28,0x26,0x27,0x28,0x22,0x2e,0x27,0x2b,0x22,0x28,0x23,0x23,0x28,0x46,0x6c,0x23,0x23,0x27,0x43,0x30,0x27,0x29,0x34,0x22,0x23,0x6d,0x2c,0x01,0x0d, // code info
    0x2b,0x00, // BUILD_LIST 0
    0xc3, // STORE_FAST 3
    0x2b,0x00, // BUILD_LIST 0
    0xc4, // STORE_FAST 4
    0xb0, // LOAD_FAST 0
    0x13,0x22, // LOAD_ATTR 'opt'
    0x5f, // GET_ITER_STACK
    0x4b,0x15, // FOR_ITER 21
    0xc5, // STORE_FAST 5
    0xb3, // LOAD_FAST 3
    0x14,0x20, // LOAD_METHOD 'append'
    0xb5, // LOAD_FAST 5
    0x13,0x14, // LOAD_ATTR 'dest'
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0xb4, // LOAD_FAST 4
    0x14,0x20, // LOAD_METHOD 'append'
    0xb5, // LOAD_FAST 5
    0x13,0x18, // LOAD_ATTR 'default'
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x42,0x29, // JUMP -23
    0x2b,0x00, // BUILD_LIST 0
    0x27,0x0d, // STORE_DEREF 13
    0xb1, // LOAD_FAST 1
    0xbd, // LOAD_FAST 13
    0x20,0x00,0x02, // MAKE_CLOSURE 0
    0xc6, // STORE_FAST 6
    0x50, // LOAD_CONST_FALSE
    0xc7, // STORE_FAST 7
    0x42,0xdc,0x81, // JUMP 220
    0x25,0x01, // LOAD_DEREF 1
    0x44,0x8a,0x81, // POP_JUMP_IF_FALSE 138
    0x25,0x01, // LOAD_DEREF 1
    0x80, // LOAD_CONST_SMALL_INT 0
    0x55, // LOAD_SUBSCR
    0x14,0x0a, // LOAD_METHOD 'startswith'
    0x10,0x0d, // LOAD_CONST_STRING '-'
    0x36,0x01, // CALL_METHOD 1
    0x44,0xfd,0x80, // POP_JUMP_IF_FALSE 125
    0x25,0x01, // LOAD_DEREF 1
    0x80, // LOAD_CONST_SMALL_INT 0
    0x55, // LOAD_SUBSCR
    0x10,0x0d, // LOAD_CONST_STRING '-'
    0xdc, // BINARY_OP 5 __ne__
    0x44,0xf3,0x80, // POP_JUMP_IF_FALSE 115
    0x25,0x01, // LOAD_DEREF 1
    0x80, // LOAD_CONST_SMALL_INT 0
    0x55, // LOAD_SUBSCR
    0x10,0x0b, // LOAD_CONST_STRING '--'
    0xdc, // BINARY_OP 5 __ne__
    0x44,0xe9,0x80, // POP_JUMP_IF_FALSE 105
    0x25,0x01, // LOAD_DEREF 1
    0x14,0x1c, // LOAD_METHOD 'pop'
    0x80, // LOAD_CONST_SMALL_INT 0
    0x36,0x01, // CALL_METHOD 1
    0xc8, // STORE_FAST 8
    0xb8, // LOAD_FAST 8
    0x23,0x07, // LOAD_CONST_OBJ 7
    0xdd, // BINARY_OP 6 <in>
    0x44,0x4f, // POP_JUMP_IF_FALSE 15
    0xb0, // LOAD_FAST 0
    0x14,0x27, // LOAD_METHOD 'usage'
    0x52, // LOAD_CONST_TRUE
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x12,0x02, // LOAD_GLOBAL 'sys'
    0x14,0x33, // LOAD_METHOD 'exit'
    0x80, // LOAD_CONST_SMALL_INT 0
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x50, // LOAD_CONST_FALSE
    0xc9, // STORE_FAST 9
    0x12,0x47, // LOAD_GLOBAL 'enumerate'
    0xb0, // LOAD_FAST 0
    0x13,0x22, // LOAD_ATTR 'opt'
    0x34,0x01, // CALL_FUNCTION 1
    0x5f, // GET_ITER_STACK
    0x4b,0x20, // FOR_ITER 32
    0x30,0x02, // UNPACK_SEQUENCE 2
    0xca, // STORE_FAST 10
    0xc5, // STORE_FAST 5
    0xb8, // LOAD_FAST 8
    0xb5, // LOAD_FAST 5
    0x13,0x13, // LOAD_ATTR 'names'
    0xdd, // BINARY_OP 6 <in>
    0x44,0x53, // POP_JUMP_IF_FALSE 19
    0xb5, // LOAD_FAST 5
    0x14,0x1a, // LOAD_METHOD 'parse'
    0xb8, // LOAD_FAST 8
    0x25,0x01, // LOAD_DEREF 1
    0x36,0x02, // CALL_METHOD 2
    0xb4, // LOAD_FAST 4
    0xba, // LOAD_FAST 10
    0x56, // STORE_SUBSCR
    0x52, // LOAD_CONST_TRUE
    0xc9, // STORE_FAST 9
    0x59, // POP_TOP
    0x59, // POP_TOP
    0x59, // POP_TOP
    0x59, // POP_TOP
    0x42,0x42, // JUMP 2
    0x42,0x1e, // JUMP -34
    0xb9, // LOAD_FAST 9
    0x43,0x5a, // POP_JUMP_IF_TRUE 26
    0xb2, // LOAD_FAST 2
    0x44,0x4e, // POP_JUMP_IF_FALSE 14
    0x25,0x0d, // LOAD_DEREF 13
    0x14,0x20, // LOAD_METHOD 'append'
    0xb8, // LOAD_FAST 8
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0xb6, // LOAD_FAST 6
    0x34,0x00, // CALL_FUNCTION 0
    0x59, // POP_TOP
    0x42,0x49, // JUMP 9
    0x12,0x05, // LOAD_GLOBAL '_ArgError'
    0x23,0x08, // LOAD_CONST_OBJ 8
    0xb8, // LOAD_FAST 8
    0xf8, // BINARY_OP 33 __mod__
    0x34,0x01, // CALL_FUNCTION 1
    0x65, // RAISE_OBJ
    0x42,0xcd,0x80, // JUMP 77
    0xb7, // LOAD_FAST 7
    0x44,0x5d, // POP_JUMP_IF_FALSE 29
    0xb2, // LOAD_FAST 2
    0x44,0x4a, // POP_JUMP_IF_FALSE 10
    0x25,0x0d, // LOAD_DEREF 13
    0x25,0x01, // LOAD_DEREF 1
    0xf2, // BINARY_OP 27 __add__
    0x27,0x0d, // STORE_DEREF 13
    0x42,0xc6,0x80, // JUMP 70
    0x12,0x05, // LOAD_GLOBAL '_ArgError'
    0x23,0x09, // LOAD_CONST_OBJ 9
    0x10,0x34, // LOAD_CONST_STRING ' '
    0x14,0x2c, // LOAD_METHOD 'join'
    0x25,0x01, // LOAD_DEREF 1
    0x36,0x01, // CALL_METHOD 1
    0xf8, // BINARY_OP 33 __mod__
    0x34,0x01, // CALL_FUNCTION 1
    0x65, // RAISE_OBJ
    0xb0, // LOAD_FAST 0
    0x13,0x23, // LOAD_ATTR 'pos'
    0x5f, // GET_ITER_STACK
    0x4b,0x1e, // FOR_ITER 30
    0xcb, // STORE_FAST 11
    0xb3, // LOAD_FAST 3
    0x14,0x20, // LOAD_METHOD 'append'
    0xbb, // LOAD_FAST 11
    0x13,0x14, // LOAD_ATTR 'dest'
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0xb4, // LOAD_FAST 4
    0x14,0x20, // LOAD_METHOD 'append'
    0xbb, // LOAD_FAST 11
    0x14,0x1a, // LOAD_METHOD 'parse'
    0xbb, // LOAD_FAST 11
    0x13,0x13, // LOAD_ATTR 'names'
    0x80, // LOAD_CONST_SMALL_INT 0
    0x55, // LOAD_SUBSCR
    0x25,0x01, // LOAD_DEREF 1
    0x36,0x02, // CALL_METHOD 2
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x42,0x20, // JUMP -32
    0x52, // LOAD_CONST_TRUE
    0xc7, // STORE_FAST 7
    0xb2, // LOAD_FAST 2
    0x44,0x44, // POP_JUMP_IF_FALSE 4
    0xb6, // LOAD_FAST 6
    0x34,0x00, // CALL_FUNCTION 0
    0x59, // POP_TOP
    0x25,0x01, // LOAD_DEREF 1
    0x43,0x9f,0x7e, // POP_JUMP_IF_TRUE -225
    0xb7, // LOAD_FAST 7
    0x44,0x9b,0x7e, // POP_JUMP_IF_FALSE -229
    0x12,0x03, // LOAD_GLOBAL 'namedtuple'
    0x10,0x35, // LOAD_CONST_STRING 'args'
    0xb3, // LOAD_FAST 3
    0x34,0x02, // CALL_FUNCTION 2
    0xb4, // LOAD_FAST 4
    0x81, // LOAD_CONST_SMALL_INT 1
    0x35,0x01, // CALL_FUNCTION_VAR_KW 1
    0xcc, // STORE_FAST 12
    0xb2, // LOAD_FAST 2
    0x44,0x46, // POP_JUMP_IF_FALSE 6
    0xbc, // LOAD_FAST 12
    0x25,0x0d, // LOAD_DEREF 13
    0x2a,0x02, // BUILD_TUPLE 2
    0x63, // RETURN_VALUE
    0xbc, // LOAD_FAST 12
    0x63, // RETURN_VALUE
};
// child of argparse_ArgumentParser__parse_args
// frozen bytecode for file argparse.py, scope argparse_ArgumentParser__parse_args_consume_unknown
static const byte fun_data_argparse_ArgumentParser__parse_args_consume_unknown[42] = {
    0x32,0x0c, // prelude
    0x3a,0x1e,0x1e, // names: consume_unknown, *, *
    0x80,0xb8,0x22, // code info
    0x42,0x4e, // JUMP 14
    0x25,0x01, // LOAD_DEREF 1
    0x14,0x20, // LOAD_METHOD 'append'
    0x25,0x00, // LOAD_DEREF 0
    0x14,0x1c, // LOAD_METHOD 'pop'
    0x80, // LOAD_CONST_SMALL_INT 0
    0x36,0x01, // CALL_METHOD 1
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x25,0x00, // LOAD_DEREF 0
    0x44,0x4c, // POP_JUMP_IF_FALSE 12
    0x25,0x00, // LOAD_DEREF 0
    0x80, // LOAD_CONST_SMALL_INT 0
    0x55, // LOAD_SUBSCR
    0x14,0x0a, // LOAD_METHOD 'startswith'
    0x10,0x0d, // LOAD_CONST_STRING '-'
    0x36,0x01, // CALL_METHOD 1
    0x44,0x22, // POP_JUMP_IF_FALSE -30
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_argparse_ArgumentParser__parse_args_consume_unknown = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_argparse_ArgumentParser__parse_args_consume_unknown,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 42,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 7,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 58,
        .line_info = fun_data_argparse_ArgumentParser__parse_args_consume_unknown + 5,
        .line_info_top = fun_data_argparse_ArgumentParser__parse_args_consume_unknown + 8,
        .opcodes = fun_data_argparse_ArgumentParser__parse_args_consume_unknown + 8,
    },
    #endif
    #endif
};
#else
#define proto_fun_argparse_ArgumentParser__parse_args_consume_unknown fun_data_argparse_ArgumentParser__parse_args_consume_unknown[0]
#endif

static const mp_raw_code_t *const children_argparse_ArgumentParser__parse_args[] = {
    (const mp_raw_code_t *)&proto_fun_argparse_ArgumentParser__parse_args_consume_unknown,
};

static const mp_raw_code_truncated_t proto_fun_argparse_ArgumentParser__parse_args = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_argparse_ArgumentParser__parse_args,
    .children = (void *)&children_argparse_ArgumentParser__parse_args,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 351,
    .n_children = 1,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 24,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 3,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 49,
        .line_info = fun_data_argparse_ArgumentParser__parse_args + 8,
        .line_info_top = fun_data_argparse_ArgumentParser__parse_args + 49,
        .opcodes = fun_data_argparse_ArgumentParser__parse_args + 51,
    },
    #endif
    #endif
};

static const mp_raw_code_t *const children_argparse_ArgumentParser[] = {
    (const mp_raw_code_t *)&proto_fun_argparse_ArgumentParser___init__,
    (const mp_raw_code_t *)&proto_fun_argparse_ArgumentParser_add_argument,
    (const mp_raw_code_t *)&proto_fun_argparse_ArgumentParser_usage,
    (const mp_raw_code_t *)&proto_fun_argparse_ArgumentParser_parse_args,
    (const mp_raw_code_t *)&proto_fun_argparse_ArgumentParser_parse_known_args,
    (const mp_raw_code_t *)&proto_fun_argparse_ArgumentParser__parse_args_impl,
    (const mp_raw_code_t *)&proto_fun_argparse_ArgumentParser__parse_args,
};

static const mp_raw_code_truncated_t proto_fun_argparse_ArgumentParser = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_argparse_ArgumentParser,
    .children = (void *)&children_argparse_ArgumentParser,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 69,
    .n_children = 7,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 7,
        .line_info = fun_data_argparse_ArgumentParser + 3,
        .line_info_top = fun_data_argparse_ArgumentParser + 15,
        .opcodes = fun_data_argparse_ArgumentParser + 15,
    },
    #endif
    #endif
};

static const mp_raw_code_t *const children_argparse__lt_module_gt_[] = {
    (const mp_raw_code_t *)&proto_fun_argparse__ArgError,
    (const mp_raw_code_t *)&proto_fun_argparse__Arg,
    (const mp_raw_code_t *)&proto_fun_argparse__dest_from_optnames,
    (const mp_raw_code_t *)&proto_fun_argparse_ArgumentParser,
};

static const mp_raw_code_truncated_t proto_fun_argparse__lt_module_gt_ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_argparse__lt_module_gt_,
    .children = (void *)&children_argparse__lt_module_gt_,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 72,
    .n_children = 4,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 1,
        .line_info = fun_data_argparse__lt_module_gt_ + 3,
        .line_info_top = fun_data_argparse__lt_module_gt_ + 15,
        .opcodes = fun_data_argparse__lt_module_gt_ + 15,
    },
    #endif
    #endif
};

static const qstr_short_t const_qstr_table_data_argparse[74] = {
    MP_QSTR_argparse_dot_py,
    MP_QSTR__lt_module_gt_,
    MP_QSTR_sys,
    MP_QSTR_namedtuple,
    MP_QSTR_collections,
    MP_QSTR__ArgError,
    MP_QSTR__Arg,
    MP_QSTR_ArgumentParser,
    MP_QSTR_0_dot_4_dot_0,
    MP_QSTR__dest_from_optnames,
    MP_QSTR_startswith,
    MP_QSTR__hyphen__hyphen_,
    MP_QSTR_lstrip,
    MP_QSTR__hyphen_,
    MP_QSTR_replace,
    MP_QSTR__,
    MP_QSTR_,
    MP_QSTR_description,
    MP_QSTR___init__,
    MP_QSTR_names,
    MP_QSTR_dest,
    MP_QSTR_action,
    MP_QSTR_nargs,
    MP_QSTR_const,
    MP_QSTR_default,
    MP_QSTR_help,
    MP_QSTR_parse,
    MP_QSTR_store,
    MP_QSTR_pop,
    MP_QSTR__question_,
    MP_QSTR__star_,
    MP_QSTR__plus_,
    MP_QSTR_append,
    MP_QSTR_AssertionError,
    MP_QSTR_opt,
    MP_QSTR_pos,
    MP_QSTR_add_argument,
    MP_QSTR_get,
    MP_QSTR_store_true,
    MP_QSTR_usage,
    MP_QSTR_argv,
    MP_QSTR_end,
    MP_QSTR__space__bracket_open__percent_s_percent_s_bracket_close_,
    MP_QSTR__comma__space_,
    MP_QSTR_join,
    MP_QSTR__space__space__percent__hyphen_16s_percent_s,
    MP_QSTR_parse_args,
    MP_QSTR__parse_args_impl,
    MP_QSTR_parse_known_args,
    MP_QSTR__parse_args,
    MP_QSTR_error_colon_,
    MP_QSTR_exit,
    MP_QSTR__space_,
    MP_QSTR_args,
    MP_QSTR_render_arg,
    MP_QSTR__space__percent_s,
    MP_QSTR__space__percent_s_paren_open_x_percent_d_paren_close_,
    MP_QSTR__space__percent_s_percent_s,
    MP_QSTR_consume_unknown,
    MP_QSTR_BaseException,
    MP_QSTR___version__,
    MP_QSTR___name__,
    MP_QSTR___module__,
    MP_QSTR___qualname__,
    MP_QSTR_opt_names,
    MP_QSTR_self,
    MP_QSTR_optname,
    MP_QSTR_int,
    MP_QSTR_full,
    MP_QSTR_print,
    MP_QSTR_return_unknown,
    MP_QSTR_enumerate,
    MP_QSTR_arg,
    MP_QSTR_isinstance,
};

// constants
static const mp_obj_str_t const_obj_argparse_6 = {{&mp_type_str}, 48152, 44, (const byte*)"\x20\x20\x2d\x68\x2c\x20\x2d\x2d\x68\x65\x6c\x70\x20\x20\x20\x20\x20\x20\x73\x68\x6f\x77\x20\x74\x68\x69\x73\x20\x6d\x65\x73\x73\x61\x67\x65\x20\x61\x6e\x64\x20\x65\x78\x69\x74"};
static const mp_rom_obj_tuple_t const_obj_argparse_7 = {{&mp_type_tuple}, 2, {
    MP_ROM_QSTR(MP_QSTR__hyphen_h),
    MP_ROM_QSTR(MP_QSTR__hyphen__hyphen_help),
}};

// constant table
static const mp_rom_obj_t const_obj_table_data_argparse[10] = {
    MP_ROM_QSTR(MP_QSTR_expecting_space_value_space_for_space__percent_s),
    MP_ROM_QSTR(MP_QSTR_store_const),
    MP_ROM_QSTR(MP_QSTR_store_false),
    MP_ROM_QSTR(MP_QSTR_usage_colon__space__percent_s_space__bracket_open__hyphen_h_bracket_close_),
    MP_ROM_QSTR(MP_QSTR__0x0a_positional_space_args_colon_),
    MP_ROM_QSTR(MP_QSTR__0x0a_optional_space_args_colon_),
    MP_ROM_PTR(&const_obj_argparse_6),
    MP_ROM_PTR(&const_obj_argparse_7),
    MP_ROM_QSTR(MP_QSTR_unknown_space_option_space__percent_s),
    MP_ROM_QSTR(MP_QSTR_extra_space_args_colon__space__percent_s),
};

static const mp_frozen_module_t frozen_module_argparse = {
    .constants = {
        .qstr_table = (qstr_short_t *)&const_qstr_table_data_argparse,
        .obj_table = (mp_obj_t *)&const_obj_table_data_argparse,
    },
    .proto_fun = &proto_fun_argparse__lt_module_gt_,
};

////////////////////////////////////////////////////////////////////////////////
// frozen module requests___init__
// - original source file: /Users/gadgetoid/Development/micropython-web/picovector/ports/sokol/build/frozen_mpy/requests/__init__.mpy
// - frozen file name: requests/__init__.py
// - .mpy header: 4d:06:00:1f

// frozen bytecode for file requests/__init__.py, scope requests___init____lt_module_gt_
static const byte fun_data_requests___init____lt_module_gt_[79] = {
    0x30,0x24, // prelude
    0x01, // names: <module>
    0x66,0x89,0x20,0x8e,0xa4,0x64,0x20,0x64,0x20,0x64,0x20,0x64,0x20,0x64,0x20,0x64,0x20, // code info
    0x80, // LOAD_CONST_SMALL_INT 0
    0x51, // LOAD_CONST_NONE
    0x1b,0x02, // IMPORT_NAME 'socket'
    0x16,0x02, // STORE_NAME 'socket'
    0x54, // LOAD_BUILD_CLASS
    0x32,0x00, // MAKE_FUNCTION 0
    0x10,0x03, // LOAD_CONST_STRING 'Response'
    0x34,0x02, // CALL_FUNCTION 2
    0x16,0x03, // STORE_NAME 'Response'
    0x51, // LOAD_CONST_NONE
    0x51, // LOAD_CONST_NONE
    0x51, // LOAD_CONST_NONE
    0x51, // LOAD_CONST_NONE
    0x51, // LOAD_CONST_NONE
    0x51, // LOAD_CONST_NONE
    0x52, // LOAD_CONST_TRUE
    0x2a,0x07, // BUILD_TUPLE 7
    0x53, // LOAD_NULL
    0x33,0x01, // MAKE_FUNCTION_DEFARGS 1
    0x16,0x05, // STORE_NAME 'request'
    0x32,0x02, // MAKE_FUNCTION 2
    0x16,0x33, // STORE_NAME 'head'
    0x32,0x03, // MAKE_FUNCTION 3
    0x16,0x27, // STORE_NAME 'get'
    0x32,0x04, // MAKE_FUNCTION 4
    0x16,0x35, // STORE_NAME 'post'
    0x32,0x05, // MAKE_FUNCTION 5
    0x16,0x37, // STORE_NAME 'put'
    0x32,0x06, // MAKE_FUNCTION 6
    0x16,0x39, // STORE_NAME 'patch'
    0x32,0x07, // MAKE_FUNCTION 7
    0x16,0x3b, // STORE_NAME 'delete'
    0x10,0x04, // LOAD_CONST_STRING '0.10.2'
    0x16,0x45, // STORE_NAME '__version__'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
// child of requests___init____lt_module_gt_
// frozen bytecode for file requests/__init__.py, scope requests___init___Response
static const byte fun_data_requests___init___Response[51] = {
    0x08,0x16, // prelude
    0x03, // names: Response
    0x68,0x20,0x64,0x40,0x64,0x60,0x88,0x0a,0x68,0x20, // code info
    0x11,0x46, // LOAD_NAME '__name__'
    0x16,0x47, // STORE_NAME '__module__'
    0x10,0x03, // LOAD_CONST_STRING 'Response'
    0x16,0x48, // STORE_NAME '__qualname__'
    0x32,0x00, // MAKE_FUNCTION 0
    0x16,0x3d, // STORE_NAME '__init__'
    0x32,0x01, // MAKE_FUNCTION 1
    0x16,0x26, // STORE_NAME 'close'
    0x11,0x49, // LOAD_NAME 'property'
    0x32,0x02, // MAKE_FUNCTION 2
    0x34,0x01, // CALL_FUNCTION 1
    0x16,0x41, // STORE_NAME 'content'
    0x11,0x49, // LOAD_NAME 'property'
    0x32,0x03, // MAKE_FUNCTION 3
    0x34,0x01, // CALL_FUNCTION 1
    0x16,0x43, // STORE_NAME 'text'
    0x32,0x04, // MAKE_FUNCTION 4
    0x16,0x23, // STORE_NAME 'json'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
// child of requests___init___Response
// frozen bytecode for file requests/__init__.py, scope requests___init___Response___init__
static const byte fun_data_requests___init___Response___init__[24] = {
    0x1a,0x0e, // prelude
    0x3d,0x58,0x59, // names: __init__, self, f
    0x60,0x40,0x24,0x25, // code info
    0xb1, // LOAD_FAST 1
    0xb0, // LOAD_FAST 0
    0x18,0x3e, // STORE_ATTR 'raw'
    0x10,0x2c, // LOAD_CONST_STRING 'utf-8'
    0xb0, // LOAD_FAST 0
    0x18,0x3f, // STORE_ATTR 'encoding'
    0x51, // LOAD_CONST_NONE
    0xb0, // LOAD_FAST 0
    0x18,0x40, // STORE_ATTR '_cached'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_requests___init___Response___init__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_requests___init___Response___init__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 24,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 61,
        .line_info = fun_data_requests___init___Response___init__ + 5,
        .line_info_top = fun_data_requests___init___Response___init__ + 9,
        .opcodes = fun_data_requests___init___Response___init__ + 9,
    },
    #endif
    #endif
};
#else
#define proto_fun_requests___init___Response___init__ fun_data_requests___init___Response___init__[0]
#endif

// child of requests___init___Response
// frozen bytecode for file requests/__init__.py, scope requests___init___Response_close
static const byte fun_data_requests___init___Response_close[32] = {
    0x11,0x0e, // prelude
    0x26,0x58, // names: close, self
    0x80,0x0a,0x25,0x28,0x24, // code info
    0xb0, // LOAD_FAST 0
    0x13,0x3e, // LOAD_ATTR 'raw'
    0x44,0x4c, // POP_JUMP_IF_FALSE 12
    0xb0, // LOAD_FAST 0
    0x13,0x3e, // LOAD_ATTR 'raw'
    0x14,0x26, // LOAD_METHOD 'close'
    0x36,0x00, // CALL_METHOD 0
    0x59, // POP_TOP
    0x51, // LOAD_CONST_NONE
    0xb0, // LOAD_FAST 0
    0x18,0x3e, // STORE_ATTR 'raw'
    0x51, // LOAD_CONST_NONE
    0xb0, // LOAD_FAST 0
    0x18,0x40, // STORE_ATTR '_cached'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_requests___init___Response_close = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_requests___init___Response_close,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 32,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 38,
        .line_info = fun_data_requests___init___Response_close + 4,
        .line_info_top = fun_data_requests___init___Response_close + 9,
        .opcodes = fun_data_requests___init___Response_close + 9,
    },
    #endif
    #endif
};
#else
#define proto_fun_requests___init___Response_close fun_data_requests___init___Response_close[0]
#endif

// child of requests___init___Response
// frozen bytecode for file requests/__init__.py, scope requests___init___Response_content
static const byte fun_data_requests___init___Response_content[48] = {
    0x2d,0x12, // prelude
    0x41,0x58, // names: content, self
    0x80,0x11,0x27,0x22,0x4b,0x28,0x25, // code info
    0xb0, // LOAD_FAST 0
    0x13,0x40, // LOAD_ATTR '_cached'
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0x44,0x5a, // POP_JUMP_IF_FALSE 26
    0x49,0x0b, // SETUP_FINALLY 11
    0xb0, // LOAD_FAST 0
    0x13,0x3e, // LOAD_ATTR 'raw'
    0x14,0x42, // LOAD_METHOD 'read'
    0x36,0x00, // CALL_METHOD 0
    0xb0, // LOAD_FAST 0
    0x18,0x40, // STORE_ATTR '_cached'
    0x51, // LOAD_CONST_NONE
    0xb0, // LOAD_FAST 0
    0x13,0x3e, // LOAD_ATTR 'raw'
    0x14,0x26, // LOAD_METHOD 'close'
    0x36,0x00, // CALL_METHOD 0
    0x59, // POP_TOP
    0x51, // LOAD_CONST_NONE
    0xb0, // LOAD_FAST 0
    0x18,0x3e, // STORE_ATTR 'raw'
    0x5d, // END_FINALLY
    0xb0, // LOAD_FAST 0
    0x13,0x40, // LOAD_ATTR '_cached'
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_requests___init___Response_content = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_requests___init___Response_content,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 48,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 6,
        .n_exc_stack = 1,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 65,
        .line_info = fun_data_requests___init___Response_content + 4,
        .line_info_top = fun_data_requests___init___Response_content + 11,
        .opcodes = fun_data_requests___init___Response_content + 11,
    },
    #endif
    #endif
};
#else
#define proto_fun_requests___init___Response_content fun_data_requests___init___Response_content[0]
#endif

// child of requests___init___Response
// frozen bytecode for file requests/__init__.py, scope requests___init___Response_text
static const byte fun_data_requests___init___Response_text[17] = {
    0x19,0x08, // prelude
    0x43,0x58, // names: text, self
    0x80,0x1b, // code info
    0x12,0x52, // LOAD_GLOBAL 'str'
    0xb0, // LOAD_FAST 0
    0x13,0x41, // LOAD_ATTR 'content'
    0xb0, // LOAD_FAST 0
    0x13,0x3f, // LOAD_ATTR 'encoding'
    0x34,0x02, // CALL_FUNCTION 2
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_requests___init___Response_text = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_requests___init___Response_text,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 17,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 67,
        .line_info = fun_data_requests___init___Response_text + 4,
        .line_info_top = fun_data_requests___init___Response_text + 6,
        .opcodes = fun_data_requests___init___Response_text + 6,
    },
    #endif
    #endif
};
#else
#define proto_fun_requests___init___Response_text fun_data_requests___init___Response_text[0]
#endif

// child of requests___init___Response
// frozen bytecode for file requests/__init__.py, scope requests___init___Response_json
static const byte fun_data_requests___init___Response_json[21] = {
    0x21,0x0a, // prelude
    0x23,0x58, // names: json, self
    0x80,0x1e,0x45, // code info
    0x80, // LOAD_CONST_SMALL_INT 0
    0x51, // LOAD_CONST_NONE
    0x1b,0x23, // IMPORT_NAME 'json'
    0xc1, // STORE_FAST 1
    0xb1, // LOAD_FAST 1
    0x14,0x44, // LOAD_METHOD 'loads'
    0xb0, // LOAD_FAST 0
    0x13,0x41, // LOAD_ATTR 'content'
    0x36,0x01, // CALL_METHOD 1
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_requests___init___Response_json = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_requests___init___Response_json,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 21,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 35,
        .line_info = fun_data_requests___init___Response_json + 4,
        .line_info_top = fun_data_requests___init___Response_json + 7,
        .opcodes = fun_data_requests___init___Response_json + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_requests___init___Response_json fun_data_requests___init___Response_json[0]
#endif

static const mp_raw_code_t *const children_requests___init___Response[] = {
    (const mp_raw_code_t *)&proto_fun_requests___init___Response___init__,
    (const mp_raw_code_t *)&proto_fun_requests___init___Response_close,
    (const mp_raw_code_t *)&proto_fun_requests___init___Response_content,
    (const mp_raw_code_t *)&proto_fun_requests___init___Response_text,
    (const mp_raw_code_t *)&proto_fun_requests___init___Response_json,
};

static const mp_raw_code_truncated_t proto_fun_requests___init___Response = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_requests___init___Response,
    .children = (void *)&children_requests___init___Response,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 51,
    .n_children = 5,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 2,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 3,
        .line_info = fun_data_requests___init___Response + 3,
        .line_info_top = fun_data_requests___init___Response + 13,
        .opcodes = fun_data_requests___init___Response + 13,
    },
    #endif
    #endif
};

// child of requests___init____lt_module_gt_
// frozen bytecode for file requests/__init__.py, scope requests___init___request
static const byte fun_data_requests___init___request[1150] = {
    0xcd,0xa1,0x85,0x01,0xf6,0x02, // prelude
    0x05,0x4a,0x4b,0x4c,0x23,0x32,0x4d,0x4e,0x4f,0x50, // names: request, method, url, data, json, headers, stream, auth, timeout, parse_headers
    0x80,0x2e,0x25,0x45,0x46,0x22,0x57,0x26,0x45,0x25,0x29,0x32,0x4b,0x22,0x5a,0x2f,0x27,0x26,0x27,0x26,0x46,0x47,0x49,0x27,0x2f,0x48,0x31,0x46,0x23,0x26,0x44,0x54,0x66,0x48,0x23,0x2b,0x26,0x2c,0x28,0x2f,0x4f,0x27,0x46,0x26,0x28,0x4c,0x46,0x27,0x46,0x23,0x23,0x2e,0x28,0x27,0x4f,0x27,0x66,0x26,0x29,0x29,0x2b,0x4b,0x49,0x24,0x24,0x2d,0x26,0x30,0x29,0x2b,0x4b,0x26,0x4d,0x48,0x48,0x2a,0x4a,0x2a,0x2a,0x24,0x2a,0x2a,0x20,0x28,0x2b,0x43,0x2a,0x27,0x33,0x3f,0x36,0x50,0x2c,0x25,0x22,0x25,0x2a,0x2f,0x4d,0x54,0x27,0x42,0x23,0x47,0x29,0x30,0x4c,0x4d,0x28,0x26,0x26,0x27,0x26, // code info
    0xb4, // LOAD_FAST 4
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0x44,0x45, // POP_JUMP_IF_FALSE 5
    0x2c,0x00, // BUILD_MAP 0
    0xc4, // STORE_FAST 4
    0x42,0x46, // JUMP 6
    0xb4, // LOAD_FAST 4
    0x14,0x06, // LOAD_METHOD 'copy'
    0x36,0x00, // CALL_METHOD 0
    0xc4, // STORE_FAST 4
    0x51, // LOAD_CONST_NONE
    0xc9, // STORE_FAST 9
    0xb2, // LOAD_FAST 2
    0x46,0x13, // JUMP_IF_FALSE_OR_POP 19
    0x12,0x51, // LOAD_GLOBAL 'getattr'
    0xb2, // LOAD_FAST 2
    0x10,0x07, // LOAD_CONST_STRING '__next__'
    0x51, // LOAD_CONST_NONE
    0x34,0x03, // CALL_FUNCTION 3
    0x46,0x09, // JUMP_IF_FALSE_OR_POP 9
    0x12,0x51, // LOAD_GLOBAL 'getattr'
    0xb2, // LOAD_FAST 2
    0x10,0x08, // LOAD_CONST_STRING '__len__'
    0x51, // LOAD_CONST_NONE
    0x34,0x03, // CALL_FUNCTION 3
    0xd3, // UNARY_OP 3 <not>
    0xca, // STORE_FAST 10
    0xb6, // LOAD_FAST 6
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0xd3, // UNARY_OP 3 <not>
    0x44,0x70, // POP_JUMP_IF_FALSE 48
    0x80, // LOAD_CONST_SMALL_INT 0
    0x51, // LOAD_CONST_NONE
    0x1b,0x09, // IMPORT_NAME 'binascii'
    0xcb, // STORE_FAST 11
    0xb6, // LOAD_FAST 6
    0x30,0x02, // UNPACK_SEQUENCE 2
    0xcc, // STORE_FAST 12
    0xcd, // STORE_FAST 13
    0x23,0x00, // LOAD_CONST_OBJ 0
    0x14,0x0a, // LOAD_METHOD 'format'
    0xbc, // LOAD_FAST 12
    0xbd, // LOAD_FAST 13
    0x36,0x02, // CALL_METHOD 2
    0xce, // STORE_FAST 14
    0x12,0x52, // LOAD_GLOBAL 'str'
    0xbb, // LOAD_FAST 11
    0x14,0x0b, // LOAD_METHOD 'b2a_base64'
    0xbe, // LOAD_FAST 14
    0x36,0x01, // CALL_METHOD 1
    0x51, // LOAD_CONST_NONE
    0x7f, // LOAD_CONST_SMALL_INT -1
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0x10,0x0c, // LOAD_CONST_STRING 'ascii'
    0x34,0x02, // CALL_FUNCTION 2
    0xce, // STORE_FAST 14
    0x10,0x0d, // LOAD_CONST_STRING 'Basic {}'
    0x14,0x0a, // LOAD_METHOD 'format'
    0xbe, // LOAD_FAST 14
    0x36,0x01, // CALL_METHOD 1
    0xb4, // LOAD_FAST 4
    0x23,0x01, // LOAD_CONST_OBJ 1
    0x56, // STORE_SUBSCR
    0x48,0x13, // SETUP_EXCEPT 19
    0xb1, // LOAD_FAST 1
    0x14,0x0e, // LOAD_METHOD 'split'
    0x10,0x0f, // LOAD_CONST_STRING '/'
    0x83, // LOAD_CONST_SMALL_INT 3
    0x36,0x02, // CALL_METHOD 2
    0x30,0x04, // UNPACK_SEQUENCE 4
    0xcf, // STORE_FAST 15
    0x26,0x10, // STORE_FAST_N 16
    0x26,0x11, // STORE_FAST_N 17
    0x26,0x12, // STORE_FAST_N 18
    0x4a,0x1d, // POP_EXCEPT_JUMP 29
    0x57, // DUP_TOP
    0x12,0x53, // LOAD_GLOBAL 'ValueError'
    0xdf, // BINARY_OP 8 <exception match>
    0x44,0x56, // POP_JUMP_IF_FALSE 22
    0x59, // POP_TOP
    0xb1, // LOAD_FAST 1
    0x14,0x0e, // LOAD_METHOD 'split'
    0x10,0x0f, // LOAD_CONST_STRING '/'
    0x82, // LOAD_CONST_SMALL_INT 2
    0x36,0x02, // CALL_METHOD 2
    0x30,0x03, // UNPACK_SEQUENCE 3
    0xcf, // STORE_FAST 15
    0x26,0x10, // STORE_FAST_N 16
    0x26,0x11, // STORE_FAST_N 17
    0x10,0x10, // LOAD_CONST_STRING ''
    0x26,0x12, // STORE_FAST_N 18
    0x4a,0x01, // POP_EXCEPT_JUMP 1
    0x5d, // END_FINALLY
    0xbf, // LOAD_FAST 15
    0x10,0x11, // LOAD_CONST_STRING 'http:'
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x47, // POP_JUMP_IF_FALSE 7
    0x22,0x80,0x50, // LOAD_CONST_SMALL_INT 80
    0x26,0x13, // STORE_FAST_N 19
    0x42,0x5c, // JUMP 28
    0xbf, // LOAD_FAST 15
    0x10,0x12, // LOAD_CONST_STRING 'https:'
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x4d, // POP_JUMP_IF_FALSE 13
    0x80, // LOAD_CONST_SMALL_INT 0
    0x51, // LOAD_CONST_NONE
    0x1b,0x13, // IMPORT_NAME 'tls'
    0x26,0x14, // STORE_FAST_N 20
    0x22,0x83,0x3b, // LOAD_CONST_SMALL_INT 443
    0x26,0x13, // STORE_FAST_N 19
    0x42,0x49, // JUMP 9
    0x12,0x53, // LOAD_GLOBAL 'ValueError'
    0x23,0x02, // LOAD_CONST_OBJ 2
    0xbf, // LOAD_FAST 15
    0xf2, // BINARY_OP 27 __add__
    0x34,0x01, // CALL_FUNCTION 1
    0x65, // RAISE_OBJ
    0x10,0x14, // LOAD_CONST_STRING ':'
    0x24,0x11, // LOAD_FAST_N 17
    0xdd, // BINARY_OP 6 <in>
    0x44,0x57, // POP_JUMP_IF_FALSE 23
    0x24,0x11, // LOAD_FAST_N 17
    0x14,0x0e, // LOAD_METHOD 'split'
    0x10,0x14, // LOAD_CONST_STRING ':'
    0x81, // LOAD_CONST_SMALL_INT 1
    0x36,0x02, // CALL_METHOD 2
    0x30,0x02, // UNPACK_SEQUENCE 2
    0x26,0x11, // STORE_FAST_N 17
    0x26,0x13, // STORE_FAST_N 19
    0x12,0x54, // LOAD_GLOBAL 'int'
    0x24,0x13, // LOAD_FAST_N 19
    0x34,0x01, // CALL_FUNCTION 1
    0x26,0x13, // STORE_FAST_N 19
    0x12,0x02, // LOAD_GLOBAL 'socket'
    0x14,0x15, // LOAD_METHOD 'getaddrinfo'
    0x24,0x11, // LOAD_FAST_N 17
    0x24,0x13, // LOAD_FAST_N 19
    0x80, // LOAD_CONST_SMALL_INT 0
    0x12,0x02, // LOAD_GLOBAL 'socket'
    0x13,0x16, // LOAD_ATTR 'SOCK_STREAM'
    0x36,0x04, // CALL_METHOD 4
    0x26,0x15, // STORE_FAST_N 21
    0x24,0x15, // LOAD_FAST_N 21
    0x80, // LOAD_CONST_SMALL_INT 0
    0x55, // LOAD_SUBSCR
    0x26,0x15, // STORE_FAST_N 21
    0x51, // LOAD_CONST_NONE
    0x26,0x16, // STORE_FAST_N 22
    0xb8, // LOAD_FAST 8
    0x50, // LOAD_CONST_FALSE
    0xde, // BINARY_OP 7 <is>
    0xd3, // UNARY_OP 3 <not>
    0x44,0x44, // POP_JUMP_IF_FALSE 4
    0x2c,0x00, // BUILD_MAP 0
    0x26,0x16, // STORE_FAST_N 22
    0x12,0x02, // LOAD_GLOBAL 'socket'
    0x14,0x02, // LOAD_METHOD 'socket'
    0x24,0x15, // LOAD_FAST_N 21
    0x80, // LOAD_CONST_SMALL_INT 0
    0x55, // LOAD_SUBSCR
    0x12,0x02, // LOAD_GLOBAL 'socket'
    0x13,0x16, // LOAD_ATTR 'SOCK_STREAM'
    0x24,0x15, // LOAD_FAST_N 21
    0x82, // LOAD_CONST_SMALL_INT 2
    0x55, // LOAD_SUBSCR
    0x36,0x03, // CALL_METHOD 3
    0x26,0x17, // STORE_FAST_N 23
    0xb7, // LOAD_FAST 7
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0xd3, // UNARY_OP 3 <not>
    0x44,0x48, // POP_JUMP_IF_FALSE 8
    0x24,0x17, // LOAD_FAST_N 23
    0x14,0x17, // LOAD_METHOD 'settimeout'
    0xb7, // LOAD_FAST 7
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x48,0xea,0x04, // SETUP_EXCEPT 618
    0x24,0x17, // LOAD_FAST_N 23
    0x14,0x18, // LOAD_METHOD 'connect'
    0x24,0x15, // LOAD_FAST_N 21
    0x7f, // LOAD_CONST_SMALL_INT -1
    0x55, // LOAD_SUBSCR
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0xbf, // LOAD_FAST 15
    0x10,0x12, // LOAD_CONST_STRING 'https:'
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x63, // POP_JUMP_IF_FALSE 35
    0x24,0x14, // LOAD_FAST_N 20
    0x14,0x19, // LOAD_METHOD 'SSLContext'
    0x24,0x14, // LOAD_FAST_N 20
    0x13,0x1a, // LOAD_ATTR 'PROTOCOL_TLS_CLIENT'
    0x36,0x01, // CALL_METHOD 1
    0x26,0x18, // STORE_FAST_N 24
    0x24,0x14, // LOAD_FAST_N 20
    0x13,0x1b, // LOAD_ATTR 'CERT_NONE'
    0x24,0x18, // LOAD_FAST_N 24
    0x18,0x1c, // STORE_ATTR 'verify_mode'
    0x24,0x18, // LOAD_FAST_N 24
    0x14,0x1d, // LOAD_METHOD 'wrap_socket'
    0x24,0x17, // LOAD_FAST_N 23
    0x10,0x1e, // LOAD_CONST_STRING 'server_hostname'
    0x24,0x11, // LOAD_FAST_N 17
    0x36,0x82,0x01, // CALL_METHOD 257
    0x26,0x17, // STORE_FAST_N 23
    0x24,0x17, // LOAD_FAST_N 23
    0x14,0x1f, // LOAD_METHOD 'write'
    0x23,0x03, // LOAD_CONST_OBJ 3
    0xb0, // LOAD_FAST 0
    0x24,0x12, // LOAD_FAST_N 18
    0x2a,0x02, // BUILD_TUPLE 2
    0xf8, // BINARY_OP 33 __mod__
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x10,0x20, // LOAD_CONST_STRING 'Host'
    0xb4, // LOAD_FAST 4
    0xdd, // BINARY_OP 6 <in>
    0xd3, // UNARY_OP 3 <not>
    0x44,0x46, // POP_JUMP_IF_FALSE 6
    0x24,0x11, // LOAD_FAST_N 17
    0xb4, // LOAD_FAST 4
    0x10,0x20, // LOAD_CONST_STRING 'Host'
    0x56, // STORE_SUBSCR
    0xb3, // LOAD_FAST 3
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0xd3, // UNARY_OP 3 <not>
    0x44,0x67, // POP_JUMP_IF_FALSE 39
    0xb2, // LOAD_FAST 2
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0x43,0x43, // POP_JUMP_IF_TRUE 3
    0x12,0x21, // LOAD_GLOBAL 'AssertionError'
    0x65, // RAISE_OBJ
    0x80, // LOAD_CONST_SMALL_INT 0
    0x10,0x22, // LOAD_CONST_STRING 'dumps'
    0x2a,0x01, // BUILD_TUPLE 1
    0x1b,0x23, // IMPORT_NAME 'json'
    0x1c,0x22, // IMPORT_FROM 'dumps'
    0x26,0x19, // STORE_FAST_N 25
    0x59, // POP_TOP
    0x24,0x19, // LOAD_FAST_N 25
    0xb3, // LOAD_FAST 3
    0x34,0x01, // CALL_FUNCTION 1
    0xc2, // STORE_FAST 2
    0x23,0x04, // LOAD_CONST_OBJ 4
    0xb4, // LOAD_FAST 4
    0xdd, // BINARY_OP 6 <in>
    0xd3, // UNARY_OP 3 <not>
    0x44,0x46, // POP_JUMP_IF_FALSE 6
    0x23,0x05, // LOAD_CONST_OBJ 5
    0xb4, // LOAD_FAST 4
    0x23,0x04, // LOAD_CONST_OBJ 4
    0x56, // STORE_SUBSCR
    0xb2, // LOAD_FAST 2
    0x44,0x6f, // POP_JUMP_IF_FALSE 47
    0xba, // LOAD_FAST 10
    0x44,0x56, // POP_JUMP_IF_FALSE 22
    0x23,0x06, // LOAD_CONST_OBJ 6
    0xb4, // LOAD_FAST 4
    0xdd, // BINARY_OP 6 <in>
    0xd3, // UNARY_OP 3 <not>
    0x44,0x4d, // POP_JUMP_IF_FALSE 13
    0x23,0x07, // LOAD_CONST_OBJ 7
    0xb4, // LOAD_FAST 4
    0xdd, // BINARY_OP 6 <in>
    0xd3, // UNARY_OP 3 <not>
    0x44,0x46, // POP_JUMP_IF_FALSE 6
    0x10,0x24, // LOAD_CONST_STRING 'chunked'
    0xb4, // LOAD_FAST 4
    0x23,0x06, // LOAD_CONST_OBJ 6
    0x56, // STORE_SUBSCR
    0x42,0x56, // JUMP 22
    0x23,0x07, // LOAD_CONST_OBJ 7
    0xb4, // LOAD_FAST 4
    0xdd, // BINARY_OP 6 <in>
    0xd3, // UNARY_OP 3 <not>
    0x44,0x4f, // POP_JUMP_IF_FALSE 15
    0x12,0x52, // LOAD_GLOBAL 'str'
    0x12,0x55, // LOAD_GLOBAL 'len'
    0xb2, // LOAD_FAST 2
    0x34,0x01, // CALL_FUNCTION 1
    0x34,0x01, // CALL_FUNCTION 1
    0xb4, // LOAD_FAST 4
    0x23,0x07, // LOAD_CONST_OBJ 7
    0x56, // STORE_SUBSCR
    0x42,0x40, // JUMP 0
    0x10,0x25, // LOAD_CONST_STRING 'Connection'
    0xb4, // LOAD_FAST 4
    0xdd, // BINARY_OP 6 <in>
    0xd3, // UNARY_OP 3 <not>
    0x44,0x46, // POP_JUMP_IF_FALSE 6
    0x10,0x26, // LOAD_CONST_STRING 'close'
    0xb4, // LOAD_FAST 4
    0x10,0x25, // LOAD_CONST_STRING 'Connection'
    0x56, // STORE_SUBSCR
    0xb4, // LOAD_FAST 4
    0x5f, // GET_ITER_STACK
    0x4b,0x2a, // FOR_ITER 42
    0x26,0x1a, // STORE_FAST_N 26
    0x24,0x17, // LOAD_FAST_N 23
    0x14,0x1f, // LOAD_METHOD 'write'
    0x24,0x1a, // LOAD_FAST_N 26
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x24,0x17, // LOAD_FAST_N 23
    0x14,0x1f, // LOAD_METHOD 'write'
    0x23,0x08, // LOAD_CONST_OBJ 8
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x24,0x17, // LOAD_FAST_N 23
    0x14,0x1f, // LOAD_METHOD 'write'
    0xb4, // LOAD_FAST 4
    0x24,0x1a, // LOAD_FAST_N 26
    0x55, // LOAD_SUBSCR
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x24,0x17, // LOAD_FAST_N 23
    0x14,0x1f, // LOAD_METHOD 'write'
    0x23,0x09, // LOAD_CONST_OBJ 9
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x42,0x14, // JUMP -44
    0x24,0x17, // LOAD_FAST_N 23
    0x14,0x1f, // LOAD_METHOD 'write'
    0x23,0x09, // LOAD_CONST_OBJ 9
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0xb2, // LOAD_FAST 2
    0x44,0xe1,0x80, // POP_JUMP_IF_FALSE 97
    0xba, // LOAD_FAST 10
    0x44,0xd5,0x80, // POP_JUMP_IF_FALSE 85
    0xb4, // LOAD_FAST 4
    0x14,0x27, // LOAD_METHOD 'get'
    0x23,0x06, // LOAD_CONST_OBJ 6
    0x51, // LOAD_CONST_NONE
    0x36,0x02, // CALL_METHOD 2
    0x10,0x24, // LOAD_CONST_STRING 'chunked'
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x75, // POP_JUMP_IF_FALSE 53
    0xb2, // LOAD_FAST 2
    0x5f, // GET_ITER_STACK
    0x4b,0x26, // FOR_ITER 38
    0x26,0x1b, // STORE_FAST_N 27
    0x24,0x17, // LOAD_FAST_N 23
    0x14,0x1f, // LOAD_METHOD 'write'
    0x23,0x0a, // LOAD_CONST_OBJ 10
    0x12,0x55, // LOAD_GLOBAL 'len'
    0x24,0x1b, // LOAD_FAST_N 27
    0x34,0x01, // CALL_FUNCTION 1
    0xf8, // BINARY_OP 33 __mod__
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x24,0x17, // LOAD_FAST_N 23
    0x14,0x1f, // LOAD_METHOD 'write'
    0x24,0x1b, // LOAD_FAST_N 27
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x24,0x17, // LOAD_FAST_N 23
    0x14,0x1f, // LOAD_METHOD 'write'
    0x23,0x09, // LOAD_CONST_OBJ 9
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x42,0x18, // JUMP -40
    0x24,0x17, // LOAD_FAST_N 23
    0x14,0x1f, // LOAD_METHOD 'write'
    0x10,0x28, // LOAD_CONST_STRING '0\r\n\r\n'
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x42,0x51, // JUMP 17
    0xb2, // LOAD_FAST 2
    0x5f, // GET_ITER_STACK
    0x4b,0x0d, // FOR_ITER 13
    0x26,0x1b, // STORE_FAST_N 27
    0x24,0x17, // LOAD_FAST_N 23
    0x14,0x1f, // LOAD_METHOD 'write'
    0x24,0x1b, // LOAD_FAST_N 27
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x42,0x31, // JUMP -15
    0x42,0x48, // JUMP 8
    0x24,0x17, // LOAD_FAST_N 23
    0x14,0x1f, // LOAD_METHOD 'write'
    0xb2, // LOAD_FAST 2
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x24,0x17, // LOAD_FAST_N 23
    0x14,0x29, // LOAD_METHOD 'readline'
    0x36,0x00, // CALL_METHOD 0
    0x26,0x1c, // STORE_FAST_N 28
    0x24,0x1c, // LOAD_FAST_N 28
    0x14,0x0e, // LOAD_METHOD 'split'
    0x51, // LOAD_CONST_NONE
    0x82, // LOAD_CONST_SMALL_INT 2
    0x36,0x02, // CALL_METHOD 2
    0x26,0x1c, // STORE_FAST_N 28
    0x12,0x55, // LOAD_GLOBAL 'len'
    0x24,0x1c, // LOAD_FAST_N 28
    0x34,0x01, // CALL_FUNCTION 1
    0x82, // LOAD_CONST_SMALL_INT 2
    0xd7, // BINARY_OP 0 __lt__
    0x44,0x4a, // POP_JUMP_IF_FALSE 10
    0x12,0x53, // LOAD_GLOBAL 'ValueError'
    0x23,0x0b, // LOAD_CONST_OBJ 11
    0x24,0x1c, // LOAD_FAST_N 28
    0xf8, // BINARY_OP 33 __mod__
    0x34,0x01, // CALL_FUNCTION 1
    0x65, // RAISE_OBJ
    0x12,0x54, // LOAD_GLOBAL 'int'
    0x24,0x1c, // LOAD_FAST_N 28
    0x81, // LOAD_CONST_SMALL_INT 1
    0x55, // LOAD_SUBSCR
    0x34,0x01, // CALL_FUNCTION 1
    0x26,0x1d, // STORE_FAST_N 29
    0x10,0x10, // LOAD_CONST_STRING ''
    0x26,0x1e, // STORE_FAST_N 30
    0x12,0x55, // LOAD_GLOBAL 'len'
    0x24,0x1c, // LOAD_FAST_N 28
    0x34,0x01, // CALL_FUNCTION 1
    0x82, // LOAD_CONST_SMALL_INT 2
    0xd8, // BINARY_OP 1 __gt__
    0x44,0x4a, // POP_JUMP_IF_FALSE 10
    0x24,0x1c, // LOAD_FAST_N 28
    0x82, // LOAD_CONST_SMALL_INT 2
    0x55, // LOAD_SUBSCR
    0x14,0x2a, // LOAD_METHOD 'rstrip'
    0x36,0x00, // CALL_METHOD 0
    0x26,0x1e, // STORE_FAST_N 30
    0x24,0x17, // LOAD_FAST_N 23
    0x14,0x29, // LOAD_METHOD 'readline'
    0x36,0x00, // CALL_METHOD 0
    0x26,0x1c, // STORE_FAST_N 28
    0x24,0x1c, // LOAD_FAST_N 28
    0x44,0x47, // POP_JUMP_IF_FALSE 7
    0x24,0x1c, // LOAD_FAST_N 28
    0x23,0x09, // LOAD_CONST_OBJ 9
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x43, // POP_JUMP_IF_FALSE 3
    0x42,0xb2,0x81, // JUMP 178
    0x24,0x1c, // LOAD_FAST_N 28
    0x14,0x2b, // LOAD_METHOD 'startswith'
    0x23,0x0c, // LOAD_CONST_OBJ 12
    0x36,0x01, // CALL_METHOD 1
    0x44,0x5a, // POP_JUMP_IF_FALSE 26
    0x23,0x0d, // LOAD_CONST_OBJ 13
    0x24,0x1c, // LOAD_FAST_N 28
    0xdd, // BINARY_OP 6 <in>
    0x44,0x50, // POP_JUMP_IF_FALSE 16
    0x12,0x53, // LOAD_GLOBAL 'ValueError'
    0x23,0x0e, // LOAD_CONST_OBJ 14
    0x12,0x52, // LOAD_GLOBAL 'str'
    0x24,0x1c, // LOAD_FAST_N 28
    0x10,0x2c, // LOAD_CONST_STRING 'utf-8'
    0x34,0x02, // CALL_FUNCTION 2
    0xf2, // BINARY_OP 27 __add__
    0x34,0x01, // CALL_FUNCTION 1
    0x65, // RAISE_OBJ
    0x42,0xd1,0x80, // JUMP 81
    0x24,0x1c, // LOAD_FAST_N 28
    0x14,0x2b, // LOAD_METHOD 'startswith'
    0x23,0x0f, // LOAD_CONST_OBJ 15
    0x36,0x01, // CALL_METHOD 1
    0x44,0xc6,0x80, // POP_JUMP_IF_FALSE 70
    0x22,0x81,0x48, // LOAD_CONST_SMALL_INT 200
    0x24,0x1d, // LOAD_FAST_N 29
    0x57, // DUP_TOP
    0x5b, // ROT_THREE
    0xda, // BINARY_OP 3 __le__
    0x46,0x06, // JUMP_IF_FALSE_OR_POP 6
    0x22,0x82,0x2b, // LOAD_CONST_SMALL_INT 299
    0xda, // BINARY_OP 3 __le__
    0x42,0x42, // JUMP 2
    0x5a, // ROT_TWO
    0x59, // POP_TOP
    0x43,0x72, // POP_JUMP_IF_TRUE 50
    0x24,0x1d, // LOAD_FAST_N 29
    0x22,0x82,0x2d, // LOAD_CONST_SMALL_INT 301
    0x22,0x82,0x2e, // LOAD_CONST_SMALL_INT 302
    0x22,0x82,0x2f, // LOAD_CONST_SMALL_INT 303
    0x22,0x82,0x33, // LOAD_CONST_SMALL_INT 307
    0x22,0x82,0x34, // LOAD_CONST_SMALL_INT 308
    0x2b,0x05, // BUILD_LIST 5
    0xdd, // BINARY_OP 6 <in>
    0x44,0x50, // POP_JUMP_IF_FALSE 16
    0x12,0x52, // LOAD_GLOBAL 'str'
    0x24,0x1c, // LOAD_FAST_N 28
    0x8a, // LOAD_CONST_SMALL_INT 10
    0x7e, // LOAD_CONST_SMALL_INT -2
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0x10,0x2c, // LOAD_CONST_STRING 'utf-8'
    0x34,0x02, // CALL_FUNCTION 2
    0xc9, // STORE_FAST 9
    0x42,0x4a, // JUMP 10
    0x12,0x56, // LOAD_GLOBAL 'NotImplementedError'
    0x23,0x10, // LOAD_CONST_OBJ 16
    0x24,0x1d, // LOAD_FAST_N 29
    0xf8, // BINARY_OP 33 __mod__
    0x34,0x01, // CALL_FUNCTION 1
    0x65, // RAISE_OBJ
    0x42,0x40, // JUMP 0
    0xb8, // LOAD_FAST 8
    0x50, // LOAD_CONST_FALSE
    0xde, // BINARY_OP 7 <is>
    0x44,0x42, // POP_JUMP_IF_FALSE 2
    0x42,0x73, // JUMP 51
    0xb8, // LOAD_FAST 8
    0x52, // LOAD_CONST_TRUE
    0xde, // BINARY_OP 7 <is>
    0x44,0x66, // POP_JUMP_IF_FALSE 38
    0x12,0x52, // LOAD_GLOBAL 'str'
    0x24,0x1c, // LOAD_FAST_N 28
    0x10,0x2c, // LOAD_CONST_STRING 'utf-8'
    0x34,0x02, // CALL_FUNCTION 2
    0x26,0x1c, // STORE_FAST_N 28
    0x24,0x1c, // LOAD_FAST_N 28
    0x14,0x0e, // LOAD_METHOD 'split'
    0x10,0x14, // LOAD_CONST_STRING ':'
    0x81, // LOAD_CONST_SMALL_INT 1
    0x36,0x02, // CALL_METHOD 2
    0x30,0x02, // UNPACK_SEQUENCE 2
    0x26,0x1a, // STORE_FAST_N 26
    0x26,0x1f, // STORE_FAST_N 31
    0x24,0x1f, // LOAD_FAST_N 31
    0x14,0x2d, // LOAD_METHOD 'strip'
    0x36,0x00, // CALL_METHOD 0
    0x24,0x16, // LOAD_FAST_N 22
    0x24,0x1a, // LOAD_FAST_N 26
    0x56, // STORE_SUBSCR
    0x42,0x48, // JUMP 8
    0xb8, // LOAD_FAST 8
    0x24,0x1c, // LOAD_FAST_N 28
    0x24,0x16, // LOAD_FAST_N 22
    0x34,0x02, // CALL_FUNCTION 2
    0x59, // POP_TOP
    0x42,0xb8,0x7e, // JUMP -200
    0x4a,0x10, // POP_EXCEPT_JUMP 16
    0x57, // DUP_TOP
    0x12,0x57, // LOAD_GLOBAL 'OSError'
    0xdf, // BINARY_OP 8 <exception match>
    0x44,0x49, // POP_JUMP_IF_FALSE 9
    0x59, // POP_TOP
    0x24,0x17, // LOAD_FAST_N 23
    0x14,0x26, // LOAD_METHOD 'close'
    0x36,0x00, // CALL_METHOD 0
    0x59, // POP_TOP
    0x64, // RAISE_LAST
    0x5d, // END_FINALLY
    0xb9, // LOAD_FAST 9
    0x44,0x79, // POP_JUMP_IF_FALSE 57
    0x24,0x17, // LOAD_FAST_N 23
    0x14,0x26, // LOAD_METHOD 'close'
    0x36,0x00, // CALL_METHOD 0
    0x59, // POP_TOP
    0xb4, // LOAD_FAST 4
    0x14,0x2e, // LOAD_METHOD 'pop'
    0x10,0x20, // LOAD_CONST_STRING 'Host'
    0x51, // LOAD_CONST_NONE
    0x36,0x02, // CALL_METHOD 2
    0x59, // POP_TOP
    0x24,0x1d, // LOAD_FAST_N 29
    0x22,0x82,0x2d, // LOAD_CONST_SMALL_INT 301
    0x22,0x82,0x2e, // LOAD_CONST_SMALL_INT 302
    0x22,0x82,0x2f, // LOAD_CONST_SMALL_INT 303
    0x2b,0x03, // BUILD_LIST 3
    0xdd, // BINARY_OP 6 <in>
    0x44,0x4c, // POP_JUMP_IF_FALSE 12
    0x12,0x05, // LOAD_GLOBAL 'request'
    0x10,0x2f, // LOAD_CONST_STRING 'GET'
    0xb9, // LOAD_FAST 9
    0x51, // LOAD_CONST_NONE
    0x51, // LOAD_CONST_NONE
    0xb4, // LOAD_FAST 4
    0xb5, // LOAD_FAST 5
    0x34,0x06, // CALL_FUNCTION 6
    0x63, // RETURN_VALUE
    0x12,0x05, // LOAD_GLOBAL 'request'
    0xb0, // LOAD_FAST 0
    0xb9, // LOAD_FAST 9
    0xb2, // LOAD_FAST 2
    0xb3, // LOAD_FAST 3
    0xb4, // LOAD_FAST 4
    0xb5, // LOAD_FAST 5
    0x34,0x06, // CALL_FUNCTION 6
    0x63, // RETURN_VALUE
    0x42,0x64, // JUMP 36
    0x12,0x03, // LOAD_GLOBAL 'Response'
    0x24,0x17, // LOAD_FAST_N 23
    0x34,0x01, // CALL_FUNCTION 1
    0x26,0x20, // STORE_FAST_N 32
    0x24,0x1d, // LOAD_FAST_N 29
    0x24,0x20, // LOAD_FAST_N 32
    0x18,0x30, // STORE_ATTR 'status_code'
    0x24,0x1e, // LOAD_FAST_N 30
    0x24,0x20, // LOAD_FAST_N 32
    0x18,0x31, // STORE_ATTR 'reason'
    0x24,0x16, // LOAD_FAST_N 22
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0xd3, // UNARY_OP 3 <not>
    0x44,0x46, // POP_JUMP_IF_FALSE 6
    0x24,0x16, // LOAD_FAST_N 22
    0x24,0x20, // LOAD_FAST_N 32
    0x18,0x32, // STORE_ATTR 'headers'
    0x24,0x20, // LOAD_FAST_N 32
    0x63, // RETURN_VALUE
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_requests___init___request = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_requests___init___request,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 1150,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 42,
        .n_exc_stack = 1,
        .scope_flags = 0,
        .n_pos_args = 9,
        .n_kwonly_args = 0,
        .n_def_pos_args = 7,
        .qstr_block_name_idx = 5,
        .line_info = fun_data_requests___init___request + 16,
        .line_info_top = fun_data_requests___init___request + 129,
        .opcodes = fun_data_requests___init___request + 129,
    },
    #endif
    #endif
};
#else
#define proto_fun_requests___init___request fun_data_requests___init___request[0]
#endif

// child of requests___init____lt_module_gt_
// frozen bytecode for file requests/__init__.py, scope requests___init___head
static const byte fun_data_requests___init___head[20] = {
    0xb9,0x80,0x40,0x08, // prelude
    0x33,0x4b, // names: head, url
    0x80,0xc8, // code info
    0x12,0x05, // LOAD_GLOBAL 'request'
    0x10,0x34, // LOAD_CONST_STRING 'HEAD'
    0xb0, // LOAD_FAST 0
    0x53, // LOAD_NULL
    0xb1, // LOAD_FAST 1
    0x80, // LOAD_CONST_SMALL_INT 0
    0x35,0x82,0x02, // CALL_FUNCTION_VAR_KW 258
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_requests___init___head = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_requests___init___head,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 20,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 8,
        .n_exc_stack = 0,
        .scope_flags = 2,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 51,
        .line_info = fun_data_requests___init___head + 6,
        .line_info_top = fun_data_requests___init___head + 8,
        .opcodes = fun_data_requests___init___head + 8,
    },
    #endif
    #endif
};
#else
#define proto_fun_requests___init___head fun_data_requests___init___head[0]
#endif

// child of requests___init____lt_module_gt_
// frozen bytecode for file requests/__init__.py, scope requests___init___get
static const byte fun_data_requests___init___get[20] = {
    0xb9,0x80,0x40,0x08, // prelude
    0x27,0x4b, // names: get, url
    0x80,0xcc, // code info
    0x12,0x05, // LOAD_GLOBAL 'request'
    0x10,0x2f, // LOAD_CONST_STRING 'GET'
    0xb0, // LOAD_FAST 0
    0x53, // LOAD_NULL
    0xb1, // LOAD_FAST 1
    0x80, // LOAD_CONST_SMALL_INT 0
    0x35,0x82,0x02, // CALL_FUNCTION_VAR_KW 258
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_requests___init___get = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_requests___init___get,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 20,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 8,
        .n_exc_stack = 0,
        .scope_flags = 2,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 39,
        .line_info = fun_data_requests___init___get + 6,
        .line_info_top = fun_data_requests___init___get + 8,
        .opcodes = fun_data_requests___init___get + 8,
    },
    #endif
    #endif
};
#else
#define proto_fun_requests___init___get fun_data_requests___init___get[0]
#endif

// child of requests___init____lt_module_gt_
// frozen bytecode for file requests/__init__.py, scope requests___init___post
static const byte fun_data_requests___init___post[20] = {
    0xb9,0x80,0x40,0x08, // prelude
    0x35,0x4b, // names: post, url
    0x80,0xd0, // code info
    0x12,0x05, // LOAD_GLOBAL 'request'
    0x10,0x36, // LOAD_CONST_STRING 'POST'
    0xb0, // LOAD_FAST 0
    0x53, // LOAD_NULL
    0xb1, // LOAD_FAST 1
    0x80, // LOAD_CONST_SMALL_INT 0
    0x35,0x82,0x02, // CALL_FUNCTION_VAR_KW 258
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_requests___init___post = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_requests___init___post,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 20,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 8,
        .n_exc_stack = 0,
        .scope_flags = 2,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 53,
        .line_info = fun_data_requests___init___post + 6,
        .line_info_top = fun_data_requests___init___post + 8,
        .opcodes = fun_data_requests___init___post + 8,
    },
    #endif
    #endif
};
#else
#define proto_fun_requests___init___post fun_data_requests___init___post[0]
#endif

// child of requests___init____lt_module_gt_
// frozen bytecode for file requests/__init__.py, scope requests___init___put
static const byte fun_data_requests___init___put[20] = {
    0xb9,0x80,0x40,0x08, // prelude
    0x37,0x4b, // names: put, url
    0x80,0xd4, // code info
    0x12,0x05, // LOAD_GLOBAL 'request'
    0x10,0x38, // LOAD_CONST_STRING 'PUT'
    0xb0, // LOAD_FAST 0
    0x53, // LOAD_NULL
    0xb1, // LOAD_FAST 1
    0x80, // LOAD_CONST_SMALL_INT 0
    0x35,0x82,0x02, // CALL_FUNCTION_VAR_KW 258
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_requests___init___put = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_requests___init___put,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 20,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 8,
        .n_exc_stack = 0,
        .scope_flags = 2,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 55,
        .line_info = fun_data_requests___init___put + 6,
        .line_info_top = fun_data_requests___init___put + 8,
        .opcodes = fun_data_requests___init___put + 8,
    },
    #endif
    #endif
};
#else
#define proto_fun_requests___init___put fun_data_requests___init___put[0]
#endif

// child of requests___init____lt_module_gt_
// frozen bytecode for file requests/__init__.py, scope requests___init___patch
static const byte fun_data_requests___init___patch[20] = {
    0xb9,0x80,0x40,0x08, // prelude
    0x39,0x4b, // names: patch, url
    0x80,0xd8, // code info
    0x12,0x05, // LOAD_GLOBAL 'request'
    0x10,0x3a, // LOAD_CONST_STRING 'PATCH'
    0xb0, // LOAD_FAST 0
    0x53, // LOAD_NULL
    0xb1, // LOAD_FAST 1
    0x80, // LOAD_CONST_SMALL_INT 0
    0x35,0x82,0x02, // CALL_FUNCTION_VAR_KW 258
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_requests___init___patch = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_requests___init___patch,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 20,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 8,
        .n_exc_stack = 0,
        .scope_flags = 2,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 57,
        .line_info = fun_data_requests___init___patch + 6,
        .line_info_top = fun_data_requests___init___patch + 8,
        .opcodes = fun_data_requests___init___patch + 8,
    },
    #endif
    #endif
};
#else
#define proto_fun_requests___init___patch fun_data_requests___init___patch[0]
#endif

// child of requests___init____lt_module_gt_
// frozen bytecode for file requests/__init__.py, scope requests___init___delete
static const byte fun_data_requests___init___delete[20] = {
    0xb9,0x80,0x40,0x08, // prelude
    0x3b,0x4b, // names: delete, url
    0x80,0xdc, // code info
    0x12,0x05, // LOAD_GLOBAL 'request'
    0x10,0x3c, // LOAD_CONST_STRING 'DELETE'
    0xb0, // LOAD_FAST 0
    0x53, // LOAD_NULL
    0xb1, // LOAD_FAST 1
    0x80, // LOAD_CONST_SMALL_INT 0
    0x35,0x82,0x02, // CALL_FUNCTION_VAR_KW 258
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_requests___init___delete = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_requests___init___delete,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 20,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 8,
        .n_exc_stack = 0,
        .scope_flags = 2,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 59,
        .line_info = fun_data_requests___init___delete + 6,
        .line_info_top = fun_data_requests___init___delete + 8,
        .opcodes = fun_data_requests___init___delete + 8,
    },
    #endif
    #endif
};
#else
#define proto_fun_requests___init___delete fun_data_requests___init___delete[0]
#endif

static const mp_raw_code_t *const children_requests___init____lt_module_gt_[] = {
    (const mp_raw_code_t *)&proto_fun_requests___init___Response,
    (const mp_raw_code_t *)&proto_fun_requests___init___request,
    (const mp_raw_code_t *)&proto_fun_requests___init___head,
    (const mp_raw_code_t *)&proto_fun_requests___init___get,
    (const mp_raw_code_t *)&proto_fun_requests___init___post,
    (const mp_raw_code_t *)&proto_fun_requests___init___put,
    (const mp_raw_code_t *)&proto_fun_requests___init___patch,
    (const mp_raw_code_t *)&proto_fun_requests___init___delete,
};

static const mp_raw_code_truncated_t proto_fun_requests___init____lt_module_gt_ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_requests___init____lt_module_gt_,
    .children = (void *)&children_requests___init____lt_module_gt_,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 79,
    .n_children = 8,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 7,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 1,
        .line_info = fun_data_requests___init____lt_module_gt_ + 3,
        .line_info_top = fun_data_requests___init____lt_module_gt_ + 20,
        .opcodes = fun_data_requests___init____lt_module_gt_ + 20,
    },
    #endif
    #endif
};

static const qstr_short_t const_qstr_table_data_requests___init__[90] = {
    MP_QSTR_requests_slash___init___dot_py,
    MP_QSTR__lt_module_gt_,
    MP_QSTR_socket,
    MP_QSTR_Response,
    MP_QSTR_0_dot_10_dot_2,
    MP_QSTR_request,
    MP_QSTR_copy,
    MP_QSTR___next__,
    MP_QSTR___len__,
    MP_QSTR_binascii,
    MP_QSTR_format,
    MP_QSTR_b2a_base64,
    MP_QSTR_ascii,
    MP_QSTR_Basic_space__brace_open__brace_close_,
    MP_QSTR_split,
    MP_QSTR__slash_,
    MP_QSTR_,
    MP_QSTR_http_colon_,
    MP_QSTR_https_colon_,
    MP_QSTR_tls,
    MP_QSTR__colon_,
    MP_QSTR_getaddrinfo,
    MP_QSTR_SOCK_STREAM,
    MP_QSTR_settimeout,
    MP_QSTR_connect,
    MP_QSTR_SSLContext,
    MP_QSTR_PROTOCOL_TLS_CLIENT,
    MP_QSTR_CERT_NONE,
    MP_QSTR_verify_mode,
    MP_QSTR_wrap_socket,
    MP_QSTR_server_hostname,
    MP_QSTR_write,
    MP_QSTR_Host,
    MP_QSTR_AssertionError,
    MP_QSTR_dumps,
    MP_QSTR_json,
    MP_QSTR_chunked,
    MP_QSTR_Connection,
    MP_QSTR_close,
    MP_QSTR_get,
    MP_QSTR_0_0x0d__0x0a__0x0d__0x0a_,
    MP_QSTR_readline,
    MP_QSTR_rstrip,
    MP_QSTR_startswith,
    MP_QSTR_utf_hyphen_8,
    MP_QSTR_strip,
    MP_QSTR_pop,
    MP_QSTR_GET,
    MP_QSTR_status_code,
    MP_QSTR_reason,
    MP_QSTR_headers,
    MP_QSTR_head,
    MP_QSTR_HEAD,
    MP_QSTR_post,
    MP_QSTR_POST,
    MP_QSTR_put,
    MP_QSTR_PUT,
    MP_QSTR_patch,
    MP_QSTR_PATCH,
    MP_QSTR_delete,
    MP_QSTR_DELETE,
    MP_QSTR___init__,
    MP_QSTR_raw,
    MP_QSTR_encoding,
    MP_QSTR__cached,
    MP_QSTR_content,
    MP_QSTR_read,
    MP_QSTR_text,
    MP_QSTR_loads,
    MP_QSTR___version__,
    MP_QSTR___name__,
    MP_QSTR___module__,
    MP_QSTR___qualname__,
    MP_QSTR_property,
    MP_QSTR_method,
    MP_QSTR_url,
    MP_QSTR_data,
    MP_QSTR_stream,
    MP_QSTR_auth,
    MP_QSTR_timeout,
    MP_QSTR_parse_headers,
    MP_QSTR_getattr,
    MP_QSTR_str,
    MP_QSTR_ValueError,
    MP_QSTR_int,
    MP_QSTR_len,
    MP_QSTR_NotImplementedError,
    MP_QSTR_OSError,
    MP_QSTR_self,
    MP_QSTR_f,
};

// constants
static const mp_obj_str_t const_obj_requests___init___0 = {{&mp_type_bytes}, 14943, 5, (const byte*)"\x7b\x7d\x3a\x7b\x7d"};
static const mp_obj_str_t const_obj_requests___init___3 = {{&mp_type_bytes}, 47477, 17, (const byte*)"\x25\x73\x20\x2f\x25\x73\x20\x48\x54\x54\x50\x2f\x31\x2e\x30\x0d\x0a"};
static const mp_obj_str_t const_obj_requests___init___8 = {{&mp_type_bytes}, 26975, 2, (const byte*)"\x3a\x20"};
static const mp_obj_str_t const_obj_requests___init___9 = {{&mp_type_bytes}, 27298, 2, (const byte*)"\x0d\x0a"};
static const mp_obj_str_t const_obj_requests___init___10 = {{&mp_type_bytes}, 50079, 4, (const byte*)"\x25\x78\x0d\x0a"};
static const mp_obj_str_t const_obj_requests___init___11 = {{&mp_type_str}, 62148, 29, (const byte*)"\x48\x54\x54\x50\x20\x65\x72\x72\x6f\x72\x3a\x20\x42\x61\x64\x53\x74\x61\x74\x75\x73\x4c\x69\x6e\x65\x3a\x0a\x25\x73"};
static const mp_obj_str_t const_obj_requests___init___12 = {{&mp_type_bytes}, 59642, 18, (const byte*)"\x54\x72\x61\x6e\x73\x66\x65\x72\x2d\x45\x6e\x63\x6f\x64\x69\x6e\x67\x3a"};
static const mp_obj_str_t const_obj_requests___init___13 = {{&mp_type_bytes}, 3583, 7, (const byte*)"\x63\x68\x75\x6e\x6b\x65\x64"};
static const mp_obj_str_t const_obj_requests___init___15 = {{&mp_type_bytes}, 1090, 9, (const byte*)"\x4c\x6f\x63\x61\x74\x69\x6f\x6e\x3a"};
static const mp_obj_str_t const_obj_requests___init___16 = {{&mp_type_str}, 18157, 29, (const byte*)"\x52\x65\x64\x69\x72\x65\x63\x74\x20\x25\x64\x20\x6e\x6f\x74\x20\x79\x65\x74\x20\x73\x75\x70\x70\x6f\x72\x74\x65\x64"};

// constant table
static const mp_rom_obj_t const_obj_table_data_requests___init__[17] = {
    MP_ROM_PTR(&const_obj_requests___init___0),
    MP_ROM_QSTR(MP_QSTR_Authorization),
    MP_ROM_QSTR(MP_QSTR_Unsupported_space_protocol_colon__space_),
    MP_ROM_PTR(&const_obj_requests___init___3),
    MP_ROM_QSTR(MP_QSTR_Content_hyphen_Type),
    MP_ROM_QSTR(MP_QSTR_application_slash_json),
    MP_ROM_QSTR(MP_QSTR_Transfer_hyphen_Encoding),
    MP_ROM_QSTR(MP_QSTR_Content_hyphen_Length),
    MP_ROM_PTR(&const_obj_requests___init___8),
    MP_ROM_PTR(&const_obj_requests___init___9),
    MP_ROM_PTR(&const_obj_requests___init___10),
    MP_ROM_PTR(&const_obj_requests___init___11),
    MP_ROM_PTR(&const_obj_requests___init___12),
    MP_ROM_PTR(&const_obj_requests___init___13),
    MP_ROM_QSTR(MP_QSTR_Unsupported_space_),
    MP_ROM_PTR(&const_obj_requests___init___15),
    MP_ROM_PTR(&const_obj_requests___init___16),
};

static const mp_frozen_module_t frozen_module_requests___init__ = {
    .constants = {
        .qstr_table = (qstr_short_t *)&const_qstr_table_data_requests___init__,
        .obj_table = (mp_obj_t *)&const_obj_table_data_requests___init__,
    },
    .proto_fun = &proto_fun_requests___init____lt_module_gt_,
};

////////////////////////////////////////////////////////////////////////////////
// frozen module mip___init__
// - original source file: /Users/gadgetoid/Development/micropython-web/picovector/ports/sokol/build/frozen_mpy/mip/__init__.mpy
// - frozen file name: mip/__init__.py
// - .mpy header: 4d:06:00:1f

// frozen bytecode for file mip/__init__.py, scope mip___init____lt_module_gt_
static const byte fun_data_mip___init____lt_module_gt_[85] = {
    0x18,0x02, // prelude
    0x01, // names: <module>
     // code info
    0x80, // LOAD_CONST_SMALL_INT 0
    0x10,0x02, // LOAD_CONST_STRING 'const'
    0x2a,0x01, // BUILD_TUPLE 1
    0x1b,0x03, // IMPORT_NAME 'micropython'
    0x1c,0x02, // IMPORT_FROM 'const'
    0x16,0x02, // STORE_NAME 'const'
    0x59, // POP_TOP
    0x80, // LOAD_CONST_SMALL_INT 0
    0x51, // LOAD_CONST_NONE
    0x1b,0x04, // IMPORT_NAME 'requests'
    0x16,0x04, // STORE_NAME 'requests'
    0x80, // LOAD_CONST_SMALL_INT 0
    0x51, // LOAD_CONST_NONE
    0x1b,0x05, // IMPORT_NAME 'sys'
    0x16,0x05, // STORE_NAME 'sys'
    0x22,0x81,0x00, // LOAD_CONST_SMALL_INT 128
    0x16,0x45, // STORE_NAME '_CHUNK_SIZE'
    0x23,0x00, // LOAD_CONST_OBJ 0
    0x16,0x46, // STORE_NAME 'allowed_mip_url_prefixes'
    0x32,0x00, // MAKE_FUNCTION 0
    0x16,0x07, // STORE_NAME '_ensure_path_exists'
    0x32,0x01, // MAKE_FUNCTION 1
    0x16,0x0f, // STORE_NAME '_chunk'
    0x32,0x02, // MAKE_FUNCTION 2
    0x16,0x11, // STORE_NAME '_check_exists'
    0x51, // LOAD_CONST_NONE
    0x2a,0x01, // BUILD_TUPLE 1
    0x53, // LOAD_NULL
    0x33,0x03, // MAKE_FUNCTION_DEFARGS 3
    0x16,0x1a, // STORE_NAME '_rewrite_url'
    0x32,0x04, // MAKE_FUNCTION 4
    0x16,0x21, // STORE_NAME '_download_file'
    0x32,0x05, // MAKE_FUNCTION 5
    0x16,0x2b, // STORE_NAME '_install_json'
    0x32,0x06, // MAKE_FUNCTION 6
    0x16,0x34, // STORE_NAME '_install_package'
    0x51, // LOAD_CONST_NONE
    0x51, // LOAD_CONST_NONE
    0x51, // LOAD_CONST_NONE
    0x52, // LOAD_CONST_TRUE
    0x2a,0x04, // BUILD_TUPLE 4
    0x53, // LOAD_NULL
    0x33,0x07, // MAKE_FUNCTION_DEFARGS 7
    0x16,0x3e, // STORE_NAME 'install'
    0x10,0x06, // LOAD_CONST_STRING '0.4.1'
    0x16,0x47, // STORE_NAME '__version__'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
// child of mip___init____lt_module_gt_
// frozen bytecode for file mip/__init__.py, scope mip___init____ensure_path_exists
static const byte fun_data_mip___init____ensure_path_exists[97] = {
    0x65,0x04, // prelude
    0x07,0x3f, // names: _ensure_path_exists, path
     // code info
    0x80, // LOAD_CONST_SMALL_INT 0
    0x51, // LOAD_CONST_NONE
    0x1b,0x08, // IMPORT_NAME 'os'
    0xc1, // STORE_FAST 1
    0xb0, // LOAD_FAST 0
    0x14,0x09, // LOAD_METHOD 'split'
    0x10,0x0a, // LOAD_CONST_STRING '/'
    0x36,0x01, // CALL_METHOD 1
    0xc2, // STORE_FAST 2
    0xb2, // LOAD_FAST 2
    0x80, // LOAD_CONST_SMALL_INT 0
    0x55, // LOAD_SUBSCR
    0x43,0x50, // POP_JUMP_IF_TRUE 16
    0xb2, // LOAD_FAST 2
    0x14,0x0b, // LOAD_METHOD 'pop'
    0x80, // LOAD_CONST_SMALL_INT 0
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x10,0x0a, // LOAD_CONST_STRING '/'
    0xb2, // LOAD_FAST 2
    0x80, // LOAD_CONST_SMALL_INT 0
    0x55, // LOAD_SUBSCR
    0xf2, // BINARY_OP 27 __add__
    0xb2, // LOAD_FAST 2
    0x80, // LOAD_CONST_SMALL_INT 0
    0x56, // STORE_SUBSCR
    0x10,0x0c, // LOAD_CONST_STRING ''
    0xc3, // STORE_FAST 3
    0x12,0x48, // LOAD_GLOBAL 'len'
    0xb2, // LOAD_FAST 2
    0x34,0x01, // CALL_FUNCTION 1
    0x81, // LOAD_CONST_SMALL_INT 1
    0xf3, // BINARY_OP 28 __sub__
    0x80, // LOAD_CONST_SMALL_INT 0
    0x42,0x65, // JUMP 37
    0x57, // DUP_TOP
    0xc4, // STORE_FAST 4
    0xb3, // LOAD_FAST 3
    0xb2, // LOAD_FAST 2
    0xb4, // LOAD_FAST 4
    0x55, // LOAD_SUBSCR
    0xe5, // BINARY_OP 14 __iadd__
    0xc3, // STORE_FAST 3
    0x48,0x09, // SETUP_EXCEPT 9
    0xb1, // LOAD_FAST 1
    0x14,0x0d, // LOAD_METHOD 'stat'
    0xb3, // LOAD_FAST 3
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x4a,0x0b, // POP_EXCEPT_JUMP 11
    0x59, // POP_TOP
    0xb1, // LOAD_FAST 1
    0x14,0x0e, // LOAD_METHOD 'mkdir'
    0xb3, // LOAD_FAST 3
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x4a,0x01, // POP_EXCEPT_JUMP 1
    0x5d, // END_FINALLY
    0xb3, // LOAD_FAST 3
    0x10,0x0a, // LOAD_CONST_STRING '/'
    0xe5, // BINARY_OP 14 __iadd__
    0xc3, // STORE_FAST 3
    0x81, // LOAD_CONST_SMALL_INT 1
    0xe5, // BINARY_OP 14 __iadd__
    0x58, // DUP_TOP_TWO
    0x5a, // ROT_TWO
    0xd7, // BINARY_OP 0 __lt__
    0x43,0x16, // POP_JUMP_IF_TRUE -42
    0x59, // POP_TOP
    0x59, // POP_TOP
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_mip___init____ensure_path_exists = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_mip___init____ensure_path_exists,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 97,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 13,
        .n_exc_stack = 1,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 7,
        .line_info = fun_data_mip___init____ensure_path_exists + 4,
        .line_info_top = fun_data_mip___init____ensure_path_exists + 4,
        .opcodes = fun_data_mip___init____ensure_path_exists + 4,
    },
    #endif
    #endif
};
#else
#define proto_fun_mip___init____ensure_path_exists fun_data_mip___init____ensure_path_exists[0]
#endif

// child of mip___init____lt_module_gt_
// frozen bytecode for file mip/__init__.py, scope mip___init____chunk
static const byte fun_data_mip___init____chunk[53] = {
    0x3a,0x06, // prelude
    0x0f,0x49,0x4a, // names: _chunk, src, dest
     // code info
    0x12,0x4b, // LOAD_GLOBAL 'memoryview'
    0x12,0x4c, // LOAD_GLOBAL 'bytearray'
    0x12,0x45, // LOAD_GLOBAL '_CHUNK_SIZE'
    0x34,0x01, // CALL_FUNCTION 1
    0x34,0x01, // CALL_FUNCTION 1
    0xc2, // STORE_FAST 2
    0xb0, // LOAD_FAST 0
    0x14,0x10, // LOAD_METHOD 'readinto'
    0xb2, // LOAD_FAST 2
    0x36,0x01, // CALL_METHOD 1
    0xc3, // STORE_FAST 3
    0xb3, // LOAD_FAST 3
    0x80, // LOAD_CONST_SMALL_INT 0
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x42, // POP_JUMP_IF_FALSE 2
    0x42,0x55, // JUMP 21
    0xb1, // LOAD_FAST 1
    0xb3, // LOAD_FAST 3
    0x12,0x45, // LOAD_GLOBAL '_CHUNK_SIZE'
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x43, // POP_JUMP_IF_FALSE 3
    0xb2, // LOAD_FAST 2
    0x42,0x46, // JUMP 6
    0xb2, // LOAD_FAST 2
    0x51, // LOAD_CONST_NONE
    0xb3, // LOAD_FAST 3
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0x34,0x01, // CALL_FUNCTION 1
    0x59, // POP_TOP
    0x42,0x1d, // JUMP -35
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_mip___init____chunk = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_mip___init____chunk,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 53,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 8,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 15,
        .line_info = fun_data_mip___init____chunk + 5,
        .line_info_top = fun_data_mip___init____chunk + 5,
        .opcodes = fun_data_mip___init____chunk + 5,
    },
    #endif
    #endif
};
#else
#define proto_fun_mip___init____chunk fun_data_mip___init____chunk[0]
#endif

// child of mip___init____lt_module_gt_
// frozen bytecode for file mip/__init__.py, scope mip___init____check_exists
static const byte fun_data_mip___init____check_exists[88] = {
    0xf2,0x02,0x06, // prelude
    0x11,0x3f,0x4d, // names: _check_exists, path, short_hash
     // code info
    0x80, // LOAD_CONST_SMALL_INT 0
    0x51, // LOAD_CONST_NONE
    0x1b,0x08, // IMPORT_NAME 'os'
    0xc2, // STORE_FAST 2
    0x48,0x45, // SETUP_EXCEPT 69
    0x80, // LOAD_CONST_SMALL_INT 0
    0x51, // LOAD_CONST_NONE
    0x1b,0x12, // IMPORT_NAME 'binascii'
    0xc3, // STORE_FAST 3
    0x80, // LOAD_CONST_SMALL_INT 0
    0x51, // LOAD_CONST_NONE
    0x1b,0x13, // IMPORT_NAME 'hashlib'
    0xc4, // STORE_FAST 4
    0x12,0x4e, // LOAD_GLOBAL 'open'
    0xb0, // LOAD_FAST 0
    0x10,0x14, // LOAD_CONST_STRING 'rb'
    0x34,0x02, // CALL_FUNCTION 2
    0x47,0x2e, // SETUP_WITH 46
    0xc5, // STORE_FAST 5
    0xb4, // LOAD_FAST 4
    0x14,0x15, // LOAD_METHOD 'sha256'
    0x36,0x00, // CALL_METHOD 0
    0xc6, // STORE_FAST 6
    0x12,0x0f, // LOAD_GLOBAL '_chunk'
    0xb5, // LOAD_FAST 5
    0xb6, // LOAD_FAST 6
    0x13,0x16, // LOAD_ATTR 'update'
    0x34,0x02, // CALL_FUNCTION 2
    0x59, // POP_TOP
    0x12,0x4f, // LOAD_GLOBAL 'str'
    0xb3, // LOAD_FAST 3
    0x14,0x17, // LOAD_METHOD 'hexlify'
    0xb6, // LOAD_FAST 6
    0x14,0x18, // LOAD_METHOD 'digest'
    0x36,0x00, // CALL_METHOD 0
    0x36,0x01, // CALL_METHOD 1
    0x51, // LOAD_CONST_NONE
    0x12,0x48, // LOAD_GLOBAL 'len'
    0xb1, // LOAD_FAST 1
    0x34,0x01, // CALL_FUNCTION 1
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0x10,0x19, // LOAD_CONST_STRING 'utf-8'
    0x34,0x02, // CALL_FUNCTION 2
    0xc7, // STORE_FAST 7
    0xb7, // LOAD_FAST 7
    0xb1, // LOAD_FAST 1
    0xd9, // BINARY_OP 2 __eq__
    0x63, // RETURN_VALUE
    0x5c, // WITH_CLEANUP
    0x5d, // END_FINALLY
    0x4a,0x04, // POP_EXCEPT_JUMP 4
    0x59, // POP_TOP
    0x50, // LOAD_CONST_FALSE
    0x63, // RETURN_VALUE
    0x5d, // END_FINALLY
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_mip___init____check_exists = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_mip___init____check_exists,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 88,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 15,
        .n_exc_stack = 2,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 17,
        .line_info = fun_data_mip___init____check_exists + 6,
        .line_info_top = fun_data_mip___init____check_exists + 6,
        .opcodes = fun_data_mip___init____check_exists + 6,
    },
    #endif
    #endif
};
#else
#define proto_fun_mip___init____check_exists fun_data_mip___init____check_exists[0]
#endif

// child of mip___init____lt_module_gt_
// frozen bytecode for file mip/__init__.py, scope mip___init____rewrite_url
static const byte fun_data_mip___init____rewrite_url[132] = {
    0xba,0x01,0x06, // prelude
    0x1a,0x50,0x51, // names: _rewrite_url, url, branch
     // code info
    0xb1, // LOAD_FAST 1
    0x43,0x43, // POP_JUMP_IF_TRUE 3
    0x10,0x1b, // LOAD_CONST_STRING 'HEAD'
    0xc1, // STORE_FAST 1
    0xb0, // LOAD_FAST 0
    0x14,0x1c, // LOAD_METHOD 'startswith'
    0x10,0x1d, // LOAD_CONST_STRING 'github:'
    0x36,0x01, // CALL_METHOD 1
    0x44,0x72, // POP_JUMP_IF_FALSE 50
    0xb0, // LOAD_FAST 0
    0x87, // LOAD_CONST_SMALL_INT 7
    0x51, // LOAD_CONST_NONE
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0x14,0x09, // LOAD_METHOD 'split'
    0x10,0x0a, // LOAD_CONST_STRING '/'
    0x36,0x01, // CALL_METHOD 1
    0xc0, // STORE_FAST 0
    0x23,0x01, // LOAD_CONST_OBJ 1
    0xb0, // LOAD_FAST 0
    0x80, // LOAD_CONST_SMALL_INT 0
    0x55, // LOAD_SUBSCR
    0xf2, // BINARY_OP 27 __add__
    0x10,0x0a, // LOAD_CONST_STRING '/'
    0xf2, // BINARY_OP 27 __add__
    0xb0, // LOAD_FAST 0
    0x81, // LOAD_CONST_SMALL_INT 1
    0x55, // LOAD_SUBSCR
    0xf2, // BINARY_OP 27 __add__
    0x10,0x0a, // LOAD_CONST_STRING '/'
    0xf2, // BINARY_OP 27 __add__
    0xb1, // LOAD_FAST 1
    0xf2, // BINARY_OP 27 __add__
    0x10,0x0a, // LOAD_CONST_STRING '/'
    0xf2, // BINARY_OP 27 __add__
    0x10,0x0a, // LOAD_CONST_STRING '/'
    0x14,0x1e, // LOAD_METHOD 'join'
    0xb0, // LOAD_FAST 0
    0x82, // LOAD_CONST_SMALL_INT 2
    0x51, // LOAD_CONST_NONE
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0x36,0x01, // CALL_METHOD 1
    0xf2, // BINARY_OP 27 __add__
    0xc0, // STORE_FAST 0
    0x42,0x7b, // JUMP 59
    0xb0, // LOAD_FAST 0
    0x14,0x1c, // LOAD_METHOD 'startswith'
    0x10,0x1f, // LOAD_CONST_STRING 'gitlab:'
    0x36,0x01, // CALL_METHOD 1
    0x44,0x72, // POP_JUMP_IF_FALSE 50
    0xb0, // LOAD_FAST 0
    0x87, // LOAD_CONST_SMALL_INT 7
    0x51, // LOAD_CONST_NONE
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0x14,0x09, // LOAD_METHOD 'split'
    0x10,0x0a, // LOAD_CONST_STRING '/'
    0x36,0x01, // CALL_METHOD 1
    0xc0, // STORE_FAST 0
    0x23,0x02, // LOAD_CONST_OBJ 2
    0xb0, // LOAD_FAST 0
    0x80, // LOAD_CONST_SMALL_INT 0
    0x55, // LOAD_SUBSCR
    0xf2, // BINARY_OP 27 __add__
    0x10,0x0a, // LOAD_CONST_STRING '/'
    0xf2, // BINARY_OP 27 __add__
    0xb0, // LOAD_FAST 0
    0x81, // LOAD_CONST_SMALL_INT 1
    0x55, // LOAD_SUBSCR
    0xf2, // BINARY_OP 27 __add__
    0x10,0x20, // LOAD_CONST_STRING '/-/raw/'
    0xf2, // BINARY_OP 27 __add__
    0xb1, // LOAD_FAST 1
    0xf2, // BINARY_OP 27 __add__
    0x10,0x0a, // LOAD_CONST_STRING '/'
    0xf2, // BINARY_OP 27 __add__
    0x10,0x0a, // LOAD_CONST_STRING '/'
    0x14,0x1e, // LOAD_METHOD 'join'
    0xb0, // LOAD_FAST 0
    0x82, // LOAD_CONST_SMALL_INT 2
    0x51, // LOAD_CONST_NONE
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0x36,0x01, // CALL_METHOD 1
    0xf2, // BINARY_OP 27 __add__
    0xc0, // STORE_FAST 0
    0x42,0x40, // JUMP 0
    0xb0, // LOAD_FAST 0
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_mip___init____rewrite_url = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_mip___init____rewrite_url,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 132,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 8,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 1,
        .qstr_block_name_idx = 26,
        .line_info = fun_data_mip___init____rewrite_url + 6,
        .line_info_top = fun_data_mip___init____rewrite_url + 6,
        .opcodes = fun_data_mip___init____rewrite_url + 6,
    },
    #endif
    #endif
};
#else
#define proto_fun_mip___init____rewrite_url fun_data_mip___init____rewrite_url[0]
#endif

// child of mip___init____lt_module_gt_
// frozen bytecode for file mip/__init__.py, scope mip___init____download_file
static const byte fun_data_mip___init____download_file[89] = {
    0xda,0x02,0x06, // prelude
    0x21,0x50,0x4a, // names: _download_file, url, dest
     // code info
    0x12,0x04, // LOAD_GLOBAL 'requests'
    0x14,0x22, // LOAD_METHOD 'get'
    0xb0, // LOAD_FAST 0
    0x36,0x01, // CALL_METHOD 1
    0xc2, // STORE_FAST 2
    0x49,0x40, // SETUP_FINALLY 64
    0xb2, // LOAD_FAST 2
    0x13,0x23, // LOAD_ATTR 'status_code'
    0x22,0x81,0x48, // LOAD_CONST_SMALL_INT 200
    0xdc, // BINARY_OP 5 __ne__
    0x44,0x4f, // POP_JUMP_IF_FALSE 15
    0x12,0x52, // LOAD_GLOBAL 'print'
    0x10,0x24, // LOAD_CONST_STRING 'Error'
    0xb2, // LOAD_FAST 2
    0x13,0x23, // LOAD_ATTR 'status_code'
    0x10,0x25, // LOAD_CONST_STRING 'requesting'
    0xb0, // LOAD_FAST 0
    0x34,0x04, // CALL_FUNCTION 4
    0x59, // POP_TOP
    0x50, // LOAD_CONST_FALSE
    0x63, // RETURN_VALUE
    0x12,0x52, // LOAD_GLOBAL 'print'
    0x10,0x26, // LOAD_CONST_STRING 'Copying:'
    0xb1, // LOAD_FAST 1
    0x34,0x02, // CALL_FUNCTION 2
    0x59, // POP_TOP
    0x12,0x07, // LOAD_GLOBAL '_ensure_path_exists'
    0xb1, // LOAD_FAST 1
    0x34,0x01, // CALL_FUNCTION 1
    0x59, // POP_TOP
    0x12,0x4e, // LOAD_GLOBAL 'open'
    0xb1, // LOAD_FAST 1
    0x10,0x27, // LOAD_CONST_STRING 'wb'
    0x34,0x02, // CALL_FUNCTION 2
    0x47,0x0d, // SETUP_WITH 13
    0xc3, // STORE_FAST 3
    0x12,0x0f, // LOAD_GLOBAL '_chunk'
    0xb2, // LOAD_FAST 2
    0x13,0x28, // LOAD_ATTR 'raw'
    0xb3, // LOAD_FAST 3
    0x13,0x29, // LOAD_ATTR 'write'
    0x34,0x02, // CALL_FUNCTION 2
    0x59, // POP_TOP
    0x51, // LOAD_CONST_NONE
    0x5c, // WITH_CLEANUP
    0x5d, // END_FINALLY
    0x52, // LOAD_CONST_TRUE
    0x63, // RETURN_VALUE
    0xb2, // LOAD_FAST 2
    0x14,0x2a, // LOAD_METHOD 'close'
    0x36,0x00, // CALL_METHOD 0
    0x59, // POP_TOP
    0x5d, // END_FINALLY
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_mip___init____download_file = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_mip___init____download_file,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 89,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 12,
        .n_exc_stack = 2,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 33,
        .line_info = fun_data_mip___init____download_file + 6,
        .line_info_top = fun_data_mip___init____download_file + 6,
        .opcodes = fun_data_mip___init____download_file + 6,
    },
    #endif
    #endif
};
#else
#define proto_fun_mip___init____download_file fun_data_mip___init____download_file[0]
#endif

// child of mip___init____lt_module_gt_
// frozen bytecode for file mip/__init__.py, scope mip___init____install_json
static const byte fun_data_mip___init____install_json[271] = {
    0xcd,0x14,0x0d, // prelude
    0x2b,0x53,0x54,0x55,0x56,0x57, // names: _install_json, package_json_url, index, target, version, mpy
    0x0f, // code info
    0x12,0x04, // LOAD_GLOBAL 'requests'
    0x14,0x22, // LOAD_METHOD 'get'
    0x12,0x1a, // LOAD_GLOBAL '_rewrite_url'
    0xb0, // LOAD_FAST 0
    0xb3, // LOAD_FAST 3
    0x34,0x02, // CALL_FUNCTION 2
    0x36,0x01, // CALL_METHOD 1
    0xc5, // STORE_FAST 5
    0x49,0x1a, // SETUP_FINALLY 26
    0xb5, // LOAD_FAST 5
    0x13,0x23, // LOAD_ATTR 'status_code'
    0x22,0x81,0x48, // LOAD_CONST_SMALL_INT 200
    0xdc, // BINARY_OP 5 __ne__
    0x44,0x4a, // POP_JUMP_IF_FALSE 10
    0x12,0x52, // LOAD_GLOBAL 'print'
    0x23,0x03, // LOAD_CONST_OBJ 3
    0xb0, // LOAD_FAST 0
    0x34,0x02, // CALL_FUNCTION 2
    0x59, // POP_TOP
    0x50, // LOAD_CONST_FALSE
    0x63, // RETURN_VALUE
    0xb5, // LOAD_FAST 5
    0x14,0x2c, // LOAD_METHOD 'json'
    0x36,0x00, // CALL_METHOD 0
    0xc6, // STORE_FAST 6
    0x51, // LOAD_CONST_NONE
    0xb5, // LOAD_FAST 5
    0x14,0x2a, // LOAD_METHOD 'close'
    0x36,0x00, // CALL_METHOD 0
    0x59, // POP_TOP
    0x5d, // END_FINALLY
    0xb6, // LOAD_FAST 6
    0x14,0x22, // LOAD_METHOD 'get'
    0x10,0x2d, // LOAD_CONST_STRING 'hashes'
    0x2a,0x00, // BUILD_TUPLE 0
    0x36,0x02, // CALL_METHOD 2
    0x5f, // GET_ITER_STACK
    0x4b,0x46, // FOR_ITER 70
    0x30,0x02, // UNPACK_SEQUENCE 2
    0xc7, // STORE_FAST 7
    0xc8, // STORE_FAST 8
    0xb2, // LOAD_FAST 2
    0x10,0x0a, // LOAD_CONST_STRING '/'
    0xf2, // BINARY_OP 27 __add__
    0xb7, // LOAD_FAST 7
    0xf2, // BINARY_OP 27 __add__
    0xc9, // STORE_FAST 9
    0x12,0x11, // LOAD_GLOBAL '_check_exists'
    0xb9, // LOAD_FAST 9
    0xb8, // LOAD_FAST 8
    0x34,0x02, // CALL_FUNCTION 2
    0x44,0x4a, // POP_JUMP_IF_FALSE 10
    0x12,0x52, // LOAD_GLOBAL 'print'
    0x10,0x2e, // LOAD_CONST_STRING 'Exists:'
    0xb9, // LOAD_FAST 9
    0x34,0x02, // CALL_FUNCTION 2
    0x59, // POP_TOP
    0x42,0x66, // JUMP 38
    0x23,0x04, // LOAD_CONST_OBJ 4
    0x14,0x2f, // LOAD_METHOD 'format'
    0xb1, // LOAD_FAST 1
    0xb8, // LOAD_FAST 8
    0x51, // LOAD_CONST_NONE
    0x82, // LOAD_CONST_SMALL_INT 2
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0xb8, // LOAD_FAST 8
    0x36,0x03, // CALL_METHOD 3
    0xca, // STORE_FAST 10
    0x12,0x21, // LOAD_GLOBAL '_download_file'
    0xba, // LOAD_FAST 10
    0xb9, // LOAD_FAST 9
    0x34,0x02, // CALL_FUNCTION 2
    0x43,0x4f, // POP_JUMP_IF_TRUE 15
    0x12,0x52, // LOAD_GLOBAL 'print'
    0x23,0x05, // LOAD_CONST_OBJ 5
    0x14,0x2f, // LOAD_METHOD 'format'
    0xb7, // LOAD_FAST 7
    0xb8, // LOAD_FAST 8
    0x36,0x02, // CALL_METHOD 2
    0x34,0x01, // CALL_FUNCTION 1
    0x59, // POP_TOP
    0x50, // LOAD_CONST_FALSE
    0x63, // RETURN_VALUE
    0x42,0xb8,0x7f, // JUMP -72
    0xb0, // LOAD_FAST 0
    0x14,0x30, // LOAD_METHOD 'rpartition'
    0x10,0x0a, // LOAD_CONST_STRING '/'
    0x36,0x01, // CALL_METHOD 1
    0x80, // LOAD_CONST_SMALL_INT 0
    0x55, // LOAD_SUBSCR
    0xcb, // STORE_FAST 11
    0xb6, // LOAD_FAST 6
    0x14,0x22, // LOAD_METHOD 'get'
    0x10,0x31, // LOAD_CONST_STRING 'urls'
    0x2a,0x00, // BUILD_TUPLE 0
    0x36,0x02, // CALL_METHOD 2
    0x5f, // GET_ITER_STACK
    0x4b,0x4c, // FOR_ITER 76
    0x30,0x02, // UNPACK_SEQUENCE 2
    0xc7, // STORE_FAST 7
    0x27,0x0f, // STORE_DEREF 15
    0xb2, // LOAD_FAST 2
    0x10,0x0a, // LOAD_CONST_STRING '/'
    0xf2, // BINARY_OP 27 __add__
    0xb7, // LOAD_FAST 7
    0xf2, // BINARY_OP 27 __add__
    0xc9, // STORE_FAST 9
    0x12,0x58, // LOAD_GLOBAL 'any'
    0xbf, // LOAD_FAST 15
    0x20,0x00,0x01, // MAKE_CLOSURE 0
    0x12,0x46, // LOAD_GLOBAL 'allowed_mip_url_prefixes'
    0x5e, // GET_ITER
    0x34,0x01, // CALL_FUNCTION 1
    0x34,0x01, // CALL_FUNCTION 1
    0xcc, // STORE_FAST 12
    0xbb, // LOAD_FAST 11
    0x44,0x4e, // POP_JUMP_IF_FALSE 14
    0xbc, // LOAD_FAST 12
    0x43,0x4b, // POP_JUMP_IF_TRUE 11
    0x10,0x32, // LOAD_CONST_STRING '{}/{}'
    0x14,0x2f, // LOAD_METHOD 'format'
    0xbb, // LOAD_FAST 11
    0x25,0x0f, // LOAD_DEREF 15
    0x36,0x02, // CALL_METHOD 2
    0x27,0x0f, // STORE_DEREF 15
    0x12,0x21, // LOAD_GLOBAL '_download_file'
    0x12,0x1a, // LOAD_GLOBAL '_rewrite_url'
    0x25,0x0f, // LOAD_DEREF 15
    0xb3, // LOAD_FAST 3
    0x34,0x02, // CALL_FUNCTION 2
    0xb9, // LOAD_FAST 9
    0x34,0x02, // CALL_FUNCTION 2
    0x43,0x50, // POP_JUMP_IF_TRUE 16
    0x12,0x52, // LOAD_GLOBAL 'print'
    0x23,0x05, // LOAD_CONST_OBJ 5
    0x14,0x2f, // LOAD_METHOD 'format'
    0xb7, // LOAD_FAST 7
    0x25,0x0f, // LOAD_DEREF 15
    0x36,0x02, // CALL_METHOD 2
    0x34,0x01, // CALL_FUNCTION 1
    0x59, // POP_TOP
    0x50, // LOAD_CONST_FALSE
    0x63, // RETURN_VALUE
    0x42,0xb2,0x7f, // JUMP -78
    0xb6, // LOAD_FAST 6
    0x14,0x22, // LOAD_METHOD 'get'
    0x10,0x33, // LOAD_CONST_STRING 'deps'
    0x2a,0x00, // BUILD_TUPLE 0
    0x36,0x02, // CALL_METHOD 2
    0x5f, // GET_ITER_STACK
    0x4b,0x13, // FOR_ITER 19
    0x30,0x02, // UNPACK_SEQUENCE 2
    0xcd, // STORE_FAST 13
    0xce, // STORE_FAST 14
    0x12,0x34, // LOAD_GLOBAL '_install_package'
    0xbd, // LOAD_FAST 13
    0xb1, // LOAD_FAST 1
    0xb2, // LOAD_FAST 2
    0xbe, // LOAD_FAST 14
    0xb4, // LOAD_FAST 4
    0x34,0x05, // CALL_FUNCTION 5
    0x43,0x42, // POP_JUMP_IF_TRUE 2
    0x50, // LOAD_CONST_FALSE
    0x63, // RETURN_VALUE
    0x42,0x2b, // JUMP -21
    0x52, // LOAD_CONST_TRUE
    0x63, // RETURN_VALUE
};
// child of mip___init____install_json
// frozen bytecode for file mip/__init__.py, scope mip___init____install_json__lt_genexpr_gt_
static const byte fun_data_mip___init____install_json__lt_genexpr_gt_[26] = {
    0xca,0x40,0x06, // prelude
    0x44,0x5b,0x5b, // names: <genexpr>, *, *
     // code info
    0x53, // LOAD_NULL
    0xb1, // LOAD_FAST 1
    0x53, // LOAD_NULL
    0x53, // LOAD_NULL
    0x4b,0x0c, // FOR_ITER 12
    0xc2, // STORE_FAST 2
    0x25,0x00, // LOAD_DEREF 0
    0x14,0x1c, // LOAD_METHOD 'startswith'
    0xb2, // LOAD_FAST 2
    0x36,0x01, // CALL_METHOD 1
    0x67, // YIELD_VALUE
    0x59, // POP_TOP
    0x42,0x32, // JUMP -14
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_mip___init____install_json__lt_genexpr_gt_ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 1,
    .fun_data = fun_data_mip___init____install_json__lt_genexpr_gt_,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 26,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 10,
        .n_exc_stack = 0,
        .scope_flags = 1,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 68,
        .line_info = fun_data_mip___init____install_json__lt_genexpr_gt_ + 6,
        .line_info_top = fun_data_mip___init____install_json__lt_genexpr_gt_ + 6,
        .opcodes = fun_data_mip___init____install_json__lt_genexpr_gt_ + 6,
    },
    #endif
    #endif
};
#else
#define proto_fun_mip___init____install_json__lt_genexpr_gt_ fun_data_mip___init____install_json__lt_genexpr_gt_[0]
#endif

static const mp_raw_code_t *const children_mip___init____install_json[] = {
    (const mp_raw_code_t *)&proto_fun_mip___init____install_json__lt_genexpr_gt_,
};

static const mp_raw_code_truncated_t proto_fun_mip___init____install_json = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_mip___init____install_json,
    .children = (void *)&children_mip___init____install_json,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 271,
    .n_children = 1,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 26,
        .n_exc_stack = 1,
        .scope_flags = 0,
        .n_pos_args = 5,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 43,
        .line_info = fun_data_mip___init____install_json + 9,
        .line_info_top = fun_data_mip___init____install_json + 9,
        .opcodes = fun_data_mip___init____install_json + 10,
    },
    #endif
    #endif
};

// child of mip___init____lt_module_gt_
// frozen bytecode for file mip/__init__.py, scope mip___init____install_package
static const byte fun_data_mip___init____install_package[214] = {
    0xe1,0x04,0x0d, // prelude
    0x34,0x59,0x54,0x55,0x56,0x57, // names: _install_package, package, index, target, version, mpy
    0x00, // code info
    0x12,0x58, // LOAD_GLOBAL 'any'
    0xb0, // LOAD_FAST 0
    0x20,0x00,0x01, // MAKE_CLOSURE 0
    0x12,0x46, // LOAD_GLOBAL 'allowed_mip_url_prefixes'
    0x5e, // GET_ITER
    0x34,0x01, // CALL_FUNCTION 1
    0x34,0x01, // CALL_FUNCTION 1
    0x44,0xf0,0x80, // POP_JUMP_IF_FALSE 112
    0x25,0x00, // LOAD_DEREF 0
    0x14,0x35, // LOAD_METHOD 'endswith'
    0x10,0x36, // LOAD_CONST_STRING '.py'
    0x36,0x01, // CALL_METHOD 1
    0x43,0x4a, // POP_JUMP_IF_TRUE 10
    0x25,0x00, // LOAD_DEREF 0
    0x14,0x35, // LOAD_METHOD 'endswith'
    0x10,0x37, // LOAD_CONST_STRING '.mpy'
    0x36,0x01, // CALL_METHOD 1
    0x44,0x69, // POP_JUMP_IF_FALSE 41
    0x12,0x52, // LOAD_GLOBAL 'print'
    0x23,0x06, // LOAD_CONST_OBJ 6
    0x14,0x2f, // LOAD_METHOD 'format'
    0x25,0x00, // LOAD_DEREF 0
    0xb2, // LOAD_FAST 2
    0x36,0x02, // CALL_METHOD 2
    0x34,0x01, // CALL_FUNCTION 1
    0x59, // POP_TOP
    0x12,0x21, // LOAD_GLOBAL '_download_file'
    0x12,0x1a, // LOAD_GLOBAL '_rewrite_url'
    0x25,0x00, // LOAD_DEREF 0
    0xb3, // LOAD_FAST 3
    0x34,0x02, // CALL_FUNCTION 2
    0xb2, // LOAD_FAST 2
    0x10,0x0a, // LOAD_CONST_STRING '/'
    0xf2, // BINARY_OP 27 __add__
    0x25,0x00, // LOAD_DEREF 0
    0x14,0x38, // LOAD_METHOD 'rsplit'
    0x10,0x0a, // LOAD_CONST_STRING '/'
    0x36,0x01, // CALL_METHOD 1
    0x7f, // LOAD_CONST_SMALL_INT -1
    0x55, // LOAD_SUBSCR
    0xf2, // BINARY_OP 27 __add__
    0x34,0x02, // CALL_FUNCTION 2
    0x63, // RETURN_VALUE
    0x25,0x00, // LOAD_DEREF 0
    0x14,0x35, // LOAD_METHOD 'endswith'
    0x10,0x39, // LOAD_CONST_STRING '.json'
    0x36,0x01, // CALL_METHOD 1
    0x43,0x58, // POP_JUMP_IF_TRUE 24
    0x25,0x00, // LOAD_DEREF 0
    0x14,0x35, // LOAD_METHOD 'endswith'
    0x10,0x0a, // LOAD_CONST_STRING '/'
    0x36,0x01, // CALL_METHOD 1
    0x43,0x47, // POP_JUMP_IF_TRUE 7
    0x25,0x00, // LOAD_DEREF 0
    0x10,0x0a, // LOAD_CONST_STRING '/'
    0xe5, // BINARY_OP 14 __iadd__
    0x27,0x00, // STORE_DEREF 0
    0x25,0x00, // LOAD_DEREF 0
    0x23,0x07, // LOAD_CONST_OBJ 7
    0xe5, // BINARY_OP 14 __iadd__
    0x27,0x00, // STORE_DEREF 0
    0x12,0x52, // LOAD_GLOBAL 'print'
    0x23,0x08, // LOAD_CONST_OBJ 8
    0x14,0x2f, // LOAD_METHOD 'format'
    0x25,0x00, // LOAD_DEREF 0
    0xb2, // LOAD_FAST 2
    0x36,0x02, // CALL_METHOD 2
    0x34,0x01, // CALL_FUNCTION 1
    0x59, // POP_TOP
    0x42,0xc1,0x80, // JUMP 65
    0xb3, // LOAD_FAST 3
    0x43,0x43, // POP_JUMP_IF_TRUE 3
    0x10,0x3a, // LOAD_CONST_STRING 'latest'
    0xc3, // STORE_FAST 3
    0x12,0x52, // LOAD_GLOBAL 'print'
    0x23,0x09, // LOAD_CONST_OBJ 9
    0x14,0x2f, // LOAD_METHOD 'format'
    0x25,0x00, // LOAD_DEREF 0
    0xb3, // LOAD_FAST 3
    0xb1, // LOAD_FAST 1
    0xb2, // LOAD_FAST 2
    0x36,0x04, // CALL_METHOD 4
    0x34,0x01, // CALL_FUNCTION 1
    0x59, // POP_TOP
    0xb4, // LOAD_FAST 4
    0x44,0x58, // POP_JUMP_IF_FALSE 24
    0x12,0x5a, // LOAD_GLOBAL 'hasattr'
    0x12,0x05, // LOAD_GLOBAL 'sys'
    0x13,0x3b, // LOAD_ATTR 'implementation'
    0x10,0x3c, // LOAD_CONST_STRING '_mpy'
    0x34,0x02, // CALL_FUNCTION 2
    0x44,0x4c, // POP_JUMP_IF_FALSE 12
    0x12,0x05, // LOAD_GLOBAL 'sys'
    0x13,0x3b, // LOAD_ATTR 'implementation'
    0x13,0x3c, // LOAD_ATTR '_mpy'
    0x22,0x81,0x7f, // LOAD_CONST_SMALL_INT 255
    0xef, // BINARY_OP 24 __and__
    0x42,0x42, // JUMP 2
    0x10,0x3d, // LOAD_CONST_STRING 'py'
    0xc5, // STORE_FAST 5
    0x23,0x0a, // LOAD_CONST_OBJ 10
    0x14,0x2f, // LOAD_METHOD 'format'
    0xb1, // LOAD_FAST 1
    0xb5, // LOAD_FAST 5
    0x25,0x00, // LOAD_DEREF 0
    0xb3, // LOAD_FAST 3
    0x36,0x04, // CALL_METHOD 4
    0x27,0x00, // STORE_DEREF 0
    0x12,0x2b, // LOAD_GLOBAL '_install_json'
    0x25,0x00, // LOAD_DEREF 0
    0xb1, // LOAD_FAST 1
    0xb2, // LOAD_FAST 2
    0xb3, // LOAD_FAST 3
    0xb4, // LOAD_FAST 4
    0x34,0x05, // CALL_FUNCTION 5
    0x63, // RETURN_VALUE
};
// child of mip___init____install_package
// frozen bytecode for file mip/__init__.py, scope mip___init____install_package__lt_genexpr_gt_
static const byte fun_data_mip___init____install_package__lt_genexpr_gt_[26] = {
    0xca,0x40,0x06, // prelude
    0x44,0x5b,0x5b, // names: <genexpr>, *, *
     // code info
    0x53, // LOAD_NULL
    0xb1, // LOAD_FAST 1
    0x53, // LOAD_NULL
    0x53, // LOAD_NULL
    0x4b,0x0c, // FOR_ITER 12
    0xc2, // STORE_FAST 2
    0x25,0x00, // LOAD_DEREF 0
    0x14,0x1c, // LOAD_METHOD 'startswith'
    0xb2, // LOAD_FAST 2
    0x36,0x01, // CALL_METHOD 1
    0x67, // YIELD_VALUE
    0x59, // POP_TOP
    0x42,0x32, // JUMP -14
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_mip___init____install_package__lt_genexpr_gt_ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 1,
    .fun_data = fun_data_mip___init____install_package__lt_genexpr_gt_,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 26,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 10,
        .n_exc_stack = 0,
        .scope_flags = 1,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 68,
        .line_info = fun_data_mip___init____install_package__lt_genexpr_gt_ + 6,
        .line_info_top = fun_data_mip___init____install_package__lt_genexpr_gt_ + 6,
        .opcodes = fun_data_mip___init____install_package__lt_genexpr_gt_ + 6,
    },
    #endif
    #endif
};
#else
#define proto_fun_mip___init____install_package__lt_genexpr_gt_ fun_data_mip___init____install_package__lt_genexpr_gt_[0]
#endif

static const mp_raw_code_t *const children_mip___init____install_package[] = {
    (const mp_raw_code_t *)&proto_fun_mip___init____install_package__lt_genexpr_gt_,
};

static const mp_raw_code_truncated_t proto_fun_mip___init____install_package = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_mip___init____install_package,
    .children = (void *)&children_mip___init____install_package,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 214,
    .n_children = 1,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 13,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 5,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 52,
        .line_info = fun_data_mip___init____install_package + 9,
        .line_info_top = fun_data_mip___init____install_package + 9,
        .opcodes = fun_data_mip___init____install_package + 10,
    },
    #endif
    #endif
};

// child of mip___init____lt_module_gt_
// frozen bytecode for file mip/__init__.py, scope mip___init___install
static const byte fun_data_mip___init___install[100] = {
    0xe1,0x84,0x80,0x01,0x0c, // prelude
    0x3e,0x59,0x54,0x55,0x56,0x57, // names: install, package, index, target, version, mpy
     // code info
    0xb2, // LOAD_FAST 2
    0x43,0x6d, // POP_JUMP_IF_TRUE 45
    0x12,0x05, // LOAD_GLOBAL 'sys'
    0x13,0x3f, // LOAD_ATTR 'path'
    0x5f, // GET_ITER_STACK
    0x4b,0x1d, // FOR_ITER 29
    0xc5, // STORE_FAST 5
    0xb5, // LOAD_FAST 5
    0x14,0x1c, // LOAD_METHOD 'startswith'
    0x10,0x40, // LOAD_CONST_STRING '/rom'
    0x36,0x01, // CALL_METHOD 1
    0x43,0x51, // POP_JUMP_IF_TRUE 17
    0xb5, // LOAD_FAST 5
    0x14,0x35, // LOAD_METHOD 'endswith'
    0x10,0x41, // LOAD_CONST_STRING '/lib'
    0x36,0x01, // CALL_METHOD 1
    0x44,0x48, // POP_JUMP_IF_FALSE 8
    0xb5, // LOAD_FAST 5
    0xc2, // STORE_FAST 2
    0x59, // POP_TOP
    0x59, // POP_TOP
    0x59, // POP_TOP
    0x59, // POP_TOP
    0x42,0x4b, // JUMP 11
    0x42,0x21, // JUMP -31
    0x12,0x52, // LOAD_GLOBAL 'print'
    0x23,0x0b, // LOAD_CONST_OBJ 11
    0x34,0x01, // CALL_FUNCTION 1
    0x59, // POP_TOP
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
    0xb1, // LOAD_FAST 1
    0x43,0x43, // POP_JUMP_IF_TRUE 3
    0x23,0x0c, // LOAD_CONST_OBJ 12
    0xc1, // STORE_FAST 1
    0x12,0x34, // LOAD_GLOBAL '_install_package'
    0xb0, // LOAD_FAST 0
    0xb1, // LOAD_FAST 1
    0x14,0x42, // LOAD_METHOD 'rstrip'
    0x10,0x0a, // LOAD_CONST_STRING '/'
    0x36,0x01, // CALL_METHOD 1
    0xb2, // LOAD_FAST 2
    0xb3, // LOAD_FAST 3
    0xb4, // LOAD_FAST 4
    0x34,0x05, // CALL_FUNCTION 5
    0x44,0x49, // POP_JUMP_IF_FALSE 9
    0x12,0x52, // LOAD_GLOBAL 'print'
    0x10,0x43, // LOAD_CONST_STRING 'Done'
    0x34,0x01, // CALL_FUNCTION 1
    0x59, // POP_TOP
    0x42,0x47, // JUMP 7
    0x12,0x52, // LOAD_GLOBAL 'print'
    0x23,0x0d, // LOAD_CONST_OBJ 13
    0x34,0x01, // CALL_FUNCTION 1
    0x59, // POP_TOP
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_mip___init___install = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_mip___init___install,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 100,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 13,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 5,
        .n_kwonly_args = 0,
        .n_def_pos_args = 4,
        .qstr_block_name_idx = 62,
        .line_info = fun_data_mip___init___install + 11,
        .line_info_top = fun_data_mip___init___install + 11,
        .opcodes = fun_data_mip___init___install + 11,
    },
    #endif
    #endif
};
#else
#define proto_fun_mip___init___install fun_data_mip___init___install[0]
#endif

static const mp_raw_code_t *const children_mip___init____lt_module_gt_[] = {
    (const mp_raw_code_t *)&proto_fun_mip___init____ensure_path_exists,
    (const mp_raw_code_t *)&proto_fun_mip___init____chunk,
    (const mp_raw_code_t *)&proto_fun_mip___init____check_exists,
    (const mp_raw_code_t *)&proto_fun_mip___init____rewrite_url,
    (const mp_raw_code_t *)&proto_fun_mip___init____download_file,
    (const mp_raw_code_t *)&proto_fun_mip___init____install_json,
    (const mp_raw_code_t *)&proto_fun_mip___init____install_package,
    (const mp_raw_code_t *)&proto_fun_mip___init___install,
};

static const mp_raw_code_truncated_t proto_fun_mip___init____lt_module_gt_ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_mip___init____lt_module_gt_,
    .children = (void *)&children_mip___init____lt_module_gt_,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 85,
    .n_children = 8,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 1,
        .line_info = fun_data_mip___init____lt_module_gt_ + 3,
        .line_info_top = fun_data_mip___init____lt_module_gt_ + 3,
        .opcodes = fun_data_mip___init____lt_module_gt_ + 3,
    },
    #endif
    #endif
};

static const qstr_short_t const_qstr_table_data_mip___init__[92] = {
    MP_QSTR_mip_slash___init___dot_py,
    MP_QSTR__lt_module_gt_,
    MP_QSTR_const,
    MP_QSTR_micropython,
    MP_QSTR_requests,
    MP_QSTR_sys,
    MP_QSTR_0_dot_4_dot_1,
    MP_QSTR__ensure_path_exists,
    MP_QSTR_os,
    MP_QSTR_split,
    MP_QSTR__slash_,
    MP_QSTR_pop,
    MP_QSTR_,
    MP_QSTR_stat,
    MP_QSTR_mkdir,
    MP_QSTR__chunk,
    MP_QSTR_readinto,
    MP_QSTR__check_exists,
    MP_QSTR_binascii,
    MP_QSTR_hashlib,
    MP_QSTR_rb,
    MP_QSTR_sha256,
    MP_QSTR_update,
    MP_QSTR_hexlify,
    MP_QSTR_digest,
    MP_QSTR_utf_hyphen_8,
    MP_QSTR__rewrite_url,
    MP_QSTR_HEAD,
    MP_QSTR_startswith,
    MP_QSTR_github_colon_,
    MP_QSTR_join,
    MP_QSTR_gitlab_colon_,
    MP_QSTR__slash__hyphen__slash_raw_slash_,
    MP_QSTR__download_file,
    MP_QSTR_get,
    MP_QSTR_status_code,
    MP_QSTR_Error,
    MP_QSTR_requesting,
    MP_QSTR_Copying_colon_,
    MP_QSTR_wb,
    MP_QSTR_raw,
    MP_QSTR_write,
    MP_QSTR_close,
    MP_QSTR__install_json,
    MP_QSTR_json,
    MP_QSTR_hashes,
    MP_QSTR_Exists_colon_,
    MP_QSTR_format,
    MP_QSTR_rpartition,
    MP_QSTR_urls,
    MP_QSTR__brace_open__brace_close__slash__brace_open__brace_close_,
    MP_QSTR_deps,
    MP_QSTR__install_package,
    MP_QSTR_endswith,
    MP_QSTR__dot_py,
    MP_QSTR__dot_mpy,
    MP_QSTR_rsplit,
    MP_QSTR__dot_json,
    MP_QSTR_latest,
    MP_QSTR_implementation,
    MP_QSTR__mpy,
    MP_QSTR_py,
    MP_QSTR_install,
    MP_QSTR_path,
    MP_QSTR__slash_rom,
    MP_QSTR__slash_lib,
    MP_QSTR_rstrip,
    MP_QSTR_Done,
    MP_QSTR__lt_genexpr_gt_,
    MP_QSTR__CHUNK_SIZE,
    MP_QSTR_allowed_mip_url_prefixes,
    MP_QSTR___version__,
    MP_QSTR_len,
    MP_QSTR_src,
    MP_QSTR_dest,
    MP_QSTR_memoryview,
    MP_QSTR_bytearray,
    MP_QSTR_short_hash,
    MP_QSTR_open,
    MP_QSTR_str,
    MP_QSTR_url,
    MP_QSTR_branch,
    MP_QSTR_print,
    MP_QSTR_package_json_url,
    MP_QSTR_index,
    MP_QSTR_target,
    MP_QSTR_version,
    MP_QSTR_mpy,
    MP_QSTR_any,
    MP_QSTR_package,
    MP_QSTR_hasattr,
    MP_QSTR__star_,
};

// constants
static const mp_rom_obj_tuple_t const_obj_mip___init___0 = {{&mp_type_tuple}, 4, {
    MP_ROM_QSTR(MP_QSTR_http_colon__slash__slash_),
    MP_ROM_QSTR(MP_QSTR_https_colon__slash__slash_),
    MP_ROM_QSTR(MP_QSTR_github_colon_),
    MP_ROM_QSTR(MP_QSTR_gitlab_colon_),
}};
static const mp_obj_str_t const_obj_mip___init___1 = {{&mp_type_str}, 18723, 34, (const byte*)"\x68\x74\x74\x70\x73\x3a\x2f\x2f\x72\x61\x77\x2e\x67\x69\x74\x68\x75\x62\x75\x73\x65\x72\x63\x6f\x6e\x74\x65\x6e\x74\x2e\x63\x6f\x6d\x2f"};
static const mp_obj_str_t const_obj_mip___init___9 = {{&mp_type_str}, 17480, 32, (const byte*)"\x49\x6e\x73\x74\x61\x6c\x6c\x69\x6e\x67\x20\x7b\x7d\x20\x28\x7b\x7d\x29\x20\x66\x72\x6f\x6d\x20\x7b\x7d\x20\x74\x6f\x20\x7b\x7d"};
static const mp_obj_str_t const_obj_mip___init___11 = {{&mp_type_str}, 43215, 34, (const byte*)"\x55\x6e\x61\x62\x6c\x65\x20\x74\x6f\x20\x66\x69\x6e\x64\x20\x6c\x69\x62\x20\x64\x69\x72\x20\x69\x6e\x20\x73\x79\x73\x2e\x70\x61\x74\x68"};
static const mp_obj_str_t const_obj_mip___init___12 = {{&mp_type_str}, 61939, 29, (const byte*)"\x68\x74\x74\x70\x73\x3a\x2f\x2f\x6d\x69\x63\x72\x6f\x70\x79\x74\x68\x6f\x6e\x2e\x6f\x72\x67\x2f\x70\x69\x2f\x76\x32"};
static const mp_obj_str_t const_obj_mip___init___13 = {{&mp_type_str}, 57771, 34, (const byte*)"\x50\x61\x63\x6b\x61\x67\x65\x20\x6d\x61\x79\x20\x62\x65\x20\x70\x61\x72\x74\x69\x61\x6c\x6c\x79\x20\x69\x6e\x73\x74\x61\x6c\x6c\x65\x64"};

// constant table
static const mp_rom_obj_t const_obj_table_data_mip___init__[14] = {
    MP_ROM_PTR(&const_obj_mip___init___0),
    MP_ROM_PTR(&const_obj_mip___init___1),
    MP_ROM_QSTR(MP_QSTR_https_colon__slash__slash_gitlab_dot_com_slash_),
    MP_ROM_QSTR(MP_QSTR_Package_space_not_space_found_colon_),
    MP_ROM_QSTR(MP_QSTR__brace_open__brace_close__slash_file_slash__brace_open__brace_close__slash__brace_open__brace_close_),
    MP_ROM_QSTR(MP_QSTR_File_space_not_space_found_colon__space__brace_open__brace_close__space__brace_open__brace_close_),
    MP_ROM_QSTR(MP_QSTR_Downloading_space__brace_open__brace_close__space_to_space__brace_open__brace_close_),
    MP_ROM_QSTR(MP_QSTR_package_dot_json),
    MP_ROM_QSTR(MP_QSTR_Installing_space__brace_open__brace_close__space_to_space__brace_open__brace_close_),
    MP_ROM_PTR(&const_obj_mip___init___9),
    MP_ROM_QSTR(MP_QSTR__brace_open__brace_close__slash_package_slash__brace_open__brace_close__slash__brace_open__brace_close__slash__brace_open__brace_close__dot_json),
    MP_ROM_PTR(&const_obj_mip___init___11),
    MP_ROM_PTR(&const_obj_mip___init___12),
    MP_ROM_PTR(&const_obj_mip___init___13),
};

static const mp_frozen_module_t frozen_module_mip___init__ = {
    .constants = {
        .qstr_table = (qstr_short_t *)&const_qstr_table_data_mip___init__,
        .obj_table = (mp_obj_t *)&const_obj_table_data_mip___init__,
    },
    .proto_fun = &proto_fun_mip___init____lt_module_gt_,
};

////////////////////////////////////////////////////////////////////////////////
// frozen module mip___main__
// - original source file: /Users/gadgetoid/Development/micropython-web/picovector/ports/sokol/build/frozen_mpy/mip/__main__.mpy
// - frozen file name: mip/__main__.py
// - .mpy header: 4d:06:00:1f

// frozen bytecode for file mip/__main__.py, scope mip___main____lt_module_gt_
static const byte fun_data_mip___main____lt_module_gt_[81] = {
    0x20,0x14, // prelude
    0x01, // names: <module>
    0x60,0x26,0x66,0x84,0x22,0x2c,0x2b,0x47,0x71, // code info
    0x80, // LOAD_CONST_SMALL_INT 0
    0x51, // LOAD_CONST_NONE
    0x1b,0x02, // IMPORT_NAME 'argparse'
    0x16,0x02, // STORE_NAME 'argparse'
    0x80, // LOAD_CONST_SMALL_INT 0
    0x51, // LOAD_CONST_NONE
    0x1b,0x03, // IMPORT_NAME 'sys'
    0x16,0x03, // STORE_NAME 'sys'
    0x32,0x00, // MAKE_FUNCTION 0
    0x16,0x08, // STORE_NAME 'do_install'
    0x11,0x1f, // LOAD_NAME 'len'
    0x11,0x03, // LOAD_NAME 'sys'
    0x13,0x04, // LOAD_ATTR 'argv'
    0x34,0x01, // CALL_FUNCTION 1
    0x82, // LOAD_CONST_SMALL_INT 2
    0xdb, // BINARY_OP 4 __ge__
    0x44,0x63, // POP_JUMP_IF_FALSE 35
    0x11,0x03, // LOAD_NAME 'sys'
    0x13,0x04, // LOAD_ATTR 'argv'
    0x81, // LOAD_CONST_SMALL_INT 1
    0x55, // LOAD_SUBSCR
    0x10,0x05, // LOAD_CONST_STRING 'install'
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x47, // POP_JUMP_IF_FALSE 7
    0x11,0x08, // LOAD_NAME 'do_install'
    0x34,0x00, // CALL_FUNCTION 0
    0x59, // POP_TOP
    0x42,0x51, // JUMP 17
    0x11,0x20, // LOAD_NAME 'print'
    0x23,0x00, // LOAD_CONST_OBJ 0
    0x14,0x06, // LOAD_METHOD 'format'
    0x11,0x03, // LOAD_NAME 'sys'
    0x13,0x04, // LOAD_ATTR 'argv'
    0x81, // LOAD_CONST_SMALL_INT 1
    0x55, // LOAD_SUBSCR
    0x36,0x01, // CALL_METHOD 1
    0x34,0x01, // CALL_FUNCTION 1
    0x59, // POP_TOP
    0x10,0x07, // LOAD_CONST_STRING '0.1.0'
    0x16,0x21, // STORE_NAME '__version__'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
// child of mip___main____lt_module_gt_
// frozen bytecode for file mip/__main__.py, scope mip___main___do_install
static const byte fun_data_mip___main___do_install[180] = {
    0x70,0x26, // prelude
    0x08, // names: do_install
    0x80,0x08,0x27,0x69,0x46,0x69,0x46,0x6b,0x46,0x6b,0x46,0x2d,0x52,0x4b,0x27,0x22,0x26,0x2b, // code info
    0x12,0x02, // LOAD_GLOBAL 'argparse'
    0x14,0x09, // LOAD_METHOD 'ArgumentParser'
    0x36,0x00, // CALL_METHOD 0
    0xc0, // STORE_FAST 0
    0xb0, // LOAD_FAST 0
    0x14,0x0a, // LOAD_METHOD 'add_argument'
    0x10,0x0b, // LOAD_CONST_STRING '-t'
    0x10,0x0c, // LOAD_CONST_STRING '--target'
    0x10,0x0d, // LOAD_CONST_STRING 'help'
    0x23,0x01, // LOAD_CONST_OBJ 1
    0x36,0x82,0x02, // CALL_METHOD 258
    0x59, // POP_TOP
    0xb0, // LOAD_FAST 0
    0x14,0x0a, // LOAD_METHOD 'add_argument'
    0x10,0x0e, // LOAD_CONST_STRING '-i'
    0x10,0x0f, // LOAD_CONST_STRING '--index'
    0x10,0x0d, // LOAD_CONST_STRING 'help'
    0x23,0x02, // LOAD_CONST_OBJ 2
    0x36,0x82,0x02, // CALL_METHOD 258
    0x59, // POP_TOP
    0xb0, // LOAD_FAST 0
    0x14,0x0a, // LOAD_METHOD 'add_argument'
    0x10,0x10, // LOAD_CONST_STRING '--mpy'
    0x10,0x11, // LOAD_CONST_STRING 'action'
    0x10,0x12, // LOAD_CONST_STRING 'store_true'
    0x10,0x0d, // LOAD_CONST_STRING 'help'
    0x23,0x03, // LOAD_CONST_OBJ 3
    0x36,0x84,0x01, // CALL_METHOD 513
    0x59, // POP_TOP
    0xb0, // LOAD_FAST 0
    0x14,0x0a, // LOAD_METHOD 'add_argument'
    0x10,0x13, // LOAD_CONST_STRING '--no-mpy'
    0x10,0x11, // LOAD_CONST_STRING 'action'
    0x10,0x12, // LOAD_CONST_STRING 'store_true'
    0x10,0x0d, // LOAD_CONST_STRING 'help'
    0x23,0x04, // LOAD_CONST_OBJ 4
    0x36,0x84,0x01, // CALL_METHOD 513
    0x59, // POP_TOP
    0xb0, // LOAD_FAST 0
    0x14,0x0a, // LOAD_METHOD 'add_argument'
    0x10,0x14, // LOAD_CONST_STRING 'package'
    0x10,0x15, // LOAD_CONST_STRING 'nargs'
    0x10,0x16, // LOAD_CONST_STRING '+'
    0x36,0x82,0x01, // CALL_METHOD 257
    0x59, // POP_TOP
    0xb0, // LOAD_FAST 0
    0x14,0x17, // LOAD_METHOD 'parse_args'
    0x10,0x18, // LOAD_CONST_STRING 'args'
    0x12,0x03, // LOAD_GLOBAL 'sys'
    0x13,0x04, // LOAD_ATTR 'argv'
    0x82, // LOAD_CONST_SMALL_INT 2
    0x51, // LOAD_CONST_NONE
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0x36,0x82,0x00, // CALL_METHOD 256
    0xc1, // STORE_FAST 1
    0x81, // LOAD_CONST_SMALL_INT 1
    0x10,0x05, // LOAD_CONST_STRING 'install'
    0x2a,0x01, // BUILD_TUPLE 1
    0x1b,0x19, // IMPORT_NAME ''
    0x1c,0x05, // IMPORT_FROM 'install'
    0xc2, // STORE_FAST 2
    0x59, // POP_TOP
    0xb1, // LOAD_FAST 1
    0x13,0x14, // LOAD_ATTR 'package'
    0x5f, // GET_ITER_STACK
    0x4b,0x26, // FOR_ITER 38
    0xc3, // STORE_FAST 3
    0x51, // LOAD_CONST_NONE
    0xc4, // STORE_FAST 4
    0x10,0x1a, // LOAD_CONST_STRING '@'
    0xb3, // LOAD_FAST 3
    0xdd, // BINARY_OP 6 <in>
    0x44,0x4b, // POP_JUMP_IF_FALSE 11
    0xb3, // LOAD_FAST 3
    0x14,0x1b, // LOAD_METHOD 'split'
    0x10,0x1a, // LOAD_CONST_STRING '@'
    0x36,0x01, // CALL_METHOD 1
    0x30,0x02, // UNPACK_SEQUENCE 2
    0xc3, // STORE_FAST 3
    0xc4, // STORE_FAST 4
    0xb2, // LOAD_FAST 2
    0xb3, // LOAD_FAST 3
    0xb1, // LOAD_FAST 1
    0x13,0x1c, // LOAD_ATTR 'index'
    0xb1, // LOAD_FAST 1
    0x13,0x1d, // LOAD_ATTR 'target'
    0xb4, // LOAD_FAST 4
    0xb1, // LOAD_FAST 1
    0x13,0x1e, // LOAD_ATTR 'no_mpy'
    0xd3, // UNARY_OP 3 <not>
    0x34,0x05, // CALL_FUNCTION 5
    0x59, // POP_TOP
    0x42,0x18, // JUMP -40
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_mip___main___do_install = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_mip___main___do_install,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 180,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 15,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 8,
        .line_info = fun_data_mip___main___do_install + 3,
        .line_info_top = fun_data_mip___main___do_install + 21,
        .opcodes = fun_data_mip___main___do_install + 21,
    },
    #endif
    #endif
};
#else
#define proto_fun_mip___main___do_install fun_data_mip___main___do_install[0]
#endif

static const mp_raw_code_t *const children_mip___main____lt_module_gt_[] = {
    (const mp_raw_code_t *)&proto_fun_mip___main___do_install,
};

static const mp_raw_code_truncated_t proto_fun_mip___main____lt_module_gt_ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_mip___main____lt_module_gt_,
    .children = (void *)&children_mip___main____lt_module_gt_,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 81,
    .n_children = 1,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 1,
        .line_info = fun_data_mip___main____lt_module_gt_ + 3,
        .line_info_top = fun_data_mip___main____lt_module_gt_ + 12,
        .opcodes = fun_data_mip___main____lt_module_gt_ + 12,
    },
    #endif
    #endif
};

static const qstr_short_t const_qstr_table_data_mip___main__[34] = {
    MP_QSTR_mip_slash___main___dot_py,
    MP_QSTR__lt_module_gt_,
    MP_QSTR_argparse,
    MP_QSTR_sys,
    MP_QSTR_argv,
    MP_QSTR_install,
    MP_QSTR_format,
    MP_QSTR_0_dot_1_dot_0,
    MP_QSTR_do_install,
    MP_QSTR_ArgumentParser,
    MP_QSTR_add_argument,
    MP_QSTR__hyphen_t,
    MP_QSTR__hyphen__hyphen_target,
    MP_QSTR_help,
    MP_QSTR__hyphen_i,
    MP_QSTR__hyphen__hyphen_index,
    MP_QSTR__hyphen__hyphen_mpy,
    MP_QSTR_action,
    MP_QSTR_store_true,
    MP_QSTR__hyphen__hyphen_no_hyphen_mpy,
    MP_QSTR_package,
    MP_QSTR_nargs,
    MP_QSTR__plus_,
    MP_QSTR_parse_args,
    MP_QSTR_args,
    MP_QSTR_,
    MP_QSTR__at_sign_,
    MP_QSTR_split,
    MP_QSTR_index,
    MP_QSTR_target,
    MP_QSTR_no_mpy,
    MP_QSTR_len,
    MP_QSTR_print,
    MP_QSTR___version__,
};

// constants
static const mp_obj_str_t const_obj_mip___main___0 = {{&mp_type_str}, 9058, 25, (const byte*)"\x6d\x69\x70\x3a\x20\x55\x6e\x6b\x6e\x6f\x77\x6e\x20\x63\x6f\x6d\x6d\x61\x6e\x64\x20\x22\x7b\x7d\x22"};
static const mp_obj_str_t const_obj_mip___main___1 = {{&mp_type_str}, 27229, 28, (const byte*)"\x44\x69\x72\x65\x63\x74\x6f\x72\x79\x20\x74\x6f\x20\x73\x74\x61\x72\x74\x20\x64\x69\x73\x63\x6f\x76\x65\x72\x79"};
static const mp_obj_str_t const_obj_mip___main___2 = {{&mp_type_str}, 3750, 27, (const byte*)"\x50\x61\x74\x74\x65\x72\x6e\x20\x74\x6f\x20\x6d\x61\x74\x63\x68\x20\x74\x65\x73\x74\x20\x66\x69\x6c\x65\x73"};
static const mp_obj_str_t const_obj_mip___main___3 = {{&mp_type_str}, 62243, 41, (const byte*)"\x64\x6f\x77\x6e\x6c\x6f\x61\x64\x20\x61\x73\x20\x63\x6f\x6d\x70\x69\x6c\x65\x64\x20\x2e\x6d\x70\x79\x20\x66\x69\x6c\x65\x73\x20\x28\x64\x65\x66\x61\x75\x6c\x74\x29"};
static const mp_obj_str_t const_obj_mip___main___4 = {{&mp_type_str}, 13868, 28, (const byte*)"\x64\x6f\x77\x6e\x6c\x6f\x61\x64\x20\x61\x73\x20\x2e\x70\x79\x20\x73\x6f\x75\x72\x63\x65\x20\x66\x69\x6c\x65\x73"};

// constant table
static const mp_rom_obj_t const_obj_table_data_mip___main__[5] = {
    MP_ROM_PTR(&const_obj_mip___main___0),
    MP_ROM_PTR(&const_obj_mip___main___1),
    MP_ROM_PTR(&const_obj_mip___main___2),
    MP_ROM_PTR(&const_obj_mip___main___3),
    MP_ROM_PTR(&const_obj_mip___main___4),
};

static const mp_frozen_module_t frozen_module_mip___main__ = {
    .constants = {
        .qstr_table = (qstr_short_t *)&const_qstr_table_data_mip___main__,
        .obj_table = (mp_obj_t *)&const_obj_table_data_mip___main__,
    },
    .proto_fun = &proto_fun_mip___main____lt_module_gt_,
};

////////////////////////////////////////////////////////////////////////////////
// frozen module ssl
// - original source file: /Users/gadgetoid/Development/micropython-web/picovector/ports/sokol/build/frozen_mpy/ssl.mpy
// - frozen file name: ssl.py
// - .mpy header: 4d:06:00:1f

// frozen bytecode for file ssl.py, scope ssl__lt_module_gt_
static const byte fun_data_ssl__lt_module_gt_[47] = {
    0x30,0x02, // prelude
    0x01, // names: <module>
     // code info
    0x80, // LOAD_CONST_SMALL_INT 0
    0x51, // LOAD_CONST_NONE
    0x1b,0x02, // IMPORT_NAME 'tls'
    0x16,0x02, // STORE_NAME 'tls'
    0x80, // LOAD_CONST_SMALL_INT 0
    0x10,0x03, // LOAD_CONST_STRING '*'
    0x2a,0x01, // BUILD_TUPLE 1
    0x1b,0x02, // IMPORT_NAME 'tls'
    0x69, // IMPORT_STAR
    0x54, // LOAD_BUILD_CLASS
    0x32,0x00, // MAKE_FUNCTION 0
    0x10,0x04, // LOAD_CONST_STRING 'SSLContext'
    0x34,0x02, // CALL_FUNCTION 2
    0x16,0x04, // STORE_NAME 'SSLContext'
    0x50, // LOAD_CONST_FALSE
    0x51, // LOAD_CONST_NONE
    0x51, // LOAD_CONST_NONE
    0x11,0x13, // LOAD_NAME 'CERT_NONE'
    0x51, // LOAD_CONST_NONE
    0x51, // LOAD_CONST_NONE
    0x52, // LOAD_CONST_TRUE
    0x2a,0x07, // BUILD_TUPLE 7
    0x53, // LOAD_NULL
    0x33,0x01, // MAKE_FUNCTION_DEFARGS 1
    0x16,0x07, // STORE_NAME 'wrap_socket'
    0x10,0x05, // LOAD_CONST_STRING '0.2.1'
    0x16,0x14, // STORE_NAME '__version__'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
// child of ssl__lt_module_gt_
// frozen bytecode for file ssl.py, scope ssl_SSLContext
static const byte fun_data_ssl_SSLContext[58] = {
    0x10,0x02, // prelude
    0x04, // names: SSLContext
     // code info
    0x11,0x15, // LOAD_NAME '__name__'
    0x16,0x16, // STORE_NAME '__module__'
    0x10,0x04, // LOAD_CONST_STRING 'SSLContext'
    0x16,0x17, // STORE_NAME '__qualname__'
    0x32,0x00, // MAKE_FUNCTION 0
    0x16,0x0f, // STORE_NAME '__init__'
    0x11,0x18, // LOAD_NAME 'property'
    0x32,0x01, // MAKE_FUNCTION 1
    0x34,0x01, // CALL_FUNCTION 1
    0x16,0x0b, // STORE_NAME 'verify_mode'
    0x11,0x0b, // LOAD_NAME 'verify_mode'
    0x13,0x06, // LOAD_ATTR 'setter'
    0x32,0x02, // MAKE_FUNCTION 2
    0x34,0x01, // CALL_FUNCTION 1
    0x16,0x0b, // STORE_NAME 'verify_mode'
    0x32,0x03, // MAKE_FUNCTION 3
    0x16,0x08, // STORE_NAME 'load_cert_chain'
    0x51, // LOAD_CONST_NONE
    0x51, // LOAD_CONST_NONE
    0x2a,0x02, // BUILD_TUPLE 2
    0x53, // LOAD_NULL
    0x33,0x04, // MAKE_FUNCTION_DEFARGS 4
    0x16,0x09, // STORE_NAME 'load_verify_locations'
    0x50, // LOAD_CONST_FALSE
    0x52, // LOAD_CONST_TRUE
    0x51, // LOAD_CONST_NONE
    0x2a,0x03, // BUILD_TUPLE 3
    0x53, // LOAD_NULL
    0x33,0x05, // MAKE_FUNCTION_DEFARGS 5
    0x16,0x07, // STORE_NAME 'wrap_socket'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
// child of ssl_SSLContext
// frozen bytecode for file ssl.py, scope ssl_SSLContext___init__
static const byte fun_data_ssl_SSLContext___init__[27] = {
    0xa9,0x80,0x80,0x40,0x04, // prelude
    0x0f,0x20, // names: __init__, self
     // code info
    0x12,0x02, // LOAD_GLOBAL 'tls'
    0x14,0x04, // LOAD_METHOD 'SSLContext'
    0xb1, // LOAD_FAST 1
    0x81, // LOAD_CONST_SMALL_INT 1
    0x37,0x01, // CALL_METHOD_VAR_KW 1
    0xb0, // LOAD_FAST 0
    0x18,0x10, // STORE_ATTR '_context'
    0x12,0x13, // LOAD_GLOBAL 'CERT_NONE'
    0xb0, // LOAD_FAST 0
    0x13,0x10, // LOAD_ATTR '_context'
    0x18,0x0b, // STORE_ATTR 'verify_mode'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_ssl_SSLContext___init__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_ssl_SSLContext___init__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 27,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 6,
        .n_exc_stack = 0,
        .scope_flags = 4,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 15,
        .line_info = fun_data_ssl_SSLContext___init__ + 7,
        .line_info_top = fun_data_ssl_SSLContext___init__ + 7,
        .opcodes = fun_data_ssl_SSLContext___init__ + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_ssl_SSLContext___init__ fun_data_ssl_SSLContext___init__[0]
#endif

// child of ssl_SSLContext
// frozen bytecode for file ssl.py, scope ssl_SSLContext_verify_mode
static const byte fun_data_ssl_SSLContext_verify_mode[10] = {
    0x09,0x04, // prelude
    0x0b,0x20, // names: verify_mode, self
     // code info
    0xb0, // LOAD_FAST 0
    0x13,0x10, // LOAD_ATTR '_context'
    0x13,0x0b, // LOAD_ATTR 'verify_mode'
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_ssl_SSLContext_verify_mode = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_ssl_SSLContext_verify_mode,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 10,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 2,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 11,
        .line_info = fun_data_ssl_SSLContext_verify_mode + 4,
        .line_info_top = fun_data_ssl_SSLContext_verify_mode + 4,
        .opcodes = fun_data_ssl_SSLContext_verify_mode + 4,
    },
    #endif
    #endif
};
#else
#define proto_fun_ssl_SSLContext_verify_mode fun_data_ssl_SSLContext_verify_mode[0]
#endif

// child of ssl_SSLContext
// frozen bytecode for file ssl.py, scope ssl_SSLContext_verify_mode2
static const byte fun_data_ssl_SSLContext_verify_mode2[13] = {
    0x1a,0x06, // prelude
    0x0b,0x20,0x21, // names: verify_mode, self, val
     // code info
    0xb1, // LOAD_FAST 1
    0xb0, // LOAD_FAST 0
    0x13,0x10, // LOAD_ATTR '_context'
    0x18,0x0b, // STORE_ATTR 'verify_mode'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_ssl_SSLContext_verify_mode2 = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_ssl_SSLContext_verify_mode2,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 13,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 11,
        .line_info = fun_data_ssl_SSLContext_verify_mode2 + 5,
        .line_info_top = fun_data_ssl_SSLContext_verify_mode2 + 5,
        .opcodes = fun_data_ssl_SSLContext_verify_mode2 + 5,
    },
    #endif
    #endif
};
#else
#define proto_fun_ssl_SSLContext_verify_mode2 fun_data_ssl_SSLContext_verify_mode2[0]
#endif

// child of ssl_SSLContext
// frozen bytecode for file ssl.py, scope ssl_SSLContext_load_cert_chain
static const byte fun_data_ssl_SSLContext_load_cert_chain[74] = {
    0x47,0x08, // prelude
    0x08,0x20,0x22,0x23, // names: load_cert_chain, self, certfile, keyfile
     // code info
    0x12,0x24, // LOAD_GLOBAL 'isinstance'
    0xb1, // LOAD_FAST 1
    0x12,0x25, // LOAD_GLOBAL 'str'
    0x34,0x02, // CALL_FUNCTION 2
    0x44,0x53, // POP_JUMP_IF_FALSE 19
    0x12,0x26, // LOAD_GLOBAL 'open'
    0xb1, // LOAD_FAST 1
    0x10,0x11, // LOAD_CONST_STRING 'rb'
    0x34,0x02, // CALL_FUNCTION 2
    0x47,0x08, // SETUP_WITH 8
    0xc3, // STORE_FAST 3
    0xb3, // LOAD_FAST 3
    0x14,0x12, // LOAD_METHOD 'read'
    0x36,0x00, // CALL_METHOD 0
    0xc1, // STORE_FAST 1
    0x51, // LOAD_CONST_NONE
    0x5c, // WITH_CLEANUP
    0x5d, // END_FINALLY
    0x12,0x24, // LOAD_GLOBAL 'isinstance'
    0xb2, // LOAD_FAST 2
    0x12,0x25, // LOAD_GLOBAL 'str'
    0x34,0x02, // CALL_FUNCTION 2
    0x44,0x53, // POP_JUMP_IF_FALSE 19
    0x12,0x26, // LOAD_GLOBAL 'open'
    0xb2, // LOAD_FAST 2
    0x10,0x11, // LOAD_CONST_STRING 'rb'
    0x34,0x02, // CALL_FUNCTION 2
    0x47,0x08, // SETUP_WITH 8
    0xc3, // STORE_FAST 3
    0xb3, // LOAD_FAST 3
    0x14,0x12, // LOAD_METHOD 'read'
    0x36,0x00, // CALL_METHOD 0
    0xc2, // STORE_FAST 2
    0x51, // LOAD_CONST_NONE
    0x5c, // WITH_CLEANUP
    0x5d, // END_FINALLY
    0xb0, // LOAD_FAST 0
    0x13,0x10, // LOAD_ATTR '_context'
    0x14,0x08, // LOAD_METHOD 'load_cert_chain'
    0xb1, // LOAD_FAST 1
    0xb2, // LOAD_FAST 2
    0x36,0x02, // CALL_METHOD 2
    0x59, // POP_TOP
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_ssl_SSLContext_load_cert_chain = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_ssl_SSLContext_load_cert_chain,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 74,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 9,
        .n_exc_stack = 1,
        .scope_flags = 0,
        .n_pos_args = 3,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 8,
        .line_info = fun_data_ssl_SSLContext_load_cert_chain + 6,
        .line_info_top = fun_data_ssl_SSLContext_load_cert_chain + 6,
        .opcodes = fun_data_ssl_SSLContext_load_cert_chain + 6,
    },
    #endif
    #endif
};
#else
#define proto_fun_ssl_SSLContext_load_cert_chain fun_data_ssl_SSLContext_load_cert_chain[0]
#endif

// child of ssl_SSLContext
// frozen bytecode for file ssl.py, scope ssl_SSLContext_load_verify_locations
static const byte fun_data_ssl_SSLContext_load_verify_locations[41] = {
    0xc7,0x80,0x01,0x08, // prelude
    0x09,0x20,0x27,0x0a, // names: load_verify_locations, self, cafile, cadata
     // code info
    0xb1, // LOAD_FAST 1
    0x44,0x53, // POP_JUMP_IF_FALSE 19
    0x12,0x26, // LOAD_GLOBAL 'open'
    0xb1, // LOAD_FAST 1
    0x10,0x11, // LOAD_CONST_STRING 'rb'
    0x34,0x02, // CALL_FUNCTION 2
    0x47,0x08, // SETUP_WITH 8
    0xc3, // STORE_FAST 3
    0xb3, // LOAD_FAST 3
    0x14,0x12, // LOAD_METHOD 'read'
    0x36,0x00, // CALL_METHOD 0
    0xc2, // STORE_FAST 2
    0x51, // LOAD_CONST_NONE
    0x5c, // WITH_CLEANUP
    0x5d, // END_FINALLY
    0xb0, // LOAD_FAST 0
    0x13,0x10, // LOAD_ATTR '_context'
    0x14,0x09, // LOAD_METHOD 'load_verify_locations'
    0xb2, // LOAD_FAST 2
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_ssl_SSLContext_load_verify_locations = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_ssl_SSLContext_load_verify_locations,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 41,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 9,
        .n_exc_stack = 1,
        .scope_flags = 0,
        .n_pos_args = 3,
        .n_kwonly_args = 0,
        .n_def_pos_args = 2,
        .qstr_block_name_idx = 9,
        .line_info = fun_data_ssl_SSLContext_load_verify_locations + 8,
        .line_info_top = fun_data_ssl_SSLContext_load_verify_locations + 8,
        .opcodes = fun_data_ssl_SSLContext_load_verify_locations + 8,
    },
    #endif
    #endif
};
#else
#define proto_fun_ssl_SSLContext_load_verify_locations fun_data_ssl_SSLContext_load_verify_locations[0]
#endif

// child of ssl_SSLContext
// frozen bytecode for file ssl.py, scope ssl_SSLContext_wrap_socket
static const byte fun_data_ssl_SSLContext_wrap_socket[29] = {
    0xe9,0x85,0x01,0x0c, // prelude
    0x07,0x20,0x19,0x0c,0x0d,0x0e, // names: wrap_socket, self, sock, server_side, do_handshake_on_connect, server_hostname
     // code info
    0xb0, // LOAD_FAST 0
    0x13,0x10, // LOAD_ATTR '_context'
    0x14,0x07, // LOAD_METHOD 'wrap_socket'
    0xb1, // LOAD_FAST 1
    0x10,0x0c, // LOAD_CONST_STRING 'server_side'
    0xb2, // LOAD_FAST 2
    0x10,0x0d, // LOAD_CONST_STRING 'do_handshake_on_connect'
    0xb3, // LOAD_FAST 3
    0x10,0x0e, // LOAD_CONST_STRING 'server_hostname'
    0xb4, // LOAD_FAST 4
    0x36,0x86,0x01, // CALL_METHOD 769
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_ssl_SSLContext_wrap_socket = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_ssl_SSLContext_wrap_socket,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 29,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 14,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 5,
        .n_kwonly_args = 0,
        .n_def_pos_args = 3,
        .qstr_block_name_idx = 7,
        .line_info = fun_data_ssl_SSLContext_wrap_socket + 10,
        .line_info_top = fun_data_ssl_SSLContext_wrap_socket + 10,
        .opcodes = fun_data_ssl_SSLContext_wrap_socket + 10,
    },
    #endif
    #endif
};
#else
#define proto_fun_ssl_SSLContext_wrap_socket fun_data_ssl_SSLContext_wrap_socket[0]
#endif

static const mp_raw_code_t *const children_ssl_SSLContext[] = {
    (const mp_raw_code_t *)&proto_fun_ssl_SSLContext___init__,
    (const mp_raw_code_t *)&proto_fun_ssl_SSLContext_verify_mode,
    (const mp_raw_code_t *)&proto_fun_ssl_SSLContext_verify_mode2,
    (const mp_raw_code_t *)&proto_fun_ssl_SSLContext_load_cert_chain,
    (const mp_raw_code_t *)&proto_fun_ssl_SSLContext_load_verify_locations,
    (const mp_raw_code_t *)&proto_fun_ssl_SSLContext_wrap_socket,
};

static const mp_raw_code_truncated_t proto_fun_ssl_SSLContext = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_ssl_SSLContext,
    .children = (void *)&children_ssl_SSLContext,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 58,
    .n_children = 6,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 4,
        .line_info = fun_data_ssl_SSLContext + 3,
        .line_info_top = fun_data_ssl_SSLContext + 3,
        .opcodes = fun_data_ssl_SSLContext + 3,
    },
    #endif
    #endif
};

// child of ssl__lt_module_gt_
// frozen bytecode for file ssl.py, scope ssl_wrap_socket
static const byte fun_data_ssl_wrap_socket[76] = {
    0x88,0x91,0x85,0x01,0x12, // prelude
    0x07,0x19,0x0c,0x1a,0x1b,0x1c,0x0a,0x0e,0x1d, // names: wrap_socket, sock, server_side, key, cert, cert_reqs, cadata, server_hostname, do_handshake
     // code info
    0x12,0x04, // LOAD_GLOBAL 'SSLContext'
    0xb1, // LOAD_FAST 1
    0x44,0x44, // POP_JUMP_IF_FALSE 4
    0x12,0x1e, // LOAD_GLOBAL 'PROTOCOL_TLS_SERVER'
    0x42,0x42, // JUMP 2
    0x12,0x1f, // LOAD_GLOBAL 'PROTOCOL_TLS_CLIENT'
    0x34,0x01, // CALL_FUNCTION 1
    0xc8, // STORE_FAST 8
    0xb3, // LOAD_FAST 3
    0x43,0x43, // POP_JUMP_IF_TRUE 3
    0xb2, // LOAD_FAST 2
    0x44,0x48, // POP_JUMP_IF_FALSE 8
    0xb8, // LOAD_FAST 8
    0x14,0x08, // LOAD_METHOD 'load_cert_chain'
    0xb3, // LOAD_FAST 3
    0xb2, // LOAD_FAST 2
    0x36,0x02, // CALL_METHOD 2
    0x59, // POP_TOP
    0xb5, // LOAD_FAST 5
    0x44,0x4a, // POP_JUMP_IF_FALSE 10
    0xb8, // LOAD_FAST 8
    0x14,0x09, // LOAD_METHOD 'load_verify_locations'
    0x10,0x0a, // LOAD_CONST_STRING 'cadata'
    0xb5, // LOAD_FAST 5
    0x36,0x82,0x00, // CALL_METHOD 256
    0x59, // POP_TOP
    0xb4, // LOAD_FAST 4
    0xb8, // LOAD_FAST 8
    0x18,0x0b, // STORE_ATTR 'verify_mode'
    0xb8, // LOAD_FAST 8
    0x14,0x07, // LOAD_METHOD 'wrap_socket'
    0xb0, // LOAD_FAST 0
    0x10,0x0c, // LOAD_CONST_STRING 'server_side'
    0xb1, // LOAD_FAST 1
    0x10,0x0d, // LOAD_CONST_STRING 'do_handshake_on_connect'
    0xb7, // LOAD_FAST 7
    0x10,0x0e, // LOAD_CONST_STRING 'server_hostname'
    0xb6, // LOAD_FAST 6
    0x36,0x86,0x01, // CALL_METHOD 769
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_ssl_wrap_socket = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_ssl_wrap_socket,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 76,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 18,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 8,
        .n_kwonly_args = 0,
        .n_def_pos_args = 7,
        .qstr_block_name_idx = 7,
        .line_info = fun_data_ssl_wrap_socket + 14,
        .line_info_top = fun_data_ssl_wrap_socket + 14,
        .opcodes = fun_data_ssl_wrap_socket + 14,
    },
    #endif
    #endif
};
#else
#define proto_fun_ssl_wrap_socket fun_data_ssl_wrap_socket[0]
#endif

static const mp_raw_code_t *const children_ssl__lt_module_gt_[] = {
    (const mp_raw_code_t *)&proto_fun_ssl_SSLContext,
    (const mp_raw_code_t *)&proto_fun_ssl_wrap_socket,
};

static const mp_raw_code_truncated_t proto_fun_ssl__lt_module_gt_ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_ssl__lt_module_gt_,
    .children = (void *)&children_ssl__lt_module_gt_,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 47,
    .n_children = 2,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 7,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 1,
        .line_info = fun_data_ssl__lt_module_gt_ + 3,
        .line_info_top = fun_data_ssl__lt_module_gt_ + 3,
        .opcodes = fun_data_ssl__lt_module_gt_ + 3,
    },
    #endif
    #endif
};

static const qstr_short_t const_qstr_table_data_ssl[40] = {
    MP_QSTR_ssl_dot_py,
    MP_QSTR__lt_module_gt_,
    MP_QSTR_tls,
    MP_QSTR__star_,
    MP_QSTR_SSLContext,
    MP_QSTR_0_dot_2_dot_1,
    MP_QSTR_setter,
    MP_QSTR_wrap_socket,
    MP_QSTR_load_cert_chain,
    MP_QSTR_load_verify_locations,
    MP_QSTR_cadata,
    MP_QSTR_verify_mode,
    MP_QSTR_server_side,
    MP_QSTR_do_handshake_on_connect,
    MP_QSTR_server_hostname,
    MP_QSTR___init__,
    MP_QSTR__context,
    MP_QSTR_rb,
    MP_QSTR_read,
    MP_QSTR_CERT_NONE,
    MP_QSTR___version__,
    MP_QSTR___name__,
    MP_QSTR___module__,
    MP_QSTR___qualname__,
    MP_QSTR_property,
    MP_QSTR_sock,
    MP_QSTR_key,
    MP_QSTR_cert,
    MP_QSTR_cert_reqs,
    MP_QSTR_do_handshake,
    MP_QSTR_PROTOCOL_TLS_SERVER,
    MP_QSTR_PROTOCOL_TLS_CLIENT,
    MP_QSTR_self,
    MP_QSTR_val,
    MP_QSTR_certfile,
    MP_QSTR_keyfile,
    MP_QSTR_isinstance,
    MP_QSTR_str,
    MP_QSTR_open,
    MP_QSTR_cafile,
};

static const mp_frozen_module_t frozen_module_ssl = {
    .constants = {
        .qstr_table = (qstr_short_t *)&const_qstr_table_data_ssl,
        .obj_table = NULL,
    },
    .proto_fun = &proto_fun_ssl__lt_module_gt_,
};

////////////////////////////////////////////////////////////////////////////////
// frozen module asyncio___init__
// - original source file: /Users/gadgetoid/Development/micropython-web/picovector/ports/sokol/build/frozen_mpy/asyncio/__init__.mpy
// - frozen file name: asyncio/__init__.py
// - .mpy header: 4d:06:00:1f

// frozen bytecode for file asyncio/__init__.py, scope asyncio___init____lt_module_gt_
static const byte fun_data_asyncio___init____lt_module_gt_[75] = {
    0x10,0x02, // prelude
    0x01, // names: <module>
     // code info
    0x81, // LOAD_CONST_SMALL_INT 1
    0x10,0x02, // LOAD_CONST_STRING '*'
    0x2a,0x01, // BUILD_TUPLE 1
    0x1b,0x03, // IMPORT_NAME 'core'
    0x69, // IMPORT_STAR
    0x23,0x00, // LOAD_CONST_OBJ 0
    0x16,0x0e, // STORE_NAME '__version__'
    0x2c,0x0a, // BUILD_MAP 10
    0x10,0x04, // LOAD_CONST_STRING 'funcs'
    0x10,0x05, // LOAD_CONST_STRING 'wait_for'
    0x62, // STORE_MAP
    0x10,0x04, // LOAD_CONST_STRING 'funcs'
    0x23,0x01, // LOAD_CONST_OBJ 1
    0x62, // STORE_MAP
    0x10,0x04, // LOAD_CONST_STRING 'funcs'
    0x10,0x06, // LOAD_CONST_STRING 'gather'
    0x62, // STORE_MAP
    0x10,0x07, // LOAD_CONST_STRING 'event'
    0x10,0x08, // LOAD_CONST_STRING 'Event'
    0x62, // STORE_MAP
    0x10,0x07, // LOAD_CONST_STRING 'event'
    0x23,0x02, // LOAD_CONST_OBJ 2
    0x62, // STORE_MAP
    0x10,0x09, // LOAD_CONST_STRING 'lock'
    0x10,0x0a, // LOAD_CONST_STRING 'Lock'
    0x62, // STORE_MAP
    0x10,0x0b, // LOAD_CONST_STRING 'stream'
    0x23,0x03, // LOAD_CONST_OBJ 3
    0x62, // STORE_MAP
    0x10,0x0b, // LOAD_CONST_STRING 'stream'
    0x23,0x04, // LOAD_CONST_OBJ 4
    0x62, // STORE_MAP
    0x10,0x0b, // LOAD_CONST_STRING 'stream'
    0x23,0x05, // LOAD_CONST_OBJ 5
    0x62, // STORE_MAP
    0x10,0x0b, // LOAD_CONST_STRING 'stream'
    0x23,0x06, // LOAD_CONST_OBJ 6
    0x62, // STORE_MAP
    0x16,0x0f, // STORE_NAME '_attrs'
    0x32,0x00, // MAKE_FUNCTION 0
    0x16,0x0c, // STORE_NAME '__getattr__'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
// child of asyncio___init____lt_module_gt_
// frozen bytecode for file asyncio/__init__.py, scope asyncio___init_____getattr__
static const byte fun_data_asyncio___init_____getattr__[48] = {
    0x49,0x04, // prelude
    0x0c,0x10, // names: __getattr__, attr
     // code info
    0x12,0x0f, // LOAD_GLOBAL '_attrs'
    0x14,0x0d, // LOAD_METHOD 'get'
    0xb0, // LOAD_FAST 0
    0x51, // LOAD_CONST_NONE
    0x36,0x02, // CALL_METHOD 2
    0xc1, // STORE_FAST 1
    0xb1, // LOAD_FAST 1
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0x44,0x46, // POP_JUMP_IF_FALSE 6
    0x12,0x11, // LOAD_GLOBAL 'AttributeError'
    0xb0, // LOAD_FAST 0
    0x34,0x01, // CALL_FUNCTION 1
    0x65, // RAISE_OBJ
    0x12,0x12, // LOAD_GLOBAL 'getattr'
    0x12,0x13, // LOAD_GLOBAL '__import__'
    0xb1, // LOAD_FAST 1
    0x51, // LOAD_CONST_NONE
    0x51, // LOAD_CONST_NONE
    0x52, // LOAD_CONST_TRUE
    0x81, // LOAD_CONST_SMALL_INT 1
    0x34,0x05, // CALL_FUNCTION 5
    0xb0, // LOAD_FAST 0
    0x34,0x02, // CALL_FUNCTION 2
    0xc2, // STORE_FAST 2
    0xb2, // LOAD_FAST 2
    0x12,0x14, // LOAD_GLOBAL 'globals'
    0x34,0x00, // CALL_FUNCTION 0
    0xb0, // LOAD_FAST 0
    0x56, // STORE_SUBSCR
    0xb2, // LOAD_FAST 2
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio___init_____getattr__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio___init_____getattr__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 48,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 10,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 12,
        .line_info = fun_data_asyncio___init_____getattr__ + 4,
        .line_info_top = fun_data_asyncio___init_____getattr__ + 4,
        .opcodes = fun_data_asyncio___init_____getattr__ + 4,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio___init_____getattr__ fun_data_asyncio___init_____getattr__[0]
#endif

static const mp_raw_code_t *const children_asyncio___init____lt_module_gt_[] = {
    (const mp_raw_code_t *)&proto_fun_asyncio___init_____getattr__,
};

static const mp_raw_code_truncated_t proto_fun_asyncio___init____lt_module_gt_ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio___init____lt_module_gt_,
    .children = (void *)&children_asyncio___init____lt_module_gt_,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 75,
    .n_children = 1,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 1,
        .line_info = fun_data_asyncio___init____lt_module_gt_ + 3,
        .line_info_top = fun_data_asyncio___init____lt_module_gt_ + 3,
        .opcodes = fun_data_asyncio___init____lt_module_gt_ + 3,
    },
    #endif
    #endif
};

static const qstr_short_t const_qstr_table_data_asyncio___init__[21] = {
    MP_QSTR_asyncio_slash___init___dot_py,
    MP_QSTR__lt_module_gt_,
    MP_QSTR__star_,
    MP_QSTR_core,
    MP_QSTR_funcs,
    MP_QSTR_wait_for,
    MP_QSTR_gather,
    MP_QSTR_event,
    MP_QSTR_Event,
    MP_QSTR_lock,
    MP_QSTR_Lock,
    MP_QSTR_stream,
    MP_QSTR___getattr__,
    MP_QSTR_get,
    MP_QSTR___version__,
    MP_QSTR__attrs,
    MP_QSTR_attr,
    MP_QSTR_AttributeError,
    MP_QSTR_getattr,
    MP_QSTR___import__,
    MP_QSTR_globals,
};

// constants
static const mp_rom_obj_tuple_t const_obj_asyncio___init___0 = {{&mp_type_tuple}, 3, {
    MP_ROM_INT(3),
    MP_ROM_INT(0),
    MP_ROM_INT(0),
}};

// constant table
static const mp_rom_obj_t const_obj_table_data_asyncio___init__[7] = {
    MP_ROM_PTR(&const_obj_asyncio___init___0),
    MP_ROM_QSTR(MP_QSTR_wait_for_ms),
    MP_ROM_QSTR(MP_QSTR_ThreadSafeFlag),
    MP_ROM_QSTR(MP_QSTR_open_connection),
    MP_ROM_QSTR(MP_QSTR_start_server),
    MP_ROM_QSTR(MP_QSTR_StreamReader),
    MP_ROM_QSTR(MP_QSTR_StreamWriter),
};

static const mp_frozen_module_t frozen_module_asyncio___init__ = {
    .constants = {
        .qstr_table = (qstr_short_t *)&const_qstr_table_data_asyncio___init__,
        .obj_table = (mp_obj_t *)&const_obj_table_data_asyncio___init__,
    },
    .proto_fun = &proto_fun_asyncio___init____lt_module_gt_,
};

////////////////////////////////////////////////////////////////////////////////
// frozen module asyncio_core
// - original source file: /Users/gadgetoid/Development/micropython-web/picovector/ports/sokol/build/frozen_mpy/asyncio/core.mpy
// - frozen file name: asyncio/core.py
// - .mpy header: 4d:06:00:1f

// frozen bytecode for file asyncio/core.py, scope asyncio_core__lt_module_gt_
static const byte fun_data_asyncio_core__lt_module_gt_[218] = {
    0x2c,0x02, // prelude
    0x01, // names: <module>
     // code info
    0x80, // LOAD_CONST_SMALL_INT 0
    0x10,0x02, // LOAD_CONST_STRING 'ticks_ms'
    0x10,0x03, // LOAD_CONST_STRING 'ticks_diff'
    0x10,0x04, // LOAD_CONST_STRING 'ticks_add'
    0x2a,0x03, // BUILD_TUPLE 3
    0x1b,0x05, // IMPORT_NAME 'time'
    0x1c,0x02, // IMPORT_FROM 'ticks_ms'
    0x16,0x49, // STORE_NAME 'ticks'
    0x1c,0x03, // IMPORT_FROM 'ticks_diff'
    0x16,0x03, // STORE_NAME 'ticks_diff'
    0x1c,0x04, // IMPORT_FROM 'ticks_add'
    0x16,0x04, // STORE_NAME 'ticks_add'
    0x59, // POP_TOP
    0x80, // LOAD_CONST_SMALL_INT 0
    0x51, // LOAD_CONST_NONE
    0x1b,0x06, // IMPORT_NAME 'sys'
    0x16,0x06, // STORE_NAME 'sys'
    0x80, // LOAD_CONST_SMALL_INT 0
    0x51, // LOAD_CONST_NONE
    0x1b,0x07, // IMPORT_NAME 'select'
    0x16,0x07, // STORE_NAME 'select'
    0x48,0x14, // SETUP_EXCEPT 20
    0x80, // LOAD_CONST_SMALL_INT 0
    0x10,0x08, // LOAD_CONST_STRING 'TaskQueue'
    0x10,0x09, // LOAD_CONST_STRING 'Task'
    0x2a,0x02, // BUILD_TUPLE 2
    0x1b,0x0a, // IMPORT_NAME '_asyncio'
    0x1c,0x08, // IMPORT_FROM 'TaskQueue'
    0x16,0x08, // STORE_NAME 'TaskQueue'
    0x1c,0x09, // IMPORT_FROM 'Task'
    0x16,0x09, // STORE_NAME 'Task'
    0x59, // POP_TOP
    0x4a,0x16, // POP_EXCEPT_JUMP 22
    0x59, // POP_TOP
    0x81, // LOAD_CONST_SMALL_INT 1
    0x10,0x08, // LOAD_CONST_STRING 'TaskQueue'
    0x10,0x09, // LOAD_CONST_STRING 'Task'
    0x2a,0x02, // BUILD_TUPLE 2
    0x1b,0x0b, // IMPORT_NAME 'task'
    0x1c,0x08, // IMPORT_FROM 'TaskQueue'
    0x16,0x08, // STORE_NAME 'TaskQueue'
    0x1c,0x09, // IMPORT_FROM 'Task'
    0x16,0x09, // STORE_NAME 'Task'
    0x59, // POP_TOP
    0x4a,0x01, // POP_EXCEPT_JUMP 1
    0x5d, // END_FINALLY
    0x54, // LOAD_BUILD_CLASS
    0x32,0x00, // MAKE_FUNCTION 0
    0x10,0x0c, // LOAD_CONST_STRING 'CancelledError'
    0x11,0x4a, // LOAD_NAME 'BaseException'
    0x34,0x03, // CALL_FUNCTION 3
    0x16,0x0c, // STORE_NAME 'CancelledError'
    0x54, // LOAD_BUILD_CLASS
    0x32,0x01, // MAKE_FUNCTION 1
    0x10,0x0d, // LOAD_CONST_STRING 'TimeoutError'
    0x11,0x4b, // LOAD_NAME 'Exception'
    0x34,0x03, // CALL_FUNCTION 3
    0x16,0x0d, // STORE_NAME 'TimeoutError'
    0x2c,0x03, // BUILD_MAP 3
    0x23,0x00, // LOAD_CONST_OBJ 0
    0x10,0x0e, // LOAD_CONST_STRING 'message'
    0x62, // STORE_MAP
    0x51, // LOAD_CONST_NONE
    0x10,0x0f, // LOAD_CONST_STRING 'exception'
    0x62, // STORE_MAP
    0x51, // LOAD_CONST_NONE
    0x10,0x10, // LOAD_CONST_STRING 'future'
    0x62, // STORE_MAP
    0x16,0x4c, // STORE_NAME '_exc_context'
    0x54, // LOAD_BUILD_CLASS
    0x32,0x02, // MAKE_FUNCTION 2
    0x10,0x11, // LOAD_CONST_STRING 'SingletonGenerator'
    0x34,0x02, // CALL_FUNCTION 2
    0x16,0x11, // STORE_NAME 'SingletonGenerator'
    0x11,0x11, // LOAD_NAME 'SingletonGenerator'
    0x34,0x00, // CALL_FUNCTION 0
    0x2a,0x01, // BUILD_TUPLE 1
    0x53, // LOAD_NULL
    0x33,0x03, // MAKE_FUNCTION_DEFARGS 3
    0x16,0x14, // STORE_NAME 'sleep_ms'
    0x32,0x04, // MAKE_FUNCTION 4
    0x16,0x16, // STORE_NAME 'sleep'
    0x54, // LOAD_BUILD_CLASS
    0x32,0x05, // MAKE_FUNCTION 5
    0x10,0x12, // LOAD_CONST_STRING 'IOQueue'
    0x34,0x02, // CALL_FUNCTION 2
    0x16,0x12, // STORE_NAME 'IOQueue'
    0x32,0x06, // MAKE_FUNCTION 6
    0x16,0x17, // STORE_NAME '_promote_to_task'
    0x32,0x07, // MAKE_FUNCTION 7
    0x16,0x18, // STORE_NAME 'create_task'
    0x51, // LOAD_CONST_NONE
    0x2a,0x01, // BUILD_TUPLE 1
    0x53, // LOAD_NULL
    0x33,0x08, // MAKE_FUNCTION_DEFARGS 8
    0x16,0x1b, // STORE_NAME 'run_until_complete'
    0x32,0x09, // MAKE_FUNCTION 9
    0x16,0x26, // STORE_NAME 'run'
    0x32,0x0a, // MAKE_FUNCTION 10
    0x16,0x27, // STORE_NAME '_stopper'
    0x51, // LOAD_CONST_NONE
    0x17,0x4d, // STORE_GLOBAL 'cur_task'
    0x51, // LOAD_CONST_NONE
    0x17,0x4e, // STORE_GLOBAL '_stop_task'
    0x54, // LOAD_BUILD_CLASS
    0x32,0x0b, // MAKE_FUNCTION 11
    0x10,0x13, // LOAD_CONST_STRING 'Loop'
    0x34,0x02, // CALL_FUNCTION 2
    0x16,0x13, // STORE_NAME 'Loop'
    0x80, // LOAD_CONST_SMALL_INT 0
    0x80, // LOAD_CONST_SMALL_INT 0
    0x2a,0x02, // BUILD_TUPLE 2
    0x53, // LOAD_NULL
    0x33,0x0c, // MAKE_FUNCTION_DEFARGS 12
    0x16,0x28, // STORE_NAME 'get_event_loop'
    0x32,0x0d, // MAKE_FUNCTION 13
    0x16,0x29, // STORE_NAME 'current_task'
    0x32,0x0e, // MAKE_FUNCTION 14
    0x16,0x2a, // STORE_NAME 'new_event_loop'
    0x11,0x2a, // LOAD_NAME 'new_event_loop'
    0x34,0x00, // CALL_FUNCTION 0
    0x59, // POP_TOP
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
// child of asyncio_core__lt_module_gt_
// frozen bytecode for file asyncio/core.py, scope asyncio_core_CancelledError
static const byte fun_data_asyncio_core_CancelledError[13] = {
    0x00,0x02, // prelude
    0x0c, // names: CancelledError
     // code info
    0x11,0x4f, // LOAD_NAME '__name__'
    0x16,0x50, // STORE_NAME '__module__'
    0x10,0x0c, // LOAD_CONST_STRING 'CancelledError'
    0x16,0x51, // STORE_NAME '__qualname__'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_core_CancelledError = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_core_CancelledError,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 13,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 1,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 12,
        .line_info = fun_data_asyncio_core_CancelledError + 3,
        .line_info_top = fun_data_asyncio_core_CancelledError + 3,
        .opcodes = fun_data_asyncio_core_CancelledError + 3,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_core_CancelledError fun_data_asyncio_core_CancelledError[0]
#endif

// child of asyncio_core__lt_module_gt_
// frozen bytecode for file asyncio/core.py, scope asyncio_core_TimeoutError
static const byte fun_data_asyncio_core_TimeoutError[13] = {
    0x00,0x02, // prelude
    0x0d, // names: TimeoutError
     // code info
    0x11,0x4f, // LOAD_NAME '__name__'
    0x16,0x50, // STORE_NAME '__module__'
    0x10,0x0d, // LOAD_CONST_STRING 'TimeoutError'
    0x16,0x51, // STORE_NAME '__qualname__'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_core_TimeoutError = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_core_TimeoutError,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 13,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 1,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 13,
        .line_info = fun_data_asyncio_core_TimeoutError + 3,
        .line_info_top = fun_data_asyncio_core_TimeoutError + 3,
        .opcodes = fun_data_asyncio_core_TimeoutError + 3,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_core_TimeoutError fun_data_asyncio_core_TimeoutError[0]
#endif

// child of asyncio_core__lt_module_gt_
// frozen bytecode for file asyncio/core.py, scope asyncio_core_SingletonGenerator
static const byte fun_data_asyncio_core_SingletonGenerator[25] = {
    0x00,0x02, // prelude
    0x11, // names: SingletonGenerator
     // code info
    0x11,0x4f, // LOAD_NAME '__name__'
    0x16,0x50, // STORE_NAME '__module__'
    0x10,0x11, // LOAD_CONST_STRING 'SingletonGenerator'
    0x16,0x51, // STORE_NAME '__qualname__'
    0x32,0x00, // MAKE_FUNCTION 0
    0x16,0x2b, // STORE_NAME '__init__'
    0x32,0x01, // MAKE_FUNCTION 1
    0x16,0x2d, // STORE_NAME '__iter__'
    0x32,0x02, // MAKE_FUNCTION 2
    0x16,0x2e, // STORE_NAME '__next__'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
// child of asyncio_core_SingletonGenerator
// frozen bytecode for file asyncio/core.py, scope asyncio_core_SingletonGenerator___init__
static const byte fun_data_asyncio_core_SingletonGenerator___init__[17] = {
    0x11,0x04, // prelude
    0x2b,0x63, // names: __init__, self
     // code info
    0x51, // LOAD_CONST_NONE
    0xb0, // LOAD_FAST 0
    0x18,0x15, // STORE_ATTR 'state'
    0x12,0x5d, // LOAD_GLOBAL 'StopIteration'
    0x34,0x00, // CALL_FUNCTION 0
    0xb0, // LOAD_FAST 0
    0x18,0x2c, // STORE_ATTR 'exc'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_core_SingletonGenerator___init__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_core_SingletonGenerator___init__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 17,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 43,
        .line_info = fun_data_asyncio_core_SingletonGenerator___init__ + 4,
        .line_info_top = fun_data_asyncio_core_SingletonGenerator___init__ + 4,
        .opcodes = fun_data_asyncio_core_SingletonGenerator___init__ + 4,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_core_SingletonGenerator___init__ fun_data_asyncio_core_SingletonGenerator___init__[0]
#endif

// child of asyncio_core_SingletonGenerator
// frozen bytecode for file asyncio/core.py, scope asyncio_core_SingletonGenerator___iter__
static const byte fun_data_asyncio_core_SingletonGenerator___iter__[6] = {
    0x09,0x04, // prelude
    0x2d,0x63, // names: __iter__, self
     // code info
    0xb0, // LOAD_FAST 0
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_core_SingletonGenerator___iter__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_core_SingletonGenerator___iter__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 6,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 2,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 45,
        .line_info = fun_data_asyncio_core_SingletonGenerator___iter__ + 4,
        .line_info_top = fun_data_asyncio_core_SingletonGenerator___iter__ + 4,
        .opcodes = fun_data_asyncio_core_SingletonGenerator___iter__ + 4,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_core_SingletonGenerator___iter__ fun_data_asyncio_core_SingletonGenerator___iter__[0]
#endif

// child of asyncio_core_SingletonGenerator
// frozen bytecode for file asyncio/core.py, scope asyncio_core_SingletonGenerator___next__
static const byte fun_data_asyncio_core_SingletonGenerator___next__[42] = {
    0x21,0x04, // prelude
    0x2e,0x63, // names: __next__, self
     // code info
    0xb0, // LOAD_FAST 0
    0x13,0x15, // LOAD_ATTR 'state'
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0xd3, // UNARY_OP 3 <not>
    0x44,0x52, // POP_JUMP_IF_FALSE 18
    0x12,0x5b, // LOAD_GLOBAL '_task_queue'
    0x14,0x1a, // LOAD_METHOD 'push'
    0x12,0x4d, // LOAD_GLOBAL 'cur_task'
    0xb0, // LOAD_FAST 0
    0x13,0x15, // LOAD_ATTR 'state'
    0x36,0x02, // CALL_METHOD 2
    0x59, // POP_TOP
    0x51, // LOAD_CONST_NONE
    0xb0, // LOAD_FAST 0
    0x18,0x15, // STORE_ATTR 'state'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
    0x51, // LOAD_CONST_NONE
    0xb0, // LOAD_FAST 0
    0x13,0x2c, // LOAD_ATTR 'exc'
    0x18,0x2f, // STORE_ATTR '__traceback__'
    0xb0, // LOAD_FAST 0
    0x13,0x2c, // LOAD_ATTR 'exc'
    0x65, // RAISE_OBJ
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_core_SingletonGenerator___next__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_core_SingletonGenerator___next__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 42,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 46,
        .line_info = fun_data_asyncio_core_SingletonGenerator___next__ + 4,
        .line_info_top = fun_data_asyncio_core_SingletonGenerator___next__ + 4,
        .opcodes = fun_data_asyncio_core_SingletonGenerator___next__ + 4,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_core_SingletonGenerator___next__ fun_data_asyncio_core_SingletonGenerator___next__[0]
#endif

static const mp_raw_code_t *const children_asyncio_core_SingletonGenerator[] = {
    (const mp_raw_code_t *)&proto_fun_asyncio_core_SingletonGenerator___init__,
    (const mp_raw_code_t *)&proto_fun_asyncio_core_SingletonGenerator___iter__,
    (const mp_raw_code_t *)&proto_fun_asyncio_core_SingletonGenerator___next__,
};

static const mp_raw_code_truncated_t proto_fun_asyncio_core_SingletonGenerator = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_core_SingletonGenerator,
    .children = (void *)&children_asyncio_core_SingletonGenerator,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 25,
    .n_children = 3,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 1,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 17,
        .line_info = fun_data_asyncio_core_SingletonGenerator + 3,
        .line_info_top = fun_data_asyncio_core_SingletonGenerator + 3,
        .opcodes = fun_data_asyncio_core_SingletonGenerator + 3,
    },
    #endif
    #endif
};

// child of asyncio_core__lt_module_gt_
// frozen bytecode for file asyncio/core.py, scope asyncio_core_sleep_ms
static const byte fun_data_asyncio_core_sleep_ms[25] = {
    0xb2,0x01,0x06, // prelude
    0x14,0x52,0x53, // names: sleep_ms, t, sgen
     // code info
    0x12,0x04, // LOAD_GLOBAL 'ticks_add'
    0x12,0x49, // LOAD_GLOBAL 'ticks'
    0x34,0x00, // CALL_FUNCTION 0
    0x12,0x54, // LOAD_GLOBAL 'max'
    0x80, // LOAD_CONST_SMALL_INT 0
    0xb0, // LOAD_FAST 0
    0x34,0x02, // CALL_FUNCTION 2
    0x34,0x02, // CALL_FUNCTION 2
    0xb1, // LOAD_FAST 1
    0x18,0x15, // STORE_ATTR 'state'
    0xb1, // LOAD_FAST 1
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_core_sleep_ms = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_core_sleep_ms,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 25,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 7,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 1,
        .qstr_block_name_idx = 20,
        .line_info = fun_data_asyncio_core_sleep_ms + 6,
        .line_info_top = fun_data_asyncio_core_sleep_ms + 6,
        .opcodes = fun_data_asyncio_core_sleep_ms + 6,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_core_sleep_ms fun_data_asyncio_core_sleep_ms[0]
#endif

// child of asyncio_core__lt_module_gt_
// frozen bytecode for file asyncio/core.py, scope asyncio_core_sleep
static const byte fun_data_asyncio_core_sleep[18] = {
    0x21,0x04, // prelude
    0x16,0x52, // names: sleep, t
     // code info
    0x12,0x14, // LOAD_GLOBAL 'sleep_ms'
    0x12,0x55, // LOAD_GLOBAL 'int'
    0xb0, // LOAD_FAST 0
    0x22,0x87,0x68, // LOAD_CONST_SMALL_INT 1000
    0xf4, // BINARY_OP 29 __mul__
    0x34,0x01, // CALL_FUNCTION 1
    0x34,0x01, // CALL_FUNCTION 1
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_core_sleep = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_core_sleep,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 18,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 22,
        .line_info = fun_data_asyncio_core_sleep + 4,
        .line_info_top = fun_data_asyncio_core_sleep + 4,
        .opcodes = fun_data_asyncio_core_sleep + 4,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_core_sleep fun_data_asyncio_core_sleep[0]
#endif

// child of asyncio_core__lt_module_gt_
// frozen bytecode for file asyncio/core.py, scope asyncio_core_IOQueue
static const byte fun_data_asyncio_core_IOQueue[41] = {
    0x00,0x02, // prelude
    0x12, // names: IOQueue
     // code info
    0x11,0x4f, // LOAD_NAME '__name__'
    0x16,0x50, // STORE_NAME '__module__'
    0x10,0x12, // LOAD_CONST_STRING 'IOQueue'
    0x16,0x51, // STORE_NAME '__qualname__'
    0x32,0x00, // MAKE_FUNCTION 0
    0x16,0x2b, // STORE_NAME '__init__'
    0x32,0x01, // MAKE_FUNCTION 1
    0x16,0x32, // STORE_NAME '_enqueue'
    0x32,0x02, // MAKE_FUNCTION 2
    0x16,0x37, // STORE_NAME '_dequeue'
    0x32,0x03, // MAKE_FUNCTION 3
    0x16,0x39, // STORE_NAME 'queue_read'
    0x32,0x04, // MAKE_FUNCTION 4
    0x16,0x3a, // STORE_NAME 'queue_write'
    0x32,0x05, // MAKE_FUNCTION 5
    0x16,0x3b, // STORE_NAME 'remove'
    0x32,0x06, // MAKE_FUNCTION 6
    0x16,0x1f, // STORE_NAME 'wait_io_event'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
// child of asyncio_core_IOQueue
// frozen bytecode for file asyncio/core.py, scope asyncio_core_IOQueue___init__
static const byte fun_data_asyncio_core_IOQueue___init__[20] = {
    0x11,0x04, // prelude
    0x2b,0x63, // names: __init__, self
     // code info
    0x12,0x07, // LOAD_GLOBAL 'select'
    0x14,0x30, // LOAD_METHOD 'poll'
    0x36,0x00, // CALL_METHOD 0
    0xb0, // LOAD_FAST 0
    0x18,0x31, // STORE_ATTR 'poller'
    0x2c,0x00, // BUILD_MAP 0
    0xb0, // LOAD_FAST 0
    0x18,0x1e, // STORE_ATTR 'map'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_core_IOQueue___init__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_core_IOQueue___init__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 20,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 43,
        .line_info = fun_data_asyncio_core_IOQueue___init__ + 4,
        .line_info_top = fun_data_asyncio_core_IOQueue___init__ + 4,
        .opcodes = fun_data_asyncio_core_IOQueue___init__ + 4,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_core_IOQueue___init__ fun_data_asyncio_core_IOQueue___init__[0]
#endif

// child of asyncio_core_IOQueue
// frozen bytecode for file asyncio/core.py, scope asyncio_core_IOQueue__enqueue
static const byte fun_data_asyncio_core_IOQueue__enqueue[105] = {
    0x4b,0x08, // prelude
    0x32,0x63,0x64,0x65, // names: _enqueue, self, s, idx
     // code info
    0x12,0x66, // LOAD_GLOBAL 'id'
    0xb1, // LOAD_FAST 1
    0x34,0x01, // CALL_FUNCTION 1
    0xb0, // LOAD_FAST 0
    0x13,0x1e, // LOAD_ATTR 'map'
    0xdd, // BINARY_OP 6 <in>
    0xd3, // UNARY_OP 3 <not>
    0x44,0x6f, // POP_JUMP_IF_FALSE 47
    0x51, // LOAD_CONST_NONE
    0x51, // LOAD_CONST_NONE
    0xb1, // LOAD_FAST 1
    0x2b,0x03, // BUILD_LIST 3
    0xc3, // STORE_FAST 3
    0x12,0x4d, // LOAD_GLOBAL 'cur_task'
    0xb3, // LOAD_FAST 3
    0xb2, // LOAD_FAST 2
    0x56, // STORE_SUBSCR
    0xb3, // LOAD_FAST 3
    0xb0, // LOAD_FAST 0
    0x13,0x1e, // LOAD_ATTR 'map'
    0x12,0x66, // LOAD_GLOBAL 'id'
    0xb1, // LOAD_FAST 1
    0x34,0x01, // CALL_FUNCTION 1
    0x56, // STORE_SUBSCR
    0xb0, // LOAD_FAST 0
    0x13,0x31, // LOAD_ATTR 'poller'
    0x14,0x33, // LOAD_METHOD 'register'
    0xb1, // LOAD_FAST 1
    0xb2, // LOAD_FAST 2
    0x80, // LOAD_CONST_SMALL_INT 0
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x46, // POP_JUMP_IF_FALSE 6
    0x12,0x07, // LOAD_GLOBAL 'select'
    0x13,0x34, // LOAD_ATTR 'POLLIN'
    0x42,0x44, // JUMP 4
    0x12,0x07, // LOAD_GLOBAL 'select'
    0x13,0x35, // LOAD_ATTR 'POLLOUT'
    0x36,0x02, // CALL_METHOD 2
    0x59, // POP_TOP
    0x42,0x61, // JUMP 33
    0xb0, // LOAD_FAST 0
    0x13,0x1e, // LOAD_ATTR 'map'
    0x12,0x66, // LOAD_GLOBAL 'id'
    0xb1, // LOAD_FAST 1
    0x34,0x01, // CALL_FUNCTION 1
    0x55, // LOAD_SUBSCR
    0xc4, // STORE_FAST 4
    0x12,0x4d, // LOAD_GLOBAL 'cur_task'
    0xb4, // LOAD_FAST 4
    0xb2, // LOAD_FAST 2
    0x56, // STORE_SUBSCR
    0xb0, // LOAD_FAST 0
    0x13,0x31, // LOAD_ATTR 'poller'
    0x14,0x36, // LOAD_METHOD 'modify'
    0xb1, // LOAD_FAST 1
    0x12,0x07, // LOAD_GLOBAL 'select'
    0x13,0x34, // LOAD_ATTR 'POLLIN'
    0x12,0x07, // LOAD_GLOBAL 'select'
    0x13,0x35, // LOAD_ATTR 'POLLOUT'
    0xed, // BINARY_OP 22 __or__
    0x36,0x02, // CALL_METHOD 2
    0x59, // POP_TOP
    0xb0, // LOAD_FAST 0
    0x12,0x4d, // LOAD_GLOBAL 'cur_task'
    0x18,0x21, // STORE_ATTR 'data'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_core_IOQueue__enqueue = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_core_IOQueue__enqueue,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 105,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 10,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 3,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 50,
        .line_info = fun_data_asyncio_core_IOQueue__enqueue + 6,
        .line_info_top = fun_data_asyncio_core_IOQueue__enqueue + 6,
        .opcodes = fun_data_asyncio_core_IOQueue__enqueue + 6,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_core_IOQueue__enqueue fun_data_asyncio_core_IOQueue__enqueue[0]
#endif

// child of asyncio_core_IOQueue
// frozen bytecode for file asyncio/core.py, scope asyncio_core_IOQueue__dequeue
static const byte fun_data_asyncio_core_IOQueue__dequeue[27] = {
    0x22,0x06, // prelude
    0x37,0x63,0x64, // names: _dequeue, self, s
     // code info
    0xb0, // LOAD_FAST 0
    0x13,0x1e, // LOAD_ATTR 'map'
    0x12,0x66, // LOAD_GLOBAL 'id'
    0xb1, // LOAD_FAST 1
    0x34,0x01, // CALL_FUNCTION 1
    0x53, // LOAD_NULL
    0x5b, // ROT_THREE
    0x56, // STORE_SUBSCR
    0xb0, // LOAD_FAST 0
    0x13,0x31, // LOAD_ATTR 'poller'
    0x14,0x38, // LOAD_METHOD 'unregister'
    0xb1, // LOAD_FAST 1
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_core_IOQueue__dequeue = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_core_IOQueue__dequeue,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 27,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 55,
        .line_info = fun_data_asyncio_core_IOQueue__dequeue + 5,
        .line_info_top = fun_data_asyncio_core_IOQueue__dequeue + 5,
        .opcodes = fun_data_asyncio_core_IOQueue__dequeue + 5,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_core_IOQueue__dequeue fun_data_asyncio_core_IOQueue__dequeue[0]
#endif

// child of asyncio_core_IOQueue
// frozen bytecode for file asyncio/core.py, scope asyncio_core_IOQueue_queue_read
static const byte fun_data_asyncio_core_IOQueue_queue_read[15] = {
    0x2a,0x06, // prelude
    0x39,0x63,0x64, // names: queue_read, self, s
     // code info
    0xb0, // LOAD_FAST 0
    0x14,0x32, // LOAD_METHOD '_enqueue'
    0xb1, // LOAD_FAST 1
    0x80, // LOAD_CONST_SMALL_INT 0
    0x36,0x02, // CALL_METHOD 2
    0x59, // POP_TOP
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_core_IOQueue_queue_read = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_core_IOQueue_queue_read,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 15,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 6,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 57,
        .line_info = fun_data_asyncio_core_IOQueue_queue_read + 5,
        .line_info_top = fun_data_asyncio_core_IOQueue_queue_read + 5,
        .opcodes = fun_data_asyncio_core_IOQueue_queue_read + 5,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_core_IOQueue_queue_read fun_data_asyncio_core_IOQueue_queue_read[0]
#endif

// child of asyncio_core_IOQueue
// frozen bytecode for file asyncio/core.py, scope asyncio_core_IOQueue_queue_write
static const byte fun_data_asyncio_core_IOQueue_queue_write[15] = {
    0x2a,0x06, // prelude
    0x3a,0x63,0x64, // names: queue_write, self, s
     // code info
    0xb0, // LOAD_FAST 0
    0x14,0x32, // LOAD_METHOD '_enqueue'
    0xb1, // LOAD_FAST 1
    0x81, // LOAD_CONST_SMALL_INT 1
    0x36,0x02, // CALL_METHOD 2
    0x59, // POP_TOP
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_core_IOQueue_queue_write = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_core_IOQueue_queue_write,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 15,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 6,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 58,
        .line_info = fun_data_asyncio_core_IOQueue_queue_write + 5,
        .line_info_top = fun_data_asyncio_core_IOQueue_queue_write + 5,
        .opcodes = fun_data_asyncio_core_IOQueue_queue_write + 5,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_core_IOQueue_queue_write fun_data_asyncio_core_IOQueue_queue_write[0]
#endif

// child of asyncio_core_IOQueue
// frozen bytecode for file asyncio/core.py, scope asyncio_core_IOQueue_remove
static const byte fun_data_asyncio_core_IOQueue_remove[65] = {
    0x6a,0x06, // prelude
    0x3b,0x63,0x0b, // names: remove, self, task
     // code info
    0x51, // LOAD_CONST_NONE
    0xc2, // STORE_FAST 2
    0xb0, // LOAD_FAST 0
    0x13,0x1e, // LOAD_ATTR 'map'
    0x5f, // GET_ITER_STACK
    0x4b,0x1f, // FOR_ITER 31
    0xc3, // STORE_FAST 3
    0xb0, // LOAD_FAST 0
    0x13,0x1e, // LOAD_ATTR 'map'
    0xb3, // LOAD_FAST 3
    0x55, // LOAD_SUBSCR
    0x30,0x03, // UNPACK_SEQUENCE 3
    0xc4, // STORE_FAST 4
    0xc5, // STORE_FAST 5
    0xc6, // STORE_FAST 6
    0xb4, // LOAD_FAST 4
    0xb1, // LOAD_FAST 1
    0xde, // BINARY_OP 7 <is>
    0x43,0x45, // POP_JUMP_IF_TRUE 5
    0xb5, // LOAD_FAST 5
    0xb1, // LOAD_FAST 1
    0xde, // BINARY_OP 7 <is>
    0x44,0x48, // POP_JUMP_IF_FALSE 8
    0xb6, // LOAD_FAST 6
    0xc2, // STORE_FAST 2
    0x59, // POP_TOP
    0x59, // POP_TOP
    0x59, // POP_TOP
    0x59, // POP_TOP
    0x42,0x42, // JUMP 2
    0x42,0x1f, // JUMP -33
    0xb2, // LOAD_FAST 2
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0xd3, // UNARY_OP 3 <not>
    0x44,0x49, // POP_JUMP_IF_FALSE 9
    0xb0, // LOAD_FAST 0
    0x14,0x37, // LOAD_METHOD '_dequeue'
    0xb6, // LOAD_FAST 6
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x42,0x42, // JUMP 2
    0x42,0x42, // JUMP 2
    0x42,0x06, // JUMP -58
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_core_IOQueue_remove = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_core_IOQueue_remove,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 65,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 14,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 59,
        .line_info = fun_data_asyncio_core_IOQueue_remove + 5,
        .line_info_top = fun_data_asyncio_core_IOQueue_remove + 5,
        .opcodes = fun_data_asyncio_core_IOQueue_remove + 5,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_core_IOQueue_remove fun_data_asyncio_core_IOQueue_remove[0]
#endif

// child of asyncio_core_IOQueue
// frozen bytecode for file asyncio/core.py, scope asyncio_core_IOQueue_wait_io_event
static const byte fun_data_asyncio_core_IOQueue_wait_io_event[156] = {
    0x62,0x06, // prelude
    0x1f,0x63,0x67, // names: wait_io_event, self, dt
     // code info
    0xb0, // LOAD_FAST 0
    0x13,0x31, // LOAD_ATTR 'poller'
    0x14,0x3c, // LOAD_METHOD 'ipoll'
    0xb1, // LOAD_FAST 1
    0x36,0x01, // CALL_METHOD 1
    0x5f, // GET_ITER_STACK
    0x4b,0x89,0x01, // FOR_ITER 137
    0x30,0x02, // UNPACK_SEQUENCE 2
    0xc2, // STORE_FAST 2
    0xc3, // STORE_FAST 3
    0xb0, // LOAD_FAST 0
    0x13,0x1e, // LOAD_ATTR 'map'
    0x12,0x66, // LOAD_GLOBAL 'id'
    0xb2, // LOAD_FAST 2
    0x34,0x01, // CALL_FUNCTION 1
    0x55, // LOAD_SUBSCR
    0xc4, // STORE_FAST 4
    0xb3, // LOAD_FAST 3
    0x12,0x07, // LOAD_GLOBAL 'select'
    0x13,0x35, // LOAD_ATTR 'POLLOUT'
    0xd2, // UNARY_OP 2 __invert__
    0xef, // BINARY_OP 24 __and__
    0x44,0x56, // POP_JUMP_IF_FALSE 22
    0xb4, // LOAD_FAST 4
    0x80, // LOAD_CONST_SMALL_INT 0
    0x55, // LOAD_SUBSCR
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0xd3, // UNARY_OP 3 <not>
    0x44,0x4e, // POP_JUMP_IF_FALSE 14
    0x12,0x5b, // LOAD_GLOBAL '_task_queue'
    0x14,0x1a, // LOAD_METHOD 'push'
    0xb4, // LOAD_FAST 4
    0x80, // LOAD_CONST_SMALL_INT 0
    0x55, // LOAD_SUBSCR
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x51, // LOAD_CONST_NONE
    0xb4, // LOAD_FAST 4
    0x80, // LOAD_CONST_SMALL_INT 0
    0x56, // STORE_SUBSCR
    0xb3, // LOAD_FAST 3
    0x12,0x07, // LOAD_GLOBAL 'select'
    0x13,0x34, // LOAD_ATTR 'POLLIN'
    0xd2, // UNARY_OP 2 __invert__
    0xef, // BINARY_OP 24 __and__
    0x44,0x56, // POP_JUMP_IF_FALSE 22
    0xb4, // LOAD_FAST 4
    0x81, // LOAD_CONST_SMALL_INT 1
    0x55, // LOAD_SUBSCR
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0xd3, // UNARY_OP 3 <not>
    0x44,0x4e, // POP_JUMP_IF_FALSE 14
    0x12,0x5b, // LOAD_GLOBAL '_task_queue'
    0x14,0x1a, // LOAD_METHOD 'push'
    0xb4, // LOAD_FAST 4
    0x81, // LOAD_CONST_SMALL_INT 1
    0x55, // LOAD_SUBSCR
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x51, // LOAD_CONST_NONE
    0xb4, // LOAD_FAST 4
    0x81, // LOAD_CONST_SMALL_INT 1
    0x56, // STORE_SUBSCR
    0xb4, // LOAD_FAST 4
    0x80, // LOAD_CONST_SMALL_INT 0
    0x55, // LOAD_SUBSCR
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0x44,0x50, // POP_JUMP_IF_FALSE 16
    0xb4, // LOAD_FAST 4
    0x81, // LOAD_CONST_SMALL_INT 1
    0x55, // LOAD_SUBSCR
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0x44,0x49, // POP_JUMP_IF_FALSE 9
    0xb0, // LOAD_FAST 0
    0x14,0x37, // LOAD_METHOD '_dequeue'
    0xb2, // LOAD_FAST 2
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x42,0x63, // JUMP 35
    0xb4, // LOAD_FAST 4
    0x80, // LOAD_CONST_SMALL_INT 0
    0x55, // LOAD_SUBSCR
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0x44,0x4f, // POP_JUMP_IF_FALSE 15
    0xb0, // LOAD_FAST 0
    0x13,0x31, // LOAD_ATTR 'poller'
    0x14,0x36, // LOAD_METHOD 'modify'
    0xb2, // LOAD_FAST 2
    0x12,0x07, // LOAD_GLOBAL 'select'
    0x13,0x35, // LOAD_ATTR 'POLLOUT'
    0x36,0x02, // CALL_METHOD 2
    0x59, // POP_TOP
    0x42,0x4d, // JUMP 13
    0xb0, // LOAD_FAST 0
    0x13,0x31, // LOAD_ATTR 'poller'
    0x14,0x36, // LOAD_METHOD 'modify'
    0xb2, // LOAD_FAST 2
    0x12,0x07, // LOAD_GLOBAL 'select'
    0x13,0x34, // LOAD_ATTR 'POLLIN'
    0x36,0x02, // CALL_METHOD 2
    0x59, // POP_TOP
    0x42,0xf4,0x7e, // JUMP -140
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_core_IOQueue_wait_io_event = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_core_IOQueue_wait_io_event,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 156,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 13,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 31,
        .line_info = fun_data_asyncio_core_IOQueue_wait_io_event + 5,
        .line_info_top = fun_data_asyncio_core_IOQueue_wait_io_event + 5,
        .opcodes = fun_data_asyncio_core_IOQueue_wait_io_event + 5,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_core_IOQueue_wait_io_event fun_data_asyncio_core_IOQueue_wait_io_event[0]
#endif

static const mp_raw_code_t *const children_asyncio_core_IOQueue[] = {
    (const mp_raw_code_t *)&proto_fun_asyncio_core_IOQueue___init__,
    (const mp_raw_code_t *)&proto_fun_asyncio_core_IOQueue__enqueue,
    (const mp_raw_code_t *)&proto_fun_asyncio_core_IOQueue__dequeue,
    (const mp_raw_code_t *)&proto_fun_asyncio_core_IOQueue_queue_read,
    (const mp_raw_code_t *)&proto_fun_asyncio_core_IOQueue_queue_write,
    (const mp_raw_code_t *)&proto_fun_asyncio_core_IOQueue_remove,
    (const mp_raw_code_t *)&proto_fun_asyncio_core_IOQueue_wait_io_event,
};

static const mp_raw_code_truncated_t proto_fun_asyncio_core_IOQueue = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_core_IOQueue,
    .children = (void *)&children_asyncio_core_IOQueue,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 41,
    .n_children = 7,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 1,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 18,
        .line_info = fun_data_asyncio_core_IOQueue + 3,
        .line_info_top = fun_data_asyncio_core_IOQueue + 3,
        .opcodes = fun_data_asyncio_core_IOQueue + 3,
    },
    #endif
    #endif
};

// child of asyncio_core__lt_module_gt_
// frozen bytecode for file asyncio/core.py, scope asyncio_core__promote_to_task
static const byte fun_data_asyncio_core__promote_to_task[21] = {
    0x19,0x04, // prelude
    0x17,0x56, // names: _promote_to_task, aw
     // code info
    0x12,0x57, // LOAD_GLOBAL 'isinstance'
    0xb0, // LOAD_FAST 0
    0x12,0x09, // LOAD_GLOBAL 'Task'
    0x34,0x02, // CALL_FUNCTION 2
    0x44,0x42, // POP_JUMP_IF_FALSE 2
    0xb0, // LOAD_FAST 0
    0x63, // RETURN_VALUE
    0x12,0x18, // LOAD_GLOBAL 'create_task'
    0xb0, // LOAD_FAST 0
    0x34,0x01, // CALL_FUNCTION 1
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_core__promote_to_task = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_core__promote_to_task,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 21,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 23,
        .line_info = fun_data_asyncio_core__promote_to_task + 4,
        .line_info_top = fun_data_asyncio_core__promote_to_task + 4,
        .opcodes = fun_data_asyncio_core__promote_to_task + 4,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_core__promote_to_task fun_data_asyncio_core__promote_to_task[0]
#endif

// child of asyncio_core__lt_module_gt_
// frozen bytecode for file asyncio/core.py, scope asyncio_core_create_task
static const byte fun_data_asyncio_core_create_task[40] = {
    0x21,0x04, // prelude
    0x18,0x22, // names: create_task, coro
     // code info
    0x12,0x58, // LOAD_GLOBAL 'hasattr'
    0xb0, // LOAD_FAST 0
    0x10,0x19, // LOAD_CONST_STRING 'send'
    0x34,0x02, // CALL_FUNCTION 2
    0x43,0x47, // POP_JUMP_IF_TRUE 7
    0x12,0x59, // LOAD_GLOBAL 'TypeError'
    0x23,0x01, // LOAD_CONST_OBJ 1
    0x34,0x01, // CALL_FUNCTION 1
    0x65, // RAISE_OBJ
    0x12,0x09, // LOAD_GLOBAL 'Task'
    0xb0, // LOAD_FAST 0
    0x12,0x5a, // LOAD_GLOBAL 'globals'
    0x34,0x00, // CALL_FUNCTION 0
    0x34,0x02, // CALL_FUNCTION 2
    0xc1, // STORE_FAST 1
    0x12,0x5b, // LOAD_GLOBAL '_task_queue'
    0x14,0x1a, // LOAD_METHOD 'push'
    0xb1, // LOAD_FAST 1
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0xb1, // LOAD_FAST 1
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_core_create_task = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_core_create_task,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 40,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 24,
        .line_info = fun_data_asyncio_core_create_task + 4,
        .line_info_top = fun_data_asyncio_core_create_task + 4,
        .opcodes = fun_data_asyncio_core_create_task + 4,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_core_create_task fun_data_asyncio_core_create_task[0]
#endif

// child of asyncio_core__lt_module_gt_
// frozen bytecode for file asyncio/core.py, scope asyncio_core_run_until_complete
static const byte fun_data_asyncio_core_run_until_complete[346] = {
    0xf1,0x03,0x04, // prelude
    0x1b,0x5c, // names: run_until_complete, main_task
     // code info
    0x12,0x0c, // LOAD_GLOBAL 'CancelledError'
    0x12,0x4b, // LOAD_GLOBAL 'Exception'
    0x2a,0x02, // BUILD_TUPLE 2
    0xc1, // STORE_FAST 1
    0x12,0x0c, // LOAD_GLOBAL 'CancelledError'
    0x12,0x5d, // LOAD_GLOBAL 'StopIteration'
    0x2a,0x02, // BUILD_TUPLE 2
    0xc2, // STORE_FAST 2
    0x81, // LOAD_CONST_SMALL_INT 1
    0xc3, // STORE_FAST 3
    0x42,0x7e, // JUMP 62
    0x7f, // LOAD_CONST_SMALL_INT -1
    0xc3, // STORE_FAST 3
    0x12,0x5b, // LOAD_GLOBAL '_task_queue'
    0x14,0x1c, // LOAD_METHOD 'peek'
    0x36,0x00, // CALL_METHOD 0
    0xc4, // STORE_FAST 4
    0xb4, // LOAD_FAST 4
    0x44,0x53, // POP_JUMP_IF_FALSE 19
    0x12,0x54, // LOAD_GLOBAL 'max'
    0x80, // LOAD_CONST_SMALL_INT 0
    0x12,0x03, // LOAD_GLOBAL 'ticks_diff'
    0xb4, // LOAD_FAST 4
    0x13,0x1d, // LOAD_ATTR 'ph_key'
    0x12,0x49, // LOAD_GLOBAL 'ticks'
    0x34,0x00, // CALL_FUNCTION 0
    0x34,0x02, // CALL_FUNCTION 2
    0x34,0x02, // CALL_FUNCTION 2
    0xc3, // STORE_FAST 3
    0x42,0x57, // JUMP 23
    0x12,0x5e, // LOAD_GLOBAL '_io_queue'
    0x13,0x1e, // LOAD_ATTR 'map'
    0x43,0x51, // POP_JUMP_IF_TRUE 17
    0x51, // LOAD_CONST_NONE
    0x17,0x4d, // STORE_GLOBAL 'cur_task'
    0xb0, // LOAD_FAST 0
    0x44,0x45, // POP_JUMP_IF_FALSE 5
    0xb0, // LOAD_FAST 0
    0x13,0x15, // LOAD_ATTR 'state'
    0x43,0x42, // POP_JUMP_IF_TRUE 2
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
    0x83, // LOAD_CONST_SMALL_INT 3
    0xc3, // STORE_FAST 3
    0x42,0x40, // JUMP 0
    0x12,0x5e, // LOAD_GLOBAL '_io_queue'
    0x14,0x1f, // LOAD_METHOD 'wait_io_event'
    0xb3, // LOAD_FAST 3
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0xb3, // LOAD_FAST 3
    0x80, // LOAD_CONST_SMALL_INT 0
    0xd8, // BINARY_OP 1 __gt__
    0x43,0xbc,0x7f, // POP_JUMP_IF_TRUE -68
    0x12,0x5b, // LOAD_GLOBAL '_task_queue'
    0x14,0x20, // LOAD_METHOD 'pop'
    0x36,0x00, // CALL_METHOD 0
    0xc4, // STORE_FAST 4
    0xb4, // LOAD_FAST 4
    0x17,0x4d, // STORE_GLOBAL 'cur_task'
    0x48,0x22, // SETUP_EXCEPT 34
    0xb4, // LOAD_FAST 4
    0x13,0x21, // LOAD_ATTR 'data'
    0xc5, // STORE_FAST 5
    0xb5, // LOAD_FAST 5
    0x43,0x4b, // POP_JUMP_IF_TRUE 11
    0xb4, // LOAD_FAST 4
    0x13,0x22, // LOAD_ATTR 'coro'
    0x14,0x19, // LOAD_METHOD 'send'
    0x51, // LOAD_CONST_NONE
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x42,0x4d, // JUMP 13
    0x51, // LOAD_CONST_NONE
    0xb4, // LOAD_FAST 4
    0x18,0x21, // STORE_ATTR 'data'
    0xb4, // LOAD_FAST 4
    0x13,0x22, // LOAD_ATTR 'coro'
    0x14,0x23, // LOAD_METHOD 'throw'
    0xb5, // LOAD_FAST 5
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x4a,0xcc,0x01, // POP_EXCEPT_JUMP 204
    0x57, // DUP_TOP
    0xb1, // LOAD_FAST 1
    0xdf, // BINARY_OP 8 <exception match>
    0x44,0xc5,0x81, // POP_JUMP_IF_FALSE 197
    0xc6, // STORE_FAST 6
    0x49,0xba,0x01, // SETUP_FINALLY 186
    0xb4, // LOAD_FAST 4
    0xb0, // LOAD_FAST 0
    0xde, // BINARY_OP 7 <is>
    0xc7, // STORE_FAST 7
    0xb7, // LOAD_FAST 7
    0x44,0x5d, // POP_JUMP_IF_FALSE 29
    0x51, // LOAD_CONST_NONE
    0x17,0x4d, // STORE_GLOBAL 'cur_task'
    0x12,0x57, // LOAD_GLOBAL 'isinstance'
    0xb6, // LOAD_FAST 6
    0x12,0x5d, // LOAD_GLOBAL 'StopIteration'
    0x34,0x02, // CALL_FUNCTION 2
    0x43,0x46, // POP_JUMP_IF_TRUE 6
    0x50, // LOAD_CONST_FALSE
    0xb4, // LOAD_FAST 4
    0x18,0x15, // STORE_ATTR 'state'
    0xb6, // LOAD_FAST 6
    0x65, // RAISE_OBJ
    0xb4, // LOAD_FAST 4
    0x13,0x15, // LOAD_ATTR 'state'
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0x44,0x44, // POP_JUMP_IF_FALSE 4
    0x50, // LOAD_CONST_FALSE
    0xb4, // LOAD_FAST 4
    0x18,0x15, // STORE_ATTR 'state'
    0xb4, // LOAD_FAST 4
    0x13,0x15, // LOAD_ATTR 'state'
    0x44,0xe4,0x80, // POP_JUMP_IF_FALSE 100
    0xb4, // LOAD_FAST 4
    0x13,0x15, // LOAD_ATTR 'state'
    0x52, // LOAD_CONST_TRUE
    0xde, // BINARY_OP 7 <is>
    0x44,0x4c, // POP_JUMP_IF_FALSE 12
    0xb7, // LOAD_FAST 7
    0x44,0x43, // POP_JUMP_IF_FALSE 3
    0x50, // LOAD_CONST_FALSE
    0x42,0x41, // JUMP 1
    0x51, // LOAD_CONST_NONE
    0xb4, // LOAD_FAST 4
    0x18,0x15, // STORE_ATTR 'state'
    0x42,0x78, // JUMP 56
    0x12,0x5f, // LOAD_GLOBAL 'callable'
    0xb4, // LOAD_FAST 4
    0x13,0x15, // LOAD_ATTR 'state'
    0x34,0x01, // CALL_FUNCTION 1
    0x44,0x50, // POP_JUMP_IF_FALSE 16
    0xb4, // LOAD_FAST 4
    0x14,0x15, // LOAD_METHOD 'state'
    0xb4, // LOAD_FAST 4
    0xb6, // LOAD_FAST 6
    0x36,0x02, // CALL_METHOD 2
    0x59, // POP_TOP
    0x50, // LOAD_CONST_FALSE
    0xb4, // LOAD_FAST 4
    0x18,0x15, // STORE_ATTR 'state'
    0x52, // LOAD_CONST_TRUE
    0xc7, // STORE_FAST 7
    0x42,0x5f, // JUMP 31
    0x42,0x50, // JUMP 16
    0x12,0x5b, // LOAD_GLOBAL '_task_queue'
    0x14,0x1a, // LOAD_METHOD 'push'
    0xb4, // LOAD_FAST 4
    0x13,0x15, // LOAD_ATTR 'state'
    0x14,0x20, // LOAD_METHOD 'pop'
    0x36,0x00, // CALL_METHOD 0
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x52, // LOAD_CONST_TRUE
    0xc7, // STORE_FAST 7
    0xb4, // LOAD_FAST 4
    0x13,0x15, // LOAD_ATTR 'state'
    0x14,0x1c, // LOAD_METHOD 'peek'
    0x36,0x00, // CALL_METHOD 0
    0x43,0x27, // POP_JUMP_IF_TRUE -25
    0x50, // LOAD_CONST_FALSE
    0xb4, // LOAD_FAST 4
    0x18,0x15, // STORE_ATTR 'state'
    0xb7, // LOAD_FAST 7
    0x43,0x50, // POP_JUMP_IF_TRUE 16
    0x12,0x57, // LOAD_GLOBAL 'isinstance'
    0xb6, // LOAD_FAST 6
    0xb2, // LOAD_FAST 2
    0x34,0x02, // CALL_FUNCTION 2
    0x43,0x48, // POP_JUMP_IF_TRUE 8
    0x12,0x5b, // LOAD_GLOBAL '_task_queue'
    0x14,0x1a, // LOAD_METHOD 'push'
    0xb4, // LOAD_FAST 4
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0xb6, // LOAD_FAST 6
    0xb4, // LOAD_FAST 4
    0x18,0x21, // STORE_ATTR 'data'
    0x42,0x62, // JUMP 34
    0xb4, // LOAD_FAST 4
    0x13,0x15, // LOAD_ATTR 'state'
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0x44,0x5b, // POP_JUMP_IF_FALSE 27
    0xb5, // LOAD_FAST 5
    0xb4, // LOAD_FAST 4
    0x18,0x21, // STORE_ATTR 'data'
    0xb5, // LOAD_FAST 5
    0x12,0x4c, // LOAD_GLOBAL '_exc_context'
    0x10,0x0f, // LOAD_CONST_STRING 'exception'
    0x56, // STORE_SUBSCR
    0xb4, // LOAD_FAST 4
    0x12,0x4c, // LOAD_GLOBAL '_exc_context'
    0x10,0x10, // LOAD_CONST_STRING 'future'
    0x56, // STORE_SUBSCR
    0x12,0x13, // LOAD_GLOBAL 'Loop'
    0x14,0x24, // LOAD_METHOD 'call_exception_handler'
    0x12,0x4c, // LOAD_GLOBAL '_exc_context'
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x42,0x40, // JUMP 0
    0xb4, // LOAD_FAST 4
    0xb0, // LOAD_FAST 0
    0xde, // BINARY_OP 7 <is>
    0x44,0x44, // POP_JUMP_IF_FALSE 4
    0xb6, // LOAD_FAST 6
    0x13,0x25, // LOAD_ATTR 'value'
    0x63, // RETURN_VALUE
    0x51, // LOAD_CONST_NONE
    0x51, // LOAD_CONST_NONE
    0xc6, // STORE_FAST 6
    0x28,0x06, // DELETE_FAST 6
    0x5d, // END_FINALLY
    0x4a,0x01, // POP_EXCEPT_JUMP 1
    0x5d, // END_FINALLY
    0x42,0xbb,0x7d, // JUMP -325
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_core_run_until_complete = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_core_run_until_complete,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 346,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 15,
        .n_exc_stack = 2,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 1,
        .qstr_block_name_idx = 27,
        .line_info = fun_data_asyncio_core_run_until_complete + 5,
        .line_info_top = fun_data_asyncio_core_run_until_complete + 5,
        .opcodes = fun_data_asyncio_core_run_until_complete + 5,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_core_run_until_complete fun_data_asyncio_core_run_until_complete[0]
#endif

// child of asyncio_core__lt_module_gt_
// frozen bytecode for file asyncio/core.py, scope asyncio_core_run
static const byte fun_data_asyncio_core_run[14] = {
    0x19,0x04, // prelude
    0x26,0x22, // names: run, coro
     // code info
    0x12,0x1b, // LOAD_GLOBAL 'run_until_complete'
    0x12,0x18, // LOAD_GLOBAL 'create_task'
    0xb0, // LOAD_FAST 0
    0x34,0x01, // CALL_FUNCTION 1
    0x34,0x01, // CALL_FUNCTION 1
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_core_run = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_core_run,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 14,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 38,
        .line_info = fun_data_asyncio_core_run + 4,
        .line_info_top = fun_data_asyncio_core_run + 4,
        .opcodes = fun_data_asyncio_core_run + 4,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_core_run fun_data_asyncio_core_run[0]
#endif

// child of asyncio_core__lt_module_gt_
// frozen bytecode for file asyncio/core.py, scope asyncio_core__stopper
static const byte fun_data_asyncio_core__stopper[6] = {
    0x80,0x40,0x02, // prelude
    0x27, // names: _stopper
     // code info
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_core__stopper = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 1,
    .fun_data = fun_data_asyncio_core__stopper,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 6,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 1,
        .n_exc_stack = 0,
        .scope_flags = 1,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 39,
        .line_info = fun_data_asyncio_core__stopper + 4,
        .line_info_top = fun_data_asyncio_core__stopper + 4,
        .opcodes = fun_data_asyncio_core__stopper + 4,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_core__stopper fun_data_asyncio_core__stopper[0]
#endif

// child of asyncio_core__lt_module_gt_
// frozen bytecode for file asyncio/core.py, scope asyncio_core_Loop
static const byte fun_data_asyncio_core_Loop[52] = {
    0x00,0x02, // prelude
    0x13, // names: Loop
     // code info
    0x11,0x4f, // LOAD_NAME '__name__'
    0x16,0x50, // STORE_NAME '__module__'
    0x10,0x13, // LOAD_CONST_STRING 'Loop'
    0x16,0x51, // STORE_NAME '__qualname__'
    0x51, // LOAD_CONST_NONE
    0x16,0x41, // STORE_NAME '_exc_handler'
    0x32,0x00, // MAKE_FUNCTION 0
    0x16,0x18, // STORE_NAME 'create_task'
    0x32,0x01, // MAKE_FUNCTION 1
    0x16,0x3d, // STORE_NAME 'run_forever'
    0x32,0x02, // MAKE_FUNCTION 2
    0x16,0x1b, // STORE_NAME 'run_until_complete'
    0x32,0x03, // MAKE_FUNCTION 3
    0x16,0x3e, // STORE_NAME 'stop'
    0x32,0x04, // MAKE_FUNCTION 4
    0x16,0x3f, // STORE_NAME 'close'
    0x32,0x05, // MAKE_FUNCTION 5
    0x16,0x40, // STORE_NAME 'set_exception_handler'
    0x32,0x06, // MAKE_FUNCTION 6
    0x16,0x42, // STORE_NAME 'get_exception_handler'
    0x32,0x07, // MAKE_FUNCTION 7
    0x16,0x43, // STORE_NAME 'default_exception_handler'
    0x32,0x08, // MAKE_FUNCTION 8
    0x16,0x24, // STORE_NAME 'call_exception_handler'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
// child of asyncio_core_Loop
// frozen bytecode for file asyncio/core.py, scope asyncio_core_Loop_create_task
static const byte fun_data_asyncio_core_Loop_create_task[10] = {
    0x11,0x04, // prelude
    0x18,0x22, // names: create_task, coro
     // code info
    0x12,0x18, // LOAD_GLOBAL 'create_task'
    0xb0, // LOAD_FAST 0
    0x34,0x01, // CALL_FUNCTION 1
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_core_Loop_create_task = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_core_Loop_create_task,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 10,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 24,
        .line_info = fun_data_asyncio_core_Loop_create_task + 4,
        .line_info_top = fun_data_asyncio_core_Loop_create_task + 4,
        .opcodes = fun_data_asyncio_core_Loop_create_task + 4,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_core_Loop_create_task fun_data_asyncio_core_Loop_create_task[0]
#endif

// child of asyncio_core_Loop
// frozen bytecode for file asyncio/core.py, scope asyncio_core_Loop_run_forever
static const byte fun_data_asyncio_core_Loop_run_forever[26] = {
    0x10,0x02, // prelude
    0x3d, // names: run_forever
     // code info
    0x12,0x09, // LOAD_GLOBAL 'Task'
    0x12,0x27, // LOAD_GLOBAL '_stopper'
    0x34,0x00, // CALL_FUNCTION 0
    0x12,0x5a, // LOAD_GLOBAL 'globals'
    0x34,0x00, // CALL_FUNCTION 0
    0x34,0x02, // CALL_FUNCTION 2
    0x17,0x4e, // STORE_GLOBAL '_stop_task'
    0x12,0x1b, // LOAD_GLOBAL 'run_until_complete'
    0x12,0x4e, // LOAD_GLOBAL '_stop_task'
    0x34,0x01, // CALL_FUNCTION 1
    0x59, // POP_TOP
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_core_Loop_run_forever = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_core_Loop_run_forever,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 26,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 61,
        .line_info = fun_data_asyncio_core_Loop_run_forever + 3,
        .line_info_top = fun_data_asyncio_core_Loop_run_forever + 3,
        .opcodes = fun_data_asyncio_core_Loop_run_forever + 3,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_core_Loop_run_forever fun_data_asyncio_core_Loop_run_forever[0]
#endif

// child of asyncio_core_Loop
// frozen bytecode for file asyncio/core.py, scope asyncio_core_Loop_run_until_complete
static const byte fun_data_asyncio_core_Loop_run_until_complete[14] = {
    0x19,0x04, // prelude
    0x1b,0x56, // names: run_until_complete, aw
     // code info
    0x12,0x1b, // LOAD_GLOBAL 'run_until_complete'
    0x12,0x17, // LOAD_GLOBAL '_promote_to_task'
    0xb0, // LOAD_FAST 0
    0x34,0x01, // CALL_FUNCTION 1
    0x34,0x01, // CALL_FUNCTION 1
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_core_Loop_run_until_complete = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_core_Loop_run_until_complete,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 14,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 27,
        .line_info = fun_data_asyncio_core_Loop_run_until_complete + 4,
        .line_info_top = fun_data_asyncio_core_Loop_run_until_complete + 4,
        .opcodes = fun_data_asyncio_core_Loop_run_until_complete + 4,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_core_Loop_run_until_complete fun_data_asyncio_core_Loop_run_until_complete[0]
#endif

// child of asyncio_core_Loop
// frozen bytecode for file asyncio/core.py, scope asyncio_core_Loop_stop
static const byte fun_data_asyncio_core_Loop_stop[24] = {
    0x10,0x02, // prelude
    0x3e, // names: stop
     // code info
    0x12,0x4e, // LOAD_GLOBAL '_stop_task'
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0xd3, // UNARY_OP 3 <not>
    0x44,0x4c, // POP_JUMP_IF_FALSE 12
    0x12,0x5b, // LOAD_GLOBAL '_task_queue'
    0x14,0x1a, // LOAD_METHOD 'push'
    0x12,0x4e, // LOAD_GLOBAL '_stop_task'
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x51, // LOAD_CONST_NONE
    0x17,0x4e, // STORE_GLOBAL '_stop_task'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_core_Loop_stop = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_core_Loop_stop,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 24,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 62,
        .line_info = fun_data_asyncio_core_Loop_stop + 3,
        .line_info_top = fun_data_asyncio_core_Loop_stop + 3,
        .opcodes = fun_data_asyncio_core_Loop_stop + 3,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_core_Loop_stop fun_data_asyncio_core_Loop_stop[0]
#endif

// child of asyncio_core_Loop
// frozen bytecode for file asyncio/core.py, scope asyncio_core_Loop_close
static const byte fun_data_asyncio_core_Loop_close[5] = {
    0x00,0x02, // prelude
    0x3f, // names: close
     // code info
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_core_Loop_close = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_core_Loop_close,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 5,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 1,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 63,
        .line_info = fun_data_asyncio_core_Loop_close + 3,
        .line_info_top = fun_data_asyncio_core_Loop_close + 3,
        .opcodes = fun_data_asyncio_core_Loop_close + 3,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_core_Loop_close fun_data_asyncio_core_Loop_close[0]
#endif

// child of asyncio_core_Loop
// frozen bytecode for file asyncio/core.py, scope asyncio_core_Loop_set_exception_handler
static const byte fun_data_asyncio_core_Loop_set_exception_handler[11] = {
    0x11,0x04, // prelude
    0x40,0x68, // names: set_exception_handler, handler
     // code info
    0xb0, // LOAD_FAST 0
    0x12,0x13, // LOAD_GLOBAL 'Loop'
    0x18,0x41, // STORE_ATTR '_exc_handler'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_core_Loop_set_exception_handler = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_core_Loop_set_exception_handler,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 11,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 64,
        .line_info = fun_data_asyncio_core_Loop_set_exception_handler + 4,
        .line_info_top = fun_data_asyncio_core_Loop_set_exception_handler + 4,
        .opcodes = fun_data_asyncio_core_Loop_set_exception_handler + 4,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_core_Loop_set_exception_handler fun_data_asyncio_core_Loop_set_exception_handler[0]
#endif

// child of asyncio_core_Loop
// frozen bytecode for file asyncio/core.py, scope asyncio_core_Loop_get_exception_handler
static const byte fun_data_asyncio_core_Loop_get_exception_handler[8] = {
    0x00,0x02, // prelude
    0x42, // names: get_exception_handler
     // code info
    0x12,0x13, // LOAD_GLOBAL 'Loop'
    0x13,0x41, // LOAD_ATTR '_exc_handler'
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_core_Loop_get_exception_handler = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_core_Loop_get_exception_handler,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 8,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 1,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 66,
        .line_info = fun_data_asyncio_core_Loop_get_exception_handler + 3,
        .line_info_top = fun_data_asyncio_core_Loop_get_exception_handler + 3,
        .opcodes = fun_data_asyncio_core_Loop_get_exception_handler + 3,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_core_Loop_get_exception_handler fun_data_asyncio_core_Loop_get_exception_handler[0]
#endif

// child of asyncio_core_Loop
// frozen bytecode for file asyncio/core.py, scope asyncio_core_Loop_default_exception_handler
static const byte fun_data_asyncio_core_Loop_default_exception_handler[64] = {
    0x42,0x06, // prelude
    0x43,0x69,0x6a, // names: default_exception_handler, loop, context
     // code info
    0x12,0x6b, // LOAD_GLOBAL 'print'
    0xb1, // LOAD_FAST 1
    0x10,0x0e, // LOAD_CONST_STRING 'message'
    0x55, // LOAD_SUBSCR
    0x10,0x44, // LOAD_CONST_STRING 'file'
    0x12,0x06, // LOAD_GLOBAL 'sys'
    0x13,0x45, // LOAD_ATTR 'stderr'
    0x34,0x82,0x01, // CALL_FUNCTION 257
    0x59, // POP_TOP
    0x12,0x6b, // LOAD_GLOBAL 'print'
    0x10,0x46, // LOAD_CONST_STRING 'future:'
    0xb1, // LOAD_FAST 1
    0x10,0x10, // LOAD_CONST_STRING 'future'
    0x55, // LOAD_SUBSCR
    0x10,0x47, // LOAD_CONST_STRING 'coro='
    0xb1, // LOAD_FAST 1
    0x10,0x10, // LOAD_CONST_STRING 'future'
    0x55, // LOAD_SUBSCR
    0x13,0x22, // LOAD_ATTR 'coro'
    0x10,0x44, // LOAD_CONST_STRING 'file'
    0x12,0x06, // LOAD_GLOBAL 'sys'
    0x13,0x45, // LOAD_ATTR 'stderr'
    0x34,0x82,0x04, // CALL_FUNCTION 260
    0x59, // POP_TOP
    0x12,0x06, // LOAD_GLOBAL 'sys'
    0x14,0x48, // LOAD_METHOD 'print_exception'
    0xb1, // LOAD_FAST 1
    0x10,0x0f, // LOAD_CONST_STRING 'exception'
    0x55, // LOAD_SUBSCR
    0x12,0x06, // LOAD_GLOBAL 'sys'
    0x13,0x45, // LOAD_ATTR 'stderr'
    0x36,0x02, // CALL_METHOD 2
    0x59, // POP_TOP
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_core_Loop_default_exception_handler = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_core_Loop_default_exception_handler,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 64,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 9,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 67,
        .line_info = fun_data_asyncio_core_Loop_default_exception_handler + 5,
        .line_info_top = fun_data_asyncio_core_Loop_default_exception_handler + 5,
        .opcodes = fun_data_asyncio_core_Loop_default_exception_handler + 5,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_core_Loop_default_exception_handler fun_data_asyncio_core_Loop_default_exception_handler[0]
#endif

// child of asyncio_core_Loop
// frozen bytecode for file asyncio/core.py, scope asyncio_core_Loop_call_exception_handler
static const byte fun_data_asyncio_core_Loop_call_exception_handler[22] = {
    0x19,0x04, // prelude
    0x24,0x6a, // names: call_exception_handler, context
     // code info
    0x12,0x13, // LOAD_GLOBAL 'Loop'
    0x13,0x41, // LOAD_ATTR '_exc_handler'
    0x45,0x04, // JUMP_IF_TRUE_OR_POP 4
    0x12,0x13, // LOAD_GLOBAL 'Loop'
    0x13,0x43, // LOAD_ATTR 'default_exception_handler'
    0x12,0x13, // LOAD_GLOBAL 'Loop'
    0xb0, // LOAD_FAST 0
    0x34,0x02, // CALL_FUNCTION 2
    0x59, // POP_TOP
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_core_Loop_call_exception_handler = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_core_Loop_call_exception_handler,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 22,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 36,
        .line_info = fun_data_asyncio_core_Loop_call_exception_handler + 4,
        .line_info_top = fun_data_asyncio_core_Loop_call_exception_handler + 4,
        .opcodes = fun_data_asyncio_core_Loop_call_exception_handler + 4,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_core_Loop_call_exception_handler fun_data_asyncio_core_Loop_call_exception_handler[0]
#endif

static const mp_raw_code_t *const children_asyncio_core_Loop[] = {
    (const mp_raw_code_t *)&proto_fun_asyncio_core_Loop_create_task,
    (const mp_raw_code_t *)&proto_fun_asyncio_core_Loop_run_forever,
    (const mp_raw_code_t *)&proto_fun_asyncio_core_Loop_run_until_complete,
    (const mp_raw_code_t *)&proto_fun_asyncio_core_Loop_stop,
    (const mp_raw_code_t *)&proto_fun_asyncio_core_Loop_close,
    (const mp_raw_code_t *)&proto_fun_asyncio_core_Loop_set_exception_handler,
    (const mp_raw_code_t *)&proto_fun_asyncio_core_Loop_get_exception_handler,
    (const mp_raw_code_t *)&proto_fun_asyncio_core_Loop_default_exception_handler,
    (const mp_raw_code_t *)&proto_fun_asyncio_core_Loop_call_exception_handler,
};

static const mp_raw_code_truncated_t proto_fun_asyncio_core_Loop = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_core_Loop,
    .children = (void *)&children_asyncio_core_Loop,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 52,
    .n_children = 9,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 1,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 19,
        .line_info = fun_data_asyncio_core_Loop + 3,
        .line_info_top = fun_data_asyncio_core_Loop + 3,
        .opcodes = fun_data_asyncio_core_Loop + 3,
    },
    #endif
    #endif
};

// child of asyncio_core__lt_module_gt_
// frozen bytecode for file asyncio/core.py, scope asyncio_core_get_event_loop
static const byte fun_data_asyncio_core_get_event_loop[10] = {
    0x92,0x80,0x01,0x06, // prelude
    0x28,0x60,0x61, // names: get_event_loop, runq_len, waitq_len
     // code info
    0x12,0x13, // LOAD_GLOBAL 'Loop'
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_core_get_event_loop = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_core_get_event_loop,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 10,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 2,
        .qstr_block_name_idx = 40,
        .line_info = fun_data_asyncio_core_get_event_loop + 7,
        .line_info_top = fun_data_asyncio_core_get_event_loop + 7,
        .opcodes = fun_data_asyncio_core_get_event_loop + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_core_get_event_loop fun_data_asyncio_core_get_event_loop[0]
#endif

// child of asyncio_core__lt_module_gt_
// frozen bytecode for file asyncio/core.py, scope asyncio_core_current_task
static const byte fun_data_asyncio_core_current_task[19] = {
    0x08,0x02, // prelude
    0x29, // names: current_task
     // code info
    0x12,0x4d, // LOAD_GLOBAL 'cur_task'
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0x44,0x47, // POP_JUMP_IF_FALSE 7
    0x12,0x62, // LOAD_GLOBAL 'RuntimeError'
    0x23,0x02, // LOAD_CONST_OBJ 2
    0x34,0x01, // CALL_FUNCTION 1
    0x65, // RAISE_OBJ
    0x12,0x4d, // LOAD_GLOBAL 'cur_task'
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_core_current_task = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_core_current_task,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 19,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 2,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 41,
        .line_info = fun_data_asyncio_core_current_task + 3,
        .line_info_top = fun_data_asyncio_core_current_task + 3,
        .opcodes = fun_data_asyncio_core_current_task + 3,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_core_current_task fun_data_asyncio_core_current_task[0]
#endif

// child of asyncio_core__lt_module_gt_
// frozen bytecode for file asyncio/core.py, scope asyncio_core_new_event_loop
static const byte fun_data_asyncio_core_new_event_loop[18] = {
    0x00,0x02, // prelude
    0x2a, // names: new_event_loop
     // code info
    0x12,0x08, // LOAD_GLOBAL 'TaskQueue'
    0x34,0x00, // CALL_FUNCTION 0
    0x17,0x5b, // STORE_GLOBAL '_task_queue'
    0x12,0x12, // LOAD_GLOBAL 'IOQueue'
    0x34,0x00, // CALL_FUNCTION 0
    0x17,0x5e, // STORE_GLOBAL '_io_queue'
    0x12,0x13, // LOAD_GLOBAL 'Loop'
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_core_new_event_loop = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_core_new_event_loop,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 18,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 1,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 42,
        .line_info = fun_data_asyncio_core_new_event_loop + 3,
        .line_info_top = fun_data_asyncio_core_new_event_loop + 3,
        .opcodes = fun_data_asyncio_core_new_event_loop + 3,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_core_new_event_loop fun_data_asyncio_core_new_event_loop[0]
#endif

static const mp_raw_code_t *const children_asyncio_core__lt_module_gt_[] = {
    (const mp_raw_code_t *)&proto_fun_asyncio_core_CancelledError,
    (const mp_raw_code_t *)&proto_fun_asyncio_core_TimeoutError,
    (const mp_raw_code_t *)&proto_fun_asyncio_core_SingletonGenerator,
    (const mp_raw_code_t *)&proto_fun_asyncio_core_sleep_ms,
    (const mp_raw_code_t *)&proto_fun_asyncio_core_sleep,
    (const mp_raw_code_t *)&proto_fun_asyncio_core_IOQueue,
    (const mp_raw_code_t *)&proto_fun_asyncio_core__promote_to_task,
    (const mp_raw_code_t *)&proto_fun_asyncio_core_create_task,
    (const mp_raw_code_t *)&proto_fun_asyncio_core_run_until_complete,
    (const mp_raw_code_t *)&proto_fun_asyncio_core_run,
    (const mp_raw_code_t *)&proto_fun_asyncio_core__stopper,
    (const mp_raw_code_t *)&proto_fun_asyncio_core_Loop,
    (const mp_raw_code_t *)&proto_fun_asyncio_core_get_event_loop,
    (const mp_raw_code_t *)&proto_fun_asyncio_core_current_task,
    (const mp_raw_code_t *)&proto_fun_asyncio_core_new_event_loop,
};

static const mp_raw_code_truncated_t proto_fun_asyncio_core__lt_module_gt_ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_core__lt_module_gt_,
    .children = (void *)&children_asyncio_core__lt_module_gt_,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 218,
    .n_children = 15,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 6,
        .n_exc_stack = 1,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 1,
        .line_info = fun_data_asyncio_core__lt_module_gt_ + 3,
        .line_info_top = fun_data_asyncio_core__lt_module_gt_ + 3,
        .opcodes = fun_data_asyncio_core__lt_module_gt_ + 3,
    },
    #endif
    #endif
};

static const qstr_short_t const_qstr_table_data_asyncio_core[108] = {
    MP_QSTR_asyncio_slash_core_dot_py,
    MP_QSTR__lt_module_gt_,
    MP_QSTR_ticks_ms,
    MP_QSTR_ticks_diff,
    MP_QSTR_ticks_add,
    MP_QSTR_time,
    MP_QSTR_sys,
    MP_QSTR_select,
    MP_QSTR_TaskQueue,
    MP_QSTR_Task,
    MP_QSTR__asyncio,
    MP_QSTR_task,
    MP_QSTR_CancelledError,
    MP_QSTR_TimeoutError,
    MP_QSTR_message,
    MP_QSTR_exception,
    MP_QSTR_future,
    MP_QSTR_SingletonGenerator,
    MP_QSTR_IOQueue,
    MP_QSTR_Loop,
    MP_QSTR_sleep_ms,
    MP_QSTR_state,
    MP_QSTR_sleep,
    MP_QSTR__promote_to_task,
    MP_QSTR_create_task,
    MP_QSTR_send,
    MP_QSTR_push,
    MP_QSTR_run_until_complete,
    MP_QSTR_peek,
    MP_QSTR_ph_key,
    MP_QSTR_map,
    MP_QSTR_wait_io_event,
    MP_QSTR_pop,
    MP_QSTR_data,
    MP_QSTR_coro,
    MP_QSTR_throw,
    MP_QSTR_call_exception_handler,
    MP_QSTR_value,
    MP_QSTR_run,
    MP_QSTR__stopper,
    MP_QSTR_get_event_loop,
    MP_QSTR_current_task,
    MP_QSTR_new_event_loop,
    MP_QSTR___init__,
    MP_QSTR_exc,
    MP_QSTR___iter__,
    MP_QSTR___next__,
    MP_QSTR___traceback__,
    MP_QSTR_poll,
    MP_QSTR_poller,
    MP_QSTR__enqueue,
    MP_QSTR_register,
    MP_QSTR_POLLIN,
    MP_QSTR_POLLOUT,
    MP_QSTR_modify,
    MP_QSTR__dequeue,
    MP_QSTR_unregister,
    MP_QSTR_queue_read,
    MP_QSTR_queue_write,
    MP_QSTR_remove,
    MP_QSTR_ipoll,
    MP_QSTR_run_forever,
    MP_QSTR_stop,
    MP_QSTR_close,
    MP_QSTR_set_exception_handler,
    MP_QSTR__exc_handler,
    MP_QSTR_get_exception_handler,
    MP_QSTR_default_exception_handler,
    MP_QSTR_file,
    MP_QSTR_stderr,
    MP_QSTR_future_colon_,
    MP_QSTR_coro_equals_,
    MP_QSTR_print_exception,
    MP_QSTR_ticks,
    MP_QSTR_BaseException,
    MP_QSTR_Exception,
    MP_QSTR__exc_context,
    MP_QSTR_cur_task,
    MP_QSTR__stop_task,
    MP_QSTR___name__,
    MP_QSTR___module__,
    MP_QSTR___qualname__,
    MP_QSTR_t,
    MP_QSTR_sgen,
    MP_QSTR_max,
    MP_QSTR_int,
    MP_QSTR_aw,
    MP_QSTR_isinstance,
    MP_QSTR_hasattr,
    MP_QSTR_TypeError,
    MP_QSTR_globals,
    MP_QSTR__task_queue,
    MP_QSTR_main_task,
    MP_QSTR_StopIteration,
    MP_QSTR__io_queue,
    MP_QSTR_callable,
    MP_QSTR_runq_len,
    MP_QSTR_waitq_len,
    MP_QSTR_RuntimeError,
    MP_QSTR_self,
    MP_QSTR_s,
    MP_QSTR_idx,
    MP_QSTR_id,
    MP_QSTR_dt,
    MP_QSTR_handler,
    MP_QSTR_loop,
    MP_QSTR_context,
    MP_QSTR_print,
};

// constants
static const mp_obj_str_t const_obj_asyncio_core_0 = {{&mp_type_str}, 64973, 31, (const byte*)"\x54\x61\x73\x6b\x20\x65\x78\x63\x65\x70\x74\x69\x6f\x6e\x20\x77\x61\x73\x6e\x27\x74\x20\x72\x65\x74\x72\x69\x65\x76\x65\x64"};

// constant table
static const mp_rom_obj_t const_obj_table_data_asyncio_core[3] = {
    MP_ROM_PTR(&const_obj_asyncio_core_0),
    MP_ROM_QSTR(MP_QSTR_coroutine_space_expected),
    MP_ROM_QSTR(MP_QSTR_no_space_running_space_event_space_loop),
};

static const mp_frozen_module_t frozen_module_asyncio_core = {
    .constants = {
        .qstr_table = (qstr_short_t *)&const_qstr_table_data_asyncio_core,
        .obj_table = (mp_obj_t *)&const_obj_table_data_asyncio_core,
    },
    .proto_fun = &proto_fun_asyncio_core__lt_module_gt_,
};

////////////////////////////////////////////////////////////////////////////////
// frozen module asyncio_event
// - original source file: /Users/gadgetoid/Development/micropython-web/picovector/ports/sokol/build/frozen_mpy/asyncio/event.mpy
// - frozen file name: asyncio/event.py
// - .mpy header: 4d:06:00:1f

// frozen bytecode for file asyncio/event.py, scope asyncio_event__lt_module_gt_
static const byte fun_data_asyncio_event__lt_module_gt_[59] = {
    0x2c,0x02, // prelude
    0x01, // names: <module>
     // code info
    0x81, // LOAD_CONST_SMALL_INT 1
    0x10,0x02, // LOAD_CONST_STRING 'core'
    0x2a,0x01, // BUILD_TUPLE 1
    0x1b,0x03, // IMPORT_NAME ''
    0x1c,0x02, // IMPORT_FROM 'core'
    0x16,0x02, // STORE_NAME 'core'
    0x59, // POP_TOP
    0x54, // LOAD_BUILD_CLASS
    0x32,0x00, // MAKE_FUNCTION 0
    0x10,0x04, // LOAD_CONST_STRING 'Event'
    0x34,0x02, // CALL_FUNCTION 2
    0x16,0x04, // STORE_NAME 'Event'
    0x48,0x15, // SETUP_EXCEPT 21
    0x80, // LOAD_CONST_SMALL_INT 0
    0x51, // LOAD_CONST_NONE
    0x1b,0x05, // IMPORT_NAME 'io'
    0x16,0x05, // STORE_NAME 'io'
    0x54, // LOAD_BUILD_CLASS
    0x32,0x01, // MAKE_FUNCTION 1
    0x10,0x06, // LOAD_CONST_STRING 'ThreadSafeFlag'
    0x11,0x05, // LOAD_NAME 'io'
    0x13,0x07, // LOAD_ATTR 'IOBase'
    0x34,0x03, // CALL_FUNCTION 3
    0x16,0x06, // STORE_NAME 'ThreadSafeFlag'
    0x4a,0x0a, // POP_EXCEPT_JUMP 10
    0x57, // DUP_TOP
    0x11,0x19, // LOAD_NAME 'ImportError'
    0xdf, // BINARY_OP 8 <exception match>
    0x44,0x43, // POP_JUMP_IF_FALSE 3
    0x59, // POP_TOP
    0x4a,0x01, // POP_EXCEPT_JUMP 1
    0x5d, // END_FINALLY
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
// child of asyncio_event__lt_module_gt_
// frozen bytecode for file asyncio/event.py, scope asyncio_event_Event
static const byte fun_data_asyncio_event_Event[33] = {
    0x00,0x02, // prelude
    0x04, // names: Event
     // code info
    0x11,0x1a, // LOAD_NAME '__name__'
    0x16,0x1b, // STORE_NAME '__module__'
    0x10,0x04, // LOAD_CONST_STRING 'Event'
    0x16,0x1c, // STORE_NAME '__qualname__'
    0x32,0x00, // MAKE_FUNCTION 0
    0x16,0x08, // STORE_NAME '__init__'
    0x32,0x01, // MAKE_FUNCTION 1
    0x16,0x0c, // STORE_NAME 'is_set'
    0x32,0x02, // MAKE_FUNCTION 2
    0x16,0x0d, // STORE_NAME 'set'
    0x32,0x03, // MAKE_FUNCTION 3
    0x16,0x12, // STORE_NAME 'clear'
    0x32,0x04, // MAKE_FUNCTION 4
    0x16,0x13, // STORE_NAME 'wait'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
// child of asyncio_event_Event
// frozen bytecode for file asyncio/event.py, scope asyncio_event_Event___init__
static const byte fun_data_asyncio_event_Event___init__[19] = {
    0x11,0x04, // prelude
    0x08,0x1d, // names: __init__, self
     // code info
    0x50, // LOAD_CONST_FALSE
    0xb0, // LOAD_FAST 0
    0x18,0x09, // STORE_ATTR 'state'
    0x12,0x02, // LOAD_GLOBAL 'core'
    0x14,0x0a, // LOAD_METHOD 'TaskQueue'
    0x36,0x00, // CALL_METHOD 0
    0xb0, // LOAD_FAST 0
    0x18,0x0b, // STORE_ATTR 'waiting'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_event_Event___init__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_event_Event___init__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 19,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 8,
        .line_info = fun_data_asyncio_event_Event___init__ + 4,
        .line_info_top = fun_data_asyncio_event_Event___init__ + 4,
        .opcodes = fun_data_asyncio_event_Event___init__ + 4,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_event_Event___init__ fun_data_asyncio_event_Event___init__[0]
#endif

// child of asyncio_event_Event
// frozen bytecode for file asyncio/event.py, scope asyncio_event_Event_is_set
static const byte fun_data_asyncio_event_Event_is_set[8] = {
    0x09,0x04, // prelude
    0x0c,0x1d, // names: is_set, self
     // code info
    0xb0, // LOAD_FAST 0
    0x13,0x09, // LOAD_ATTR 'state'
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_event_Event_is_set = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_event_Event_is_set,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 8,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 2,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 12,
        .line_info = fun_data_asyncio_event_Event_is_set + 4,
        .line_info_top = fun_data_asyncio_event_Event_is_set + 4,
        .opcodes = fun_data_asyncio_event_Event_is_set + 4,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_event_Event_is_set fun_data_asyncio_event_Event_is_set[0]
#endif

// child of asyncio_event_Event
// frozen bytecode for file asyncio/event.py, scope asyncio_event_Event_set
static const byte fun_data_asyncio_event_Event_set[37] = {
    0x21,0x04, // prelude
    0x0d,0x1d, // names: set, self
     // code info
    0x42,0x50, // JUMP 16
    0x12,0x02, // LOAD_GLOBAL 'core'
    0x13,0x0e, // LOAD_ATTR '_task_queue'
    0x14,0x0f, // LOAD_METHOD 'push'
    0xb0, // LOAD_FAST 0
    0x13,0x0b, // LOAD_ATTR 'waiting'
    0x14,0x10, // LOAD_METHOD 'pop'
    0x36,0x00, // CALL_METHOD 0
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0xb0, // LOAD_FAST 0
    0x13,0x0b, // LOAD_ATTR 'waiting'
    0x14,0x11, // LOAD_METHOD 'peek'
    0x36,0x00, // CALL_METHOD 0
    0x43,0x27, // POP_JUMP_IF_TRUE -25
    0x52, // LOAD_CONST_TRUE
    0xb0, // LOAD_FAST 0
    0x18,0x09, // STORE_ATTR 'state'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_event_Event_set = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_event_Event_set,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 37,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 13,
        .line_info = fun_data_asyncio_event_Event_set + 4,
        .line_info_top = fun_data_asyncio_event_Event_set + 4,
        .opcodes = fun_data_asyncio_event_Event_set + 4,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_event_Event_set fun_data_asyncio_event_Event_set[0]
#endif

// child of asyncio_event_Event
// frozen bytecode for file asyncio/event.py, scope asyncio_event_Event_clear
static const byte fun_data_asyncio_event_Event_clear[10] = {
    0x11,0x04, // prelude
    0x12,0x1d, // names: clear, self
     // code info
    0x50, // LOAD_CONST_FALSE
    0xb0, // LOAD_FAST 0
    0x18,0x09, // STORE_ATTR 'state'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_event_Event_clear = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_event_Event_clear,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 10,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 18,
        .line_info = fun_data_asyncio_event_Event_clear + 4,
        .line_info_top = fun_data_asyncio_event_Event_clear + 4,
        .opcodes = fun_data_asyncio_event_Event_clear + 4,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_event_Event_clear fun_data_asyncio_event_Event_clear[0]
#endif

// child of asyncio_event_Event
// frozen bytecode for file asyncio/event.py, scope asyncio_event_Event_wait
static const byte fun_data_asyncio_event_Event_wait[36] = {
    0x99,0x40,0x04, // prelude
    0x13,0x1d, // names: wait, self
     // code info
    0xb0, // LOAD_FAST 0
    0x13,0x09, // LOAD_ATTR 'state'
    0x43,0x58, // POP_JUMP_IF_TRUE 24
    0xb0, // LOAD_FAST 0
    0x13,0x0b, // LOAD_ATTR 'waiting'
    0x14,0x0f, // LOAD_METHOD 'push'
    0x12,0x02, // LOAD_GLOBAL 'core'
    0x13,0x14, // LOAD_ATTR 'cur_task'
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0xb0, // LOAD_FAST 0
    0x13,0x0b, // LOAD_ATTR 'waiting'
    0x12,0x02, // LOAD_GLOBAL 'core'
    0x13,0x14, // LOAD_ATTR 'cur_task'
    0x18,0x15, // STORE_ATTR 'data'
    0x51, // LOAD_CONST_NONE
    0x67, // YIELD_VALUE
    0x59, // POP_TOP
    0x52, // LOAD_CONST_TRUE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_event_Event_wait = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 1,
    .fun_data = fun_data_asyncio_event_Event_wait,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 36,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 1,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 19,
        .line_info = fun_data_asyncio_event_Event_wait + 5,
        .line_info_top = fun_data_asyncio_event_Event_wait + 5,
        .opcodes = fun_data_asyncio_event_Event_wait + 5,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_event_Event_wait fun_data_asyncio_event_Event_wait[0]
#endif

static const mp_raw_code_t *const children_asyncio_event_Event[] = {
    (const mp_raw_code_t *)&proto_fun_asyncio_event_Event___init__,
    (const mp_raw_code_t *)&proto_fun_asyncio_event_Event_is_set,
    (const mp_raw_code_t *)&proto_fun_asyncio_event_Event_set,
    (const mp_raw_code_t *)&proto_fun_asyncio_event_Event_clear,
    (const mp_raw_code_t *)&proto_fun_asyncio_event_Event_wait,
};

static const mp_raw_code_truncated_t proto_fun_asyncio_event_Event = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_event_Event,
    .children = (void *)&children_asyncio_event_Event,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 33,
    .n_children = 5,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 1,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 4,
        .line_info = fun_data_asyncio_event_Event + 3,
        .line_info_top = fun_data_asyncio_event_Event + 3,
        .opcodes = fun_data_asyncio_event_Event + 3,
    },
    #endif
    #endif
};

// child of asyncio_event__lt_module_gt_
// frozen bytecode for file asyncio/event.py, scope asyncio_event_ThreadSafeFlag
static const byte fun_data_asyncio_event_ThreadSafeFlag[33] = {
    0x00,0x02, // prelude
    0x06, // names: ThreadSafeFlag
     // code info
    0x11,0x1a, // LOAD_NAME '__name__'
    0x16,0x1b, // STORE_NAME '__module__'
    0x10,0x06, // LOAD_CONST_STRING 'ThreadSafeFlag'
    0x16,0x1c, // STORE_NAME '__qualname__'
    0x32,0x00, // MAKE_FUNCTION 0
    0x16,0x08, // STORE_NAME '__init__'
    0x32,0x01, // MAKE_FUNCTION 1
    0x16,0x16, // STORE_NAME 'ioctl'
    0x32,0x02, // MAKE_FUNCTION 2
    0x16,0x0d, // STORE_NAME 'set'
    0x32,0x03, // MAKE_FUNCTION 3
    0x16,0x12, // STORE_NAME 'clear'
    0x32,0x04, // MAKE_FUNCTION 4
    0x16,0x13, // STORE_NAME 'wait'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
// child of asyncio_event_ThreadSafeFlag
// frozen bytecode for file asyncio/event.py, scope asyncio_event_ThreadSafeFlag___init__
static const byte fun_data_asyncio_event_ThreadSafeFlag___init__[10] = {
    0x11,0x04, // prelude
    0x08,0x1d, // names: __init__, self
     // code info
    0x80, // LOAD_CONST_SMALL_INT 0
    0xb0, // LOAD_FAST 0
    0x18,0x09, // STORE_ATTR 'state'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_event_ThreadSafeFlag___init__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_event_ThreadSafeFlag___init__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 10,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 8,
        .line_info = fun_data_asyncio_event_ThreadSafeFlag___init__ + 4,
        .line_info_top = fun_data_asyncio_event_ThreadSafeFlag___init__ + 4,
        .opcodes = fun_data_asyncio_event_ThreadSafeFlag___init__ + 4,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_event_ThreadSafeFlag___init__ fun_data_asyncio_event_ThreadSafeFlag___init__[0]
#endif

// child of asyncio_event_ThreadSafeFlag
// frozen bytecode for file asyncio/event.py, scope asyncio_event_ThreadSafeFlag_ioctl
static const byte fun_data_asyncio_event_ThreadSafeFlag_ioctl[19] = {
    0x23,0x08, // prelude
    0x16,0x1d,0x1e,0x1f, // names: ioctl, self, req, flags
     // code info
    0xb1, // LOAD_FAST 1
    0x83, // LOAD_CONST_SMALL_INT 3
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x46, // POP_JUMP_IF_FALSE 6
    0xb0, // LOAD_FAST 0
    0x13,0x09, // LOAD_ATTR 'state'
    0xb2, // LOAD_FAST 2
    0xf4, // BINARY_OP 29 __mul__
    0x63, // RETURN_VALUE
    0x7f, // LOAD_CONST_SMALL_INT -1
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_event_ThreadSafeFlag_ioctl = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_event_ThreadSafeFlag_ioctl,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 19,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 3,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 22,
        .line_info = fun_data_asyncio_event_ThreadSafeFlag_ioctl + 6,
        .line_info_top = fun_data_asyncio_event_ThreadSafeFlag_ioctl + 6,
        .opcodes = fun_data_asyncio_event_ThreadSafeFlag_ioctl + 6,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_event_ThreadSafeFlag_ioctl fun_data_asyncio_event_ThreadSafeFlag_ioctl[0]
#endif

// child of asyncio_event_ThreadSafeFlag
// frozen bytecode for file asyncio/event.py, scope asyncio_event_ThreadSafeFlag_set
static const byte fun_data_asyncio_event_ThreadSafeFlag_set[10] = {
    0x11,0x04, // prelude
    0x0d,0x1d, // names: set, self
     // code info
    0x81, // LOAD_CONST_SMALL_INT 1
    0xb0, // LOAD_FAST 0
    0x18,0x09, // STORE_ATTR 'state'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_event_ThreadSafeFlag_set = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_event_ThreadSafeFlag_set,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 10,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 13,
        .line_info = fun_data_asyncio_event_ThreadSafeFlag_set + 4,
        .line_info_top = fun_data_asyncio_event_ThreadSafeFlag_set + 4,
        .opcodes = fun_data_asyncio_event_ThreadSafeFlag_set + 4,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_event_ThreadSafeFlag_set fun_data_asyncio_event_ThreadSafeFlag_set[0]
#endif

// child of asyncio_event_ThreadSafeFlag
// frozen bytecode for file asyncio/event.py, scope asyncio_event_ThreadSafeFlag_clear
static const byte fun_data_asyncio_event_ThreadSafeFlag_clear[10] = {
    0x11,0x04, // prelude
    0x12,0x1d, // names: clear, self
     // code info
    0x80, // LOAD_CONST_SMALL_INT 0
    0xb0, // LOAD_FAST 0
    0x18,0x09, // STORE_ATTR 'state'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_event_ThreadSafeFlag_clear = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_event_ThreadSafeFlag_clear,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 10,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 18,
        .line_info = fun_data_asyncio_event_ThreadSafeFlag_clear + 4,
        .line_info_top = fun_data_asyncio_event_ThreadSafeFlag_clear + 4,
        .opcodes = fun_data_asyncio_event_ThreadSafeFlag_clear + 4,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_event_ThreadSafeFlag_clear fun_data_asyncio_event_ThreadSafeFlag_clear[0]
#endif

// child of asyncio_event_ThreadSafeFlag
// frozen bytecode for file asyncio/event.py, scope asyncio_event_ThreadSafeFlag_wait
static const byte fun_data_asyncio_event_ThreadSafeFlag_wait[27] = {
    0x99,0x40,0x04, // prelude
    0x13,0x1d, // names: wait, self
     // code info
    0xb0, // LOAD_FAST 0
    0x13,0x09, // LOAD_ATTR 'state'
    0x43,0x4b, // POP_JUMP_IF_TRUE 11
    0x12,0x02, // LOAD_GLOBAL 'core'
    0x13,0x17, // LOAD_ATTR '_io_queue'
    0x14,0x18, // LOAD_METHOD 'queue_read'
    0xb0, // LOAD_FAST 0
    0x36,0x01, // CALL_METHOD 1
    0x67, // YIELD_VALUE
    0x59, // POP_TOP
    0x80, // LOAD_CONST_SMALL_INT 0
    0xb0, // LOAD_FAST 0
    0x18,0x09, // STORE_ATTR 'state'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_event_ThreadSafeFlag_wait = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 1,
    .fun_data = fun_data_asyncio_event_ThreadSafeFlag_wait,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 27,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 1,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 19,
        .line_info = fun_data_asyncio_event_ThreadSafeFlag_wait + 5,
        .line_info_top = fun_data_asyncio_event_ThreadSafeFlag_wait + 5,
        .opcodes = fun_data_asyncio_event_ThreadSafeFlag_wait + 5,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_event_ThreadSafeFlag_wait fun_data_asyncio_event_ThreadSafeFlag_wait[0]
#endif

static const mp_raw_code_t *const children_asyncio_event_ThreadSafeFlag[] = {
    (const mp_raw_code_t *)&proto_fun_asyncio_event_ThreadSafeFlag___init__,
    (const mp_raw_code_t *)&proto_fun_asyncio_event_ThreadSafeFlag_ioctl,
    (const mp_raw_code_t *)&proto_fun_asyncio_event_ThreadSafeFlag_set,
    (const mp_raw_code_t *)&proto_fun_asyncio_event_ThreadSafeFlag_clear,
    (const mp_raw_code_t *)&proto_fun_asyncio_event_ThreadSafeFlag_wait,
};

static const mp_raw_code_truncated_t proto_fun_asyncio_event_ThreadSafeFlag = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_event_ThreadSafeFlag,
    .children = (void *)&children_asyncio_event_ThreadSafeFlag,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 33,
    .n_children = 5,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 1,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 6,
        .line_info = fun_data_asyncio_event_ThreadSafeFlag + 3,
        .line_info_top = fun_data_asyncio_event_ThreadSafeFlag + 3,
        .opcodes = fun_data_asyncio_event_ThreadSafeFlag + 3,
    },
    #endif
    #endif
};

static const mp_raw_code_t *const children_asyncio_event__lt_module_gt_[] = {
    (const mp_raw_code_t *)&proto_fun_asyncio_event_Event,
    (const mp_raw_code_t *)&proto_fun_asyncio_event_ThreadSafeFlag,
};

static const mp_raw_code_truncated_t proto_fun_asyncio_event__lt_module_gt_ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_event__lt_module_gt_,
    .children = (void *)&children_asyncio_event__lt_module_gt_,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 59,
    .n_children = 2,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 6,
        .n_exc_stack = 1,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 1,
        .line_info = fun_data_asyncio_event__lt_module_gt_ + 3,
        .line_info_top = fun_data_asyncio_event__lt_module_gt_ + 3,
        .opcodes = fun_data_asyncio_event__lt_module_gt_ + 3,
    },
    #endif
    #endif
};

static const qstr_short_t const_qstr_table_data_asyncio_event[32] = {
    MP_QSTR_asyncio_slash_event_dot_py,
    MP_QSTR__lt_module_gt_,
    MP_QSTR_core,
    MP_QSTR_,
    MP_QSTR_Event,
    MP_QSTR_io,
    MP_QSTR_ThreadSafeFlag,
    MP_QSTR_IOBase,
    MP_QSTR___init__,
    MP_QSTR_state,
    MP_QSTR_TaskQueue,
    MP_QSTR_waiting,
    MP_QSTR_is_set,
    MP_QSTR_set,
    MP_QSTR__task_queue,
    MP_QSTR_push,
    MP_QSTR_pop,
    MP_QSTR_peek,
    MP_QSTR_clear,
    MP_QSTR_wait,
    MP_QSTR_cur_task,
    MP_QSTR_data,
    MP_QSTR_ioctl,
    MP_QSTR__io_queue,
    MP_QSTR_queue_read,
    MP_QSTR_ImportError,
    MP_QSTR___name__,
    MP_QSTR___module__,
    MP_QSTR___qualname__,
    MP_QSTR_self,
    MP_QSTR_req,
    MP_QSTR_flags,
};

static const mp_frozen_module_t frozen_module_asyncio_event = {
    .constants = {
        .qstr_table = (qstr_short_t *)&const_qstr_table_data_asyncio_event,
        .obj_table = NULL,
    },
    .proto_fun = &proto_fun_asyncio_event__lt_module_gt_,
};

////////////////////////////////////////////////////////////////////////////////
// frozen module asyncio_funcs
// - original source file: /Users/gadgetoid/Development/micropython-web/picovector/ports/sokol/build/frozen_mpy/asyncio/funcs.mpy
// - frozen file name: asyncio/funcs.py
// - .mpy header: 4d:06:00:1f

// frozen bytecode for file asyncio/funcs.py, scope asyncio_funcs__lt_module_gt_
static const byte fun_data_asyncio_funcs__lt_module_gt_[56] = {
    0x18,0x02, // prelude
    0x01, // names: <module>
     // code info
    0x81, // LOAD_CONST_SMALL_INT 1
    0x10,0x02, // LOAD_CONST_STRING 'core'
    0x2a,0x01, // BUILD_TUPLE 1
    0x1b,0x03, // IMPORT_NAME ''
    0x1c,0x02, // IMPORT_FROM 'core'
    0x16,0x02, // STORE_NAME 'core'
    0x59, // POP_TOP
    0x32,0x00, // MAKE_FUNCTION 0
    0x16,0x07, // STORE_NAME '_run'
    0x11,0x02, // LOAD_NAME 'core'
    0x13,0x04, // LOAD_ATTR 'sleep'
    0x2a,0x01, // BUILD_TUPLE 1
    0x53, // LOAD_NULL
    0x33,0x01, // MAKE_FUNCTION_DEFARGS 1
    0x16,0x0b, // STORE_NAME 'wait_for'
    0x32,0x02, // MAKE_FUNCTION 2
    0x16,0x12, // STORE_NAME 'wait_for_ms'
    0x54, // LOAD_BUILD_CLASS
    0x32,0x03, // MAKE_FUNCTION 3
    0x10,0x05, // LOAD_CONST_STRING '_Remove'
    0x34,0x02, // CALL_FUNCTION 2
    0x16,0x05, // STORE_NAME '_Remove'
    0x53, // LOAD_NULL
    0x2c,0x00, // BUILD_MAP 0
    0x50, // LOAD_CONST_FALSE
    0x10,0x06, // LOAD_CONST_STRING 'return_exceptions'
    0x62, // STORE_MAP
    0x33,0x04, // MAKE_FUNCTION_DEFARGS 4
    0x16,0x14, // STORE_NAME 'gather'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
// child of asyncio_funcs__lt_module_gt_
// frozen bytecode for file asyncio/funcs.py, scope asyncio_funcs__run
static const byte fun_data_asyncio_funcs__run[66] = {
    0xd2,0x42,0x06, // prelude
    0x07,0x1b,0x1c, // names: _run, waiter, aw
     // code info
    0x48,0x09, // SETUP_EXCEPT 9
    0xb1, // LOAD_FAST 1
    0x5e, // GET_ITER
    0x51, // LOAD_CONST_NONE
    0x68, // YIELD_FROM
    0xc2, // STORE_FAST 2
    0x52, // LOAD_CONST_TRUE
    0xc3, // STORE_FAST 3
    0x4a,0x16, // POP_EXCEPT_JUMP 22
    0x57, // DUP_TOP
    0x12,0x1d, // LOAD_GLOBAL 'BaseException'
    0xdf, // BINARY_OP 8 <exception match>
    0x44,0x4f, // POP_JUMP_IF_FALSE 15
    0xc4, // STORE_FAST 4
    0x49,0x05, // SETUP_FINALLY 5
    0x51, // LOAD_CONST_NONE
    0xc2, // STORE_FAST 2
    0xb4, // LOAD_FAST 4
    0xc3, // STORE_FAST 3
    0x51, // LOAD_CONST_NONE
    0x51, // LOAD_CONST_NONE
    0xc4, // STORE_FAST 4
    0x28,0x04, // DELETE_FAST 4
    0x5d, // END_FINALLY
    0x4a,0x01, // POP_EXCEPT_JUMP 1
    0x5d, // END_FINALLY
    0xb0, // LOAD_FAST 0
    0x13,0x08, // LOAD_ATTR 'data'
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0x44,0x52, // POP_JUMP_IF_FALSE 18
    0xb0, // LOAD_FAST 0
    0x14,0x09, // LOAD_METHOD 'cancel'
    0x36,0x00, // CALL_METHOD 0
    0x44,0x4b, // POP_JUMP_IF_FALSE 11
    0x12,0x02, // LOAD_GLOBAL 'core'
    0x14,0x0a, // LOAD_METHOD 'CancelledError'
    0xb3, // LOAD_FAST 3
    0xb2, // LOAD_FAST 2
    0x36,0x02, // CALL_METHOD 2
    0xb0, // LOAD_FAST 0
    0x18,0x08, // STORE_ATTR 'data'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_funcs__run = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 1,
    .fun_data = fun_data_asyncio_funcs__run,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 66,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 11,
        .n_exc_stack = 2,
        .scope_flags = 1,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 7,
        .line_info = fun_data_asyncio_funcs__run + 6,
        .line_info_top = fun_data_asyncio_funcs__run + 6,
        .opcodes = fun_data_asyncio_funcs__run + 6,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_funcs__run fun_data_asyncio_funcs__run[0]
#endif

// child of asyncio_funcs__lt_module_gt_
// frozen bytecode for file asyncio/funcs.py, scope asyncio_funcs_wait_for
static const byte fun_data_asyncio_funcs_wait_for[119] = {
    0xdb,0x43,0x08, // prelude
    0x0b,0x1c,0x1e,0x04, // names: wait_for, aw, timeout, sleep
     // code info
    0x12,0x02, // LOAD_GLOBAL 'core'
    0x14,0x0c, // LOAD_METHOD '_promote_to_task'
    0xb0, // LOAD_FAST 0
    0x36,0x01, // CALL_METHOD 1
    0xc0, // STORE_FAST 0
    0xb1, // LOAD_FAST 1
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0x44,0x45, // POP_JUMP_IF_FALSE 5
    0xb0, // LOAD_FAST 0
    0x5e, // GET_ITER
    0x51, // LOAD_CONST_NONE
    0x68, // YIELD_FROM
    0x63, // RETURN_VALUE
    0x12,0x02, // LOAD_GLOBAL 'core'
    0x14,0x0d, // LOAD_METHOD 'create_task'
    0x12,0x07, // LOAD_GLOBAL '_run'
    0x12,0x02, // LOAD_GLOBAL 'core'
    0x13,0x0e, // LOAD_ATTR 'cur_task'
    0xb0, // LOAD_FAST 0
    0x34,0x02, // CALL_FUNCTION 2
    0x36,0x01, // CALL_METHOD 1
    0xc3, // STORE_FAST 3
    0x48,0x0a, // SETUP_EXCEPT 10
    0xb2, // LOAD_FAST 2
    0xb1, // LOAD_FAST 1
    0x34,0x01, // CALL_FUNCTION 1
    0x5e, // GET_ITER
    0x51, // LOAD_CONST_NONE
    0x68, // YIELD_FROM
    0x59, // POP_TOP
    0x4a,0x32, // POP_EXCEPT_JUMP 50
    0x57, // DUP_TOP
    0x12,0x02, // LOAD_GLOBAL 'core'
    0x13,0x0a, // LOAD_ATTR 'CancelledError'
    0xdf, // BINARY_OP 8 <exception match>
    0x44,0x69, // POP_JUMP_IF_FALSE 41
    0xc4, // STORE_FAST 4
    0x49,0x1f, // SETUP_FINALLY 31
    0xb4, // LOAD_FAST 4
    0x13,0x0f, // LOAD_ATTR 'value'
    0xc5, // STORE_FAST 5
    0xb5, // LOAD_FAST 5
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0x44,0x48, // POP_JUMP_IF_FALSE 8
    0xb3, // LOAD_FAST 3
    0x14,0x09, // LOAD_METHOD 'cancel'
    0x36,0x00, // CALL_METHOD 0
    0x59, // POP_TOP
    0xb4, // LOAD_FAST 4
    0x65, // RAISE_OBJ
    0xb5, // LOAD_FAST 5
    0x52, // LOAD_CONST_TRUE
    0xde, // BINARY_OP 7 <is>
    0x44,0x46, // POP_JUMP_IF_FALSE 6
    0xb4, // LOAD_FAST 4
    0x13,0x10, // LOAD_ATTR 'args'
    0x81, // LOAD_CONST_SMALL_INT 1
    0x55, // LOAD_SUBSCR
    0x63, // RETURN_VALUE
    0xb5, // LOAD_FAST 5
    0x65, // RAISE_OBJ
    0x51, // LOAD_CONST_NONE
    0x51, // LOAD_CONST_NONE
    0xc4, // STORE_FAST 4
    0x28,0x04, // DELETE_FAST 4
    0x5d, // END_FINALLY
    0x4a,0x01, // POP_EXCEPT_JUMP 1
    0x5d, // END_FINALLY
    0xb3, // LOAD_FAST 3
    0x14,0x09, // LOAD_METHOD 'cancel'
    0x36,0x00, // CALL_METHOD 0
    0x59, // POP_TOP
    0xb3, // LOAD_FAST 3
    0x5e, // GET_ITER
    0x51, // LOAD_CONST_NONE
    0x68, // YIELD_FROM
    0x59, // POP_TOP
    0x12,0x02, // LOAD_GLOBAL 'core'
    0x13,0x11, // LOAD_ATTR 'TimeoutError'
    0x65, // RAISE_OBJ
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_funcs_wait_for = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 1,
    .fun_data = fun_data_asyncio_funcs_wait_for,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 119,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 12,
        .n_exc_stack = 2,
        .scope_flags = 1,
        .n_pos_args = 3,
        .n_kwonly_args = 0,
        .n_def_pos_args = 1,
        .qstr_block_name_idx = 11,
        .line_info = fun_data_asyncio_funcs_wait_for + 7,
        .line_info_top = fun_data_asyncio_funcs_wait_for + 7,
        .opcodes = fun_data_asyncio_funcs_wait_for + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_funcs_wait_for fun_data_asyncio_funcs_wait_for[0]
#endif

// child of asyncio_funcs__lt_module_gt_
// frozen bytecode for file asyncio/funcs.py, scope asyncio_funcs_wait_for_ms
static const byte fun_data_asyncio_funcs_wait_for_ms[16] = {
    0x2a,0x06, // prelude
    0x12,0x1c,0x1e, // names: wait_for_ms, aw, timeout
     // code info
    0x12,0x0b, // LOAD_GLOBAL 'wait_for'
    0xb0, // LOAD_FAST 0
    0xb1, // LOAD_FAST 1
    0x12,0x02, // LOAD_GLOBAL 'core'
    0x13,0x13, // LOAD_ATTR 'sleep_ms'
    0x34,0x03, // CALL_FUNCTION 3
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_funcs_wait_for_ms = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_funcs_wait_for_ms,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 16,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 6,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 18,
        .line_info = fun_data_asyncio_funcs_wait_for_ms + 5,
        .line_info_top = fun_data_asyncio_funcs_wait_for_ms + 5,
        .opcodes = fun_data_asyncio_funcs_wait_for_ms + 5,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_funcs_wait_for_ms fun_data_asyncio_funcs_wait_for_ms[0]
#endif

// child of asyncio_funcs__lt_module_gt_
// frozen bytecode for file asyncio/funcs.py, scope asyncio_funcs__Remove
static const byte fun_data_asyncio_funcs__Remove[21] = {
    0x08,0x02, // prelude
    0x05, // names: _Remove
     // code info
    0x11,0x1f, // LOAD_NAME '__name__'
    0x16,0x20, // STORE_NAME '__module__'
    0x10,0x05, // LOAD_CONST_STRING '_Remove'
    0x16,0x21, // STORE_NAME '__qualname__'
    0x11,0x22, // LOAD_NAME 'staticmethod'
    0x32,0x00, // MAKE_FUNCTION 0
    0x34,0x01, // CALL_FUNCTION 1
    0x16,0x16, // STORE_NAME 'remove'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
// child of asyncio_funcs__Remove
// frozen bytecode for file asyncio/funcs.py, scope asyncio_funcs__Remove_remove
static const byte fun_data_asyncio_funcs__Remove_remove[6] = {
    0x09,0x04, // prelude
    0x16,0x28, // names: remove, t
     // code info
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_funcs__Remove_remove = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_funcs__Remove_remove,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 6,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 2,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 22,
        .line_info = fun_data_asyncio_funcs__Remove_remove + 4,
        .line_info_top = fun_data_asyncio_funcs__Remove_remove + 4,
        .opcodes = fun_data_asyncio_funcs__Remove_remove + 4,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_funcs__Remove_remove fun_data_asyncio_funcs__Remove_remove[0]
#endif

static const mp_raw_code_t *const children_asyncio_funcs__Remove[] = {
    (const mp_raw_code_t *)&proto_fun_asyncio_funcs__Remove_remove,
};

static const mp_raw_code_truncated_t proto_fun_asyncio_funcs__Remove = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_funcs__Remove,
    .children = (void *)&children_asyncio_funcs__Remove,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 21,
    .n_children = 1,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 2,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 5,
        .line_info = fun_data_asyncio_funcs__Remove + 3,
        .line_info_top = fun_data_asyncio_funcs__Remove + 3,
        .opcodes = fun_data_asyncio_funcs__Remove + 3,
    },
    #endif
    #endif
};

// child of asyncio_funcs__lt_module_gt_
// frozen bytecode for file asyncio/funcs.py, scope asyncio_funcs_gather
static const byte fun_data_asyncio_funcs_gather[281] = {
    0xf0,0xca,0x80,0xc0,0x40,0x85,0x01, // prelude
    0x14,0x06, // names: gather, return_exceptions
    0x00,0x07,0x08, // code info
    0xb0, // LOAD_FAST 0
    0xb7, // LOAD_FAST 7
    0xb8, // LOAD_FAST 8
    0x20,0x00,0x03, // MAKE_CLOSURE 0
    0xc2, // STORE_FAST 2
    0x32,0x01, // MAKE_FUNCTION 1
    0xb1, // LOAD_FAST 1
    0x34,0x01, // CALL_FUNCTION 1
    0xc3, // STORE_FAST 3
    0x80, // LOAD_CONST_SMALL_INT 0
    0x27,0x07, // STORE_DEREF 7
    0x12,0x23, // LOAD_GLOBAL 'len'
    0xb3, // LOAD_FAST 3
    0x34,0x01, // CALL_FUNCTION 1
    0x80, // LOAD_CONST_SMALL_INT 0
    0x42,0xc4,0x80, // JUMP 68
    0x57, // DUP_TOP
    0xc4, // STORE_FAST 4
    0xb3, // LOAD_FAST 3
    0xb4, // LOAD_FAST 4
    0x55, // LOAD_SUBSCR
    0x13,0x15, // LOAD_ATTR 'state'
    0x52, // LOAD_CONST_TRUE
    0xde, // BINARY_OP 7 <is>
    0x44,0x4e, // POP_JUMP_IF_FALSE 14
    0xb2, // LOAD_FAST 2
    0xb3, // LOAD_FAST 3
    0xb4, // LOAD_FAST 4
    0x55, // LOAD_SUBSCR
    0x18,0x15, // STORE_ATTR 'state'
    0x25,0x07, // LOAD_DEREF 7
    0x81, // LOAD_CONST_SMALL_INT 1
    0xe5, // BINARY_OP 14 __iadd__
    0x27,0x07, // STORE_DEREF 7
    0x42,0x69, // JUMP 41
    0xb3, // LOAD_FAST 3
    0xb4, // LOAD_FAST 4
    0x55, // LOAD_SUBSCR
    0x13,0x15, // LOAD_ATTR 'state'
    0x43,0x5b, // POP_JUMP_IF_TRUE 27
    0x12,0x24, // LOAD_GLOBAL 'isinstance'
    0xb3, // LOAD_FAST 3
    0xb4, // LOAD_FAST 4
    0x55, // LOAD_SUBSCR
    0x13,0x08, // LOAD_ATTR 'data'
    0x12,0x25, // LOAD_GLOBAL 'StopIteration'
    0x34,0x02, // CALL_FUNCTION 2
    0x43,0x4c, // POP_JUMP_IF_TRUE 12
    0x25,0x00, // LOAD_DEREF 0
    0x43,0x48, // POP_JUMP_IF_TRUE 8
    0x12,0x23, // LOAD_GLOBAL 'len'
    0xb3, // LOAD_FAST 3
    0x34,0x01, // CALL_FUNCTION 1
    0xd1, // UNARY_OP 1 __neg__
    0x27,0x07, // STORE_DEREF 7
    0x42,0x47, // JUMP 7
    0x12,0x26, // LOAD_GLOBAL 'RuntimeError'
    0x23,0x00, // LOAD_CONST_OBJ 0
    0x34,0x01, // CALL_FUNCTION 1
    0x65, // RAISE_OBJ
    0x81, // LOAD_CONST_SMALL_INT 1
    0xe5, // BINARY_OP 14 __iadd__
    0x58, // DUP_TOP_TWO
    0x5a, // ROT_TWO
    0xd7, // BINARY_OP 0 __lt__
    0x43,0xb6,0x7f, // POP_JUMP_IF_TRUE -74
    0x59, // POP_TOP
    0x59, // POP_TOP
    0x12,0x02, // LOAD_GLOBAL 'core'
    0x13,0x0e, // LOAD_ATTR 'cur_task'
    0x27,0x08, // STORE_DEREF 8
    0x50, // LOAD_CONST_FALSE
    0xc5, // STORE_FAST 5
    0x25,0x07, // LOAD_DEREF 7
    0x80, // LOAD_CONST_SMALL_INT 0
    0xd8, // BINARY_OP 1 __gt__
    0x44,0x66, // POP_JUMP_IF_FALSE 38
    0x12,0x05, // LOAD_GLOBAL '_Remove'
    0x25,0x08, // LOAD_DEREF 8
    0x18,0x08, // STORE_ATTR 'data'
    0x48,0x05, // SETUP_EXCEPT 5
    0x51, // LOAD_CONST_NONE
    0x67, // YIELD_VALUE
    0x59, // POP_TOP
    0x4a,0x19, // POP_EXCEPT_JUMP 25
    0x57, // DUP_TOP
    0x12,0x02, // LOAD_GLOBAL 'core'
    0x13,0x0a, // LOAD_ATTR 'CancelledError'
    0xdf, // BINARY_OP 8 <exception match>
    0x44,0x50, // POP_JUMP_IF_FALSE 16
    0xc6, // STORE_FAST 6
    0x49,0x06, // SETUP_FINALLY 6
    0x52, // LOAD_CONST_TRUE
    0xc5, // STORE_FAST 5
    0xb6, // LOAD_FAST 6
    0x27,0x07, // STORE_DEREF 7
    0x51, // LOAD_CONST_NONE
    0x51, // LOAD_CONST_NONE
    0xc6, // STORE_FAST 6
    0x28,0x06, // DELETE_FAST 6
    0x5d, // END_FINALLY
    0x4a,0x01, // POP_EXCEPT_JUMP 1
    0x5d, // END_FINALLY
    0x12,0x23, // LOAD_GLOBAL 'len'
    0xb3, // LOAD_FAST 3
    0x34,0x01, // CALL_FUNCTION 1
    0x80, // LOAD_CONST_SMALL_INT 0
    0x42,0xda,0x80, // JUMP 90
    0x57, // DUP_TOP
    0xc4, // STORE_FAST 4
    0xb3, // LOAD_FAST 3
    0xb4, // LOAD_FAST 4
    0x55, // LOAD_SUBSCR
    0x13,0x15, // LOAD_ATTR 'state'
    0xb2, // LOAD_FAST 2
    0xde, // BINARY_OP 7 <is>
    0x44,0x53, // POP_JUMP_IF_FALSE 19
    0x52, // LOAD_CONST_TRUE
    0xb3, // LOAD_FAST 3
    0xb4, // LOAD_FAST 4
    0x55, // LOAD_SUBSCR
    0x18,0x15, // STORE_ATTR 'state'
    0xb5, // LOAD_FAST 5
    0x44,0x48, // POP_JUMP_IF_FALSE 8
    0xb3, // LOAD_FAST 3
    0xb4, // LOAD_FAST 4
    0x55, // LOAD_SUBSCR
    0x14,0x09, // LOAD_METHOD 'cancel'
    0x36,0x00, // CALL_METHOD 0
    0x59, // POP_TOP
    0x42,0x7a, // JUMP 58
    0x12,0x24, // LOAD_GLOBAL 'isinstance'
    0xb3, // LOAD_FAST 3
    0xb4, // LOAD_FAST 4
    0x55, // LOAD_SUBSCR
    0x13,0x08, // LOAD_ATTR 'data'
    0x12,0x25, // LOAD_GLOBAL 'StopIteration'
    0x34,0x02, // CALL_FUNCTION 2
    0x44,0x4c, // POP_JUMP_IF_FALSE 12
    0xb3, // LOAD_FAST 3
    0xb4, // LOAD_FAST 4
    0x55, // LOAD_SUBSCR
    0x13,0x08, // LOAD_ATTR 'data'
    0x13,0x0f, // LOAD_ATTR 'value'
    0xb3, // LOAD_FAST 3
    0xb4, // LOAD_FAST 4
    0x56, // STORE_SUBSCR
    0x42,0x61, // JUMP 33
    0x25,0x00, // LOAD_DEREF 0
    0x44,0x4a, // POP_JUMP_IF_FALSE 10
    0xb3, // LOAD_FAST 3
    0xb4, // LOAD_FAST 4
    0x55, // LOAD_SUBSCR
    0x13,0x08, // LOAD_ATTR 'data'
    0xb3, // LOAD_FAST 3
    0xb4, // LOAD_FAST 4
    0x56, // STORE_SUBSCR
    0x42,0x53, // JUMP 19
    0x12,0x24, // LOAD_GLOBAL 'isinstance'
    0x25,0x07, // LOAD_DEREF 7
    0x12,0x27, // LOAD_GLOBAL 'int'
    0x34,0x02, // CALL_FUNCTION 2
    0x44,0x49, // POP_JUMP_IF_FALSE 9
    0xb3, // LOAD_FAST 3
    0xb4, // LOAD_FAST 4
    0x55, // LOAD_SUBSCR
    0x13,0x08, // LOAD_ATTR 'data'
    0x27,0x07, // STORE_DEREF 7
    0x42,0x40, // JUMP 0
    0x81, // LOAD_CONST_SMALL_INT 1
    0xe5, // BINARY_OP 14 __iadd__
    0x58, // DUP_TOP_TWO
    0x5a, // ROT_TWO
    0xd7, // BINARY_OP 0 __lt__
    0x43,0xa0,0x7f, // POP_JUMP_IF_TRUE -96
    0x59, // POP_TOP
    0x59, // POP_TOP
    0x25,0x07, // LOAD_DEREF 7
    0x44,0x43, // POP_JUMP_IF_FALSE 3
    0x25,0x07, // LOAD_DEREF 7
    0x65, // RAISE_OBJ
    0xb3, // LOAD_FAST 3
    0x63, // RETURN_VALUE
};
// child of asyncio_funcs_gather
// frozen bytecode for file asyncio/funcs.py, scope asyncio_funcs_gather_done
static const byte fun_data_asyncio_funcs_gather_done[64] = {
    0xb9,0x04,0x0c, // prelude
    0x17,0x29,0x29,0x29,0x28,0x2a, // names: done, *, *, *, t, er
     // code info
    0x25,0x02, // LOAD_DEREF 2
    0x13,0x08, // LOAD_ATTR 'data'
    0x12,0x05, // LOAD_GLOBAL '_Remove'
    0xde, // BINARY_OP 7 <is>
    0xd3, // UNARY_OP 3 <not>
    0x44,0x42, // POP_JUMP_IF_FALSE 2
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
    0x25,0x00, // LOAD_DEREF 0
    0x43,0x4e, // POP_JUMP_IF_TRUE 14
    0x12,0x24, // LOAD_GLOBAL 'isinstance'
    0xb4, // LOAD_FAST 4
    0x12,0x25, // LOAD_GLOBAL 'StopIteration'
    0x34,0x02, // CALL_FUNCTION 2
    0x43,0x45, // POP_JUMP_IF_TRUE 5
    0xb4, // LOAD_FAST 4
    0x27,0x01, // STORE_DEREF 1
    0x42,0x4c, // JUMP 12
    0x25,0x01, // LOAD_DEREF 1
    0x81, // LOAD_CONST_SMALL_INT 1
    0xe6, // BINARY_OP 15 __isub__
    0x27,0x01, // STORE_DEREF 1
    0x25,0x01, // LOAD_DEREF 1
    0x44,0x42, // POP_JUMP_IF_FALSE 2
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
    0x12,0x02, // LOAD_GLOBAL 'core'
    0x13,0x18, // LOAD_ATTR '_task_queue'
    0x14,0x19, // LOAD_METHOD 'push'
    0x25,0x02, // LOAD_DEREF 2
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_funcs_gather_done = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_funcs_gather_done,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 64,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 8,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 5,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 23,
        .line_info = fun_data_asyncio_funcs_gather_done + 9,
        .line_info_top = fun_data_asyncio_funcs_gather_done + 9,
        .opcodes = fun_data_asyncio_funcs_gather_done + 9,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_funcs_gather_done fun_data_asyncio_funcs_gather_done[0]
#endif

// child of asyncio_funcs_gather
// frozen bytecode for file asyncio/funcs.py, scope asyncio_funcs_gather__lt_listcomp_gt_
static const byte fun_data_asyncio_funcs_gather__lt_listcomp_gt_[23] = {
    0x49,0x04, // prelude
    0x1a,0x29, // names: <listcomp>, *
     // code info
    0x2b,0x00, // BUILD_LIST 0
    0xb0, // LOAD_FAST 0
    0x5f, // GET_ITER_STACK
    0x4b,0x0c, // FOR_ITER 12
    0xc1, // STORE_FAST 1
    0x12,0x02, // LOAD_GLOBAL 'core'
    0x14,0x0c, // LOAD_METHOD '_promote_to_task'
    0xb1, // LOAD_FAST 1
    0x36,0x01, // CALL_METHOD 1
    0x2f,0x14, // STORE_COMP 20
    0x42,0x32, // JUMP -14
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_funcs_gather__lt_listcomp_gt_ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_funcs_gather__lt_listcomp_gt_,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 23,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 10,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 26,
        .line_info = fun_data_asyncio_funcs_gather__lt_listcomp_gt_ + 4,
        .line_info_top = fun_data_asyncio_funcs_gather__lt_listcomp_gt_ + 4,
        .opcodes = fun_data_asyncio_funcs_gather__lt_listcomp_gt_ + 4,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_funcs_gather__lt_listcomp_gt_ fun_data_asyncio_funcs_gather__lt_listcomp_gt_[0]
#endif

static const mp_raw_code_t *const children_asyncio_funcs_gather[] = {
    (const mp_raw_code_t *)&proto_fun_asyncio_funcs_gather_done,
    (const mp_raw_code_t *)&proto_fun_asyncio_funcs_gather__lt_listcomp_gt_,
};

static const mp_raw_code_truncated_t proto_fun_asyncio_funcs_gather = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 1,
    .fun_data = fun_data_asyncio_funcs_gather,
    .children = (void *)&children_asyncio_funcs_gather,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 281,
    .n_children = 2,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 15,
        .n_exc_stack = 2,
        .scope_flags = 13,
        .n_pos_args = 0,
        .n_kwonly_args = 1,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 20,
        .line_info = fun_data_asyncio_funcs_gather + 9,
        .line_info_top = fun_data_asyncio_funcs_gather + 9,
        .opcodes = fun_data_asyncio_funcs_gather + 12,
    },
    #endif
    #endif
};

static const mp_raw_code_t *const children_asyncio_funcs__lt_module_gt_[] = {
    (const mp_raw_code_t *)&proto_fun_asyncio_funcs__run,
    (const mp_raw_code_t *)&proto_fun_asyncio_funcs_wait_for,
    (const mp_raw_code_t *)&proto_fun_asyncio_funcs_wait_for_ms,
    (const mp_raw_code_t *)&proto_fun_asyncio_funcs__Remove,
    (const mp_raw_code_t *)&proto_fun_asyncio_funcs_gather,
};

static const mp_raw_code_truncated_t proto_fun_asyncio_funcs__lt_module_gt_ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_funcs__lt_module_gt_,
    .children = (void *)&children_asyncio_funcs__lt_module_gt_,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 56,
    .n_children = 5,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 1,
        .line_info = fun_data_asyncio_funcs__lt_module_gt_ + 3,
        .line_info_top = fun_data_asyncio_funcs__lt_module_gt_ + 3,
        .opcodes = fun_data_asyncio_funcs__lt_module_gt_ + 3,
    },
    #endif
    #endif
};

static const qstr_short_t const_qstr_table_data_asyncio_funcs[43] = {
    MP_QSTR_asyncio_slash_funcs_dot_py,
    MP_QSTR__lt_module_gt_,
    MP_QSTR_core,
    MP_QSTR_,
    MP_QSTR_sleep,
    MP_QSTR__Remove,
    MP_QSTR_return_exceptions,
    MP_QSTR__run,
    MP_QSTR_data,
    MP_QSTR_cancel,
    MP_QSTR_CancelledError,
    MP_QSTR_wait_for,
    MP_QSTR__promote_to_task,
    MP_QSTR_create_task,
    MP_QSTR_cur_task,
    MP_QSTR_value,
    MP_QSTR_args,
    MP_QSTR_TimeoutError,
    MP_QSTR_wait_for_ms,
    MP_QSTR_sleep_ms,
    MP_QSTR_gather,
    MP_QSTR_state,
    MP_QSTR_remove,
    MP_QSTR_done,
    MP_QSTR__task_queue,
    MP_QSTR_push,
    MP_QSTR__lt_listcomp_gt_,
    MP_QSTR_waiter,
    MP_QSTR_aw,
    MP_QSTR_BaseException,
    MP_QSTR_timeout,
    MP_QSTR___name__,
    MP_QSTR___module__,
    MP_QSTR___qualname__,
    MP_QSTR_staticmethod,
    MP_QSTR_len,
    MP_QSTR_isinstance,
    MP_QSTR_StopIteration,
    MP_QSTR_RuntimeError,
    MP_QSTR_int,
    MP_QSTR_t,
    MP_QSTR__star_,
    MP_QSTR_er,
};

// constants

// constant table
static const mp_rom_obj_t const_obj_table_data_asyncio_funcs[1] = {
    MP_ROM_QSTR(MP_QSTR_can_squot_t_space_gather),
};

static const mp_frozen_module_t frozen_module_asyncio_funcs = {
    .constants = {
        .qstr_table = (qstr_short_t *)&const_qstr_table_data_asyncio_funcs,
        .obj_table = (mp_obj_t *)&const_obj_table_data_asyncio_funcs,
    },
    .proto_fun = &proto_fun_asyncio_funcs__lt_module_gt_,
};

////////////////////////////////////////////////////////////////////////////////
// frozen module asyncio_lock
// - original source file: /Users/gadgetoid/Development/micropython-web/picovector/ports/sokol/build/frozen_mpy/asyncio/lock.mpy
// - frozen file name: asyncio/lock.py
// - .mpy header: 4d:06:00:1f

// frozen bytecode for file asyncio/lock.py, scope asyncio_lock__lt_module_gt_
static const byte fun_data_asyncio_lock__lt_module_gt_[26] = {
    0x10,0x02, // prelude
    0x01, // names: <module>
     // code info
    0x81, // LOAD_CONST_SMALL_INT 1
    0x10,0x02, // LOAD_CONST_STRING 'core'
    0x2a,0x01, // BUILD_TUPLE 1
    0x1b,0x03, // IMPORT_NAME ''
    0x1c,0x02, // IMPORT_FROM 'core'
    0x16,0x02, // STORE_NAME 'core'
    0x59, // POP_TOP
    0x54, // LOAD_BUILD_CLASS
    0x32,0x00, // MAKE_FUNCTION 0
    0x10,0x04, // LOAD_CONST_STRING 'Lock'
    0x34,0x02, // CALL_FUNCTION 2
    0x16,0x04, // STORE_NAME 'Lock'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
// child of asyncio_lock__lt_module_gt_
// frozen bytecode for file asyncio/lock.py, scope asyncio_lock_Lock
static const byte fun_data_asyncio_lock_Lock[37] = {
    0x00,0x02, // prelude
    0x04, // names: Lock
     // code info
    0x11,0x15, // LOAD_NAME '__name__'
    0x16,0x16, // STORE_NAME '__module__'
    0x10,0x04, // LOAD_CONST_STRING 'Lock'
    0x16,0x17, // STORE_NAME '__qualname__'
    0x32,0x00, // MAKE_FUNCTION 0
    0x16,0x05, // STORE_NAME '__init__'
    0x32,0x01, // MAKE_FUNCTION 1
    0x16,0x09, // STORE_NAME 'locked'
    0x32,0x02, // MAKE_FUNCTION 2
    0x16,0x0a, // STORE_NAME 'release'
    0x32,0x03, // MAKE_FUNCTION 3
    0x16,0x0f, // STORE_NAME 'acquire'
    0x32,0x04, // MAKE_FUNCTION 4
    0x16,0x13, // STORE_NAME '__aenter__'
    0x32,0x05, // MAKE_FUNCTION 5
    0x16,0x14, // STORE_NAME '__aexit__'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
// child of asyncio_lock_Lock
// frozen bytecode for file asyncio/lock.py, scope asyncio_lock_Lock___init__
static const byte fun_data_asyncio_lock_Lock___init__[19] = {
    0x11,0x04, // prelude
    0x05,0x18, // names: __init__, self
     // code info
    0x80, // LOAD_CONST_SMALL_INT 0
    0xb0, // LOAD_FAST 0
    0x18,0x06, // STORE_ATTR 'state'
    0x12,0x02, // LOAD_GLOBAL 'core'
    0x14,0x07, // LOAD_METHOD 'TaskQueue'
    0x36,0x00, // CALL_METHOD 0
    0xb0, // LOAD_FAST 0
    0x18,0x08, // STORE_ATTR 'waiting'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_lock_Lock___init__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_lock_Lock___init__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 19,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 5,
        .line_info = fun_data_asyncio_lock_Lock___init__ + 4,
        .line_info_top = fun_data_asyncio_lock_Lock___init__ + 4,
        .opcodes = fun_data_asyncio_lock_Lock___init__ + 4,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_lock_Lock___init__ fun_data_asyncio_lock_Lock___init__[0]
#endif

// child of asyncio_lock_Lock
// frozen bytecode for file asyncio/lock.py, scope asyncio_lock_Lock_locked
static const byte fun_data_asyncio_lock_Lock_locked[10] = {
    0x11,0x04, // prelude
    0x09,0x18, // names: locked, self
     // code info
    0xb0, // LOAD_FAST 0
    0x13,0x06, // LOAD_ATTR 'state'
    0x81, // LOAD_CONST_SMALL_INT 1
    0xd9, // BINARY_OP 2 __eq__
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_lock_Lock_locked = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_lock_Lock_locked,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 10,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 9,
        .line_info = fun_data_asyncio_lock_Lock_locked + 4,
        .line_info_top = fun_data_asyncio_lock_Lock_locked + 4,
        .opcodes = fun_data_asyncio_lock_Lock_locked + 4,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_lock_Lock_locked fun_data_asyncio_lock_Lock_locked[0]
#endif

// child of asyncio_lock_Lock
// frozen bytecode for file asyncio/lock.py, scope asyncio_lock_Lock_release
static const byte fun_data_asyncio_lock_Lock_release[57] = {
    0x19,0x04, // prelude
    0x0a,0x18, // names: release, self
     // code info
    0xb0, // LOAD_FAST 0
    0x13,0x06, // LOAD_ATTR 'state'
    0x81, // LOAD_CONST_SMALL_INT 1
    0xdc, // BINARY_OP 5 __ne__
    0x44,0x47, // POP_JUMP_IF_FALSE 7
    0x12,0x19, // LOAD_GLOBAL 'RuntimeError'
    0x23,0x00, // LOAD_CONST_OBJ 0
    0x34,0x01, // CALL_FUNCTION 1
    0x65, // RAISE_OBJ
    0xb0, // LOAD_FAST 0
    0x13,0x08, // LOAD_ATTR 'waiting'
    0x14,0x0b, // LOAD_METHOD 'peek'
    0x36,0x00, // CALL_METHOD 0
    0x44,0x58, // POP_JUMP_IF_FALSE 24
    0xb0, // LOAD_FAST 0
    0x13,0x08, // LOAD_ATTR 'waiting'
    0x14,0x0c, // LOAD_METHOD 'pop'
    0x36,0x00, // CALL_METHOD 0
    0xb0, // LOAD_FAST 0
    0x18,0x06, // STORE_ATTR 'state'
    0x12,0x02, // LOAD_GLOBAL 'core'
    0x13,0x0d, // LOAD_ATTR '_task_queue'
    0x14,0x0e, // LOAD_METHOD 'push'
    0xb0, // LOAD_FAST 0
    0x13,0x06, // LOAD_ATTR 'state'
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x42,0x44, // JUMP 4
    0x80, // LOAD_CONST_SMALL_INT 0
    0xb0, // LOAD_FAST 0
    0x18,0x06, // STORE_ATTR 'state'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_lock_Lock_release = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_lock_Lock_release,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 57,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 10,
        .line_info = fun_data_asyncio_lock_Lock_release + 4,
        .line_info_top = fun_data_asyncio_lock_Lock_release + 4,
        .opcodes = fun_data_asyncio_lock_Lock_release + 4,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_lock_Lock_release fun_data_asyncio_lock_Lock_release[0]
#endif

// child of asyncio_lock_Lock
// frozen bytecode for file asyncio/lock.py, scope asyncio_lock_Lock_acquire
static const byte fun_data_asyncio_lock_Lock_acquire[88] = {
    0xb9,0x42,0x04, // prelude
    0x0f,0x18, // names: acquire, self
     // code info
    0xb0, // LOAD_FAST 0
    0x13,0x06, // LOAD_ATTR 'state'
    0x80, // LOAD_CONST_SMALL_INT 0
    0xdc, // BINARY_OP 5 __ne__
    0x44,0xc5,0x80, // POP_JUMP_IF_FALSE 69
    0xb0, // LOAD_FAST 0
    0x13,0x08, // LOAD_ATTR 'waiting'
    0x14,0x0e, // LOAD_METHOD 'push'
    0x12,0x02, // LOAD_GLOBAL 'core'
    0x13,0x10, // LOAD_ATTR 'cur_task'
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0xb0, // LOAD_FAST 0
    0x13,0x08, // LOAD_ATTR 'waiting'
    0x12,0x02, // LOAD_GLOBAL 'core'
    0x13,0x10, // LOAD_ATTR 'cur_task'
    0x18,0x11, // STORE_ATTR 'data'
    0x48,0x05, // SETUP_EXCEPT 5
    0x51, // LOAD_CONST_NONE
    0x67, // YIELD_VALUE
    0x59, // POP_TOP
    0x4a,0x29, // POP_EXCEPT_JUMP 41
    0x57, // DUP_TOP
    0x12,0x02, // LOAD_GLOBAL 'core'
    0x13,0x12, // LOAD_ATTR 'CancelledError'
    0xdf, // BINARY_OP 8 <exception match>
    0x44,0x60, // POP_JUMP_IF_FALSE 32
    0xc1, // STORE_FAST 1
    0x49,0x16, // SETUP_FINALLY 22
    0xb0, // LOAD_FAST 0
    0x13,0x06, // LOAD_ATTR 'state'
    0x12,0x02, // LOAD_GLOBAL 'core'
    0x13,0x10, // LOAD_ATTR 'cur_task'
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x4a, // POP_JUMP_IF_FALSE 10
    0x81, // LOAD_CONST_SMALL_INT 1
    0xb0, // LOAD_FAST 0
    0x18,0x06, // STORE_ATTR 'state'
    0xb0, // LOAD_FAST 0
    0x14,0x0a, // LOAD_METHOD 'release'
    0x36,0x00, // CALL_METHOD 0
    0x59, // POP_TOP
    0xb1, // LOAD_FAST 1
    0x65, // RAISE_OBJ
    0x51, // LOAD_CONST_NONE
    0xc1, // STORE_FAST 1
    0x28,0x01, // DELETE_FAST 1
    0x5d, // END_FINALLY
    0x4a,0x01, // POP_EXCEPT_JUMP 1
    0x5d, // END_FINALLY
    0x81, // LOAD_CONST_SMALL_INT 1
    0xb0, // LOAD_FAST 0
    0x18,0x06, // STORE_ATTR 'state'
    0x52, // LOAD_CONST_TRUE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_lock_Lock_acquire = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 1,
    .fun_data = fun_data_asyncio_lock_Lock_acquire,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 88,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 8,
        .n_exc_stack = 2,
        .scope_flags = 1,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 15,
        .line_info = fun_data_asyncio_lock_Lock_acquire + 5,
        .line_info_top = fun_data_asyncio_lock_Lock_acquire + 5,
        .opcodes = fun_data_asyncio_lock_Lock_acquire + 5,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_lock_Lock_acquire fun_data_asyncio_lock_Lock_acquire[0]
#endif

// child of asyncio_lock_Lock
// frozen bytecode for file asyncio/lock.py, scope asyncio_lock_Lock___aenter__
static const byte fun_data_asyncio_lock_Lock___aenter__[14] = {
    0x91,0x40,0x04, // prelude
    0x13,0x18, // names: __aenter__, self
     // code info
    0xb0, // LOAD_FAST 0
    0x14,0x0f, // LOAD_METHOD 'acquire'
    0x36,0x00, // CALL_METHOD 0
    0x5e, // GET_ITER
    0x51, // LOAD_CONST_NONE
    0x68, // YIELD_FROM
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_lock_Lock___aenter__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 1,
    .fun_data = fun_data_asyncio_lock_Lock___aenter__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 14,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 1,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 19,
        .line_info = fun_data_asyncio_lock_Lock___aenter__ + 5,
        .line_info_top = fun_data_asyncio_lock_Lock___aenter__ + 5,
        .opcodes = fun_data_asyncio_lock_Lock___aenter__ + 5,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_lock_Lock___aenter__ fun_data_asyncio_lock_Lock___aenter__[0]
#endif

// child of asyncio_lock_Lock
// frozen bytecode for file asyncio/lock.py, scope asyncio_lock_Lock___aexit__
static const byte fun_data_asyncio_lock_Lock___aexit__[14] = {
    0xa8,0x44,0x0a, // prelude
    0x14,0x18,0x1a,0x1b,0x1c, // names: __aexit__, self, exc_type, exc, tb
     // code info
    0xb0, // LOAD_FAST 0
    0x14,0x0a, // LOAD_METHOD 'release'
    0x36,0x00, // CALL_METHOD 0
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_lock_Lock___aexit__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 1,
    .fun_data = fun_data_asyncio_lock_Lock___aexit__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 14,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 6,
        .n_exc_stack = 0,
        .scope_flags = 1,
        .n_pos_args = 4,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 20,
        .line_info = fun_data_asyncio_lock_Lock___aexit__ + 8,
        .line_info_top = fun_data_asyncio_lock_Lock___aexit__ + 8,
        .opcodes = fun_data_asyncio_lock_Lock___aexit__ + 8,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_lock_Lock___aexit__ fun_data_asyncio_lock_Lock___aexit__[0]
#endif

static const mp_raw_code_t *const children_asyncio_lock_Lock[] = {
    (const mp_raw_code_t *)&proto_fun_asyncio_lock_Lock___init__,
    (const mp_raw_code_t *)&proto_fun_asyncio_lock_Lock_locked,
    (const mp_raw_code_t *)&proto_fun_asyncio_lock_Lock_release,
    (const mp_raw_code_t *)&proto_fun_asyncio_lock_Lock_acquire,
    (const mp_raw_code_t *)&proto_fun_asyncio_lock_Lock___aenter__,
    (const mp_raw_code_t *)&proto_fun_asyncio_lock_Lock___aexit__,
};

static const mp_raw_code_truncated_t proto_fun_asyncio_lock_Lock = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_lock_Lock,
    .children = (void *)&children_asyncio_lock_Lock,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 37,
    .n_children = 6,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 1,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 4,
        .line_info = fun_data_asyncio_lock_Lock + 3,
        .line_info_top = fun_data_asyncio_lock_Lock + 3,
        .opcodes = fun_data_asyncio_lock_Lock + 3,
    },
    #endif
    #endif
};

static const mp_raw_code_t *const children_asyncio_lock__lt_module_gt_[] = {
    (const mp_raw_code_t *)&proto_fun_asyncio_lock_Lock,
};

static const mp_raw_code_truncated_t proto_fun_asyncio_lock__lt_module_gt_ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_lock__lt_module_gt_,
    .children = (void *)&children_asyncio_lock__lt_module_gt_,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 26,
    .n_children = 1,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 1,
        .line_info = fun_data_asyncio_lock__lt_module_gt_ + 3,
        .line_info_top = fun_data_asyncio_lock__lt_module_gt_ + 3,
        .opcodes = fun_data_asyncio_lock__lt_module_gt_ + 3,
    },
    #endif
    #endif
};

static const qstr_short_t const_qstr_table_data_asyncio_lock[29] = {
    MP_QSTR_asyncio_slash_lock_dot_py,
    MP_QSTR__lt_module_gt_,
    MP_QSTR_core,
    MP_QSTR_,
    MP_QSTR_Lock,
    MP_QSTR___init__,
    MP_QSTR_state,
    MP_QSTR_TaskQueue,
    MP_QSTR_waiting,
    MP_QSTR_locked,
    MP_QSTR_release,
    MP_QSTR_peek,
    MP_QSTR_pop,
    MP_QSTR__task_queue,
    MP_QSTR_push,
    MP_QSTR_acquire,
    MP_QSTR_cur_task,
    MP_QSTR_data,
    MP_QSTR_CancelledError,
    MP_QSTR___aenter__,
    MP_QSTR___aexit__,
    MP_QSTR___name__,
    MP_QSTR___module__,
    MP_QSTR___qualname__,
    MP_QSTR_self,
    MP_QSTR_RuntimeError,
    MP_QSTR_exc_type,
    MP_QSTR_exc,
    MP_QSTR_tb,
};

// constants

// constant table
static const mp_rom_obj_t const_obj_table_data_asyncio_lock[1] = {
    MP_ROM_QSTR(MP_QSTR_Lock_space_not_space_acquired),
};

static const mp_frozen_module_t frozen_module_asyncio_lock = {
    .constants = {
        .qstr_table = (qstr_short_t *)&const_qstr_table_data_asyncio_lock,
        .obj_table = (mp_obj_t *)&const_obj_table_data_asyncio_lock,
    },
    .proto_fun = &proto_fun_asyncio_lock__lt_module_gt_,
};

////////////////////////////////////////////////////////////////////////////////
// frozen module asyncio_stream
// - original source file: /Users/gadgetoid/Development/micropython-web/picovector/ports/sokol/build/frozen_mpy/asyncio/stream.mpy
// - frozen file name: asyncio/stream.py
// - .mpy header: 4d:06:00:1f

// frozen bytecode for file asyncio/stream.py, scope asyncio_stream__lt_module_gt_
static const byte fun_data_asyncio_stream__lt_module_gt_[90] = {
    0x10,0x02, // prelude
    0x01, // names: <module>
     // code info
    0x81, // LOAD_CONST_SMALL_INT 1
    0x10,0x02, // LOAD_CONST_STRING 'core'
    0x2a,0x01, // BUILD_TUPLE 1
    0x1b,0x03, // IMPORT_NAME ''
    0x1c,0x02, // IMPORT_FROM 'core'
    0x16,0x02, // STORE_NAME 'core'
    0x59, // POP_TOP
    0x54, // LOAD_BUILD_CLASS
    0x32,0x00, // MAKE_FUNCTION 0
    0x10,0x04, // LOAD_CONST_STRING 'Stream'
    0x34,0x02, // CALL_FUNCTION 2
    0x16,0x04, // STORE_NAME 'Stream'
    0x11,0x04, // LOAD_NAME 'Stream'
    0x16,0x3c, // STORE_NAME 'StreamReader'
    0x11,0x04, // LOAD_NAME 'Stream'
    0x16,0x3d, // STORE_NAME 'StreamWriter'
    0x51, // LOAD_CONST_NONE
    0x51, // LOAD_CONST_NONE
    0x2a,0x02, // BUILD_TUPLE 2
    0x53, // LOAD_NULL
    0x33,0x01, // MAKE_FUNCTION_DEFARGS 1
    0x16,0x0a, // STORE_NAME 'open_connection'
    0x54, // LOAD_BUILD_CLASS
    0x32,0x02, // MAKE_FUNCTION 2
    0x10,0x05, // LOAD_CONST_STRING 'Server'
    0x34,0x02, // CALL_FUNCTION 2
    0x16,0x05, // STORE_NAME 'Server'
    0x85, // LOAD_CONST_SMALL_INT 5
    0x51, // LOAD_CONST_NONE
    0x2a,0x02, // BUILD_TUPLE 2
    0x53, // LOAD_NULL
    0x33,0x03, // MAKE_FUNCTION_DEFARGS 3
    0x16,0x1a, // STORE_NAME 'start_server'
    0x80, // LOAD_CONST_SMALL_INT 0
    0x7f, // LOAD_CONST_SMALL_INT -1
    0x2a,0x02, // BUILD_TUPLE 2
    0x53, // LOAD_NULL
    0x33,0x04, // MAKE_FUNCTION_DEFARGS 4
    0x16,0x26, // STORE_NAME 'stream_awrite'
    0x11,0x04, // LOAD_NAME 'Stream'
    0x13,0x06, // LOAD_ATTR 'wait_closed'
    0x11,0x04, // LOAD_NAME 'Stream'
    0x18,0x07, // STORE_ATTR 'aclose'
    0x11,0x26, // LOAD_NAME 'stream_awrite'
    0x11,0x04, // LOAD_NAME 'Stream'
    0x18,0x08, // STORE_ATTR 'awrite'
    0x11,0x26, // LOAD_NAME 'stream_awrite'
    0x11,0x04, // LOAD_NAME 'Stream'
    0x18,0x09, // STORE_ATTR 'awritestr'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
// child of asyncio_stream__lt_module_gt_
// frozen bytecode for file asyncio/stream.py, scope asyncio_stream_Stream
static const byte fun_data_asyncio_stream_Stream[62] = {
    0x08,0x02, // prelude
    0x04, // names: Stream
     // code info
    0x11,0x3e, // LOAD_NAME '__name__'
    0x16,0x3f, // STORE_NAME '__module__'
    0x10,0x04, // LOAD_CONST_STRING 'Stream'
    0x16,0x40, // STORE_NAME '__qualname__'
    0x2c,0x00, // BUILD_MAP 0
    0x2a,0x01, // BUILD_TUPLE 1
    0x53, // LOAD_NULL
    0x33,0x00, // MAKE_FUNCTION_DEFARGS 0
    0x16,0x29, // STORE_NAME '__init__'
    0x32,0x01, // MAKE_FUNCTION 1
    0x16,0x2d, // STORE_NAME 'get_extra_info'
    0x32,0x02, // MAKE_FUNCTION 2
    0x16,0x2e, // STORE_NAME 'close'
    0x32,0x03, // MAKE_FUNCTION 3
    0x16,0x06, // STORE_NAME 'wait_closed'
    0x7f, // LOAD_CONST_SMALL_INT -1
    0x2a,0x01, // BUILD_TUPLE 1
    0x53, // LOAD_NULL
    0x33,0x04, // MAKE_FUNCTION_DEFARGS 4
    0x16,0x2f, // STORE_NAME 'read'
    0x32,0x05, // MAKE_FUNCTION 5
    0x16,0x31, // STORE_NAME 'readinto'
    0x32,0x06, // MAKE_FUNCTION 6
    0x16,0x32, // STORE_NAME 'readexactly'
    0x32,0x07, // MAKE_FUNCTION 7
    0x16,0x33, // STORE_NAME 'readline'
    0x32,0x08, // MAKE_FUNCTION 8
    0x16,0x27, // STORE_NAME 'write'
    0x32,0x09, // MAKE_FUNCTION 9
    0x16,0x28, // STORE_NAME 'drain'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
// child of asyncio_stream_Stream
// frozen bytecode for file asyncio/stream.py, scope asyncio_stream_Stream___init__
static const byte fun_data_asyncio_stream_Stream___init__[22] = {
    0xa3,0x01,0x08, // prelude
    0x29,0x46,0x2a,0x2b, // names: __init__, self, s, e
     // code info
    0xb1, // LOAD_FAST 1
    0xb0, // LOAD_FAST 0
    0x18,0x2a, // STORE_ATTR 's'
    0xb2, // LOAD_FAST 2
    0xb0, // LOAD_FAST 0
    0x18,0x2b, // STORE_ATTR 'e'
    0x23,0x00, // LOAD_CONST_OBJ 0
    0xb0, // LOAD_FAST 0
    0x18,0x2c, // STORE_ATTR 'out_buf'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_stream_Stream___init__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_stream_Stream___init__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 22,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 3,
        .n_kwonly_args = 0,
        .n_def_pos_args = 1,
        .qstr_block_name_idx = 41,
        .line_info = fun_data_asyncio_stream_Stream___init__ + 7,
        .line_info_top = fun_data_asyncio_stream_Stream___init__ + 7,
        .opcodes = fun_data_asyncio_stream_Stream___init__ + 7,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_stream_Stream___init__ fun_data_asyncio_stream_Stream___init__[0]
#endif

// child of asyncio_stream_Stream
// frozen bytecode for file asyncio/stream.py, scope asyncio_stream_Stream_get_extra_info
static const byte fun_data_asyncio_stream_Stream_get_extra_info[11] = {
    0x1a,0x06, // prelude
    0x2d,0x46,0x4c, // names: get_extra_info, self, v
     // code info
    0xb0, // LOAD_FAST 0
    0x13,0x2b, // LOAD_ATTR 'e'
    0xb1, // LOAD_FAST 1
    0x55, // LOAD_SUBSCR
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_stream_Stream_get_extra_info = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_stream_Stream_get_extra_info,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 11,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 4,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 45,
        .line_info = fun_data_asyncio_stream_Stream_get_extra_info + 5,
        .line_info_top = fun_data_asyncio_stream_Stream_get_extra_info + 5,
        .opcodes = fun_data_asyncio_stream_Stream_get_extra_info + 5,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_stream_Stream_get_extra_info fun_data_asyncio_stream_Stream_get_extra_info[0]
#endif

// child of asyncio_stream_Stream
// frozen bytecode for file asyncio/stream.py, scope asyncio_stream_Stream_close
static const byte fun_data_asyncio_stream_Stream_close[6] = {
    0x09,0x04, // prelude
    0x2e,0x46, // names: close, self
     // code info
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_stream_Stream_close = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_stream_Stream_close,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 6,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 2,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 46,
        .line_info = fun_data_asyncio_stream_Stream_close + 4,
        .line_info_top = fun_data_asyncio_stream_Stream_close + 4,
        .opcodes = fun_data_asyncio_stream_Stream_close + 4,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_stream_Stream_close fun_data_asyncio_stream_Stream_close[0]
#endif

// child of asyncio_stream_Stream
// frozen bytecode for file asyncio/stream.py, scope asyncio_stream_Stream_wait_closed
static const byte fun_data_asyncio_stream_Stream_wait_closed[15] = {
    0x91,0x40,0x04, // prelude
    0x06,0x46, // names: wait_closed, self
     // code info
    0xb0, // LOAD_FAST 0
    0x13,0x2a, // LOAD_ATTR 's'
    0x14,0x2e, // LOAD_METHOD 'close'
    0x36,0x00, // CALL_METHOD 0
    0x59, // POP_TOP
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_stream_Stream_wait_closed = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 1,
    .fun_data = fun_data_asyncio_stream_Stream_wait_closed,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 15,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 1,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 6,
        .line_info = fun_data_asyncio_stream_Stream_wait_closed + 5,
        .line_info_top = fun_data_asyncio_stream_Stream_wait_closed + 5,
        .opcodes = fun_data_asyncio_stream_Stream_wait_closed + 5,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_stream_Stream_wait_closed fun_data_asyncio_stream_Stream_wait_closed[0]
#endif

// child of asyncio_stream_Stream
// frozen bytecode for file asyncio/stream.py, scope asyncio_stream_Stream_read
static const byte fun_data_asyncio_stream_Stream_read[61] = {
    0xb2,0x41,0x06, // prelude
    0x2f,0x46,0x4d, // names: read, self, n
     // code info
    0x23,0x00, // LOAD_CONST_OBJ 0
    0xc2, // STORE_FAST 2
    0x12,0x02, // LOAD_GLOBAL 'core'
    0x13,0x18, // LOAD_ATTR '_io_queue'
    0x14,0x30, // LOAD_METHOD 'queue_read'
    0xb0, // LOAD_FAST 0
    0x13,0x2a, // LOAD_ATTR 's'
    0x36,0x01, // CALL_METHOD 1
    0x67, // YIELD_VALUE
    0x59, // POP_TOP
    0xb0, // LOAD_FAST 0
    0x13,0x2a, // LOAD_ATTR 's'
    0x14,0x2f, // LOAD_METHOD 'read'
    0xb1, // LOAD_FAST 1
    0x36,0x01, // CALL_METHOD 1
    0xc3, // STORE_FAST 3
    0xb3, // LOAD_FAST 3
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0xd3, // UNARY_OP 3 <not>
    0x44,0x54, // POP_JUMP_IF_FALSE 20
    0xb1, // LOAD_FAST 1
    0x80, // LOAD_CONST_SMALL_INT 0
    0xdb, // BINARY_OP 4 __ge__
    0x44,0x42, // POP_JUMP_IF_FALSE 2
    0xb3, // LOAD_FAST 3
    0x63, // RETURN_VALUE
    0x12,0x4b, // LOAD_GLOBAL 'len'
    0xb3, // LOAD_FAST 3
    0x34,0x01, // CALL_FUNCTION 1
    0x43,0x42, // POP_JUMP_IF_TRUE 2
    0xb2, // LOAD_FAST 2
    0x63, // RETURN_VALUE
    0xb2, // LOAD_FAST 2
    0xb3, // LOAD_FAST 3
    0xe5, // BINARY_OP 14 __iadd__
    0xc2, // STORE_FAST 2
    0x42,0x0e, // JUMP -50
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_stream_Stream_read = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 1,
    .fun_data = fun_data_asyncio_stream_Stream_read,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 61,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 7,
        .n_exc_stack = 0,
        .scope_flags = 1,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 1,
        .qstr_block_name_idx = 47,
        .line_info = fun_data_asyncio_stream_Stream_read + 6,
        .line_info_top = fun_data_asyncio_stream_Stream_read + 6,
        .opcodes = fun_data_asyncio_stream_Stream_read + 6,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_stream_Stream_read fun_data_asyncio_stream_Stream_read[0]
#endif

// child of asyncio_stream_Stream
// frozen bytecode for file asyncio/stream.py, scope asyncio_stream_Stream_readinto
static const byte fun_data_asyncio_stream_Stream_readinto[28] = {
    0xa2,0x40,0x06, // prelude
    0x31,0x46,0x47, // names: readinto, self, buf
     // code info
    0x12,0x02, // LOAD_GLOBAL 'core'
    0x13,0x18, // LOAD_ATTR '_io_queue'
    0x14,0x30, // LOAD_METHOD 'queue_read'
    0xb0, // LOAD_FAST 0
    0x13,0x2a, // LOAD_ATTR 's'
    0x36,0x01, // CALL_METHOD 1
    0x67, // YIELD_VALUE
    0x59, // POP_TOP
    0xb0, // LOAD_FAST 0
    0x13,0x2a, // LOAD_ATTR 's'
    0x14,0x31, // LOAD_METHOD 'readinto'
    0xb1, // LOAD_FAST 1
    0x36,0x01, // CALL_METHOD 1
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_stream_Stream_readinto = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 1,
    .fun_data = fun_data_asyncio_stream_Stream_readinto,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 28,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 0,
        .scope_flags = 1,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 49,
        .line_info = fun_data_asyncio_stream_Stream_readinto + 6,
        .line_info_top = fun_data_asyncio_stream_Stream_readinto + 6,
        .opcodes = fun_data_asyncio_stream_Stream_readinto + 6,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_stream_Stream_readinto fun_data_asyncio_stream_Stream_readinto[0]
#endif

// child of asyncio_stream_Stream
// frozen bytecode for file asyncio/stream.py, scope asyncio_stream_Stream_readexactly
static const byte fun_data_asyncio_stream_Stream_readexactly[66] = {
    0xb2,0x40,0x06, // prelude
    0x32,0x46,0x4d, // names: readexactly, self, n
     // code info
    0x23,0x00, // LOAD_CONST_OBJ 0
    0xc2, // STORE_FAST 2
    0x42,0x72, // JUMP 50
    0x12,0x02, // LOAD_GLOBAL 'core'
    0x13,0x18, // LOAD_ATTR '_io_queue'
    0x14,0x30, // LOAD_METHOD 'queue_read'
    0xb0, // LOAD_FAST 0
    0x13,0x2a, // LOAD_ATTR 's'
    0x36,0x01, // CALL_METHOD 1
    0x67, // YIELD_VALUE
    0x59, // POP_TOP
    0xb0, // LOAD_FAST 0
    0x13,0x2a, // LOAD_ATTR 's'
    0x14,0x2f, // LOAD_METHOD 'read'
    0xb1, // LOAD_FAST 1
    0x36,0x01, // CALL_METHOD 1
    0xc3, // STORE_FAST 3
    0xb3, // LOAD_FAST 3
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0xd3, // UNARY_OP 3 <not>
    0x44,0x56, // POP_JUMP_IF_FALSE 22
    0x12,0x4b, // LOAD_GLOBAL 'len'
    0xb3, // LOAD_FAST 3
    0x34,0x01, // CALL_FUNCTION 1
    0x43,0x43, // POP_JUMP_IF_TRUE 3
    0x12,0x4e, // LOAD_GLOBAL 'EOFError'
    0x65, // RAISE_OBJ
    0xb2, // LOAD_FAST 2
    0xb3, // LOAD_FAST 3
    0xe5, // BINARY_OP 14 __iadd__
    0xc2, // STORE_FAST 2
    0xb1, // LOAD_FAST 1
    0x12,0x4b, // LOAD_GLOBAL 'len'
    0xb3, // LOAD_FAST 3
    0x34,0x01, // CALL_FUNCTION 1
    0xe6, // BINARY_OP 15 __isub__
    0xc1, // STORE_FAST 1
    0xb1, // LOAD_FAST 1
    0x43,0x0b, // POP_JUMP_IF_TRUE -53
    0xb2, // LOAD_FAST 2
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_stream_Stream_readexactly = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 1,
    .fun_data = fun_data_asyncio_stream_Stream_readexactly,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 66,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 7,
        .n_exc_stack = 0,
        .scope_flags = 1,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 50,
        .line_info = fun_data_asyncio_stream_Stream_readexactly + 6,
        .line_info_top = fun_data_asyncio_stream_Stream_readexactly + 6,
        .opcodes = fun_data_asyncio_stream_Stream_readexactly + 6,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_stream_Stream_readexactly fun_data_asyncio_stream_Stream_readexactly[0]
#endif

// child of asyncio_stream_Stream
// frozen bytecode for file asyncio/stream.py, scope asyncio_stream_Stream_readline
static const byte fun_data_asyncio_stream_Stream_readline[56] = {
    0xa9,0x40,0x04, // prelude
    0x33,0x46, // names: readline, self
     // code info
    0x23,0x00, // LOAD_CONST_OBJ 0
    0xc1, // STORE_FAST 1
    0x12,0x02, // LOAD_GLOBAL 'core'
    0x13,0x18, // LOAD_ATTR '_io_queue'
    0x14,0x30, // LOAD_METHOD 'queue_read'
    0xb0, // LOAD_FAST 0
    0x13,0x2a, // LOAD_ATTR 's'
    0x36,0x01, // CALL_METHOD 1
    0x67, // YIELD_VALUE
    0x59, // POP_TOP
    0xb0, // LOAD_FAST 0
    0x13,0x2a, // LOAD_ATTR 's'
    0x14,0x33, // LOAD_METHOD 'readline'
    0x36,0x00, // CALL_METHOD 0
    0xc2, // STORE_FAST 2
    0xb2, // LOAD_FAST 2
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0x44,0x42, // POP_JUMP_IF_FALSE 2
    0x42,0x50, // JUMP 16
    0xb1, // LOAD_FAST 1
    0xb2, // LOAD_FAST 2
    0xe5, // BINARY_OP 14 __iadd__
    0xc1, // STORE_FAST 1
    0xb2, // LOAD_FAST 2
    0x44,0x47, // POP_JUMP_IF_FALSE 7
    0xb1, // LOAD_FAST 1
    0x7f, // LOAD_CONST_SMALL_INT -1
    0x55, // LOAD_SUBSCR
    0x8a, // LOAD_CONST_SMALL_INT 10
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x42, // POP_JUMP_IF_FALSE 2
    0xb1, // LOAD_FAST 1
    0x63, // RETURN_VALUE
    0x42,0x12, // JUMP -46
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_stream_Stream_readline = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 1,
    .fun_data = fun_data_asyncio_stream_Stream_readline,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 56,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 6,
        .n_exc_stack = 0,
        .scope_flags = 1,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 51,
        .line_info = fun_data_asyncio_stream_Stream_readline + 5,
        .line_info_top = fun_data_asyncio_stream_Stream_readline + 5,
        .opcodes = fun_data_asyncio_stream_Stream_readline + 5,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_stream_Stream_readline fun_data_asyncio_stream_Stream_readline[0]
#endif

// child of asyncio_stream_Stream
// frozen bytecode for file asyncio/stream.py, scope asyncio_stream_Stream_write
static const byte fun_data_asyncio_stream_Stream_write[54] = {
    0x2a,0x06, // prelude
    0x27,0x46,0x47, // names: write, self, buf
     // code info
    0xb0, // LOAD_FAST 0
    0x13,0x2c, // LOAD_ATTR 'out_buf'
    0x43,0x61, // POP_JUMP_IF_TRUE 33
    0xb0, // LOAD_FAST 0
    0x13,0x2a, // LOAD_ATTR 's'
    0x14,0x27, // LOAD_METHOD 'write'
    0xb1, // LOAD_FAST 1
    0x36,0x01, // CALL_METHOD 1
    0xc2, // STORE_FAST 2
    0xb2, // LOAD_FAST 2
    0x12,0x4b, // LOAD_GLOBAL 'len'
    0xb1, // LOAD_FAST 1
    0x34,0x01, // CALL_FUNCTION 1
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x42, // POP_JUMP_IF_FALSE 2
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
    0xb2, // LOAD_FAST 2
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0xd3, // UNARY_OP 3 <not>
    0x44,0x47, // POP_JUMP_IF_FALSE 7
    0xb1, // LOAD_FAST 1
    0xb2, // LOAD_FAST 2
    0x51, // LOAD_CONST_NONE
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0xc1, // STORE_FAST 1
    0xb0, // LOAD_FAST 0
    0x57, // DUP_TOP
    0x13,0x2c, // LOAD_ATTR 'out_buf'
    0xb1, // LOAD_FAST 1
    0xe5, // BINARY_OP 14 __iadd__
    0x5a, // ROT_TWO
    0x18,0x2c, // STORE_ATTR 'out_buf'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_stream_Stream_write = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_stream_Stream_write,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 54,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 6,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 2,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 39,
        .line_info = fun_data_asyncio_stream_Stream_write + 5,
        .line_info_top = fun_data_asyncio_stream_Stream_write + 5,
        .opcodes = fun_data_asyncio_stream_Stream_write + 5,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_stream_Stream_write fun_data_asyncio_stream_Stream_write[0]
#endif

// child of asyncio_stream_Stream
// frozen bytecode for file asyncio/stream.py, scope asyncio_stream_Stream_drain
static const byte fun_data_asyncio_stream_Stream_drain[86] = {
    0xc1,0x40,0x04, // prelude
    0x28,0x46, // names: drain, self
     // code info
    0xb0, // LOAD_FAST 0
    0x13,0x2c, // LOAD_ATTR 'out_buf'
    0x43,0x4b, // POP_JUMP_IF_TRUE 11
    0x12,0x02, // LOAD_GLOBAL 'core'
    0x14,0x23, // LOAD_METHOD 'sleep_ms'
    0x80, // LOAD_CONST_SMALL_INT 0
    0x36,0x01, // CALL_METHOD 1
    0x5e, // GET_ITER
    0x51, // LOAD_CONST_NONE
    0x68, // YIELD_FROM
    0x63, // RETURN_VALUE
    0x12,0x4a, // LOAD_GLOBAL 'memoryview'
    0xb0, // LOAD_FAST 0
    0x13,0x2c, // LOAD_ATTR 'out_buf'
    0x34,0x01, // CALL_FUNCTION 1
    0xc1, // STORE_FAST 1
    0x80, // LOAD_CONST_SMALL_INT 0
    0xc2, // STORE_FAST 2
    0x42,0x65, // JUMP 37
    0x12,0x02, // LOAD_GLOBAL 'core'
    0x13,0x18, // LOAD_ATTR '_io_queue'
    0x14,0x19, // LOAD_METHOD 'queue_write'
    0xb0, // LOAD_FAST 0
    0x13,0x2a, // LOAD_ATTR 's'
    0x36,0x01, // CALL_METHOD 1
    0x67, // YIELD_VALUE
    0x59, // POP_TOP
    0xb0, // LOAD_FAST 0
    0x13,0x2a, // LOAD_ATTR 's'
    0x14,0x27, // LOAD_METHOD 'write'
    0xb1, // LOAD_FAST 1
    0xb2, // LOAD_FAST 2
    0x51, // LOAD_CONST_NONE
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0x36,0x01, // CALL_METHOD 1
    0xc3, // STORE_FAST 3
    0xb3, // LOAD_FAST 3
    0x51, // LOAD_CONST_NONE
    0xde, // BINARY_OP 7 <is>
    0xd3, // UNARY_OP 3 <not>
    0x44,0x44, // POP_JUMP_IF_FALSE 4
    0xb2, // LOAD_FAST 2
    0xb3, // LOAD_FAST 3
    0xe5, // BINARY_OP 14 __iadd__
    0xc2, // STORE_FAST 2
    0xb2, // LOAD_FAST 2
    0x12,0x4b, // LOAD_GLOBAL 'len'
    0xb1, // LOAD_FAST 1
    0x34,0x01, // CALL_FUNCTION 1
    0xd7, // BINARY_OP 0 __lt__
    0x43,0x12, // POP_JUMP_IF_TRUE -46
    0x23,0x00, // LOAD_CONST_OBJ 0
    0xb0, // LOAD_FAST 0
    0x18,0x2c, // STORE_ATTR 'out_buf'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_stream_Stream_drain = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 1,
    .fun_data = fun_data_asyncio_stream_Stream_drain,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 86,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 9,
        .n_exc_stack = 0,
        .scope_flags = 1,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 40,
        .line_info = fun_data_asyncio_stream_Stream_drain + 5,
        .line_info_top = fun_data_asyncio_stream_Stream_drain + 5,
        .opcodes = fun_data_asyncio_stream_Stream_drain + 5,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_stream_Stream_drain fun_data_asyncio_stream_Stream_drain[0]
#endif

static const mp_raw_code_t *const children_asyncio_stream_Stream[] = {
    (const mp_raw_code_t *)&proto_fun_asyncio_stream_Stream___init__,
    (const mp_raw_code_t *)&proto_fun_asyncio_stream_Stream_get_extra_info,
    (const mp_raw_code_t *)&proto_fun_asyncio_stream_Stream_close,
    (const mp_raw_code_t *)&proto_fun_asyncio_stream_Stream_wait_closed,
    (const mp_raw_code_t *)&proto_fun_asyncio_stream_Stream_read,
    (const mp_raw_code_t *)&proto_fun_asyncio_stream_Stream_readinto,
    (const mp_raw_code_t *)&proto_fun_asyncio_stream_Stream_readexactly,
    (const mp_raw_code_t *)&proto_fun_asyncio_stream_Stream_readline,
    (const mp_raw_code_t *)&proto_fun_asyncio_stream_Stream_write,
    (const mp_raw_code_t *)&proto_fun_asyncio_stream_Stream_drain,
};

static const mp_raw_code_truncated_t proto_fun_asyncio_stream_Stream = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_stream_Stream,
    .children = (void *)&children_asyncio_stream_Stream,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 62,
    .n_children = 10,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 2,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 4,
        .line_info = fun_data_asyncio_stream_Stream + 3,
        .line_info_top = fun_data_asyncio_stream_Stream + 3,
        .opcodes = fun_data_asyncio_stream_Stream + 3,
    },
    #endif
    #endif
};

// child of asyncio_stream__lt_module_gt_
// frozen bytecode for file asyncio/stream.py, scope asyncio_stream_open_connection
static const byte fun_data_asyncio_stream_open_connection[171] = {
    0x88,0xd6,0x01,0x0a, // prelude
    0x0a,0x41,0x42,0x12,0x16, // names: open_connection, host, port, ssl, server_hostname
     // code info
    0x80, // LOAD_CONST_SMALL_INT 0
    0x10,0x0b, // LOAD_CONST_STRING 'EINPROGRESS'
    0x2a,0x01, // BUILD_TUPLE 1
    0x1b,0x0c, // IMPORT_NAME 'errno'
    0x1c,0x0b, // IMPORT_FROM 'EINPROGRESS'
    0xc4, // STORE_FAST 4
    0x59, // POP_TOP
    0x80, // LOAD_CONST_SMALL_INT 0
    0x51, // LOAD_CONST_NONE
    0x1b,0x0d, // IMPORT_NAME 'socket'
    0xc5, // STORE_FAST 5
    0xb5, // LOAD_FAST 5
    0x14,0x0e, // LOAD_METHOD 'getaddrinfo'
    0xb0, // LOAD_FAST 0
    0xb1, // LOAD_FAST 1
    0x80, // LOAD_CONST_SMALL_INT 0
    0xb5, // LOAD_FAST 5
    0x13,0x0f, // LOAD_ATTR 'SOCK_STREAM'
    0x36,0x04, // CALL_METHOD 4
    0x80, // LOAD_CONST_SMALL_INT 0
    0x55, // LOAD_SUBSCR
    0xc6, // STORE_FAST 6
    0xb5, // LOAD_FAST 5
    0x14,0x0d, // LOAD_METHOD 'socket'
    0xb6, // LOAD_FAST 6
    0x80, // LOAD_CONST_SMALL_INT 0
    0x55, // LOAD_SUBSCR
    0xb6, // LOAD_FAST 6
    0x81, // LOAD_CONST_SMALL_INT 1
    0x55, // LOAD_SUBSCR
    0xb6, // LOAD_FAST 6
    0x82, // LOAD_CONST_SMALL_INT 2
    0x55, // LOAD_SUBSCR
    0x36,0x03, // CALL_METHOD 3
    0xc7, // STORE_FAST 7
    0xb7, // LOAD_FAST 7
    0x14,0x10, // LOAD_METHOD 'setblocking'
    0x50, // LOAD_CONST_FALSE
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x48,0x0b, // SETUP_EXCEPT 11
    0xb7, // LOAD_FAST 7
    0x14,0x11, // LOAD_METHOD 'connect'
    0xb6, // LOAD_FAST 6
    0x7f, // LOAD_CONST_SMALL_INT -1
    0x55, // LOAD_SUBSCR
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x4a,0x1b, // POP_EXCEPT_JUMP 27
    0x57, // DUP_TOP
    0x12,0x43, // LOAD_GLOBAL 'OSError'
    0xdf, // BINARY_OP 8 <exception match>
    0x44,0x54, // POP_JUMP_IF_FALSE 20
    0xc8, // STORE_FAST 8
    0x49,0x0a, // SETUP_FINALLY 10
    0xb8, // LOAD_FAST 8
    0x13,0x0c, // LOAD_ATTR 'errno'
    0xb4, // LOAD_FAST 4
    0xdc, // BINARY_OP 5 __ne__
    0x44,0x42, // POP_JUMP_IF_FALSE 2
    0xb8, // LOAD_FAST 8
    0x65, // RAISE_OBJ
    0x51, // LOAD_CONST_NONE
    0x51, // LOAD_CONST_NONE
    0xc8, // STORE_FAST 8
    0x28,0x08, // DELETE_FAST 8
    0x5d, // END_FINALLY
    0x4a,0x01, // POP_EXCEPT_JUMP 1
    0x5d, // END_FINALLY
    0xb2, // LOAD_FAST 2
    0x44,0x6d, // POP_JUMP_IF_FALSE 45
    0xb2, // LOAD_FAST 2
    0x52, // LOAD_CONST_TRUE
    0xde, // BINARY_OP 7 <is>
    0x44,0x4e, // POP_JUMP_IF_FALSE 14
    0x80, // LOAD_CONST_SMALL_INT 0
    0x51, // LOAD_CONST_NONE
    0x1b,0x12, // IMPORT_NAME 'ssl'
    0xc9, // STORE_FAST 9
    0xb9, // LOAD_FAST 9
    0x14,0x13, // LOAD_METHOD 'SSLContext'
    0xb9, // LOAD_FAST 9
    0x13,0x14, // LOAD_ATTR 'PROTOCOL_TLS_CLIENT'
    0x36,0x01, // CALL_METHOD 1
    0xc2, // STORE_FAST 2
    0xb3, // LOAD_FAST 3
    0x43,0x42, // POP_JUMP_IF_TRUE 2
    0xb0, // LOAD_FAST 0
    0xc3, // STORE_FAST 3
    0xb2, // LOAD_FAST 2
    0x14,0x15, // LOAD_METHOD 'wrap_socket'
    0xb7, // LOAD_FAST 7
    0x10,0x16, // LOAD_CONST_STRING 'server_hostname'
    0xb3, // LOAD_FAST 3
    0x10,0x17, // LOAD_CONST_STRING 'do_handshake_on_connect'
    0x50, // LOAD_CONST_FALSE
    0x36,0x84,0x01, // CALL_METHOD 513
    0xc7, // STORE_FAST 7
    0xb7, // LOAD_FAST 7
    0x14,0x10, // LOAD_METHOD 'setblocking'
    0x50, // LOAD_CONST_FALSE
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x12,0x04, // LOAD_GLOBAL 'Stream'
    0xb7, // LOAD_FAST 7
    0x34,0x01, // CALL_FUNCTION 1
    0xca, // STORE_FAST 10
    0x12,0x02, // LOAD_GLOBAL 'core'
    0x13,0x18, // LOAD_ATTR '_io_queue'
    0x14,0x19, // LOAD_METHOD 'queue_write'
    0xb7, // LOAD_FAST 7
    0x36,0x01, // CALL_METHOD 1
    0x67, // YIELD_VALUE
    0x59, // POP_TOP
    0xba, // LOAD_FAST 10
    0xba, // LOAD_FAST 10
    0x2a,0x02, // BUILD_TUPLE 2
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_stream_open_connection = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 1,
    .fun_data = fun_data_asyncio_stream_open_connection,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 171,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 18,
        .n_exc_stack = 2,
        .scope_flags = 1,
        .n_pos_args = 4,
        .n_kwonly_args = 0,
        .n_def_pos_args = 2,
        .qstr_block_name_idx = 10,
        .line_info = fun_data_asyncio_stream_open_connection + 9,
        .line_info_top = fun_data_asyncio_stream_open_connection + 9,
        .opcodes = fun_data_asyncio_stream_open_connection + 9,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_stream_open_connection fun_data_asyncio_stream_open_connection[0]
#endif

// child of asyncio_stream__lt_module_gt_
// frozen bytecode for file asyncio/stream.py, scope asyncio_stream_Server
static const byte fun_data_asyncio_stream_Server[33] = {
    0x00,0x02, // prelude
    0x05, // names: Server
     // code info
    0x11,0x3e, // LOAD_NAME '__name__'
    0x16,0x3f, // STORE_NAME '__module__'
    0x10,0x05, // LOAD_CONST_STRING 'Server'
    0x16,0x40, // STORE_NAME '__qualname__'
    0x32,0x00, // MAKE_FUNCTION 0
    0x16,0x34, // STORE_NAME '__aenter__'
    0x32,0x01, // MAKE_FUNCTION 1
    0x16,0x35, // STORE_NAME '__aexit__'
    0x32,0x02, // MAKE_FUNCTION 2
    0x16,0x2e, // STORE_NAME 'close'
    0x32,0x03, // MAKE_FUNCTION 3
    0x16,0x06, // STORE_NAME 'wait_closed'
    0x32,0x04, // MAKE_FUNCTION 4
    0x16,0x21, // STORE_NAME '_serve'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
// child of asyncio_stream_Server
// frozen bytecode for file asyncio/stream.py, scope asyncio_stream_Server___aenter__
static const byte fun_data_asyncio_stream_Server___aenter__[7] = {
    0x89,0x40,0x04, // prelude
    0x34,0x46, // names: __aenter__, self
     // code info
    0xb0, // LOAD_FAST 0
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_stream_Server___aenter__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 1,
    .fun_data = fun_data_asyncio_stream_Server___aenter__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 7,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 2,
        .n_exc_stack = 0,
        .scope_flags = 1,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 52,
        .line_info = fun_data_asyncio_stream_Server___aenter__ + 5,
        .line_info_top = fun_data_asyncio_stream_Server___aenter__ + 5,
        .opcodes = fun_data_asyncio_stream_Server___aenter__ + 5,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_stream_Server___aenter__ fun_data_asyncio_stream_Server___aenter__[0]
#endif

// child of asyncio_stream_Server
// frozen bytecode for file asyncio/stream.py, scope asyncio_stream_Server___aexit__
static const byte fun_data_asyncio_stream_Server___aexit__[25] = {
    0xa8,0x44,0x0a, // prelude
    0x35,0x46,0x4f,0x50,0x51, // names: __aexit__, self, exc_type, exc, tb
     // code info
    0xb0, // LOAD_FAST 0
    0x14,0x2e, // LOAD_METHOD 'close'
    0x36,0x00, // CALL_METHOD 0
    0x59, // POP_TOP
    0xb0, // LOAD_FAST 0
    0x14,0x06, // LOAD_METHOD 'wait_closed'
    0x36,0x00, // CALL_METHOD 0
    0x5e, // GET_ITER
    0x51, // LOAD_CONST_NONE
    0x68, // YIELD_FROM
    0x59, // POP_TOP
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_stream_Server___aexit__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 1,
    .fun_data = fun_data_asyncio_stream_Server___aexit__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 25,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 6,
        .n_exc_stack = 0,
        .scope_flags = 1,
        .n_pos_args = 4,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 53,
        .line_info = fun_data_asyncio_stream_Server___aexit__ + 8,
        .line_info_top = fun_data_asyncio_stream_Server___aexit__ + 8,
        .opcodes = fun_data_asyncio_stream_Server___aexit__ + 8,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_stream_Server___aexit__ fun_data_asyncio_stream_Server___aexit__[0]
#endif

// child of asyncio_stream_Server
// frozen bytecode for file asyncio/stream.py, scope asyncio_stream_Server_close
static const byte fun_data_asyncio_stream_Server_close[18] = {
    0x11,0x04, // prelude
    0x2e,0x46, // names: close, self
     // code info
    0x52, // LOAD_CONST_TRUE
    0xb0, // LOAD_FAST 0
    0x18,0x36, // STORE_ATTR 'state'
    0xb0, // LOAD_FAST 0
    0x13,0x22, // LOAD_ATTR 'task'
    0x14,0x25, // LOAD_METHOD 'cancel'
    0x36,0x00, // CALL_METHOD 0
    0x59, // POP_TOP
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_stream_Server_close = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_stream_Server_close,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 18,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 46,
        .line_info = fun_data_asyncio_stream_Server_close + 4,
        .line_info_top = fun_data_asyncio_stream_Server_close + 4,
        .opcodes = fun_data_asyncio_stream_Server_close + 4,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_stream_Server_close fun_data_asyncio_stream_Server_close[0]
#endif

// child of asyncio_stream_Server
// frozen bytecode for file asyncio/stream.py, scope asyncio_stream_Server_wait_closed
static const byte fun_data_asyncio_stream_Server_wait_closed[14] = {
    0x91,0x40,0x04, // prelude
    0x06,0x46, // names: wait_closed, self
     // code info
    0xb0, // LOAD_FAST 0
    0x13,0x22, // LOAD_ATTR 'task'
    0x5e, // GET_ITER
    0x51, // LOAD_CONST_NONE
    0x68, // YIELD_FROM
    0x59, // POP_TOP
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_stream_Server_wait_closed = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 1,
    .fun_data = fun_data_asyncio_stream_Server_wait_closed,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 14,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 1,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 6,
        .line_info = fun_data_asyncio_stream_Server_wait_closed + 5,
        .line_info_top = fun_data_asyncio_stream_Server_wait_closed + 5,
        .opcodes = fun_data_asyncio_stream_Server_wait_closed + 5,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_stream_Server_wait_closed fun_data_asyncio_stream_Server_wait_closed[0]
#endif

// child of asyncio_stream_Server
// frozen bytecode for file asyncio/stream.py, scope asyncio_stream_Server__serve
static const byte fun_data_asyncio_stream_Server__serve[174] = {
    0xf8,0x46,0x0a, // prelude
    0x21,0x46,0x2a,0x44,0x12, // names: _serve, self, s, cb, ssl
     // code info
    0x50, // LOAD_CONST_FALSE
    0xb0, // LOAD_FAST 0
    0x18,0x36, // STORE_ATTR 'state'
    0x48,0x0d, // SETUP_EXCEPT 13
    0x12,0x02, // LOAD_GLOBAL 'core'
    0x13,0x18, // LOAD_ATTR '_io_queue'
    0x14,0x30, // LOAD_METHOD 'queue_read'
    0xb1, // LOAD_FAST 1
    0x36,0x01, // CALL_METHOD 1
    0x67, // YIELD_VALUE
    0x59, // POP_TOP
    0x4a,0x23, // POP_EXCEPT_JUMP 35
    0x57, // DUP_TOP
    0x12,0x02, // LOAD_GLOBAL 'core'
    0x13,0x24, // LOAD_ATTR 'CancelledError'
    0xdf, // BINARY_OP 8 <exception match>
    0x44,0x5a, // POP_JUMP_IF_FALSE 26
    0xc4, // STORE_FAST 4
    0x49,0x10, // SETUP_FINALLY 16
    0xb1, // LOAD_FAST 1
    0x14,0x2e, // LOAD_METHOD 'close'
    0x36,0x00, // CALL_METHOD 0
    0x59, // POP_TOP
    0xb0, // LOAD_FAST 0
    0x13,0x36, // LOAD_ATTR 'state'
    0x44,0x42, // POP_JUMP_IF_FALSE 2
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
    0xb4, // LOAD_FAST 4
    0x65, // RAISE_OBJ
    0x51, // LOAD_CONST_NONE
    0x51, // LOAD_CONST_NONE
    0xc4, // STORE_FAST 4
    0x28,0x04, // DELETE_FAST 4
    0x5d, // END_FINALLY
    0x4a,0x01, // POP_EXCEPT_JUMP 1
    0x5d, // END_FINALLY
    0x48,0x0b, // SETUP_EXCEPT 11
    0xb1, // LOAD_FAST 1
    0x14,0x37, // LOAD_METHOD 'accept'
    0x36,0x00, // CALL_METHOD 0
    0x30,0x02, // UNPACK_SEQUENCE 2
    0xc5, // STORE_FAST 5
    0xc6, // STORE_FAST 6
    0x4a,0x06, // POP_EXCEPT_JUMP 6
    0x59, // POP_TOP
    0x40,0xda,0x80,0x01, // UNWIND_JUMP 90
    0x5d, // END_FINALLY
    0xb3, // LOAD_FAST 3
    0x44,0x76, // POP_JUMP_IF_FALSE 54
    0x48,0x10, // SETUP_EXCEPT 16
    0xb3, // LOAD_FAST 3
    0x14,0x15, // LOAD_METHOD 'wrap_socket'
    0xb5, // LOAD_FAST 5
    0x10,0x38, // LOAD_CONST_STRING 'server_side'
    0x52, // LOAD_CONST_TRUE
    0x10,0x17, // LOAD_CONST_STRING 'do_handshake_on_connect'
    0x50, // LOAD_CONST_FALSE
    0x36,0x84,0x01, // CALL_METHOD 513
    0xc5, // STORE_FAST 5
    0x4a,0x24, // POP_EXCEPT_JUMP 36
    0x57, // DUP_TOP
    0x12,0x43, // LOAD_GLOBAL 'OSError'
    0xdf, // BINARY_OP 8 <exception match>
    0x44,0x5d, // POP_JUMP_IF_FALSE 29
    0xc7, // STORE_FAST 7
    0x49,0x13, // SETUP_FINALLY 19
    0x12,0x02, // LOAD_GLOBAL 'core'
    0x13,0x39, // LOAD_ATTR 'sys'
    0x14,0x3a, // LOAD_METHOD 'print_exception'
    0xb7, // LOAD_FAST 7
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0xb5, // LOAD_FAST 5
    0x14,0x2e, // LOAD_METHOD 'close'
    0x36,0x00, // CALL_METHOD 0
    0x59, // POP_TOP
    0x40,0x68,0x02, // UNWIND_JUMP 40
    0x51, // LOAD_CONST_NONE
    0xc7, // STORE_FAST 7
    0x28,0x07, // DELETE_FAST 7
    0x5d, // END_FINALLY
    0x4a,0x01, // POP_EXCEPT_JUMP 1
    0x5d, // END_FINALLY
    0xb5, // LOAD_FAST 5
    0x14,0x10, // LOAD_METHOD 'setblocking'
    0x50, // LOAD_CONST_FALSE
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x12,0x04, // LOAD_GLOBAL 'Stream'
    0xb5, // LOAD_FAST 5
    0x2c,0x01, // BUILD_MAP 1
    0xb6, // LOAD_FAST 6
    0x10,0x3b, // LOAD_CONST_STRING 'peername'
    0x62, // STORE_MAP
    0x34,0x02, // CALL_FUNCTION 2
    0xc8, // STORE_FAST 8
    0x12,0x02, // LOAD_GLOBAL 'core'
    0x14,0x20, // LOAD_METHOD 'create_task'
    0xb2, // LOAD_FAST 2
    0xb8, // LOAD_FAST 8
    0xb8, // LOAD_FAST 8
    0x34,0x02, // CALL_FUNCTION 2
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x42,0xe0,0x7e, // JUMP -160
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_stream_Server__serve = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 1,
    .fun_data = fun_data_asyncio_stream_Server__serve,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 174,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 16,
        .n_exc_stack = 2,
        .scope_flags = 1,
        .n_pos_args = 4,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 33,
        .line_info = fun_data_asyncio_stream_Server__serve + 8,
        .line_info_top = fun_data_asyncio_stream_Server__serve + 8,
        .opcodes = fun_data_asyncio_stream_Server__serve + 8,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_stream_Server__serve fun_data_asyncio_stream_Server__serve[0]
#endif

static const mp_raw_code_t *const children_asyncio_stream_Server[] = {
    (const mp_raw_code_t *)&proto_fun_asyncio_stream_Server___aenter__,
    (const mp_raw_code_t *)&proto_fun_asyncio_stream_Server___aexit__,
    (const mp_raw_code_t *)&proto_fun_asyncio_stream_Server_close,
    (const mp_raw_code_t *)&proto_fun_asyncio_stream_Server_wait_closed,
    (const mp_raw_code_t *)&proto_fun_asyncio_stream_Server__serve,
};

static const mp_raw_code_truncated_t proto_fun_asyncio_stream_Server = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_stream_Server,
    .children = (void *)&children_asyncio_stream_Server,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 33,
    .n_children = 5,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 1,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 5,
        .line_info = fun_data_asyncio_stream_Server + 3,
        .line_info_top = fun_data_asyncio_stream_Server + 3,
        .opcodes = fun_data_asyncio_stream_Server + 3,
    },
    #endif
    #endif
};

// child of asyncio_stream__lt_module_gt_
// frozen bytecode for file asyncio/stream.py, scope asyncio_stream_start_server
static const byte fun_data_asyncio_stream_start_server[135] = {
    0xf9,0xc6,0x01,0x0c, // prelude
    0x1a,0x44,0x41,0x42,0x45,0x12, // names: start_server, cb, host, port, backlog, ssl
     // code info
    0x80, // LOAD_CONST_SMALL_INT 0
    0x51, // LOAD_CONST_NONE
    0x1b,0x0d, // IMPORT_NAME 'socket'
    0xc5, // STORE_FAST 5
    0xb5, // LOAD_FAST 5
    0x14,0x0e, // LOAD_METHOD 'getaddrinfo'
    0xb1, // LOAD_FAST 1
    0xb2, // LOAD_FAST 2
    0x36,0x02, // CALL_METHOD 2
    0x80, // LOAD_CONST_SMALL_INT 0
    0x55, // LOAD_SUBSCR
    0xc1, // STORE_FAST 1
    0xb5, // LOAD_FAST 5
    0x14,0x0d, // LOAD_METHOD 'socket'
    0x36,0x00, // CALL_METHOD 0
    0xc6, // STORE_FAST 6
    0xb6, // LOAD_FAST 6
    0x14,0x10, // LOAD_METHOD 'setblocking'
    0x50, // LOAD_CONST_FALSE
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0xb6, // LOAD_FAST 6
    0x14,0x1b, // LOAD_METHOD 'setsockopt'
    0xb5, // LOAD_FAST 5
    0x13,0x1c, // LOAD_ATTR 'SOL_SOCKET'
    0xb5, // LOAD_FAST 5
    0x13,0x1d, // LOAD_ATTR 'SO_REUSEADDR'
    0x81, // LOAD_CONST_SMALL_INT 1
    0x36,0x03, // CALL_METHOD 3
    0x59, // POP_TOP
    0xb6, // LOAD_FAST 6
    0x14,0x1e, // LOAD_METHOD 'bind'
    0xb1, // LOAD_FAST 1
    0x7f, // LOAD_CONST_SMALL_INT -1
    0x55, // LOAD_SUBSCR
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0xb6, // LOAD_FAST 6
    0x14,0x1f, // LOAD_METHOD 'listen'
    0xb3, // LOAD_FAST 3
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0x12,0x05, // LOAD_GLOBAL 'Server'
    0x34,0x00, // CALL_FUNCTION 0
    0xc7, // STORE_FAST 7
    0x12,0x02, // LOAD_GLOBAL 'core'
    0x14,0x20, // LOAD_METHOD 'create_task'
    0xb7, // LOAD_FAST 7
    0x14,0x21, // LOAD_METHOD '_serve'
    0xb6, // LOAD_FAST 6
    0xb0, // LOAD_FAST 0
    0xb4, // LOAD_FAST 4
    0x36,0x03, // CALL_METHOD 3
    0x36,0x01, // CALL_METHOD 1
    0xb7, // LOAD_FAST 7
    0x18,0x22, // STORE_ATTR 'task'
    0x48,0x0d, // SETUP_EXCEPT 13
    0x12,0x02, // LOAD_GLOBAL 'core'
    0x14,0x23, // LOAD_METHOD 'sleep_ms'
    0x80, // LOAD_CONST_SMALL_INT 0
    0x36,0x01, // CALL_METHOD 1
    0x5e, // GET_ITER
    0x51, // LOAD_CONST_NONE
    0x68, // YIELD_FROM
    0x59, // POP_TOP
    0x4a,0x1d, // POP_EXCEPT_JUMP 29
    0x57, // DUP_TOP
    0x12,0x02, // LOAD_GLOBAL 'core'
    0x13,0x24, // LOAD_ATTR 'CancelledError'
    0xdf, // BINARY_OP 8 <exception match>
    0x44,0x54, // POP_JUMP_IF_FALSE 20
    0xc8, // STORE_FAST 8
    0x49,0x0a, // SETUP_FINALLY 10
    0xb7, // LOAD_FAST 7
    0x13,0x22, // LOAD_ATTR 'task'
    0x14,0x25, // LOAD_METHOD 'cancel'
    0x36,0x00, // CALL_METHOD 0
    0x59, // POP_TOP
    0xb8, // LOAD_FAST 8
    0x65, // RAISE_OBJ
    0x51, // LOAD_CONST_NONE
    0xc8, // STORE_FAST 8
    0x28,0x08, // DELETE_FAST 8
    0x5d, // END_FINALLY
    0x4a,0x01, // POP_EXCEPT_JUMP 1
    0x5d, // END_FINALLY
    0xb7, // LOAD_FAST 7
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_stream_start_server = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 1,
    .fun_data = fun_data_asyncio_stream_start_server,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 135,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 16,
        .n_exc_stack = 2,
        .scope_flags = 1,
        .n_pos_args = 5,
        .n_kwonly_args = 0,
        .n_def_pos_args = 2,
        .qstr_block_name_idx = 26,
        .line_info = fun_data_asyncio_stream_start_server + 10,
        .line_info_top = fun_data_asyncio_stream_start_server + 10,
        .opcodes = fun_data_asyncio_stream_start_server + 10,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_stream_start_server fun_data_asyncio_stream_start_server[0]
#endif

// child of asyncio_stream__lt_module_gt_
// frozen bytecode for file asyncio/stream.py, scope asyncio_stream_stream_awrite
static const byte fun_data_asyncio_stream_stream_awrite[63] = {
    0xb8,0xc4,0x01,0x0a, // prelude
    0x26,0x46,0x47,0x48,0x49, // names: stream_awrite, self, buf, off, sz
     // code info
    0xb2, // LOAD_FAST 2
    0x80, // LOAD_CONST_SMALL_INT 0
    0xdc, // BINARY_OP 5 __ne__
    0x43,0x45, // POP_JUMP_IF_TRUE 5
    0xb3, // LOAD_FAST 3
    0x7f, // LOAD_CONST_SMALL_INT -1
    0xdc, // BINARY_OP 5 __ne__
    0x44,0x5a, // POP_JUMP_IF_FALSE 26
    0x12,0x4a, // LOAD_GLOBAL 'memoryview'
    0xb1, // LOAD_FAST 1
    0x34,0x01, // CALL_FUNCTION 1
    0xc1, // STORE_FAST 1
    0xb3, // LOAD_FAST 3
    0x7f, // LOAD_CONST_SMALL_INT -1
    0xd9, // BINARY_OP 2 __eq__
    0x44,0x46, // POP_JUMP_IF_FALSE 6
    0x12,0x4b, // LOAD_GLOBAL 'len'
    0xb1, // LOAD_FAST 1
    0x34,0x01, // CALL_FUNCTION 1
    0xc3, // STORE_FAST 3
    0xb1, // LOAD_FAST 1
    0xb2, // LOAD_FAST 2
    0xb2, // LOAD_FAST 2
    0xb3, // LOAD_FAST 3
    0xf2, // BINARY_OP 27 __add__
    0x2e,0x02, // BUILD_SLICE 2
    0x55, // LOAD_SUBSCR
    0xc1, // STORE_FAST 1
    0xb0, // LOAD_FAST 0
    0x14,0x27, // LOAD_METHOD 'write'
    0xb1, // LOAD_FAST 1
    0x36,0x01, // CALL_METHOD 1
    0x59, // POP_TOP
    0xb0, // LOAD_FAST 0
    0x14,0x28, // LOAD_METHOD 'drain'
    0x36,0x00, // CALL_METHOD 0
    0x5e, // GET_ITER
    0x51, // LOAD_CONST_NONE
    0x68, // YIELD_FROM
    0x59, // POP_TOP
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_asyncio_stream_stream_awrite = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 1,
    .fun_data = fun_data_asyncio_stream_stream_awrite,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 63,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 8,
        .n_exc_stack = 0,
        .scope_flags = 1,
        .n_pos_args = 4,
        .n_kwonly_args = 0,
        .n_def_pos_args = 2,
        .qstr_block_name_idx = 38,
        .line_info = fun_data_asyncio_stream_stream_awrite + 9,
        .line_info_top = fun_data_asyncio_stream_stream_awrite + 9,
        .opcodes = fun_data_asyncio_stream_stream_awrite + 9,
    },
    #endif
    #endif
};
#else
#define proto_fun_asyncio_stream_stream_awrite fun_data_asyncio_stream_stream_awrite[0]
#endif

static const mp_raw_code_t *const children_asyncio_stream__lt_module_gt_[] = {
    (const mp_raw_code_t *)&proto_fun_asyncio_stream_Stream,
    (const mp_raw_code_t *)&proto_fun_asyncio_stream_open_connection,
    (const mp_raw_code_t *)&proto_fun_asyncio_stream_Server,
    (const mp_raw_code_t *)&proto_fun_asyncio_stream_start_server,
    (const mp_raw_code_t *)&proto_fun_asyncio_stream_stream_awrite,
};

static const mp_raw_code_truncated_t proto_fun_asyncio_stream__lt_module_gt_ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_asyncio_stream__lt_module_gt_,
    .children = (void *)&children_asyncio_stream__lt_module_gt_,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 90,
    .n_children = 5,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 3,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 1,
        .line_info = fun_data_asyncio_stream__lt_module_gt_ + 3,
        .line_info_top = fun_data_asyncio_stream__lt_module_gt_ + 3,
        .opcodes = fun_data_asyncio_stream__lt_module_gt_ + 3,
    },
    #endif
    #endif
};

static const qstr_short_t const_qstr_table_data_asyncio_stream[82] = {
    MP_QSTR_asyncio_slash_stream_dot_py,
    MP_QSTR__lt_module_gt_,
    MP_QSTR_core,
    MP_QSTR_,
    MP_QSTR_Stream,
    MP_QSTR_Server,
    MP_QSTR_wait_closed,
    MP_QSTR_aclose,
    MP_QSTR_awrite,
    MP_QSTR_awritestr,
    MP_QSTR_open_connection,
    MP_QSTR_EINPROGRESS,
    MP_QSTR_errno,
    MP_QSTR_socket,
    MP_QSTR_getaddrinfo,
    MP_QSTR_SOCK_STREAM,
    MP_QSTR_setblocking,
    MP_QSTR_connect,
    MP_QSTR_ssl,
    MP_QSTR_SSLContext,
    MP_QSTR_PROTOCOL_TLS_CLIENT,
    MP_QSTR_wrap_socket,
    MP_QSTR_server_hostname,
    MP_QSTR_do_handshake_on_connect,
    MP_QSTR__io_queue,
    MP_QSTR_queue_write,
    MP_QSTR_start_server,
    MP_QSTR_setsockopt,
    MP_QSTR_SOL_SOCKET,
    MP_QSTR_SO_REUSEADDR,
    MP_QSTR_bind,
    MP_QSTR_listen,
    MP_QSTR_create_task,
    MP_QSTR__serve,
    MP_QSTR_task,
    MP_QSTR_sleep_ms,
    MP_QSTR_CancelledError,
    MP_QSTR_cancel,
    MP_QSTR_stream_awrite,
    MP_QSTR_write,
    MP_QSTR_drain,
    MP_QSTR___init__,
    MP_QSTR_s,
    MP_QSTR_e,
    MP_QSTR_out_buf,
    MP_QSTR_get_extra_info,
    MP_QSTR_close,
    MP_QSTR_read,
    MP_QSTR_queue_read,
    MP_QSTR_readinto,
    MP_QSTR_readexactly,
    MP_QSTR_readline,
    MP_QSTR___aenter__,
    MP_QSTR___aexit__,
    MP_QSTR_state,
    MP_QSTR_accept,
    MP_QSTR_server_side,
    MP_QSTR_sys,
    MP_QSTR_print_exception,
    MP_QSTR_peername,
    MP_QSTR_StreamReader,
    MP_QSTR_StreamWriter,
    MP_QSTR___name__,
    MP_QSTR___module__,
    MP_QSTR___qualname__,
    MP_QSTR_host,
    MP_QSTR_port,
    MP_QSTR_OSError,
    MP_QSTR_cb,
    MP_QSTR_backlog,
    MP_QSTR_self,
    MP_QSTR_buf,
    MP_QSTR_off,
    MP_QSTR_sz,
    MP_QSTR_memoryview,
    MP_QSTR_len,
    MP_QSTR_v,
    MP_QSTR_n,
    MP_QSTR_EOFError,
    MP_QSTR_exc_type,
    MP_QSTR_exc,
    MP_QSTR_tb,
};

// constants

// constant table
static const mp_rom_obj_t const_obj_table_data_asyncio_stream[1] = {
    MP_ROM_PTR(&mp_const_empty_bytes_obj),
};

static const mp_frozen_module_t frozen_module_asyncio_stream = {
    .constants = {
        .qstr_table = (qstr_short_t *)&const_qstr_table_data_asyncio_stream,
        .obj_table = (mp_obj_t *)&const_obj_table_data_asyncio_stream,
    },
    .proto_fun = &proto_fun_asyncio_stream__lt_module_gt_,
};

////////////////////////////////////////////////////////////////////////////////
// frozen module uasyncio
// - original source file: /Users/gadgetoid/Development/micropython-web/picovector/ports/sokol/build/frozen_mpy/uasyncio.mpy
// - frozen file name: uasyncio.py
// - .mpy header: 4d:06:00:1f

// frozen bytecode for file uasyncio.py, scope uasyncio__lt_module_gt_
static const byte fun_data_uasyncio__lt_module_gt_[9] = {
    0x00,0x02, // prelude
    0x01, // names: <module>
     // code info
    0x32,0x00, // MAKE_FUNCTION 0
    0x16,0x02, // STORE_NAME '__getattr__'
    0x51, // LOAD_CONST_NONE
    0x63, // RETURN_VALUE
};
// child of uasyncio__lt_module_gt_
// frozen bytecode for file uasyncio.py, scope uasyncio___getattr__
static const byte fun_data_uasyncio___getattr__[16] = {
    0x21,0x04, // prelude
    0x02,0x04, // names: __getattr__, attr
     // code info
    0x80, // LOAD_CONST_SMALL_INT 0
    0x51, // LOAD_CONST_NONE
    0x1b,0x03, // IMPORT_NAME 'asyncio'
    0xc1, // STORE_FAST 1
    0x12,0x05, // LOAD_GLOBAL 'getattr'
    0xb1, // LOAD_FAST 1
    0xb0, // LOAD_FAST 0
    0x34,0x02, // CALL_FUNCTION 2
    0x63, // RETURN_VALUE
};
#if MICROPY_PERSISTENT_CODE_SAVE
static const mp_raw_code_truncated_t proto_fun_uasyncio___getattr__ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_uasyncio___getattr__,
    .children = NULL,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 16,
    .n_children = 0,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 5,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 1,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 2,
        .line_info = fun_data_uasyncio___getattr__ + 4,
        .line_info_top = fun_data_uasyncio___getattr__ + 4,
        .opcodes = fun_data_uasyncio___getattr__ + 4,
    },
    #endif
    #endif
};
#else
#define proto_fun_uasyncio___getattr__ fun_data_uasyncio___getattr__[0]
#endif

static const mp_raw_code_t *const children_uasyncio__lt_module_gt_[] = {
    (const mp_raw_code_t *)&proto_fun_uasyncio___getattr__,
};

static const mp_raw_code_truncated_t proto_fun_uasyncio__lt_module_gt_ = {
    .proto_fun_indicator[0] = MP_PROTO_FUN_INDICATOR_RAW_CODE_0,
    .proto_fun_indicator[1] = MP_PROTO_FUN_INDICATOR_RAW_CODE_1,
    .kind = MP_CODE_BYTECODE,
    .is_generator = 0,
    .fun_data = fun_data_uasyncio__lt_module_gt_,
    .children = (void *)&children_uasyncio__lt_module_gt_,
    #if MICROPY_PERSISTENT_CODE_SAVE
    .fun_data_len = 9,
    .n_children = 1,
    #if MICROPY_EMIT_MACHINE_CODE
    .prelude_offset = 0,
    #endif
    #if MICROPY_PY_SYS_SETTRACE
    .line_of_definition = 0,
    .prelude = {
        .n_state = 1,
        .n_exc_stack = 0,
        .scope_flags = 0,
        .n_pos_args = 0,
        .n_kwonly_args = 0,
        .n_def_pos_args = 0,
        .qstr_block_name_idx = 1,
        .line_info = fun_data_uasyncio__lt_module_gt_ + 3,
        .line_info_top = fun_data_uasyncio__lt_module_gt_ + 3,
        .opcodes = fun_data_uasyncio__lt_module_gt_ + 3,
    },
    #endif
    #endif
};

static const qstr_short_t const_qstr_table_data_uasyncio[6] = {
    MP_QSTR_uasyncio_dot_py,
    MP_QSTR__lt_module_gt_,
    MP_QSTR___getattr__,
    MP_QSTR_asyncio,
    MP_QSTR_attr,
    MP_QSTR_getattr,
};

static const mp_frozen_module_t frozen_module_uasyncio = {
    .constants = {
        .qstr_table = (qstr_short_t *)&const_qstr_table_data_uasyncio,
        .obj_table = NULL,
    },
    .proto_fun = &proto_fun_uasyncio__lt_module_gt_,
};

////////////////////////////////////////////////////////////////////////////////
// collection of all frozen modules

const char mp_frozen_names[] = {
    #ifdef MP_FROZEN_STR_NAMES
    MP_FROZEN_STR_NAMES
    #endif
    "argparse.py\0"
    "requests/__init__.py\0"
    "mip/__init__.py\0"
    "mip/__main__.py\0"
    "ssl.py\0"
    "asyncio/__init__.py\0"
    "asyncio/core.py\0"
    "asyncio/event.py\0"
    "asyncio/funcs.py\0"
    "asyncio/lock.py\0"
    "asyncio/stream.py\0"
    "uasyncio.py\0"
    "\0"
};

const mp_frozen_module_t *const mp_frozen_mpy_content[] = {
    &frozen_module_argparse,
    &frozen_module_requests___init__,
    &frozen_module_mip___init__,
    &frozen_module_mip___main__,
    &frozen_module_ssl,
    &frozen_module_asyncio___init__,
    &frozen_module_asyncio_core,
    &frozen_module_asyncio_event,
    &frozen_module_asyncio_funcs,
    &frozen_module_asyncio_lock,
    &frozen_module_asyncio_stream,
    &frozen_module_uasyncio,
};

#ifdef MICROPY_FROZEN_LIST_ITEM
MICROPY_FROZEN_LIST_ITEM("argparse", "argparse.py")
MICROPY_FROZEN_LIST_ITEM("requests", "requests/__init__.py")
MICROPY_FROZEN_LIST_ITEM("mip", "mip/__init__.py")
MICROPY_FROZEN_LIST_ITEM("mip/__main__", "mip/__main__.py")
MICROPY_FROZEN_LIST_ITEM("ssl", "ssl.py")
MICROPY_FROZEN_LIST_ITEM("asyncio", "asyncio/__init__.py")
MICROPY_FROZEN_LIST_ITEM("asyncio/core", "asyncio/core.py")
MICROPY_FROZEN_LIST_ITEM("asyncio/event", "asyncio/event.py")
MICROPY_FROZEN_LIST_ITEM("asyncio/funcs", "asyncio/funcs.py")
MICROPY_FROZEN_LIST_ITEM("asyncio/lock", "asyncio/lock.py")
MICROPY_FROZEN_LIST_ITEM("asyncio/stream", "asyncio/stream.py")
MICROPY_FROZEN_LIST_ITEM("uasyncio", "uasyncio.py")
#endif

/*
byte sizes:
qstr content: 303 unique, 3845 bytes
bc content: 9067
const str content: 509
const int content: 0
const obj content: 352
const table qstr content: 0 entries, 0 bytes
const table ptr content: 59 entries, 236 bytes
raw code content: 142 * 4 = 2272
mp_frozen_mpy_names_content: 189
mp_frozen_mpy_content_size: 48
total: 16518
*/
