#ifndef _STACK_INT_H_
#define _STACK_INT_H_

#include "stack.h"

#define MAX_STACK_SIZE 1000

extern int stack_int[MAX_STACK_SIZE];
extern int top_int;

void push_int(int item);
int pop_int(void);

void stackFull_int(void);
int stackEmpty_int(void);

#endif