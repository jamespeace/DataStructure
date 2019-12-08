#ifndef _AVL_H_
#define _AVL_H_

template <class K, class E> class AVL;

template <class K, class E>
class AvlNode {
friend class AVL<K, E>;
public:
    AvlNode(const K& k, const E& e):key(k), element(e), bf(0), height(1), leftChild(nullptr), rightChild(nullptr)
    {}

private:
    K key;
    E element;
    int bf;
    int height;
    AvlNode<K, E> *leftChild, *rightChild;
};

template <class K, class E>
class AVL {
public:
    AVL():root(nullptr){}
    E& Search(const K&) const;
    void Insert(const K&, const E&);
    void Delete(const K&);
    void InOrder(int);
private:
    void InOrder(AvlNode<K, E>*, int);
    AvlNode<K, E> *root;
};

#endif
