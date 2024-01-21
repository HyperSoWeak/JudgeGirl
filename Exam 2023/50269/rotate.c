#include <stdio.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#include "rotate.h"
 
void rotate(int *P[MAX][MAX], int n) {
    int *q[MAX][MAX];
    rep(i,0,n) rep(j,0,n) q[i][j] = P[i][j];
    rep(i,0,n) rep(j,0,n) P[i][j] = q[n-j-1][i];
}