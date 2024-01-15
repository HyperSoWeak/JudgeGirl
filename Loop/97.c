#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) (a)>(b) ? (a) : (b)
#define min(a,b) (a)<(b) ? (a) : (b)
#define oo 1e9
 
int abs(int a) { return a<0 ? -a : a; }
 
typedef struct Lot {
    int x, y, c, n;
} Lot;
 
signed main() {
    int n, m, x, y;
    Lot a[10];
    scanf("%d", &n);
    rep(i,0,n) a[i].n = 0;
    rep(i,0,n) scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].c);
    scanf("%d", &m);
    while(m--) {
        scanf("%d%d", &x, &y);
        int idx, minn=oo, xi=oo, yi=oo;
        rep(i,0,n) {
            if(a[i].n >= a[i].c) continue;
            int dis = abs(x - a[i].x) + abs(y - a[i].y);
            if(dis<minn || (dis==minn && (a[i].x<xi || a[i].x==xi&&a[i].y<yi))) {
                minn = dis;
                idx = i;
                xi = a[i].x;
                yi = a[i].y;
            }
        }
        a[idx].n++;
    }
    rep(i,0,n) printf("%d\n", a[i].n);
}