#ifndef LEETCODE_ITERATOR_HPP
#define LEETCODE_ITERATOR_HPP

#include <vector>

class Iterator {
 private:
  typedef std::vector<int>::const_iterator it_t;
  it_t cit, end;
 public:
  Iterator(const std::vector<int> &iteration);
  Iterator(const Iterator &it);
  virtual ~Iterator();
  // Returns the next element in the iteration.
  int next();
  // Returns true if the iteration has more elements.
  bool hasNext() const;
};

#endif //LEETCODE_ITERATOR_HPP
