#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))
#define ll long long
#define oo 1e9
#define MAXN 105
 
signed main() {
    int n, a[MAXN][MAXN], m, x, y, vis[MAXN][MAXN]={0};
    int dx[] = {0,1,0,-1};
    int dy[] = {1,0,-1,0};
    int type[16];
    type[9]=0, type[12]=1, type[6]=2, type[3]=3;
    scanf("%d", &n);
    rep1(i,1,n) rep1(j,1,n) scanf("%d", &a[i][j]);
    scanf("%d", &m);
    while(m--) {
        scanf("%d%d", &x, &y);
        x++, y++;
        vis[x][y] = 2;
    }
    rep1(x,1,n) rep1(y,1,n) {
        if(vis[x][y] == 2) {
            int t = 0;
            for(int i=0, j=1; i<4; ++i, j*=2) if(a[x+dx[i]][y+dy[i]]) t += j;
            printf("%d ", type[t]);
            int cnt=0, nx=x, ny=y;
 
            int ddx = (a[x+1][y]) ? 1 : -1;
            while(a[nx][y]) {
                vis[nx][y] = 1;
                nx += ddx;
                cnt++;
            }
            printf("%d ", cnt);
 
            cnt = 0;
            int ddy = (a[x][y+1]) ? 1 : -1;
            while(a[x][ny]) {
                vis[x][ny] = 1;
                ny += ddy;
                cnt++;
            }
            printf("%d\n", cnt);
        }
    }
}