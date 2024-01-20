#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) (a)>(b) ? (a) : (b)
#define min(a,b) (a)<(b) ? (a) : (b)
#define ULL unsigned long long
#define OO 1e9
 
signed main() {
    int n;
    ULL a;
    scanf("%d", &n);
    rep(i,0,n) {
        scanf("%llu", &a);
        rep(j,0,12) {
            int x = a & 31;
            putchar('a'+x);
            a>>=5;
        }
    }
}