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
 
int n, W;
int w[MAXN], v[MAXN];
 
int rec(int wsum, int vsum, int idx) {
    if(idx == n) return vsum;
    int ans = rec(wsum, vsum, idx+1);
    if(wsum+w[idx] <= W) {
        int a = rec(wsum+w[idx], vsum+v[idx], idx+1);
        ans = max(ans, a);
    }
    return ans;
}
 
signed main() {
    scanf("%d%d", &n, &W);
    rep(i,0,n) scanf("%d%d", &w[i], &v[i]);
    printf("%d", rec(0, 0, 0));
}