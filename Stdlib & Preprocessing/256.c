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
#define oo 1e9
#define ll long long
 
typedef struct Number {
    ll num;
    int cnt;
} Number;
 
int cmp(const void *a, const void *b) {
    const Number *A = (const Number *)a;
    const Number *B = (const Number *)b;
    if(A->cnt != B->cnt) return A->cnt - B->cnt;
    return A->num>B->num ? 1 : -1;
}
 
signed main() {
    Number a[1005];
    int n = 0;
    while(scanf("%lld", &a[n].num) != EOF) {
        a[n].cnt = __builtin_popcountll(a[n].num);
        n++;
    }
    qsort(a, n, sizeof(Number), cmp);
    rep(i,0,n) printf("%lld\n", a[i].num);
}