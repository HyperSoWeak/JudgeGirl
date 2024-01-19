#include<stdio.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
 
int dst(int x1, int y1, int x2, int y2) {
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}
 
int main() {
    int ax,ay,bx,by,cx,cy,dx,dy;
    int t[2][2][2] = {
        { {-1, 3}, {2, 6} },
        { {1, 5}, {4, 0} }
    };
    while(scanf("%d%d%d%d%d%d%d%d",&ax,&ay,&bx,&by,&cx,&cy,&dx,&dy) != EOF) {
        int a=dst(ax,ay,dx,dy);
        int b=dst(bx,by,dx,dy);
        int c=dst(cx,cy,dx,dy);
        printf("%d ", t[a<=b && a<=c][b<=a && b<=c][c<=a && c<=b]);
    }
}