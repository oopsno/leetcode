#include <set>

#if (defined(OFFLINE))
#include "leet/structure.hpp"
namespace X217 {
#endif

class Solution {
 public:
  bool containsDuplicate(std::vector<int> &nums) {
    return std::set<int>(nums.cbegin(), nums.cend()).size() < nums.size();
  }
};

#if (defined(OFFLINE))
}
#endif