#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>
#include<math.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))
#define OO 1e9
#define ERR 2e9+7
#define MAXN 500
 
void PrintMap(int X, int Y, int a[MAXN][MAXN]) {
    rep(y,0,Y) rep(x,0,X) printf("%d%c", a[x][y], " \n"[x==X-1]);
}
 
bool InMap(int X, int Y, int x, int y) {
    return (x>=0 && x<X && y>=0 && y<Y);
}
 
signed main() {
    int dx[] = {1,0,-1,0};
    int dy[] = {0,1,0,-1};
    int X, Y, x, y, e, O, ox, oy, ow, a[MAXN][MAXN] = 0;
    scanf("%d%d", &Y, &X);
    scanf("%d%d%d", &y, &x, &e);
    a[x][y] = e;
    scanf("%d", &O);
    rep(i,0,O) {
        scanf("%d%d%d", &oy, &ox, &ow);
        a[ox][oy] = ow;
    }
    int cmd;
    while(scanf("%d", &cmd) != EOF) {
        if(cmd == 0) {
            PrintMap(X,Y,a);
        } else {
            cmd--;
            int nx = x+dx[cmd];
            int ny = y+dy[cmd];
            int w = 0;
            while(InMap(X,Y,nx,ny) && a[nx][ny] != 0) {
                w += a[nx][ny];
                nx += dx[cmd];
                ny += dy[cmd];
            }
            if(w>e || !InMap(X,Y,nx,ny)) continue;
            while(nx != x+dx[cmd] || ny != y+dy[cmd]) {
                a[nx][ny] = a[nx-dx[cmd]][ny-dy[cmd]];
                nx -= dx[cmd];
                ny -= dy[cmd];
            }
            a[nx][ny] = e-w;
            a[x][y] = 0;
            e -= w, x = nx, y = ny;
        }
    }
}