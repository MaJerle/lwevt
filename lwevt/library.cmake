# 
# This file provides set of variables for end user
# and also generates one (or more) libraries, that can be added to the project using target_link_libraries(...)
#
# Before this file is included to the root CMakeLists file (using include() function), user can set some variables:
#
# LWEVT_OPTS_DIR: If defined, it should set the folder path where options file shall be generated.
# LWEVT_TYPES_DIR: If defined, it should set the folder path where event types file shall be generated.
# LWEVT_COMPILE_OPTIONS: If defined, it provide compiler options for generated library.
# LWEVT_COMPILE_DEFINITIONS: If defined, it provides "-D" definitions to the library build
#

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