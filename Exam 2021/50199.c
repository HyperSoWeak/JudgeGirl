#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) (a)>(b) ? (a) : (b)
#define min(a,b) (a)<(b) ? (a) : (b)
#define ll long long
#define oo 1e9
 
signed main() {
    int r, c, a[505][505];
    int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};
    rep(i,0,505) rep(j,0,505) a[i][j]=-1;
    scanf("%d%d", &r, &c);
    rep1(i,1,r) rep1(j,1,c) scanf("%d", &a[i][j]);
    rep1(i,1,r) rep1(j,1,c) {
        if(a[i][j]==0) continue;
        int cnt=0;
        rep(k,0,4) {
            if(a[i+dx[k]][j+dy[k]] == a[i][j]) cnt++;
        }
        if(cnt==2) {
            rep(k,0,4) if(a[i+dx[k]][j+dy[k]] == a[i][j]) a[i+dx[k]][j+dy[k]] = 0;
            a[i][j] = 0;
        }
    }
    rep1(i,1,r) rep1(j,1,c) printf("%d%c", a[i][j], " \n"[j==c]);
}