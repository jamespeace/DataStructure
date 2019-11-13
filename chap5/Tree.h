#ifndef _TREE_H_
#define _TREE_H_

#include "../chap3/cpp/Stack/Stack.h"
template <class T>
class Tree; // forward declaration.

template <class T>
class TreeNode {
    friend class Tree<T>;
public:
    TreeNode(T data = 0, TreeNode<T> *leftChild = 0, TreeNode<T> *rightChild = 0);
private:
    T data;
    TreeNode<T> *leftChild;
    TreeNode<T> *rightChild;
};

template <class T>
class Tree {
public:
    class InorderIterator {
    public:
        InorderIterator() {currentNode = root;}
        T* Next();
    private:
        Stack<TreeNode<T>*> s;
        TreeNode<T> *currentNode;
    };
    //  Tree operations.
    void Inorder();
    void LevelOrder();
    void SetRoot(TreeNode<T> *r) {root = r;}

private:
    // Tree operations.
    void Inorder(TreeNode<T> *root);
    void Visit(TreeNode<T> *);
    void NonrecInorder();
    TreeNode<T> *root;
};


#endif
