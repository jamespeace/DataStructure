#ifndef _GENLISTNODE_H_
#define _GENLISTNODE_H_

template <class T> class GenList; // forward declaration

template <class T>
class GenListNode {
friend class GenList<T>;
private:
    GenListNode <T> *next;
    bool tag;
    union {
        T data;
        GenListNode *down;
    };
};

template <class T>
class GenList {
public:
    // List manipulation operations
    void Copy(const GenList<T> &) const;
    bool operator==(const GenList<T>&) const;
private:
    GenListNode<T> *first;
    GenListNode<T>* Copy(GenListNode <T> *);
    bool Equal(GenListNode<T> *s, GenListNode<T> *t);
};

#endif