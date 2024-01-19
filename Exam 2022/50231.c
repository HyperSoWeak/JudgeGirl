#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))
#define ll long long
#define oo 1e9
#define MAXN 105
#define MAXS (MAXN*MAXN)
#define MAXC 10
 
int N, S, C;
int t[MAXN][MAXN][MAXN];
int h[MAXN][MAXN];
int ht[MAXS][MAXC][2]; // value, pos
 
int Find(int key, int idx) {
    int hash = (77 * key + 2222) % S;
    rep(i,0,MAXC) {
        if(ht[hash][i][0] == key) {
            ht[hash][i][0] = 0;
            return ht[hash][i][1];
        }
    }
    // not found (insert)
    rep(i,0,MAXC) {
        if(ht[hash][i][0] == 0) {
            ht[hash][i][0] = key;
            ht[hash][i][1] = idx;
            return -1;
        }
    }
}
 
int GetKey(int x, int y) {
    if(h[x][y]-1 < 0) return -1;
    return t[x][y][h[x][y]-1];
}
 
void PrintHashTable() {
    printf("\n----------------\n");
    printf("Hash table:\n");
    rep(i,0,S) rep(j,0,C) printf("%d%c", ht[i][j][0], " \n"[j==C-1]);
    printf("----------------\n");
}
 
void PrintTop() {
    printf("\n----------------\n");
    printf("Top:\n");
    rep(i,0,N) {
        printf("%2d: ", i);
        rep(j,0,N) printf("%8d%c", GetKey(i, j), " \n"[j==N-1]);
    }
    printf("----------------\n");
}
 
signed main() {
    scanf("%d%d%d", &N, &S, &C);
    rep1(i,1,N) rep(x,0,i) rep(y,0,i) scanf("%d", &t[x][y][N-i]);
    rep(x,0,N) rep(y,0,N) h[x][y] = N - max(x, y);
 
    // hash table
    int idx = 0, mi[2];
    bool find = false;
    rep(x,0,N) rep(y,0,N) {
        int key = GetKey(x, y);
        int result = Find(key, idx);
        if(result != -1) {
            find = true;
            mi[0] = idx;
            mi[1] = result;
        }
        idx++;
    }
 
    // loop
    bool first = true;
    while(find) {
        //PrintTop();
        //PrintHashTable();
        int x[2] = {mi[0]/N, mi[1]/N};
        int y[2] = {mi[0]%N, mi[1]%N};
        int key = GetKey(x[0], y[0]);
        if(first) first = false;
        else printf(" ");
        printf("%d", key);
        rep(i,0,2) h[x[i]][y[i]]--;
 
        find = false;
        int ni[2];
        rep(i,0,2) {
            int k = GetKey(x[i], y[i]);
            if(k == -1) continue;
            int result = Find(k, mi[i]);
            if(result != -1) {
                find = true;
                ni[0] = mi[i];
                ni[1] = result;
            }
        }
        rep(i,0,2) mi[i] = ni[i];
    }
    //PrintTop();
    //PrintHashTable();
}