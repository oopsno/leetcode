/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
#include <stack>
#include <vector>
class Solution {
public:
  std::vector<int> inorderTraversal(TreeNode *root) {
    std::vector<int> results;
    std::stack<TreeNode *> s;
    TreeNode *node = root;
    while (node != nullptr or not s.empty()) {
      while (node != nullptr) {
        s.push(node);
        node = node->left;
      }
      node = s.top();
      s.pop();
      results.emplace_back(node->val);
      node = node->right;
    }
    return results;
  }
};
// @lc code=end
