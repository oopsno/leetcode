#include <string>
#include <vector>
#include <numeric>
#include <functional>

#if (defined(OFFLINE))
#include "leet/structure.hpp"
namespace X6 {
#endif

class Solution {
 public:
  struct trace_t {
    const int rows;
    int current = 0;
    bool increasing = false;
    trace_t(int rows) : rows(rows) { }
    int next() {
      if (rows == 1) {
        return 0;
      }
      int n = current;
      if (n == 0 || n == rows - 1) {
        increasing ^= true;
      }
      if (increasing) {
        current += 1;
      } else {
        current -= 1;
      }
      return n;
    }
  };
  std::string convert(std::string s, int numRows) {
    std::vector<std::string> buckets(numRows);
    trace_t trace(numRows);
    for (char c : s) {
      buckets[trace.next()].push_back(c);
    }
    return std::accumulate(buckets.begin(), buckets.end(), std::string(""), std::plus<std::string>());
  }
};

#if (defined(OFFLINE))
}
#endif