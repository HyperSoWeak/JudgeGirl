#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) (a)>(b) ? (a) : (b)
#define min(a,b) (a)<(b) ? (a) : (b)
#define ll long long
#define oo 1e9
 
signed main() {
    int k, a, r=0;
    bool f=false;
    scanf("%d", &k);
    while(scanf("%d", &a) != EOF) {
        if(!f && (r*10+a)/k!=0) f = true;
        if(f) printf("%d\n", (r*10+a)/k);
        r = (r*10+a)%k;
    }
    if(!f) printf("0");
}