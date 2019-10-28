#include "stack_precedence.h"
#include <stdio.h>
#include <stdlib.h>
#include "postfix.h"

void push_precedence(precedence item)
{
    if (top_precedence >= MAX_STACK_SIZE - 1)
        stackFull_precedence();
    stack_precedence[++top_precedence] = item;
}

precedence pop_precedence(void)
{
    if (top_precedence == -1)
        return stackEmpty_precedence();
    return stack_precedence[top_precedence--];
}

void stackFull_precedence()
{
    fprintf(stderr, "stack is full.\n");
    exit(EXIT_FAILURE);
}

precedence stackEmpty_precedence()
{
    fprintf(stderr, "stack is empty.\n");
    exit(EXIT_FAILURE);
}
