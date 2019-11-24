/**
 * The sorted chains beginning at start1 and start2, respectively, are merged.
 * link[0] is used as a temporary header. Return start of merged chain.
 * **/
template <class T>
int ListMerge(T* a, int *link, const int start1, const int start2)
{
    int iResult = 0; // last record of result chain
    int i1, i2;
    for (i1 = start1, i2 = start2; i1 && i2;)
        if (a[i1] <= a[i2]) {
            link[iResult] = i1;
            iResult = i1;
            i1 = link[i1];
        } else {
            link[iResult] = i2;
            iResult = i2;
            i2 = link[i2];
        }
    // attach remaining records to result chain
    if (i1 == 0)
        link[iResult] = i2;
    else
        link[iResult] = i1;
    return link[0];
}

/**
    a[left:right] is to be sorted. link[i] is initially 0 for all i.
    rMergeSort returns the index of the first element in the sorted  chain.
**/
template <class T>
int rMergeSort(T* a, int *link, const int left, const int right)
{
    if (left >= right)
        return left;
    int mid = (left + right)/2;
    return ListMerge(a, link,
                    rMergeSort(a, link, left, mid),     // sort left half
                    rMergeSort(a, link, mid+1, right));   // sort right half
}
