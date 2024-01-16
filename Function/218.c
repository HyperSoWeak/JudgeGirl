#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) (a)>(b) ? (a) : (b)
#define min(a,b) (a)<(b) ? (a) : (b)
#define ll long long
#define oo 1e9
 
int C(int n, int k) {
    k = min(k, n-k);
    int ans = 1;
    for(int i=n; i>n-k; --i) ans *= i;
    for(int i=1; i<=k; ++i) ans /= i;
    return ans;
}
 
signed main() {
    int n, m, ans=0;
    scanf("%d%d", &n, &m);
    rep1(i,0,m) ans += C(n, i);
    printf("%d", ans);
}