/**
 * 78. Subsets
 */

#include <vector>
#include <bitset>

class Solution {
 public:
  std::vector<std::vector<int>> subsets(const std::vector<int>& nums) {
    std::vector<int> x(nums.size());
    std::vector<std::vector<int>> xs;
    constexpr auto bits = sizeof(int) * 8;
    for (size_t i = 0; i < (1 << nums.size()); ++i) {
      const std::bitset<bits> bitmap(i);
      xs.emplace_back();
      auto &vec = xs.back();
      for (auto k = 0; k < nums.size(); ++k) {
        if (bitmap[k]) {
          vec.push_back(nums[k]);
        }
      }
    }
    return xs;
  }
};

#include <gtest/gtest.h>
using V = std::vector<int>;
using VV = std::vector<V>;

TEST(Subsets, Empty) {
  Solution s;
  ASSERT_EQ(s.subsets({}), VV{{}});
}

TEST(Subsets, Singleton) {
  Solution s;
  ASSERT_EQ(s.subsets({42}), (VV{{}, {42}}));
}

TEST(Subsets, Many) {
  Solution s;
  ASSERT_EQ(s.subsets({42, 21}), (VV{{}, {42}, {21}, {42, 21}}));
}
