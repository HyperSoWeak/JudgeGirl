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
#define MAXN 100005
 
signed main() {
    int p[4][2][3] = {
        { {1,1,0},
          {0,1,1} },
        { {0,1,1},
          {1,1,0} },
        { {0,1,0},
          {1,1,1} },
        { {1,1,1},
          {0,1,0} }
    };
    int h[MAXN] = {0};
    int n, a, b;
    scanf("%d", &n);
    while(scanf("%d%d", &a, &b) != EOF) {
        int x = 0;
        rep(i,0,3) x = max(x, h[a+i] + p[b][1][i]);
        rep(i,0,3) h[a+i] = x + p[b][0][i];
    }
    rep(i,0,n) printf("%d%c", h[i], " \n"[i==n-1]);
}