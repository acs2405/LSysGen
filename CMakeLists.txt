cmake_minimum_required(VERSION 3.7)

project("LSysGen")

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# using /MD flag for antlr4_runtime (for Visual C++ compilers only)
set(ANTLR4_WITH_STATIC_CRT OFF)

# required if linking to static library
# add_definitions(-DANTLR4CPP_STATIC)

# set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# # To use PKG_CHECK_MODULES to find some optional packages
# find_package(PkgConfig)


find_package(Boost REQUIRED)

include(ExternalAntlr4Cpp)

include_directories(${ANTLR4_INCLUDE_DIRS})

find_package(ANTLR)
if(ANTLR_FOUND)
  antlr_target(LSysDLexer LSysDLexer.g4 LEXER)
  antlr_target(LSysDParser LSysDParser.g4 PARSER
               DEPENDS_ANTLR LSysDLexer
               COMPILE_FLAGS -lib ${ANTLR_LSysDLexer_OUTPUT_DIR})

  # include generated files in project environment
  include_directories(${ANTLR_LSysDLexer_OUTPUT_DIR})
  include_directories(${ANTLR_LSysDParser_OUTPUT_DIR})
else()
  set(ANTLR_LSysDLexer_OUTPUT_DIR ${PROJECT_SOURCE_DIR}/antlr4-generated)
  set(ANTLR_LSysDParser_OUTPUT_DIR ${PROJECT_SOURCE_DIR}/antlr4-generated)

  set(ANTLR_LSysDLexer_CXX_OUTPUTS
    ${PROJECT_SOURCE_DIR}/antlr4-generated/LSysDLexer.cpp 
    )
  set(ANTLR_LSysDParser_CXX_OUTPUTS
    ${PROJECT_SOURCE_DIR}/antlr4-generated/LSysDParser.cpp
    ${PROJECT_SOURCE_DIR}/antlr4-generated/LSysDParserBaseVisitor.cpp   
    ${PROJECT_SOURCE_DIR}/antlr4-generated/LSysDParserVisitor.cpp
    )
endif()

# cmake_policy(SET CMP0072 NEW)
# find_package(OpenGL)
# find_package(GLUT)
# if(OpenGL_FOUND AND GLUT_FOUND)
#   # cmake_policy(SET CMP0072 NEW)

#   # find_package(OpenGL REQUIRED)
#   # find_package(GLUT REQUIRED)

#   # add_compile_definitions(LSYSGEN_WINDOW)
#   set(LSYSGEN_GRAPHICS True)

#   include_directories(${OPENGL_INCLUDE_DIRS})
#   include_directories(${GLUT_INCLUDE_DIRS})
# else()
#   # add_compile_definitions(LSYSGEN_JUST_PRINT)
#   # add_compile_definitions(LSYSGEN_INTERACTIVE)
#   set(LSYSGEN_GRAPHICS False)
# endif()

# Add CIMG Flags to Compilation Flags
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CIMG_CFLAGS}")

# CMake commands for this specific project start here

# to disable some warnings for CImg
if (NOT WIN32)
  set(CMAKE_CXX_FLAGS "-Wdeprecated -Wno-attributes" )
endif()

if (APPLE)
  set(CMAKE_CXX_FLAGS "-Wdeprecated -std=c++17" )
  include_directories(/usr/local/Cellar/boost/1.73.0/include)
endif()

if (MSVC)
  set(CMAKE_CXX_FLAGS "/EHsc /wd4127 /wd4311 /wd4312 /wd4512 /wd4571 /wd4640 /wd4706 /wd4710 /wd4800 /wd4804 /wd4820 /wd4996")
endif()

# Debug:
# SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Og")

# Optimized:
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")


foreach( src_file ${ANTLR_LSysDLexer_CXX_OUTPUTS} ${ANTLR_LSysDParser_CXX_OUTPUTS} )
      set_source_files_properties(
          ${src_file}
          PROPERTIES
          GENERATED TRUE
          )
endforeach( src_file ${ANTLR_LSysDLexer_CXX_OUTPUTS} ${ANTLR_LSysDParser_CXX_OUTPUTS} )

# set(ANTLR4_JAR "java -jar ${PROJECT_SOURCE_DIR}/antlr-4.8-complete.jar")

# add_custom_target(GenerateParser DEPENDS ${lsysgen_GENERATED_SRC})
# add_custom_command(OUTPUT ${lsysgen_GENERATED_SRC}
#     # COMMAND 
#     # ${CMAKE_COMMAND} -E make_directory ${PROJECT_SOURCE_DIR}/demo/generated/
#     COMMAND
#     # "${Java_JAVA_EXECUTABLE}" -jar ${ANTLR_JAR_LOCATION}
#     # -Werror
#     "${ANTLR4_JAR}" -o "${PROJECT_SOURCE_DIR}/antlr4-runtime/" "${PROJECT_SOURCE_DIR}/LSysDParser.g4" "${PROJECT_SOURCE_DIR}/LSysDLexer.g4" -Dlanguage=Cpp -no-listener -visitor
#     WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
#     DEPENDS ${PROJECT_SOURCE_DIR}/LSysDLexer.g4 ${PROJECT_SOURCE_DIR}/LSysDParser.g4
#     )


include_directories(
  ${PROJECT_SOURCE_DIR}/antlr4-generated/
  ${PROJECT_SOURCE_DIR}/src/
  ${PROJECT_SOURCE_DIR}/
  )

set(lsysgen_SRC_COMMON 
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
  )

# set(lsysgen_2D_SRC
#   ${PROJECT_SOURCE_DIR}/src/Drawer2D.cpp
#   )

set(lsysgen_JP_SRC
  ${PROJECT_SOURCE_DIR}/src/printer.cpp
  )

set(lsysgen_SVG_SRC
  ${PROJECT_SOURCE_DIR}/src/lsys2svg.cpp
  )

set(lsysgen_SRC ${lsysgen_SRC_COMMON} ${lsysgen_JP_SRC} ${lsysgen_SVG_SRC})



add_library(lsysgen SHARED 
  ${lsysgen_SRC_COMMON} 
  ${ANTLR_LSysDLexer_CXX_OUTPUTS} 
  ${ANTLR_LSysDParser_CXX_OUTPUTS}
  )

target_link_libraries(lsysgen antlr4_shared)
target_link_libraries(lsysgen ${SYSTEM_LIBS})



# if (LSYSGEN_GRAPHICS)
#   add_executable(lsys2d ${lsysgen_2D_SRC})
#   target_link_libraries(lsys2d lsysgen)
#   target_link_libraries(lsys2d ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
# endif()

add_executable(lsys ${lsysgen_JP_SRC})
target_link_libraries( lsys lsysgen )

add_executable(lsys2svg ${lsysgen_SVG_SRC})
target_link_libraries( lsys2svg lsysgen )


if (NOT CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
  set (flags_1 "-Wno-overloaded-virtual")
else()
  set (flags_1 "-MP /wd4251")
endif()

foreach( src_file ${lsysgen_SRC} )
      set_source_files_properties(
          ${src_file}
          PROPERTIES
          COMPILE_FLAGS "${COMPILE_FLAGS} ${flags_1}"
          )
endforeach( src_file ${lsysgen_SRC} )

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")  
  # see https://github.com/antlr/antlr4/issues/1874
  target_compile_options(lsysgen PUBLIC "$<$<CONFIG:DEBUG>:/MT>")
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
