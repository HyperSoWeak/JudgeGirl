#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) (a)>(b) ? (a) : (b)
#define min(a,b) (a)<(b) ? (a) : (b)
#define oo 1e9
 
signed main() {
    int n, m, x, sum[1005]={0}, maxn[1005], minn[1005];
    rep(i,0,1005) maxn[i]=-oo, minn[i]=oo;
    scanf("%d%d",&n,&m);
    while(n--) {
        scanf("%d",&x);
        int r = x%m;
        sum[r] += x;
        maxn[r] = max(maxn[r], x);
        minn[r] = min(minn[r], x);
    }
    rep(i,0,m) printf("%d %d %d\n",sum[i],maxn[i],minn[i]);
}