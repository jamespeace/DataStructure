#include "Tree.h"
#include "../chap3/cpp/Stack/Stack.cpp"
#include "../chap3/cpp/Queue/Queue.cpp"
#include <iostream>
using namespace std;

template <class T>
void Tree<T>::Preorder()
{
    Preorder(root);
}

template <class T>
void Tree<T>::Postorder()
{
    Postorder(root);
}

template <class T>
void Tree<T>::Preorder(TreeNode<T> *currentNode)
{
    if (currentNode) {
        Visit(currentNode);
        Preorder(currentNode->leftChild);
        Preorder(currentNode->rightChild);
    }
}

template <class T>
void Tree<T>::Postorder(TreeNode<T> *currentNode)
{
    if (currentNode) {
        Preorder(currentNode->leftChild);
        Preorder(currentNode->rightChild);
        Visit(currentNode);
    }
}

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
    TreeNode<T> *currentNode = root;
    while (currentNode)
    {
        Visit(currentNode);
        if (currentNode->leftChild)
            q.Push(currentNode->leftChild);
        if (currentNode->rightChild)
            q.Push(currentNode->rightChild);
        if (q.IsEmpty())
            return;
        currentNode = q.Front();
        q.Pop();
    }
}

template <class T>
T* Tree<T>::InorderIterator::Next()
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

template <class T>
TreeNode<T>::TreeNode(T d, TreeNode<T>* left, TreeNode<T>* right):data(d),leftChild(left),rightChild(right)
{}

template <class T>
void Tree<T>::Visit(TreeNode<T> *currentNode)
{cout << currentNode->data << endl;}

template <class T>
Tree<T>::Tree(TreeNode<T> *r) : root(r)
{}
