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
#define MAXR 1000
#define MAXC 1000
 
int CountUpDown(int x, int y, int m[MAXR][MAXC], bool ap[]) {
    int ans = 0;
    rep(i,0,4) rep(j,0,4) {
        int u = m[x-1][y+i];
        int d = m[x+1][y+j];
        if(!ap[u] && !ap[d] && u+d==7) ans++;
    }
    return ans;
}
 
int Count(int x, int y, int m[MAXR][MAXC]) {
    bool ap[7] = {false};
    rep(i,0,4) {
        if(ap[m[x][y+i]]) return 0;
        else ap[m[x][y+i]] = true;
    }
    if(!(m[x][y]+m[x][y+2]==7 && m[x][y+1]+m[x][y+3]==7)) return 0;
    else return CountUpDown(x, y, m, ap);
}
 
signed main() {
    int m[MAXR][MAXC], R, C;
    scanf("%d%d", &R, &C);
    rep(i,0,R) rep(j,0,C) scanf("%d", &m[i][j]);
    int ans = 0;
    rep(i,1,R-1) rep(j,0,C-3) ans += Count(i, j, m);
    printf("%d", ans);
}