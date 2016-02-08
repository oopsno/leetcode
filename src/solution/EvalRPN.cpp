#include <string>

#if (defined(OFFLINE))
#include "leet/structure.hpp"
namespace X150 {
#endif

class Solution {
 public:
  Solution() : stack(new int[stack_size]) { }
  ~Solution() {
    delete[](stack);
  }
  int evalRPN(const std::vector<std::string> &tokens) {
    if (tokens.size() > stack_size) {
      delete[](stack);
      stack = new int[tokens.size()];
      stack_size = tokens.size();
    }
    for (const std::string &token : tokens) {
      const char first = token.front();
      if (std::isdigit(first) || token.size() > 1) {
        stack[++top] = std::stoi(token);
      } else {
        int rhs = stack[top--];
        operate(first, stack[top], rhs);
      }
    }
    return stack[top--];
  }
 private:
  static inline void operate(const char op, int &lhs, int rhs) {
    switch (op) {
      case '+':
        lhs += rhs;
        break;
      case '-':
        lhs -= rhs;
        break;
      case '*':
        lhs *= rhs;
        break;
      case '/':
        lhs /= rhs;
        break;
      default:
        break;
    };
  }
  size_t stack_size = 1 << 18; // 128K will cover all test cases...
  int *stack;
  int top = 0;
};

#if (defined(OFFLINE))
}
#endif