#include <iostream>
#include <iomanip>
#include "AVL.h"
#include "../chap3/cpp/Stack/Stack.cpp"

template <class K, class E>
void AVL<K, E>::Insert(const K& k, const E& e)
{
    if (!root) {    // special case: empty tree
        root = new AvlNode<K, E>(k, e);
        return;
    }
    // Phase 1: Locate insertion point for e
    AvlNode<K, E> *a = 0,   // most recent node with bf = +-1
                *pa = 0,    // parent of a
                *p = root,  // p moves through the tree
                *pp = 0;    // parent of p
    while (p) {
        if (p->bf) {
            a = p;
            pa = pp;
        }
        if (k < p->key) {
            // take left branch
            pp = p;
            p = p->leftChild;
        } else if (k > p->key) {
            pp = p; p = p->rightChild;
        } else {
            // k already in tree
            p->element = e;
            return;
        }
    }
    // It's complete binary tree
    if (!a) {
        a = root;
        a->height += 1;
    }
    // Phase 2: Insert and rebalance. k is not in the tree and
    // may be inserted as the appropriate child of pp.
    AvlNode<K, E> *y = new AvlNode<K, E>(k, e);
    if (k < pp->key)
        pp->leftChild = y;      // insert as left child
    else
        pp->rightChild = y;     // insert as right child
    
    // Adjust balance factors of nodes on path from a to pp. By the definition
    // of a, all nodes on this path presently have a balance factor of 0. Their new
    // balance factor will be +-1. d = +1 implies that k is inserted in the left subtree
    // of a. d = -1 implies that k is inserted in the right subtree of a.
    int d;
    AvlNode<K, E> *b, // child of a
                  *c; // child of b

    if (k > a->key) {
        b = p = a->rightChild; d = -1;
    } else {
        b = p = a->leftChild; d = 1;
    }

    while (p != y)
        if (k > p->key) {
            // height of right increases by 1
            p->bf = -1;
            p->height += 1;
            p = p->rightChild;
        } else {
            // height of left increases by 1
            p->bf = 1;
            p->height += 1;
            p = p->leftChild;
        }
    
    // Is tree unbalanced?
    if (!(a->bf) || !(a->bf + d)) {// tree still balanced
        a->bf += d; return;
    }
    
    // tree unbalanced, determine rotation type
    if (d == 1) {
        if (b->bf == 1) {   // rotation type LL
            a->leftChild = b->rightChild;
            b->rightChild = a;
            a->bf = 0;
            a->height -= 2;
            b->bf = 0;
        } else {            // rotation type LR
            c = b->rightChild;
            // counterclockwise rotation in b
            b->rightChild = c->leftChild;
            c->leftChild = b;
            // clockwise rotation in a
            a->leftChild = c->rightChild;
            c->rightChild = a;
            switch (c->bf) {
                case 1:
                    a->bf = -1; b->bf = 0;
                    break;
                case -1:
                    a->bf = 0; b->bf = 1;
                    break;
            }
            a->height -= 3;
            b->height -= 1;
            c->height += 1;
            c->bf = 0; b = c; // c is the new root
        }
    } // end of left imbalance
    else { // right imbalance: this is symmetric to left imbalance
        if (b->bf == -1) {  // rotation type RR
            a->rightChild = b->leftChild;
            b->leftChild = a;
            a->bf = 0;
            a->height -= 2;
            b->bf = 0;
        } else {            // rotation type RL
            c = b->leftChild;
            // clockwise rotation in b
            b->leftChild = c->rightChild;
            c->rightChild = b;
            // counterclockwise rotation in a
            a->rightChild = c->leftChild;
            c->leftChild = a;
            switch (c->bf) {
                case 1:
                    a->bf = 0; b->bf = -1;
                    break;
                case -1:
                    a->bf = 1; b->bf = 0;
            }
            a->height -= 3;
            b->height -= 1;
            c->height += 1;
            c->bf = 0; b = c;
        }
    } // end of right imbalance

    // Subtree with root b has been rebalanced.
    if (!pa)
        root = b;
    else if (a == pa->leftChild)
        pa->leftChild = b;
    else
        pa->rightChild = b;
    return ;
}

template <class K, class E>
void AVL<K, E>::InOrder(int i)
{
    if (i == 1)
        std::cout << "element: ";
    else if (i == 2)
        std::cout << "bf:      ";
    else if (i == 3)
        std::cout << "height:  ";
    InOrder(root, i);
    std::cout << "NULL" << std::endl;
}

template <class K, class E>
void AVL<K, E>::InOrder(AvlNode<K, E> *current, int i)
{
    if (!current)
        return;
    InOrder(current->leftChild, i);
    if (i == 1)
        std::cout << std::setw(2) << current->element << ", ";
    else if (i == 2)
        std::cout << std::setw(2) << current->bf << ", ";
    else if (i == 3)
        std::cout << std::setw(2) << current->height << ", ";
    InOrder(current->rightChild, i);
}

template <class K, class E>
void AVL<K, E>::Delete(const K& k)
{
    if (!root) {    // special case: empty tree
        std::cout << "Delete node failed. Tree is empty." << endl;
        return;
    }
    // Phase 1:
    Stack<AvlNode<K, E>*> *s = new Stack<AvlNode<K, E>*>();
    AvlNode<K, E>   *p = root,  // p moves through the tree
                    **pp = nullptr,    // parent of p
                    **gp = nullptr;    // grandparent of p
    while (p) {
        if (k < p->key) {
            // take left branch
            s->Push(p);
            gp = pp;
            pp = &p->leftChild;
            p = p->leftChild;
        } else if (k > p->key) {
            s->Push(p);
            gp = pp;
            pp = &p->rightChild; 
            p = p->rightChild;
        } else {
            // find the node
            break;
        }
    }

    // can't find the node
    if (p == nullptr) {
        std::cout << "Delete node failed. Cannot find the node" << endl;
        s->~Stack();
        return;
    }

    // Phase 2: Delete and rebalance. k is in the tree and
    // may be deleted as the appropriate child of pp.
    AvlNode<K, E> *delNode = p,
                  **pDelNode = pp;

    // Deleted node has 2 children. Choose left most child as new root of the subtree.
    if (p->leftChild && p->rightChild) {
        s->Push(p);
        gp = pp;
        pp = &p->leftChild;
        p = p->leftChild;
        while (p->rightChild) {
            s->Push(p);
            gp = pp;
            pp = &p->rightChild;
            p = p->rightChild;
        }
        // swap delNode and left most child.
        delNode->key = p->key;
        delNode->element = p->element;
        delNode = p;
        pDelNode = pp;
    }

    int d;
    // Delete node.
    // delNode is root;
    if (!pDelNode) {
        root = nullptr;
        delNode->~AvlNode();
    }
    // There are only 2 circulstances because we have switched the 2-children node with the left most node in 2-children situation.
    else if (delNode->rightChild) {
        p = delNode->rightChild;
        *pDelNode = delNode->rightChild;
    } else {
        p = delNode->leftChild;
        *pDelNode = delNode->leftChild;
    }
    delNode->~AvlNode();

    // TODO: start from here
    // Adjust balance factors of nodes on path from a to pp. By the definition
    // of a, all nodes on this path presently have a balance factor of 0. Their new
    // balance factor will be +-1. d = -1 implies that k is deleted in the left subtree
    // of a. d = +1 implies that k is deleted in the right subtree of a.
    AvlNode<K, E> *a,
                  *b, // child of a
                  *c, // child of b
                  *pa;
    a = p;

    // iterate every node until reach root.
    while (!s->IsEmpty()) {
        a = s->Top();
        s->Pop();
        int leftHeight = 0, rightHeight = 0;
        if (a->rightChild)
            rightHeight = a->rightChild->height;
        if (a->leftChild)
            leftHeight = a->leftChild->height;
        if (abs(rightHeight - leftHeight) <= 1) {
            // node is still balanced.
            a->bf = leftHeight - rightHeight;
            a->height = max(leftHeight, rightHeight) + 1;
            continue;
        } else {
            if (leftHeight > rightHeight) {
                d = 1;
                b = a->leftChild;
            } else {
                d = -1;
                b = a->rightChild;
            }
        }

        // tree unbalanced, determine rotation type
        if (d == 1) {
            if (b->bf == 1) {   // rotation type LL
                a->leftChild = b->rightChild;
                b->rightChild = a;
                a->bf = 0;
                a->height -= 2;
                b->bf = 0;
            } else {            // rotation type LR
                c = b->rightChild;
                // counterclockwise rotation in b
                b->rightChild = c->leftChild;
                c->leftChild = b;
                // clockwise rotation in a
                a->leftChild = c->rightChild;
                c->rightChild = a;
                switch (c->bf) {
                    case 1:
                        a->bf = -1; b->bf = 0;
                        break;
                    case -1:
                        a->bf = 0; b->bf = 1;
                        break;
                }
                a->height -= 3;
                b->height -= 1;
                c->height += 1;
                c->bf = 0; b = c; // c is the new root
            }
        } // end of left imbalance
        else { // right imbalance: this is symmetric to left imbalance
            if (b->bf == -1) {  // rotation type RR
                a->rightChild = b->leftChild;
                b->leftChild = a;
                a->bf = 0;
                a->height -= 2;
                b->bf = 0;
            } else {            // rotation type RL
                c = b->leftChild;
                // clockwise rotation in b
                b->leftChild = c->rightChild;
                c->rightChild = b;
                // counterclockwise rotation in a
                a->rightChild = c->leftChild;
                c->leftChild = a;
                switch (c->bf) {
                    case 1:
                        a->bf = 0; b->bf = -1;
                        break;
                    case -1:
                        a->bf = 1; b->bf = 0;
                }
                a->height -= 3;
                b->height -= 1;
                c->height += 1;
                c->bf = 0; b = c;
            }
        } // end of right imbalance
        try {
            pa = s->Top();
        } catch (const char *str) {
            pa = nullptr;
        }
        
        // Subtree with root b has been rebalanced.
        if (!pa)
            root = b;
        else if (a == pa->leftChild)
            pa->leftChild = b;
        else
            pa->rightChild = b;
    }
    delete s;
}
