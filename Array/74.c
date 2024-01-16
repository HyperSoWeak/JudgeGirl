#include<stdio.h>
#include<stdlib.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
 
int main() {
    int n, m, a[100005], r[200005];
    scanf("%d", &n);
    rep(i,0,n) scanf("%d", &a[i]);
    scanf("%d", &m);
    rep(i,0,n) r[a[i]%m]++;
    rep(i,0,m) printf("%d\n", r[i]);
}