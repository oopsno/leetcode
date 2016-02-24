#include <iterator>
#include <algorithm>
#include <vector>

#if (defined(OFFLINE))
#include "leet/structure.hpp"
namespace X239 {
#endif

class Solution {
 public:
  typedef std::vector<int>::iterator it_t;
  typedef std::vector<int>::const_iterator cit_t;

  std::vector<int> maxSlidingWindow(const std::vector<int> &nums, const int k) {
    if (nums.empty()) {
      return nums;
    }
    if (k == 1) {
      return nums;
    }
    const size_t size = nums.size() - k + 1;
    cit_t head = nums.cbegin();
    cit_t hop = nums.cbegin() + k;
    const cit_t stop = nums.cbegin() + size;
    std::vector<int> swmax(size);
    it_t it = swmax.begin();
    while (head != stop) {
      *it++ = *std::max_element(head++, hop++);
    }
    return swmax;
  }
};

#if (defined(OFFLINE))
}
#endif