#ifndef _BST_H_
#define _BST_H_

#include <utility>
#include <iostream>
#include "Dictionary.h"
#include "Tree.h"
using namespace std;

template <class K, class E>
class BST : public Dictionary<K, E> {
public:
    BST(TreeNode<pair<K, E>> *p = 0) : root(p) {}
    pair<K, E> *Get(const K &k) const;
    pair<K, E> *RankGet(int r);
    bool IsEmpty() const { return root == nullptr;}
    void Insert(const pair<K, E> &p);
    void Delete(const K &p){}

private:
    pair<K, E> *Get(TreeNode<pair<K, E>>*p, const K &k) const;
    TreeNode<pair<K, E>> *root;
};

#endif
