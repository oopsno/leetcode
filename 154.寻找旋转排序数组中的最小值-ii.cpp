/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 * See also: https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/
 */

// @lc code=start
#include <vector>
class Solution {
  int findMin(const std::vector<int> &nums, size_t left, size_t right) noexcept {
    if (right - left == 1) {
      return nums[left];
    }
    if (right - left == 2) {
      return std::min(nums[left], nums[left + 1]);
    }
    size_t middle = (left + right) / 2;
    if (nums[left] > nums[middle]) {
      // 左半部分逆序
      return findMin(nums, left, middle + 1);
    } else if (nums[middle] > nums[right - 1]) {
      // 右半部分逆序
      return findMin(nums, middle, right);
    } else {
      // 不可确定
      return std::min(findMin(nums, left, middle),
                      findMin(nums, middle, right));
    }
  }

public:
  int findMin(const std::vector<int> &nums) noexcept {
    if (nums.front() < nums.back()) {
      return nums.front();
    } else {
      return findMin(nums, 0, nums.size());
    }
  }

  int minArray(const std::vector<int> &nums) noexcept {
    return findMin(nums);
  }
};
// @lc code=end

#include <iostream>

int main() {
  Solution s;
  std::vector<int> xs{2, 2, 2, 0, 1};
  auto value = s.findMin(xs);
  std::cout << value << std::endl;
  return 0;
}