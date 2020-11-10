/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
#include <queue>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> levelOrder(TreeNode *root) {
    if (root == nullptr) {
      return {};
    }
    std::queue<TreeNode *> queue{{root}};
    std::vector<std::vector<int>> result;
    while (not queue.empty()) {
      TreeNode *top = queue.front();
      queue.pop();
      std::vector<int> level;
    }
    return result;
  }
};
// @lc code=end
