#include <gtest/gtest.h>
#include "solution/ValidParentheses.cpp"
namespace X20 {

Solution s;
typedef int case_t;

TEST(ValidParentheses, Functionality) {
  EXPECT_TRUE(s.isValid("()"));
  EXPECT_TRUE(s.isValid("()[]{}"));
  EXPECT_FALSE(s.isValid("(]"));
  EXPECT_FALSE(s.isValid("([)]"));
}


}

