#include "stack_int.h"
#include <stdio.h>
#include <stdlib.h>

void push_int(int item)
{
    if (top_int >= MAX_STACK_SIZE - 1)
        stackFull_int();
    stack_int[++top_int] = item;
}

int pop_int()
{
    if (top_int == -1)
        return stackEmpty_int();
    return stack_int[top_int--];
}

void stackFull_int()
{
    fprintf(stderr, "stack is full.\n");
    exit(EXIT_FAILURE);
}

int stackEmpty_int()
{
    fprintf(stderr, "stack is empty.\n");
    exit(EXIT_FAILURE);
}