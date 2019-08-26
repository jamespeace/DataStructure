#include "transpose.h"

void fastTranspose(term a[], term b[])
{
    int rowTerms[MAX_COL]; // the numbers of element rowTerms[i] in i col.
    int startingPos[MAX_COL]; // every i col's start position at startingPos[i]
    int i, j, numCols = a[0].col, numTerms = a[0].value;

    b[0].row = numCols;
    b[0].col = a[0].row;
    b[0].value = numTerms;

    /* non zero matrix */
    if (numTerms > 0) {
        for (i = 0; i < numCols; i++)
            rowTerms[i] = 0;
        for (i = 1; i <= numTerms; i++)
            rowTerms[a[i].col]++;
        startingPos[0] = 1;
        for (i = 1; i < numCols; i++)
            startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
        for (i = 1; i <= numTerms; i++) {
            j = startingPos[a[i].col]++;
            b[j].row = a[i].col;
            b[j].col = a[i].row;
            b[j].value = a[i].value;
        }
    }
}
