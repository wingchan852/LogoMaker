//
// Created by Wing Yin Chan on 21/9/2021.
//

#ifndef DOUBLE_LINKEDLIST_NODE_ITERATOR_H
#define DOUBLE_LINKEDLIST_NODE_ITERATOR_H
#include <iterator>
#include "Node.h"

template <class T>
class Node_Iterator : public std::iterator<std::bidirectional_iterator_tag, T>{
private:
    Node<T>* current;
public:
    Node_Iterator();
    Node_Iterator(Node<T>* current);
    Node_Iterator& operator++();
    Node_Iterator operator++(int);
    Node_Iterator& operator--();
    Node_Iterator operator--(int);
    T& operator*();
    const T& operator*() const;
    template <class S>
    friend bool operator==(const Node_Iterator<S>& L, const Node_Iterator<S>& R);
    template <class S>
    friend bool operator!=(const Node_Iterator<S>& L, const Node_Iterator<S>& R);
};

#include "Node_Iterator.cpp"
#endif //DOUBLE_LINKEDLIST_NODE_ITERATOR_H
