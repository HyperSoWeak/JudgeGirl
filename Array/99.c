#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) (a)>(b) ? (a) : (b)
#define min(a,b) (a)<(b) ? (a) : (b)
#define ll long long
#define oo 1e9
 
typedef struct Player {
    char name[64];
    int wx[256];
    int wy[256];
    int zx, zy;
    int x[65537];
    int y[65537];
    int r;
} Player;
 
int n, m, a;
Player p[10];
 
bool win(int i) {
    rep(j,0,m) {
        if(p[i].wx[j] == m) return true;
        if(p[i].wy[j] == m) return true;
    }
    if(p[i].zx==m || p[i].zy==m) return true;
    return false;
}
 
signed main() {
    scanf("%d%d", &n, &m);
    rep(i,0,n) {
        scanf("%s", &p[i].name);
        rep(x,0,m) rep(y,0,m) {
            scanf("%d", &a);
            p[i].x[a] = x;
            p[i].y[a] = y;
        }
        // initialize
        rep(j,0,256) {
            p[i].wx[j] = 0;
            p[i].wy[j] = 0;
        }
        p[i].zx = 0, p[i].zy = 0;
    }
 
    while(scanf("%d", &a) != EOF) {
        bool over = false;
        rep(i,0,n) {
            int x = p[i].x[a];
            int y = p[i].y[a];
            p[i].wx[x]++;
            p[i].wy[y]++;
            if(x==y) p[i].zx++;
            if(x==m-y-1) p[i].zy++;
 
            if(win(i)) {
                if(!over) {
                    printf("%d %s", a, p[i].name);
                    over = true;
                } else printf(" %s", p[i].name);
            }
        }
        if(over) return 0;
    }
}