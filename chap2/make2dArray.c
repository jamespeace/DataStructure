#include <stdio.h>
#include <stdlib.h>
#include "define.h"

int **make2dArray(int rows, int cols)
{
    /* create a rows * cols 2d array */
    int **x, i;

    /* allocate memory for rows pointers */
    CALLOC(x, rows, sizeof(*x));

    /* allocate memory for cols */
    for (int i = 0; i < rows; i++)
        CALLOC(x[i], cols, sizeof(**x));
    return x;
}

void free2dArray(int **p, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
        free(p[i]);
    free(p);
}
