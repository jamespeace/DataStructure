#include "MaxHeap.h"

template <class T>
void ChangeSize1D(T*& a, const int oldSize, const int newSize)
{
    if (newSize < 0) throw "New length must be > 0";

    T* temp = new T[newSize];
    int number = min(oldSize, newSize);
    copy(a, a+ number, temp);
    delete []a;
    a = temp;
}

template <class T>
MaxHeap<T>::MaxHeap(int theCapacity = 10)
{
    if (theCapacity < 1) throw "Capacity must be >= 1";
    capacity = theCapacity;
    heapSize = 0;
    // heap[0] is not used
    heap = new T[capacity+1];
}

template <class T>
void MaxHeap<T>::Push(const T& e)
{
    if (heapSize == capacity) { // double the capacity
        ChangeSize1D(heap, capacity, 2*capacity);
        capacity *= 2;
    } 
    int currentNode = ++heapSize;
    while (currentNode != 1 && heap[currentNode / 2] < e) {
        // bubble up
        heap[currentNode] = heap[currentNode/2]; // move parent down
        currentNode /= 2;
    }
    heap[currentNode] = e;
}

template <class T>
void MaxHeap<T>::Pop()
{
    // Delete max element.
    if (IsEmpty()) throw "Heap is empty. Cannot delete.";
    heap[1].~T()    // delete max element.

    // remove last element from heap
    T lastE = heap[heapSize] - 1;

    // trickle down
    int currentNode = 1;    // root
    int child = 2;          // a child of currentNode
    while (currentNode <= heapSize) {
        // set child to larger child of currentNode
        if (child <heapSize && heap[child] < heap[child+1])
            child++;
        
        // can we put lastE in currentNode?
        if (lastE >= heap[child])
            break; // yes

        // no
        heap[currentNode] = heap[child];
        currentNode = child;
        child *= 2;
    }
    heap[currentNode] = lastE;
}
