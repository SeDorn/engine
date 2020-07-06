cmake_minimum_required(VERSION 3.16)
project(Test)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(TestRun ../math/Vector.cpp ../math/Vector.h TestVector.cpp)
target_link_libraries(TestRun gtest gtest_main)