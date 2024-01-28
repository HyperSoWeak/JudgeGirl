#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define oo 1e9
 
int max(int a, int b) { return a > b? a : b; }
 
signed main() {
    int n, cnt1=0, cnt2=0, maxn=-oo;
    bool a[1005][1005];
    scanf("%d", &n);
    rep(i,0,n) rep(j,0,n) scanf("%d", &a[i][j]);
    rep(i,0,n) {
        rep(j,0,n) {
            if(a[i][j]) cnt1++;
            else {
                maxn = max(maxn, cnt1);
                cnt1 = 0;
            }
            if(a[j][i]) cnt2++;
            else {
                maxn = max(maxn, cnt2);
                cnt2 = 0;
            }
        }
        maxn = max(maxn, cnt1);
        maxn = max(maxn, cnt2);
        cnt1=0, cnt2=0;
    }
    rep(i,0,n) {
        rep(j,0,n) {
            if(i+j<n && a[j][i+j]) cnt1++;
            else {
                maxn = max(maxn, cnt1);
                cnt1 = 0;
            }
            if(i+j<n && a[i+j][j]) cnt2++;
            else {
                maxn = max(maxn, cnt2);
                cnt2 = 0;
            }
        }
        maxn = max(maxn, cnt1);
        maxn = max(maxn, cnt2);
        cnt1=0, cnt2=0;
    }
    printf("%d\n", maxn);
}