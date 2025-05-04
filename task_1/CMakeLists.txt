add_library(MyVector test_1.cpp MyVector.hpp)

target_include_directories(MyVector PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})