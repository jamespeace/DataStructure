#include <stdio.h>
#include <stdlib.h>
#include "define.h"

#define COLS 2
#define ROWS 2

void add(int **a, int **b, int **c, int rows, int cols)
{
    int i, j;
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
}


int main()
{
    int **a, **b, **c;
    int **p;

    a = make2dArray(ROWS, COLS);
    b = make2dArray(ROWS, COLS);
    c = make2dArray(ROWS, COLS);

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            a[i][j] = COLS * i + j;
            b[i][j] = COLS * i + j;
        }
    }
    add((int **)a, (int **)b, (int **)c, ROWS, COLS);

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    free2dArray(a, ROWS, COLS);
    free2dArray(b, ROWS, COLS);
    free2dArray(c, ROWS, COLS);

    return 0;
}