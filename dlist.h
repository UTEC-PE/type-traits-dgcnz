#ifndef DLIST_H
#define DLIST_H

#include "iterator.h"

template <typename T> class DListIterator : public Iterator<T> {
public:
  DListIterator() : Iterator<T>(){};
  DListIterator(Node<T> *current) : Iterator<T>(current){};
  DListIterator<T> operator++() {
    if (this->current) {
      this->current = this->current->next;
      return *this;
    }
  }
  DListIterator<T> operator--() {
    if (this->current) {
      this->current = this->current->prev;
      return *this;
    }
  }
};

template <typename Tr> class DList {
public:
  typedef typename Tr::T T;
  typedef DListIterator<T> iterator;

private:
  Node<T> *head;
  Node<T> *tail;

public:
  DList() { head = tail = nullptr; };

  void push_front(T data) {

    Node<T> *node = new Node<T>(data);

    node->next = this->head;
    if (head) {
      this->head->prev = node;
      this->head = node;
    } else {
      this->head = this->tail = node;
    }

    node->prev = nullptr;
  }

  void push_back(T data) {

    Node<T> *node = new Node<T>(data);
    node->next = nullptr;

    node->prev = this->tail;
    if (this->head) {
      this->tail->next = node;
      this->tail = node;

    } else {
      this->head = this->tail = node;
    }
  }

  void pop_front() {
    if (!(this->head)) {
      return;
    } else if (this->head && this->head->next) {
      this->head = this->head->next;
      delete (this->head->prev);
    } else {
      delete (this->head);
    }
  }

  void pop_back() {
    if (!(this->head)) {
      return;
    } else if (this->head && this->head->next) {
      this->tail = this->tail->prev;
      delete (this->tail->next);
    } else {
      delete (this->head);
    }
  }

  iterator begin() { return (iterator(this->head)); }

  iterator end() { return (iterator(nullptr)); }

  ~DList() {
    if (head) {
      head->killSelf();
    }
  }
};

#endif
