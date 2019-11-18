#include "ThreadedBinaryTree.h"

template <class T>
ThreadedTree<T>::ThreadedTree()
{
    root = new ThreadedNode<T>();
    root->leftThread = false;
    root->rightThread = false;
    root->rightChild = root;
    root->leftChild = root;
}

template <class T>
T* ThreadedTree<T>::ThreadedInorderIterator::Next()
{
    ThreadedNode<T> *temp = currentnode->rightChild;
    if (!temp->rightThread)
        while (temp->leftThread)
            temp = temp->leftChild;
    currentnode = temp;
    if (currentnode == root)
        return 0;
    else
        return &currentnode->data;
}

template <class T>
void ThreadedTree<T>::InsertRight(ThreadedNode<T>*s, ThreadedNode<T>*r)
{
    // Insert r as the right child of s.
    r->rightChild = s->rightChild;
    r->rightThread = s->rightThread;
    r->leftChild = s;
    r->leftChild = true;
    s->rightChild = r;
    s->rightThread = false;
    if (r->rightThread) {
        // returns the inorder successor of r
        ThreadedNode<T> *temp = InorderSucc(r);
        temp->leftChild = r;
    }
}

template <class T>
ThreadedNode<T> *ThreadedTree<T>::InorderSucc(ThreadedNode<T>* currentNode) const
{
    ThreadedNode<T> *temp = currentNode->rightChild;
    if (!currentNode->rightThread)
        while (!temp->leftThread)
            temp = temp->leftChild;
    if (temp == root)
        return nullptr;
    else
        return temp; 
}

template <class T>
ThreadedNode<T> *ThreadedTree<T>::InorderPres(ThreadedNode<T>*currentNode) const
{
    ThreadedNode<T> *temp = currentNode->leftChild;
    if (!currentNode->leftThread)
        while (!temp->rightThread)
            temp = temp->rightChild;
    if (temp == root)
        return nullptr;
    else
        return temp;
}
