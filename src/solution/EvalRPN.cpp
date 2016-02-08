#include <string>
#include <vector>
#include <stack>

#if (defined(OFFLINE))
#include "leet/structure.hpp"
namespace X150 {
#endif

class Solution {
 public:
  int evalRPN(const std::vector<std::string> &tokens) {
    for (std::string token : tokens) {
      const char first = token.front();
      if (std::isdigit(first) || token.size() > 1) {
        stack.push(std::stoi(token));
      } else {
        int rhs = stack.top();
        stack.pop();
        int lhs = stack.top();
        stack.pop();
        stack.push(operate(first, lhs, rhs));
      }
    }
    int result = stack.top();
    stack.pop();
    return result;
  }
 private:
  static int operate(const char op, int lhs, int rhs) {
    int result;
    switch (op) {
      case '+':
        result = lhs + rhs;
        break;
      case '-':
        result = lhs - rhs;
        break;
      case '*':
        result = lhs * rhs;
        break;
      case '/':
        result = lhs / rhs;
        break;
      default:
        result = 0;
    };
    return result;
  }
  std::stack<int> stack;
};

#if (defined(OFFLINE))
}
#endif