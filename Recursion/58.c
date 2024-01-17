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
#define ll long long
#define oo 1e9
#define MAXN 405
 
int N, M, cnt, idx=0, size[MAXN*MAXN/2+1];
int lake[MAXN][MAXN] = {0};
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
 
void DFS(int x, int y) {
    lake[x][y] = 0;
    cnt++;
    rep(k,0,4) {
        int nx = x+dx[k];
        int ny = y+dy[k];
        if(lake[nx][ny]) DFS(nx, ny);
    }
}
 
int cmp(const void *a, const void *b) {
    int A = *(int *)a;
    int B = *(int *)b;
    if(A==B) return 0;
    if(A>B) return -1;
    return 1;
}
 
signed main() {
    scanf("%d%d", &N, &M);
    rep1(i,1,N) rep1(j,1,M) scanf("%d", &lake[i][j]);
    rep1(i,1,N) rep1(j,1,M) {
        if(lake[i][j]) {
            cnt = 0;
            DFS(i, j);
            size[idx++] = cnt;
        }
    }
    qsort(size, idx, sizeof(int), cmp);
    rep(i,0,idx) printf("%d\n", size[i]);
}