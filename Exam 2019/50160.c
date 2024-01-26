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
#define oo 1e9
 
typedef struct {
    int base;
    int extra;
    int cd;
    int last;
} Skill;
 
signed main() {
    int health, round, regen, maxHealth;
    Skill s[4];
    scanf("%d", &round);
    scanf("%d%d", &maxHealth, &regen);
    health = maxHealth;
    rep(i,0,3) scanf("%d%d%d", &s[i].base, &s[i].extra, &s[i].cd);
    scanf("%d", &s[3].base);
    s[3].extra = 0, s[3].cd = 1;
    rep(i,0,4) s[i].last = -oo;
 
    for(int r=0; r<round; r++) {
        int matk = -1, midx;
        rep(i,0,4) {
            if(r-s[i].last < s[i].cd) continue;
 
            int atk = s[i].base;
            if(r > s[i].cd) {
                if(s[i].last == -oo) atk += s[i].extra * (r - s[i].cd);
                else atk += s[i].extra * (r - s[i].last - s[i].cd);
            }
 
            if(atk > matk) {
                matk = atk;
                midx = i;
            }
        }
 
        health -= matk;
        s[midx].last = r;
        printf("%d", health);
        if(health <= 0) break;
        health = min(maxHealth, health+regen);
        printf(" ");
    }
}