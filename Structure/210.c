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
#define OO 1e9
#define ERR 2e9+7
 
typedef struct Data {
    char str[3][85];
    int  num[5];
} DataT;
 
int mapping(char *s) {
    if(!strcmp(s, "lastname"))  return 0;
    if(!strcmp(s, "firstname")) return 1;
    if(!strcmp(s, "ID"))        return 2;
    if(!strcmp(s, "salary"))    return 3;
    if(!strcmp(s, "age"))       return 4;
}
 
int split(char *str, char **res) {
    int i = 0;
    char *p;
    p = strtok(str, " ");
    while(p != NULL) {
        res[i++] = p;
        p = strtok(NULL, " ");
    }
    return i;
}
 
void printData(DataT *data, int x, int *used, int ui) {
    bool first = true;
    rep(i,0,ui) {
        if(!first) printf(" ");
        if(used[i] <= 2) printf("%s", data[x].str[used[i]]);
        else printf("%d", data[x].num[used[i]]);
        first = false;
    }
    printf("\n");
}
 
signed main() {
    DataT data[50];
    int n;
    scanf("%d", &n);
    rep(i,0,n) {
        scanf("%s", &data[i].str[0]);
        scanf("%s", &data[i].str[1]);
        scanf("%s", &data[i].str[2]);
        scanf("%d", &data[i].num[3]);
        scanf("%d", &data[i].num[4]);
    }
 
    int q;
    char s[1000];
    char *t[30];
    scanf("%d", &q);
    getchar();
    while(q--) {
        gets(s);
        split(s, t);
 
        int i = 1;
        int used[20];
        while(strcmp(t[i], "where")) {
            used[i-1] = mapping(t[i]);
            i++;
        }
        int ui = i-1;
 
        int key = mapping(t[i+1]);
        if(key <= 2) { // str
 
            if(!strcmp(t[i+2], "==")) {
                rep(j,0,n) {
                    if(!strcmp(data[j].str[key], t[i+3])) {
                        printData(data, j, used, ui);
                    }
                }
            } else if(!strcmp(t[i+2], "!=")) {
                rep(j,0,n) {
                    if(strcmp(data[j].str[key], t[i+3])) {
                        printData(data, j, used, ui);
                    }
                }
            }
 
        } else { // int
 
            if(!strcmp(t[i+2], "==")) {
                rep(j,0,n) {
                    if(data[j].num[key] == atoi(t[i+3])) {
                        printData(data, j, used, ui);
                    }
                }
            } else if(!strcmp(t[i+2], ">")) {
                rep(j,0,n) {
                    if(data[j].num[key] > atoi(t[i+3])) {
                        printData(data, j, used, ui);
                    }
                }
            } else if(!strcmp(t[i+2], "<")) {
                rep(j,0,n) {
                    if(data[j].num[key] < atoi(t[i+3])) {
                        printData(data, j, used, ui);
                    }
                }
            }
 
        }
    }
}