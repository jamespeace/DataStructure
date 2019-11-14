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

template <class K, class E>
pair<K, E> *BST<K, E>::RankGet(int r)
{
    // Search the binary search tree for the rth smallest pair.
    TreeNode<pair<K, E>>*currentNode = root;
    while (currentNode) {
        if (r < currentNode->leftSize)
            currentNode = currentNode->leftChild;
        if (r > currentNode->rightChild) {
            currentNode = currentNode->rightChild;
            r -= currentNode->leftSize;
        }
        return &currentNode->data;
    }
    return 0;
}

template <class K, class E>
void BST<K, E>::Insert(const pair<K, E> &thePair)
{
    // Insert thePair into the binary search tree
    // Search for thePair.first, pp is parent of p
    TreeNode<pair<K, E>> *p = root, *pp = 0;
    while(p) {
        pp = p;
        if (thePair.first < p->data.first)
            p = p->leftChild;
        else if (thePair.first > p->data.first)
            p = p->rightChild;
        else {
            // duplicate, update associated element
            p->data.second = thePair.second;
            return;
        }
    }
    // perform insertion
    p = new TreeNode<pair<K, E>>(thePair);
    if (root) {
        // root not empty
        if (thePair.first < pp->data.first)
            pp->leftChild = p;
        else
            pp->rightChild = p;
    }
    else
        root = p; 
}
