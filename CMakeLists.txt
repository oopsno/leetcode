cmake_minimum_required(VERSION 3.8)
project(LeetCode CXX)

# Using Google Test
find_package(GTest 1.8 REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})
link_libraries(${GTEST_LIBRARIES})

# Using Boost.Filesystem
find_package(Boost 1.64 QUIET COMPONENTS filesystem)

# Using C++17
set(CMAKE_CXX_STANDARD_REQUIRED 17)
set(CMAKE_CXX_STANDARD 17)

# Including custom headers
include_directories(include)

# Main function for GTEST
add_library(gtest-main src/main.cpp)

# Enable testing
enable_testing()

# Add all solutions
macro(add_solution NAME SOURCE)
  list(APPEND SOLUTIONS ${SOURCE})
  add_executable(${NAME} ${SOURCE})
  target_link_libraries(${NAME} gtest-main)
  add_test(${NAME} ${NAME})
endmacro(add_solution)

add_solution(0001 src/1.cpp)
add_solution(0002 src/2.cpp)
add_solution(0003 src/3.cpp)
add_solution(0258 src/258.cpp)

add_executable(unittest "${SOLUTIONS}")
target_link_libraries(unittest gtest-main)

if (${Boost_FOUND})
    add_executable(generate_readme src/generate_readme.cpp)
    target_link_libraries(generate_readme ${Boost_LIBRARIES})
endif()
