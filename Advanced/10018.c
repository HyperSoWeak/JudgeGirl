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
    int n, a, cnt[100005] = {0};
    scanf("%d", &n);
    rep(i,0,n) {
        scanf("%d", &a);
        if(cnt[a] > 0) {
            printf("%d", a);
            return 0;
        }
        cnt[a]++;
    }
}