#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))
#define ll long long
#define oo 1e9
#define MAXN 500
 
signed main() {
    int X, Y, type, x, y, m[MAXN][MAXN];
    int dx[] = {1,0,-1,0,1,1,-1,-1};
    int dy[] = {0,1,0,-1,1,-1,1,-1};
    int t[4][2] = { {0,0}, {0,8}, {4,8}, {0,4} };
    scanf("%d%d", &Y, &X);
    rep(j,0,Y) rep(i,0,X) m[i][j] = 0;
    while(scanf("%d%d%d", &type, &x, &y) != EOF) {
        m[x][y] = 1;
        rep(i,t[type][0],t[type][1]) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            while(nx>=0 && ny>=0 && nx<X && ny<Y && m[nx][ny]==0) {
                m[nx][ny] = 1;
                nx += dx[i];
                ny += dy[i];
            } 
        }
    }
     rep(j,0,Y) rep(i,0,X) printf("%d%c", m[i][j], " \n"[i==X-1]);
}