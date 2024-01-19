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
#define MAXLEN 128
 
signed main() {
    char a[MAXLEN], b[MAXLEN];
    scanf("%s", a);
    while(scanf("%s", b) != EOF) {
        int la = strlen(a);
        int lb = strlen(b);
        int maxlen = min(la, lb);
        for(int i=la-maxlen; maxlen>=0; --maxlen, ++i) {
            bool f = true;
            rep(j,0,maxlen) {
                if(a[i+j] != b[j]) {
                    f = false;
                    break;
                }
            }
            if(f) break;
        }
        rep(i,0,lb-maxlen) a[la+i] = b[maxlen+i];
        a[la+lb-maxlen] = '\0';
    }
    puts(a);
}