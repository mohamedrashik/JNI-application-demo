cmake_minimum_required(VERSION 3.22.1)

project("nativemath")

set(EIGEN_INCLUDE_DIR "/home/android-dev/aosp/external/eigen")
include_directories(${EIGEN_INCLUDE_DIR})
#configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config.h.in ${CMAKE_CURRENT_SOURCE_DIR}/include/config.h)

add_library(${CMAKE_PROJECT_NAME} SHARED
        nativemath.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME}
        android
        log)