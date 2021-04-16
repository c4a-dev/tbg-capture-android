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
        android_camera.c
)

# Link the library
find_library(log-lib log)
find_library(android-lib android)
message(STATUS "CONAN_LIBS=${CONAN_LIBS}")
target_link_libraries(tbg-capture
        ${android-lib}
        ${log-lib}
        ${CONAN_LIBS}
        /Users/mtownsend/work/c4a/tbg-capture-android/gstreamer/gst-build-arm64-v8a/libgstreamer_android.so
)