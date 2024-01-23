#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) (a)>(b) ? (a) : (b)
#define min(a,b) (a)<(b) ? (a) : (b)
#define ll long long
#define oo 1e9
 
signed main() {
    int r, c, a[605][605], t, s;
    scanf("%d%d", &r, &c);
    rep(i,0,r) rep(j,0,c) scanf("%d", &a[i][j]);
    int x1=0, y2=c;
    while(scanf("%d%d", &t, &s) != EOF) {
        if(t==1) {
            rep(i,0,s) rep(j,0,y2) a[x1+s+i][j] += a[x1+s-1-i][j];
            x1 += s;
        } else if(t==2) {
            rep(j,0,s) rep(i,x1,r) a[i][y2-s-1-j] += a[i][y2-s+j];
            y2 -= s;
        } else {
            rep(i,0,s) rep(j,i+1,s) {
                a[x1+j][y2-s+i] += a[x1+i][y2-s+j];
                a[x1+i][y2-s+j] = 0;
            }
        }
    }
    rep(i,x1,r) rep(j,0,y2) printf("%d%c", a[i][j], " \n"[j==y2-1]);
}