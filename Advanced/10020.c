#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>
#include<math.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))
#define OO 1e9
#define ERR 2e9+7
 
signed main() {
    double a, b, c;
    while(scanf("%lf%lf%lf", &a, &b, &c) != EOF) {
        double d = sqrt(b*b - 4*a*c);
        printf("%.20lf %.20lf\n", (-b-d)/(2*a), (-b+d)/(2*a));
    }
}