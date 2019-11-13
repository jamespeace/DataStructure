#include "Bag_template.h"
#include <algorithm>

using namespace std;

template <class T>
Bag<T>::Bag(int bagCapacity):capacity(bagCapacity) {
    if (bagCapacity < 1) throw "Capacity must be > 0";
    array = new T[capacity];
    top = -1;
}

template <class T>
Bag<T>::~Bag() {delete [] array;}

template <class T>
inline int Bag<T>::Size() const {return top+1;}

template <class T>
inline bool Bag<T>::IsEmpty() const {return Size() == 0;}

template <class T>
inline T& Bag<T>::Element() const {
    if (IsEmpty()) throw "Bag is empty";
    return array[0];
}

template <class T>
void Bag<T>::Push(const T& x)
{
    if (capacity == top + 1) ChangeSize1D(array, capacity, 2 * capacity);
    capacity *= 2;
    array[++top] = x;
}

template <class T>
void Bag<T>::Pop()
{
    if (IsEmpty()) throw "Bag is empty, cannot delete";
    int deletePos = top/2;
    copy(array+deletePos+1, array+top+1, array+deletePos);
    top--;
}