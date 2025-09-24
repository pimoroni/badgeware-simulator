add_library(usermod_picovector INTERFACE)

target_sources(usermod_picovector INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/modpicovector_bindings.c
    ${CMAKE_CURRENT_LIST_DIR}/modpicovector.cpp
    ${CMAKE_CURRENT_LIST_DIR}/picovector.cpp
    ${CMAKE_CURRENT_LIST_DIR}/image.cpp
    ${CMAKE_CURRENT_LIST_DIR}/shape.cpp
    ${CMAKE_CURRENT_LIST_DIR}/brush.cpp
    ${CMAKE_CURRENT_LIST_DIR}/primitive.cpp
    
)

target_include_directories(usermod_picovector INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(usermod INTERFACE usermod_picovector)

set_source_files_properties(
    ${CMAKE_CURRENT_LIST_DIR}/modpicovector.cpp
    ${CMAKE_CURRENT_LIST_DIR}/picovector.cpp
    ${CMAKE_CURRENT_LIST_DIR}/image.cpp
    ${CMAKE_CURRENT_LIST_DIR}/shape.cpp
    ${CMAKE_CURRENT_LIST_DIR}/brush.cpp
    ${CMAKE_CURRENT_LIST_DIR}/primitive.cpp
    PROPERTIES COMPILE_FLAGS
    #"-Wno-discarded-qualifiers"
    "-Wno-unused-variable"
)