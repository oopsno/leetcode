/**
 * 112. Path Sum
 */

#include "leetcode.hpp"
DESCRIPTION(112, "Path Sum", BinaryTree);

class Solution {
 public:
  bool hasPathSum(TreeNode *root, int sum) {
    if (root == nullptr) {
      return false;
    }
    const auto rest = sum - root->val;
    if (root->left and root->right) {
      return hasPathSum(root->left, rest) or hasPathSum(root->right, rest);
    }
    if (root->left) {
      return hasPathSum(root->left, rest);
    }
    if (root->right) {
      return hasPathSum(root->right, rest);
    }
    return rest == 0;
  }
};

TEST(PathSum, Empty) {
  ASSERT_FALSE(s.hasPathSum(nullptr, 0));
}

TEST(PathSum, Singleton) {
  auto t = Tree{1};
  ASSERT_TRUE(s.hasPathSum(t, 1));
}

TEST(PathSum, List) {
  auto t = Tree{1, 2};
  ASSERT_TRUE(s.hasPathSum(t, 3));
  ASSERT_FALSE(s.hasPathSum(t, 1));
}

TEST(PathSum, Custom) {
  auto t0 = Tree{5, 4, 8, 11, 13, 4, 7, 2, std::nullopt, std::nullopt, std::nullopt, 1};
  ASSERT_TRUE(s.hasPathSum(t0, 22));
}
