#ifndef _LINKEDQUEUE_H_
#define _LINKEDQUEUE_H_

#include "ChainNode.h"

template <class T>
class LinkedQueue {
public:
    LinkedQueue();
    ~LinkedQueue();
    bool IsEmpty() const;
    T& Front() const;
    T& Rear() const;
    void Push(const T& e);
    void Pop();
private:
    ChainNode<T> *front;
    ChainNode<T> *rear;
};

#endif