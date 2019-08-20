#include <stdio.h>
#include <stdlib.h>

int factorial_iter(int n)
{
    if (n < 2)
        return 1;
    int sum = 1;
    for (int i = 2; i <= n; i++)
        sum *= i;
    return sum;
}

int main(void)
{
    printf("10! = %d\n", factorial_iter(10));
    printf("4! = %d\n", factorial_iter(4));
    return 0;
}