#include <vector>
#include <array>
#include <bitset>
#include <numeric>
#include <functional>

#if (defined(OFFLINE))
#include "leet/structure.hpp"
namespace X136 {
#endif

class Solution {
  /**
   * Given an array of integers, every element appears twice except for one. Find that single one.
   */
 public:
  int singleNumber(std::vector<int> &nums) {
    return std::accumulate(nums.cbegin(), nums.cend(), 0, std::bit_xor<int>());
  }
};

#if (defined(OFFLINE))
}
#endif


#if (defined(OFFLINE))
namespace X137 {
#endif

class Solution {
  /**
   * Given an array of integers, every element appears three times except for one. Find that single one.
   */
 public:
  int singleNumber(std::vector<int> &numbers) {
    constexpr size_t bitwidth = sizeof(int) * 8;
    int counter[bitwidth] = {};
    int result = 0;
    for (int number : numbers) {
      for (uint32_t i = 0, flag = 1; i < bitwidth; ++i, flag <<= 1) {
        counter[i] += (flag & number) != 0;
      }
    }
    for (uint32_t i = 0, flag = 1; i < bitwidth; ++i, flag <<= 1) {
      if (counter[i] % 3 != 0) {
        result |= flag;
      }
    }
    return result;
  }
};

#if (defined(OFFLINE))
}
#endif

#if (defined(OFFLINE))
namespace X260 {
#endif

class Solution {
 public:
  std::vector<int> singleNumber(std::vector<int> &nums) {
    int flag = std::accumulate(nums.begin(), nums.end(), 0, std::bit_xor<int>());
    flag &= -flag;
    std::vector<int> res(2, 0);
    for (auto &a : nums) {
      if (a & flag) {
        res[0] ^= a;
      } else { res[1] ^= a; }
    }
    return res;
  }
};

#if (defined(OFFLINE))
}
#endif
