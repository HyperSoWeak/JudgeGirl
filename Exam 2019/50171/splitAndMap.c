#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define oo 1e9
void splitAndMap(char*** ptr, char* str) {
    int n = 0;
    while(ptr[n] != NULL) n++;
    int len[10] = {0}, idx[10] = {0};
    char *tok = strtok(str, "*");
    while(tok != NULL) {
        int minlen = oo, mi;
        rep(i,0,n) if(len[i] < minlen) {
            minlen = len[i];
            mi = i;
        }
        ptr[mi][idx[mi]++] = tok;
        len[mi] += strlen(tok);
        tok = strtok(NULL, "*");
    }
}