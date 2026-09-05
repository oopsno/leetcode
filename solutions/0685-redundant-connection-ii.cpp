/*
 * @lc app=leetcode.cn id=685 lang=cpp
 *
 * [685] 冗余连接 II
 */

// @lc code=start
#include <vector>

struct UnionFind {
  std::vector<int> uf;
  UnionFind(size_t n) : uf(n) {
    for (int i = 0; i < n; ++i) {
      uf[i] = i;
    }
  }
  int find(int index) const noexcept {
    if (index == uf[index]) {
      return index;
    } else {
      return find(uf[index]);
    }
  }
  void merge(int u, int v) noexcept { uf[find(u)] = find(v); }
};

class Solution {
public:
  std::vector<int>
  findRedundantDirectedConnection(std::vector<std::vector<int>> &edges) {
    UnionFind uf(edges.size() + 1);
    std::vector<int> parent = std::move(UnionFind(edges.size() + 1).uf);
    int cycle = -1;
    int conflict = -1;
    for (int i = 0; i < edges.size(); ++i) {
      const auto &uv = edges[i];
      const int u = uv[0], v = uv[1];
      if (parent[v] != v) {
        conflict = i;
      } else {
        parent[v] = u;
        if (uf.find(u) == uf.find(v)) {
          cycle = i;
        } else {
          uf.merge(u, v);
        }
      }
    }
    if (conflict < 0) {
      return edges[cycle];
    } else {
      const auto &uv = edges[conflict];
      if (cycle >= 0) {
        return {parent[uv[1]], uv[1]};
      } else {
        return uv;
      }
    }
  }
};
// @lc code=end
