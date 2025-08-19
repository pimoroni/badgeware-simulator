# 1 "<stdin>"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 424 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "<stdin>" 2
# 29 "<stdin>"
# 1 "/Users/gadgetoid/Development/micropython-web/picovector/lib/micropython/py/mpconfig.h" 1
# 91 "/Users/gadgetoid/Development/micropython-web/picovector/lib/micropython/py/mpconfig.h"
# 1 "/Users/gadgetoid/Development/micropython-web/picovector/ports/sokol/mpconfigport.h" 1
# 33 "/Users/gadgetoid/Development/micropython-web/picovector/ports/sokol/mpconfigport.h"
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/time.h" 1
# 63 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/time.h"
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_time.h" 1
# 66 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_time.h"
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types.h" 1
# 27 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types.h"
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types.h" 1
# 32 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types.h"
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h" 1
# 782 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h"
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_symbol_aliasing.h" 1
# 783 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h" 2
# 848 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h"
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_posix_availability.h" 1
# 849 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h" 2
# 33 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types.h" 2
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_types.h" 1
# 34 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_types.h"
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_types.h" 1
# 28 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_types.h"
typedef signed char __int8_t;



typedef unsigned char __uint8_t;
typedef short __int16_t;
typedef unsigned short __uint16_t;
typedef int __int32_t;
typedef unsigned int __uint32_t;
typedef long long __int64_t;
typedef unsigned long long __uint64_t;

typedef long __darwin_intptr_t;
typedef unsigned int __darwin_natural_t;
# 61 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_types.h"
typedef int __darwin_ct_rune_t;





typedef union {
 char __mbstate8[128];
 long long _mbstateL;
} __mbstate_t;

typedef __mbstate_t __darwin_mbstate_t;




typedef long int __darwin_ptrdiff_t;
# 87 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/_types.h"
typedef long unsigned int __darwin_size_t;







typedef __builtin_va_list __darwin_va_list;







typedef int __darwin_wchar_t;




typedef __darwin_wchar_t __darwin_rune_t;


typedef int __darwin_wint_t;




typedef unsigned long __darwin_clock_t;
typedef __uint32_t __darwin_socklen_t;
typedef long __darwin_ssize_t;
typedef long __darwin_time_t;
# 35 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_types.h" 2
# 34 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types.h" 2
# 67 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types.h"
typedef __int64_t __darwin_blkcnt_t;
typedef __int32_t __darwin_blksize_t;
typedef __int32_t __darwin_dev_t;
typedef unsigned int __darwin_fsblkcnt_t;
typedef unsigned int __darwin_fsfilcnt_t;
typedef __uint32_t __darwin_gid_t;
typedef __uint32_t __darwin_id_t;
typedef __uint64_t __darwin_ino64_t;

typedef __darwin_ino64_t __darwin_ino_t;



typedef __darwin_natural_t __darwin_mach_port_name_t;
typedef __darwin_mach_port_name_t __darwin_mach_port_t;
typedef __uint16_t __darwin_mode_t;
typedef __int64_t __darwin_off_t;
typedef __int32_t __darwin_pid_t;
typedef __uint32_t __darwin_sigset_t;
typedef __int32_t __darwin_suseconds_t;
typedef __uint32_t __darwin_uid_t;
typedef __uint32_t __darwin_useconds_t;
typedef unsigned char __darwin_uuid_t[16];
typedef char __darwin_uuid_string_t[37];



# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_types.h" 1
# 57 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_types.h"
struct __darwin_pthread_handler_rec {
 void (*__routine)(void *);
 void *__arg;
 struct __darwin_pthread_handler_rec *__next;
};

struct _opaque_pthread_attr_t {
 long __sig;
 char __opaque[56];
};

struct _opaque_pthread_cond_t {
 long __sig;
 char __opaque[40];
};

struct _opaque_pthread_condattr_t {
 long __sig;
 char __opaque[8];
};

struct _opaque_pthread_mutex_t {
 long __sig;
 char __opaque[56];
};

struct _opaque_pthread_mutexattr_t {
 long __sig;
 char __opaque[8];
};

struct _opaque_pthread_once_t {
 long __sig;
 char __opaque[8];
};

struct _opaque_pthread_rwlock_t {
 long __sig;
 char __opaque[192];
};

struct _opaque_pthread_rwlockattr_t {
 long __sig;
 char __opaque[16];
};

struct _opaque_pthread_t {
 long __sig;
 struct __darwin_pthread_handler_rec *__cleanup_stack;
 char __opaque[8176];
};

typedef struct _opaque_pthread_attr_t __darwin_pthread_attr_t;
typedef struct _opaque_pthread_cond_t __darwin_pthread_cond_t;
typedef struct _opaque_pthread_condattr_t __darwin_pthread_condattr_t;
typedef unsigned long __darwin_pthread_key_t;
typedef struct _opaque_pthread_mutex_t __darwin_pthread_mutex_t;
typedef struct _opaque_pthread_mutexattr_t __darwin_pthread_mutexattr_t;
typedef struct _opaque_pthread_once_t __darwin_pthread_once_t;
typedef struct _opaque_pthread_rwlock_t __darwin_pthread_rwlock_t;
typedef struct _opaque_pthread_rwlockattr_t __darwin_pthread_rwlockattr_t;
typedef struct _opaque_pthread_t *__darwin_pthread_t;
# 95 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types.h" 2
# 28 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types.h" 2
# 40 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types.h"
typedef int __darwin_nl_item;
typedef int __darwin_wctrans_t;

typedef __uint32_t __darwin_wctype_t;
# 67 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_time.h" 2

# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/Availability.h" 1
# 176 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/Availability.h"
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityVersions.h" 1
# 177 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/Availability.h" 2
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternal.h" 1
# 178 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/Availability.h" 2
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternalLegacy.h" 1
# 179 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/Availability.h" 2
# 69 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_time.h" 2
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_clock_t.h" 1
# 30 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_clock_t.h"
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/types.h" 1
# 37 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/types.h"
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/types.h" 1
# 55 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/types.h"
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int8_t.h" 1
# 30 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int8_t.h"
typedef signed char int8_t;
# 56 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/types.h" 2
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int16_t.h" 1
# 30 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int16_t.h"
typedef short int16_t;
# 57 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/types.h" 2
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int32_t.h" 1
# 30 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int32_t.h"
typedef int int32_t;
# 58 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/types.h" 2
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int64_t.h" 1
# 30 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int64_t.h"
typedef long long int64_t;
# 59 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/types.h" 2

# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int8_t.h" 1
# 30 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int8_t.h"
typedef unsigned char u_int8_t;
# 61 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/types.h" 2
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int16_t.h" 1
# 30 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int16_t.h"
typedef unsigned short u_int16_t;
# 62 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/types.h" 2
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int32_t.h" 1
# 30 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int32_t.h"
typedef unsigned int u_int32_t;
# 63 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/types.h" 2
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int64_t.h" 1
# 30 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int64_t.h"
typedef unsigned long long u_int64_t;
# 64 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/types.h" 2


typedef int64_t register_t;




# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_intptr_t.h" 1
# 32 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_intptr_t.h"
typedef __darwin_intptr_t intptr_t;
# 72 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/types.h" 2
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uintptr_t.h" 1
# 34 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uintptr_t.h"
typedef unsigned long uintptr_t;
# 73 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/types.h" 2




typedef u_int64_t user_addr_t;
typedef u_int64_t user_size_t;
typedef int64_t user_ssize_t;
typedef int64_t user_long_t;
typedef u_int64_t user_ulong_t;
typedef int64_t user_time_t;
typedef int64_t user_off_t;
# 105 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/arm/types.h"
typedef u_int64_t syscall_arg_t;
# 38 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/types.h" 2
# 31 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_clock_t.h" 2
typedef __darwin_clock_t clock_t;
# 70 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_time.h" 2
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_null.h" 1
# 71 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_time.h" 2
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h" 1
# 50 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h"
typedef __darwin_size_t size_t;
# 72 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_time.h" 2
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_time_t.h" 1
# 31 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_time_t.h"
typedef __darwin_time_t time_t;
# 73 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_time.h" 2
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_timespec.h" 1
# 33 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_timespec.h"
struct timespec
{
 __darwin_time_t tv_sec;
 long tv_nsec;
};
# 74 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_time.h" 2

struct tm {
 int tm_sec;
 int tm_min;
 int tm_hour;
 int tm_mday;
 int tm_mon;
 int tm_year;
 int tm_wday;
 int tm_yday;
 int tm_isdst;
 long tm_gmtoff;
 char *tm_zone;
};
# 98 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_time.h"
extern char *tzname[];


extern int getdate_err;

extern long timezone __asm("_" "timezone" );

extern int daylight;


char *asctime(const struct tm *);
clock_t clock(void) __asm("_" "clock" );
char *ctime(const time_t *);
double difftime(time_t, time_t);
struct tm *getdate(const char *);
struct tm *gmtime(const time_t *);
struct tm *localtime(const time_t *);
time_t mktime(struct tm *) __asm("_" "mktime" );
size_t strftime(char * restrict, size_t, const char * restrict, const struct tm * restrict) __asm("_" "strftime" );
char *strptime(const char * restrict, const char * restrict, struct tm * restrict) __asm("_" "strptime" );
time_t time(time_t *);


void tzset(void);



char *asctime_r(const struct tm * restrict, char * restrict);
char *ctime_r(const time_t *, char *);
struct tm *gmtime_r(const time_t * restrict, struct tm * restrict);
struct tm *localtime_r(const time_t * restrict, struct tm * restrict);


time_t posix2time(time_t);



void tzsetwall(void);
time_t time2posix(time_t);
time_t timelocal(struct tm * const);
time_t timegm(struct tm * const);



int nanosleep(const struct timespec *__rqtp, struct timespec *__rmtp) __asm("_" "nanosleep" );
# 153 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_time.h"
typedef enum {
_CLOCK_REALTIME __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) = 0,

_CLOCK_MONOTONIC __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) = 6,


_CLOCK_MONOTONIC_RAW __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) = 4,

_CLOCK_MONOTONIC_RAW_APPROX __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) = 5,

_CLOCK_UPTIME_RAW __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) = 8,

_CLOCK_UPTIME_RAW_APPROX __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) = 9,


_CLOCK_PROCESS_CPUTIME_ID __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) = 12,

_CLOCK_THREAD_CPUTIME_ID __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0))) = 16

} clockid_t;

__attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0)))
int clock_getres(clockid_t __clock_id, struct timespec *__res);

__attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0)))
int clock_gettime(clockid_t __clock_id, struct timespec *__tp);


__attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0))) __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0)))
__uint64_t clock_gettime_nsec_np(clockid_t __clock_id);


__attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,unavailable)))
__attribute__((availability(tvos,unavailable))) __attribute__((availability(watchos,unavailable)))
int clock_settime(clockid_t __clock_id, const struct timespec *__tp);
# 198 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_time.h"
__attribute__((availability(macos,introduced=10.15))) __attribute__((availability(ios,introduced=13.0))) __attribute__((availability(tvos,introduced=13.0))) __attribute__((availability(watchos,introduced=6.0)))
int timespec_get(struct timespec *ts, int base);
# 64 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/time.h" 2
# 34 "/Users/gadgetoid/Development/micropython-web/picovector/ports/sokol/mpconfigport.h" 2


# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h" 1
# 72 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h"
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/unistd.h" 1
# 84 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/unistd.h"
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_posix_vdisable.h" 1
# 85 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/unistd.h" 2
# 122 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/unistd.h"
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_seek_set.h" 1
# 123 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/unistd.h" 2
# 132 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/unistd.h"
struct accessx_descriptor {
 unsigned int ad_name_offset;
 int ad_flags;
 int ad_pad[2];
};
# 180 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/unistd.h"
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h" 1
# 181 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/unistd.h" 2
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ssize_t.h" 1
# 31 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ssize_t.h"
typedef __darwin_ssize_t ssize_t;
# 182 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/unistd.h" 2
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint64_t.h" 1
# 31 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint64_t.h"
typedef unsigned long long uint64_t;
# 183 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/unistd.h" 2
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint32_t.h" 1
# 31 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint32_t.h"
typedef unsigned int uint32_t;
# 184 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/unistd.h" 2




int getattrlistbulk(int, void *, void *, size_t, uint64_t) __attribute__((availability(macosx,introduced=10.10)));
int getattrlistat(int, const char *, void *, void *, size_t, unsigned long) __attribute__((availability(macosx,introduced=10.10)));
int setattrlistat(int, const char *, void *, void *, size_t, uint32_t) __attribute__((availability(macosx,introduced=10.13))) __attribute__((availability(ios,introduced=11.0))) __attribute__((availability(tvos,introduced=11.0))) __attribute__((availability(watchos,introduced=4.0)));
ssize_t freadlink(int, char * restrict, size_t) __attribute__((availability(macos,introduced=13.0))) __attribute__((availability(ios,introduced=16.0))) __attribute__((availability(tvos,introduced=16.0))) __attribute__((availability(watchos,introduced=9.0)));
# 200 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/unistd.h"
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h" 1
# 201 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/unistd.h" 2


# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h" 1
# 31 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h"
typedef __darwin_uid_t uid_t;
# 204 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/unistd.h" 2
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_gid_t.h" 1
# 31 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_gid_t.h"
typedef __darwin_gid_t gid_t;
# 205 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/unistd.h" 2




int faccessat(int, const char *, int, int) __attribute__((availability(macosx,introduced=10.10)));
int fchownat(int, const char *, uid_t, gid_t, int) __attribute__((availability(macosx,introduced=10.10)));
int linkat(int, const char *, int, const char *, int) __attribute__((availability(macosx,introduced=10.10)));
ssize_t readlinkat(int, const char *, char *, size_t) __attribute__((availability(macosx,introduced=10.10)));
int symlinkat(const char *, int, const char *) __attribute__((availability(macosx,introduced=10.10)));
int unlinkat(int, const char *, int) __attribute__((availability(macosx,introduced=10.10)));
# 73 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h" 2



# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_off_t.h" 1
# 31 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_off_t.h"
typedef __darwin_off_t off_t;
# 77 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h" 2
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_pid_t.h" 1
# 31 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_pid_t.h"
typedef __darwin_pid_t pid_t;
# 78 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h" 2


# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h" 1
# 81 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h" 2


# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_useconds_t.h" 1
# 31 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_useconds_t.h"
typedef __darwin_useconds_t useconds_t;
# 84 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h" 2
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_null.h" 1
# 85 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h" 2
# 430 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h"
void _exit(int) __attribute__((__noreturn__));
int access(const char *, int);
unsigned int
  alarm(unsigned int);
int chdir(const char *);
int chown(const char *, uid_t, gid_t);

int close(int) __asm("_" "close" );

int dup(int);
int dup2(int, int);
int execl(const char * __path, const char * __arg0, ...) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
int execle(const char * __path, const char * __arg0, ...) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
int execlp(const char * __file, const char * __arg0, ...) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
int execv(const char * __path, char * const * __argv) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
int execve(const char * __file, char * const * __argv, char * const * __envp) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
int execvp(const char * __file, char * const * __argv) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
pid_t fork(void) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
long fpathconf(int, int);
char *getcwd(char *, size_t);
gid_t getegid(void);
uid_t geteuid(void);
gid_t getgid(void);



int getgroups(int, gid_t []);

char *getlogin(void);
pid_t getpgrp(void);
pid_t getpid(void);
pid_t getppid(void);
uid_t getuid(void);
int isatty(int);
int link(const char *, const char *);
off_t lseek(int, off_t, int);
long pathconf(const char *, int);

int pause(void) __asm("_" "pause" );

int pipe(int [2]);

ssize_t read(int, void *, size_t) __asm("_" "read" );

int rmdir(const char *);
int setgid(gid_t);
int setpgid(pid_t, pid_t);
pid_t setsid(void);
int setuid(uid_t);

unsigned int
  sleep(unsigned int) __asm("_" "sleep" );

long sysconf(int);
pid_t tcgetpgrp(int);
int tcsetpgrp(int, pid_t);
char *ttyname(int);


int ttyname_r(int, char *, size_t) __asm("_" "ttyname_r" );




int unlink(const char *);

ssize_t write(int __fd, const void * __buf, size_t __nbyte) __asm("_" "write" );
# 507 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h"
size_t confstr(int, char *, size_t) __asm("_" "confstr" );

int getopt(int, char * const [], const char *) __asm("_" "getopt" );

extern char *optarg;
extern int optind, opterr, optopt;
# 525 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h"
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_ctermid.h" 1
# 31 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_ctermid.h"
char *ctermid(char *);
# 526 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h" 2
# 538 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h"
__attribute__((__deprecated__)) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)))

void *brk(const void *);
int chroot(const char *) ;


char *crypt(const char *, const char *);

void encrypt(char *, int) __asm("_" "encrypt" );



int fchdir(int);
long gethostid(void);
pid_t getpgid(pid_t);
pid_t getsid(pid_t);



int getdtablesize(void) ;
int getpagesize(void) __attribute__((__const__)) ;
char *getpass(const char *) ;




char *getwd(char *) ;


int lchown(const char *, uid_t, gid_t) __asm("_" "lchown" );

int lockf(int, int, off_t) __asm("_" "lockf" );

int nice(int) __asm("_" "nice" );

ssize_t pread(int __fd, void * __buf, size_t __nbyte, off_t __offset) __asm("_" "pread" );

ssize_t pwrite(int __fd, const void * __buf, size_t __nbyte, off_t __offset) __asm("_" "pwrite" );






__attribute__((__deprecated__)) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)))

void *sbrk(int);



pid_t setpgrp(void) __asm("_" "setpgrp" );




int setregid(gid_t, gid_t) __asm("_" "setregid" );

int setreuid(uid_t, uid_t) __asm("_" "setreuid" );

void swab(const void * restrict, void * restrict, ssize_t);
void sync(void);
int truncate(const char *, off_t);
useconds_t ualarm(useconds_t, useconds_t);
int usleep(useconds_t) __asm("_" "usleep" );


__attribute__((__deprecated__("Use posix_spawn or fork")))

pid_t vfork(void) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));


int fsync(int) __asm("_" "fsync" );

int ftruncate(int, off_t);
int getlogin_r(char *, size_t);
# 625 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h"
int fchown(int, uid_t, gid_t);
int gethostname(char *, size_t);
ssize_t readlink(const char * restrict, char * restrict, size_t);
int setegid(gid_t);
int seteuid(uid_t);
int symlink(const char *, const char *);
# 639 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h"
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/select.h" 1
# 66 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/select.h"
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/appleapiopts.h" 1
# 67 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/select.h" 2








# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_def.h" 1
# 50 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_def.h"
typedef struct fd_set {
 __int32_t fds_bits[((((1024) % ((sizeof(__int32_t) * 8))) == 0) ? ((1024) / ((sizeof(__int32_t) * 8))) : (((1024) / ((sizeof(__int32_t) * 8))) + 1))];
} fd_set;

int __darwin_check_fd_set_overflow(int, const void *, int) __attribute__((availability(macos,introduced=11.0))) __attribute__((availability(ios,introduced=14.0))) __attribute__((availability(tvos,introduced=14.0))) __attribute__((availability(watchos,introduced=7.0)));


inline __attribute__ ((__always_inline__)) int
__darwin_check_fd_set(int _a, const void *_b)
{

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunguarded-availability-new"

 if ((uintptr_t)&__darwin_check_fd_set_overflow != (uintptr_t) 0) {



  return __darwin_check_fd_set_overflow(_a, _b, 0);

 } else {
  return 1;
 }

#pragma clang diagnostic pop

}


inline __attribute__ ((__always_inline__)) int
__darwin_fd_isset(int _fd, const struct fd_set *_p)
{
 if (__darwin_check_fd_set(_fd, (const void *) _p)) {
  return _p->fds_bits[(unsigned long)_fd / (sizeof(__int32_t) * 8)] & ((__int32_t)(((unsigned long)1) << ((unsigned long)_fd % (sizeof(__int32_t) * 8))));
 }

 return 0;
}

inline __attribute__ ((__always_inline__)) void
__darwin_fd_set(int _fd, struct fd_set *const _p)
{
 if (__darwin_check_fd_set(_fd, (const void *) _p)) {
  (_p->fds_bits[(unsigned long)_fd / (sizeof(__int32_t) * 8)] |= ((__int32_t)(((unsigned long)1) << ((unsigned long)_fd % (sizeof(__int32_t) * 8)))));
 }
}

inline __attribute__ ((__always_inline__)) void
__darwin_fd_clr(int _fd, struct fd_set *const _p)
{
 if (__darwin_check_fd_set(_fd, (const void *) _p)) {
  (_p->fds_bits[(unsigned long)_fd / (sizeof(__int32_t) * 8)] &= ~((__int32_t)(((unsigned long)1) << ((unsigned long)_fd % (sizeof(__int32_t) * 8)))));
 }
}
# 76 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/select.h" 2

# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_timeval.h" 1
# 34 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_timeval.h"
struct timeval
{
 __darwin_time_t tv_sec;
 __darwin_suseconds_t tv_usec;
};
# 78 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/select.h" 2







# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_suseconds_t.h" 1
# 31 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_suseconds_t.h"
typedef __darwin_suseconds_t suseconds_t;
# 86 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/select.h" 2
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigset_t.h" 1
# 31 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigset_t.h"
typedef __darwin_sigset_t sigset_t;
# 87 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/select.h" 2
# 100 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/select.h"
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_setsize.h" 1
# 101 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/select.h" 2
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_set.h" 1
# 102 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/select.h" 2
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_clr.h" 1
# 103 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/select.h" 2
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_isset.h" 1
# 104 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/select.h" 2
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_zero.h" 1
# 105 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/select.h" 2


# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_copy.h" 1
# 108 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/select.h" 2






int pselect(int, fd_set * restrict, fd_set * restrict,
    fd_set * restrict, const struct timespec * restrict,
    const sigset_t * restrict)




__asm("_" "pselect" )




;




# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_select.h" 1
# 43 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_select.h"
int select(int, fd_set * restrict, fd_set * restrict,
    fd_set * restrict, struct timeval * restrict)





__asm("_" "select" )




;
# 132 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/select.h" 2
# 640 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h" 2

# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_dev_t.h" 1
# 31 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_dev_t.h"
typedef __darwin_dev_t dev_t;
# 642 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h" 2
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_mode_t.h" 1
# 31 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_mode_t.h"
typedef __darwin_mode_t mode_t;
# 643 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h" 2
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uuid_t.h" 1
# 31 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uuid_t.h"
typedef __darwin_uuid_t uuid_t;
# 644 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h" 2


void _Exit(int) __attribute__((__noreturn__));
int accessx_np(const struct accessx_descriptor *, size_t, int *, uid_t);
int acct(const char *);
int add_profil(char *, size_t, unsigned long, unsigned int) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
void endusershell(void);
int execvP(const char * __file, const char * __searchpath, char * const * __argv) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
char *fflagstostr(unsigned long);
int getdomainname(char *, int);
int getgrouplist(const char *, int, int *, int *);

# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/gethostuuid.h" 1
# 41 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/gethostuuid.h"
int gethostuuid(uuid_t, const struct timespec *) __attribute__((availability(macos,introduced=10.5))) __attribute__((availability(ios,unavailable))) __attribute__((availability(tvos,unavailable))) __attribute__((availability(watchos,unavailable)));
# 657 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h" 2

mode_t getmode(const void *, mode_t);
int getpeereid(int, uid_t *, gid_t *);
int getsgroups_np(int *, uuid_t);
char *getusershell(void);
int getwgroups_np(int *, uuid_t);
int initgroups(const char *, int);
int issetugid(void);
char *mkdtemp(char *);
int mknod(const char *, mode_t, dev_t);
int mkpath_np(const char *path, mode_t omode) __attribute__((availability(macosx,introduced=10.8)));
int mkpathat_np(int dfd, const char *path, mode_t omode)
  __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0)))
  __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0)));
int mkstemp(char *);
int mkstemps(char *, int);
char *mktemp(char *);
int mkostemp(char *path, int oflags)
  __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0)))
  __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0)));
int mkostemps(char *path, int slen, int oflags)
  __attribute__((availability(macosx,introduced=10.12))) __attribute__((availability(ios,introduced=10.0)))
  __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0)));

int mkstemp_dprotected_np(char *path, int dpclass, int dpflags)
  __attribute__((availability(macosx,unavailable))) __attribute__((availability(ios,introduced=10.0)))
  __attribute__((availability(tvos,introduced=10.0))) __attribute__((availability(watchos,introduced=3.0)));
char *mkdtempat_np(int dfd, char *path)
  __attribute__((availability(macosx,introduced=10.13))) __attribute__((availability(ios,introduced=11.0)))
  __attribute__((availability(tvos,introduced=11.0))) __attribute__((availability(watchos,introduced=4.0)));
int mkstempsat_np(int dfd, char *path, int slen)
  __attribute__((availability(macosx,introduced=10.13))) __attribute__((availability(ios,introduced=11.0)))
  __attribute__((availability(tvos,introduced=11.0))) __attribute__((availability(watchos,introduced=4.0)));
int mkostempsat_np(int dfd, char *path, int slen, int oflags)
  __attribute__((availability(macosx,introduced=10.13))) __attribute__((availability(ios,introduced=11.0)))
  __attribute__((availability(tvos,introduced=11.0))) __attribute__((availability(watchos,introduced=4.0)));
int nfssvc(int, void *);
int profil(char *, size_t, unsigned long, unsigned int);

__attribute__((__deprecated__("Use of per-thread security contexts is error-prone and discouraged.")))
int pthread_setugid_np(uid_t, gid_t);
int pthread_getugid_np( uid_t *, gid_t *);

int reboot(int);
int revoke(const char *);

__attribute__((__deprecated__)) int rcmd(char **, int, const char *, const char *, const char *, int *);
__attribute__((__deprecated__)) int rcmd_af(char **, int, const char *, const char *, const char *, int *,
  int);
__attribute__((__deprecated__)) int rresvport(int *);
__attribute__((__deprecated__)) int rresvport_af(int *, int);
__attribute__((__deprecated__)) int iruserok(unsigned long, int, const char *, const char *);
__attribute__((__deprecated__)) int iruserok_sa(const void *, int, int, const char *, const char *);
__attribute__((__deprecated__)) int ruserok(const char *, int, const char *, const char *);

int setdomainname(const char *, int);
int setgroups(int, const gid_t *);
void sethostid(long);
int sethostname(const char *, int);

void setkey(const char *) __asm("_" "setkey" );



int setlogin(const char *);
void *setmode(const char *) __asm("_" "setmode" );
int setrgid(gid_t);
int setruid(uid_t);
int setsgroups_np(int, const uuid_t);
void setusershell(void);
int setwgroups_np(int, const uuid_t);
int strtofflags(char **, unsigned long *, unsigned long *);
int swapon(const char *);
int ttyslot(void);
int undelete(const char *);
int unwhiteout(const char *);
void *valloc(size_t);

__attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)))
__attribute__((availability(ios,deprecated=10.0,message="syscall(2) is unsupported; " "please switch to a supported interface. For SYS_kdebug_trace use kdebug_signpost().")))

__attribute__((availability(macosx,deprecated=10.12,message="syscall(2) is unsupported; " "please switch to a supported interface. For SYS_kdebug_trace use kdebug_signpost().")))

int syscall(int, ...);

extern char *suboptarg;
int getsubopt(char **, char * const *, char **);



int fgetattrlist(int,void*,void*,size_t,unsigned int) __attribute__((availability(macosx,introduced=10.6)));
int fsetattrlist(int,void*,void*,size_t,unsigned int) __attribute__((availability(macosx,introduced=10.6)));
int getattrlist(const char*,void*,void*,size_t,unsigned int) __asm("_" "getattrlist" );
int setattrlist(const char*,void*,void*,size_t,unsigned int) __asm("_" "setattrlist" );
int exchangedata(const char*,const char*,unsigned int) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
int getdirentriesattr(int,void*,void*,size_t,unsigned int*,unsigned int*,unsigned int*,unsigned int) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
# 767 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h"
struct fssearchblock;
struct searchstate;

int searchfs(const char *, struct fssearchblock *, unsigned long *, unsigned int, unsigned int, struct searchstate *) __attribute__((availability(watchos,unavailable))) __attribute__((availability(tvos,unavailable)));
int fsctl(const char *,unsigned long,void*,unsigned int);
int ffsctl(int,unsigned long,void*,unsigned int) __attribute__((availability(macosx,introduced=10.6)));




int fsync_volume_np(int, int) __attribute__((availability(macosx,introduced=10.8)));
int sync_volume_np(const char *, int) __attribute__((availability(macosx,introduced=10.8)));

extern int optreset;
# 37 "/Users/gadgetoid/Development/micropython-web/picovector/ports/sokol/mpconfigport.h" 2


# 1 "/Users/gadgetoid/Development/micropython-web/picovector/ports/sokol/variants/standard/mpconfigvariant.h" 1
# 33 "/Users/gadgetoid/Development/micropython-web/picovector/ports/sokol/variants/standard/mpconfigvariant.h"
# 1 "/Users/gadgetoid/Development/micropython-web/picovector/ports/sokol/variants/standard/../mpconfigvariant_common.h" 1
# 34 "/Users/gadgetoid/Development/micropython-web/picovector/ports/sokol/variants/standard/mpconfigvariant.h" 2
# 40 "/Users/gadgetoid/Development/micropython-web/picovector/ports/sokol/mpconfigport.h" 2
# 79 "/Users/gadgetoid/Development/micropython-web/picovector/ports/sokol/mpconfigport.h"
typedef long mp_int_t;
typedef unsigned long mp_uint_t;
# 95 "/Users/gadgetoid/Development/micropython-web/picovector/ports/sokol/mpconfigport.h"
typedef long mp_off_t;
# 104 "/Users/gadgetoid/Development/micropython-web/picovector/ports/sokol/mpconfigport.h"
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/alloca.h" 1
# 29 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/alloca.h"
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h" 1
# 30 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/alloca.h" 2


void *alloca(size_t);
# 105 "/Users/gadgetoid/Development/micropython-web/picovector/ports/sokol/mpconfigport.h" 2
# 173 "/Users/gadgetoid/Development/micropython-web/picovector/ports/sokol/mpconfigport.h"
extern const struct _mp_print_t mp_stderr_print;




void mp_unix_alloc_exec(size_t min_size, void **ptr, size_t *size);
void mp_unix_free_exec(void *ptr, size_t size);





# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stddef.h" 1
# 67 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stddef.h"
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_null.h" 1
# 68 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stddef.h" 2
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_offsetof.h" 1
# 69 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stddef.h" 2
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ptrdiff_t.h" 1
# 51 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ptrdiff_t.h"
typedef __darwin_ptrdiff_t ptrdiff_t;
# 70 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stddef.h" 2


# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_rsize_t.h" 1
# 50 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_rsize_t.h"
typedef __darwin_size_t rsize_t;
# 73 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stddef.h" 2




# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h" 1
# 78 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stddef.h" 2

# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_wchar_t.h" 1
# 53 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_wchar_t.h"
typedef __darwin_wchar_t wchar_t;
# 80 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stddef.h" 2


# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_wint_t.h" 1
# 32 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_wint_t.h"
typedef __darwin_wint_t wint_t;
# 83 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stddef.h" 2




typedef long double max_align_t;
# 186 "/Users/gadgetoid/Development/micropython-web/picovector/ports/sokol/mpconfigport.h" 2
void mp_hal_get_random(size_t n, void *buf);
static inline unsigned long mp_random_seed_init(void) {
    unsigned long r;
    mp_hal_get_random(sizeof(r), &r);
    return r;
}
# 228 "/Users/gadgetoid/Development/micropython-web/picovector/ports/sokol/mpconfigport.h"
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sched.h" 1
# 28 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sched.h"
# 1 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/pthread/pthread_impl.h" 1
# 33 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/pthread/pthread_impl.h"
#pragma clang assume_nonnull begin
# 33 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/pthread/pthread_impl.h"
#pragma clang assume_nonnull end
# 29 "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sched.h" 2






struct sched_param { int sched_priority; char __opaque[4]; };




extern int sched_yield(void);
extern int sched_get_priority_min(int);
extern int sched_get_priority_max(int);
# 229 "/Users/gadgetoid/Development/micropython-web/picovector/ports/sokol/mpconfigport.h" 2
# 92 "/Users/gadgetoid/Development/micropython-web/picovector/lib/micropython/py/mpconfig.h" 2
# 862 "/Users/gadgetoid/Development/micropython-web/picovector/lib/micropython/py/mpconfig.h"
typedef double mp_float_t;
# 979 "/Users/gadgetoid/Development/micropython-web/picovector/lib/micropython/py/mpconfig.h"
typedef time_t mp_timestamp_t;
# 30 "<stdin>" 2





QCFG(BYTES_IN_LEN, (1))
QCFG(BYTES_IN_HASH, (2))

Q()
Q(*)
Q(_)
Q(/)

Q(>>> )
Q(... )


Q(%#o)
Q(%#x)




Q({:#b})
Q( )
Q(\n)
Q(maximum recursion depth exceeded)
Q(<module>)
Q(<lambda>)
Q(<listcomp>)
Q(<dictcomp>)
Q(<setcomp>)
Q(<genexpr>)
Q(<string>)
Q(<stdin>)
Q(utf-8)
# 106 "<stdin>"
Q(ARRAY)

Q(AUTO)

Q(ArithmeticError)

Q(ArithmeticError)

Q(AssertionError)

Q(AssertionError)

Q(AssertionError)

Q(AttributeError)

Q(AttributeError)

Q(BFINT16)

Q(BFINT32)

Q(BFINT8)

Q(BFUINT16)

Q(BFUINT32)

Q(BFUINT8)

Q(BF_LEN)

Q(BF_POS)

Q(BIG_ENDIAN)

Q(BaseException)

Q(BaseException)

Q(BaseException)

Q(BytesIO)

Q(BytesIO)

Q(CancelledError)

Q(DeflateIO)

Q(DeflateIO)

Q(EACCES)

Q(EACCES)

Q(EADDRINUSE)

Q(EADDRINUSE)

Q(EAGAIN)

Q(EAGAIN)

Q(EALREADY)

Q(EALREADY)

Q(EBADF)

Q(EBADF)

Q(ECONNABORTED)

Q(ECONNABORTED)

Q(ECONNREFUSED)

Q(ECONNREFUSED)

Q(ECONNRESET)

Q(ECONNRESET)

Q(EEXIST)

Q(EEXIST)

Q(EHOSTUNREACH)

Q(EHOSTUNREACH)

Q(EINPROGRESS)

Q(EINPROGRESS)

Q(EINVAL)

Q(EINVAL)

Q(EIO)

Q(EIO)

Q(EISDIR)

Q(EISDIR)

Q(ENOBUFS)

Q(ENOBUFS)

Q(ENODEV)

Q(ENODEV)

Q(ENOENT)

Q(ENOENT)

Q(ENOMEM)

Q(ENOMEM)

Q(ENOTCONN)

Q(ENOTCONN)

Q(EOFError)

Q(EOFError)

Q(EOPNOTSUPP)

Q(EOPNOTSUPP)

Q(EPERM)

Q(EPERM)

Q(ETIMEDOUT)

Q(ETIMEDOUT)

Q(Ellipsis)

Q(Ellipsis)

Q(Exception)

Q(Exception)

Q(FLOAT32)

Q(FLOAT64)

Q(FileIO)

Q(FileIO)

Q(FrameBuffer)

Q(FrameBuffer)

Q(FrameBuffer1)

Q(GS2_HMSB)

Q(GS4_HMSB)

Q(GS8)

Q(GZIP)

Q(GeneratorExit)

Q(GeneratorExit)

Q(INT)

Q(INT16)

Q(INT32)

Q(INT64)

Q(INT8)

Q(IOBase)

Q(IOBase)

Q(ImportError)

Q(ImportError)

Q(IndentationError)

Q(IndentationError)

Q(IndexError)

Q(IndexError)

Q(KeyError)

Q(KeyError)

Q(KeyboardInterrupt)

Q(KeyboardInterrupt)

Q(LITTLE_ENDIAN)

Q(LONG)

Q(LONGLONG)

Q(LookupError)

Q(LookupError)

Q(MONO_HLSB)

Q(MONO_HMSB)

Q(MONO_VLSB)

Q(MVLSB)

Q(MemoryError)

Q(MemoryError)

Q(NATIVE)

Q(NameError)

Q(NameError)

Q(NoneType)

Q(NotImplemented)

Q(NotImplemented)

Q(NotImplementedError)

Q(NotImplementedError)

Q(OSError)

Q(OSError)

Q(OrderedDict)

Q(OrderedDict)

Q(OrderedDict)

Q(OverflowError)

Q(OverflowError)

Q(POLLERR)

Q(POLLHUP)

Q(POLLIN)

Q(POLLOUT)

Q(PTR)

Q(PicoVector)

Q(PicoVector)

Q(PinBase)

Q(PinBase)

Q(RAW)

Q(RGB565)

Q(RingIO)

Q(RingIO)

Q(RuntimeError)

Q(RuntimeError)

Q(SHORT)

Q(Shape)

Q(Signal)

Q(Signal)

Q(StopAsyncIteration)

Q(StopAsyncIteration)

Q(StopAsyncIteration)

Q(StopIteration)

Q(StopIteration)

Q(StringIO)

Q(StringIO)

Q(SyntaxError)

Q(SyntaxError)

Q(SystemExit)

Q(SystemExit)

Q(Task)

Q(Task)

Q(TaskQueue)

Q(TaskQueue)

Q(TextIOWrapper)

Q(TextIOWrapper)

Q(TypeError)

Q(TypeError)

Q(UINT)

Q(UINT16)

Q(UINT32)

Q(UINT64)

Q(UINT8)

Q(ULONG)

Q(ULONGLONG)

Q(USHORT)

Q(UnicodeError)

Q(UnicodeError)

Q(VOID)

Q(ValueError)

Q(ValueError)

Q(VfsPosix)

Q(VfsPosix)

Q(VfsPosix)

Q(VfsRom)

Q(VfsRom)

Q(ZLIB)

Q(ZeroDivisionError)

Q(ZeroDivisionError)

Q(_)

Q(_0x0a_)

Q(__abs__)

Q(__add__)

Q(__aenter__)

Q(__aenter__)

Q(__aexit__)

Q(__aexit__)

Q(__aiter__)

Q(__all__)

Q(__and__)

Q(__anext__)

Q(__bases__)

Q(__bool__)

Q(__build_class__)

Q(__build_class__)

Q(__call__)

Q(__class__)

Q(__class__)

Q(__class__)

Q(__class__)

Q(__class__)

Q(__class__)

Q(__class__)

Q(__complex__)

Q(__contains__)

Q(__contains__)

Q(__contains__)

Q(__del__)

Q(__del__)

Q(__del__)

Q(__del__)

Q(__delattr__)

Q(__delattr__)

Q(__delattr__)

Q(__delattr__)

Q(__delete__)

Q(__delete__)

Q(__delete__)

Q(__delitem__)

Q(__delitem__)

Q(__dict__)

Q(__dict__)

Q(__dict__)

Q(__dir__)

Q(__divmod__)

Q(__enter__)

Q(__enter__)

Q(__enter__)

Q(__enter__)

Q(__enter__)

Q(__eq__)

Q(__eq__)

Q(__exit__)

Q(__exit__)

Q(__exit__)

Q(__exit__)

Q(__exit__)

Q(__file__)

Q(__file__)

Q(__file__)

Q(__file__)

Q(__float__)

Q(__floordiv__)

Q(__ge__)

Q(__get__)

Q(__get__)

Q(__get__)

Q(__getattr__)

Q(__getattr__)

Q(__getattr__)

Q(__getattr__)

Q(__getitem__)

Q(__getitem__)

Q(__getitem__)

Q(__getitem__)

Q(__globals__)

Q(__gt__)

Q(__hash__)

Q(__iadd__)

Q(__import__)

Q(__import__)

Q(__init__)

Q(__init__)

Q(__init__)

Q(__init__)

Q(__init__)

Q(__int__)

Q(__invert__)

Q(__isub__)

Q(__iter__)

Q(__le__)

Q(__len__)

Q(__lshift__)

Q(__lt__)

Q(__main__)

Q(__main__)

Q(__main__)

Q(__main__)

Q(__main__)

Q(__main__)

Q(__main__)

Q(__matmul__)

Q(__mod__)

Q(__module__)

Q(__mul__)

Q(__name__)

Q(__name__)

Q(__name__)

Q(__name__)

Q(__name__)

Q(__name__)

Q(__name__)

Q(__name__)

Q(__name__)

Q(__name__)

Q(__name__)

Q(__name__)

Q(__name__)

Q(__name__)

Q(__name__)

Q(__name__)

Q(__name__)

Q(__name__)

Q(__name__)

Q(__name__)

Q(__name__)

Q(__name__)

Q(__name__)

Q(__name__)

Q(__name__)

Q(__name__)

Q(__name__)

Q(__name__)

Q(__name__)

Q(__name__)

Q(__name__)

Q(__name__)

Q(__name__)

Q(__name__)

Q(__name__)

Q(__name__)

Q(__name__)

Q(__name__)

Q(__name__)

Q(__ne__)

Q(__neg__)

Q(__new__)

Q(__new__)

Q(__new__)

Q(__next__)

Q(__next__)

Q(__next__)

Q(__next__)

Q(__or__)

Q(__path__)

Q(__path__)

Q(__path__)

Q(__path__)

Q(__pos__)

Q(__pow__)

Q(__qualname__)

Q(__radd__)

Q(__rand__)

Q(__repl_print__)

Q(__repl_print__)

Q(__repr__)

Q(__repr__)

Q(__reversed__)

Q(__rfloordiv__)

Q(__rlshift__)

Q(__rmatmul__)

Q(__rmod__)

Q(__rmul__)

Q(__ror__)

Q(__rpow__)

Q(__rrshift__)

Q(__rshift__)

Q(__rsub__)

Q(__rtruediv__)

Q(__rxor__)

Q(__set__)

Q(__set__)

Q(__set__)

Q(__set_name__)

Q(__set_name__)

Q(__setattr__)

Q(__setattr__)

Q(__setattr__)

Q(__setattr__)

Q(__setitem__)

Q(__setitem__)

Q(__str__)

Q(__sub__)

Q(__traceback__)

Q(__truediv__)

Q(__xor__)

Q(_asyncio)

Q(_asyncio)

Q(_brace_open__colon__hash_b_brace_close_)

Q(_dot__dot__dot__space_)

Q(_gt__gt__gt__space_)

Q(_lt_dictcomp_gt_)

Q(_lt_dictcomp_gt_)

Q(_lt_genexpr_gt_)

Q(_lt_genexpr_gt_)

Q(_lt_lambda_gt_)

Q(_lt_lambda_gt_)

Q(_lt_listcomp_gt_)

Q(_lt_listcomp_gt_)

Q(_lt_module_gt_)

Q(_lt_module_gt_)

Q(_lt_setcomp_gt_)

Q(_lt_setcomp_gt_)

Q(_lt_stdin_gt_)

Q(_lt_stdin_gt_)

Q(_lt_stdin_gt_)

Q(_lt_string_gt_)

Q(_machine)

Q(_mpy)

Q(_percent__hash_o)

Q(_percent__hash_x)

Q(_slash_)

Q(_slash_)

Q(_slash_)

Q(_slash_)

Q(_slash_)

Q(_slash_)

Q(_space_)

Q(_star_)

Q(_star_)

Q(_task_queue)

Q(a2b_base64)

Q(abs)

Q(abs_tol)

Q(acos)

Q(acosh)

Q(add)

Q(addressof)

Q(all)

Q(any)

Q(any)

Q(append)

Q(append)

Q(append)

Q(appendleft)

Q(arc)

Q(args)

Q(argv)

Q(array)

Q(array)

Q(array)

Q(array)

Q(asin)

Q(asinh)

Q(atan)

Q(atan2)

Q(atanh)

Q(atexit)

Q(b2a_base64)

Q(bin)

Q(binascii)

Q(binascii)

Q(blit)

Q(bool)

Q(bool)

Q(bound_method)

Q(buffer)

Q(buffering)

Q(builtins)

Q(builtins)

Q(bytearray)

Q(bytearray)

Q(bytearray_at)

Q(bytecode)

Q(byteorder)

Q(bytes)

Q(bytes)

Q(bytes)

Q(bytes_at)

Q(calcsize)

Q(callable)

Q(cancel)

Q(ceil)

Q(center)

Q(chdir)

Q(chdir)

Q(chdir)

Q(chdir)

Q(chdir)

Q(choice)

Q(chr)

Q(circle)

Q(classmethod)

Q(classmethod)

Q(clear)

Q(clear)

Q(clear)

Q(clock)

Q(close)

Q(close)

Q(close)

Q(close)

Q(close)

Q(close)

Q(close)

Q(close)

Q(closure)

Q(cmath)

Q(cmath)

Q(code)

Q(collect)

Q(collections)

Q(collections)

Q(compile)

Q(compile)

Q(complex)

Q(complex)

Q(const)

Q(const)

Q(copy)

Q(copy)

Q(copy)

Q(copy)

Q(copysign)

Q(coro)

Q(cos)

Q(cos)

Q(cosh)

Q(count)

Q(count)

Q(count)

Q(count)

Q(crc32)

Q(cur_task)

Q(cur_task)

Q(data)

Q(data)

Q(decode)

Q(default)

Q(deflate)

Q(deflate)

Q(degrees)

Q(delattr)

Q(deleter)

Q(deque)

Q(deque)

Q(dict)

Q(dict)

Q(dict_view)

Q(difference)

Q(difference)

Q(difference_update)

Q(digest)

Q(dir)

Q(disable)

Q(discard)

Q(divmod)

Q(doc)

Q(done)

Q(draw)

Q(dump)

Q(dumps)

Q(e)

Q(e)

Q(ellipse)

Q(enable)

Q(encode)

Q(encoding)

Q(end)

Q(endswith)

Q(enumerate)

Q(enumerate)

Q(erf)

Q(erfc)

Q(errno)

Q(errno)

Q(errno)

Q(errno)

Q(errno)

Q(errorcode)

Q(eval)

Q(eval)

Q(exc_info)

Q(exec)

Q(exec)

Q(execfile)

Q(executable)

Q(exit)

Q(exp)

Q(exp)

Q(expm1)

Q(extend)

Q(extend)

Q(extend)

Q(fabs)

Q(factorial)

Q(file)

Q(fileno)

Q(fill)

Q(fill_rect)

Q(filter)

Q(filter)

Q(find)

Q(float)

Q(float)

Q(floor)

Q(flush)

Q(flush)

Q(fmod)

Q(format)

Q(framebuf)

Q(framebuf)

Q(frexp)

Q(from)

Q(from)

Q(from_bytes)

Q(fromhex)

Q(fromkeys)

Q(frozenset)

Q(frozenset)

Q(function)

Q(function)

Q(function)

Q(function)

Q(function)

Q(function)

Q(function)

Q(function)

Q(gamma)

Q(gc)

Q(gc)

Q(generator)

Q(generator)

Q(get)

Q(getattr)

Q(getcwd)

Q(getcwd)

Q(getcwd)

Q(getcwd)

Q(getenv)

Q(getrandbits)

Q(getter)

Q(getvalue)

Q(globals)

Q(gmtime)

Q(group)

Q(hasattr)

Q(hash)

Q(hashlib)

Q(hashlib)

Q(heap_lock)

Q(heap_unlock)

Q(heapify)

Q(heappop)

Q(heappush)

Q(heapq)

Q(heapq)

Q(help)

Q(hex)

Q(hex)

Q(hexlify)

Q(hline)

Q(id)

Q(idle)

Q(ilistdir)

Q(ilistdir)

Q(ilistdir)

Q(ilistdir)

Q(ilistdir)

Q(imag)

Q(implementation)

Q(index)

Q(index)

Q(index)

Q(indices)

Q(inf)

Q(inner_radius)

Q(input)

Q(insert)

Q(int)

Q(int)

Q(intersection)

Q(intersection)

Q(intersection_update)

Q(invert)

Q(io)

Q(io)

Q(ioctl)

Q(ioctl)

Q(ioctl)

Q(ipoll)

Q(isalpha)

Q(isclose)

Q(isdigit)

Q(isdisjoint)

Q(isdisjoint)

Q(isenabled)

Q(isfinite)

Q(isinf)

Q(isinstance)

Q(islower)

Q(isnan)

Q(isspace)

Q(issubclass)

Q(issubset)

Q(issubset)

Q(issuperset)

Q(issuperset)

Q(isupper)

Q(items)

Q(iter)

Q(iterable)

Q(iterator)

Q(iterator)

Q(iterator)

Q(iterator)

Q(iterator)

Q(iterator)

Q(join)

Q(json)

Q(json)

Q(kbd_intr)

Q(keepends)

Q(key)

Q(key)

Q(keys)

Q(keys)

Q(ldexp)

Q(len)

Q(lgamma)

Q(libc_ver)

Q(line)

Q(line)

Q(list)

Q(list)

Q(listdir)

Q(little)

Q(little)

Q(little)

Q(load)

Q(loads)

Q(locals)

Q(localtime)

Q(log)

Q(log)

Q(log10)

Q(log10)

Q(log2)

Q(loop)

Q(lower)

Q(lstrip)

Q(machine)

Q(machine)

Q(map)

Q(map)

Q(match)

Q(match)

Q(match)

Q(math)

Q(math)

Q(math)

Q(max)

Q(maximum_space_recursion_space_depth_space_exceeded)

Q(maxsize)

Q(mem)

Q(mem16)

Q(mem32)

Q(mem8)

Q(mem_alloc)

Q(mem_current)

Q(mem_free)

Q(mem_info)

Q(mem_peak)

Q(mem_total)

Q(memoryview)

Q(memoryview)

Q(micropython)

Q(micropython)

Q(micropython)

Q(micropython)

Q(min)

Q(mkdir)

Q(mkdir)

Q(mkdir)

Q(mkfs)

Q(mktime)

Q(mode)

Q(modf)

Q(modify)

Q(modpicovector)

Q(module)

Q(modules)

Q(modules)

Q(mount)

Q(mount)

Q(mount)

Q(mount)

Q(mount)

Q(mount)

Q(n)

Q(name)

Q(namedtuple)

Q(nan)

Q(newline)

Q(next)

Q(object)

Q(object)

Q(oct)

Q(off)

Q(on)

Q(open)

Q(open)

Q(open)

Q(open)

Q(open)

Q(opt_level)

Q(ord)

Q(os)

Q(os)

Q(outer_radius)

Q(pack)

Q(pack_into)

Q(partition)

Q(path)

Q(peek)

Q(pend_throw)

Q(ph_key)

Q(phase)

Q(pi)

Q(pi)

Q(picovector)

Q(pie)

Q(pixel)

Q(platform)

Q(platform)

Q(platform)

Q(platform)

Q(polar)

Q(poll)

Q(poll)

Q(poll)

Q(poly)

Q(pop)

Q(pop)

Q(pop)

Q(pop)

Q(pop)

Q(popitem)

Q(popleft)

Q(pow)

Q(pow)

Q(print)

Q(print_exception)

Q(property)

Q(property)

Q(ps1)

Q(ps2)

Q(push)

Q(putenv)

Q(python_compiler)

Q(qstr_info)

Q(r)

Q(radians)

Q(radius)

Q(radius)

Q(radius)

Q(radius)

Q(randint)

Q(random)

Q(random)

Q(random)

Q(randrange)

Q(range)

Q(range)

Q(range)

Q(rb)

Q(re)

Q(re)

Q(re)

Q(read)

Q(read)

Q(read)

Q(read)

Q(read)

Q(read)

Q(readblocks)

Q(readinto)

Q(readinto)

Q(readinto)

Q(readinto)

Q(readinto)

Q(readinto)

Q(readinto)

Q(readline)

Q(readline)

Q(readline)

Q(readline)

Q(readline)

Q(readline)

Q(readlines)

Q(readlines)

Q(readonly)

Q(real)

Q(rect)

Q(rect)

Q(rectangle)

Q(register)

Q(regular_polygon)

Q(rel_tol)

Q(remove)

Q(remove)

Q(remove)

Q(remove)

Q(remove)

Q(remove)

Q(remove)

Q(rename)

Q(rename)

Q(rename)

Q(replace)

Q(repr)

Q(reverse)

Q(reverse)

Q(reversed)

Q(reversed)

Q(rfind)

Q(rindex)

Q(rmdir)

Q(rmdir)

Q(rmdir)

Q(round)

Q(rpartition)

Q(rsplit)

Q(rstrip)

Q(schedule)

Q(scroll)

Q(search)

Q(search)

Q(seed)

Q(seek)

Q(seek)

Q(seek)

Q(select)

Q(select)

Q(send)

Q(send)

Q(sep)

Q(sep)

Q(separators)

Q(set)

Q(set)

Q(setattr)

Q(setblocking)

Q(setdefault)

Q(setter)

Q(sha256)

Q(sha256)

Q(sides)

Q(sin)

Q(sin)

Q(single)

Q(sinh)

Q(size)

Q(sizeof)

Q(sleep)

Q(sleep_ms)

Q(sleep_us)

Q(slice)

Q(slice)

Q(soft_reset)

Q(sort)

Q(sorted)

Q(spikes)

Q(split)

Q(split)

Q(splitlines)

Q(sqrt)

Q(sqrt)

Q(squircle)

Q(stack_use)

Q(star)

Q(start)

Q(start)

Q(start)

Q(startswith)

Q(stat)

Q(stat)

Q(stat)

Q(stat)

Q(stat)

Q(state)

Q(state)

Q(staticmethod)

Q(staticmethod)

Q(statvfs)

Q(statvfs)

Q(statvfs)

Q(statvfs)

Q(step)

Q(step)

Q(stop)

Q(stop)

Q(str)

Q(str)

Q(str)

Q(str)

Q(strip)

Q(stroke)

Q(struct)

Q(struct)

Q(struct)

Q(struct)

Q(sub)

Q(sub)

Q(sum)

Q(super)

Q(super)

Q(super)

Q(symmetric_difference)

Q(symmetric_difference)

Q(symmetric_difference_update)

Q(sync)

Q(sys)

Q(sys)

Q(system)

Q(tan)

Q(tanh)

Q(tau)

Q(tell)

Q(tell)

Q(tell)

Q(text)

Q(threshold)

Q(throw)

Q(throw)

Q(ticks_add)

Q(ticks_cpu)

Q(ticks_diff)

Q(ticks_ms)

Q(ticks_us)

Q(time)

Q(time)

Q(time)

Q(time_ns)

Q(time_pulse_us)

Q(to)

Q(to)

Q(to_bytes)

Q(trunc)

Q(tuple)

Q(tuple)

Q(tuple)

Q(type)

Q(type)

Q(uctypes)

Q(uctypes)

Q(uctypes)

Q(umount)

Q(umount)

Q(umount)

Q(umount)

Q(umount)

Q(unhexlify)

Q(uniform)

Q(union)

Q(union)

Q(unlink)

Q(unpack)

Q(unpack_from)

Q(unregister)

Q(unsetenv)

Q(update)

Q(update)

Q(update)

Q(upper)

Q(urandom)

Q(usys)

Q(utf_hyphen_8)

Q(utf_hyphen_8)

Q(value)

Q(value)

Q(value)

Q(value)

Q(values)

Q(version)

Q(version)

Q(version_info)

Q(vfs)

Q(vfs)

Q(vline)

Q(websocket)

Q(websocket)

Q(websocket)

Q(websocket)

Q(write)

Q(write)

Q(write)

Q(write)

Q(write)

Q(writeblocks)

Q(x)

Q(x)

Q(x)

Q(x)

Q(x)

Q(x)

Q(x1)

Q(x1)

Q(x2)

Q(x2)

Q(y)

Q(y)

Q(y)

Q(y)

Q(y)

Q(y)

Q(y1)

Q(y1)

Q(y2)

Q(y2)

Q(zip)

Q(zip)
