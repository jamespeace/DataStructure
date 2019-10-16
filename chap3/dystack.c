
#include "dystack.h"
#include <stdio.h>
#include <stdlib.h>

element *createS()
{
    stack = malloc(sizeof(*stack));
}

void push(element item)
{
    if (isFull())
        return stackFull();
    stack[++top] = item;
}

element pop()
{
    if (isEmpty())
        return stackEmpty();
    return stack[top--];
}

void stackFull()
{
    REALLOC(stack, 2 * capacity * sizeof(*stack));
    capacity *= 2;
}

element stackEmpty()
{
    fprintf(stderr, "stack is empty.\n");
    exit(EXIT_FAILURE);
}

bool isFull()
{
    if (top == (MAX_STACK_SIZE - 1))
        return true;
    else
        return false;
}

bool isEmpty()
{
    if (top == -1)
        return true;
    else
        return false;
}

int main(int argc, char const *argv[])
{
    pop();
    return 0;
}
