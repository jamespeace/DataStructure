#ifndef _STACK_H_
#define _STACK_H_

#define MAX_STACK_SIZE 1000

int stack[MAX_STACK_SIZE];
extern int top;

void push(int item);
int pop(void);
int stackEmpty();
void stackFull();

#endif