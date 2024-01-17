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
#define MAXS 10
 
char s[3][MAXS];
int map[26];
int used[26], ui=0;
 
int Digit(int n) {
    int ans = 0;
    while(n != 0) {
        ans ++;
        n /= 10;
    }
    return ans;
}
 
int ToInt(char str[MAXS]) {
    int ans = 0, len = strlen(str);
    rep(i,0,len) {
        ans *= 10;
        if(isdigit(str[i])) ans += str[i]-'0';
        else ans += map[str[i]-'A'];
    }
    return ans;
}
 
bool Check() {
    return ToInt(s[0]) * ToInt(s[1]) == ToInt(s[2]);
}
 
void PrintAns() {
    printf("%0*d x ", strlen(s[0]), ToInt(s[0]));
    printf("%0*d = ", strlen(s[1]), ToInt(s[1]));
    printf("%0*d\n", strlen(s[2]), ToInt(s[2]));
}
 
void FindLetters() {
    bool a[26] = {0};
    rep(i,0,strlen(s[0])) a[s[0][i]-'A'] = 1;
    rep(i,0,strlen(s[1])) a[s[1][i]-'A'] = 1;
    rep(i,0,strlen(s[2])) a[s[2][i]-'A'] = 1;
    rep(i,0,26) if(a[i]) used[ui++] = i;
}
 
bool Solve(int n) {
    if(n == ui) return Check();
 
    rep1(i,0,9) {
        map[used[n]] = i;
        if(Solve(n+1)) return true;
    }
}
 
signed main() {
    scanf("%s%s%s", s[0], s[1], s[2]);
    FindLetters();
    Solve(0);
    PrintAns();
}