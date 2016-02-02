#include <gtest/gtest.h>
#include "solution/MaximumProductofWordLengths.cpp"


namespace X318 {

Solution s;

TEST(MaximumProductofWordLengths, Character) {
  uint64_t a = Solution::set_letters("letters");
  EXPECT_EQ(Solution::get_letters(a), "elrst");
}

TEST(MaximumProductofWordLengths, Product) {
  uint64_t lhs = Solution::set_letters("abcd");
  uint64_t rhs = Solution::set_letters("wxyz");
  uint64_t ehs = Solution::set_letters("wsad");
  EXPECT_EQ(Solution::product(lhs, rhs), 16);
  EXPECT_EQ(Solution::product(lhs, ehs), 0);
}

TEST(MaximumProductofWordLengths, Functionality) {
  typedef std::pair<int, std::vector<std::string>> case_t;
  std::vector<case_t> cases = {case_t(16, {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"}),
                               case_t(04, {"a", "ab", "abc", "d", "cd", "bcd", "abcd"}),
                               case_t(00, {"a", "aa", "aaa", "aaaa"})};
  for (auto c : cases) {
    EXPECT_EQ(Solution().maxProduct(c.second), c.first);
  }
}

}
