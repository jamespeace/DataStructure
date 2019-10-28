#include <stdio.h>
#include "stack_postfix.h"

char *expr = "62/3-42*+";
int top = -1;

typedef enum
{
    lparen,
    rparen,
    plus,
    minus,
    times,
    divide,
    mod,
    eos,
    operand
} precedence;

precedence getToken(char *symbol, int *n);

int eval(void)
{
    precedence token;
    char symbol;
    int op1, op2;
    int n = 0; // counter of string expression.
    token = getToken(&symbol, &n);
    
    while (token != eos) {
        if (token == operand) {
            push(symbol - '0');
        } else {
            op2 = pop();
            op1 = pop();
            switch (token) {
                case plus:
                    push(op1 + op2);
                    break;
                case minus:
                    push(op1 - op2);
                    break;
                case times:
                    push(op1 * op2);
                    break;
                case mod:
                    push(op1 % op2);
                    break;
                case divide:
                    push(op1 / op2);
                    break;
            }
        }
        token = getToken(&symbol, &n);
    }
    return pop();
}

precedence getToken(char *symbol, int *n)
{
    *symbol = expr[(*n)++];
    switch (*symbol)
    {
    case '(':
        return lparen;
    case ')':
        return rparen;
    case '+':
        return plus;
    case '-':
        return minus;
    case '*':
        return times;
    case '/':
        return divide;
    case '%':
        return mod;
    case '\0':
        return eos;
    default  :
        return operand;
        /* no error checking. default is number */
    }
}

int main(int argc, char const *argv[])
{
    printf("%d\n", eval());
    return 0;
}
