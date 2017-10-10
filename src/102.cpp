/**
 * 102. Binary Tree Level Order Traversal
 */

#include "leetcode.hpp"
using TreeNode = LeetCode::TreeNode<int>;
using Tree = LeetCode::Tree<int>;

#include <vector>

class Solution {
 public:
  std::vector<std::vector<int>> levelOrder(TreeNode *root) {
    std::vector<std::vector<int>> xs;
    levelOrder(root, xs, 1);
    return xs;
  }

  void levelOrder(TreeNode *root, std::vector<std::vector<int>> &xs, int level) {
    if (root != nullptr) {
      while (xs.size() < level) {
        xs.emplace_back();
      }
      xs[level - 1].push_back(root->val);
      levelOrder(root->left, xs, level + 1);
      levelOrder(root->right, xs, level + 1);
    }
  }
};

#include <gtest/gtest.h>

TEST(BinaryTreeTraversal, LevelOrder) {
  auto tree = Tree{3, 9, 20, std::nullopt, std::nullopt, 15, 7};
  auto traversal = Solution().levelOrder(tree);
  ASSERT_EQ(traversal, (typeof(traversal){{3}, {9, 20}, {15, 7}}));
}


