# Toolchain file to compile Windows 64-bit binaries in Linux with MinGW-64
# To use this file:
# cmake -DCMAKE_TOOLCHAIN_FILE=cmake/x86_64-w64-mingw32.cmake ..

# the name of the target operating system
set(CMAKE_SYSTEM_NAME Windows)
# set(CMAKE_SYSTEM_VERSION 1)
set(CMAKE_SYSTEM_PROCESSOR x86_64)
set(TOOLCHAIN_PREFIX x86_64-w64-mingw32) # for win64, mingw-64
# set(TOOLCHAIN_PREFIX amd64-w64-mingw32) # for win64, mingw-64
# Requires mingw-w64 package

# which compilers to use for C and C++
set(CMAKE_C_COMPILER   ${TOOLCHAIN_PREFIX}-gcc-posix)
set(CMAKE_CXX_COMPILER ${TOOLCHAIN_PREFIX}-g++-posix)

# where is the target environment located
set(CMAKE_FIND_ROOT_PATH  /usr/${TOOLCHAIN_PREFIX})

# adjust the default behavior of the FIND_XXX() commands:
# search programs in the host environment
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)

# search headers, libraries and packages in the target environment
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
