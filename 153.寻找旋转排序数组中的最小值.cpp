/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
#include <vector>
#include <numeric>
class Solution {
  int findMin(const std::vector<int> &nums, size_t left, size_t right) noexcept {
    if (right - left == 1) {
        return nums[left];
    }
    if (right - left == 2) {
        return std::min(nums[left], nums[left + 1]);
    }
    size_t middle = (left + right) / 2;
    if (nums[left] < nums[middle]) { // 左半部分有序
        return findMin(nums, middle, right);
    } else {
        return findMin(nums, left, middle + 1);
    }
  }

public:
  int findMin(const std::vector<int> &nums) noexcept {
    if (nums.front() <= nums.back()) {
        return nums.front();
    }
    return findMin(nums, 0, nums.size());
  }
};
// @lc code=end

#include <iostream>

int main() {
    Solution s;
    std::vector<int> nums{3, 4, 5, 1, 2};
    auto result = s.findMin(nums);
    std::cout << result << std::endl;
    return 0;
}
