#include<stdio.h>
#include<string.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define ll long long
#define oo 1e9
 
int abs(int a) { return a<0 ? -a : a; }
int min(int a, int b) {
    if(a<b) return a;
    else return b;
}
 
int dist(const char *a, const char *b, int ia, int ib, int mind, int d) {
    int la = strlen(a) - ia;
    int lb = strlen(b) - ib;
    if(abs(la-lb) + d >= mind) return oo;
 
    if(la * lb == 0) return abs(la - lb);
    if(a[ia] == b[ib]) return dist(a, b, ia+1, ib+1, mind, d);
 
    return 1 + min(dist(a,b,ia+1,ib,mind,d+1), dist(a,b,ia,ib+1,mind,d+1));
}
 
signed main() {
    int n = 0;
    char s[100][15];
    while(scanf("%s", s[n]) != EOF) n++;
 
    int mind=oo, id1, id2;
    rep(i,0,n) rep(j,i+1,n) {
        int d = dist(s[i], s[j], 0, 0, mind, 0);
        if(d < mind) {
            mind = d;
            id1 = i+1;
            id2 = j+1;
        }
    }
    printf("%d %d %d", mind, id1, id2);
}