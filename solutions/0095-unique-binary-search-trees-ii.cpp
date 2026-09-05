/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 */

#include <algorithm>
#include <string>
#include <vector>

/**
 * LeetCode 二叉树结构
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}

  // 以下为自定义的调试功能
  std::vector<std::string> dump() const noexcept {
    auto elements = std::vector<std::string>();
    dump(elements);
    return elements;
  }

  std::vector<std::string>
  dump(std::vector<std::string> &elements) const noexcept {
    elements.emplace_back(std::to_string(val));
    if (left == nullptr and right == nullptr) {
      return elements;
    }
    if (left == nullptr and right != nullptr) {
      elements.push_back("null");
      right->dump(elements);
    }
    if (left != nullptr) {
      left->dump(elements);
      if (right != nullptr) {
        right->dump(elements);
      }
    }
    return elements;
  }
};

// @lc code=start
class Solution {
public:
  std::vector<int> range(int n) {
    auto numbers = std::vector<int>(n);
    for (int i = 0; i < n; ++i) {
      numbers[i] = i + 1;
    }
    return numbers;
  }
  std::tuple<std::vector<int>, std::vector<int>>
  split_at(const std::vector<int> &numbers, int n) {
    for (int i = 0; i < numbers.size(); ++i) {
      if (numbers[i] == n) {
        auto lhs = std::vector<int>(i);
        std::copy_n(numbers.cbegin(), lhs.size(), lhs.begin());
        auto rhs = std::vector<int>(numbers.size() - i - 1);
        std::copy_n(numbers.crbegin(), rhs.size(), rhs.rbegin());
        return {lhs, rhs};
      }
    }
    return {{}, {}};
  }

  std::vector<TreeNode *> generateTrees(const std::vector<int> &numbers) {
    if (numbers.empty()) {
      return {nullptr};
    }
    if (numbers.size() == 1) {
      return {new TreeNode(numbers.front())};
    }
    std::vector<TreeNode *> trees;
    std::vector<std::tuple<std::vector<TreeNode *>, std::vector<TreeNode *>>> children;
    for (auto root : numbers) {
      auto [lhs, rhs] = split_at(numbers, root);
      auto lhs_nodes = generateTrees(lhs);
      auto rhs_nodes = generateTrees(rhs);
      for (auto lhs_node : lhs_nodes) {
        for (auto rhs_node : rhs_nodes) {
          auto tree = new TreeNode(root, lhs_node, rhs_node);
          trees.push_back(tree);
        }
      }
    }
    return trees;
  }

public:
  std::vector<TreeNode *> generateTrees(int n) {
    if (n == 0) {
      return {};
    }
    return generateTrees(range(n));
  }
};
// @lc code=end

// #include <spdlog/spdlog.h>