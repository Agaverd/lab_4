add_library(MyArray test_3.cpp MyArray.hpp)

target_include_directories(MyArray PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})