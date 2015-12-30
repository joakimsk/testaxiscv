cmake_minimum_required (VERSION 3.4.1)
project(axis_test_program)

add_subdirectory(axis_ptz)
add_subdirectory(axis_cv)

set(SOURCES src/main.cpp)

set(CMAKE_CXX_FLAGS "-std=c++11")

add_executable(axis_test_program ${SOURCES})

FIND_PACKAGE(CURL)
INCLUDE_DIRECTORIES(${CURL_INCLUDE_DIR})
FIND_PACKAGE(BOOST)
INCLUDE_DIRECTORIES(${BOOST_INCLUDE_DIR})
find_package( OpenCV REQUIRED )


#get_cmake_property(_variableNames VARIABLES)
#foreach (_variableName ${_variableNames})
#    message(STATUS "${_variableName}=${${_variableName}}")
#endforeach()

target_link_libraries(axis_test_program LINK_PUBLIC axis_ptz_lib axis_cv_lib ${CURL_LIBRARIES} ${BOOST_LIBRARIES} ${OpenCV_LIBS})