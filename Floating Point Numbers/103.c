#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) (a)>(b) ? (a) : (b)
#define min(a,b) (a)<(b) ? (a) : (b)
#define ll long long
#define oo 1e9
#define PI 3.1415926
 
signed main() {
    int n;
    double A[16][16], X[16], Y[16];
    scanf("%d", &n);
    rep(i,0,n) rep(j,0,n) scanf("%lf", &A[i][j]);
    rep(i,0,n) scanf("%lf", &Y[i]);
    for(int i=n-1; i>=0; --i) {
        X[i] = Y[i] / A[i][i];
        for(int j=i-1; j>=0; --j) Y[j] -= A[j][i] * X[i];
    }
    rep(i,0,n) printf("%f\n", X[i]);
}