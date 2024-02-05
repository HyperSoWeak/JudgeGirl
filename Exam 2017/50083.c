#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>
#include<math.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))
#define oo 1e9
#define ERR -(2e9+7)
 
signed main() {
    int A, B, R, w;
    scanf("%d%d%d", &A, &B, &R);
    while(scanf("%d", &w) != EOF) {
        if(R == 0) {
            if(A-w >= 0) A-=w;
            else if(B-w >= 0) B-=w;
        } else {
            int a = A-w, b = B-w;
            if(a>=0) {
                if(b>=0) {
                    if(a<=b) A-=w;
                    else B-=w;
                } else A-=w;
            } else if(b>=0) B-=w;
        }
        printf("%d %d\n", A, B);
    }
}