#include <string>
#if (defined(OFFLINE))
#include "leet/structure.hpp"
namespace X224 {
#endif

class Solution {
 public:
  static int calculate(const std::string &s) {
    it_t cursor = s.c_str();
    return parse_expr(cursor);
  }

 private:
  typedef const char *it_t;

  static inline char next(it_t &cursor) {
    char c = *cursor;
    for (; c == ' '; c = *++cursor);
    return c;
  }

  static inline int parse_int(it_t &cursor) {
    int value = 0;
    for (char c = *cursor; '0' <= c && c <= '9'; c = *++cursor) {
      value = value * 10 + c - '0';
    }
    return value;
  }

  static inline int parse_atom(it_t &cursor) {
    int atom;
    const char first = next(cursor);
    if (first == '(') {
      // eval atom & skip '(' ')'
      atom = parse_expr(++cursor);
      ++cursor;
    } else {
      atom = parse_int(cursor);
    }
    return atom;
  }

  static inline int parse_expr(it_t &cursor) {
    char op;
    int lhs = parse_atom(cursor);
    while ((op = next(cursor)) && op != ')') { // deal with EOF & nested expressions
      // skip operator
      int rhs = parse_atom(++cursor);
      if (op == '+') {
        lhs += rhs;
      } else {
        lhs -= rhs;
      }
    }
    return lhs;
  }
};

#if (defined(OFFLINE))
}
#endif