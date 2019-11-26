#ifndef _LINEARPROBING_H_
#define _LINEARPROBING_H_

#include <utility>

using namespace std;

template <class K, class E>
class LinearProbing {
public:
    pair<K, E>* Get(const K& k);
private:
    int h(K& k);
    pair<K, E>** ht;
};
#endif