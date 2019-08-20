#include <stdio.h>
#include <stdlib.h>

int factorial_rec(int n)
{
    if (n < 2)
        return 1;
    else 
        return n * factorial_rec(n-1);
}

int main(void)
{
    printf("10! = %d\n", factorial_rec(10));
    printf("4! = %d\n", factorial_rec(4));
    return 0;
}
