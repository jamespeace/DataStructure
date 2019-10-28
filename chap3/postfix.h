#ifndef _POSTFIX_H_
#define _POSTFIX_H_

#define MAX_LINE_SIZE 100

typedef enum {
    lparen, rparen, plus, minus, times, divide, mod, eos, operand
    } precedence;

precedence getToken(char expr[], char *symbol, int *n);
void printToken(char buffer[], precedence token, int *index);

#endif