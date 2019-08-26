#include <stdio.h>
#include "transpose.h"

void transpose(term a[], term b[])
{
    int n, i, j, currentb;

    n = a[0].value;
    b[0].col = a[0].col;
    b[0].row = a[0].row;
    b[0].value = n;

    if (n > 0) { /* non zero matrix */
        currentb = 1;
        for ( i = 0; i < a[0].col; i++)
        {
            for (j = 1; j <= n; j++)
            /* find element from current col */
                if (a[j].col == i) {
                    b[currentb].col = a[j].col;
                    b[currentb].row = a[j].row;
                    b[currentb].value = a[j].value;
                    currentb++;
                }
        }
    }
}

