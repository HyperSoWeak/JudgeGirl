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
 
int f(const char *s) {
    int ans = 0;
    rep(i,0,strlen(s)) ans += s[i];
    return ans % 1000;
}
 
bool isValid(const char *s) {
    if(!(isalpha(s[0]) || s[0]=='_')) return false;
    rep(i,0,strlen(s))
        if(!(isalpha(s[i]) || isdigit(s[i]) || s[i]=='_'))
            return false;
    return true;
}
 
typedef struct HashTable {
    char key[25];
    int cnt;
} HT;
 
int Find(char *key, HT ht[1000][3]) {
    int v = f(key);
    rep(i,0,3) {
        if(strcmp(ht[v][i].key,key)==0) {
            return ++ht[v][i].cnt;
        }
    }
    // Not found
    rep(i,0,3) {
        if(strcmp(ht[v][i].key,"")==0) {
            strcpy(ht[v][i].key, key);
            return ++ht[v][i].cnt;
        }
    }
}
 
signed main() {
    HT ht[1000][3];
    char s[25];
    rep(i,0,1000) rep(j,0,3) {
        ht[i][j].cnt = 0;
        strcpy(ht[i][j].key, "");
    }
    while(scanf("%s", s) != EOF) {
        if(!isValid(s)) continue;
        printf("%s %d\n", s, Find(s, ht));
    }
}