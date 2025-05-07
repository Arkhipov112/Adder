cmake_minimum_required(VERSION 3.30.4)

set(CMAKE_CXX_STANDARD 14)

project(Adder)

add_subdirectory(
    googletest
)

add_library(
    parser
    parser/parser.cpp
    parser/parser.hpp
)

add_library(
    adder
    adder/adder.cpp
    adder/adder.hpp
)

add_executable(
    AdderTest
    test/test.cpp
)

target_link_libraries(
    AdderTest
    gtest
    gtest_main
    adder
    parser
)