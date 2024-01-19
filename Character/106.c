#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) (a)>(b) ? (a) : (b)
#define min(a,b) (a)<(b) ? (a) : (b)
#define ll long long
#define oo 1e9
 
signed main() {
    char s[1005];
    while(scanf("%s", s) && s[0]!='-') {
        int l = strlen(s);
        int x=0, y=0;
        rep(i,0,l) {
            x += (s[i]-'0');
            y += (s[i]-'0') * ((i%2)*2-1);
        }
        if((s[l-1]-'0')%2 == 0) printf("yes ");
        else printf("no ");
        if(x%3 == 0) printf("yes ");
        else printf("no ");
        if((s[l-1]-'0')%5 == 0) printf("yes ");
        else printf("no ");
        if(y%11 == 0) printf("yes\n");
        else printf("no\n");
    }
}