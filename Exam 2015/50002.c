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
    int n, k, a[105][105], b[105][105], cnt[105][105], maxn=-oo, mx, my;
    int dx[] = {1,1,1,0,-1,-1,-1,0}, dy[] = {-1,0,1,1,1,0,-1,-1};
    rep(i,0,105) rep(j,0,105) b[i][j]=0, cnt[i][j]=0;
    scanf("%d%d", &n, &k);
    rep1(i,1,n) rep1(j,1,n) {
        scanf("%d", &a[i][j]);
        if(a[i][j] == 1) cnt[i][j]++;
    }
    rep(g,0,k) {
        rep1(i,1,n) rep1(j,1,n) b[i][j] = a[i][j];
        rep1(i,1,n) rep1(j,1,n) {
            int x = 0;
            rep(p,0,8) if(b[i+dx[p]][j+dy[p]] == 1) x++;
            if(b[i][j]==0 && x==3) a[i][j] = 1;
            else if(b[i][j]==1 && x!=2 && x!=3) a[i][j] = 0;
            if(a[i][j] == 1) cnt[i][j]++;
        }
    }
    rep1(i,1,n) rep1(j,1,n) printf("%d%c", a[i][j], " \n"[j==n]);
    rep1(i,1,n) rep1(j,1,n) {
        if(cnt[i][j] >= maxn) {
            maxn = cnt[i][j];
            mx = i, my = j;
        }
    }
    printf("%d %d", mx, my);
}