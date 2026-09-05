/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

// @lc code=start
#include <algorithm>
#include <functional>
#include <memory>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct graph {
  std::unordered_map<std::string,
                     std::priority_queue<std::string, std::vector<std::string>,
                                         std::greater<std::string>>>
      edges;
  std::vector<std::string> stack;

  void add_edge(const std::string &u, const std::string &v) noexcept {
    edges[u].push(v);
  }

  void dfs(std::string &&start) {
    while (edges.count(start) and not edges[start].empty()) {
      std::string top = edges[start].top();
      edges[start].pop();
      dfs(std::move(top));
    }
    stack.push_back(start);
  }
};

class Solution {
public:
  std::vector<std::string>
  findItinerary(std::vector<std::vector<std::string>> &tickets) const noexcept {
    // 构建有向图
    graph dig;
    for (const auto &pair : tickets) {
      const std::string &from = pair[0];
      const std::string &to = pair[1];
      dig.add_edge(from, to);
    }
    dig.dfs("JFK");
    std::reverse(dig.stack.begin(), dig.stack.end());
    return dig.stack;
  }
};
// @lc code=end