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
#define MAXN 1000
 
bool vis[MAXN][MAXN] = {0};
int ax[MAXN*MAXN], ay[MAXN*MAXN];
 
signed main() {
    int N, M, Q, lx, ly, rx, ry;
    scanf("%d%d%d", &N, &M, &Q);
    while(Q--) {
        scanf("%d%d%d%d", &lx, &ly, &rx, &ry);
        int idx = 0;
        rep1(x,lx,rx) rep1(y,ly,ry) {
            if(!vis[x][y]) {
                vis[x][y] = 1;
                ax[idx] = x;
                ay[idx] = y;
                idx++;
            }
        }
        printf("%d", idx);
        rep(i,0,idx) printf(" (%d, %d)", ax[i], ay[i]);
        printf("\n");
    }
}