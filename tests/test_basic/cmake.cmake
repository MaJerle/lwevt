# CMake include file

# Add more sources
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/test_basic.c
)

# Options files
set(LWEVT_OPTS_FILE ${CMAKE_CURRENT_LIST_DIR}/lwevt_opts.h)
set(LWEVT_TYPES_FILE ${CMAKE_CURRENT_LIST_DIR}/lwevt_types.h)
