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
 
int rec(int x, int y, int X, int Y) {
    if(x==X-1 && y==Y-1) return 1;
    if(x>=X || y>=Y) return 0;
    return rec(x+1, y, X, Y) + rec(x, y+1, X, Y);
}
 
signed main() {
    int X, Y;
    scanf("%d%d", &X, &Y);
    printf("%d", rec(0,0,X,Y));
}