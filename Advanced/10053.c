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
 
int winState(int sx, int sy) {
    if(sx > sy) return 0;
    if(sy > sx) return 1;
    return 2;
}
 
void solve(int a[4][4], int vis[4][4], int n, int x, bool turn, int sx, int sy, int ans[3]) {
    if(turn == 0) {
        bool f = false;
        rep(i,0,n) {
            if(!vis[x][i]) {
                f = true;
                vis[x][i] = 1;
                solve(a,vis,n,i,1,sx+a[x][i],sy,ans);
                vis[x][i] = 0;
            }
        }
        if(!f) ans[winState(sx, sy)]++;
    } else {
        bool f = false;
        rep(i,0,n) {
            if(!vis[i][x]) {
                f = true;
                vis[i][x] = 1;
                solve(a,vis,n,i,0,sx,sy+a[i][x],ans);
                vis[i][x] = 0;
            }
        }
        if(!f) ans[winState(sx, sy)]++;
    }
}
 
signed main() {
    int n, a[4][4];
    while(scanf("%d", &n) != EOF) {
        rep(i,0,n) rep(j,0,n) scanf("%d", &a[i][j]);
        int vis[4][4] = 0;
        int ans[3] = {0};
        rep(i,0,n) {
            vis[0][i] = 1;
            solve(a,vis,n,i,1,a[0][i],0,ans);
            vis[0][i] = 0;
        }
        printf("%d %d %d\n", ans[0], ans[1], ans[2]);
    }
}