#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

template <class T>
class BinaryTree {
    // objects: A finite set of nodes either empty or consisting of a
    // root node, left BinaryTree and right BinaryTree.
public:
    // create an empty binary tree
    BinaryTree();

    // return true iff the binary tree is empty
    bool IsEmpty();

    // Creates a binary tree whose left subtree is bt 1, whose right subtree
    // is bt 2, and whose root node contains item
    BinaryTree(BinaryTree<T>& bt1, T& item, BinaryTree<T>& bt2);

    // return the left of *this
    BinaryTree<T> LeftSubtree();

    // return the right of *this
    BinaryTree<T> RightSubtree();

    // return the data in the root node of *this
    T RootData();
};

#endif