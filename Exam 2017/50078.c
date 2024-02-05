#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) (a)>(b) ? (a) : (b)
#define min(a,b) (a)<(b) ? (a) : (b)
#define ll long long
#define oo 1e9
 
signed main() {
    int ax,ay,bx,by,cx,cy;
    scanf("%d%d%d%d%d%d",&ax,&ay,&bx,&by,&cx,&cy);
    printf("%d\n%d\n", bx+cx-ax, by+cy-ay);
    printf("%d\n%d\n", ax+cx-bx, ay+cy-by);
    printf("%d\n%d\n", bx+ax-cx, by+ay-cy);
}