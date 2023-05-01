# Toolchain file to compile Linux 32-bit binaries in Linux (64 bits)
# To use this file:
# cmake -DCMAKE_TOOLCHAIN_FILE=cmake/i686-linux-gnu.cmake ..

# the name of the target operating system
set(CMAKE_SYSTEM_NAME Linux)
# set(CMAKE_SYSTEM_VERSION 1)
set(CMAKE_SYSTEM_PROCESSOR i686)
set(TOOLCHAIN_PREFIX i686-linux-gnu) # for linux32
# Requires g++-i686-linux-gnu package

# which compilers to use for C and C++
set(CMAKE_C_COMPILER   gcc)
set(CMAKE_C_FLAGS -m32)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS -m32)

# where is the target environment located
set(CMAKE_FIND_ROOT_PATH  /usr/${TOOLCHAIN_PREFIX})

# adjust the default behavior of the FIND_XXX() commands:
# search programs in the host environment
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)

# search headers, libraries and packages in the target environment
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
