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
 
signed main() {
    int x, y;
    char one, zero;
    scanf("%d%d", &y, &x);
    scanf(" %c %c", &one, &zero);
    unsigned int a;
    int cnt = 0;
    int round = x*y / 32 + 1;
    rep(p,0,round) {
        scanf("%u", &a);
        bool b[32];
        rep(i,0,32) {
            b[31-i] = a & 1;
            a >>= 1;
        }
        rep(i,0,32) {
            if(x == 0) return 0;
            printf("%c", b[i] ? one : zero);
            cnt++;
            if(cnt == y) {
                printf("\n");
                cnt = 0;
                x--;
            }
        }
    }
}