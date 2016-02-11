#include <gtest/gtest.h>
#include <random>
#include "solution/Pow3.cpp"

namespace X326 {

Solution s;
typedef int case_t;

TEST(Pow3, Powers) {
  int power = 1;
  const int *po3 = po3s<19>::type::array;
  for (int i = 0; i < 20; i++) {
    EXPECT_EQ(power, po3[i]);
    power *= 3;
  }
}

bool isPowerOfThree(int n) {
  if (n < 1) {
    return false;
  }
  if (n == 1) {
    return true;
  }
  std::div_t r = std::div(n, 3);
  return r.rem == 0 and isPowerOfThree(r.quot);
}

TEST(Pow3, Functionality) {
  int power = 1;
  const int *po3 = po3s<19>::type::array;
  for (int i = 0; i < 20; i++) {
    EXPECT_TRUE(s.isPowerOfThree(po3[i]));
    power *= 3;
  }
}

TEST(Pow3, RandomCases) {
  std::mt19937 engine(326);
  std::uniform_int_distribution<int> dist;
  const int *po3 = po3s<19>::type::array;
  for (int i = 0; i < 2000000; i++) {
    int next = dist(engine);
    EXPECT_EQ(isPowerOfThree(next), s.isPowerOfThree(next));
  }
}

}

