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
#define MAXN 100 // 100
#define MAXK MAXN * MAXN
#define MAXC 10
 
typedef struct Cube {
    char str[6];
    int x, y;
} Cube;
 
Cube tower[MAXN][MAXN][MAXN];
Cube hash[MAXK][MAXC];
int height[MAXN][MAXN];
int N, K, C = 10;
 
int Hash(const Cube *c) {
    int len = strlen(c->str);
    int ans = 0;
    rep(i,0,len) ans = ans*29 + (c->str[i]-'a'+1);
    return ans % K;
}
 
Cube Find(const Cube *c) { // and delete
    Cube empty = { .x = -1 };
    int h = Hash(c);
    rep(i,0,C) {
        if(!strcmp(hash[h][i].str, c->str)) { // find
            Cube ans = hash[h][i];
            hash[h][i] = empty;
            return ans;
        }
    }
    return empty;
}
 
bool Insert(Cube *c) {
    int h = Hash(c);
    rep(i,0,C) {
        if(hash[h][i].x == -1) { // empty space
            hash[h][i] = *c;
            return true;
        }
    }
    //printf("ERROR: Hash Table is full!\n");
    return false;
}
 
Cube GetKey(int x, int y) {
    Cube empty = { .x = -1 };
    if(height[x][y] == N) return empty; // end of tower
    return tower[height[x][y]++][x][y];
}
 
void ReadTower() {
    rep(layer,0,N) rep1(x,0,layer) rep1(y,0,layer) {
        scanf("%s", tower[layer][x][y].str);
        tower[layer][x][y].x = x;
        tower[layer][x][y].y = y;
    }
}
 
void PrintCube(Cube c) {
    printf("Cube: %s,\t(%d, %d)\n", c.str, c.x, c.y);
}
 
void Init() {
    rep(k,0,K) rep(c,0,C) {
        hash[k][c].x = -1;
    }
    rep(x,0,N) rep(y,0,N) {
        height[x][y] = max(x, y);
    }
}
 
signed main() {
    scanf("%d", &N);
    K = N * N;
    ReadTower();
    Init();
 
    Cube p1, p2;
    bool found = false;
    rep(x,0,N) rep(y,0,N) {
        Cube now = GetKey(x, y);
        //PrintCube(now);
        Cube res = Find(&now);
 
        if(res.x == -1) { // Not Found
            Insert(&now);
        } else { // Store
            found = true;
            p1 = now;
            p2 = res;
        }
    }
 
    while(found) {
        printf("%s\n", p1.str);
        found = false;
 
        p1 = GetKey(p1.x, p1.y);
        p2 = GetKey(p2.x, p2.y);
 
        if(p1.x != -1 && p1.y != -1 && strcmp(p1.str, p2.str)==0) {
            found = true;
            continue;
        }
 
        Cube r1 = { .x = -1 }, r2 = r1;
        if(p1.x != -1) r1 = Find(&p1);
        if(p2.x != -1) r2 = Find(&p2);
 
        if(r1.x != -1) { // Found p1
            found = true;
            Insert(&p2);
            p2 = r1;
        } else if(r2.x != -1) { // Found p2
            found = true;
            Insert(&p1);
            p1 = r2;
        }
    }
}