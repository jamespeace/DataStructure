#include "GenListNode.h"

// Driver
template <class T>
void GenList<T>::Copy(const GenList<T> &l) const
{
    // Make a copy of l.
    first = Copy(l.first);
}

// Workhorse
template <class T>
GenListNode<T>* GenList<T>::Copy(GenListNode <T> *p)
{
    // Copy the nonrecursive list with no shared sublists pointed at by p.
    GenListNode<T> *q = 0;
    if (p) {
        q = new GenListNode<T>;
        q->tag = p->tag;
        if (p->tag) {
            q->down = Copy(p->down);
        } else {
            q->data = p->data;
        }
        q->next = Copy(p->next);
    }
    return q;
}

template <class T>
bool GenList<T>::operator==(const GenList<T>&l) const
{
    // *this and l are non-recursive lists.
    // The function returns true iff the two lists are identical.
    return Equal(first, l.first);
}

// Workhorse
template <class T>
bool GenList<T>::Equal(GenListNode<T> *s, GenListNode<T> *t)
{
    if (!s)
}