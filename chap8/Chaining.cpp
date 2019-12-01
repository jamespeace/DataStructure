#include "Chaining.h"
#include "../chap4/ChainNode.h"

template <class K, class E>
Chaining<K, E>::Chaining()
{
    ht = new ChainNode<pair<K, E>>*[26];
}

template <class K, class E>
Chaining<K, E>::~Chaining()
{
    delete []ht;
}

template <class K, class E>
bool Chaining<K, E>::IsEmpty() const
{
    return ht == nullptr;
}

template <class K, class E>
pair<K, E>* Chaining<K, E>::Get(const K& k) const
{
    int i = h(k);   // home bucket
    //search the chain ht[i]
    for (ChainNode<pair<K, E>> *current = ht[i]; current; current = current->link)
        if (current->data.first == k)
            return &current->data;
}

template <class K, class E>
void Chaining<K, E>::Insert(const pair<K, E>& p)
{
    int i = h(p.first); // home bucket

    // Insert into the chain ht[i]
    ChainNode<pair<K, E>> *next = nullptr;
    ChainNode<pair<K, E>> *node = new ChainNode<pair<K, E>>(p, ht[i]);
    ht[i] = node;
}

template <class K, class E>
void Chaining<K, E>::Delete(const K& k)
{
    int i = h(k);     // home bucket

    // Search the chain ht[i]
    ChainNode<pair<K, E>> *current, *pre;
    for (current = ht[i]; current != nullptr && current->data.first != k; pre = current, current = current->link)
        ;
    if (current) {
        pre->link = current->link;
        current->~ChainNode();
    }
}

template <class K, class E>
void Chaining<K, E>::PrintChaining()
{
    ChainNode<pair<K, E>> *cur;

    for (int i = 0; i < 26; i++) {
        cur = ht[i];
        cout << "[" << i << "]: ";
        while (cur) {
            cout << cur->data.first << "-> ";
            cur = cur->link;
        }
        cout << "null" << endl;
    }
}

template <class K, class E>
int Chaining<K, E>::h(const K& k) const
{
    return (k.at(0) - 'A') % 26;
}
