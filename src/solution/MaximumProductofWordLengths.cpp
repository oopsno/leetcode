#include <string>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#if (defined(OFFLINE))
#include "leet/structure.hpp"
namespace X318 {
#endif

class Solution {
 public:
  struct pair {
    uint32_t letters, length;
  };
  int maxProduct(std::vector<std::string> &words) {
    const size_t words_count = words.size();
    uint64_t *xs = new uint64_t[words_count];
    std::transform(words.cbegin(), words.cend(), xs, set_letters);
    int result = 0;
    for (int i = 0; i < words_count; i++) {
      for (int j = i + 1; j < words_count; j++) {
        result = std::max(result, product(xs[i], xs[j]));
      }
    }
    delete[](xs);
    return result;
  }
  static inline uint64_t set_letters(const std::string &letters) {
    return std::accumulate(letters.cbegin(), letters.cend(), 0ULL, [](uint64_t p, char c) {
      return p | (1ULL << (c - 'a' + 32));
    }) | letters.size();
  }
  static inline std::string get_letters(const uint64_t character) {
    std::string letters;
    uint64_t pattern = 1ULL << 32;
    for (char c = 'a'; c <= 'z'; ++c) {
      if (pattern & character) {
        letters.push_back(c);
      }
      pattern <<= 1;
    }
    return letters;
  }
  static inline int product(const uint64_t lhs, const uint64_t rhs) {
    if (lhs & rhs & (UINT64_MAX - UINT32_MAX)) {
      return 0;
    } else {
      return int(lhs) * int(rhs);
    }
  }
};

#if (defined(OFFLINE))
}
#endif