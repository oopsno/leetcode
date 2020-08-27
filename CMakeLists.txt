cmake_minimum_required(VERSION 3.8)
project(LeetCode CXX)

# Using Google Test
find_package(GTest 1.8 REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})
link_libraries(${GTEST_LIBRARIES})

# Using C++17
set(CMAKE_CXX_STANDARD_REQUIRED 17)
set(CMAKE_CXX_STANDARD 17)

# Including custom headers
include_directories(include)

# Main function for GTEST
add_library(gtest-main test/gtest-main.cpp)

# LeetCode Supports
add_library(leetcode src/leetcode.cpp include/leetcode.hpp)

# Enable testing
enable_testing()

# Add all solutions
macro(add_solution NAME SOURCE)
  list(APPEND SOLUTIONS ${SOURCE})
  add_executable(${NAME} ${SOURCE})
  target_link_libraries(${NAME} gtest-main leetcode)
  add_test(${NAME} ${NAME})
endmacro(add_solution)

add_solution(0007 src/7.cpp)
add_solution(0094 src/94.cpp)
add_solution(0098 src/98.cpp)
add_solution(0100 src/100.cpp)
add_solution(0101 src/101.cpp)
add_solution(0102 src/102.cpp)
add_solution(0104 src/104.cpp)
add_solution(0111 src/111.cpp)
add_solution(0112 src/112.cpp)
add_solution(0144 src/144.cpp)
add_solution(0145 src/145.cpp)
add_solution(0258 src/258.cpp)

add_executable(all-unittests "${SOLUTIONS}")
target_link_libraries(all-unittests gtest-main leetcode)

add_executable(leetcode-unittest test/gtest-main.cpp test/leetcode.cpp)
target_link_libraries(leetcode-unittest leetcode)