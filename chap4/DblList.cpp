#include "DblList.h"

void DblList::Delete(DblListNode* x)
{
    if (x == first) throw "Deletion of header node not permitted";
    else {
        x->left->right = x->right;
        x->right->left = x->left;
        delete x;
    }
}

void DblList::Insert(DblListNode *p, DblListNode *x)
{
    // Insert node p to the right of node x
    p->left = x;
    p->right = x->right;
    p->right->left = p;
    x->right = p;
}