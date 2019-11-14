#ifndef _TREE_H_
#define _TREE_H_

#include "../chap3/cpp/Stack/Stack.h"
template <class T>
class Tree; // forward declaration.

template <class K, class E>
class BST;

template <class T>
class TreeNode {
    friend class Tree<T>;
    template <class K, class E>
    friend class BST;

public:
    TreeNode(T t = 0, TreeNode<T> *left = 0, TreeNode<T> *right = 0);
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
    Tree(TreeNode<T> *r = 0);
    void Preorder();
    void Postorder();
    void Inorder();
    void LevelOrder();
    void SetRoot(TreeNode<T> *r) {root = r;}

private:
    // Tree operations.
    void Preorder(TreeNode<T> *currentNode);
    void Postorder(TreeNode<T> *currentNode);
    void Inorder(TreeNode<T> *root);
    void Visit(TreeNode<T> *);
    void NonrecInorder();
    TreeNode<T> *root;
};

#endif
