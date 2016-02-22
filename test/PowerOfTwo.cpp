#include <gtest/gtest.h>
#include "solution/PowerOfTwo.cpp"
namespace X231 {

Solution s;
typedef std::pair<int, bool> case_t;


TEST(PowerOfTwo, Functionality) {
  std::vector<case_t> cases {
      {0, false},
      {INT_MIN, false},
      {4<<8, true}
  };
  for (case_t &c : cases) {
    EXPECT_EQ(s.isPowerOfTwo(c.first), c.second);
  }
}

}

