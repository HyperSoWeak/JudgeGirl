#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))
#define ll long long
#define oo 1e9
 
signed main() {
    char str[105];
    while(gets(str) != 0) {
        int len = strlen(str);
        for(int i=len-1; i>=0; --i) {
            if(!isspace(str[i])) {
                str[i+1] = '\0';
                break;
            }
        }
        int i=0;
        while(isspace(str[i])) i++;
        for(; i<len; ++i) {
            if(str[i] == '\0') {
                putchar('\n');
                break;
            } else putchar(str[i]);
        }
    }
}