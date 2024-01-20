#include<stdio.h>
#include<stdlib.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define oo 1e9
 
int main() {
    int a,li[4]={oo,oo,oo,oo},i=0,fd[4]={-oo,-oo,-oo,-oo},sd[4]={-oo,-oo,-oo,-oo},fi[4],si[4];
    while(scanf("%d", &a) != EOF) {
        int d = i-li[a];
        if(d>fd[a]) {
            sd[a] = fd[a];
            si[a] = fi[a];
            fd[a] = d;
            fi[a] = i;
        } else if(d==fd[a]) {
            fd[a] = d;
            fi[a] = i;
        } else if(d>=sd[a]) {
            sd[a] = d;
            si[a] = i;
        }
        li[a] = i;
        i++;
    }
    rep1(j,1,3) printf("%d %d %d\n", sd[j], si[j]-sd[j], si[j]);
}