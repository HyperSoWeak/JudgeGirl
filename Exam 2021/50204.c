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
#define MAXN 100
 
signed main() {
    int N, M, cube[MAXN][MAXN][MAXN], tmp[MAXN][MAXN];
    scanf("%d%d", &N, &M);
    rep(x,0,N) rep(y,0,N) rep(z,0,N) cube[x][y][z] = x*N*N + y*N + z;
    rep(m,0,M) {
        int type, idx;
        scanf("%d%d", &type, &idx);
        if(type == 0) {
            rep(y,0,N) rep(z,0,N) tmp[y][z] = cube[idx][N-z-1][y];
            rep(y,0,N) rep(z,0,N) cube[idx][y][z] = tmp[y][z];
        } else {
            rep(x,0,N) rep(y,0,N) tmp[x][y] = cube[N-y-1][x][idx];
            rep(x,0,N) rep(y,0,N) cube[x][y][idx] = tmp[x][y];
        }
    }
    rep(i,0,N) rep(j,0,N) rep(k,0,N) printf("%d%c", cube[i][j][k], " \n"[k==N-1]);
}