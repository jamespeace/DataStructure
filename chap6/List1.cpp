#include <utility>
using namespace std;
/*
    Rearrange the sorted chain beginning at first so that the records a[1:n]
    are in sorted order.
    */
template <class T>
void List1(T *a, int *linka, const int n, int first)
{
    int *linkb = new int [n+1]; // array for backward links
    int prev = 0;
    for (int current = first; current; current = linka[current]) {
        // convert chain into a doubly linked list
        linkb[current] = prev;
        prev = current;
    }

    // move a[first] to position i while
    // maintaining the list
    for (int i = 1; i < n; i++) {
        if (first != i) {
            if (linka[i] != 0)
                linkb[linka[i]] = first;
            linka[linkb[i]] = first;
            swap(a[first], a[i]);
            swap(linka[first], linka[i]);
            swap(linkb[first], linkb[i]);
        }
        first = linka[i];
    }
}
