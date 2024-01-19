#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) (a)>(b) ? (a) : (b)
#define min(a,b) (a)<(b) ? (a) : (b)
#define ll long long
#define oo 1e9
 
int p(int x, int n) {
    int ans = 1;
    while(n--) ans *= x;
    return ans;
}
 
signed main() {
    int w, x, y, z;
    scanf("%d%d%d%d", &w, &x, &y, &z);
    for(int d=1; d<w/4; ++d) {
        for(int c=d+1; c+d<w/2; ++c) {
            for(int b=c+1, a=w-b-c-d; b<a; ++b, a=w-b-c-d) {
                if(p(a,2)+p(b,2)+p(c,2)+p(d,2) != x) continue;
                if(p(a,3)+p(b,3)+p(c,3)+p(d,3) != y) continue;
                if(p(a,4)+p(b,4)+p(c,4)+p(d,4) != z) continue;
                printf("%d\n%d\n%d\n%d", a, b, c, d);
                return 0;
            }
        }
    }
    printf("-1");
}