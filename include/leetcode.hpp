#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <optional>
#include <functional>

#define GTEST_DONT_DEFINE_TEST 1
#include <gtest/gtest.h>

namespace LeetCode {

template<typename T>
struct TreeNode {
  TreeNode(T value, TreeNode<T> *left, TreeNode<T> *right) : val{value}, left{left}, right{right} {}

  explicit TreeNode(T value) : val{value}, left{nullptr}, right{nullptr} {}

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
  explicit Tree(const Container<std::optional<T>> &xs) : node{TreeNode<T>::build(xs, 1)} {}

  template<template<typename> typename Container=std::vector>
  explicit Tree(Container<std::optional<T>> &&xs) : node{TreeNode<T>::build(std::move(xs), 1)} {}

  Tree(std::initializer_list<std::optional<T>> il) : node{
      TreeNode<T>::build(std::vector<std::optional<T>>(il.begin(), il.end()), 1)} {}

  explicit Tree(TreeNode<T> *node) : node{node} {}

  ~Tree() {
    TreeNode<T>::release(node);
  }

  inline operator TreeNode<T> *() {
    return node;
  }

  inline TreeNode<T> *operator->() {
    return node;
  }

  bool operator==(const Tree<T> &rhs) const {
    TreeNode<T>::is_same(node, rhs.node);
  }

  TreeNode<T> *node;
};

template<typename T>
struct ListNode {
  explicit ListNode(T x) : val{x}, next{nullptr} {}
  ListNode(T x,  ListNode<T> *next) : val{x}, next{next} {}

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

  template<template<typename> typename Container=std::vector>
  static ListNode<T> *build(const Container<T> &xs) {
    ListNode<T> *head = nullptr, *current = nullptr;
    for (auto iter = xs.cbegin(); iter != xs.cend(); iter++) {
      if (head == nullptr) {
        head = current = new ListNode<T>(*iter);
      } else {
        current->next = new ListNode<T>(*iter);
        current = current->next;
      }
    }
    return head;
  }

  static size_t size(ListNode<T> *xs) {
    size_t length = 0;
    while (xs != nullptr) {
      xs = xs->next;
      length += 1;
    }
    return length;
  }

  T val;
  ListNode *next;
};

template<typename T>
struct List {
  template<template<typename> typename Container=std::vector>
  explicit List(const Container<T> &xs) : node{ListNode<T>::build(xs)}{}

  template<template<typename> typename Container=std::vector>
  explicit List(const Container<T> &&xs) : node{ListNode<T>::build(std::move(xs))}{}

  explicit List(std::initializer_list<T> il) : node{ListNode<T>::build(std::vector<T>(il.begin(), il.end()))} {}

  inline operator ListNode<T> *() {
    return node;
  }

  std::vector<T> to_list() const {
    ListNode<T> *head = node;
    std::vector<T> xs;
    while (head != nullptr) {
      xs.push_back(head->val);
      head = head->next;
    }
    return xs;
  }

  ListNode<T> *node;
};

}

enum Category {
  /** 线性结构 */
  Array, LinkedList, Stack, Heep, Queue, String,
  /** 查找表 */
  Map, HashTable,
  /** 树 */
  Trees, BinaryTree, BinarySearchTree, Trie,
  /** 图 */
  Graph, DFS, BFS, TopRecursion, Pointers, TologicalSort,
  /** 方法 */
  DivideAndConquer, DynamicProgramming, Backtracking, ReservoirSampling, Greedy, Memorization,
  /** 设计 */
  Design,
  /** 专项 */
  BinarySearch, Sort, BitManipulation, Minimax, Implement,
  /** 数学 */
  Geometry, Math,
  /** 其他 */
  Misc
};

namespace LeetCode {

struct SolutionDescriptor {
  SolutionDescriptor() = default;
  SolutionDescriptor(const SolutionDescriptor &descriptor);
  SolutionDescriptor(SolutionDescriptor &&descriptor) noexcept;
  SolutionDescriptor(size_t id, std::string &&path, std::string &&title, std::vector<Category> &&categories);
  SolutionDescriptor &operator=(const SolutionDescriptor &descriptor);
  size_t id = 0;
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
  SolutionDescriptorInjector(size_t id,
                             std::string &&path,
                             std::string &&title,
                             std::vector<Category> &&categories);
};

template<typename Solution, typename Body>
struct TestBody {
  explicit TestBody(Body body) : s{}, body{body} {};
  TestBody (TestBody& tb) : s{tb.s}, body{tb.body} {};
  Solution s;
  Body body;
};

}

using ListNode = LeetCode::ListNode<int>;
using List = LeetCode::List<int>;
using TreeNode = LeetCode::TreeNode<int>;
using Tree = LeetCode::Tree<int>;

#define DESCRIPTION(id, title, ...) \
  static const LeetCode::SolutionDescriptorInjector __descriptor__(id, __FILE__, title, {__VA_ARGS__})

#define TEST_BODY(test_case, test_name) __test_body_##test_case##test_name##__

#define TEST(test_case, test_name)                                                                          \
  void TEST_BODY(test_case, test_name)(Solution &);                                                         \
  GTEST_TEST(test_case, test_name) {                                                                        \
    LeetCode::TestBody<Solution, std::function<void(Solution&)>> __test__{TEST_BODY(test_case, test_name)}; \
    __test__.body(__test__.s);                                                                              \
  }                                                                                                         \
  void TEST_BODY(test_case, test_name)(Solution &s)

