#ifndef _CHAINING_H_
#define _CHAINING_H_

#include <utility>
#include "../chap4/ChainNode.h"
#include "../chap5/Dictionary.h"

using namespace std;
/*
    Search the chained hash table ht for k.
    If a pair with this key is found, return a pointer to this pair; otherwise, return 0.
    */
template <class K, class E>
class Chaining : public Dictionary<K, E> {
public:
    Chaining();
    ~Chaining();
    bool IsEmpty() const;
    pair<K, E>* Get(const K&) const;
    void Insert(const pair<K, E>&);
    void Delete(const K&);
    void PrintChaining();
private:
    int h(const K &k) const;
    ChainNode<pair<K, E>>** ht;
};

#endif