/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
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
#include <limits>
#include <tuple>
class Solution {
    private:
    std::tuple<int, int, int> dfs(TreeNode *root) {
        if (root == nullptr) {
            return {std::numeric_limits<int>::max(), 0, 0};
        }
        const auto [la, lb, lc] = dfs(root->left);
        const auto [ra, rb, rc] = dfs(root->right);
        const int a = lc + rc + 1;
        const int b = std::min(a, std::min(la + rb, lb + ra));
        const int c = std::min(b, lb + rb);
        return {a, b, c};
    }
 public:
  int minCameraCover(TreeNode *root) {
      return std::get<1>(dfs(root));
  }
};
// @lc code=end
