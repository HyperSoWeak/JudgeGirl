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
#define N 9
 
int dx[9] = {-1,-1,-1,0,0,0,1,1,1};
int dy[9] = {-1,0,1,-1,0,1,-1,0,1};
 
void PrintMap(int map[N][N]) {
    rep(i,0,N) rep(j,0,N) printf("%d%c", map[i][j], " \n"[j==N-1]);
    printf("\n");
}
 
bool isValid(int x, int y) {
    return (x>=0 && x<N && y>=0 && y<N);
}
 
bool CanPlace(int map[N][N], int x, int y) {
    if(!isValid(x, y)) return false;
    rep(k,0,9) {
        int nx = x+dx[k], ny = y+dy[k];
        if(isValid(nx, ny) && map[nx][ny]==0) return false;
    }
    return true;
}
 
bool Remain(int map[N][N], int x, int y) {
    if(!isValid(x, y)) return 0;
    return (map[x][y] != 0);
}
 
bool Solve(int map[N][N], int ans[N][N], int x, int y) {
    if(y == N) {
        if(Remain(map, x-1, y-2) || Remain(map, x-1, y-1)) return false;
        y=0, x++;
    }
    if(x == N) {
        rep(i,0,N) if(Remain(map, N-1, i) || Remain(map, N-2, i)) return false;
        return true;
    }
 
    if(Remain(map, x-1, y-2)) return false;
 
    if(CanPlace(map, x, y)) {
        ans[x][y] = 1;
        rep(k,0,9) {
            int nx = x+dx[k], ny = y+dy[k];
            if(isValid(nx, ny)) map[nx][ny]--;
        }
 
        if(Solve(map, ans, x, y+1)) return true;
 
        ans[x][y] = 0;
        rep(k,0,9) {
            int nx = x+dx[k], ny = y+dy[k];
            if(isValid(nx, ny)) map[nx][ny]++;
        }
    }
 
    if(Solve(map, ans, x, y+1)) return true;
 
    return false;
}
 
signed main() {
    int map[N][N], ans[N][N]=0;
    rep(i,0,N) rep(j,0,N) scanf("%d", &map[i][j]);
    if(Solve(map, ans, 0, 0)) {
        rep(i,0,N) rep(j,0,N) printf("%d%c", ans[i][j], " \n"[j==N-1]);
    } else printf("no solution\n");
}