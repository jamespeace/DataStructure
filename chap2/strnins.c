#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void strnins(char *s, char *t, int i)
{
    char string[MAX_SIZE] = {0};
    int len_des = strlen(t), len_src = strlen(s);

    if (i < 0 && i > (len_src + len_des)) {
        fprintf(stderr, "Position is out of bound\n");
        exit(EXIT_FAILURE);
    }

    if (!len_src)
        strcpy(s, t);
    else if (len_des) {
        strncpy(s+i+len_src, s+i, len_des-i);
        strncpy(s+i, t, len_des);
    }
}

int main(int argc, char const *argv[])
{
    char s[MAX_SIZE] = "hhh";
    char c[MAX_SIZE] = "ddd";

    strnins(s, c, 0);
    printf("s = %s\n", s);
    return 0;
}
