#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"

template <typename T> class Iterator {
protected:
  Node<T> *current;

public:
  Iterator() : current(nullptr){};
  Iterator(Node<T> *current) : current(current){};

  Iterator<T> operator=(Iterator<T> other) {
    this->current = other.current;
    return *this;
  }
  bool operator!=(Iterator<T> other) {
    return (this->current != other.current);
  }
  T operator*() {
    if (current) {
      return (this->current->data); // Esto no deberías validaro, sino dará warning. En todo caso si validas, dar un throw
    }
  }
};

#endif
