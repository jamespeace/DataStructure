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

template <class K, class E>
void BST<K, E>::Inorder() const
{
    Inorder(root);
    cout << "NULL" << endl;
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

template <class K, class E>
void BST<K, E>::Delete(const K &k)
{
    TreeNode<pair<K, E>> *deleteNode = root;
    TreeNode<pair<K, E>> **delParent = &root;
    // Search the key
    while (deleteNode)
        if (k < deleteNode->data.first) {
            delParent = &deleteNode->leftChild;
            deleteNode = deleteNode->leftChild;
        }
        else if (k > deleteNode->data.first) {
            delParent = &deleteNode->rightChild;
            deleteNode = deleteNode->rightChild;
        } else {
            break;
        }

    if (deleteNode == nullptr) {
        std::cout << "Delete node failed. Cannot find the node." << endl;
        return;
    }
    // node is found
    if (deleteNode->leftChild && deleteNode->rightChild) {
        // Node has 2 children. Use left most child to replace its position.
        TreeNode<pair<K, E>> *pp, *leftmostNode, *p = deleteNode->leftChild;
        while (p->rightChild) {
            pp = p;
            p = p->rightChild;
        }
        leftmostNode = p;
        // Right most node is the root of left sub binary search tree
        if (leftmostNode == deleteNode->leftChild) {
            leftmostNode->rightChild = deleteNode->rightChild;
        } else {
            pp->rightChild = leftmostNode->leftChild;
            leftmostNode->leftChild = deleteNode->leftChild;
            leftmostNode->rightChild = deleteNode->rightChild;
        }
        *delParent = leftmostNode;
    } else {
        // node has 1 or 0 child.
        *delParent = deleteNode->leftChild ? deleteNode->leftChild : deleteNode->rightChild;
    }
    // delete node
    deleteNode->~TreeNode<pair<K, E>>();
}

template <class K, class E>
void BST<K, E>::Inorder(TreeNode<pair<K, E>>*r) const
{
    if (r) {
        Inorder(r->leftChild);
        Visit(r);
        Inorder(r->rightChild);
    }
}

template <class K, class E>
void BST<K, E>::Visit(TreeNode<pair<K, E>>*r) const
{
    cout  << r->data.first << ", ";
}

template <class K, class E>
int BST<K, E>::Height() const
{
    return Height(root);
}

template <class K, class E>
int BST<K, E>::Height(TreeNode<pair<K, E>> *p) const
{
    if (p == nullptr)
        return 0;
    return 1 + max(Height(p->leftChild), Height(p->rightChild));
}
