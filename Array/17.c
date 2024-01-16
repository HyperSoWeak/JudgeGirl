#include<stdio.h>
#include<stdlib.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
 
int main() {
    int r, c, n, a[105]={0};
    scanf("%d %d", &r, &c);
    rep(i,0,r) {
        rep(j,0,c) {
            scanf("%d", &n);
            a[j] += n;
        }
    }
    rep(i,0,c) printf("%d\n", a[i]/r);
}