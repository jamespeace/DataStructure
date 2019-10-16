#ifndef _DEFINE_H_
#define _DEFINE_H_

#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, n)\
        if (!((p) = malloc(n))) {\
            fprintf(stderr, "Insufficient memory");\
            exit(EXIT_FAILURE);\
        }

#define CALLOC(p, n, s)\
        if (!((p) = calloc(n, s))) {\
            fprintf(stderr, "Insufficient memory");\
            exit(EXIT_FAILURE);\
        }

#define SWAP(a, b, t) ((t) = (a), (a) = (b), (b) = (t))

int **make2dArray(int rows, int cols);
void free2dArray(int **p, int rows, int cols);

#endif