#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
#define rep1(i,a,b) for(int i=a; i<=b; ++i)
#define oo 1e9
 
bool Check(char *str, char *suf, int len) {
    int l = strlen(suf);
    rep(i,0,l) {
        if(suf[i] != str[len-l+i]) return false;
    }
    return true;
}
 
signed main() {
    int freq[20] = {0};
    char suf[20][5] = {
        "able",
        "ary",
        "ed",
        "ence",
        "ful",
        "hood",
        "ical",
        "ing",
        "ish",
        "ism",
        "ist",
        "ive",
        "ize",
        "less",
        "ly",
        "ment",
        "ness",
        "ous",
        "ship",
        "tion"
    };
 
    char str[100005], *delim = " .,!?;:\n";
    while(gets(str) != 0) {
        char *s = strtok(str, delim);
        while(s != NULL) {
            int len = strlen(s);
            //printf("%d, %s\n", len, s);
            rep(i,0,20) {
                if(Check(s,suf[i],len)) {
                    freq[i]++;
                    break;
                }
            }
            s = strtok(NULL, delim);
        }
    }
    rep(i,0,20) {
        if(freq[i] != 0) {
            printf("%s:\nFrequency: %d\n", suf[i], freq[i]);
        }
    }
}