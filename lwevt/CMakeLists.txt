cmake_minimum_required(VERSION 3.22)

# Register library to the system
add_library(lwevt INTERFACE)
target_sources(lwevt INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src/lwevt/lwevt.c)
target_include_directories(lwevt INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src/include)

# Create config file
if(DEFINED LWEVT_OPTS_DIR AND NOT EXISTS ${LWEVT_OPTS_DIR}/lwevt_opts.h)
    configure_file(${CMAKE_CURRENT_LIST_DIR}/src/include/lwevt/lwevt_opts_template.h ${LWEVT_OPTS_DIR}/lwevt_opts.h COPYONLY)
endif()

# Create options file
if(DEFINED LWEVT_TYPES_DIR AND NOT EXISTS ${LWEVT_TYPES_DIR}/lwevt_types.h)
    configure_file(${CMAKE_CURRENT_LIST_DIR}/src/include/lwevt/lwevt_types_template.h ${LWEVT_OPTS_DIR}/lwevt_types.h COPYONLY)
endif()