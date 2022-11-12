//
// Created by Wing Yin Chan on 14/9/2021.
//
#ifndef DOUBLE_LINKEDLIST_LINKEDLIST_CPP
#define DOUBLE_LINKEDLIST_LINKEDLIST_CPP
#include "LinkedList.h"

template<class T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}
template<class T>
LinkedList<T>::LinkedList(const LinkedList& list)
{
    *this = list;
}

template<class T>
LinkedList<T>::~LinkedList()
{
    while(head != nullptr)
        remove(head);
}

template<class T>
int LinkedList<T>::getSize() const {
    return size;
}

template<class T>
bool LinkedList<T>::empty() const {
    return (head == nullptr && tail == nullptr);
}

template<class T>
void LinkedList<T>::push_front(T item) {
    Node<T>* n = new Node<T>;
    if(empty())
    {
        n->data = item;
        head = n;
        tail = n;
        n->prev = nullptr;
        n->next = nullptr;
    } else
    {
        n->data = item;
        n->prev = nullptr;
        n->next = head;
        head->prev = n;
        head = n;
    }
    size++;
}

template<class T>
void LinkedList<T>::push_back(T item) {
    if(empty())
        push_front(item);
    else
    {
        Node<T>* n = new Node<T>;
        n->data = item;
        n->next = nullptr;
        tail->next = n;
        n->prev = tail;
        tail = n;
        size++;
    }
}

template<class S>
std::ostream& operator<<(std::ostream& out, const LinkedList<S>& list){
    Node<S>* temp = list.head;
    while(temp!= nullptr)
    {
        out<<temp->data<<" ";
        temp = temp->next;
    }
    return out;
}

template<class T>
Node<T> *LinkedList<T>::search(T item) {
    Node<T>* temp = head;
    if(empty())
        return temp;
    else
        {
        while (temp->data != item)
        {
            temp = temp->next;
            if (temp == nullptr)
                return temp;
        }
        return temp;
        }
}

template<class T>
void LinkedList<T>::insertAfter(T item, T after) {
    Node<T>* node = search(after);
    insertAfter(item, node);
}

template<class T>
void LinkedList<T>::insertBefore(T item, T before) {
    Node<T>* node = search(before);
    if(node == head)
        push_front(item);
    else
        insertAfter(item, node->prev);
}


template<class T>
void LinkedList<T>::insertAfter(T item, Node<T> *target) {
    if(target == tail)
        push_back(item);
    else
    {
        Node<T>* n = new Node<T>;
        n->data = item;
        target->next->prev = n;
        n->next = target->next;
        n->prev = target;
        target->next = n;
        size++;
    }
}

template<class T>
void LinkedList<T>::remove(T item) {
    Node<T>* node = search(item);
    if(find(item))
    {
        remove(node);
    }
    else
        std::cout<<"item cannot be removed"<<std::endl;
}

template<class T>
void LinkedList<T>::remove(Node<T> *target) {
    if(size == 1)
    {
        delete target;
        head = nullptr;
        tail = nullptr;
    }
    else if(target == head)
    {
        head->next->prev = nullptr;
        head = target->next;
        delete target;
    } else if(target == tail)
    {
        tail->prev->next = nullptr;
        tail = target->prev;
        delete target;
    } else
    {
        target->prev->next = target->next;
        target->next->prev = target->prev;
        delete target;
    }
    size--;
}

template<class T>
bool LinkedList<T>::find(T item) {
    if(search(item) == nullptr)
        return false;
    else
        return true;
}

template<class T>
void LinkedList<T>::clear() {
    while(head != nullptr)
        remove(head);
}

template<class T>
void LinkedList<T>::operator+=(T item) {
    push_back(item);
}

template<class T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList &list) {
    if(this == &list)
        return *this;
    else
    {
        this->~LinkedList();
        this->head = nullptr;
        this->tail = nullptr;
        Node<T>* walker = list.head;
        while(walker != nullptr)
        {
            this->push_back(walker->data);
            walker = walker->next;
        }
    }
    return *this;
}

template<class T>
typename LinkedList<T>::iterator LinkedList<T>::begin() {
    return Node_Iterator<T>(head);
}

template<class T>
typename LinkedList<T>::iterator LinkedList<T>::end() {
    return Node_Iterator<T>();
}

template<class T>
void LinkedList<T>::pop_back() {
    remove(tail);
}

template<class T>
void LinkedList<T>::pop_front() {
    remove(head);
}

template<class T>
T LinkedList<T>::back() {
    assert(!empty());
    return tail->data;
}

template<class T>
T LinkedList<T>::front() {
    assert(!empty());
    return head->data;
}

template<class T>
typename LinkedList<T>::iterator LinkedList<T>::begin() const {
    return Node_Iterator<T>(head);
}

template<class T>
typename LinkedList<T>::iterator LinkedList<T>::end() const {
    return Node_Iterator<T>();
}

template<class T>
typename LinkedList<T>::iterator LinkedList<T>::rbegin() {
    return Node_Iterator<T>(tail);
}


#endif