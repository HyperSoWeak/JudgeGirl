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
#define P strtok(NULL, " ")
 
int ex(char *p) {
    if(p == NULL) return 2;
 
    if(!strcmp(p, "true")) return 1;
    if(!strcmp(p, "false")) return 0;
    if(!strcmp(p, "!")) {
        int a = ex(P);
        if(a==2) return 2;
        return !a;
    }
 
    if(!strcmp(p, "(")) {
        int a = ex(P);
        char *q = P;
        int b = ex(P);
        char *r = P;
        if(a==2 || q==NULL || b==2 || r==NULL || strcmp(r, ")")) return 2;
 
        if(!strcmp(q, "&&")) return a && b;
        if(!strcmp(q, "||")) return a || b;
 
        return 2;
    }
 
    return 2;
}
 
signed main() {
    char str[10000];
    char *s[3] = {
        "false",
        "true",
        "invalid",
    };
 
    while(gets(str) != NULL) {
        char *p = strtok(str, " ");
        int result = ex(p);
        if(P != NULL) result = 2;
        printf("%s\n", s[result]);
    }
}