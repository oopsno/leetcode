/*
 * @lc app=leetcode.cn id=783 lang=cpp
 *
 * [783] 二叉搜索树节点最小距离
 */

#include <algorithm>
#include <cmath>
#include <limits>
#include <stack>

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
 public:
  int minDiffInBST(TreeNode *root) {
    int last = -1;
    int minimal = std::numeric_limits<int>::max();
    std::stack<const TreeNode *> s;
    const TreeNode *cursor = root;
    while (cursor != nullptr or not s.empty()) {
      while (cursor != nullptr) {
        s.push(cursor);
        cursor = cursor->left;
      }
      if (not s.empty()) {
        cursor = s.top();
        s.pop();
        if (last >= 0) {
          minimal = std::min(minimal, cursor->val - last);
        }
        last = cursor->val;
        cursor = cursor->right;
      }
    }
    return minimal;
  }
};
// @lc code=end