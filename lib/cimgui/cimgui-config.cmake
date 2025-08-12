if (NOT DEFINED CIMGUI_ONCE)
    set (CIMGUI_ONCE TRUE)

    add_library(cimgui STATIC
        ${CMAKE_CURRENT_LIST_DIR}/cimgui.cpp
        ${CMAKE_CURRENT_LIST_DIR}/cimgui.h
        ${CMAKE_CURRENT_LIST_DIR}/imgui.cpp
        ${CMAKE_CURRENT_LIST_DIR}/imgui.h
        ${CMAKE_CURRENT_LIST_DIR}/imgui_widgets.cpp
        ${CMAKE_CURRENT_LIST_DIR}/imgui_draw.cpp
        ${CMAKE_CURRENT_LIST_DIR}/imgui_tables.cpp
        ${CMAKE_CURRENT_LIST_DIR}/imgui_demo.cpp
    )

    set(CIMGUI_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR})

    target_include_directories(cimgui INTERFACE ${CIMGUI_INCLUDE_DIR})
endif()

