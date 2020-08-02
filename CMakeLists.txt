cmake_minimum_required(VERSION 3.14)

set(PROJECT_NAME engine)
project(${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "-g -Wall")
set(CMAKE_CXX_STANDARD 11)

file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/math/*.cpp ${PROJECT_SOURCE_DIR}/logger/*.cpp)
list(REMOVE_ITEM SRC_FILES ${PROJECT_SOURCE_DIR}/main.cpp)

add_library(engine_lib ${SRC_FILES})
add_executable(engine ${PROJECT_SOURCE_DIR}/main.cpp)
target_link_libraries(engine engine_lib)

add_subdirectory(./googletest)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/TestVector.cpp ${PROJECT_SOURCE_DIR}/test/TestMatrix.cpp)

add_executable(runUnitTests ${TEST_SRC_FILES})
target_link_libraries(runUnitTests gtest gtest_main)
target_link_libraries(runUnitTests engine_lib)
add_test(UnitTests runUnitTests)