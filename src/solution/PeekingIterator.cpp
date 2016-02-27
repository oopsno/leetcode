#if (defined(OFFLINE))
#include "leet/structure.hpp"
#include "leet/iterator.hpp"
namespace X284 {
#endif

#include <stdexcept>

class PeekingIterator: public Iterator {
 private:
  int cache;
  bool cached;
 public:
  PeekingIterator(const std::vector<int> &nums) : Iterator(nums), cached(false) { }

  int peek() {
    if (!cached) {
      if (((Iterator *) this)->hasNext()) {
        cache = ((Iterator *) this)->next();
        cached = true;
      } else {
        throw std::out_of_range("No more elements");
      }
    }
    return cache;
  }

  int next() {
    if (cached) {
      cached = false;
      return cache;
    } else {
      return ((Iterator *) this)->next();
    }
  }

  bool hasNext() const {
    return ((Iterator *) this)->hasNext() || cached;
  }
};

#if (defined(OFFLINE))
}
#endif