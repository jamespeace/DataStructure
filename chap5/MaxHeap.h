#ifndef _MAXHEAP_H_
#define _MAXHEAP_H_

template <class T>
class MaxHeap {
public:
    MaxHeap(int theCapacity = 10);
    void Push(const T& e);
    void Pop();
    bool IsEmpty() {return heapSize == 0;}
private:
    T *heap;
    int heapSize;
    int capacity;
};

#endif
