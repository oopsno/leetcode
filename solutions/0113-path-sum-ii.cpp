/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 */

#include "leetcode/tree-node.h"
#include <fmt/base.h>
#include <vector>

namespace {
// @lc code=start
struct Context {
  explicit Context(int target) : target{target} {}
  const int target;
  int current = 0;
  std::vector<int> trace = {};
  std::vector<std::vector<int>> results = {};
};

class Solution {
private:
  void visit(TreeNode *root, Context &ctx) {
    if (root == nullptr) {
      return;
    }
    int prev_sum = std::exchange(ctx.current, ctx.current + root->val);
    ctx.trace.push_back(root->val);
    if (root->left && root->right) {
      visit(root->left, ctx);
      visit(root->right, ctx);
    } else if (root->left) {
      visit(root->left, ctx);
    } else if (root->right) {
      visit(root->right, ctx);
    } else {
      if (ctx.target == ctx.current) {
        ctx.results.push_back(ctx.trace);
      }
    }
    ctx.trace.pop_back();
    ctx.current = prev_sum;
  }

public:
  std::vector<std::vector<int>> pathSum(TreeNode *root, int sum) {
    Context ctx{sum};
    visit(root, ctx);
    return ctx.results;
  }
};
// @lc code=end
} // namespace

#include <doctest/doctest.h>

TEST_CASE("0113") {
  SUBCASE("Example 1") {
    auto root = stringToTreeNode("[5,4,8,11,null,13,4,7,2,null,null,5,1]");
    auto result = Solution().pathSum(root, 22);
    std::vector<std::vector<int>> expected = {{5, 4, 11, 2}, {5, 8, 4, 5}};
    REQUIRE_EQ(result, expected);
  }
  SUBCASE("Example 2") {
    auto root = stringToTreeNode("[1,2,3]");
    auto result = Solution().pathSum(root, 5);
    std::vector<std::vector<int>> expected = {};
    REQUIRE_EQ(result, expected);
  }
  SUBCASE("Example 3") {
    auto root = stringToTreeNode("[1,2]");
    auto result = Solution().pathSum(root, 0);
    std::vector<std::vector<int>> expected = {};
    REQUIRE_EQ(result, expected);
  }
}
