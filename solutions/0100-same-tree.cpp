/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

#include "leetcode/tree-node.h"

// @lc code=start
class Solution {
public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p == q) {
      return true;
    }
    if (p == nullptr or q == nullptr) {
      return false;
    }
    return p->val == q->val and isSameTree(p->left, q->left) and
           isSameTree(p->right, q->right);
  }
};
// @lc code=end

#include <doctest/doctest.h>

TEST_CASE("0100") {
  auto *x = stringToTreeNode("[1,2,3]");
  auto *y = stringToTreeNode("[1,2,3]");
  REQUIRE(Solution().isSameTree(x, y));
  REQUIRE(Solution().isSameTree(x, x));
  REQUIRE(Solution().isSameTree(nullptr, nullptr));
  REQUIRE_FALSE(Solution().isSameTree(nullptr, y));
  REQUIRE_FALSE(Solution().isSameTree(x, nullptr));
}