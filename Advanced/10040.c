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
#define OO 1e9
#define ERR 2e9+7
 
bool exist(char s[], char t[]) {
    int sl = strlen(s);
    int tl = strlen(t);
    rep(i,0,sl-tl+1) {
        bool find = true;
        rep(j,0,tl) if(s[i+j] != t[j]) {
            find = false;
            break;
        }
        if(find) return true;
    }
    return false;
}
 
signed main() {
    int n, q;
    char s[200][55], t[55];
    scanf("%d", &n);
    rep(i,0,n) scanf("%s", s[i]);
    scanf("%d", &q);
    while(q--) {
        scanf("%s", t);
        int cnt = 0;
        rep(i,0,n) cnt += exist(s[i], t);
        printf("%d\n", cnt);
    }
}