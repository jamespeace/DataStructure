#include "Bag.h"
#include <algorithm>

using namespace std;


Bag::Bag(int bagCapacity):capacity(bagCapacity) {
    if (bagCapacity < 1) throw "Capacity must be > 0";
    array = new int[capacity];
    top = -1;
}

Bag::~Bag() {delete [] array;}

inline int Bag::Size() const {return top+1;}

inline bool Bag::IsEmpty() const {return Size() == 0;}

inline int Bag::Element() const {
    if (IsEmpty()) throw "Bag is empty";
    return array[0];
}

void Bag::Push(const int x)
{
    if (capacity == top + 1) ChangeSize1D(array, capacity, 2 * capacity);
    capacity *= 2;
    array[++top] = x;
}

void Bag::Pop()
{
    if (IsEmpty()) throw "Bag is empty, cannot delete";
    int deletePos = top/2;
    copy(array+deletePos+1, array+top+1, array+deletePos);
    top--;
}