/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// @lc code=start
#include <stack>
#include <vector>

class Solution {
private:
  static inline bool is_leaf(TreeNode *node) noexcept {
    return node->left == nullptr and node->right == nullptr;
  }

public:
  bool isValidBST(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }
    std::stack<TreeNode *> nodes;
    nodes.push(root);
    while (not nodes.empty()) {
      TreeNode *node = nodes.top();
      nodes.pop();
      if (is_leaf(node)) {
        
      }
    }
    return true;
  }
};
// @lc code=end
