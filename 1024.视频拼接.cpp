/*
 * @lc app=leetcode.cn id=1024 lang=cpp
 *
 * [1024] 视频拼接
 */

#include <algorithm>
#include <vector>

// @lc code=start
class Solution {
 public:
  int videoStitching(std::vector<std::vector<int>> &clips,
                     int T) const noexcept {
    using clip_t = std::vector<int>;
    std::sort(clips.begin(), clips.end(),
              [](const clip_t &lhs, const clip_t &rhs) {
                return lhs.front() < rhs.front();
              });
    if (T > 0 and clips.front().front() != 0) {
        return -1;
    }
    std::vector<int> dp(T + 1, clips.size() + 1);
    dp[0] = 1;
    for (int i = 1; i <= T; ++i) {
        dp[i] = 
    }
  }
};
// @lc code=end