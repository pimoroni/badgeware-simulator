if (NOT DEFINED SOKOL_ONCE)
    set (SOKOL_ONCE TRUE)

    set(CMAKE_C_STANDARD 11)
    set(CMAKE_CXX_STANDARD 11)

    if (CMAKE_SYSTEM_NAME STREQUAL Linux)
        set(THREADS_PREFER_PTHREAD_FLAG ON)
        find_package(Threads REQUIRED)
    endif()

    get_filename_component(LIB_DIR "${CMAKE_CURRENT_LIST_DIR}/../" ABSOLUTE)

    #find_package(CIMGUI CONFIG REQUIRED PATHS ${LIB_DIR})
    #include(${LIB_DIR}/cimgui/cimgui-config.cmake)

    set(SOKOL_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR})

    set(SOKOL_HEADERS
        ${CMAKE_CURRENT_LIST_DIR}/sokol_gfx.h
        ${CMAKE_CURRENT_LIST_DIR}/sokol_app.h
        ${CMAKE_CURRENT_LIST_DIR}/sokol_args.h
        ${CMAKE_CURRENT_LIST_DIR}/sokol_imgui.h
        ${CMAKE_CURRENT_LIST_DIR}/sokol_glue.h
    )
    
    add_library(sokol STATIC
        ${CMAKE_CURRENT_LIST_DIR}/sokol.c
        ${SOKOL_HEADERS}
    )

    if(CMAKE_SYSTEM_NAME STREQUAL Darwin)
        target_compile_options(sokol PRIVATE -x objective-c)
        target_link_libraries(sokol PUBLIC
            "-framework QuartzCore"
            "-framework Cocoa"
            "-framework MetalKit"
            "-framework Metal"
        )
    else()
        if (CMAKE_SYSTEM_NAME STREQUAL Linux)
            target_link_libraries(sokol INTERFACE X11 Xi Xcursor GL dl m)
            target_link_libraries(sokol PUBLIC Threads::Threads)
        endif()
    endif()
    target_link_libraries(sokol PUBLIC cimgui)
    target_include_directories(sokol INTERFACE ${CMAKE_CURRENT_LIST_DIR})
endif()