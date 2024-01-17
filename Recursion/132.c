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
#define oo 1e9
#define MAXN 20
#define MAXC 10
 
int N, C, P, a, b;
int edge[MAXN][MAXN] = {0}, len[MAXN] = {0};
int color[MAXN] = {0};
 
bool solve(int n) {
    bool colorUsed[MAXC] = {0};
    rep(i,0,len[n]) {
        int p = edge[n][i];
        colorUsed[color[p]] = 1;
    }
 
    rep1(c,1,C) { // choose color
        if(!colorUsed[c]) {
            color[n] = c;
            bool f = 1;
            rep(i,0,len[n]) {
                int p = edge[n][i];
                if(!color[p]) {
                    f = 0;
                    if(solve(p)) return true;
                }
            }
            if(f) return true;
        }
    }
 
    color[n] = 0;
    return false;
}
 
signed main() {
    scanf("%d%d%d", &N, &C, &P);
    rep(p,0,P) {
        scanf("%d%d", &a, &b);
        edge[a][len[a]++] = b;
        edge[b][len[b]++] = a;
    }
    rep(i,0,N) {
        if(!color[i]) {
            if(!solve(i)) {
                printf("no solution.\n");
                return 0;
            }
        }
    }
    rep(i,0,N) printf("%d\n", color[i]);
}