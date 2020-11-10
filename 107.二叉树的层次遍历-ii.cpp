/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
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
#include <algorithm>
#include <queue>
#include <vector>
class Solution {
private:
  static void bfs(TreeNode *root,
                  std::vector<std::vector<int>> &results) noexcept {
    std::queue<TreeNode *> queue{{root}};
    while (not queue.empty()) {
      auto level = std::vector<int>();
      const int num_nodes = queue.size();
      for (int i = 0; i < num_nodes; ++i) {
        auto node = queue.front();
        queue.pop();
        level.push_back(node->val);
        if (node->left != nullptr) {
          queue.push(node->left);
        }
        if (node->right != nullptr) {
          queue.push(node->right);
        }
      }
      results.emplace_back(std::move(level));
    }
  }

public:
  std::vector<std::vector<int>>
  levelOrderBottom(TreeNode *root) const noexcept {
    std::vector<std::vector<int>> results = levelOrder(root);
    std::reverse(results.begin(), results.end());
    return results;
  }

  std::vector<std::vector<int>> levelOrder(TreeNode *root) const noexcept {
    if (root == nullptr) {
      return {};
    }
    std::vector<std::vector<int>> results;
    bfs(root, results);
    return results;
  }
};
// @lc code=end
