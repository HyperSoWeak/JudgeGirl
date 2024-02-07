#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))
#define oo 1e9
#define MAXM 16
 
signed main() {
    int N, M, T, C, Q, p[MAXM][MAXM], w[MAXM][MAXM];
    rep(i,0,MAXM) rep(j,0,MAXM) w[i][j] = 1;
    scanf("%d%d", &N, &M);
    T = 2 * M * M;
 
    rep(n,0,N) {
        scanf("%d", &C);
        int h = 0;
        rep(i,0,M) rep(j,0,M) {
            scanf("%d", &p[i][j]);
            h += p[i][j] * w[i][j];
        }
 
        if((h>=T) != C) {
            rep(i,0,M) rep(j,0,M) {
                if(p[i][j]) w[i][j] = C ? w[i][j]*2 : max(1, w[i][j]/2);
            }
        }
    }
 
    scanf("%d", &Q);
    while(Q--) {
        int h = 0;
        rep(i,0,M) rep(j,0,M) {
            scanf("%d", &p[i][j]);
            h += p[i][j] * w[i][j];
        }
        printf("%d\n", h>=T);
    }
}