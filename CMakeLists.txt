cmake_minimum_required(VERSION 4.4)
project(LeetCode CXX)

find_package(doctest       2  REQUIRED)
find_package(fmt           12 REQUIRED)
find_package(nlohmann_json 3  REQUIRED)

add_library(compile-options INTERFACE)

target_compile_features(compile-options INTERFACE cxx_std_23)

target_include_directories(
  compile-options INTERFACE
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
)

target_link_libraries(
  compile-options INTERFACE
    doctest::doctest
    fmt::fmt
    nlohmann_json::nlohmann_json
)

# LeetCode Supports
add_library(leetcode OBJECT src/leetcode/tree-node.cpp)

target_link_libraries(leetcode PUBLIC compile-options)

# Doctest main
add_library(doctest-main OBJECT test/doctest-main.cpp)

target_link_libraries(doctest-main PUBLIC compile-options doctest::doctest)

add_subdirectory(solutions)

add_executable(leetcode-solutions
  $<TARGET_OBJECTS:solution-objs>
  $<TARGET_OBJECTS:doctest-main>
  $<TARGET_OBJECTS:leetcode>
)

# Enable testing
enable_testing()

add_test(NAME leetcode-solutions COMMAND leetcode-solutions)