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
 
int rec(int x, int y, int m[12][12], int X) {
    if(x==X-1 && y==0) return 1;
    if(x==X || y==-1 || m[x][y]==0) return 0;
    return rec(x+1,y,m,X) + rec(x,y-1,m,X);
}
 
signed main() {
    int X, Y, m[12][12];
    scanf("%d%d", &X, &Y);
    rep(i,0,X) rep(j,0,Y) scanf("%d", &m[i][j]);
    printf("%d", rec(0,Y-1,m,X));
}