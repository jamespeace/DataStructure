#include <iostream>
#include "AVL.h"

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
    if (!a)
        a = root;
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
            p = p->rightChild;
        } else {
            // height of left increases by 1
            p->bf = 1;
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
            c->bf = 0; b = c; // c is the new root
        }
    } // end of left imbalance
    else { // right imbalance: this is symmetric to left imbalance
        if (b->bf == -1) {  // rotation type RR
            a->rightChild = b->leftChild;
            b->leftChild = a;
            a->bf = 0;
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
void AVL<K, E>::InOrder()
{
    InOrder(root);
    std::cout << "NULL" << std::endl;
}

template <class K, class E>
void AVL<K, E>::InOrder(AvlNode<K, E> *current)
{
    if (!current)
        return;
    InOrder(current->leftChild);
    std::cout << current->element << ", ";
    InOrder(current->rightChild);
}
