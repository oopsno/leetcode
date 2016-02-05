#include <gtest/gtest.h>
#include "solution/BitwiseAND.cpp"
namespace X201 {

Solution s;

TEST(BitwiseAND, Utilities) {
  integer_info i = info(5);
  integer_info j{4, 1, false};
  typedef std::pair<integer_info, integer_info> case_t;
  std::vector<case_t> cases = {
      case_t(info(8), {8, 0, 3}),
      case_t(info(5), {4, 1, 2}),
      case_t(info(0), {0, 0, 0}),
  };
  for (case_t c : cases) {
    EXPECT_TRUE(c.first == c.second);
  }
}

TEST(BitwiseAND, Functionality) {
  typedef std::pair<int, int> case_t;
  std::vector<case_t> cases = {
      case_t(s.rangeBitwiseAnd(0, INT_MAX), 0),
      case_t(s.rangeBitwiseAnd(1, INT_MAX), 0),
      case_t(s.rangeBitwiseAnd(5, 7), 4),
      case_t(s.rangeBitwiseAnd(7, 5), 4),
      case_t(s.rangeBitwiseAnd(3, 5), 0),
  };
  for (case_t c : cases) {
    EXPECT_EQ(c.first, c.second);
  }
}

}

