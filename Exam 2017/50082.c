#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define oo 1e9
 
int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }
 
signed main() {
    int t,a,b,at=0,bt=0;
    while(scanf("%d%d%d",&t,&a,&b) != EOF) {
        at = max(at,t) + a;
        bt = max(bt,at) + b;
        printf("%d\n",bt);
    }
}