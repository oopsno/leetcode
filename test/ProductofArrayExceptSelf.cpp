#include <gtest/gtest.h>
#include "solution/ProductofArrayExceptSelf.cpp"

namespace X238 {

Solution s;

TEST(ProductofArrayExceptSelf, Functionality) {
  std::vector<int> array = {1, 2, 3, 4};
  std::vector<int> answer = {24, 12, 8, 6};
  std::vector<int> result = s.productExceptSelf(array);
  EXPECT_TRUE(std::equal(result.cbegin(), result.cend(), answer.cbegin()));
}

}
