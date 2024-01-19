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
 
typedef struct Employee {
    int id;
    char first_name[32];
    char last_name[32];
    int boss_id;
} Employee;
 
int boss[32];
int n, m;
Employee emp[32];
char rel[4][15] = {
    "subordinate",
    "supervisor",
    "colleague",
    "unrelated"
};
 
int GetIndexFromName(char f[32], char l[32]) {
    rep(i,0,n) {
        if(!strcmp(f, emp[i].first_name) && !strcmp(l, emp[i].last_name))
            return i;
    }
    return -1; // Error: not found
}
int GetIndexFromId(int id) {
    rep(i,0,n) {
        if(id == emp[i].id)
            return i;
    }
    return -1; // Error: not found
}
 
int relation(char f1[32], char l1[32], char f2[32], char l2[32]) {
    int i1 = GetIndexFromName(f1, l1);
    int i2 = GetIndexFromName(f2, l2);
 
    int i = i1;
    while(boss[i] != i) {
        if(boss[i] == i2) return 0;
        i = boss[i];
    }
 
    i = i2;
    while(boss[i] != i) {
        if(boss[i] == i1) return 1;
        i = boss[i];
    }
 
    bool isBoss[32] = {0};
    while(boss[i1] != i1) {
        i1 = boss[i1];
        isBoss[i1] = true;
    }
    while(boss[i2] != i2) {
        i2 = boss[i2];
        if(isBoss[i2]) return 2;
    }
 
    return 3;
}
 
signed main() {
    scanf("%d", &n);
    rep(i,0,n) {
        scanf("%d", &emp[i].id);
        scanf("%s", emp[i].first_name);
        scanf("%s", emp[i].last_name);
        scanf("%d", &emp[i].boss_id);
    }
 
    rep(i,0,n) boss[i] = GetIndexFromId(emp[i].boss_id);
 
    scanf("%d", &m);
    char f1[32], l1[32], f2[32], l2[32];
    while(m--) {
        scanf("%s%s%s%s", f1, l1, f2, l2);
        printf("%s\n", rel[relation(f1,l1,f2,l2)]);
    }
}