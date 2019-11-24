#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
int digit(T a, int i, const int r)
{
    while (i--)
        a /= r;
    return a % r;
}

/*
    Sort a[1:n] using a d-digit radix-r sort. digit(a[i], j, r) returns the jth radix-r
    digit (from the left) of a[i]'s key. Each digit is in the range is [0, r).
    Sorting within a digit is done using a bin sort.
    */
template <class T>
int RadixSort(T *a, int *link, const int d, const int r, const int n)
{
    int e[r], f[r]; // queue front and end pointers
    int j;

    // create initial chain of records starting at first
    int first = 1;
    for (int i = 1; i < n; i++)
        link[i] = i + 1;  // link into a chain
    link[n] = 0;

    for (int i = 0; i < d; i++) {
        // sort on digit i
        fill(f, f+r, 0);
        for (int current = first; current; current = link[current]) {
            // put records into queues/bins
            int k = digit(a[current], i, r);
            if (f[k] == 0)
                f[k] = current;
            else
                link[e[k]] = current;
                e[k] = current;
        }
        for (j = 0; !f[j]; j++)  // find first nonempty queue/bin
            ;
        first = f[j];
        int last = e[j];
        for (int k = j+1; k < r; k++) // concatenate remaining queues
            if (f[k]) {
                link[last] = f[k];
                last = e[k];
            }
        link[last] = 0;
    }
    return first;
}
