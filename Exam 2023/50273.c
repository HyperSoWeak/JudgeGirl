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
 
int abs(int x) { return x < 0 ? -x : x; }
 
signed main() {
    char str[105][1005];
    int n = 0;
    while(scanf("%s", str[n]) != EOF) n++;
    strcpy(str[n],str[0]);
    int x[105], y[105];
    rep(i,0,n) {
        int al = strlen(str[i]);
        int bl = strlen(str[i+1]);
        bool flag = false;
        rep(a,0,al) {
            rep(b,0,bl) {
                if(str[i][a] == str[i+1][b]) {
                    y[i] = a;
                    x[(i+1)%n] = b;
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
    }
    int ans = 0;
    rep(i,0,n) ans += abs(x[i]-y[i]);
    printf("%d", ans);
}