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
    int n, h1, h2, t1, t2, ans=0;
    scanf("%d%d%d", &n, &h1, &h2);
    t2 = h2 - h1;
    if(t2>0) ans += 3*t2;
    else ans -= 2*t2;
    rep(i,2,n) {
        h1 = h2;
        t1 = t2;
        scanf("%d", &h2);
        t2 = h2 - h1;
        if(t2>0) {
            if(t1>0) ans += 4*t2;
            else ans += 3*t2;
        } else {
            if(t1>0) ans -= 3*t2;
            else ans -= 2*t2;
        }
    }
    printf("%d", ans);
}