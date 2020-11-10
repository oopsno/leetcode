/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 */

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// @lc code=start
#include <string>
#include <vector>
#include <cmath>

class Solution {
private:
  static std::string format(const std::vector<int> &trace) noexcept {
      std::string result;
      for (int i = 0; i < trace.size() - 1; ++i) {
          result += std::to_string(trace[i]);
          result += "->";
      }
      result += std::to_string(trace.back());
      return result;
  }
  static std::vector<std::string>
  format(const std::vector<std::vector<int>> &routes) noexcept {
      std::vector<std::string> results(routes.size());
      for (int i = 0; i < routes.size(); ++i) {
          results[i] = std::move(format(routes[i]));
      }
      return results;
  }

  inline static bool is_leaf(TreeNode *root) noexcept {
    return root->left == nullptr and root->right == nullptr;
  }

  void dfs(TreeNode *root, std::vector<int> trace,
           std::vector<std::vector<int>> &routes) const noexcept {
    if (root == nullptr) {
      return;
    }
    trace.push_back(root->val);
    const bool has_left = root->left != nullptr;
    const bool has_right = root->right != nullptr;
    if (not has_left and not has_right) {
      routes.emplace_back(std::move(trace));
    } else if (has_right and has_right) {
      std::vector<int> dup = trace;
      dfs(root->left, std::move(trace), routes);
      dfs(root->right, std::move(dup), routes);
    } else if (has_left) {
      dfs(root->left, std::move(trace), routes);
    } else {
      dfs(root->right, std::move(trace), routes);
    }
  }

public:
  std::vector<std::string> binaryTreePaths(TreeNode *root) {
    std::vector<std::vector<int>> routes;
    dfs(root, {}, routes);
    return format(routes);
    std::pow(10, )
  }
};
// @lc code=end
