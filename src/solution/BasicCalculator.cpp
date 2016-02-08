#include <string>
#include <stack>
#if (defined(OFFLINE))
#include "leet/structure.hpp"
namespace X224 {
#endif

class Solution {
 public:
  typedef std::string::const_iterator it_t;

  int calculate(std::string s) {
    it_t cursor = s.cbegin();
    end = s.cend();
    return parse_expr(cursor);
  }
 private:
  inline char next(it_t &cursor) {
    for (char c = *cursor; cursor != end; cursor++, c = *cursor) {
      if (std::isspace(c)) {
        continue;
      }
      return c;
    }
    return '\0';
  }

  int parse_int(it_t &cursor) {
    int value = 0;
    for (char c = next(cursor); cursor != end; cursor++, c = next(cursor)) {
      if (std::isspace(c)) {
        continue;
      } else if (std::isdigit(c)) {
        value *= 10;
        value += c - '0';
        continue;
      } else {
        break;
      }
    }
    return value;
  }

  int parse_atom(it_t &cursor) {
    const char first = next(cursor);
    int atom;
    if (first == '(') {
      cursor++; // pass '('
      atom = parse_expr(cursor);
      cursor++; // pass ')'
    } else {
      atom = parse_int(cursor);
    }
    return atom;
  }

  int parse_expr(it_t &cursor) {
    int lhs = parse_atom(cursor);
    char c;
    while ((c = next(cursor)) && c != ')') {
      char op = next(cursor);
      cursor++;
      int rhs = parse_atom(cursor);
      if (op == '+') {
        lhs += rhs;
      } else {
        lhs -= rhs;
      }
    }
    return lhs;
  }

  it_t end;
};

#if (defined(OFFLINE))
}
#endif