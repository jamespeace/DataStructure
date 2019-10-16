#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

#define COL 12
#define ROW 15
#define EXIT_ROW 12
#define EXIT_COL 15

int top;
typedef struct {
    short int vert;
    short int horiz;
} offsets;

offsets move[8] = {
    {-1,  0},
    {-1,  1},
    { 0,  1},
    { 1,  1},
    { 1,  0},
    { 1, -1},
    { 0, -1},
    {-1, -1}
};
int maze[COL+2][ROW+2] = {
    /*/*
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1},
    {1,0,0,1,1,0,1,1,0,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,1},
    {1,1,1,0,1,1,1,1,0,0,0,1,1,1,1,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};
*/
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,1,0,0,0,1,1,0,0,0,1,1,1,1,1,1},
    {1,1,0,0,0,1,1,0,1,1,1,0,0,1,1,1,1},
    {1,0,1,1,0,0,0,0,1,1,1,1,0,0,1,1,1},
    {1,1,1,0,1,1,1,1,0,1,1,0,1,1,0,0,1},
    {1,1,1,0,1,0,0,1,0,1,1,1,1,1,1,1,1},
    {1,0,0,1,1,0,1,1,1,0,1,0,0,1,0,1,1},
    {1,0,0,1,1,0,1,1,1,0,1,0,0,1,0,1,1},
    {1,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1},
    {1,0,0,1,1,0,1,1,0,1,1,1,1,1,0,1,1},
    {1,1,1,0,0,0,1,1,0,1,1,0,0,0,0,0,1},
    {1,0,0,1,1,1,1,1,0,0,0,1,1,1,1,0,1},
    {1,0,1,0,0,1,1,1,1,1,0,1,1,1,1,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };

void path(void)
{
    int i, row, col, nextRow, nextCol, dir, found = false;
    element position;
    int **mark;

    mark = (int **)calloc(sizeof(*mark), COL+2);
    int *cols = (int *)calloc(sizeof(*mark),  (COL+2) * (ROW+2));
    for (i = 0; i < (COL+2); i++) {
        *(mark + i) = (cols + i * (ROW+2));
    }

    mark[1][1] = 1;
    top = 0;
    stack[0].row = 1; stack[0].col = 1; stack[0].dir = 1;
    while (top > -1 && !found) {
        position = pop();
        row = position.row;
        col = position.col;
        dir = position.dir;
        while (dir < 8 && !found) {
            nextRow = row + move[dir].vert;
            nextCol = col + move[dir].horiz;
            if (nextRow == EXIT_ROW && nextCol == EXIT_COL)
                found = true;
            else if (!maze[nextRow][nextCol] && !mark[nextRow][nextCol]) {
                mark[nextRow][nextCol] = 1;
                position.row = row;
                position.col = col;
                position.dir = ++dir;
                push(position);
                row = nextRow; col = nextCol; dir = 0;
            } else
                ++dir;            
        }
    }
    if (found) {
        printf("The path is:\n");
        printf("row col\n");
        for (i = 0; i <= top; i++)
            printf("%2d%5d", stack[i].row, stack[i].col);
        printf("%2d%5d\n", row, col);
        printf("%2d%5d\n", EXIT_ROW, EXIT_COL);
    }
    else
    {
        printf("The maze does not have a path\n");
    }
    
}

int main(int argc, char const *argv[])
{
    path();
    return 0;
}
