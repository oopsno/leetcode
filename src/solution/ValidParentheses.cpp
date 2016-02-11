#include <string>

#if (defined(OFFLINE))
#include "leet/structure.hpp"
namespace X20 {
#endif

class Solution {
 public:
  Solution() : stack(new char[size]) { }
  ~Solution() {
    delete[](stack);
  }
  bool isValid(std::string s) {
    int cursor = 0;
    char current;
    if (s.size() > size) {
      delete[](stack);
      size = s.size();
      stack = new char[size];
    }
    const char *str = s.c_str();
    while ((current = *str++)) {
      switch (current) {
        case '(': case '[': case '{':
          stack[++cursor] = current;
          break;
        case ')':
          if (stack[cursor] == '(') {
            --cursor;
          } else {
            return false;
          }
          break;
        case ']': case '}':
          if (stack[cursor] == current - 2) {
            --cursor;
          } else {
            return false;
          }
        default:
          continue;
      }
    }
    return cursor == 0;
  }
 private:
  size_t size = 1 << 16; // 32K
  char *stack;
};

#if (defined(OFFLINE))
}
#endif