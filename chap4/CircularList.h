#ifndef _CIRCULARLIST_H_
#define _CIRCULARLIST_H_
#include "ChainNode.h"

template <class T>
class CircularList {
public:
    CircularList() {head = new ChainNode<T>; head->data = 0; head->link = head; last = head;}
    ~CircularList();
    void InsertFront(const T& e);

    // available space lists chap 4.5
    ChainNode<T>* GetNode();
    void RetNode(ChainNode<T>*& x);
private:
    ChainNode<T> *head;
    ChainNode<T> *last;
    static ChainNode<T> *av;
};

template <class T>
ChainNode<T>* CircularList<T>::av;

#endif