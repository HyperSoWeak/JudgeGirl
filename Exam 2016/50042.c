#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define oo 1e9
 
signed main() {
    int n,m,x,afn=-oo,afx,afy;
    scanf("%d%d",&n,&m);
    rep1(i,1,n) {
        int fn=-oo,sn=-oo,fi,si;
        rep1(j,1,m) {
            scanf("%d", &x);
            if(x >= fn) {
                sn=fn, si=fi;
                fn=x, fi=j;
            } else if(x >= sn) {
                sn=x, si=j;
            }
        }
        printf("%d %d\n", fi, si);
        if(fn >= afn) afn=fn, afx=i, afy=fi;
    }
    printf("%d %d", afx, afy);
}