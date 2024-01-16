#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) (a)>(b) ? (a) : (b)
#define min(a,b) (a)<(b) ? (a) : (b)
#define ll long long
#define oo 1e9
 
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
 
void permutation(int a[10], int idx[10], bool vis[10], int d, int n) {
    if(d == n) {
        rep(i,0,n) printf("%d%c", a[idx[i]], " \n"[i==n-1]);
        return;
    }
    rep(i,0,n) {
        if(!vis[i]) {
            idx[d] = i;
            vis[i] = true;
            permutation(a, idx, vis, d+1, n);
            vis[i] = false;
        }
    }
}
 
signed main() {
    int n, a[10], idx[10];
    bool vis[10];
    scanf("%d", &n);
    rep(i,0,n) vis[i] = false;
    rep(i,0,n) scanf("%d", &a[i]);
    rep(i,0,n-1) rep(j,0,n-1-i) if(a[j]>a[j+1]) swap(&a[j], &a[j+1]);
    permutation(a, idx, vis, 0, n);
}