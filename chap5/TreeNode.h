#ifndef _TREENODE_H_
#define _TREENODE_H_

template <class T> class Tree; // forward declaration

template <class T>
class TreeNode {
friend class Tree<T>;
private:
    T data;
    TreeNode<T> *leftChild;
    TreeNode<T> *rightChild;
};

template <class T>
class Tree {
public:
    // Tree operations
private:
    TreeNode<T> *root;
};

#endif
