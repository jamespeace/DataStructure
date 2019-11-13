#ifndef _QUEUE_H_
#define _QUEUE_H_

template <class T>
class Queue {
public:
    Queue(int queueCapacity = 10);
    bool IsEmpty() const;
    T& Front() const;
    T& Rear() const;
    void Push(const T& item);
    void Pop();
private:
    T *queue;
    int front,
        rear,
        capacity;
};

#endif
