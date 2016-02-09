#include <gtest/gtest.h>
#include "solution/Atoi.cpp"
namespace X8 {

Solution s;
typedef std::pair<std::string, int> case_t;

TEST(Atoi, Functionality) {
  std::vector<case_t> cases{
      case_t{"", 0},
      case_t{"zero", 0},
      case_t{" 2147483647", INT_MAX},
      case_t{" 2147483648", INT_MAX},
      case_t{" -2147483648", INT_MIN},
      case_t{" -2147483649", INT_MIN},
  };
  for (case_t c : cases) {
    EXPECT_EQ(s.myAtoi(c.first), c.second);
  }
}

}

