#include <stdio.h>
#include <stdlib.h>
#include "transpose.h"

#define COMPARE(x, y) ((x) > (y) ? 1 : (x) < (y) ? -1 : 0)

void storeSum(term d[], int *totalD, int row, int col, int *sum)
{
    if (*sum)
        if (*totalD < MAX_TERMS) {
            d[++*totalD].row = row;
            d[*totalD].col = col;
            d[*totalD].value = *sum;
            *sum = 0;
        }
        else
        {
            fprintf(stderr, "Numbers of terms in product exceeds %d\n", MAX_TERMS);
            exit(EXIT_FAILURE);
        }
}

void mmult(term a[], term b[], term d[])
{
    /* multiple 2 sparse matrix */
    int i, j, column;
    int totalB = b[0].value, totalD = 0;
    int rowsA = a[0].row, colsA = a[0].col, totalA = a[0].value;
    int colsB = b[0].col;
    int rowBegin = 1, row = a[1].row, sum = 0;
    term newB[MAX_TERMS];

    if (colsA != b[0].row) {
        fprintf(stderr, "Incompatible matrices\n");
        exit(EXIT_FAILURE);
    }
    fastTranspose(b, newB);
    for (int i = 1; i < 5; i++)
        printf("d[i] = %d\n", newB[i].value);
    a[totalA + 1].row = rowsA;
    newB[totalB + 1].row = colsB;
    newB[totalB + 1].col = 0;
    newB[totalB + 1].value = totalB;
    for (i = 1; i <= totalA;)
    {
        column = newB[1].row;
        for (j = 1; j <= totalB + 1;)
        {
            /* multiple rows of a and cols of b */
            if (a[i].row != row) {
                storeSum(d, &totalD, row, column, &sum);
                i = rowBegin;
                for (; newB[j].row == column; j++)
                    ;
                column = newB[j].row;
            } else if (newB[j].row != column) {
                storeSum(d, &totalD, row, column, &sum);
                i = rowBegin;
                column = newB[j].row;
            } else switch (COMPARE(a[i].col, newB[j].col)) {
                case -1:
                    i++;
                    break;
                case 0:
                    sum += (a[i++].value * newB[j++].value);
                    break;
                case 1:
                    j++;
            }
        } // for i <= totalB + 1
        for (; a[i].row == row; i++)
            ;
        rowBegin = i, row = a[i].row;
    } /* for i <= totalA */
    d[0].row = rowsA;
    d[0].col = colsB;
    d[0].value = totalD;
}


int main(void)
{
    term a[5] = {{2, 2, 4},
                 {0, 0, 1},
                 {0, 1, 2},
                 {1, 0, 3},
                 {1, 1, 4}};
    term b[5] = {{2, 2, 4},
                 {0, 0, 1},
                 {0, 1, 2},
                 {1, 0, 3},
                 {1, 1, 4}};
    term d[5] = {0};

    mmult(a, b, d);
    for (int i = 1; i < 5; i++)
        printf("d[%d] = %d\n", i, d[i].value);

    return 0;
}