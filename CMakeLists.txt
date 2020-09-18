cmake_minimum_required(VERSION 2.8)

project("LSysGen")

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# # CMake commands copied by the CMake file for CImg

# # To use PKG_CHECK_MODULES to find some optional packages
# find_package(PkgConfig)

# # ### CIMG related stuff
# # Flags to enable fast image display, using the XSHM library.
# SET(CIMG_XSHM_CCFLAGS  -Dcimg_use_xshm)

# # Flags to enable screen mode switching, using the XRandr library.
# SET(CIMG_XRANDR_CCFLAGS  -Dcimg_use_xrandr)

# # Flags to enable native support for JPEG image files, using the JPEG library.
# # ( http://www.ijg.org/ )
# SET(CIMG_JPEG_CCFLAGS  -Dcimg_use_jpeg)

# # Flags to enable native support for TIFF image files, using the TIFF library.
# # ( http://www.libtiff.org/ )
# SET(CIMG_TIFF_CCFLAGS  -Dcimg_use_tiff)

# # Flags to enable native support for PNG image files, using the PNG library.
# # ( http://www.libpng.org/ )
# SET(CIMG_PNG_CCFLAGS  -Dcimg_use_png)

# #Flags to enable OPENCV support (Camera)
# # ( http://www.opencv.org/ )
# SET(CIMG_OPENCV_CCFLAGS-Dcimg_use_opencv)

# # Flags to enable native support for EXR image files, using the OpenEXR library.
# # ( http://www.openexr.com/ )
# SET(CIMG_OPENEXR_CCFLAGS  -Dcimg_use_openexr)

# # Flags to enable native support for various video files, using the FFMPEG library.
# # ( http://www.ffmpeg.org/ )
# SET(CIMG_FFMPEG_CCFLAGS  -Dcimg_use_ffmpeg)

# # Flags to enable native support of most classical image file formats, using the Magick++ library.
# # ( http://www.imagemagick.org/Magick++/ )
# SET(CIMG_MAGICK_CCFLAGS -Dcimg_use_magick)

# # Flags to enable faster Discrete Fourier Transform computation, using the FFTW3 library
# # ( http://www.fftw.org/ )
# SET(CIMG_FFTW3_CCFLAGS  -Dcimg_use_fftw3)

# # ### Search Additional Libraries ##########
# FIND_PACKAGE(OpenCV)
# FIND_PACKAGE(JPEG)
# FIND_PACKAGE(TIFF)
# FIND_PACKAGE(PNG)
# FIND_PACKAGE(ZLIB)
# FIND_PACKAGE(LAPACK)
# FIND_PACKAGE(BLAS)

# PKG_CHECK_MODULES(FFTW3 fftw3)
# PKG_CHECK_MODULES(OPENEXR OpenEXR)
# PKG_CHECK_MODULES(MAGICK Magick++)

# if(NOT WIN32)
#   FIND_PACKAGE(X11)
#   FIND_PACKAGE(Threads REQUIRED)
# endif()

# # #### End of additional libraries search ##########


# ### Configure Paths according to detected packages
# if(TIFF_FOUND)
#   get_filename_component(TIFF_LIB_DIRS ${TIFF_LIBRARIES} PATH)
#   SET(CIMG_CFLAGS "${CIMG_CFLAGS} ${CIMG_TIFF_CCFLAGS}")
#   link_directories(${TIFF_LIB_DIRS})
#   include_directories(${TIFF_INCLUDE_DIR})
#   SET(SYSTEM_LIBS ${SYSTEM_LIBS} ${TIFF_LIBRARIES})
# endif()

# if(JPEG_FOUND)
#   get_filename_component(JPEG_LIB_DIRS ${JPEG_LIBRARIES} PATH)
#   SET(CIMG_CFLAGS "${CIMG_CFLAGS} ${CIMG_JPEG_CCFLAGS}")
#   link_directories(${JPEG_LIB_DIRS})
#   include_directories(${JPEG_INCLUDE_DIR})
#   SET(SYSTEM_LIBS ${SYSTEM_LIBS} ${JPEG_LIBRARIES})
# endif()

# if (ZLIB_FOUND)
#   SET(CIMG_CFLAGS "${CIMG_CFLAGS} ${CIMG_ZLIB_CCFLAGS}")
#   link_directories(${ZLIB_LIB_DIRS})
#   include_directories(${ZLIB_INCLUDE_DIR})
#   SET(SYSTEM_LIBS ${SYSTEM_LIBS} ${ZLIB_LIBRARIES})

#   # PNG requires ZLIB
#   if(PNG_FOUND)
#     SET(CIMG_CFLAGS "${CIMG_CFLAGS} ${CIMG_PNG_CCFLAGS}")
#     link_directories(${PNG_LIB_DIRS})
#     include_directories(${PNG_INCLUDE_DIR} )
#     SET( SYSTEM_LIBS ${SYSTEM_LIBS} ${PNG_LIBRARIES} )
#   endif()
# endif()

# if(FFTW3_FOUND)
#   SET(CIMG_CFLAGS "${CIMG_CFLAGS} ${CIMG_FFTW3_CCFLAGS}")
#   link_directories( ${FFTW3_LIBRARY_DIRS} )
#   include_directories( ${FFTW3_INCLUDE_DIRS} )
#   SET( SYSTEM_LIBS ${SYSTEM_LIBS} ${FFTW3_LIBRARIES} )
# endif()

# if(OPENEXR_FOUND)
#   SET(CIMG_CFLAGS "${CIMG_CFLAGS} ${CIMG_OPENEXR_CCFLAGS}")
#   link_directories( ${OPENEXR_LIBRARY_DIRS} )
#   include_directories( ${OPENEXR_INCLUDE_DIRS} )
#   SET( SYSTEM_LIBS ${SYSTEM_LIBS} ${OPENEXR_LIBRARIES} )
# endif()

# if(MAGICK_FOUND)
#   SET(CIMG_CFLAGS "${CIMG_CFLAGS} ${CIMG_MAGICK_CCFLAGS}")
#   link_directories( ${MAGICK_LIBRARY_DIRS} )
#   include_directories( ${MAGICK_INCLUDE_DIRS} )
#   SET( SYSTEM_LIBS ${SYSTEM_LIBS} ${MAGICK_LIBRARIES} )
# endif()

# if( LIBAVCODEC_FOUND  AND LIBAVFORMAT_FOUND AND LIBSWSCALE_FOUND AND LIBAVUTIL_FOUND )
#   SET(CIMG_CFLAGS "${CIMG_CFLAGS} ${CIMG_FFMPEG_CCFLAGS}")
#   link_directories( ${LIBAVFORMAT_LIBRARY_DIRS} )
#   link_directories( ${LIBAVCODEC_LIBRARY_DIRS} )
#   link_directories( ${LIBSWSCALE_LIBRARY_DIRS} )
#   link_directories( ${LIBAVUTIL_LIBRARY_DIRS} )
#   include_directories( ${LIBAVFORMAT_INCLUDE_DIRS} ${LIBAVFORMAT_INCLUDE_DIRS}/libavformat)
#   include_directories( ${LIBAVCODEC_INCLUDE_DIRS} ${LIBAVCODEC_INCLUDE_DIRS}/libavcodec )
#   include_directories( ${LIBSWSCALE_INCLUDE_DIRS} ${LIBSWSCALE_INCLUDE_DIRS}/libswscale)
#   include_directories( ${LIBAVUTIL_INCLUDE_DIRS} ${LIBAVUTIL_INCLUDE_DIRS}/libavutil )
#   SET( SYSTEM_LIBS ${SYSTEM_LIBS} ${LIBAVFORMAT_LIBRARIES} )
#   SET( SYSTEM_LIBS ${SYSTEM_LIBS} ${LIBAVCODEC_LIBRARIES} )
#   SET( SYSTEM_LIBS ${SYSTEM_LIBS} ${LIBSWSCALE_LIBRARIES} )
#   SET( SYSTEM_LIBS ${SYSTEM_LIBS} ${LIBAVUTIL_LIBRARIES} )
# endif()

# if(NOT APPLE)
#   if(NOT WIN32)
#     if(X11_FOUND)
#       SET(CIMG_CFLAGS "${CIMG_CFLAGS} ${CIMG_XSHM_CCFLAGS} ${CIMG_XRANDR_CCFLAGS}")
#       SET(SYSTEM_LIBS ${SYSTEM_LIBS} Xext Xrandr)
#     endif()
#   endif(NOT WIN32)
# endif(NOT APPLE)

# if(X11_FOUND)
#   link_directories(${X11_LIB_DIRS})
#   include_directories(${X11_INCLUDE_DIR})
#   SET( SYSTEM_LIBS ${SYSTEM_LIBS} ${X11_LIBRARIES} )
# endif()

# if (NOT WIN32)
#   SET( SYSTEM_LIBS ${SYSTEM_LIBS} ${CMAKE_THREAD_LIBS_INIT} )
# endif()

# if( WIN32)
#   SET( SYSTEM_LIBS  ${SYSTEM_LIBS}  gdi32 )
# endif()

# if (OpenCV_FOUND)
#   message("OpenCV Found")
#   SET(CIMG_CFLAGS "${CIMG_CFLAGS} ${CIMG_OPENCV_CCFLAGS}")
#   include_directories(${OpenCV_INCLUDE_DIRS})
#   link_directories(${OpenCV_LIB_DIRS})
#   SET( SYSTEM_LIBS  ${SYSTEM_LIBS}  ${OpenCV_LIBS} )
# endif()

# if(LAPACK_FOUND)
#   SET(CIMG_CFLAGS "${CIMG_CFLAGS} ${CIMG_LAPACK_CCFLAGS}")
#   link_directories( ${LAPACK_LIBRARY_DIRS} )
#   include_directories( ${LAPACK_INCLUDE_DIRS} )
#   SET( SYSTEM_LIBS ${SYSTEM_LIBS} ${LAPACK_LIBRARIES} )
# endif()

# if(BLAS_FOUND)
#   SET(CIMG_CFLAGS "${CIMG_CFLAGS} ${CIMG_BLAS_CCFLAGS}")
#   link_directories( ${BLAS_LIBRARY_DIRS} )
#   include_directories( ${BLAS_INCLUDE_DIRS} )
#   SET( SYSTEM_LIBS ${SYSTEM_LIBS} ${BLAS_LIBRARIES} )
# endif()


find_package(Boost REQUIRED)

cmake_policy(SET CMP0072 NEW)
find_package(OpenGL)
find_package(GLUT)
if(OpenGL_FOUND AND GLUT_FOUND)
  # cmake_policy(SET CMP0072 NEW)

  # find_package(OpenGL REQUIRED)
  # find_package(GLUT REQUIRED)

  # add_compile_definitions(LSYSGEN_WINDOW)
  set(LSYSGEN_GRAPHICS True)
else()
  # add_compile_definitions(LSYSGEN_JUST_PRINT)
  # add_compile_definitions(LSYSGEN_INTERACTIVE)
  set(LSYSGEN_GRAPHICS False)
endif()

# add_subdirectory(antlr-runtime)

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
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Og")

# Optimized:
# SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")


set(lsysgen_GENERATED_SRC
  ${PROJECT_SOURCE_DIR}/antlr4-runtime/LSysDLexer.cpp 
  ${PROJECT_SOURCE_DIR}/antlr4-runtime/LSysDParser.cpp
  ${PROJECT_SOURCE_DIR}/antlr4-runtime/LSysDParserBaseVisitor.cpp   
  ${PROJECT_SOURCE_DIR}/antlr4-runtime/LSysDParserVisitor.cpp
 )

foreach( src_file ${lsysgen_GENERATED_SRC} )
      set_source_files_properties(
          ${src_file}
          PROPERTIES
          GENERATED TRUE
          )
endforeach( src_file ${lsysgen_GENERATED_SRC} )

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
  ${OPENGL_INCLUDE_DIRS}
  ${GLUT_INCLUDE_DIRS}
  ${PROJECT_SOURCE_DIR}/antlr4-runtime/
  ${PROJECT_SOURCE_DIR}/antlr4-runtime/misc
  ${PROJECT_SOURCE_DIR}/antlr4-runtime/atn
  ${PROJECT_SOURCE_DIR}/antlr4-runtime/dfa
  ${PROJECT_SOURCE_DIR}/antlr4-runtime/tree
  ${PROJECT_SOURCE_DIR}/antlr4-runtime/support
  ${PROJECT_SOURCE_DIR}/src/
  ${PROJECT_SOURCE_DIR}/
  ${PROJECT_SOURCE_DIR}/libs/
  )

set(lsysgen_SRC_COMMON 
  ${PROJECT_SOURCE_DIR}/src/misc.cpp
  ${PROJECT_SOURCE_DIR}/src/operations.cpp
  ${PROJECT_SOURCE_DIR}/src/ParseTreeNode.cpp
  ${PROJECT_SOURCE_DIR}/src/NodeContent.cpp
  ${PROJECT_SOURCE_DIR}/src/Rule.cpp
  ${PROJECT_SOURCE_DIR}/src/Table.cpp
  ${PROJECT_SOURCE_DIR}/src/LSystem.cpp
  ${PROJECT_SOURCE_DIR}/src/ErrorHandler.cpp
  ${PROJECT_SOURCE_DIR}/src/LSysDVisitor.cpp
  ${PROJECT_SOURCE_DIR}/src/LSysDExpressionEvaluator.cpp
  ${PROJECT_SOURCE_DIR}/src/lsysgen.cpp
  ${lsysgen_GENERATED_SRC}
  )

set(lsysgen_2D_SRC
  ${PROJECT_SOURCE_DIR}/src/Drawer2D.cpp
  )

set(lsysgen_JP_SRC
  ${PROJECT_SOURCE_DIR}/src/Printer.cpp
  )

set(lsysgen_SRC ${lsysgen_SRC_COMMON} ${lsysgen_2D_SRC} ${lsysgen_JP_SRC})

# set(lsysgen_RESOURCES 
#   ${PROJECT_SOURCE_DIR}/b2.lsd
#   ${PROJECT_SOURCE_DIR}/penrose.lsd
#   ${PROJECT_SOURCE_DIR}/star.lsd
#   )

link_directories(
  # ${PROJECT_SOURCE_DIR}/test2
  ${PROJECT_SOURCE_DIR}/libs
  )

# add_executable( ${PROJECT_NAME} ${lsysgen_SRC} )
# add_library( ${PROJECT_NAME} ${lsysgen_SRC}/libs )

# add_subdirectory(${PROJECT_SOURCE_DIR}/libs)

# target_link_libraries( lsysgen ${PROJECT_NAME} )


add_library(lsysgen SHARED ${lsysgen_SRC_COMMON})

# set_property(TARGET lsysgen PROPERTY POSITION_INDEPENDENT_CODE ON)

if (LSYSGEN_GRAPHICS)
  add_executable(lsys2d ${lsysgen_2D_SRC})
  target_link_libraries(lsys2d lsysgen)

  target_link_libraries(lsys2d ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
endif()

add_executable(lsys ${lsysgen_JP_SRC})
target_link_libraries( lsys lsysgen )


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

if(WIN32)
  target_link_libraries(lsysgen "${PROJECT_SOURCE_DIR}/libs/antlr4-runtime.dll")
  # target_link_libraries(lsysgen "${PROJECT_SOURCE_DIR}/antlr-runtime-src/run/usr/local/lib/libantlr4-runtime.lib")
endif()

if(APPLE)
  target_link_libraries(lsysgen "${PROJECT_SOURCE_DIR}/libs/libantlr4-runtime.dylib")
  # target_link_libraries(lsysgen "${PROJECT_SOURCE_DIR}/antlr-runtime-src/run/usr/local/lib/libantlr4-runtime.dylib")
elseif(UNIX)
  target_link_libraries(lsysgen "${PROJECT_SOURCE_DIR}/libs/libantlr4-runtime.so")
  # target_link_libraries(lsysgen "${PROJECT_SOURCE_DIR}/antlr-runtime-src/run/usr/local/lib/libantlr4-runtime.so")
endif()

target_link_libraries(lsysgen ${SYSTEM_LIBS})

# if(CMAKE_SYSTEM_NAME MATCHES "Linux")
# add_custom_command(TARGET lsysgen POST_BUILD
#   COMMAND ${CMAKE_COMMAND} -E copy_if_different
#   "${PROJECT_SOURCE_DIR}/libs/libantlr4-runtime.so"
#   $<TARGET_FILE_DIR:lsysgen>)
# endif()

# if(WIN32)
# add_custom_command(TARGET lsysgen POST_BUILD
#   COMMAND ${CMAKE_COMMAND} -E copy_if_different
#   "${PROJECT_SOURCE_DIR}/libs/libantlr4-runtime.dll"
#   $<TARGET_FILE_DIR:lsysgen>)
# endif()

# if(APPLE)
# add_custom_command(TARGET lsysgen POST_BUILD
#   COMMAND ${CMAKE_COMMAND} -E copy_if_different
#   # "${PROJECT_SOURCE_DIR}/libs/antlr4-runtime.dylib"
#   "${PROJECT_SOURCE_DIR}/libs/libantlr4-runtime.dylib"
#   $<TARGET_FILE_DIR:lsysgen>)
# endif()

# # copy the input file next to the generated executable
# add_custom_command(TARGET lsysgen POST_BUILD
#   COMMAND ${CMAKE_COMMAND} -E copy_if_different
#   "${PROJECT_SOURCE_DIR}/b2.lsd"
#   $<TARGET_FILE_DIR:lsysgen>)

# # copy the input file next to the generated executable
# foreach( resource_file ${lsysgen_RESOURCES} )
#       add_custom_command(TARGET lsysgen POST_BUILD
#         COMMAND ${CMAKE_COMMAND} -E copy_if_different
#         ${resource_file}
#         $<TARGET_FILE_DIR:lsysgen>)
# endforeach( resource_file ${lsysgen_RESOURCES} )

# necessary because the default working directory of Visual Studio
# is not the same as the one in which the binary is created
# so we copy the input file twice:
# one for when you launch the executale in Visual Studio (CTRL+F5)
# one for when you launch it normally

# # copy the input file next to the generated executable
# if (WIN32)
# foreach( resource_file ${lsysgen_RESOURCES} )
#       add_custom_command(TARGET lsysgen POST_BUILD
#         COMMAND ${CMAKE_COMMAND} -E copy_if_different
#         "${PROJECT_SOURCE_DIR}/b2.lsd"
#         $<TARGET_FILE_DIR:lsysgen>/../)
# endforeach( resource_file ${lsysgen_RESOURCES} )
# endif()
