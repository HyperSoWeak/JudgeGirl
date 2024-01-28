#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>
#include<math.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))
#define oo 1e9
#define ERR -(2e9+7)
#define MAXN 1005
 
signed main() {
    int N, k, x, y, a[MAXN][MAXN] = {0};
    scanf("%d%d%d%d", &N, &k, &x, &y);
 
    for(int i=0; k>1; --k, i=(i+1)%N) {
        if(i == N-1) {
            x = (x-1+N) % N;
        } else {
            x = (x+1) % N;
            y = (y-1+N) % N;
        }
    }
 
    rep(i,0,N) {
        rep(j,0,N) {
            a[x][y] = k;
            k = k+1;
            if(j == N-1) {
                x = (x+1) % N;
            } else {
                x = (x-1+N) % N;
                y = (y+1) % N;
            }
        }
    }
 
    rep(i,0,N) rep(j,0,N) printf("%d%c", a[i][j], " \n"[j==N-1]);
}