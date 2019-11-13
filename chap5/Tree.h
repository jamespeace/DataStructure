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
    TreeNode<T> *root;
};

#endif
