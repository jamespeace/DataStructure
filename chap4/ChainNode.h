#ifndef _CHAINNODE_H_
#define _CHAINNODE_H_

template <class T> class Chain; // forward declaration

template <class T>
class ChainNode {
    friend class Chain<T>;
public:
    ChainNode(T element = 0, ChainNode<T>* next = nullptr)
    // 0 is the default value for element and next
    {data = element; link = next;}
private:
    T data;
    ChainNode<T>* link;
};

template <class T>
class Chain {
public:
    class ChainIterator {
    public:
        friend class Chain<T>;
        // typedefs required by C++ for a forward iterator omitted

        // constructor
        ChainIterator(ChainNode <T>* startNode = 0) {current = startNode;}
        
        // dereferencing operators
        T& operator*() const {return current->data;}
        T* operator->() const {return &current->data;}

        // increment
        ChainIterator& operator++() // preincrement
            {current = current->link;}
        ChainIterator operator++(int) // postincrement
            {
                ChainIterator old = *this;  // this is a pointer!
                current = current->link;
                return old;
            }

        // equality testing
        bool operator !=(const ChainIterator right) const
            {return current != right.current;}
        bool operator ==(const ChainIterator right) const
            {return current == right.current;}
    private:
        ChainNode<T>* current;
    };

    Chain() {first = last = nullptr;}
    void Create2();
    void Insert50(ChainNode<T> *x);
    void Delete(ChainNode<T> *x, ChainNode<T> *y);
    int Length();
    void Delete1Node(ChainNode<T>* x);
    void InsertBack(const T& e);
    void Concatenate(Chain <T>& b);
    void Reverse();

    ChainIterator begin() {return ChainIterator(first);}
    ChainIterator end() {return ChainIterator(0);}

private:
    ChainNode<T>* first;
    ChainNode<T>* last;
};

#endif