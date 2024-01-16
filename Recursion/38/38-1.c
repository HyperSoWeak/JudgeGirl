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
 
ll N, D, a, b, c, A, B, C;
 
bool rec(ll sum, ll a, ll b, ll c) {
    if(sum == D) return true;
    if(sum > D) return false;
    if(a>0 && rec(sum+A, a-1, b, c)) return true;
    if(b>0 && rec(sum+B, a, b-1, c)) return true;
    if(c>0 && rec(sum+C, a, b, c-1)) return true;
    return false;
}
 
signed main() {
    scanf("%lld", &N);
    rep(i,0,N) {
        scanf("%lld%lld%lld%lld%lld%lld%lld", &D, &a, &b, &c, &A, &B, &C);
        if(rec(0,a,b,c)) printf("yes\n");
        else printf("no\n");
    }
}