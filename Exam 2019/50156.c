#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define oo 1e9
 
signed main() {
    int a,b,v[2],x[3],d,ad=-1,ap=1;
    scanf("%d%d%d%d%d%d%d",&a,&b,&v[1],&v[0],&x[0],&x[1],&x[2]);
    rep(p,0,b+3) {
        if(p<a) d = 0;
        else if(p<b) d = v[p%2];
        else d = x[p%3];
        if(d*ap > p*ad) ad=d, ap=p;
    }
    printf("%d\n",ap);
}