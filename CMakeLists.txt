cmake_minimum_required(VERSION 3.22)

# Setup project
project(LwLibPROJECT)

if(NOT PROJECT_IS_TOP_LEVEL)
    add_subdirectory(lwevt)
else()
    # Set as executable
    add_executable(${PROJECT_NAME})
    target_sources(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR}/dev/main.c)
    target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/dev)

    # Add subdir with lwevt and link to project
    set(LWEVT_OPTS_FILE ${CMAKE_CURRENT_LIST_DIR}/dev/lwevt_opts.h)
    set(LWEVT_TYPES_FILE ${CMAKE_CURRENT_LIST_DIR}/dev/lwevt_types.h)
    add_subdirectory(lwevt)
    target_link_libraries(${PROJECT_NAME} PUBLIC lwevt)

    # Add compile options to the library, which will propagate options to executable through public link
    target_compile_definitions(lwevt PUBLIC WIN32 _DEBUG CONSOLE LWEVT_DEV)
    target_compile_options(lwevt PUBLIC -Wall -Wextra -Wpedantic)
endif()
