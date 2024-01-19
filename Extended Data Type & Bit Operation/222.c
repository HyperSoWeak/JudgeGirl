#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))
#define ll long long
#define oo 1e9
 
int hasEOF = 0;
int readchar() {
    static int N = 1<<20;
    static char buf[1<<20];
    static char *p = buf, *end = buf;
    if(p == end) {
        if((end = buf + fread(buf, 1, N, stdin)) == buf) {
            hasEOF = 1;
            return EOF;    
        }
        p = buf;
    }
    return *p++;
}
 
int ReadInt(int *x) {
    char c, neg;
    while((c = readchar()) < '-')
        if(c == EOF) return 0;
    neg = (c == '-') ? -1 : 1;
    *x = (neg == 1) ? c-'0' : 0;
    while((c = readchar()) >= '0')
        *x = (*x << 3) + (*x << 1) + c-'0';
    *x *= neg;
    return 1;
}
 
void Print(ll bookshelf) {
    for(int i=7; i>=0; --i) {
        ll ans = bookshelf >> (8*i) & 255;
        printf("%lld ", ans);
    }
    printf("\n");
}
 
int main() {
    int x;
    ll bookshelf = 0;
    while(ReadInt(&x)) {
        //Print(bookshelf);
 
        int found = -1;
        rep(i,0,8) {
            ll book = (bookshelf >> (8*i)) & 255;
            if(x == book) {
                found = i;
                break;
            }
        }
 
        if(found != -1) {
            ll left = found==7 ? 0 : bookshelf >> (8*(found+1));
            ll right = bookshelf & ((1ll<<(8*found)) - 1);
            bookshelf = left<<(8*(found+1)) | right<<8 | x;
        } else {
            bookshelf <<= 8;
            bookshelf |= x;
        }
    }
    Print(bookshelf);
    return 0;
}