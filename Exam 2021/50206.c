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
 
typedef struct Pattern {
    int id;
    int cnt;
} Pat;
 
int cmp(const void *a, const void *b) {
    Pat A = *(Pat *)a;
    Pat B = *(Pat *)b;
    if(A.cnt > B.cnt) return -1;
    if(A.cnt < B.cnt) return 1;
    return A.id - B.id;
}
 
signed main() {
    Pat pat[18000];
    rep(i,0,18000) {
        pat[i].id = i;
        pat[i].cnt = 0;
    }
 
    int id = 0, len = 0;
    char c;
    while((c=getchar()) != EOF) {
        if(!islower(c)) {
            id = 0, len = 0;
            continue;
        }
        len++;
        id = (id % 676) * 26 + (c-'a');
        if(len >= 3) pat[id].cnt++;
    }
 
    qsort(pat, 18000, sizeof(Pat), cmp);
 
    rep(i,0,3) {
        int x = pat[i].id;
        putchar('a' + x/676);
        putchar('a' + (x%676)/26);
        putchar('a' + x%26);
        putchar('\n');
    }
}