#pragma once

namespace LeetCode {

template<typename T>
struct TreeNode {
  TreeNode(T value, TreeNode<T> *left, TreeNode<T> *right) : val{value}, left{left}, right{right} {}

  TreeNode(T value) : val{value}, left{nullptr}, right{nullptr} {}

  static void release(TreeNode<T> *root) {
    if (root != nullptr) {
      release(root->left);
      release(root->right);
      delete root;
    }
  }

  TreeNode *left, *right;
  T val;
};

template<typename T>
struct ListNode {
  explicit ListNode(T x) : val(x), next(nullptr) {}

  bool equalTo(const ListNode *rhs) const {
    auto lhs = this;
    while (lhs != nullptr and rhs != nullptr) {
      if (lhs->val != rhs->val) {
        return false;
      }
      lhs = lhs->next;
      rhs = rhs->next;
    }
    return lhs == nullptr and rhs == nullptr;
  }

  T val;
  ListNode *next;
};

}

