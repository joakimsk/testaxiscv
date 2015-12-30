cmake_minimum_required (VERSION 2.6)
project(axis_test_program)

include_directories(../axis_ptz)
include_directories(../axis_cv)

set(CMAKE_CXX_FLAGS "-std=c++11")
add_executable(axis_test_program main.cpp)
target_link_libraries(axis_test_program)