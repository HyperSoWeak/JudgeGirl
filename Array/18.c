#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define oo 1e9
 
int main() {
    int r,c,a[105][105];
    int dx[]={-1,0,1,0};
    int dy[]={0,1,0,-1};
    scanf("%d%d",&r,&c);
    rep(i,0,105) rep(j,0,105) a[i][j] = -oo;
    rep1(i,1,r) rep1(j,1,c) scanf("%d",&a[i][j]);
    rep1(i,1,r) rep1(j,1,c) {
        int flag = 1;
        rep(k,0,4) if(a[i][j] <= a[i+dx[k]][j+dy[k]]) flag = 0;
        if(flag) printf("%d\n",a[i][j]);
    }
}