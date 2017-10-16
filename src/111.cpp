/**
 * 111. Minimum Depth of Binary Tree
 */

#include "leetcode.hpp"
DESCRIPTION(111, "Minimum Depth of Binary Tree", Trees);

class Solution {
 public:
  int minDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    if (root->left != nullptr and root->right != nullptr) {
      return std::min(minDepth(root->left), minDepth(root->right)) + 1;
    }
    if(root->left != nullptr) {
      return minDepth(root->left) + 1;
    }
    if(root->right != nullptr) {
      return minDepth(root->right) + 1;
    }
    return 1;
  }
};

TEST(MinimumDepthOfBinaryTree, Testcases) {
  auto empty = Tree{};
  ASSERT_EQ(s.minDepth(empty), 0);
  auto singleton = Tree{42};
  ASSERT_EQ(s.minDepth(singleton), 1);
  auto link = Tree{1, 2};
  ASSERT_EQ(s.minDepth(link), 2);
  auto full = Tree{1, 2, 3};
  ASSERT_EQ(s.minDepth(full), 2);
}
