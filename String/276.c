#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) (a)>(b) ? (a) : (b)
#define min(a,b) (a)<(b) ? (a) : (b)
#define ll long long
#define oo 1e9
#define PI 3.1415926
 
signed main() {
    char s[128], key[8][5] = {"of", "and", "the", "at", "of.", "and.", "the.", "at."};
    while(scanf("%s", &s) != EOF) {
        bool f = false;
        rep(i,0,4) if(strcmp(s, key[i]) == 0) f = true;
        if(f) continue;
        f = false;
        rep(i,4,8) if(strcmp(s, key[i]) == 0) f = true;
        if(f) {
            printf("\n");
            continue;
        }
        printf("%c", toupper(s[0]));
        if(s[strlen(s) - 1] == '.') printf("\n");
    }
}