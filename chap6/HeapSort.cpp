#include <iostream>
#include <iomanip>
#include <utility>
using namespace std;

/*
    Adjust binary tree with root root to satisfy heap property. The left and right
    subtrees of root already satisfy the heap property. No node index is > n.
*/
template <class T>
void Adjust(T *a, const int root, const int n)
{
    int j;
    T e = a[root];
    // find proper place for e
    for (j = 2*root; j <= n; j *= 2) {
        if (j < n && a[j] < a[j+1]) 
            j++; // j is max child of its parent
        if (e >= a[j])
            break;
        a[j/2] = a[j]; // move jth record up the tree
    }
    a[j/2] = e;
}

/*
    Sort a[1:n] into nondecreasing order.
*/
template <class T>
void HeapSort(T *a, const int n)
{
    int i;
    for (i = n/2; i>=1; i--) // heapify
        Adjust(a, i, n);

    for (i = n-1; i >= 1; i--) {// sort
        cout << setw(2) << a[1] << ",";
        swap(a[1],a[i+1]);  // swap first and last of current heap
        Adjust(a, 1, i);    // heapify
    }
}