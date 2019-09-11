#ifndef _STACK_H_
#define _STACK_H_

#include <stdbool.h>

#define MAX_STACK_SIZE 100

typedef struct {
    int key;
} element;

element stack[MAX_STACK_SIZE];
int top = -1;

element *createS(int size);
bool isFull();
void push(element item);
element pop();
bool isEmpty();
void stackFull();
element stackEmpty();

#endif