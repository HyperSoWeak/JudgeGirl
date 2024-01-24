#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>
#include<math.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))
#define OO 1e9
#define ERR 2e9+7
#define UI unsigned int
 
void PrintBit(UI n) {
    for(int i=31; i>=0; --i)
        printf("%d", (n>>i) & 1);
    printf("\n");
}
 
UI solve(UI n, int len) {
    if(len == 1) return n;
    len >>= 1;
    UI l = solve(n>>len, len);
    UI r = solve(n&((1<<len)-1), len);
    if(__builtin_popcount(n) & 1) return r<<len | l;
    else return l<<len | r;
}
 
signed main() {
    UI a;
    scanf("%u", &a);
    printf("%u\n", solve(a, 32));
}