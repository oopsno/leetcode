/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */

#include "leetcode/tree-node.h"

// @lc code=start
#include <vector>

class Solution {
public:
  std::vector<int> preorderTraversal(TreeNode *root) {
    std::vector<int> xs;
    preorderTraversal(root, xs);
    return xs;
  }

  void preorderTraversal(TreeNode *root, std::vector<int> &xs) {
    if (root != nullptr) {
      xs.push_back(root->val);
      preorderTraversal(root->left, xs);
      preorderTraversal(root->right, xs);
    }
  }
};
// @lc code=end

#include <doctest/doctest.h>

TEST_CASE("0144") {
  auto tree = stringToTreeNode("[1,null,2,3]");
  REQUIRE_EQ(Solution().preorderTraversal(tree), (std::vector<int>{1, 2, 3}));
  auto empty = stringToTreeNode("[]");
  REQUIRE_EQ(Solution().preorderTraversal(empty), (std::vector<int>{}));
  auto single = stringToTreeNode("[1]");
  REQUIRE_EQ(Solution().preorderTraversal(single), (std::vector<int>{1}));
}
