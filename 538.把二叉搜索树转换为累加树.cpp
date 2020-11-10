/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
 */

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// @lc code=start
#include <tuple>

class Solution {
 private:
  void convert(TreeNode* root, int acc = 0) {
    if (root == nullptr) {
      return {nullptr, 0};
    }
    TreeNode* node = root;
    while (node != nullptr) {
      // Morris 遍历
      // 1. 如果当前节点的右子节点为空，处理当前节点，并遍历当前节点的左子节点；
      if (node->right == nullptr) {
        acc += node->val;
        node->val = acc;
        node = node->left;
      } else {
        // 2. 如果当前节点的右子节点不为空，找到当前节点右子树的最左节点（该节点为当前节点中序遍历的前驱节点）
        TreeNode* leaf = node->right;
        while (leaf->left != nullptr and leaf->left != node) {
          leaf = leaf->left;
        }
        // 2a. 如果最左节点的左指针为空，将最左节点的左指针指向当前节点，遍历当前节点的右子节点；
        if (leaf->left == nullptr) {
          leaf->left = node;
          node = node->right;
        } else {
            // 2b. 如果最左节点的左指针不为空，将最左节点的左指针重新置为空（恢复树的原状），处理当前节点，并将当前节点置为其左节点
          leaf->left = nullptr;
          acc += node->val;
          node->val = acc;
          node = node->left;
        }
      }
    }
  }

 public:
  TreeNode* convertBST(TreeNode* root) { convert(root); return root; }
};
// @lc code=end
