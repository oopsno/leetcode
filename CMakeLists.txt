cmake_minimum_required(VERSION 3.3)
project(leetcode_cxx)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-DOFFLINE")
include_directories(include src)

file(GLOB all_libs    lib/leet/*.cpp)
file(GLOB all_tests   test/*.cpp)

add_library(leet ${all_libs})

add_executable(leetcode_unittest ${all_tests})
add_executable(leet_unittest lib/test/leet.cpp test/main.cpp)
target_link_libraries(leet_unittest     gtest leet)
target_link_libraries(leetcode_unittest gtest leet)

