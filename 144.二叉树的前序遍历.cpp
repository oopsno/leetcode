/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
#include <deque>
#include <vector>

// @lc code=start
class Solution {
 public:
  std::vector<int> preorderTraversal(TreeNode *root) {
    std::vector<int> result;
    if (root == nullptr) {
      return result;
    }
    std::deque<TreeNode *> queue{{root}};
    while (not queue.empty()) {
      TreeNode *node = queue.back();
      queue.pop_back();
      result.emplace_back(node->val);
      if (node->right != nullptr) {
        queue.push_back(node->right);
      }
      if (node->left != nullptr) {
        queue.push_back(node->left);
      }
    }
    return result;
  }
};
// @lc code=end
