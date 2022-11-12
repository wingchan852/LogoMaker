//
// Created by Wing Yin Chan on 21/9/2021.
//


#ifndef DOUBLE_LINKEDLIST_NODE_ITERATOR_CPP
#define DOUBLE_LINKEDLIST_NODE_ITERATOR_CPP
#include "Node_Iterator.h"

template<class T>
Node_Iterator<T>::Node_Iterator() : current(nullptr)
{

}

template<class T>
Node_Iterator<T>::Node_Iterator(Node<T> *current) : current(current)
{

}

template<class T>
Node_Iterator<T>& Node_Iterator<T>::operator++() {
    current = current->next;
    return *this;
}

template<class T>
Node_Iterator<T> Node_Iterator<T>::operator++(int) {
    Node<T>* temp = current;
    temp = temp->next;
    return Node_Iterator<T>(temp);
}

template<class T>
Node_Iterator<T>& Node_Iterator<T>::operator--() {
    current = current->prev;
    return *this;
}

template<class T>
Node_Iterator<T> Node_Iterator<T>::operator--(int) {
    Node<T>* temp = current;
    temp = temp->prev;
    return Node_Iterator<T>(temp);
}

template<class T>
T& Node_Iterator<T>::operator*() {
    return current->data;
}

template<class T>
const T& Node_Iterator<T>::operator*() const {
    return current->data;
}

template<class S>
bool operator==(const Node_Iterator<S> &L, const Node_Iterator<S> &R) {
    return (L.current == R.current);
}

template<class S>
bool operator!=(const Node_Iterator<S> &L, const Node_Iterator<S> &R) {
    return (L.current != R.current);
}


#endif