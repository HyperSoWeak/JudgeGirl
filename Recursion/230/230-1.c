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
#define ll long long
#define oo 1e9
#define MAXN 20
#define MAXW 10000
 
signed main() {
    int n, W;
    int w[MAXN], v[MAXN];
    int dp[MAXW+1] = {0};
    scanf("%d%d", &n, &W);
    rep(i,0,n) scanf("%d%d", &w[i], &v[i]);
    rep(i,0,n) for(int j=W; j-w[i]>=0; --j) dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
    printf("%d", dp[W]);
}