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
#define ll long long
 
signed main() {
    int type;
    scanf("%d", &type);
    if(type == 0) {
        char str[100005];
        scanf("%s", str);
        int len = strlen(str)+1;
        ll num = 0;
        rep(i,0,(len+7)/8) {
            rep(j,0,8) {
                if(str[8*i+j] == '\0') break;
                num |= (((ll)str[8*i+j]) << (7-j)*8);
            }
            printf("%lld\n", num);
            num = 0;
        }
    } else {
        int n;
        ll num;
        scanf("%d", &n);
        rep(i,0,n) {
            scanf("%lld", &num);
            rep(j,0,8) {
                char c = (num >> (7-j)*8) & 255LL;
                if(c == 0) break;
                putchar(c);
            }
        }
    }
}