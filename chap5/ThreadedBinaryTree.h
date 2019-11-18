#ifndef _THREADEDBINARYTREE_H_
#define _THREADEDBINARYTREE_H_

#include "Tree.h"

template <class T>
class ThreadedTree;  // forward declaration 

template <class T>
class ThreadedNode {
public:
    ThreadedNode(T t = 0, ThreadedNode<T> *left = 0, ThreadedNode<T> *right = 0);
private:
    T data;
    ThreadedNode<T> *leftChild;
    ThreadedNode<T> *rightChild;
    bool leftThread;
    bool rightThread;
};

template <class T>
class ThreadedTree {
public:
    class ThreadedInorderIterator {
    public:
        ThreadedInorderIterator() {currentnode = root->leftChild;}
        T* Next();
    private:
        ThreadedNode<T>*currentnode;
    };
    ThreadedTree();
    void InsertRight(ThreadedNode<T>*, ThreadedNode<T>*);
    ThreadedNode<T> *InorderSucc(ThreadedNode<T>*) const;
    ThreadedNode<T> *InorderPres(ThreadedNode<T>*) const;
private:
    ThreadedNode<T> *root;
};

#endif
