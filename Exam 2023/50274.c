#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define oo 1e9
#define MAXL 100005
#define MAXT 1005
 
signed main() {
    char A[MAXL], B[MAXL];
    gets(A), gets(B);
    char *delim = " .,!?;:[](){}";
    char *a[MAXT], *b[MAXT];
    int an = 1, bn = 1;
 
    char *s = strtok(A, delim);
    a[0] = s;
    while(s != NULL) {
        s = strtok(NULL, delim);
        a[an++] = s;
    }
 
    s = strtok(B, delim);
    b[0] = s;
    while(s != NULL) {
        s = strtok(NULL, delim);
        b[bn++] = s;
    }
 
    an--, bn--;
    int ai=0, bi=0;
    while(ai<an && bi<bn) {
        if(strcmp(a[ai],b[bi]) < 0) printf("%s", a[ai++]);
        else printf("%s", b[bi++]);
    }
    if(ai<an) rep(i,ai,an) printf("%s",a[i]);
    else rep(i,bi,bn) printf("%s",b[i]);
}