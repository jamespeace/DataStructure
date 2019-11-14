#include "BST.h"
#include "Tree.cpp"

//
// Driver
//

template <class K, class E>
pair<K, E> *BST<K, E>::Get(const K &k) const
{
    return Get(root, k);
}

//
// Workhorse
//
template <class K, class E>
pair<K, E> *BST<K, E>::Get(TreeNode<pair<K, E>>*p, const K &k) const
{
    if (!p) {
        return 0;
    }
    if (k < p->data.first)
        return Get(p->leftChild, k);
    if (k > p->data.first)
        return Get(p->rightChild, k);
    return &p->data;
}
