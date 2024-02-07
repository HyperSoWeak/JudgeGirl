#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) (a)>(b) ? (a) : (b)
#define min(a,b) (a)<(b) ? (a) : (b)
#define ll long long
#define oo 1e9
 
int abs(int x) { return x>0 ? x : -x; }
 
signed main() {
    int n,k,m,d,a[10][10],b[10][10],sumb=0;
    scanf("%d%d%d%d",&n,&k,&m,&d);
    rep(i,0,n) rep(j,0,n) scanf("%d",&a[i][j]);
    rep(i,0,k) rep(j,0,k) {
        scanf("%d",&b[i][j]);
        sumb += b[i][j];
    }
    for(int i=n-k; i>=0; --i) {
        for(int j=n-k; j>=0; --j) {
            int cnt=0, sum=0;
            rep(x,0,k) {
                rep(y,0,k) {
                    if(a[x+i][y+j]!=b[x][y]) cnt++;
                    sum += a[x+i][y+j];
                }
            }
            if(cnt<=m && abs(sum-sumb)<=d) {
                printf("%d %d", i, j);
                return 0;
            }
        }
    }
    printf("-1 -1");
}