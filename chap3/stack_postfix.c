#include "stack_postfix.h"
#include <stdio.h>
#include <stdlib.h>

void push(int item)
{
    if (top >= MAX_STACK_SIZE - 1)
        stackFull();
    stack[++top] = item;
}

int pop()
{
    if (top == -1)
        return stackEmpty();
    return stack[top--];
}

int stackEmpty()
{
    fprintf(stderr, "stack is empty.\n");
    exit(EXIT_FAILURE);
}

void stackFull()
{
    fprintf(stderr, "stack is full.\n");
    exit(EXIT_FAILURE);
}
