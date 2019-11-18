#ifndef _MAXHEAP_H_
#define _MAXHEAP_H_

template <class T>
class MaxHeap {
public:
    MaxHeap(int theCapacity = 10);
    void Push(const T& e);
private:
    T *heap;
    int heapSize;
    int capacity;
};

#endif
