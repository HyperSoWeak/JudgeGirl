#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define oo 1e9
 
int max(int a, int b) { return a>b ? a : b; }
int min(int a, int b) { return a<b ? a : b; }
 
signed main() {
    int k,a[20005],b[20005],x,y;
    scanf("%d", &k);
    rep(i,0,k) scanf("%d", &a[i]);
    rep(i,0,k) scanf("%d", &b[i]);
    while(scanf("%d%d", &x, &y) != EOF) {
        if(x==k) b[y] = a[y];
        else if(y==k) b[x] = 0;
        else {
            if(b[x] >= a[y]-b[y]) {
                b[x] -= a[y]-b[y];
                b[y] = a[y];
            } else {
                b[y] += b[x];
                b[x] = 0;
            }
        }
    }
    rep(i,0,k-1) printf("%d ", b[i]);
    printf("%d", b[k-1]);
}