cmake_minimum_required(VERSION 3.8)
project(LeetCode CXX)

set(CMAKE_CXX_STANDARD_REQUIRED 17)
set(CMAKE_CXX_STANDARD 17)

set(CATCH_URL https://github.com/philsquared/Catch/releases/download/v2.0.0-develop.4/catch.hpp)
set(CATCH_MD5 005a3de453c100c48599a476127a402b)
file(DOWNLOAD ${CATCH_URL} ${CMAKE_SOURCE_DIR}/include/catch.hpp EXPECTED_HASH MD5=${CATCH_MD5})

include_directories(include)

file(GLOB SOURCES src/*.cpp)
add_executable(leetcode ${SOURCES})
