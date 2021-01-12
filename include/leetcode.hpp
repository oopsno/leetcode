#pragma once

/**
 * 基本上都是来自 https://leetcode-cn.com/playground/ 的代码
 */

#include <string>
#include <vector>

#include <nlohmann/json.hpp>

namespace leetcode {
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

int stringToInteger(std::string input);
std::vector<int> stringToIntegerVector(std::string input);
ListNode *stringToListNode(std::string input);
std::string integerVectorToString(std::vector<int> list, int length = -1);
std::string listNodeToString(ListNode *node);
std::string boolToString(bool input);
bool stringToBool(std::string input);
std::string treeNodeToString(TreeNode *root);
TreeNode *stringToTreeNode(std::string input);
std::string stringToString(std::string input);
void prettyPrintTree(TreeNode *node, std::string prefix = "",
                     bool isLeft = true);
void prettyPrintLinkedList(ListNode *node);

template <typename T> struct deserializer;

template <> struct deserializer<std::vector<std::vector<int>>> {
  std::vector<std::vector<int>> operator()(std::string literal) const {
    const auto document = nlohmann::json::parse(literal);
    return document.get<std::vector<std::vector<int>>>();
  }
};

template <> struct deserializer<std::vector<int>> {
  std::vector<int> operator()(std::string literal) const {
    return stringToIntegerVector(literal);
  }
};

template <> struct deserializer<ListNode *> {
  ListNode *operator()(std::string literal) const {
    return stringToListNode(literal);
  }
};

template <> struct deserializer<TreeNode *> {
  TreeNode *operator()(std::string literal) const {
    return stringToTreeNode(literal);
  }
};

template <> struct deserializer<std::string> {
  std::string operator()(std::string literal) const {
    return literal;
  }
};

template <> struct deserializer<int> {
  int operator()(std::string literal) const { return stringToInteger(literal); }
};

template <> struct deserializer<bool> {
  bool operator()(std::string literal) const { return stringToBool(literal); }
};

} // namespace leetcode