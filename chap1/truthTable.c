/*
    Exercise chap 1.3.
    Question 3
    page 1-20
    Given n boolean variables. Find all permutation.
*/

#include <stdio.h>
#include <stdlib.h>

void truthTable(int list[], int i, int n)
{
    if (i == n) {
        printf("< ");
        for (int j = 0; j < n; j++) {
            if (list[j])
                printf("Ture ");
            else
                printf("False ");
        }
        printf(">\n");
    } else {
        list[i] = 1;
        truthTable(list, i+1, n);
        list[i] = 0;
        truthTable(list, i+1, n);
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: ./truthTable <number>");
        exit(EXIT_FAILURE);
    }

    int n = atoi(argv[1]);
    int *p = malloc(n * sizeof(int));

    truthTable(p, 0, n);

    free(p);
    return 0;
}