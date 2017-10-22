cmake_minimum_required(VERSION 2.8)
project(ccollections)

# Set prefix
#set(prefix $ENV{HOME}/dev/usr)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(arraylist-test test/arraylist-test.c)
add_executable(array-test test/array-test.c)

add_library(ccollections
  src/arraylist.c
  src/array.c)

target_link_libraries(arraylist-test ccollections)
target_link_libraries(array-test ccollections)
# Install in local creations
install(TARGETS ccollections DESTINATION ${prefix}/lib)
install(
    FILES
        src/ccollections.h
        src/arraylist.h
    DESTINATION
        ${prefix}/include)
