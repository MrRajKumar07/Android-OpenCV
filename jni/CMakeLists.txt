cmake_minimum_required(VERSION 3.10.2)
project(edgeviewer_native)

# Adjust the OpenCV_DIR path to point to the OpenCV SDK location in your repo or system.
# Example: ${CMAKE_SOURCE_DIR}/../opencv/sdk/native/jni
set(OpenCV_DIR "${CMAKE_SOURCE_DIR}/../opencv/sdk/native/jni")
find_package(OpenCV REQUIRED)

add_library(native-lib SHARED native-lib.cpp)

include_directories(${OpenCV_INCLUDE_DIRS})

target_link_libraries(native-lib ${OpenCV_LIBS} log)
