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
 
typedef struct Var {
    char name[10];
    int value;
} Var;
 
int GetIndex(Var *v, char *name, int n) {
    rep(i,0,n) {
        if(strcmp(v[i].name, name) == 0) {
            return i;
        }
    }
}
 
int GetValue(Var *v, char *name, int n) {
    rep(i,0,n) {
        if(strcmp(v[i].name, name) == 0) {
            return v[i].value;
        }
    }
}
 
signed main() {
    char equal[5], varNum=0;
    Var v[105];
    while(scanf("%s", v[varNum].name) && strcmp(v[varNum].name, "END") != 0) {
        scanf("%s", equal);
        assert(strcmp(equal, "=") == 0);
        scanf("%d", &v[varNum].value);
        varNum++;
    }
 
    char code[1001][10][10];
    int argNum[1001];
    int lineNum = 1;
    while(scanf("%s", code[lineNum][0]) != EOF) {
        if(strcmp(code[lineNum][0], "GOTO") == 0) argNum[lineNum] = 2;
        else if(strcmp(code[lineNum][0], "IF") == 0) argNum[lineNum] = 6;
        else if(strcmp(code[lineNum][0], "PRINT") == 0) argNum[lineNum] = 2;
        else if(strcmp(code[lineNum][0], "STOP") == 0) argNum[lineNum] = 1;
        else argNum[lineNum] = 5;
        rep(i,1,argNum[lineNum]) scanf("%s", code[lineNum][i]);
        lineNum++;
    }
 
    int line = 1;
    while(line != lineNum) {
        if(strcmp(code[line][0], "GOTO") == 0) {
            line = atoi(code[line][1]);
            continue;
        }
        else if(strcmp(code[line][0], "IF") == 0) {
            int a = GetValue(v, code[line][1], varNum);
            int b = GetValue(v, code[line][3], varNum);
            assert(strcmp(code[line][4], "GOTO") == 0);
 
            bool yes = false;
            if(strcmp(code[line][2], "==") == 0) {
                if(a == b) yes = true;
            }
            else if(strcmp(code[line][2], "!=") == 0) {
                if(a != b) yes = true;
            }
            else if(strcmp(code[line][2], ">") == 0) {
                if(a > b) yes = true;
            }
            else if(strcmp(code[line][2], "<") == 0) {
                if(a < b) yes = true;
            }
            else if(strcmp(code[line][2], ">=") == 0) {
                if(a >= b) yes = true;
            }
            else if(strcmp(code[line][2], "<=") == 0) {
                if(a <= b) yes = true;
            }
 
            if(yes) {
                line = atoi(code[line][5]);
                continue;
            }
        }
        else if(strcmp(code[line][0], "PRINT") == 0) {
            printf("%d\n", GetValue(v, code[line][1], varNum));
        }
        else if(strcmp(code[line][0], "STOP") == 0) {
            return 0;
        }
        else {
            int idx = GetIndex(v, code[line][0], varNum);
            assert(strcmp(code[line][1], "=") == 0);
            int a = GetValue(v, code[line][2], varNum);
            int b = GetValue(v, code[line][4], varNum);
 
            if(strcmp(code[line][3], "+") == 0) {
                v[idx].value = a + b;
            }
            else if(strcmp(code[line][3], "-") == 0) {
                v[idx].value = a - b;
            }
            else if(strcmp(code[line][3], "*") == 0) {
                v[idx].value = a * b;
            }
            else if(strcmp(code[line][3], "/") == 0) {
                v[idx].value = a / b;
            }
            else if(strcmp(code[line][3], "%") == 0) {
                v[idx].value = a % b;
            }
        }
        line++;
    }
}