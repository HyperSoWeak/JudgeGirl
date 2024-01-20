#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))
#define OO 1e9
#define ERR 2e9+7
 
signed main() {
    int t[7] = {1000, 500, 100, 50, 10, 5, 1};
 
    int n;
    while(scanf("%d", &n) != EOF) {
        rep(i,0,7) {
            printf("%d%c", n/t[i], " \n"[i==6]);
            n %= t[i];
        }
    }
}