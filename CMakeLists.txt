cmake_minimum_required(VERSION 2.8)
project(ccollections)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(arraylist-test test/arraylist-test.c)

add_library(ccollections
    src/arraylist.c)

target_link_libraries(arraylist-test ccollections)
