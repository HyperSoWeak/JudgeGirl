#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) (a)>(b) ? (a) : (b)
#define min(a,b) (a)<(b) ? (a) : (b)
#define ll long long
#define oo 1e9
 
int abs(int x) { return x < 0 ? -x : x; }
 
signed main() {
    int a,b,c,d,e,x[3],y[3],cnt[3];
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
    scanf("%d%d",&x[0],&x[1]);
    rep(i,0,2) {
        cnt[i] = 0;
        y[i] = x[i];
        while(y[i]<d || y[i]>e) {
            y[i] = (a*y[i] + b) % c;
            cnt[i]++;
        }
    }
    while(scanf("%d",&x[2]) != EOF) {
        cnt[2] = 0;
        y[2] = x[2];
        while(y[2]<d || y[2]>e) {
            y[2] = (a*y[2] + b) % c;
            cnt[2]++;
        }
 
        int p = max(cnt[0],max(cnt[1],cnt[2]));
        int q = min(cnt[0],min(cnt[1],cnt[2]));
        if(p-q==2 && (2*cnt[0]==p+q || 2*cnt[1]==p+q || 2*cnt[2]==p+q)) {
            printf("%d %d %d", x[0], x[1], x[2]);
            return 0;
        }
 
        rep(i,0,2) {
            x[i] = x[i+1];
            y[i] = y[i+1];
            cnt[i] = cnt[i+1];
        }
    }
    printf("Not found");
}