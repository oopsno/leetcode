/**
 * 98. Validate Binary Search Tree
 */

#include "leetcode.hpp"

using TreeNode = LeetCode::TreeNode<int>;

#include <tuple>
#include <limits>

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
    const auto max = std::max(static_cast<int64_t>(root->val), std::max(lmax, rmax));
    const auto min = std::min(static_cast<int64_t>(root->val), std::min(lmin, rmin));
    const auto legal = lmax < root->val and root->val < rmin;
    return std::make_tuple(min, max, legal and lbst and rbst);
  }
  bool isValidBST(TreeNode *root) {
    return std::get<2>(visit(root));
  }
};

#include <gtest/gtest.h>

TEST(ValidateBinarySearchTree, Testcases) {
  using Tree = LeetCode::Tree<int>;
  Solution s;
  auto t0 = Tree{2, 1, 3};
  ASSERT_TRUE(s.isValidBST(t0));
  auto t1 = Tree{2, 1, 3, std::nullopt, std::nullopt, 0, 5};
  ASSERT_FALSE(s.isValidBST(t1));
  auto t2 = Tree{3, std::nullopt, 30, 10, std::nullopt, std::nullopt, 15, std::nullopt, 45};
  ASSERT_FALSE(s.isValidBST(t2));
  auto t3 = Tree{std::numeric_limits<int>::max()};
  ASSERT_TRUE(s.isValidBST(t3));
}
