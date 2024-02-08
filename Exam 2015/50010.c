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
#define ll long long
#define oo 1e9
#define MAXS 100005
#define MAXC 100005
 
typedef struct Command {
    char name[25];
    char x;
    char y;
} Cmd;
 
signed main() {
    char S[MAXS];
    scanf("%s", S);
 
    Cmd cmd[MAXC];
    int n = 0;
    while(scanf("%s", cmd[n].name) && strcmp(cmd[n].name, "end")) {
        if(!strcmp(cmd[n].name, "replace")) scanf(" %c %c", &cmd[n].x, &cmd[n].y);
        else if(!strcmp(cmd[n].name, "remove")) scanf(" %c", &cmd[n].x);
        else if(!strcmp(cmd[n].name, "addhead")) scanf(" %c", &cmd[n].x);
        else if(!strcmp(cmd[n].name, "addtail")) scanf(" %c", &cmd[n].x);
        else {
            printf("invalid command %s\n", cmd[n].name);
            return 0;
        }
        n++;
    }
 
    char map[128];
    rep1(i,'a','z') map[i] = i;
    char T[MAXS];
    int ti = 0;
 
    for(int i=n-1; i>=0; i--) {
        if(!strcmp(cmd[i].name, "replace")) {
            map[cmd[i].x] = map[cmd[i].y];
        }
        else if(!strcmp(cmd[i].name, "remove")) {
            map[cmd[i].x] = '\0';
        }
        else if(!strcmp(cmd[i].name, "addhead")) {
            if(map[cmd[i].x] != '\0') putchar(map[cmd[i].x]);
        }
        else if(!strcmp(cmd[i].name, "addtail")) {
            if(map[cmd[i].x] != '\0') T[ti++] = map[cmd[i].x];
        }
    }
 
    int slen = strlen(S);
    rep(i,0,slen) {
        if(map[S[i]] != '\0') putchar(map[S[i]]);
    }
    for(int i=ti-1; i>=0; i--) putchar(T[i]);
}