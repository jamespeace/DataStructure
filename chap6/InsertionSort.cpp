#include <iostream>
#include <iomanip>
using namespace std;

template <class T>
void Insert(const T& e, T *a, int i)
{
    // Insert e into the ordered sequence a[1:i] such that the
    // resulting sequence a[1:i+1] is also ordered.
    // The array a must have space allocated for at least i + 2 elements.
    a[0] = e;
    while (e < a[i]) {
        a[i+1] = a[i];
        i--;
    }
    a[i+1] = e;
}

template <class T>
void PrintStatus(T *a, const int n)
{
    for (int i = 1; i <= n; i++)
        cout << setw(2) << a[i] << ", ";
    cout << endl;
}

template <class T>
void InsertionSort(T *a, const int n)
{
    // Sort a[1:n] into nondecreasing order.
    for (int j = 2; j <= n; j++) {
        PrintStatus(a, n);
        T temp = a[j];
        Insert(temp, a, j-1);
    }
    PrintStatus(a, n);
}
