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
#define oo 1e9
 
signed main() {
    int x, y;
    if((scanf("%d", &x)==EOF) || (scanf("%d", &y)==EOF)) {
        printf("0");
        return 0;
    }
 
    int d = y-x>0 ? 1 : -1;
    x = y;
    int rlen = 2, llen = 0;
    int maxlen = 0, maxllen = 0;
    int lstart = 1, rstart = 1, now = 3, maxidx;
 
    while(scanf("%d", &y) != EOF) {
        if((y-x) * d > 0) rlen ++;
 
        else {
            if(llen != 0) { // record
                int newlen = llen + rlen - 1;
 
                if(newlen>maxlen || (newlen==maxlen && llen>maxllen)) {
                    maxlen = newlen;
                    maxllen = llen;
                    maxidx = lstart;
                }
            }
 
            d = -d;
            llen = rlen;
            rlen = 2;
            lstart = rstart;
            rstart = now - 1;
        }
 
        x = y;
        now ++;
    }
 
    if(llen == 0) printf("0");
    else {
        int newlen = llen + rlen - 1;
        if(newlen>maxlen || (newlen==maxlen && llen>maxllen)) {
            maxlen = newlen;
            maxidx = lstart;
        }
        printf("%d %d", maxlen, maxidx);
    }
}