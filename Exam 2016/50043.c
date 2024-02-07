#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) (a)>(b) ? (a) : (b)
#define min(a,b) (a)<(b) ? (a) : (b)
#define oo 1e9
 
signed main() {
    int x1,y1,x2,y2,x3,y3,cnt=0;
    int dx[] = {0,1,0,1};
    int dy[] = {0,0,-1,-1};
    scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
    int maxx = max(x1,max(x2,x3));
    int maxy = max(y1,max(y2,y3));
    int minx = min(x1,min(x2,x3));
    int miny = min(y1,min(y2,y3));
    rep1(x,minx,maxx) {
        rep1(y,miny,maxy) {
            rep(i,0,4) {
                int nx = x+dx[i];
                int ny = y+dy[i];
                int ca = (x1-nx)*(y2-ny) - (x2-nx)*(y1-ny);
                int cb = (x2-nx)*(y3-ny) - (x3-nx)*(y2-ny);
                int cc = (x3-nx)*(y1-ny) - (x1-nx)*(y3-ny);
                if(!((ca>=0&&cb>=0&&cc>=0) || (ca<=0&&cb<=0&&cc<=0))) break;
                if(i==3) cnt++;
            }
        }
    }
    printf("%d", cnt);
}