#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))
#define ll long long
#define oo 1e9
#define MAXN 100005
 
signed main() {
    double n, x[MAXN], m=0, v=0;
    scanf("%lf", &n);
    rep(i,0,n) {
        scanf("%lf", &x[i]);
        m += x[i];
    }
    m /= n;
    rep(i,0,n) v += (m-x[i]) * (m-x[i]);
    v /= n;
    printf("%lf\n%lf", m, v);
}