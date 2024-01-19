#include<stdio.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
 
int main() {
    int n,x0,y0,x1,y1,x2,y2,ans=0;
    scanf("%d%d%d", &n, &x0, &y0);
    x1 = x0;
    y1 = y0;
    rep(i,0,n-1) {
        scanf("%d%d", &x2, &y2);
        ans += x1*y2 - x2*y1;
        x1 = x2;
        y1 = y2;
    }
    ans += x1*y0 - x0*y1;
    printf("%d", ans);
}