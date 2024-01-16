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
 
int rec(int k, int sum, int idx, int n, int *a, bool *vis) {
    if(sum > k) return 0;
    if(sum == k) return 1;
    if(idx >= n) return 0;
    int ans = 0;
 
    vis[idx] = true;
    ans += rec(k, sum+a[idx], idx+1, n, a, vis);
    vis[idx] = false;
    ans += rec(k, sum, idx+1, n, a, vis);
 
    return ans;
}
 
signed main() {
    int n, a[15], k;
    scanf("%d", &n);
    rep(i,0,n) scanf("%d", &a[i]);
    while(scanf("%d", &k) != EOF) {
        bool vis[15] = {0};
        printf("%d\n", rec(k, 0, 0, n, a, vis));
    }
}