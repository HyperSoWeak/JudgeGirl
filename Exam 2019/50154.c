#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define oo 1e9
 
signed main() {
    int a,b,c,d,e,f,g;
    scanf("%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g);
    int x = (a+b+c+d+g+f) + (a+b+c)*e + (c+d)*f + e*g;
    int y = (a+b+c)*e*g + (c+d)*f;
    printf("%d\n%d",x,y);
}