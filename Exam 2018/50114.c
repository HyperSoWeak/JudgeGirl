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
    int ax,ay,bx,by,cx,cy,dx,dy;
    scanf("%d%d%d%d%d%d%d%d",&ax,&ay,&bx,&by,&cx,&cy,&dx,&dy); 
    printf("%d\n", (cx-ax+cy-ay)*2);
    printf("%d", (cx-ax)*(cy-ay) - (cx-bx)*(by-ay) - (dx-ax)*(cy-dy));
}