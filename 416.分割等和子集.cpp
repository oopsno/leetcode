/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */
#include <algorithm>
#include <numeric>
#include <stack>
#include <vector>
// @lc code=start
class Solution {
 public:
  bool canPartition(const std::vector<int>& nums) const noexcept {
    // 若和为奇数或数组只有一个元素，必定不能分割
    const int sum = std::accumulate(nums.cbegin(), nums.cend(), 0);
    if (sum % 2 == 1 or nums.size() == 1) {
      return false;
    }
    // 问题相当于在 nums 中寻找一个和为 target = sum / 2 的子集
    const int target = sum / 2;
    // 若 target 小于数组中的最大元素，必然不能分割
    const int max_value = *std::max_element(nums.cbegin(), nums.cend());
    if (max_value > target) {
      return false;
    }
    // 0-1 背包
    std::vector<std::vector<bool>> m(nums.size(), std::vector<bool>(size_t(target + 1), false));
    m[0][nums[0]] = true;
    for (int i = 0; i < nums.size(); ++i) {
        m[i][0] =  true;
    }
    for (int i = 1; i < nums.size(); ++i) {
        for (int j = 1; j <= target; ++j) {
            if (j >= nums[i]) {
                m[i][j] = m[i - 1][j] or m[i - 1][j - nums[i]];
            } else {
                m[i][j] = m[i - 1][j];
            }
        }
    }
    return m[nums.size() - 1][target];
  }
};
// @lc code=end

#include <iostream>

int main() {
  Solution s;
  const std::vector<int> input{6, 80, 94, 12, 33, 87, 18, 72, 27, 7, 29, 35, 62, 96, 12, 38, 64, 47, 67, 31, 96, 8, 85, 78, 46, 73, 99, 11, 73, 43, 30, 71, 2, 40, 90, 33, 15, 69, 25, 80, 93, 60, 6, 95, 81, 43, 12, 65, 2, 2, 8, 7, 91, 64, 47, 58, 92, 22, 95, 64, 64, 78, 5, 61, 41, 21, 20, 61, 29, 76, 32, 48, 66, 18, 50, 15, 71, 20, 18, 87, 78, 56, 100, 54, 58, 20, 47, 14, 80, 43, 73, 69, 85, 71, 63, 86, 83, 7, 58, 95, 74, 6, 25, 7, 32, 71, 23, 22, 14, 41, 53, 58, 85, 63, 26, 91, 37, 56, 3, 82, 91, 1, 2, 62, 77, 53, 49, 45, 44, 60, 71, 89, 75, 7, 28, 13, 89, 92, 95, 74, 60, 77, 82, 30, 34, 89, 7, 68, 73, 85, 42, 51, 87, 63, 41, 3, 53, 40, 62, 7, 46, 71, 46, 40, 38, 98, 100, 41, 65, 52, 57, 72, 42, 10, 89, 50, 66, 50, 89, 13, 34, 4, 36, 82, 10, 84, 76, 52, 26, 69, 15, 77, 71, 82, 49, 48, 35, 61, 54, 80};
  std::cout << std::boolalpha << s.canPartition(input) << std::endl;
  return 0;
}
