#include "MaxHeap.h"

template <class T>
MaxHeap<T>::MaxHeap(int theCapacity = 10)
{
    if (theCapacity < 1) throw "Capacity must be >= 1";
    capacity = theCapacity;
    heapSize = 0;
    // heap[0] is not used
    heap = new T[capacity+1];
}
