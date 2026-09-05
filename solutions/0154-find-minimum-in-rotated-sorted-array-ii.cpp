/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 * See also: https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/
 */

#include <vector>
namespace {
// @lc code=start
class Solution {
  int findMinImpl(const std::vector<int> &nums, size_t left, size_t right) noexcept {
    if (right - left == 1) {
      return nums[left];
    }
    if (right - left == 2) {
      return std::min(nums[left], nums[left + 1]);
    }
    size_t middle = (left + right) / 2;
    if (nums[left] > nums[middle]) {
      // 左半部分逆序
      return findMinImpl(nums, left, middle + 1);
    } else if (nums[middle] > nums[right - 1]) {
      // 右半部分逆序
      return findMinImpl(nums, middle, right);
    } else {
      // 不可确定
      return std::min(findMinImpl(nums, left, middle),
                      findMinImpl(nums, middle, right));
    }
  }

public:
  int findMin(const std::vector<int> &nums) {
    if (nums.front() < nums.back()) {
      return nums.front();
    } else {
      return findMinImpl(nums, 0, nums.size());
    }
  }

  int minArray(const std::vector<int> &nums) noexcept {
    return findMin(nums);
  }
};
// @lc code=end
}

#include <doctest/doctest.h>
#include "leetcode/runner.h"

TEST_CASE("0154") {
  auto f = Runner(154, &Solution::findMin);
  std::vector<int> xs{2, 2, 2, 0, 1};
  REQUIRE_EQ(f(xs), 0);
}