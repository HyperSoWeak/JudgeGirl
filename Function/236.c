#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define oo 1e9
 
int gcd(int a, int b) {
    while(a%b != 0) {
        int r = a%b;
        a = b;
        b = r;
    }
    return b;
}
int lcm(int a, int b) { return a/gcd(a, b)*b; }
 
signed main() {
    int n,ans=1;
    while(scanf("%d",&n)!=EOF) ans = lcm(ans,n);
    printf("%d", ans);
}