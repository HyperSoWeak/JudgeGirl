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
 
int a[10], n, no[10][10];
bool vis[10];
 
void perm(int len) {
    if(len == n) {
        rep(i,0,n) printf("%c", 'A'+a[i]);
        printf("\n");
        return;
    }
 
    rep(i,0,n) {
        if(vis[i]) continue;
        if(no[i][len]) continue;
 
        a[len] = i;
        vis[i] = 1;
        perm(len+1);
        vis[i] = 0;
    }
}
 
signed main() {
    int m, x, y;
    while(scanf("%d%d", &n, &m) != EOF) {
        // init
        rep(i,0,10) {
            rep(j,0,10) no[i][j] = 0;
            vis[i] = 0;
        }
 
        rep(i,0,m) {
            scanf("%d%d", &x, &y);
            no[x-1][y-1] = 1;
        }
 
        perm(0);
    }
}