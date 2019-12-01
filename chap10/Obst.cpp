#include "Obst.h"

#define MAX_SIZE 5
extern int c[][MAX_SIZE+1];
extern int r[][MAX_SIZE+1];
extern int w[][MAX_SIZE+1];

int BST::KnuthMin(int i, int j)
{
    int k = i+1;
    int min_index = k;
    int min_cost = c[i][k-1] + c[k][j];
    for (k = k+1; k <= j; k++) {
        int cost = c[i][k-1] + c[k][j];
        if (cost < min_cost) {
            min_cost = cost;
            min_index = k;
        }
    }
}

void BST::Obst(double *p, double *q, int n)
{
    for (int i = 0; i < n; i++) {
        w[i][i] = q[i]; r[i][i] = c[i][i] = 0;  // initialize
        w[i][i+1] = q[i] + q[i+1] + p[i+1];     // optimal trees with one node
        r[i][i+1] = i+1;
        c[i][i+1] = w[i][i+1];
    }
    w[n][n] = q[n]; r[n][n] = c[n][n] = 0;
    for (int m = 2; m <= n; m++) {  // find optimal trees with m nodes
        for (int i = 0; i <= n - m; i++) {
            int j = i + m;
            w[i][j] = w[i][j-1] + p[j] + q[j];
            int k = KnuthMin(i, j);
            // minimizing c[i][k - 1] + c[k][j]
            c[i][j] = w[i][j] + c[i][k-1] + c[k][j]; // Eq. (10.3)
            r[i][j] = k;
        }
    }
}
