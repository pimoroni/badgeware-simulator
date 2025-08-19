# Enable/disable modules and 3rd-party libs to be included in interpreter

# Build 32-bit binaries on a 64-bit host
set(MICROPY_FORCE_32BIT 0)

# This variable can take the following values:
#  0 - no readline, just simple stdin input
#  1 - use MicroPython version of readline
set(MICROPY_USE_READLINE 1)

# btree module using Berkeley DB 1.xx
set(MICROPY_PY_BTREE 1)

# _thread module using pthreads
set(MICROPY_PY_THREAD 1)
set(MICROPY_PY_THREAD_GIL 0)

# Subset of CPython termios module
set(MICROPY_PY_TERMIOS 0)

# Subset of CPython socket module
set(MICROPY_PY_SOCKET 0)

# ffi module requires libffi (libffi-dev Debian package)
set(MICROPY_PY_FFI 1)

# ssl module requires one of the TLS libraries below
set(MICROPY_PY_SSL 1)
# axTLS has minimal size but implements only a subset of modern TLS
# functionality, so may have problems with some servers.
set(MICROPY_SSL_AXTLS 0)
# mbedTLS is more up to date and complete implementation, but also
# more bloated.
set(MICROPY_SSL_MBEDTLS 1)

# jni module requires JVM/JNI
set(MICROPY_PY_JNI 0)

# Avoid using system libraries, use copies bundled with MicroPython
# as submodules (currently affects only libffi).
set(MICROPY_STANDALONE 0)

set(MICROPY_ROM_TEXT_COMPRESSION 1)

set(MICROPY_VFS_FAT 1)
set(MICROPY_VFS_LFS1 1)
set(MICROPY_VFS_LFS2 1)
