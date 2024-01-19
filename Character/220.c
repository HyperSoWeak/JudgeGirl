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
#define ERR 2e9+7
#define MAXC 5000
 
signed main() {
    int cnt = 0, g = 1;
    char c;
    while(true) {
        if(g) c = getchar();
        if(c == EOF) break;
        if(c == '.') {
            c = getchar();
            if(c == '.') {
                g = 0;
                continue;
            }
            if(c == EOF) {
                cnt++;
                break;
            }
            if(c == '\n') cnt++; // || c == '\0'
            else if(c == ' ') {
                c = getchar();
                if(c == ' ') cnt++;
            }
        }
        g = 1;
    }
    printf("%d\n", cnt);
}