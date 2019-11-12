#include "CircularList.h"

template <class T>
void CircularList<T>::InsertFront(const T& e)
{
    // Insert the element e at the "front" of the circular
    // list *this, where last points to the last node in the list.
    ChainNode<T> *newNode = new ChainNode<T>(e);
    if (last != head) {
        newNode->link = last->link;
        last->link = newNode;
    } else {
        last = newNode;
        newNode->link = head;
        head->link = newNode;
    }
}

template <class T>
ChainNode<T>* CircularList<T>::GetNode()
{
    // Provide a node for use.
    ChainNode<T> *x;
    if (av) {
        x = av; av = av->link;
    } else {
        x = new ChainNode<T>;
    }
    return x;
}


template <class T>
void CircularList<T>::RetNode(ChainNode<T>* &x)
{
    // Free the node pointed to by x.
    x->link = av;
    av = x;
    x = 0;
}

template <class T>
CircularList<T>::~CircularList()
{
    // Delete the circular list.
    if (last) {
        ChainNode<T> *first = last->link;
        last->link = av;
        av = first->link; // first is head. The effective data is at head->link.
        last = 0;
    }
    delete head;
}