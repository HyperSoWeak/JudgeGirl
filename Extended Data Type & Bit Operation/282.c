#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) (a)>(b) ? (a) : (b)
#define min(a,b) (a)<(b) ? (a) : (b)
#define ll long long
#define oo 1e9
 
signed main() {
    ll n;
    while(scanf("%lld", &n) != EOF) {
        int cnt = 0;
        while(n > 0) {
            if(n & 1) cnt++;
            n >>= 1;
        }
        printf("%d\n", cnt);
    }
}