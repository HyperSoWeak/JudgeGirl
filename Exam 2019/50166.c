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
#define oo 1e9
 
double power(double x, int n) {
    double ans = 1;
    rep(i,0,n) ans *= x;
    return ans;
}
 
double df(double x, double p[], int d) {
    double ans = 0;
    rep1(i,1,d) ans += i * p[i] * power(x, i-1);
    return ans;
}
 
double f(double x, double p[], int d) {
    double ans = 0;
    rep1(i,0,d) ans += p[i] * power(x, i);
    return ans;
}
 
signed main() {
    int d, k;
    double x, p[11];
    scanf("%d", &d);
    for(int i=d; i>=0; --i) scanf("%lf", &p[i]);
    scanf("%d", &k);
    scanf("%lf", &x);
 
    while(k--) {
        double fx = f(x, p, d);
        double dfx = df(x, p, d);
        printf("%.4f %.4f\n", x, fx);
        x = x - fx/dfx;
    }
}