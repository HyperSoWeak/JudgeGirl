#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) (a)>(b) ? (a) : (b)
#define min(a,b) (a)<(b) ? (a) : (b)
#define ll long long
#define oo 1e9
 
ll N,l[15][15],r[15][15];
typedef struct Frac{
    ll p, q;
} Frac;
Frac ans[16];
 
ll gcd(ll a, ll b) {
    while(a%b != 0) {
        ll r = a%b;
        a = b;
        b = r;
    }
    return b;
}
 
Frac simplify(Frac a) {
    ll r = gcd(a.p, a.q);
    Frac ans = {a.p/r, a.q/r};
    return ans;
}
 
Frac mul(Frac a, Frac b) {
    Frac ans = {a.p*b.p, a.q*b.q};
    return simplify(ans);
}
 
Frac add(Frac a, Frac b) {
    Frac ans = {a.p*b.q + a.q*b.p, a.q*b.q};
    return simplify(ans);
}
 
void rec(int n, int i, Frac a) {
    if(n == N) {
        ans[i] = add(ans[i], a);
        return;
    }
    Frac lf = {l[n][i], l[n][i]+r[n][i]};
    Frac rf = {r[n][i], l[n][i]+r[n][i]};
    //Frac t = lf;
    //printf("%lld/%lld\n", t.p, t.q);
    rec(n+1, i, mul(a, lf));
    rec(n+1, i+1, mul(a, rf));
}
 
signed main() {
    rep(i,0,16) ans[i].p=0, ans[i].q=1;
    scanf("%lld", &N);
    rep(i,0,N) rep1(j,0,i) scanf("%lld%lld", &l[i][j], &r[i][j]);
    Frac a = {1, 1};
    rec(0, 0, a);
    rep(i,0,N+1) printf("%lld/%lld\n", ans[i].p, ans[i].q);
}