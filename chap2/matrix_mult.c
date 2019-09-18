#include <stdio.h>
#include <stdlib.h>
#include "transpose.h"

mmult(term a[], term b[], term d[])
{
    term newB[MAX_TERMS];
    int totalA, totalB;
    int rowsA, rowsB, colsA, colsB;
    int i, j;

    totalA = a[0].value;
    totalB = b[0].value;

    fastTranspose(b, newB);
    for (i = 1; i < totalA;) {
        for (j = 1; j < totalB;) {
            
        }
    }
}