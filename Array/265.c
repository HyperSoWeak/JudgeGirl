#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define oo 1e9
 
int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }
 
signed main() {
    int x,y,minx=oo,miny=oo,maxx=-oo,maxy=-oo;
    while(scanf("%d%d",&x,&y) != EOF) {
        minx = min(minx,x);
        miny = min(miny,y);
        maxx = max(maxx,x);
        maxy = max(maxy,y);
    }
    printf("%d", (maxx-minx)*(maxy-miny));
}