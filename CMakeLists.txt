# minimum required CMAKE version
CMAKE_MINIMUM_REQUIRED(VERSION 3.16 FATAL_ERROR)

project("LSysGen" VERSION 0.6.2)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# compiler must be >=17
set(CMAKE_CXX_STANDARD 17)

# required if linking to static library
add_definitions(-DANTLR4CPP_STATIC)

# using /MD flag for antlr4_runtime (for Visual C++ compilers only)
set(ANTLR4_WITH_STATIC_CRT OFF)

# There are two values for CMAKE_BUILD_TYPE: Release and Debug (case sensitive).
# Debug type is required to use gcc properly. Default is Release.
# To build with debug purposes run:
# cmake -DCMAKE_BUILD_TYPE=Debug ..
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# set(ANTLR_BUILD_CPP_TESTS OFF)

# Specify the version of the antlr4 library needed for this project.
# By default the latest version of antlr4 will be used.  You can specify a
# specific, stable version by setting a repository tag value or a link
# to a zip file containing the libary source.
# set(ANTLR4_TAG 4.11.1) # Requires git
set(ANTLR4_ZIP_REPOSITORY https://github.com/antlr/antlr4/archive/refs/tags/4.11.1.zip)

#find_package(git REQUIRED)

# add external build for antlrcpp
include(ExternalAntlr4Cpp)
# add antrl4cpp artifacts to project environment

add_subdirectory (antlr4cpp_generated_src)
add_subdirectory (src)
add_subdirectory (docs EXCLUDE_FROM_ALL)


# if(WIN32)
# endif()

# if(APPLE)
# elseif(UNIX)
# endif()

# if(CMAKE_SYSTEM_NAME MATCHES "Linux")
# endif()

# # copy the input file next to the generated executable
# foreach( resource_file ${lsysgen_RESOURCES} )
#       add_custom_command(TARGET lsysgen POST_BUILD
#         COMMAND ${CMAKE_COMMAND} -E copy_if_different
#         ${resource_file}
#         $<TARGET_FILE_DIR:lsysgen>)
# endforeach( resource_file ${lsysgen_RESOURCES} )

# foreach( src_file ${ANTLR_LSysDLexer_CXX_OUTPUTS} ${ANTLR_LSysDParser_CXX_OUTPUTS} )
#       set_source_files_properties(
#           ${src_file}
#           PROPERTIES
#           GENERATED TRUE
#           )
# endforeach( src_file ${ANTLR_LSysDLexer_CXX_OUTPUTS} ${ANTLR_LSysDParser_CXX_OUTPUTS} )

