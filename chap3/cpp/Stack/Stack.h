#ifndef _STACK_H_
#define _STACK_H_
template <class T>
class Stack {
public:
    Stack(int stackCapacity = 10);

    bool IsEmpty() const;
    void StackFull();

    T& Top() const;
    // Return the top element of stack

    void Push(const T& item);
    // Insert item into the top of the stack.

    void Pop();
    // Delete the top element of stack.

private:
    T *stack;
    int top;
    int capacity;
};

#endif
