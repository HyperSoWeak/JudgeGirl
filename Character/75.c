#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) (a)>(b) ? (a) : (b)
#define min(a,b) (a)<(b) ? (a) : (b)
#define oo 1e9
 
signed main() {
    int cnt[26] = {0};
    char a;
    while(scanf("%c", &a) != EOF) {
        if(a>=65 && a<=90) cnt[a-65]++;
        else if(a>=97 && a<=122) cnt[a-97]++;
    }
    rep(i,0,26) printf("%d\n", cnt[i]);
}