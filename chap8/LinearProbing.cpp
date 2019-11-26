#include "LinearProbing.h"

/*
    Search the linear probing hash table ht(each bucket has exactly one slot) for k.
    If a pair with this key is found, return a pointer to this pair; otherwise, return 0.
    */
template <class K, class E>
pair<K, E>* LinearProbing<K, E>::Get(const K& k)
{
    int i = h(k); // home bucket
    int j;
    for (j = i; ht[j] && ht[j]->first != k;) {
        j = (j + 1) % b;    // treat the table as circular
        if (j == i)
            return 0;       // back to start point
    }
    if (ht[j]->first == k)
        return ht[j];
    return 0;
}
