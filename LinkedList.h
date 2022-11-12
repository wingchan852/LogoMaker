//
// Created by Wing Yin Chan on 14/9/2021.
//

#ifndef DOUBLE_LINKEDLIST_LINKEDLIST_H
#define DOUBLE_LINKEDLIST_LINKEDLIST_H
#include "Node.h"
#include <iostream>
#include "Node_Iterator.h"
#include <assert.h>
template<class T>
class LinkedList {
public:
    typedef Node_Iterator<T> iterator;
    LinkedList();
    LinkedList(const LinkedList& list);
    ~LinkedList();
    bool empty() const;
    int getSize() const;
    void push_back(T item);
    void push_front(T item);
    void insertBefore(T item, T before);
    void insertAfter(T item, T after);
    void remove(T item);
    bool find(T item);
    void pop_back();
    void pop_front();
    void clear();
    template<class S>
    friend std::ostream& operator<<(std::ostream& out, const LinkedList<S>& list);
    void operator+=(T item);
    LinkedList<T>& operator=(const LinkedList& list);
    iterator begin();
    iterator rbegin();
    iterator begin() const;
    iterator end() const;
    iterator end();
    T back();
    T front();
private:
    void insertAfter(T item, Node<T>* target);
    void remove(Node<T>* target);
    Node<T>* search(T item);
    Node<T>* head;
    Node<T>* tail;
    int size;
};

#include "LinkedList.cpp"

#endif //DOUBLE_LINKEDLIST_LINKEDLIST_H
