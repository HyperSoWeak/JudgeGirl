#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) (a)>(b) ? (a) : (b)
#define min(a,b) (a)<(b) ? (a) : (b)
#define oo 1e9
 
signed main() {
    int n,a[2][1005],an[2]={0},x;
    scanf("%d",&n);
    while(n--) {
        scanf("%d",&x);
        a[x&1][an[x&1]++] = x;
    }
    for(int i=1;i>=0;--i) rep(j,0,an[i]) printf("%d%c",a[i][j]," \n"[j==an[i]-1]);
}