cmake_minimum_required(VERSION 3.18)

set(This first_try)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)

add_subdirectory(median_structs)

set(MEDIAN_STRUCTURES_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/median_structs)
include_directories(${MEDIAN_STRUCTURES_INCLUDE_DIR})


add_subdirectory(tests)
