
template <class T>
class Queue {
private:
    /* data */
    T *queue;               // array for queue.
    int front;              // front pointer
    int rear;               // rear pointer
    int capcacity;          // size of queue

public:
    Queue (int queueCapacity = 10);
    bool IsEmpty() const;   // Check whether the queue is empty or not
    T &Front() const;       // Return the front element of the queue.
    T &Rear() const;        // Return the rear element of the queue.
    void Push(const T &item);   // Insert item at the rear.
    void Pop();                 // Delete the front element.
};