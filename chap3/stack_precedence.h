#ifndef _STACK_PRECEDENCE_H_
#define _STACK_PRECEDENCE_H_

#include "postfix.h"
#include "stack.h"

extern int top_precedence;
extern precedence stack_precedence[MAX_STACK_SIZE];

void push_precedence(precedence item);
precedence pop_precedence(void);

void stackFull_precedence(void);
precedence stackEmpty_precedence(void);

#endif