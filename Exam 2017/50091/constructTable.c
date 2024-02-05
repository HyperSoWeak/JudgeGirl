#include<stdio.h>
#define MAXN 105
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
 
int **f[MAXN];
int *s[MAXN][MAXN];
 
int ***constructTable(int A[], int B[]) {
    int *bp = B;
 
    int i;
    for(i=0; A[i]!=0; ++i) {
        f[i] = s[i];
        rep(j,0,A[i]) {
            s[i][j] = bp;
            while(*(bp++) != 0);
        }
        s[i][A[i]] = NULL;
    }
    f[i] = NULL;
 
    return f;
}