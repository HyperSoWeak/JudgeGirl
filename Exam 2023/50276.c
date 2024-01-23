#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define oo 1e9
#define MAXN 55
 
bool isValid(int x, int y, int n) {
    return (x>=0 && y>=0 && x<n && y<n);
}
 
bool Find(char m[MAXN][MAXN], bool vis[MAXN][MAXN], int x, int y, int n, bool print, int *rx, int *ry) {
    if(!isValid(x,y,n) || vis[x][y] || m[x][y]=='0') return false;
    vis[x][y] = true;
    if(print) putchar(m[x][y]);
 
    int dx[] = {1,0,-1,0};
    int dy[] = {0,1,0,-1};
    bool find = 0;
    rep(i,0,4) {
        find = find || Find(m,vis,x+dx[i],y+dy[i],n,print,rx,ry);
    }
    if(!find) *rx = x, *ry = y;
    return true;
}
 
signed main() {
    int n, x, y;
    char m[MAXN][MAXN];
    scanf("%d", &n);
    rep(i,0,n) scanf("%s", m[i]);
    rep(i,0,n) rep(j,0,n) {
        if(m[i][j] != '0') {
            x = i, y = j;
            break;
        }
    }
 
    int x1, y1, x2, y2;
    bool v1[MAXN][MAXN] = {0};
    Find(m,v1,x,y,n,false,&x1,&y1);
    bool v2[MAXN][MAXN] = {0};
    Find(m,v2,x1,y1,n,false,&x2,&y2);
 
    int hx, hy;
    if(m[x1][y1]<m[x2][y2] ||
       (m[x1][y1]==m[x2][y2] && x1<x2) ||
       (m[x1][y1]==m[x2][y2] && x1==x2 && y1<y2)) hx = x1, hy = y1;
    else hx = x2, hy = y2;
 
    bool v3[MAXN][MAXN] = {0};
    Find(m,v3,hx,hy,n,true,&x1,&y1);
}