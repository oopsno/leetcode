/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
 */

#include "leetcode/tree-node.h"

namespace {
// @lc code=start
class Solution {
private:
  std::pair<int, int> dfs(TreeNode *node) {
    if (node == nullptr) {
      return {0, 0};
    }
    auto [rob_left, not_rob_left] = dfs(node->left);
    auto [rob_right, not_rob_right] = dfs(node->right);
    // 抢劫 node, 意味着跳过子节点和父节点
    int rob = node->val + not_rob_left + not_rob_right;
    // 不抢劫 node, 那就抢父&子节点
    int not_rob = std::max(rob_left, not_rob_left) + std::max(rob_right, not_rob_right);
    return {rob, not_rob};
  }

public:
  int rob(TreeNode *root) {
    auto [rob, not_rob] = dfs(root);
    return std::max(rob, not_rob);
  }
};
// @lc code=end
} // namespace

#include <doctest/doctest.h>

TEST_CASE("0337") {
  SUBCASE("Example 1") {
    auto root = stringToTreeNode("[3,2,3,null,3,null,1]");
    REQUIRE_EQ(Solution().rob(root), 7);
  }
  SUBCASE("Example 2") {
    auto root = stringToTreeNode("[3,4,5,1,3,null,1]");
    REQUIRE_EQ(Solution().rob(root), 9);
  }
}