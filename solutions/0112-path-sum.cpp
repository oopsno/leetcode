/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
 */

#include "leetcode/tree-node.h"

// @lc code=start
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
// @lc code=end

#include <doctest/doctest.h>

TEST_CASE("0112") {
  REQUIRE_FALSE(Solution().hasPathSum(nullptr, 0));
  auto t1 = stringToTreeNode("[1]");
  REQUIRE(Solution().hasPathSum(t1, 1));
  auto t2 = stringToTreeNode("[1,2]");
  REQUIRE(Solution().hasPathSum(t2, 3));
  REQUIRE_FALSE(Solution().hasPathSum(t2, 1));
  auto t3 = stringToTreeNode("[5,4,8,11,null,13,4,7,2,null,null,null,1]");
  REQUIRE(Solution().hasPathSum(t3, 22));
}
