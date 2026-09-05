/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
 * Given the root of a binary search tree (BST) with duplicates,
 * return all the mode(s) (i.e., the most frequently occurred element) in it.
 */

#include "leetcode/tree-node.h"

// @lc code=start
#include <optional>
#include <vector>

class Solution {
 private:
  static inline void visit(std::vector<int> &results,
                           std::optional<int> &element, int &counter,
                           int &maximum_counter, int current) noexcept {
    if (element.has_value() and element.value() == current) {
      counter += 1;
    } else {
      element = current;
      counter = 1;
    }
    if (counter == maximum_counter) {
      results.push_back(current);
    }
    if (counter > maximum_counter) {
      results.clear();
      results.push_back(element.value());
      maximum_counter = counter;
    }
  }

 public:
  std::vector<int> findMode(TreeNode *root) {
    std::vector<int> results;
    std::optional<int> element = std::nullopt;
    int counter = 0, maximum_counter = 0;
    // Morris 遍历
    TreeNode *current = root;
    while (current != nullptr) {
      if (current->left == nullptr) {
        visit(results, element, counter, maximum_counter, current->val);
        current = current->right;
      } else {
        TreeNode *pre = current->left;
        while (pre->right != nullptr and pre->right != current) {
          pre = pre->right;
        }
        if (pre->right == nullptr) {
          pre->right = current;
          current = current->left;
        } else {
          pre->right = nullptr;
          visit(results, element, counter, maximum_counter, current->val);
          current = current->right;
        }
      }
    }
    if (element != std::nullopt and results.empty()) {
      results.push_back(element.value());
    }
    return results;
  }
};
// @lc code=end

#include <doctest/doctest.h>

TEST_CASE("0501") {
  auto *tree = stringToTreeNode("[1,null,2,2]");
  REQUIRE_EQ(Solution().findMode(tree), std::vector{2});
}