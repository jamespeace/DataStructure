#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101

typedef struct
{
    int col;
    int row;
    int value;
} term;
term a[MAX_TERMS] = {
    {6, 6, 8},
    {0, 0, 15},
    {0, 3, 22},
    {0, 5, -15}, 
    {1, 1, 11},
    {1, 2, 3},
    {2, 3, -6},
    {4, 0, 91},
    {5, 2, 28}
};

term b[MAX_TERMS] = {
    {6, 6, 8},
    {0, 0, 15},
    {0, 4, 91},
    {1, 1, 11},
    {2, 1, 3},
    {2, 5, 28},
    {3, 0, 22},
    {3, 2, -6},
    {5, 0, -15}
}

