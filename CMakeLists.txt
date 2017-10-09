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
include_directories(${INCLUDE})

# Main function for GTEST
add_library(gtest-main src/main.cpp)

# Enable testing
enable_testing()

# Add all solutions
function(add_solution NAME SOURCE)
  add_executable(${NAME} ${SOURCE})
  target_link_libraries(${NAME} gtest-main)
  add_test(${NAME} ${NAME})
endfunction(add_solution)

add_solution(0001 src/1.cpp)
add_solution(0002 src/2.cpp)
add_solution(0003 src/3.cpp)
