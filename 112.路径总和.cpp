/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
class Solution {
private:
  bool hasPathSum(TreeNode *root, int sum, int current) {
    current = current + root->val;
    if (root->left == nullptr and root->right == nullptr) {
      return sum == current;
    }
    return (root->left != nullptr and hasPathSum(root->left, sum, current)) or
           (root->right != nullptr and hasPathSum(root->right, sum, current));
  }

public:
  bool hasPathSum(TreeNode *root, int sum) {
    if (root == nullptr) {
      return false;
    }
    return hasPathSum(root, sum, 0);
  }
};
// @lc code=end
