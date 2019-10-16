#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void push(element item)
{
    if (top >= MAX_STACK_SIZE - 1)
        stackFull();
    stack[++top] = item;
}

element pop()
{
    if (top == -1)
{
    fprintf(stderr, "stack is full.\n");
    exit(EXIT_FAILURE);
}

element stackEmpty()
{
    fprintf(stderr, "stack is empty.\n");
    exit(EXIT_FAILURE);
}

void stackFull()
{
    fprintf(stderr, "stack is full.\n");
    exit(EXIT_FAILURE);
}
