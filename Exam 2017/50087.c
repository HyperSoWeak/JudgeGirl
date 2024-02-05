#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))
#define oo 1e9
#define MAXN 2048
 
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
 
int balance(int p, int w[], int n) {
    int ans = 0;
    rep(i,0,n) {
        ans += (i-p) * w[i];
        if(ans > 0) return ans;
    }
    return ans;
}
 
signed main() {
    int n, w[MAXN];
    scanf("%d", &n);
    rep(i,0,n) scanf("%d", &w[i]);
 
    int t = 0;
    while(t <= n/2) {
        rep(p,1,n-1) if(balance(p,w,n) == 0) {
            printf("%d", w[0]);
            rep(i,1,n) {
                if(i==p) printf(" v");
                else printf(" %d", w[i]);
            }
            return 0;
        }
        swap(&w[t], &w[n-t-1]);
        t ++;
    }
}