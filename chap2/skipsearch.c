#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "skip.h"

#define MAX_SIZE 3
#define MAX2 2

void skip(char *x, int m, char *y, int n)
{
    int i, j;
    List ptr, z[ASIZE];

    printf("skip start\n");
    memset(z, 0, ASIZE * sizeof(List));
    for (i = 0; i < m; i++) {
        ptr = malloc(sizeof(struct _cell));
        if (ptr == NULL) {
            fprintf(stderr, "malloc failed\n");
            exit(EXIT_FAILURE);
        }
        ptr->element = i;
        ptr->next = z[x[i]];
        z[x[i]] = ptr;
    }

    /* searching */
    for (j = m - 1; j < n; j += m)
        for (ptr = z[y[j]]; ptr != NULL; ptr = ptr->next)
            if (memcmp(x, y + j - ptr->element, m) == 0)
                printf("%d\n", j - ptr->element);
    printf("skip end\n");
}

int main()
{
    char s[] = "hello world";
    char c[] = "wor";

    skip(c, sizeof(c)-1, s, sizeof(s)-1);

    return 0;
}
