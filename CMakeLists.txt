cmake_minimum_required(VERSION 3.5)
project(AcceleratedCpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp median.cpp Student_info.cpp grade.cpp)
add_executable(AcceleratedCpp ${SOURCE_FILES})