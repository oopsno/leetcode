/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

#include <functional>
#include <stack>
#include <string>
#include <vector>

// @lc code=start
class Solution {
 private:
  template <template <typename> typename Operator>
  void eval(std::stack<int>& s) {
    const int rhs = s.top();
    s.pop();
    const int lhs = s.top();
    s.pop();
    s.push(Operator<int>()(lhs, rhs));
  }

 public:
  int evalRPN(const std::vector<std::string>& tokens) {
    std::stack<int> s;
    for (const auto& token : tokens) {
      if (token == "+") {
        eval<std::plus>(s);
      } else if (token == "-") {
        eval<std::minus>(s);
      } else if (token == "*") {
        eval<std::multiplies>(s);
      } else if (token == "/") {
        eval<std::divides>(s);
      } else {
        s.push(std::atoi(token.c_str()));
      }
    }
    return s.top();
  }
};
// @lc code=end
