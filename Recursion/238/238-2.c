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
 
void rec(int idx, int sum, int n, int *a, int *ans) {
    if(idx == n) {
        ans[sum]++;
        return;
    }
    rec(idx+1, sum, n, a, ans);
    rec(idx+1, sum+a[idx], n, a, ans);
}
 
signed main() {
    int n, a[15], k, ans[10000] = {0};
    scanf("%d", &n);
    rep(i,0,n) scanf("%d", &a[i]);
    rec(0, 0, n, a, ans);
    while(scanf("%d", &k) != EOF) {
        printf("%d\n", ans[k]);
    }
}