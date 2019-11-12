#include "ChainNode.h"

template <class T>
void Chain<T>::Create2()
{
    // create and set fields of second node
    ChainNode<T>* second = new ChainNode<T>(20, nullptr);

    // create and set fields of first node
    first = new ChainNode<T>(10, second);
}

template <class T>
void Chain<T>::Insert50(ChainNode<T>* x)
{
    if (first)
        // Insert after x
        x->link = new ChainNode<T>(50, x->link);
    else
        // insert into empty list
        first = new ChainNode<T>(50);
}

template <class T>
void Chain<T>::Delete(ChainNode<T>* x, ChainNode<T>* y)
{
    if (x == first) first = first->link;
    else y->link = x->link;
    delete x;
}

template <class T>
int Chain<T>::Length()
{
    int len = 0;
    ChainNode<T> *p = first;

    while (p != nullptr) {
        len++;
        p = p->link;
    }
    return len;
}

template <class T>
void Chain<T>::Delete1Node(ChainNode<T>* x)
{
    ChainNode<T> *p = first;

    if (first == nullptr)   throw "first is nullptr.";

    if (x == first) {
        first = new ChainNode<T>(30, nullptr);
    } else {
        while ((p->link != nullptr) && (p->link != x))
            p = p->link;
        if (p->link = nullptr) throw "x is not in Chain";
        p->link = x->link;
    }
    delete x;
}

template <class T>
void Chain<T>::InsertBack(const T& e)
{
    if (first) {
        last->link = new ChainNode<T> (e);
        last = last->link;
    } else
        first = last = new ChainNode<T>(e);
}

template <class T>
void Chain<T>::Concatenate(Chain <T>& b)
{
    if (first) {
        last->link = b.first; last = b.last;
    } else {
        first = b.first; last = b.last;
    }
    b.first = b.last = 0;
}

template <class T>
void Chain<T>::Reverse()
{
    ChainNode<T> *current   = first,
                 *previous  = 0;
    while (current) {
        ChainNode<T> *r = previous;
        previous = current;
        current = current->link;
        previous->link = r;
    }
    first = previous;
}
