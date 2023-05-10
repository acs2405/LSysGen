
# Set this project's header files:
# file (GLOB lsysgen_HEADERS ${PROJECT_SOURCE_DIR}/src/*.h)

# Set this project's source files:
set(lsysgen_BASE_SRC
  ${PROJECT_SOURCE_DIR}/src/common/misc.cpp
  ${PROJECT_SOURCE_DIR}/src/common/runtime/values.cpp
  ${PROJECT_SOURCE_DIR}/src/common/runtime/operations.cpp
  ${PROJECT_SOURCE_DIR}/src/common/core/TreeNode.cpp
  ${PROJECT_SOURCE_DIR}/src/common/core/NodeContent.cpp
  ${PROJECT_SOURCE_DIR}/src/deriving/Rule.cpp
  ${PROJECT_SOURCE_DIR}/src/deriving/Table.cpp
  ${PROJECT_SOURCE_DIR}/src/deriving/Derivator.cpp
  ${PROJECT_SOURCE_DIR}/src/common/core/LSystem.cpp
  ${PROJECT_SOURCE_DIR}/src/common/core/Module.cpp
  ${PROJECT_SOURCE_DIR}/src/common/ErrorHandler.cpp
  ${PROJECT_SOURCE_DIR}/src/frontend/LSysDVisitor.cpp
  ${PROJECT_SOURCE_DIR}/src/frontend/LSysDExpressionEvaluator.cpp
  ${PROJECT_SOURCE_DIR}/src/lib/lsysgen.cpp
  ${PROJECT_SOURCE_DIR}/src/backend/interpreter2D.cpp
  ${PROJECT_SOURCE_DIR}/src/common/Settings.cpp
  ${PROJECT_SOURCE_DIR}/src/cli/cliargs.cpp
  )

set(lsysgen_MAIN_SRC
  ${PROJECT_SOURCE_DIR}/src/cli/cli.cpp
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
  ${PROJECT_SOURCE_DIR}/src/common/
  ${PROJECT_SOURCE_DIR}/src/common/core/
  ${PROJECT_SOURCE_DIR}/src/common/runtime/
  ${PROJECT_SOURCE_DIR}/src/frontend/
  ${PROJECT_SOURCE_DIR}/src/deriving/
  ${PROJECT_SOURCE_DIR}/src/backend/
  ${PROJECT_SOURCE_DIR}/src/lib/
  ${PROJECT_SOURCE_DIR}/src/cli/
  ${ANTLR_LSysDLexer_OUTPUT_DIR}
  ${ANTLR_LSysDParser_OUTPUT_DIR}
  )
target_include_directories(lsys PUBLIC
  ${PROJECT_SOURCE_DIR}/src/
  )

# Precompile headers:
target_precompile_headers(lsysgen PRIVATE
  ${PROJECT_SOURCE_DIR}/src/common/common.h
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
