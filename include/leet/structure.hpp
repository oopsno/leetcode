#ifndef LEETCODE_STRUCTURE_HPP
#define LEETCODE_STRUCTURE_HPP

#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) { }

  /* OFFLINE UILITIES */
  ListNode(std::initializer_list<int> elements);
  static ListNode *build(const std::vector<int> &elements);
  static void release(ListNode* list);
  typedef std::vector<int> vec_t;
  vec_t *dump() const;
  size_t size() const;
  int operator[](const int index);
};


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }

  /* OFFLINE UILITIES */
  static TreeNode *build(const std::vector<int> &elements);
  std::vector<int> *dump() const;
};


#endif //LEETCODE_STRUCTURE_HPP
