/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 */
#include <vector>
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
    private:
    void dfs(std::vector<double> &average, std::vector<int> &counter, TreeNode *root, const int level) {
        if (root == nullptr) {
            return;
        }
        if (level < counter.size()) {
            average[level] += root->val;
            counter[level] += 1;
        } else {
            average.emplace_back(1. * root->val);
            counter.emplace_back(1);
        }
        dfs(average, counter, root->left, level + 1);
        dfs(average, counter, root->right, level + 1);
    }
public:
  std::vector<double> averageOfLevels(TreeNode *root) {
      std::vector<double> average;
      std::vector<int> counter;
      dfs(average, counter, root, 0);
      for (int i = 0; i < counter.size(); ++i) {
          average[i] /= static_cast<double>(counter[i]);
      }
      return average;
  }
};
// @lc code=end
