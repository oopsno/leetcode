/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
#include <array>
#include <vector>
constexpr size_t BITS = 8 * sizeof(size_t);

template <size_t S, size_t... Ss>
struct make_selectors : make_selectors<(S << 1), Ss..., S> {};

template <size_t... Ss> struct make_selectors<0, Ss...> {
  static constexpr std::array<size_t, BITS> value = {Ss...};
};

// 从 (1 << 0) 到 (1 << 64)
constexpr auto selectors = make_selectors<1>::value;

class Solution {
public:
  std::vector<std::vector<int>> subsets(std::vector<int> &nums) noexcept {
    const size_t num_subsets = 1UL << nums.size();
    std::vector<std::vector<int>> result(num_subsets);
    // 此算法生成的首个子集为空集，可以跳过
    auto it = result.begin() + 1;
    for (size_t pattern = 1; pattern < num_subsets; ++pattern, ++it) {
      // 一次性预分配内存以降低申请开销
      it->resize(__builtin_popcount(pattern));
      size_t cursor = 0;
      for (size_t i = 0; i < nums.size(); ++i) {
        if ((selectors[i] & pattern) != 0) {
            it->operator[](cursor++) = nums[i];
        }
      }
    }
    return result;
  }
};
// @lc code=end