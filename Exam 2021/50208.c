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
 
bool Check(char *str, int sl, int *idx, char *cmp) {
    int len = strlen(cmp);
    rep(i,0,len) if(*idx+i>=sl || str[*idx+i]!=cmp[i]) return false;
    *idx += len;
    return true;
}
 
signed main() {
    char s[1024];
    int cnt = 0;
    while(gets(s)) {
        int len = strlen(s);
        rep(i,0,len) {
            if(s[i]=='?') cnt++;
            else if(isalpha(s[i+1]) && (s[i]=='\t' || s[i]==' ' || s[i]==')')) {
                i++;
                if(Check(s,len,&i,"case")) {
                    if(s[i]==' ' || s[i]=='(') cnt++;
                } else if(Check(s,len,&i,"if") || Check(s,len,&i,"for") || Check(s,len,&i,"while")) {
                    while(i<len && s[i] == ' ') i++;
                    if(i<len && s[i] == '(') cnt++;
                }
            }
        }
    }
    printf("%d", cnt);
}