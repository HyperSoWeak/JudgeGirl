#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))
#define ll long long
#define oo 1e9
#define MAXLEN 50000
 
signed main() {
    int len = 0;
    char buf[MAXLEN];
    char cmd[10], pos[10], data[10];
    while(scanf("%s", cmd) != EOF) {
        if(strcmp(cmd, "insert") == 0) {
            scanf("%s%s", pos, data);
            if(strcmp(pos, "left") == 0) {
                for(int i=len-1; i>=0; --i) buf[i+1] = buf[i];
                buf[0] = data[0];
            } else if(strcmp(pos, "right") == 0) {
                buf[len] = data[0];
            } else {
                int idx = atoi(pos);
                for(int i=len-1; i>=idx-1; --i) buf[i+1] = buf[i];
                buf[idx-1] = data[0];
            }
            len++;
        } else if(strcmp(cmd, "delete") == 0) {
            scanf("%s", pos);
            if(strcmp(pos, "left") == 0) {
                rep(i,1,len) buf[i-1] = buf[i];
            } else if(strcmp(pos, "right") == 0) {
 
            } else {
                int idx = atoi(pos);
                rep(i,idx,len) buf[i-1] = buf[i];
            }
            len--;
        } else return 0;
    }
 
    int l=1, maxl=0;
    rep1(i,1,len) {
        if(i<len && buf[i] == buf[i-1]) l++;
        else {
            maxl = max(maxl, l);
            l = 1;
        }
    }
    rep1(i,1,len) {
        if(i<len && buf[i] == buf[i-1]) l++;
        else {
            if(l == maxl) {
                printf("%c ", buf[i-1]);
            }
            l = 1;
        }
    }
    printf("%d", maxl);
}