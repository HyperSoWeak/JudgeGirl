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
#define oo 1e9
#define ERR -(2e9+7)
#define MAXN 105
 
void Sol(int x, int n, int l, int used[], int ans[], int rec[], bool e[10][10], int *len) {
    if(x == 0) {
        if(l > *len) {
            *len = l;
            rep(i,0,*len) ans[i] = rec[i];
        }
        return;
    }
 
    used[x] = true;
    rec[l] = x;
 
    rep(i,0,n) {
        if(e[x][i] && !used[i]) {
            Sol(i,n,l+1,used,ans,rec,e,len);
        }
    }
 
    used[x] = false;
}
 
signed main() {
    int n, len = -1;
    bool e[10][10] = {0};
 
    scanf("%d", &n);
    rep(i,0,n) rep(j,0,n) scanf("%d", &e[i][j]);
 
    int ans[10], rec[10];
    rep(i,0,n) {
        if(e[0][i]) {
            int used[10] = {0};
            Sol(i,n,0,used,ans,rec,e,&len);
        }
    }
 
    rep(i,0,len) printf("%d%c", ans[i], " \n"[i==len-1]);
}