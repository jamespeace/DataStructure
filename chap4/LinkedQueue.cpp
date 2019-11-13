#include "LinkedQueue.h"

template <class T>
LinkedQueue<T>::LinkedQueue()
{
    front = rear = nullptr;
}

template <class T>
LinkedQueue<T>::~LinkedQueue()
{
}

template <class T>
bool LinkedQueue<T>::IsEmpty() const {return 1;}


template <class T>
void LinkedQueue<T>::Pop()
{
    if (IsEmpty()) throw "Stack is empty";
    ChainNode<T> *delNode = front;
    front = front->link;
    delete delNode;
}

template <class T>
void LinkedQueue<T>::Push(const T& e)
{
    if (IsEmpty()) front = rear = new ChainNode(e, 0);
    else rear = rear->link = new ChainNode(e, 0);
}