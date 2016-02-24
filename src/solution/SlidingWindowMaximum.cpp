#include <iterator>
#include <algorithm>
#include <vector>

#if (defined(OFFLINE))
#include "leet/structure.hpp"
namespace X239 {
#endif

class Solution {
 public:
  typedef int *it_t;
  typedef const int *cit_t;

  std::vector<int> maxSlidingWindow(const std::vector<int> &nums, const int k) {
    if (k == 0 || nums.empty()) {
      return nums;
    }
    if (k == 1) {
      return nums;
    }
    const size_t size = nums.size() - k + 1;
    cit_t head = nums.data();
    cit_t hop = head + k;
    const cit_t stop = head + size;
    std::vector<int> swmax(size);
    it_t it = swmax.data();
    while (head != stop) {
      *it++ = *std::max_element(head++, hop++);
    }
    return swmax;
  }
};

#if (defined(OFFLINE))
}
#endif