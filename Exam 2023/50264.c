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
    int Y, X, L, W, x, y, s, k, a[205][205];
    scanf("%d%d%d%d", &Y, &X, &L, &W);
    scanf("%d%d%d%d", &x, &y, &s, &k);
    for(int j=Y-1; j>=0; --j) rep(i,0,X) scanf("%d", &a[i][j]);
 
    int hua = max(0, min(x-X, y-Y)) / s;
    k -= hua, x -= hua*s, y -= hua*s;
 
    while(k >= 0) {
        if(x+W-1<0 || y+L-1<0) break;
        if(x>=X || y>=Y) {
            x -= s, y -= s, k--;
            continue;
        }
 
        for(int j=Y-1; j>=0; --j) rep(i,0,X) {
            printf("%d%c", (i>=x && i<=x+W-1 && j>=y && j<=y+L-1) ? 0 : a[i][j], " \n"[i==X-1]);
        }
        printf("\n");
 
        x -= s, y -= s, k--;
    }
}