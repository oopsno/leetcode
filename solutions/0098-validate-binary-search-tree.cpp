/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

#include "leetcode/tree-node.h"

// @lc code=start
#include <algorithm>
#include <limits>
#include <tuple>

class Solution {
public:
  auto visit(TreeNode *root) -> std::tuple<int64_t, int64_t, bool> {
    int64_t lmin, lmax, rmin, rmax;
    bool lbst, rbst;
    if (root == nullptr) {
      using limit = std::numeric_limits<int64_t>;
      return std::make_tuple(limit::max(), limit::min(), true);
    }
    std::tie(lmin, lmax, lbst) = visit(root->left);
    std::tie(rmin, rmax, rbst) = visit(root->right);
    const auto mx =
        std::max(static_cast<int64_t>(root->val), std::max(lmax, rmax));
    const auto mn =
        std::min(static_cast<int64_t>(root->val), std::min(lmin, rmin));
    const auto legal = lmax < root->val and root->val < rmin;
    return std::make_tuple(mn, mx, legal and lbst and rbst);
  }
  bool isValidBST(TreeNode *root) { return std::get<2>(visit(root)); }
};
// @lc code=end

#include <doctest/doctest.h>

TEST_CASE("0098") {
  auto t0 = stringToTreeNode("[2,1,3]");
  REQUIRE(Solution().isValidBST(t0));
  auto t1 = stringToTreeNode("[5,1,4,null,null,3,6]");
  REQUIRE_FALSE(Solution().isValidBST(t1));
  auto t2 = stringToTreeNode("[3,null,30,10,null,null,15,null,45]");
  REQUIRE_FALSE(Solution().isValidBST(t2));
}
