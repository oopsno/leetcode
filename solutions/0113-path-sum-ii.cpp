/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
#include <vector>
class Solution {
private:
  void pathSum(TreeNode *root, int sum, int current, std::vector<int> trace,
               std::vector<std::vector<int>> &result) {
    current = current + root->val;
    trace.emplace_back(root->val);
    bool match = sum == current;
    if (root->left == nullptr and root->right == nullptr) {
      if (sum == current) {
        result.emplace_back(std::move(trace));
      }
    } else if (root->left != nullptr and root->right != nullptr) {
      pathSum(root->left, sum, current, trace, result);
      pathSum(root->right, sum, current, std::move(trace), result);
    } else if (root->left != nullptr) {
      pathSum(root->left, sum, current, std::move(trace), result);
    } else {
      pathSum(root->right, sum, current, std::move(trace), result);
    }
  }

public:
  std::vector<std::vector<int>> pathSum(TreeNode *root, int sum) {
    if (root == nullptr) {
      return {};
    }
    std::vector<std::vector<int>> result;
    pathSum(root, sum, 0, {}, result);
    return result;
  }
};
// @lc code=end
