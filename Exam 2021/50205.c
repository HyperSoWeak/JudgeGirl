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
    char c, p[128];
    int ans=0, num=0, mul=1;
    p['!'] = 1, p['@'] = 2, p['#'] = 3;
    p['$'] = 4, p['%'] = 5, p['^'] = 6;
    p['&'] = 7, p['('] = 9, p[')'] = 0;
    while(scanf("%c", &c) != EOF) {
        if(c=='+' || c=='*') {
            mul *= num;
            num = 0;
            if(c=='+') {
                ans += mul;
                mul = 1;
            }
        } else num = num*10+p[c];
    }
    mul *= num;
    ans += mul;
    printf("%d", ans);
}