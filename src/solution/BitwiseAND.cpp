#if (defined(OFFLINE))
#include "leet/structure.hpp"
namespace X201 {
#endif

struct integer_info {
  int fst, rem, digits;
  bool operator==(const integer_info &rhs) {
    return fst == rhs.fst and
           rem == rhs.rem and
           digits == rhs.digits;
  }
};

inline static integer_info info(const int value) {
  integer_info ii;
  if (value == 0) {
    ii = {0, 0, 0};
  } else {
    int fst = 1, digits = 0;
    while (value - fst >= fst) {
      fst <<= 1;
      digits += 1;
    }
    const int rem = value - fst;
    ii = {fst, rem, digits};
  }
  return ii;
};

class Solution {
 public:
  int rangeBitwiseAnd(int m, int n) {
    if (m == 0) {
      return 0;
    }
    if (m == n) {
      return m;
    }
    const integer_info mi = info(m), ni = info(n);
    return ni.digits == mi.digits ? mi.fst + rangeBitwiseAnd(mi.rem, ni.rem) : 0;
  }
};

#if (defined(OFFLINE))
}
#endif