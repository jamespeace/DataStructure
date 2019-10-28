#include <stdio.h>
#include "postfix.h"
#include "stack_int.h"
#include "stack_precedence.h"

char l[MAX_LINE_SIZE];

int top_int = -1;
int top_precedence = 0;
precedence stack_precedence[MAX_STACK_SIZE];
int stack_int[MAX_STACK_SIZE];

/* 
    isp and icp array are the priority of the lparen, rparen, plus, minus, times, divide, mod and eos.
*/
int isp[] = { 0, 19, 12, 12, 13, 13, 13, 0};
int icp[] = {20, 19, 12, 12, 13, 13, 13, 0};

int eval(char expr[])
{
    precedence token;
    char symbol;
    int op1, op2;
    int n = 0; /* counter for string of operation */
    int top_int = -1;
    token = getToken(expr, &symbol, &n);

    while (token != eos) {
        if (token == operand)
            push_int(symbol-'0'); /* insert to stack */
        else {
            /* move 2 operand out and calculate them.
                put the result back to stack. */
            op2 = pop_int(); /* delete operation of the stack */
            op1 = pop_int();
            switch(token) {
                case plus: push_int(op1+op2);
                            break;
                case minus: push_int(op1-op2);
                            break;
                case times: push_int(op1 * op2);
                            break;
                case mod: push_int(op1 / op2);
                            break;
            }
        }
        token = getToken(expr, &symbol, &n);
    }
    return pop_int();
}

precedence getToken(char expr[], char *symbol, int *n)
{
    *symbol = expr[(*n)++];
    switch(*symbol) {
        case '(' : return lparen;
        case ')' : return rparen;
        case '+' : return plus;
        case '-' : return minus;
        case '*' : return times;
        case '/' : return mod;
        case '\0': return eos;
        default  : return operand;
        /* no error checking, default is number */
    }
}

void printToken(char des[], precedence token, int *index)
{
    char c;
    switch (token) {
        case lparen: c = '('; break;
        case rparen: c = ')'; break;
        case plus  : c = '+'; break;
        case minus : c = '-'; break;
        case times : c = '*'; break;
        case divide: c = '/'; break;
        case mod   : c = '%'; break;
        default    : c = ' '; break;
    }
    printf("%c", c);
    des[(*index)++] = c;
}

void postfix(char expr[], char postline[])
{
    char symbol;
    precedence token;
    int n = 0;
    int index = 0; /* index for printToken() */
    stack_precedence[0] = eos;

    for (token = getToken(expr, &symbol, &n); token != eos;
                            token = getToken(expr, &symbol, &n)) {
        if (token == operand)
            postline[index++] = symbol;
        else if (token == rparen) {
            while (stack_precedence[top_precedence] != lparen)
            {
                printToken(postline, pop_precedence(), &index);
            }
            pop_precedence();
        } else {
            while (isp[stack_precedence[top_precedence]] >= icp[token])
            {
                printToken(postline, pop_precedence(), &index);
            }
            push_precedence(token);
        }
    }
    while ((token = pop_precedence()) != eos)
        printToken(postline, token, &index);
    printf("\n");
}

int main(int argc, char const *argv[])
{
    char expr[MAX_LINE_SIZE] = "1+2";
    char postline[MAX_LINE_SIZE];
    int result;

    //printf("%d\n", eval());
    postfix(expr, postline);
    printf("postline: %s\n", postline);
    result = eval(postline);
    printf("%d\n", result);

    return 0;
}
