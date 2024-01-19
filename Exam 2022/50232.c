#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))
#define ll long long
#define oo 1e9
#define MAXN 512
#define MAXK 128
 
signed main() {
    int n, k, N[MAXN][MAXN], K[MAXK][MAXK]; // input / filter
    scanf("%d%d", &n, &k);
    rep(i,0,n) rep(j,0,n) scanf("%d", &N[i][j]);
    rep(i,0,k) rep(j,0,k) scanf("%d", &K[i][j]);
    rep(i,0,n-k+1) {
        rep(j,0,n-k+1) {
            int sum = 0;
            rep(x,0,k) rep(y,0,k) {
                sum += N[i+x][j+y] * K[x][y];
            }
            printf("%d%c", sum, " \n"[j==n-k]);
        }
    }
}