#ifndef _GENLISTNODE_H_
#define _GENLISTNODE_H_
template <class T>
class GenList; // forward declaration

template <class T>
class GenListNode {
    friend class GenList<T>;
private:
    GenListNode<T> *next;
    // tag = false/true , data/down
    bool tag;
    union {
        T data;
        GenListNode<T> *down;
    };
};

template <class T>
class GenList {
public:
    bool operator==(const GenList<T> &l) const;
    void Copy(const GenList<T> &l) const;
    int Depth();

private:
    GenListNode<T> *first;
    bool Equal(GenListNode<T> *s, GenListNode<T> *t);
    GenListNode<T> *Copy(GenListNode<T> *p);
    int Depth(GenListNode<T> *);
};
#endif
