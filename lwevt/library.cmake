# Library core sources
set(lwevt_core_SRCS 
    ${CMAKE_CURRENT_LIST_DIR}/src/lwevt/lwevt.c
)

# Setup include directories
set(lwevt_include_DIRS
    ${CMAKE_CURRENT_LIST_DIR}/src/include
)

# Register library to the system
add_library(lwevt INTERFACE)
target_sources(lwevt INTERFACE ${lwevt_core_SRCS})
target_include_directories(lwevt INTERFACE ${lwevt_include_DIRS})
target_compile_options(lwevt PRIVATE ${LWEVT_COMPILE_OPTIONS})
target_compile_definitions(lwevt PRIVATE ${LWEVT_COMPILE_DEFINITIONS})

# Create config file
if(DEFINED LWEVT_OPTS_DIR AND NOT EXISTS ${LWEVT_OPTS_DIR}/lwevt_opts.h)
    configure_file(${CMAKE_CURRENT_LIST_DIR}/src/include/lwevt/lwevt_opts_template.h ${LWEVT_OPTS_DIR}/lwevt_opts.h COPYONLY)
endif()

# Create options file
if(DEFINED LWEVT_TYPES_DIR AND NOT EXISTS ${LWEVT_TYPES_DIR}/lwevt_types.h)
    configure_file(${CMAKE_CURRENT_LIST_DIR}/src/include/lwevt/lwevt_types_template.h ${LWEVT_OPTS_DIR}/lwevt_types.h COPYONLY)
endif()