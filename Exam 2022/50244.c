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
#define oo 1e9
#define MAXN 80
 
int N, t[MAXN][MAXN][MAXN];
bool vis[MAXN][MAXN][MAXN] = {0};
 
int dx[6] = {1,0,0,-1,0,0};
int dy[6] = {0,1,0,0,-1,0};
int dz[6] = {0,0,1,0,0,-1};
 
int isValid(int x, int y, int z) {
    return x>=0 && y>=0 && z>=0 && x<=z && y<=z && z<N;
}
 
int DFS(int num, int x, int y, int z) {
    if(!isValid(x,y,z) || vis[x][y][z] || t[x][y][z]!=num) return 0;
    vis[x][y][z] = true;
    int cnt = 1;
    rep(i,0,6) cnt += DFS(num,x+dx[i],y+dy[i],z+dz[i]);
    return cnt;
}
 
signed main() {
    scanf("%d", &N);
    rep(z,0,N) rep1(x,0,z) rep1(y,0,z) scanf("%d", &t[x][y][z]);
    int ans = 0, num;
    rep(z,0,N) rep1(x,0,z) rep1(y,0,z) {
        if(!vis[x][y][z]) {
            int res = DFS(t[x][y][z],x,y,z);
            if(res>ans || (res==ans && t[x][y][z]>num)) {
                ans = res;
                num = t[x][y][z];
            } 
        }
    }
    printf("%d %d", num, ans);
}