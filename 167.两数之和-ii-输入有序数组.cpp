/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
#include <vector>

class Solution {
public:
  std::vector<int> twoSum(const std::vector<int> &xs, const int target) {
    auto front = xs.cbegin();
    auto back = xs.crbegin();
    for (auto current = *front + *back; current != target;
         current = *front + *back) {
      if (current < target) {
        front += 1;
      } else {
        back += 1;
      }
    }
    return {int(std::distance(xs.cbegin(), front) + 1),
            int(xs.size()) - int(std::distance(xs.crbegin(), back))};
    return {*front, *back};
  }
};
// @lc code=end

#include <iostream>
int main() {
  auto result = Solution().twoSum({2, 7, 11, 15}, 9);
  std::cout << result.front() << ", " << result.back() << std::endl;
  return 0;
}