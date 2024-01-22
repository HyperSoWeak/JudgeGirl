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
#define ERR -(2e9+7)
#define MAXN 105
 
typedef struct Square {
    int left;
    int top;
    int right;
    int bottom;
} Square;
 
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
 
bool Sol(int idx, int n, int m[7][7], Square sq[], bool used[]) {    
    if(idx == n*n) return true;
 
    int x = idx / n + 1;
    int y = idx % n + 1;
 
    rep(i,0,n*n) {
        if(used[i]) continue;
        if(m[x][y-1] != -1 && sq[i].left != sq[m[x][y-1]].right) continue;
        if(m[x][y+1] != -1 && sq[i].right != sq[m[x][y+1]].left) continue;
        if(m[x-1][y] != -1 && sq[i].top != sq[m[x-1][y]].bottom) continue;
        if(m[x+1][y] != -1 && sq[i].bottom != sq[m[x+1][y]].top) continue;
 
        used[i] = true;
        m[x][y] = i;
        if(Sol(idx+1, n, m, sq, used)) return true;
        used[i] = false;
        m[x][y] = -1;
    }
 
    return false;
}
 
signed main() {
    Square sq[30];
    int n;
    while(scanf("%d", &n) != EOF) {
        rep(i,0,n*n) scanf("%d%d%d%d", &sq[i].left, &sq[i].top, &sq[i].right, &sq[i].bottom);
 
        int m[7][7];
        rep(i,0,7) rep(j,0,7) m[i][j] = -1;
        bool used[25] = {0};
        if(Sol(0, n, m, sq, used)) {
            rep1(i,1,n) rep1(j,1,n) printf("%d%c", m[i][j], " \n"[j==n]);
        } else printf("no solution\n");
    }
}