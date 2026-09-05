/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */

#include "leetcode/tree-node.h"

// @lc code=start
#include <vector>

class Solution {
public:
  std::vector<int> postorderTraversal(TreeNode *root) {
    std::vector<int> xs;
    postorderTraversal(root, xs);
    return xs;
  }

  void postorderTraversal(TreeNode *root, std::vector<int> &xs) {
    if (root != nullptr) {
      postorderTraversal(root->left, xs);
      postorderTraversal(root->right, xs);
      xs.push_back(root->val);
    }
  }
};
// @lc code=end

#include <doctest/doctest.h>

TEST_CASE("0145") {
  auto tree = stringToTreeNode("[1,null,2,3]");
  REQUIRE_EQ(Solution().postorderTraversal(tree), (std::vector<int>{3, 2, 1}));
  auto empty = stringToTreeNode("[]");
  REQUIRE_EQ(Solution().postorderTraversal(empty), (std::vector<int>{}));
  auto single = stringToTreeNode("[1]");
  REQUIRE_EQ(Solution().postorderTraversal(single), (std::vector<int>{1}));
}
