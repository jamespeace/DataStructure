#include "LinkedStack.h"

template <class T>
bool LinkedStack<T>::IsEmpty() const {return top == nullptr;}

template <class T>
T& LinkedStack<T>::Top() const {return top->data;}

template <class T>
void LinkedStack<T>::Push(const T& x)
{
    ChainNode<T> *e = new ChainNode<T>;
    e->data = x;
    e->link = top;
    top = e;
}

template <class T>
void LinkedStack<T>::Pop()
{
    if (IsEmpty()) throw "Stack is empty.";
    ChainNode<T> *e = top;
    top = top->link;
    delete e;
}

template <class T>
LinkedStack<T>::LinkedStack()
{
    top = nullptr;
}