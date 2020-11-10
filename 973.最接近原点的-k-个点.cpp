/*
 * @lc app=leetcode.cn id=973 lang=cpp
 *
 * [973] 最接近原点的 K 个点
 */
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>

// @lc code=start
class Solution {
 private:
  struct Element {
    Element(int distance, size_t index) : distance(distance), index(index) {}

    int distance;
    size_t index;
  };

  struct ElementCompare {
    bool operator()(const Element &lhs, const Element &rhs) noexcept {
      return lhs.distance < rhs.distance;
    }
  };

 public:
  std::vector<std::vector<int>> kClosest(
      const std::vector<std::vector<int>> &points, int K) noexcept {
    auto queue =
        std::priority_queue<Element, std::vector<Element>, ElementCompare>();
    for (size_t i = 0; i < points.size(); ++i) {
      const auto &point = points[i];
      const int distance = point[0] * point[0] + point[1] * point[i][1];
      if (i < K) {
        queue.emplace(distance, i);
      } else {
        if (distance < queue.top().distance) {
          queue.pop();
          queue.emplace(distance, i);
        }
      }
    }
    std::vector<std::vector<int>> results;
    for (int i = 0; i < K; ++i) {
      results.push_back(points[queue.top().index]);
      queue.pop();
    }
    return results;
  }
};
// @lc code=end
