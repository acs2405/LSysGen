# minimum required CMAKE version
CMAKE_MINIMUM_REQUIRED(VERSION 3.16 FATAL_ERROR)

project("LSysGen")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# compiler must be 17
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
if(WIN32)
  # Required java 11
  set(Java_JAVA_EXECUTABLE java)
endif()

# add external build for antlrcpp
include(ExternalAntlr4Cpp)
# add antrl4cpp artifacts to project environment
include_directories(${ANTLR4_INCLUDE_DIRS})

# set variable pointing to the antlr tool that supports C++
# this is not required if the jar file can be found under PATH environment
set(ANTLR_EXECUTABLE ${PROJECT_SOURCE_DIR}/antlr-4.11.1-complete.jar)
# add macros to generate ANTLR Cpp code from grammar
find_package(ANTLR)

set(ANTLR_LSysDLexer_OUTPUT_DIR ${PROJECT_SOURCE_DIR}/antlr4cpp_generated_src/LSysDLexer)
set(ANTLR_LSysDParser_OUTPUT_DIR ${PROJECT_SOURCE_DIR}/antlr4cpp_generated_src/LSysDParser)

if (Java_JAVA_EXECUTABLE)
  # Call macro to add lexer and grammar to your build dependencies.
  antlr_target(LSysDLexer LSysDLexer.g4 LEXER
               # PACKAGE antlrcpptest)
               OUTPUT_DIRECTORY ${ANTLR_LSysDLexer_OUTPUT_DIR})
  antlr_target(LSysDParser LSysDParser.g4 PARSER VISITOR
               # PACKAGE antlrcpptest
               OUTPUT_DIRECTORY ${ANTLR_LSysDParser_OUTPUT_DIR}
               DEPENDS_ANTLR LSysDLexer
               COMPILE_FLAGS -lib ${ANTLR_LSysDLexer_OUTPUT_DIR})
else()
  file (GLOB ANTLR_LSysDLexer_CXX_OUTPUTS ${ANTLR_LSysDLexer_OUTPUT_DIR}/*.cpp)
  file (GLOB ANTLR_LSysDParser_CXX_OUTPUTS ${ANTLR_LSysDParser_OUTPUT_DIR}/*.cpp)
endif()

# include generated files in project environment
include_directories(${ANTLR_LSysDLexer_OUTPUT_DIR})
include_directories(${ANTLR_LSysDParser_OUTPUT_DIR})

# cmake_policy(SET CMP0072 NEW)
# find_package(OpenGL)
# find_package(GLUT)
# if(OpenGL_FOUND AND GLUT_FOUND)
#   set(LSYSGEN_GRAPHICS True)

#   include_directories(${OPENGL_INCLUDE_DIRS})
#   include_directories(${GLUT_INCLUDE_DIRS})
# else()
#   set(LSYSGEN_GRAPHICS False)
# endif()

# file (GLOB lsysgen_HEADERS ${PROJECT_SOURCE_DIR}/src/*.h)
set(lsysgen_BASE_HEADERS
  ${PROJECT_SOURCE_DIR}/src/misc.h
  ${PROJECT_SOURCE_DIR}/src/values.h
  ${PROJECT_SOURCE_DIR}/src/operations.h
  ${PROJECT_SOURCE_DIR}/src/ParseTreeNode.h
  ${PROJECT_SOURCE_DIR}/src/NodeContent.h
  ${PROJECT_SOURCE_DIR}/src/Rule.h
  ${PROJECT_SOURCE_DIR}/src/Table.h
  ${PROJECT_SOURCE_DIR}/src/Derivator.h
  ${PROJECT_SOURCE_DIR}/src/LSystem.h
  ${PROJECT_SOURCE_DIR}/src/Module.h
  ${PROJECT_SOURCE_DIR}/src/ErrorHandler.h
  ${PROJECT_SOURCE_DIR}/src/LSysDVisitor.h
  ${PROJECT_SOURCE_DIR}/src/LSysDExpressionEvaluator.h
  ${PROJECT_SOURCE_DIR}/src/lsysgen.h
  ${PROJECT_SOURCE_DIR}/src/interpreter2D.h
  ${PROJECT_SOURCE_DIR}/src/Settings.h
  ${PROJECT_SOURCE_DIR}/src/cliargs.h
  )

include_directories(
  ${PROJECT_SOURCE_DIR}/src/
  )

set(lsysgen_BASE_SRC 
  ${PROJECT_SOURCE_DIR}/src/misc.cpp
  ${PROJECT_SOURCE_DIR}/src/values.cpp
  ${PROJECT_SOURCE_DIR}/src/operations.cpp
  ${PROJECT_SOURCE_DIR}/src/ParseTreeNode.cpp
  ${PROJECT_SOURCE_DIR}/src/NodeContent.cpp
  ${PROJECT_SOURCE_DIR}/src/Rule.cpp
  ${PROJECT_SOURCE_DIR}/src/Table.cpp
  ${PROJECT_SOURCE_DIR}/src/Derivator.cpp
  ${PROJECT_SOURCE_DIR}/src/LSystem.cpp
  ${PROJECT_SOURCE_DIR}/src/Module.cpp
  ${PROJECT_SOURCE_DIR}/src/ErrorHandler.cpp
  ${PROJECT_SOURCE_DIR}/src/LSysDVisitor.cpp
  ${PROJECT_SOURCE_DIR}/src/LSysDExpressionEvaluator.cpp
  ${PROJECT_SOURCE_DIR}/src/lsysgen.cpp
  ${PROJECT_SOURCE_DIR}/src/interpreter2D.cpp
  ${PROJECT_SOURCE_DIR}/src/Settings.cpp
  ${PROJECT_SOURCE_DIR}/src/cliargs.cpp
  )

# set(lsysgen_2D_SRC
#   ${PROJECT_SOURCE_DIR}/src/Drawer2D.cpp
#   )

set(lsysgen_MAIN_SRC
  ${PROJECT_SOURCE_DIR}/src/cli.cpp
  )

# set(lsysgen_SRC ${lsysgen_BASE_SRC} ${lsysgen_MAIN_SRC})

add_library(lsysantlr STATIC 
  ${ANTLR_LSysDLexer_CXX_OUTPUTS} 
  ${ANTLR_LSysDParser_CXX_OUTPUTS}
  )

# SHARED or STATIC
add_library(lsysgen STATIC 
  ${lsysgen_BASE_SRC} 
  )

target_precompile_headers(lsysgen PRIVATE
  # ${PROJECT_SOURCE_DIR}/src/pch.h
  ${PROJECT_SOURCE_DIR}/src/misc.h
  # ${lsysgen_BASE_HEADERS}
  )

# This lines prevent std::runtime_error with message "unknown error -1".
# (See https://github.com/antlr/antlr4/issues/3708 and/or https://stackoverflow.com/q/51584960)
find_package(Threads REQUIRED)
target_link_libraries(lsysantlr Threads::Threads)
target_link_libraries(lsysantlr antlr4_static)
target_link_libraries(lsysgen lsysantlr)
# target_link_libraries(lsysgen ${SYSTEM_LIBS})



# if (LSYSGEN_GRAPHICS)
#   add_executable(lsys2d ${lsysgen_2D_SRC})
#   target_link_libraries(lsys2d lsysgen)
#   target_link_libraries(lsys2d ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
# endif()

add_executable(lsys ${lsysgen_MAIN_SRC})
target_link_libraries(lsys lsysgen)

if(MSVC)
  target_compile_options(lsysgen PRIVATE /W4 /WX)
  target_compile_options(lsys PRIVATE /W4 /WX)
else()
  target_compile_options(lsysgen PRIVATE -Wall -Wextra -Wpedantic) # -Werror)
  target_compile_options(lsys PRIVATE -Wall -Wextra -Wpedantic) # -Werror)
endif()

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

