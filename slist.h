#ifndef SLIST_H
#define SLIST_H
#include "iterator.h"
#include <iostream>

template <class T> class SListIterator : public Iterator<T> {
public:
  SListIterator() : Iterator<T>(){};
  SListIterator(Node<T> *current) : Iterator<T>(current){};
  SListIterator<T> operator++() {
    if (this->current) {
      this->current = this->current->next;
      return *this;
    }
  }
};

template <typename Tr> class SList {
public:
  typedef typename Tr::T T;
  typedef typename Tr::Operation Operation;
  typedef SListIterator<T> iterator;

private:
  Operation cmp;

  Node<T> *head;

public:
  SList() { head = nullptr; };

  bool find(T search, Node<T> **&pointer) {

    pointer = &head;

    // Tratté de poner "while(*pointer && !cmp(...) ) pero siempre evalueaba el
    // segundo argumento, lo cual no tiene sentido"
    while (*pointer) {
      if (!cmp(search, (*pointer)->data)) {
        break;
      }

      pointer = &((*pointer)->next);
    }
    return ((*pointer)->data == search);
  }

  bool insert(T data) {

    Node<T> **pointer;
    Node<T> *node = new Node<T>(data);
    if (head) {
      if (!(this->find(data, pointer))) {
        node->next = *pointer;
        *pointer = node;
        return true;
      }
      return false;
    } else {
      head = node;
    }
  }

  bool remove(T item) {
    Node<T> **pointer;
    if (this->find(item, pointer)) {
      Node<T> *temp = (*pointer)->next;
      // delete (**pointer);
      *pointer = temp;
      return true;
    } else {
      return false;
    }
  }

  iterator begin() { return iterator(this->head); }

  iterator end() {
    Node<T> *node = nullptr;
    return iterator(node);
  }

  ~SList() {
    if (head) {
      head->killSelf();
    }
  }
};

#endif
