#include <stdio.h>
#include <stdlib.h>

#define NUMBER 24
#define MODULE_NUMBER 14
int fn(int i) {
    return i % MODULE_NUMBER;
}

void pigeon(int (*f)(int), int list[], int n)
{
    int *l = malloc(n * sizeof(*l));
    
    for (int i = 0; i < n; i++)
        l[i] = fn(list[i]);
    for (int i = 0; i < n-1; i++) {
        int target = l[i];
        for (int j = i+1; j < n; j++) {
            if (l[j] == target) {
                printf("Input %d == %d\n", list[i], list[j]);
            }
        }
    }
    free(l);
}

int main(void)
{
    int list[NUMBER];

    for (int i = 0; i < NUMBER; i++) {
        list[i] = i;
    }

    pigeon(fn, list, NUMBER);
    return 0;
}