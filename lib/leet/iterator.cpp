#include "leet/iterator.hpp"

Iterator::Iterator(const std::vector<int> &iteration) : cit(iteration.cbegin()), end(iteration.cend()) { };

Iterator::Iterator(const Iterator &it) : cit(it.cit), end(it.end) { };

Iterator::~Iterator() { }

int Iterator::next() {
  return *cit++;
}

bool Iterator::hasNext() const {
  return cit != end;
}
