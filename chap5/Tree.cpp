#include "Tree.h"
#include "../chap3/cpp/Stack/Stack.cpp"

template <class T>
void Tree<T>::NonrecInorder()
{
    // Nonrecursive inorder traversal using a stack.
    Stack<TreeNode<T>*> s; // declare and initialize stack
    TreeNode<T> *currentNode = root;
    while (1) {
        while (currentNode)
        { // move down leftChild fields
            s.Push(currentNode); // add to stack
            currentNode = currentNode->leftChild;
        }
        if (s.IsEmpty())
            return;
        currentNode = s.Top();
        s.Pop(); // delete from stack
        Visit(currentNode);
        currentNode = currentNode->rightChild;
    }
}

template <class T>
void Tree<T>::LevelOrder()
{
    // Traverse the binary tree in level order.
    Queue<TreeNode<T>*> q;
}

template <class T>
T* InorderIterator<T>::Next()
{
    while (currentNode)
    {
        s.Push(currentNode);
        currentNode = currentNode->leftChild;
    }
    if (s.IsEmpty())
        return 0;
    currentNode = s.Top();
    s.Pop();
    T& temp = currentNode->data;
    currentNode = currentNode->rightChild;
    return &temp;
}