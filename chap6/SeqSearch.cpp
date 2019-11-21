template <class E, class K>
int SeqSearch(E *a, const int n, const K& k)
{
    // Search a[1:n] from left to right. Return least i such that
    // the key of a[i] equals k. If there is no such i, return 0.
    int i;
    for (i = 1; i <= n && a[i] != k; i++)
        ;
    if (i > n)
        return 0;
    return i;
}
