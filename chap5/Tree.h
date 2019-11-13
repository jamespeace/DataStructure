#ifndef _TREE_H_
#define _TREE_H_

#include "../chap3/cpp/Stack/Stack.h"
template <class T>
class Tree; // forward declaration.

template <class T>
class TreeNode {
    friend class Tree;
public:
private:
    T data;
    TreeNode<T> *leftChild;
    TreeNode<T> *rightChild;
};

template <class T>
class Tree {
public:
    //  Tree operations.
    void Inorder();

private:
    // Tree operations.
    void Inorder(TreeNode<T> *root);
    void Visit(TreeNode<T> *);
    void NonrecInorder();
    void LevelOrder();
    TreeNode<T> *root;
};

template <class T>
class InorderIterator {
public:
    InorderIterator() {currentNode = root;}
    T* Next();
private:
    Stack<TreeNode<T>*> s;
    TreeNode<T> *currentNode;
};

#endif
