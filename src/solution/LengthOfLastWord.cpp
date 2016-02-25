#include <string>

#if (defined(OFFLINE))
#include "leet/structure.hpp"
namespace X58 {
#endif

class Solution {
 public:
  static int lengthOfLastWord(const std::string &s) {
    const char *data = s.c_str();
    int i;
    int count = 0;
    for (i = int(s.size() - 1); i >= 0; --i) {
      if (data[i] == ' ') {
        continue;
      } else {
        break;
      }
    }
    for (; i >= 0; --i) {
      if (data[i] != ' ') {
        count += 1;
      } else {
        break;
      }
    }
    return count;
  }
};

#if (defined(OFFLINE))
}
#endif