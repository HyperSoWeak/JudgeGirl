#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) (a)>(b) ? (a) : (b)
#define min(a,b) (a)<(b) ? (a) : (b)
#define ll long long
#define oo 1e9
 
signed main() {
    int k, n, p=1, cnt=1, len=0, ans=0;
    scanf("%d", &k);
    while(scanf("%d", &n) && n < 0) continue;
    while(scanf("%d", &n) != EOF && n != 0) {
        if(n*p > 0) cnt++;
        else {
            if(cnt == k) {
                if(p == 1) {
                    if(len == 0) len += k;
                    else len += 2*k;
                }
            } else if(cnt < k) {
                if(len != k) ans = max(len, ans);
                len = 0;
            } else {
                if(p == 1) {
                    if(len == 0) len += k;
                    else len += 2*k;
                    if(len != k) ans = max(len, ans);
                    len = k;
                } else {
                    if(len != k) ans = max(len, ans);
                    len = 0;
                }
            }
            cnt = 1;
            p = -p;
        }
    }
    if(cnt >= k && p == 1) {
        if(len == 0) len += k;
        else len += 2*k;
    }
    if(len != k) ans = max(len, ans);
    printf("%d", ans);
}