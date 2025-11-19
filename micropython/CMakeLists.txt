cmake_minimum_required(VERSION 3.13)

if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(CMAKE_C_COMPILER "clang")
    set(CMAKE_CXX_COMPILER "clang++")
    # Hint: export SDKROOT="$(xcrun --sdk macosx --show-sdk-path)"
    # TODO: Make this not necessary!?
endif()

set(CMAKE_OSX_DEPLOYMENT_TARGET 14)
set(USER_C_MODULES "../src/micropython.cmake")

get_filename_component(LIB_DIR "../lib/" ABSOLUTE)
get_filename_component(USER_C_MODULES ${USER_C_MODULES} ABSOLUTE)

# Set build type to reduce firmware size
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE RelWithDebInfo)
endif()

# Set main target and component locations
set(MICROPY_TARGET micropython)
set(MICROPY_DIR "${LIB_DIR}/micropython")

# Set the location of this port's directory.
set(MICROPY_PORT_DIR ${CMAKE_CURRENT_LIST_DIR})

if(NOT VARIANT)
    set(VARIANT standard)
endif()

if(NOT DEFINED HEADLESS)
    set(HEADLESS FALSE)
endif()

# Set the location of this port's directory.
set(MICROPY_VARIANT_DIR "${CMAKE_CURRENT_LIST_DIR}/variants/${VARIANT}")

# If a board variant is specified, check that it exists.
if(NOT EXISTS ${MICROPY_VARIANT_DIR}/mpconfigvariant.cmake)
    message(FATAL_ERROR "Invalid VARIANT specified: ${VARIANT} (${MICROPY_VARIANT_DIR})")
endif()

set(MICROPY_USER_FROZEN_MANIFEST ${MICROPY_FROZEN_MANIFEST})

include(${MICROPY_VARIANT_DIR}/mpconfigvariant.cmake)

# Enable error text compression by default.
if(NOT MICROPY_ROM_TEXT_COMPRESSION)
    set(MICROPY_ROM_TEXT_COMPRESSION ON)
endif()

# Enable extmod components that will be configured by extmod.cmake.
# A board may also have enabled additional components.
set(MICROPY_SSL_MBEDTLS ON)

# Necessary submodules for all variants.
# list(APPEND GIT_SUBMODULES lib/...)

# Include component cmake fragments
include(${MICROPY_DIR}/py/py.cmake)
include(${MICROPY_DIR}/extmod/extmod.cmake)

# Define the top-level project
project(${MICROPY_TARGET})

include(${MICROPY_DIR}/py/usermod.cmake)

#include(${LIB_DIR}/sokol/sokol-config.cmake)
#include(${LIB_DIR}/cimgui/cimgui-config.cmake)

add_executable(${MICROPY_TARGET})

target_link_libraries(${MICROPY_TARGET} micropy_lib_mbedtls)

if(HEADLESS)
    target_compile_definitions(${MICROPY_TARGET} PRIVATE "HEADLESS=1")
    set(MICROPY_SOURCE_PORT ${MICROPY_PORT_DIR}/headless.c)

    # The Cocoa framework normally hangs off the sokol lib
    # but is required for dmon in headless mode, so link it here
    if(CMAKE_SYSTEM_NAME STREQUAL Darwin)
        target_link_libraries(${MICROPY_TARGET}
            "-framework Cocoa"
        )
    endif()
else()
    find_package(SOKOL CONFIG REQUIRED PATHS ${LIB_DIR})
    find_package(CIMGUI CONFIG REQUIRED PATHS ${LIB_DIR})

    
    list(APPEND MICROPY_CPP_FLAGS
        "-I${CIMGUI_INCLUDE_DIR}"
    )

    target_link_libraries(${MICROPY_TARGET} sokol cimgui)
    set(MICROPY_SOURCE_PORT ${MICROPY_PORT_DIR}/main.c)
endif()

set(MICROPY_QSTRDEFS_PORT
    ${MICROPY_PORT_DIR}/qstrdefsport.h
)

set(MICROPY_SOURCE_LIB
    ${MICROPY_DIR}/shared/runtime/gchelper_generic.c
    ${MICROPY_DIR}/shared/timeutils/timeutils.c
    ${MICROPY_DIR}/shared/readline/readline.c
)

list(APPEND MICROPY_SOURCE_PORT
    ${MICROPY_PORT_DIR}/badgeware.c
    ${MICROPY_PORT_DIR}/modsimulator.c
    ${MICROPY_PORT_DIR}/gccollect.c
	${MICROPY_PORT_DIR}/unix_mphal.c
	${MICROPY_PORT_DIR}/mpthreadport.c
	${MICROPY_PORT_DIR}/input.c
	${MICROPY_PORT_DIR}/alloc.c
	${MICROPY_PORT_DIR}/fatfs_port.c
	${MICROPY_PORT_DIR}/mpbthciport.c
	${MICROPY_PORT_DIR}/mpbtstackport_common.c
	${MICROPY_PORT_DIR}/mpbtstackport_h4.c
	${MICROPY_PORT_DIR}/mpbtstackport_usb.c
	${MICROPY_PORT_DIR}/mpnimbleport.c
	#${MICROPY_PORT_DIR}/modtermios.c
	${MICROPY_PORT_DIR}/modsocket.c
	${MICROPY_PORT_DIR}/modffi.c
	${MICROPY_PORT_DIR}/modjni.c
)
message(WARNING ${MICROPY_SOURCE_PORT})

# HACK: Fixup for missing nlraarch64.c
list(APPEND MICROPY_SOURCE_PORT
    ${MICROPY_PY_DIR}/nlraarch64.c
)

list(APPEND MICROPY_SOURCE_QSTR
    ${MICROPY_SOURCE_PY}
    ${MICROPY_SOURCE_PORT}
    ${MICROPY_SOURCE_LIB}
)

if(MICROPY_PY_BLUETOOTH)
    # TODO port from Makefile
endif()

if(MICROPY_STANDALONE)
    list(APPEND GIT_SUBMODULES lib/libffi)
    # TODO port libffi stuff?
endif()

# HACK: Fixup for missing machine_pinbase.c
list(APPEND MICROPY_SOURCE_EXTMOD
    ${MICROPY_EXTMOD_DIR}/machine_pinbase.c
)

# Add qstr sources for extmod and usermod, in case they are modified by components above.
list(APPEND MICROPY_SOURCE_QSTR
    ${MICROPY_SOURCE_EXTMOD}
    ${MICROPY_SOURCE_USERMOD}
    ${MICROPY_SOURCE_VARIANT}
)

# Set the frozen manifest file
if (MICROPY_USER_FROZEN_MANIFEST)
    set(MICROPY_FROZEN_MANIFEST ${MICROPY_USER_FROZEN_MANIFEST})
elseif (NOT MICROPY_FROZEN_MANIFEST)
    set(MICROPY_FROZEN_MANIFEST ${MICROPY_VARIANT_DIR}/manifest.py)
endif()

target_sources(${MICROPY_TARGET} PRIVATE
    ${MICROPY_SOURCE_PY}
    ${MICROPY_SOURCE_EXTMOD}
    ${MICROPY_SOURCE_LIB}
    ${MICROPY_SOURCE_PORT}
    ${MICROPY_SOURCE_VARIANT}
)

target_link_libraries(${MICROPY_TARGET} usermod)
target_link_libraries(${MICROPY_TARGET} pthread)

target_include_directories(${MICROPY_TARGET} PRIVATE
    ${MICROPY_DIR}
    ${MICROPY_INC_CORE}
    ${MICROPY_INC_USERMOD}
    ${MICROPY_VARIANT_DIR}
    "${MICROPY_PORT_DIR}"
    "${CMAKE_BINARY_DIR}"
    "${LIB_DIR}"
)

# Need these to make the QSTR parser happy
list(APPEND MICROPY_CPP_FLAGS
    "-I/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include"
    "-I${MICROPY_DIR}/lib/mbedtls/include"
    "-I${MICROPY_DIR}"
    "-I${MICROPY_VARIANT_DIR}"
    "-I${MICROPY_PORT_DIR}"
    "-I${CMAKE_BINARY_DIR}"
    "-DFFCONF_H=\"${MICROPY_DIR}/lib/oofatfs/ffconf.h\""
)

target_compile_options(${MICROPY_TARGET} PRIVATE
    -Wall
    -Werror
    -Wno-missing-braces
    -g  # always include debug information in the ELF
)

target_compile_options(${MICROPY_TARGET} PRIVATE $<$<COMPILE_LANGUAGE:C>:
    -std=gnu99
>)

target_compile_options(${MICROPY_TARGET} PRIVATE $<$<COMPILE_LANGUAGE:CXX>:
    -fno-exceptions
    -fno-unwind-tables
    -fno-rtti
    -fno-use-cxa-atexit
    -std=c++20
>)

target_compile_definitions(${MICROPY_TARGET} PRIVATE
    UNIX
    MICROPY_PORT_DIR=${MICROPY_PORT_DIR}
    MICROPY_PY_TERMIOS=1
    MICROPY_PY_SOCKET=1
    #MICROPY_PY_THREAD=1  # Build fails on macOS "call to undeclared function 'pthread_mach_thread_np'"
    #MICROPY_PY_THREAD_GIL=1
    FFCONF_H="${MICROPY_DIR}/lib/oofatfs/ffconf.h"
    MPZ_DIG_SIZE=16
)

# Apply optimisations to performance-critical source code.
set_source_files_properties(
    ${MICROPY_PY_DIR}/map.c
    ${MICROPY_PY_DIR}/mpz.c
    ${MICROPY_PY_DIR}/vm.c
    PROPERTIES
    COMPILE_OPTIONS "-O2"
)

set(MICROPY_CPP_FLAGS_EXTRA ${PICO_COMMON_LANG_FLAGS})
separate_arguments(MICROPY_CPP_FLAGS_EXTRA)

# Include the main MicroPython cmake rules.
include(${MICROPY_DIR}/py/mkrules.cmake)
