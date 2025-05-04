cmake_minimum_required(VERSION 3.10)

project(lab_4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCE_FILES main.cpp src/move.cpp) #учусь использовать переменные

add_executable(lab_4_test ${SOURCE_FILES})