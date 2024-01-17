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
#define ll long long
#define oo 1e9
 
int dist(const char *a, const char *b, int ia, int ib) {
    if(a[ia] == '\0') return strlen(b) - ib;
    if(b[ib] == '\0') return strlen(a) - ia;
    if(a[ia] == b[ib]) return dist(a, b, ia+1, ib+1);
 
    int x = dist(a,b,ia+1,ib);
    int y = dist(a,b,ia,ib+1);
    return 1 + min(x, y);
}
 
signed main() {
    int n = 0;
    char s[100][15];
    while(scanf("%s", s[n]) != EOF) n++;
 
    int mind=oo, id1, id2;
    rep(i,0,n) rep(j,i+1,n) {
        int d = dist(s[i], s[j], 0, 0);
        if(d < mind) {
            mind = d;
            id1 = i+1;
            id2 = j+1;
        }
    }
    printf("%d %d %d", mind, id1, id2);
}