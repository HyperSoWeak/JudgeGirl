#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define oo 1e9
#define ll long long
 
int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }
 
signed main() {
    ll a;
    int ans=-oo,cnt=0,l=-1;
    while(scanf("%lld", &a) != EOF) {
        int d=1, b=a%10;
        while(a>=10) a/=10, d++;
        if(l==a) cnt+=d;
        else {
            ans = max(ans,cnt);
            cnt = d;
        }
        l = b;
    }
    ans = max(ans,cnt);
    printf("%d",ans);
}