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

void pmult(int startA, int finishA, int startB, int finishB, int *startD, int *finishD)
{
    float coefficient;
    *startD = avail;
    while (startA <= finishA) {
        while (startB <= finishB)
        {
            attach(terms[startA].coef * terms[startB].coef,
                    terms[startA].expon + terms[startB].expon);
            startB++;
        }
        startA++;
    }
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
