#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) (a)>(b) ? (a) : (b)
#define min(a,b) (a)<(b) ? (a) : (b)
#define oo 1e9
 
int abs(int a) { return a<0 ? -a : a; }
 
signed main() {
    int a,b,c,d,e,p,q,r,s,x,y,f;
    int dx[] = {0,1,0,-1};
    int dy[] = {1,0,-1,0};
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&p,&q,&r,&s,&x,&y,&f);
    int gold = abs(c*x+d*y)%e;
    while(f--) {
        int dir = abs(a*x+b*y)%4;
        x+=dx[dir], y+=dy[dir];
        if(x==p && y==q) x=r, y=s;
        else if(x==r && y==s) x=p, y=q;
        else gold += abs(c*x+d*y)%e;
    }
    printf("%d\n", gold);
    printf("%d %d", x, y);
}