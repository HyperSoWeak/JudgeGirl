#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>
#include<math.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))
#define OO 1e9
#define ERR 2e9+7
 
signed main() {
    int n, a, vis[105];
    rep(i,0,105) vis[i] = -1;
    scanf("%d", &n);
    rep(i,0,n) {
        scanf("%d", &a);
        printf("%d", i);
        if(vis[a] != -1) {
            printf(" %d %d", vis[a], a);
            vis[a] = -1;
        } else vis[a] = i;
        printf("\n");
    }
}