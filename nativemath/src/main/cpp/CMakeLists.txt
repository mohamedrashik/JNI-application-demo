cmake_minimum_required(VERSION 3.22.1)

project("nativemath")

add_library(${CMAKE_PROJECT_NAME} SHARED
        nativemath.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME}
        android
        log)