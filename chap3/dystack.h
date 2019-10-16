
#ifndef _DYSTACK_H_
#define _DYSTACK_H_

#include <stdbool.h>

#define MAX_STACK_SIZE 100

#define MALLOC(p, s)                              \
    if (!((p) = malloc(s)))                       \
    {                                             \
        fprintf(stderr, "Insufficient memory\n"); \
        exit(EXIT_FAILURE);                       \
    }

#define REALLOC(p, s)\
    if (!((p) = realloc(p, s))){\
        fprintf(stderr, "Insufficient memory\n"); \
        exit(EXIT_FAILURE);                       \
    }

typedef struct {
    int key;
} element;

element *stack;
int capacity = 1;
int top = -1;

element *createS();
bool isFull();
void push(element item);
element pop();
bool isEmpty();
void stackFull();
element stackEmpty();

#endif