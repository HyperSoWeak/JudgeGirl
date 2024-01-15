#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) (a)>(b) ? (a) : (b)
#define min(a,b) (a)<(b) ? (a) : (b)
#define oo 1e9
 
signed main() {
    int w,d,a[105][105],ans[405],x,y,dir;
    rep(i,0,405) ans[i] = -1;
    int dx[] = {1,0,-1,0};
    int dy[] = {0,1,0,-1};
    scanf("%d%d",&w,&d);
    rep1(i,1,d) rep1(j,1,w) scanf("%d",&a[i][j]);
    rep(i,0,w+d+w+d) {
        if(i<w) a[d+1][i+1] = i;
        else if(i<w+d) a[d-i+w][w+1] = i;
        else if(i<w+d+w) a[0][w-i+w+d] = i;
        else a[i-w-d-w+1][0] = i;
    }
    rep(i,0,w+d+w+d) {
        if(ans[i]!=-1) continue;
        if(i<w) x=d, y=i+1, dir=2;
        else if(i<w+d) x=d-i+w, y=w, dir=3;
        else if(i<w+d+w) x=1, y=w-i+w+d, dir=0;
        else x=i-w-d-w+1, y=1, dir=1;
        while(1<=x && x<=d && 1<=y && y<=w) {
            if(a[x][y]) {
                if(dir==0) dir = 3;
                else if(dir==1) dir = 2;
                else if(dir==2) dir = 1;
                else dir = 0;
            }
            x+=dx[dir], y+=dy[dir];
        }
        ans[i] = a[x][y];
        ans[a[x][y]] = i;
    }
    rep(i,0,w+d+w+d) printf("%d\n",ans[i]);
}