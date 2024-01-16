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
 
bool rec(ll sum, ll k, ll D, ll a[3], ll A[3]) {
    if(k == 3) return false;
    rep1(i,0,a[k]) {
        ll s = sum + A[k]*i;
        if(s > D) return false;
        if(s == D || rec(s, k+1, D, a, A)) return true;
    }
    return false;
}
 
signed main() {
    ll N, D, a[3], A[3];
    scanf("%lld", &N);
    rep(i,0,N) {
        scanf("%lld", &D);
        rep(i,0,3) scanf("%lld", &a[i]);
        rep(i,0,3) scanf("%lld", &A[i]);
        printf("%s\n", rec(0,0,D,a,A) ? "yes" : "no");
    }
}