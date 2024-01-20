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
#define OO 1e9
#define ERR 2e9+7
#define MAXN 50005
 
signed main() {
    int n, dis[MAXN], x[MAXN], y[MAXN], X, Y, mind=OO;
    scanf("%d", &n);
    rep(i,0,n) scanf("%d%d", &x[i], &y[i]);
    scanf("%d%d", &X, &Y);
    rep(i,0,n) {
        dis[i] = (X-x[i])*(X-x[i]) + (Y-y[i])*(Y-y[i]);
        mind = min(mind, dis[i]);
    }
    rep(i,0,n) if(dis[i]==mind) printf("%d\n", i);
}