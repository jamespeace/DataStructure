#include <utility>
using namespace std;

template <class T>
void QuickSort(T *a, const int left, const int right)
{
    // Sort a[left:right] into nondecreasing order.
    // A[left] is arbitrarily chosen as the pivot. Variables i nad j
    // are used to partition the subarray so that at any time a[m] <= pivot, m < i,
    // and a[m] >= pivot, m > j. It is assumed that a[left] <= a[right+1]
    if (left < right) {
        int i = left,
            j = right + 1;

        do {
            do i++; 
                while (a[i] < pivot);
            do j--; 
                while (a[j] > pivot);
            if (i < j) 
                swap(a[i], a[j]);
        } while (i < j);
        swap(a[left], a[j]);

        QuickSort(a, left, j-1);
        QuickSort(a, j+1, right);
    }
}
