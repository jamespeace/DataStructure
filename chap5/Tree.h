#ifndef _TREE_H_
#define _TREE_H_

template <class T>
class Tree;

template <class T>
class TreeNode
{
    friend class Tree<T>;
private:
    T data;
    TreeNode<T> *leftChild;
    TreeNode<T> *rightChild;
};

template <class T>
class Tree {
public:
    // Tree operations.
private:
    void NonrecInorder();
    void LevelOrder();
    TreeNode<T> *root;
};

template <class T>
class InorderIterator {
private:
    T *Next();
};

#endif
