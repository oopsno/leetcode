#include <numeric>
#include <cmath>

#if (defined(OFFLINE))
#include "leet/structure.hpp"
namespace X268 {
#endif

class Solution {
 public:
  static inline int sum_up_to(int n) {
    return (n * (1 + n)) / 2;
  }
  int missingNumber(std::vector<int> &nums) {
    /**
     * if nums does not contains 0, then return 0.
     * otherwise, let k = sum(nums),
     * then n(n-1) <= 2k < n(n+1),
     * that is sqrt(8 k+1)-1 < 2n <= sqrt(8k+1)+1
     * n = floor((sqrt(8k+1)+1)/2)
     */
    int sum = 0, max = 0;
    bool meet_zero = false;
    for (int num : nums) {
      if (num == 0) {
        meet_zero = true;
      }
      sum += num;
      max = std::max(max, num);
    }
    if (!meet_zero) {
      return 0;
    }
    const int detected = int(floor((1.0 + std::sqrt(1 + 8 * sum)) / 2));
    if (detected > max) {
      return max + 1;
    } else {
      return sum_up_to(max) - sum;
    }
  }
};

#if (defined(OFFLINE))
}
#endif