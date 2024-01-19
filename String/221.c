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
#define MAXW 512
 
signed main() {
    int m, idx=0, wordCnt=0;
    char str[MAXW][256];
    scanf("%d", &m);
    int lenSum = -1;
    while(scanf("%s", str[idx]) != EOF) {
        int len = strlen(str[idx]);
        if(lenSum+len+1 <= m) {
            lenSum += len+1;
            wordCnt++;
        } else {
            int fi = (idx-wordCnt+MAXW) % MAXW;
            int spaces = wordCnt-1 + m-lenSum;
            printf("%s", str[fi]);
            rep(i,1,wordCnt) {
                int sp = spaces/(wordCnt-1) + (i <= spaces%(wordCnt-1));
                rep(j,0,sp) printf(" ");
                printf("%s", str[(fi+i) % MAXW]);
            }
            if(wordCnt == 1) rep(i,0,spaces) printf(" ");
            printf("\n");
            wordCnt = 1;
            lenSum = len;
        }
        idx = (idx+1) % MAXW;
    }
    int fi = (idx-wordCnt+MAXW) % MAXW;
    int spaces = wordCnt-1 + m-lenSum;
    printf("%s", str[fi]);
    rep(i,1,wordCnt) {
        int sp = spaces/(wordCnt-1) + (i <= spaces%(wordCnt-1));
        rep(j,0,sp) printf(" ");
        printf("%s", str[(fi+i) % MAXW]);
    }
    if(wordCnt == 1) rep(i,0,spaces) printf(" ");
}