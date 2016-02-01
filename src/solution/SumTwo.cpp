#include <map>
#include <vector>
#include <algorithm>

#if (defined(OFFLINE))
#include "leet/structure.hpp"
namespace X1 {
#endif

class Solution {
 public:
  std::vector<int> twoSum(std::vector<int> &nums, int target) {
    int m, n;
    std::map<int, std::vector<int>> record;
    for (int i = 0; i < nums.size(); ++i) {
      record[nums[i]].push_back(i + 1); // value -> index
    }
    for (auto s = record.cbegin(); s != record.cend(); s++) {
      auto t = record.find(target - s->first);
      if (t != record.cend()) {
        const std::vector<int> &vm = s->second;
        const std::vector<int> &vn = t->second;
        if (&vm != &vn) {
          m = vm[0], n = vn[0];
        } else {
          m = vm[0], n = vm[1];
        }
        if (m > n) {
          return {n, m};
        } else {
          return {m, n};
        }
      }
    }
    return {0, 0};
  }
};

#if (defined(OFFLINE))
}
#endif