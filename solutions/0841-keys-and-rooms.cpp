/*
 * @lc app=leetcode.cn id=841 lang=cpp
 *
 * [841] 钥匙和房间
 */

// @lc code=start
#include <queue>
#include <unordered_set>
#include <vector>

class Solution {
public:
  bool
  canVisitAllRooms(const std::vector<std::vector<int>> &rooms) const noexcept {
    std::unordered_set<int> visited;
    std::queue<int> queue{{0}};
    while (not queue.empty()) {
      int node = queue.front();
      queue.pop();
      if (visited.count(node) == 0) {
        visited.insert(node);
        for (int succeed : rooms[node]) {
          queue.push(succeed);
        }
      }
    }
    return visited.size() == rooms.size();
  }
};
// @lc code=end