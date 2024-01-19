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
#define OO 1e9
#define ERR 2e9+7
 
int io(int x, int y, int r, int xx, int yy) {
    int dis2 = (x-xx)*(x-xx) + (y-yy)*(y-yy);
    return r*r - dis2;
}
 
signed main() {
    int xa,ya,ra,xb,yb,rb;
    scanf("%d%d%d%d%d%d",&xa,&ya,&ra,&xb,&yb,&rb);
    int x, y;
    while(scanf("%d%d", &x, &y) != EOF) {
        int a = io(xa,ya,ra,x,y);
        int b = io(xb,yb,rb,x,y);
        if(a>0 || b>0) printf("In\n");
        else if(a==0 || b==0) printf("On\n");
        else printf("Out\n");
    }
}