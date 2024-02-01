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
#define MAXL 1024
 
int cnt = 0;
 
void gen(int idx, int k, int l, int n, char *s) {
    if(cnt == n) return;
    if(idx == l) {
        rep(i,0,l) putchar(s[i]);
        putchar('\n');
        cnt++;
        return;
    }
    int t = 'z'-s[idx-1];
    rep(i,0,k-t) {
        s[idx] = 'a' + i;
        gen(idx+1, k, l, n, s);
    }
    rep(i,0,min(k,t)) {
        s[idx] = s[idx-1] + i + 1;
        gen(idx+1, k, l, n, s);
    }
}
 
signed main() {
    int k, l, n, cnt=0;
    char s[MAXL+1];
    scanf("%c %d%d%d", &s[0], &k, &l, &n);
    gen(1,k,l,n,s);
}