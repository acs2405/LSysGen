
# Set this project's header files:
# file (GLOB lsysgen_HEADERS ${PROJECT_SOURCE_DIR}/src/*.h)
set(lsysgen_BASE_HEADERS
  ${PROJECT_SOURCE_DIR}/src/misc.h
  ${PROJECT_SOURCE_DIR}/src/values.h
  ${PROJECT_SOURCE_DIR}/src/operations.h
  ${PROJECT_SOURCE_DIR}/src/TreeNode.h
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

# Set this project's source files:
set(lsysgen_BASE_SRC 
  ${PROJECT_SOURCE_DIR}/src/misc.cpp
  ${PROJECT_SOURCE_DIR}/src/values.cpp
  ${PROJECT_SOURCE_DIR}/src/operations.cpp
  ${PROJECT_SOURCE_DIR}/src/TreeNode.cpp
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

set(lsysgen_MAIN_SRC
  ${PROJECT_SOURCE_DIR}/src/cli.cpp
  )

# set(lsysgen_2D_SRC
#   ${PROJECT_SOURCE_DIR}/src/Drawer2D.cpp
#   )

# Add sources to targets:
target_sources(lsysgen PRIVATE
  ${lsysgen_BASE_SRC} 
  )

target_sources(lsys PRIVATE
  ${lsysgen_MAIN_SRC}
  )

# Include directories:
target_include_directories(lsysgen PUBLIC
  ${PROJECT_SOURCE_DIR}/src/
  ${ANTLR_LSysDLexer_OUTPUT_DIR}
  ${ANTLR_LSysDParser_OUTPUT_DIR}
  )
target_include_directories(lsys PUBLIC
  ${PROJECT_SOURCE_DIR}/src/
  )

# Precompile headers:
target_precompile_headers(lsysgen PRIVATE
  ${PROJECT_SOURCE_DIR}/src/common.h
  # ${PROJECT_SOURCE_DIR}/src/misc.h
  # ${lsysgen_BASE_HEADERS}
  )

# Link the project libraries:
target_link_libraries(lsysgen lsysantlr)
target_link_libraries(lsys lsysgen)

# if (LSYSGEN_GRAPHICS)
#   add_executable(lsys2d ${lsysgen_2D_SRC})
#   target_link_libraries(lsys2d lsysgen)
#   target_link_libraries(lsys2d ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
# endif()

# Show compilation warnings:
if(MSVC)
  target_compile_options(lsysgen PRIVATE /W4) # /WX)
  target_compile_options(lsys PRIVATE /W4) # /WX)
else()
  target_compile_options(lsysgen PRIVATE -Wall -Wextra -Wpedantic) # -Werror)
  target_compile_options(lsys PRIVATE -Wall -Wextra -Wpedantic) # -Werror)
endif()

# Set precompiler macros:
set(lsysgen_COMPILE_DEFS
  LSYSGEN_VERSION="${LSysGen_VERSION}"
  )

target_compile_definitions(lsysgen PUBLIC ${lsysgen_COMPILE_DEFS})
target_compile_definitions(lsys PUBLIC ${lsysgen_COMPILE_DEFS})

# When working with OpenGL:
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

# Export variables to parent:
set(lsysgen_BASE_HEADERS ${lsysgen_BASE_HEADERS} PARENT_SCOPE)
