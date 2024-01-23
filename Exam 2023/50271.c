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
 
char *reserved[12] = {
    "if", "else", "while", "for",
    "switch", "case", "break", "return",
    "void", "int", "float", "char"
};
 
bool isReserved(char *s) {
    rep(i,0,12) if(strcmp(s,reserved[i]) == 0) return true;
    return false;
}
 
bool isNumber(char *s) {
    int len = strlen(s);
    rep(i,0,len) if(!isdigit(s[i])) return false;
    return true;
}
 
signed main() {
    char str[1024];
    char key[32][32];
    int cnt[32] = {0}, size = 0;
    char *delim = " ,.?!:;=<>+-*/%%(){}[]&|\t\n";
    while(fgets(str, 1024, stdin) != NULL) {
        char *s = strtok(str, delim);
        while(s != NULL) {
            if(isReserved(s) || isNumber(s)) {
                s = strtok(NULL, delim);
                continue;
            }
            if(strlen(s) > 24) s[24] = '\0';
            bool find = false;
            rep(i,0,size) {
                if(strcmp(s, key[i]) == 0) {
                    cnt[i]++;
                    find = true;
                    break;
                }
            }
            if(!find) {
                strcpy(key[size], s);
                cnt[size]++;
                size++;
            }
            s = strtok(NULL, delim);
        }
    }
    rep(i,0,size) printf("%s %d\n", key[i], cnt[i]);
}