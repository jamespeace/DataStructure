template <class T>
void Merge(T *initList, T *mergedList, const int l, const int m, const int n)
{
    // initList[l:m] and initList[m+1:n] are sorted lists. They are merged to obtain
    // the sorted list mergedList[l:m]
    for (int i1 = l, iResult = l, i2 = m+1; // i1, i2, and iResult are list positions
         i1 <= m && i2 <= n; // neither input list is exhausted
         iResult++)
        if (initList[i1] <= initList[l2]) {
            mergedList[iResult] = initList[i1];
            i1++;
        } else {
            mergedList[iResult] = initList[i2];
            i2++;
        }
    // copy remaining records, if any, of first list
    copy(initList + i1, initList + m + 1, mergedList + iResult)
    // copy remaining records, if any, of second list
    copy(initList + i2, initList + n + 1, mergedList + iResult)
}
