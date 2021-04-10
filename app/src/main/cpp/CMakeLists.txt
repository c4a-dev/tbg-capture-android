# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.10.2)

# Declares and names the project.

project("tbg-capture")

# Conan setup
set(PROJECT_ROOT ${CMAKE_CURRENT_LIST_DIR})
add_definitions(-DPROJECT_ROOT="${PROJECT_ROOT}/")
set(CONAN_SYSTEM_INCLUDES 1)
include(${CMAKE_CURRENT_SOURCE_DIR}/../../../build/conan/conanbuildinfo.cmake)
conan_basic_setup()
message(STATUS "CONAN_LIBS=${CONAN_LIBS}")

# Add the library
add_library(tbg-capture
        SHARED
        native-lib.cpp
)

# Link the library
find_library(log-lib log)
target_link_libraries(tbg-capture
        ${log-lib}
        ${CONAN_LIBS}
)