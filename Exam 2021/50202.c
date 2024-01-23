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
#define PI 3.1415926
 
signed main() {
    int h, w, k, a[205][205], ans=-oo;
    scanf("%d%d%d", &h, &w, &k);
    rep(i,0,h) rep(j,0,w) scanf("%d", &a[i][j]);
    for(int i=k-1; i+k-1<h; ++i) {
        for(int j=k-1; j+k-1<w; ++j) {
            int sum = 0;
            rep(p,0,k-1) {
                sum += a[i-k+1+p][j+p];
                sum += a[i+p][j+k-1-p];
                sum += a[i+k-1-p][j-p];
                sum += a[i-p][j-k+1+p];
            }
            ans = max(ans, sum);
        }
    }
    printf("%d", ans);
}