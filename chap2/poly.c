#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100

typedef struct {
    float coef;
    int expon;
} polynomial;

polynomial terms[MAX_TERMS];
int avail = 0;

void attach(float coefficient, int exponent);

void padd(int startA, int finishA, int startB, int finishB, int *startD, int *finishD)
{
    float coefficient;
    *startD = avail;
    while (startA <= finishA && startB <= finishB)
        switch (COMPARE(terms[startA].expon, terms[startB].expon))
        {
        case -1: /* expon of a is smaller than b */
            attach(terms[startB].coef, terms[startB].expon);
            startB++;
            break;
        case 0:
            coefficient = terms[startA].coef + terms[startB].coef;
            if (coefficient)
                attach(coefficient, terms[startA].expon);
            startA++;
            startB++;
            break;
        case 1: /* expon of b is smaller than a */
            attach(terms[startA].coef, terms[startA].expon);
            startA++;
            break;
        }
    /* add remaining terms of A into D */
    for (; startA <= finishA; startA++)
        attach(terms[startA].coef, terms[startA].expon);
    /* add remaining terms of B into D */
    for (; startB <= finishB; startB++)
        attach(terms[startB].coef, terms[startB].expon);
    *finishD = avail - 1;
}

void attach(float coefficient, int exponent)
{
    if (avail >= MAX_TERMS) {
        fprintf(stderr, "Too many terms in the polynomial\n");
        exit(EXIT_FAILURE);
    }
    terms[avail].coef = coefficient;
    terms[avail++].expon = exponent;
}
