cmake_minimum_required (VERSION 2.8.9)
project(axis_test_program)

include_directories(../axis_ptz)
include_directories(../axis_cv)

#set(SOURCES main.cpp ../axis_ptz/ptz.cpp ../axis_cv/cv.cpp)
file(GLOB SOURCES "src/*.cpp")

set(CMAKE_CXX_FLAGS "-std=c++11")
add_executable(axis_test_program ${SOURCES})
target_link_libraries(axis_test_program)
