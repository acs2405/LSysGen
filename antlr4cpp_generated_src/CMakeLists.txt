
# if(WIN32)
#   # Required java 11
#   set(Java_JAVA_EXECUTABLE java)
if(NOT WIN32)
  # set variable pointing to the antlr tool that supports C++
  # this is not required if the jar file can be found under PATH environment
  set(ANTLR_EXECUTABLE ${PROJECT_SOURCE_DIR}/antlr-4.12.0-complete.jar)
  # add macros to generate ANTLR Cpp code from grammar
  find_package(ANTLR)
endif()

# Grammar outputs:
set(ANTLR_LSysDLexer_OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/LSysDLexer)
set(ANTLR_LSysDParser_OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/LSysDParser)

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

# TODO: `make antlr` to build the grammar files
# add_custom_target(antlr # ALL 
#                   DEPENDS lsysantlr)

# Add sources to libraries:
target_sources(lsysantlr PRIVATE
  ${ANTLR_LSysDLexer_CXX_OUTPUTS} 
  ${ANTLR_LSysDParser_CXX_OUTPUTS}
  )

# Include directories:
target_include_directories(lsysantlr PUBLIC
  ${ANTLR4_INCLUDE_DIRS}
  )

# This lines prevent std::runtime_error with message "unknown error -1".
# (See https://github.com/antlr/antlr4/issues/3708 and/or https://stackoverflow.com/q/51584960)
find_package(Threads REQUIRED)
target_link_libraries(lsysantlr Threads::Threads)
# set(THREADS_PREFER_PTHREAD_FLAG ON)
target_link_libraries(lsysantlr antlr4_static)

# Export variables to parent:
set(ANTLR_LSysDLexer_OUTPUT_DIR ${ANTLR_LSysDLexer_OUTPUT_DIR} PARENT_SCOPE)
set(ANTLR_LSysDParser_OUTPUT_DIR ${ANTLR_LSysDParser_OUTPUT_DIR} PARENT_SCOPE)
