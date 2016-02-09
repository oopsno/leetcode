#include <string>

#if (defined(OFFLINE))
#include "leet/structure.hpp"
namespace X8 {
#endif

class Solution {
 public:
  static int myAtoi(const std::string &str) {
    int64_t value = 0;
    int int_value;
    bool negate = false;
    const char *cursor = str.c_str();
    char current;
    // Discards any whitespace characters
    while (std::isspace(*cursor)) {
      ++cursor;
    }
    // optional plus or minus sign
    current = *cursor;
    if (current == '-') {
      negate = true;
      ++cursor;
    }
    if (current == '+') {
      ++cursor;
    }
    // takes as many characters as possible to form a valid integer number representation
    for (char c = *cursor; c; c = *++cursor) {
      if (std::isdigit(c)) {
        int64_t value_ = value * 10 + c - '0';
        if (value_ >= INT_MAX and not negate) {
          value = INT_MAX;
          break;
        } else if (value_ >= int64_t(INT_MAX) + 1 and negate) {
          value = INT_MIN;
          break;
        } else {
          value = value_;
        }
      } else {
        break;
      }
    }
    if (negate) {
      value = -value;
    }
    return int(value);
  }
};

#if (defined(OFFLINE))
}
#endif