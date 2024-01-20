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
    int n, a, p;
    while(scanf("%d", &n) != EOF) {
        int cnt = 1;
        scanf("%d", &p);
        rep(i,0,n-1) {
            scanf("%d", &a);
            if(a!=p) {
                p = a;
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }
}