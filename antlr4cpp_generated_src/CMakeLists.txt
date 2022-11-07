
# if(WIN32)
#   # Required java 11
#   set(Java_JAVA_EXECUTABLE java)
if(NOT WIN32)
  # set variable pointing to the antlr tool that supports C++
  # this is not required if the jar file can be found under PATH environment
  set(ANTLR_EXECUTABLE ${PROJECT_SOURCE_DIR}/antlr-4.11.1-complete.jar)
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

# Export variables to parent:
set(ANTLR_LSysDLexer_OUTPUT_DIR ${ANTLR_LSysDLexer_OUTPUT_DIR} PARENT_SCOPE)
set(ANTLR_LSysDParser_OUTPUT_DIR ${ANTLR_LSysDParser_OUTPUT_DIR} PARENT_SCOPE)
set(ANTLR_LSysDLexer_CXX_OUTPUTS ${ANTLR_LSysDLexer_CXX_OUTPUTS} PARENT_SCOPE)
set(ANTLR_LSysDParser_CXX_OUTPUTS ${ANTLR_LSysDParser_CXX_OUTPUTS} PARENT_SCOPE)
