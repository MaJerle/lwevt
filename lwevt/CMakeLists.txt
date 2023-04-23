cmake_minimum_required(VERSION 3.22)

# Register library to the system
add_library(lwevt INTERFACE)
target_sources(lwevt INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src/lwevt/lwevt.c)
target_include_directories(lwevt INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src/include)
