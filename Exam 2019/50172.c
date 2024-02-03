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
    char s[35], last='\0';
    int indent = 0;
    bool vert = false;
    bool first = true;
    while(scanf("%s", s) != EOF) {
        int len = strlen(s);
        bool connect = (s[0]==last);
        if(vert) {
            rep(i,connect,len) {
                putchar('\n');
                rep(j,0,indent) putchar('*');
                putchar(s[i]);
            }
        } else {
            if(connect) {
                rep(i,1,len) putchar(s[i]);
            } else {
                if(first) first = false;
                else putchar('\n');
                rep(i,0,indent) putchar('*');
                rep(i,0,len) putchar(s[i]);
            }
            indent += len-1;
        }
        last = s[len-1];
        vert = !vert;
    }
}