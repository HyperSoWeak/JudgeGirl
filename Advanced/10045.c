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
#define OO 1e9
#define ERR 2e9+7
 
int g(int z) {
    if(z <= 2) return z*z - 1;
    return 2;
}
 
int h(int y) {
    if(y < 2) return -1;
    return 2 + h(y-1) - h(y-2);
}
 
int f(int x) {
    int hh = h(x);
    int gg = g(x);
    if(x > hh) return f(x-1) - hh;
    if(x < hh) return f(gg) - gg;
    return 1;
}
 
signed main() {
    int n;
    scanf("%d", &n);
    printf("%d", f(n));
}