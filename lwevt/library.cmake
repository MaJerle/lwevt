# 
# LIB_PREFIX: LWEVT
#
# This file provides set of variables for end user
# and also generates one (or more) libraries, that can be added to the project using target_link_libraries(...)
#
# Before this file is included to the root CMakeLists file (using include() function), user can set some variables:
#
# LWEVT_OPTS_FILE: If defined, it is the path to the user options file. If not defined, one will be generated for you automatically
# LWEVT_TYPES_FILE: If defined, it is the path to the user options file. If not defined, one will be generated for you automatically
# LWEVT_COMPILE_OPTIONS: If defined, it provide compiler options for generated library.
# LWEVT_COMPILE_DEFINITIONS: If defined, it provides "-D" definitions to the library build
#

# Custom include directory
set(LWEVT_CUSTOM_INC_DIR ${CMAKE_CURRENT_BINARY_DIR}/lib_inc)

# Library core sources
set(lwevt_core_SRCS 
    ${CMAKE_CURRENT_LIST_DIR}/src/lwevt/lwevt.c
)

# Setup include directories
set(lwevt_include_DIRS
    ${CMAKE_CURRENT_LIST_DIR}/src/include
    ${LWEVT_CUSTOM_INC_DIR}
)

# Register library to the system
add_library(lwevt INTERFACE)
target_sources(lwevt INTERFACE ${lwevt_core_SRCS})
target_include_directories(lwevt INTERFACE ${lwevt_include_DIRS})
target_compile_options(lwevt PRIVATE ${LWEVT_COMPILE_OPTIONS})
target_compile_definitions(lwevt PRIVATE ${LWEVT_COMPILE_DEFINITIONS})

# Create config file if user didn't provide one info himself
if(NOT LWEVT_OPTS_FILE)
    message(STATUS "Using default lwevt_opts.h file")
    set(LWEVT_OPTS_FILE ${CMAKE_CURRENT_LIST_DIR}/src/include/lwevt/lwevt_opts_template.h)
else()
    message(STATUS "Using custom lwevt_opts.h file from ${LWEVT_OPTS_FILE}")
endif()
configure_file(${LWEVT_OPTS_FILE} ${LWEVT_CUSTOM_INC_DIR}/lwevt_opts.h COPYONLY)

# Create config file if user didn't provide one info himself
if(NOT LWEVT_TYPES_FILE)
    message(STATUS "Using default lwevt_opts.h file")
    set(LWEVT_TYPES_FILE ${CMAKE_CURRENT_LIST_DIR}/src/include/lwevt/lwevt_types_template.h)
else()
    message(STATUS "Using custom lwevt_opts.h file from ${LWEVT_TYPES_FILE}")
endif()
configure_file(${LWEVT_TYPES_FILE} ${LWEVT_CUSTOM_INC_DIR}/lwevt_types.h COPYONLY)
