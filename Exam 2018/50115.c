#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) (a)>(b) ? (a) : (b)
#define min(a,b) (a)<(b) ? (a) : (b)
#define oo 1e9
 
int abs(int a) { return a<0 ? -a : a; }
 
signed main() {
    int a,b,h,c,d;
    scanf("%d%d%d%d%d",&a,&b,&h,&c,&d);
    printf("%d", a*b*h / (a*b-c*d));   
}