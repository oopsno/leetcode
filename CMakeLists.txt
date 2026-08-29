cmake_minimum_required(VERSION 3.8)
project(LeetCode CXX)

# Using {fmt}
find_package(fmt 7 REQUIRED)

# Using C++20
set(CMAKE_CXX_STANDARD_REQUIRED 20)
set(CMAKE_CXX_STANDARD 20)

# Including custom headers
include_directories(include)

# LeetCode Supports
add_library(leetcode src/leetcode.cpp include/leetcode.hpp)

# Enable testing
enable_testing()

# Add all solutions
macro(add_solution NAME SOURCE)
  list(APPEND SOLUTIONS ${SOURCE})
  add_executable(${NAME} ${SOURCE})
  target_link_libraries(${NAME} leetcode fmt)
  # add_test(${NAME} ${NAME})
endmacro(add_solution)

include(cmake/solutions.cmake)

add_executable(all-unittests "${SOLUTIONS}")
target_link_libraries(all-unittests gtest-main leetcode)

add_executable(leetcode-unittest test/gtest-main.cpp test/leetcode.cpp)
target_link_libraries(leetcode-unittest leetcode)