#ifndef _LINKEDSTACK_H_
#define _LINKEDSTACK_H_

#include "ChainNode.h"

template <class T>
class LinkedStack {
public:
    LinkedStack();
    bool IsEmpty() const;
    T& Top() const;
    void Push(const T& e);
    void Pop();

private:
    ChainNode<T>  *top;
};
#endif