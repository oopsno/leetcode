#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <optional>

namespace LeetCode {

template<typename T>
struct TreeNode {
  TreeNode(T value, TreeNode<T> *left, TreeNode<T> *right) : val{value}, left{left}, right{right} {}

  TreeNode(T value) : val{value}, left{nullptr}, right{nullptr} {}

  bool is_leaf() const {
    return left == nullptr and right == nullptr;
  }

  static void release(TreeNode<T> *root) {
    if (root != nullptr) {
      release(root->left);
      release(root->right);
      delete root;
    }
  }

  template<template<typename> typename Container=std::vector>
  static TreeNode<T> *build(const Container<std::optional<T>> &xs, int x) {
    if (x > xs.size()) {
      return nullptr;
    }
    const auto val = xs[x - 1];
    if (not val) {
      return nullptr;
    }
    return new TreeNode<T>(val.value(), build(xs, 2 * x), build(xs, 2 * x + 1));
  }

  static bool is_same(TreeNode<T> *lhs, TreeNode<T> *rhs) {
    if (lhs == rhs) {
      return true;
    }
    if (lhs == nullptr or rhs == nullptr) {
      return false;
    }
    return lhs->val == rhs->val and is_same(lhs->left, rhs->left) and is_same(lhs->right, rhs->right);
  }

  TreeNode *left, *right;
  T val;
};

template<typename T>
struct Tree {
  template<template<typename> typename Container=std::vector>
  Tree(const Container<std::optional<T>> &xs) : node{TreeNode<T>::build(xs, 1)} {}

  template<template<typename> typename Container=std::vector>
  Tree(const Container<std::optional<T>> &&xs) : node{TreeNode<T>::build(std::move(xs), 1)} {}

  Tree(std::initializer_list<std::optional<T>> il) : node{
      TreeNode<T>::build(std::vector<std::optional<T>>(il.begin(), il.end()), 1)} {}

  Tree(TreeNode<T> *node) : node{node} {}

  ~Tree() {
    TreeNode<T>::release(node);
  }

  inline operator TreeNode<T> *() {
    return node;
  }

  inline TreeNode<T> *operator->() {
    return node;
  }

  operator==(const Tree<T> &rhs) const {
    TreeNode<T>::is_same(node, rhs.node);
  }

  TreeNode<T> *node;
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

enum Category {
  BinaryTree, List, Math
};

struct SolutionDescriptor {
  SolutionDescriptor() = default;
  SolutionDescriptor(const SolutionDescriptor &descriptor);
  SolutionDescriptor(SolutionDescriptor &&descriptor) noexcept;
  SolutionDescriptor(const size_t id, std::string &&path, std::string &&title, std::vector<Category> &&categories);
  SolutionDescriptor &operator=(const SolutionDescriptor &descriptor);
  size_t id;
  std::string path, title;
  std::vector<Category> categories;
};

struct SolutionManager {
  std::map<size_t, SolutionDescriptor> id_solution;
  std::map<std::string, SolutionDescriptor> path_solution;
  std::map<Category, std::vector<SolutionDescriptor>> cat_solutions;
  void append(const SolutionDescriptor &descriptor);
};

extern SolutionManager solution_manager;

struct SolutionDescriptorInjector {
  SolutionDescriptorInjector(const size_t id,
                             std::string &&path,
                             std::string &&title,
                             std::vector<Category> &&categories);
};

}

using LeetCode::Category::BinaryTree;
using LeetCode::Category::Math;
using LeetCode::Category::List;

#define DESCRIPTION(id, title, ...) \
  static LeetCode::SolutionDescriptorInjector __sdi_##__LINE__##__(id, __FILE__, title, {__VA_ARGS__})
