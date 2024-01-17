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
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    double d = max(0, c-a);
    double e = max(0, c-b);
    printf("%f", PI*c*c*0.75 + PI*d*d*0.25 + PI*e*e*0.25);
}