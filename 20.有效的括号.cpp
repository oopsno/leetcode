/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include <stack>
#include <string>

class Solution {
private:
  static void push(std::stack<int> &stack, int id) noexcept { stack.push(id); }
  static bool pop(std::stack<int> &stack, int id) noexcept {
    if (stack.empty() or stack.top() != id) {
      return false;
    } else {
      stack.pop();
      return true;
    }
  }

public:
  bool isValid(const std::string &s) const noexcept {
    constexpr int LP = 1, LS = 2, LB = 3;
    if (s.empty()) {
      return true;
    }
    std::stack<int> stack;
    for (char c : s) {
      switch (c) {
        case '(': push(stack, LP); break;
        case '[': push(stack, LS); break;
        case '{': push(stack, LB); break;
        case ')': if (not pop(stack, LP)) return false; break;
        case ']': if (not pop(stack, LS)) return false; break;
        case '}': if (not pop(stack, LB)) return false; break;
      }
    }
    return stack.empty();
  }
};
// @lc code=end
