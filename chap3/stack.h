#ifndef _STACK_H_
#define _STACK_H_

#define MAX_STACK_SIZE 1000

typedef struct {
    short int col;
    short int row;
    short int dir;
} element;
element stack[MAX_STACK_SIZE];
extern int top;


void push(element item);
element pop(void);
element stackEmpty();
void stackFull();

#endif