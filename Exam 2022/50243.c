#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define int long long
const int IINF = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7;
const int MN = 2e5+5;

typedef struct {
    int fi, se;
} pii;

int n, m;
pii a[5005];
int has[64];
int mn = INF, ans[64];

int check() {
    rep(i,0,m) if(!has[a[i].fi] && !has[a[i].se]) return 0;
    return 1;
}

void sol(int p, int cnt) {
    if(cnt >= mn) return;
    if(p == n) {
        if(check()) {
            mn = cnt;
            memcpy(ans, has, sizeof(has));
        }
        return;
    }
    has[p] = 1;
    sol(p+1, cnt+1);
    has[p] = 0;
    sol(p+1, cnt);
}

signed main() {
    scanf("%lld%lld", &n, &m);
    rep(i,0,m) scanf("%lld%lld", &a[i].fi, &a[i].se);
    sol(0, 0);
    rep(i,0,n) if(ans[i]) printf("%lld\n", i);
}
