#include <stdio.h>
#include <stdlib.h>

void hanoi(int i, int j, int n)
{
    if (n > 1)
        hanoi(i, 6-i-j, n-1);
    printf("move disk %d from tower%d to tower%d\n", n, i, j);
    if (n > 1)
        hanoi(6-i-j, j, n-1);
}

int main()
{
    hanoi(1, 3, 2);
    return 0;
}