#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) (a)>(b) ? (a) : (b)
#define min(a,b) (a)<(b) ? (a) : (b)
#define ll long long
#define oo 1e9
 
signed main() {
    int a=0, b=0, c=0;
    char s[105];
    scanf("%s", s);
    rep(i,0,strlen(s)) {
        if(isdigit(s[i])) a++;
        else if(islower(s[i]) || isupper(s[i])) b++;
        if(s[i]=='A' || s[i]=='a' ||
        s[i]=='E' || s[i]=='e' ||
        s[i]=='I' || s[i]=='i' ||
        s[i]=='O' || s[i]=='o' ||
        s[i]=='U' || s[i]=='u') c++;
    }
    printf("%d %d %d %d", a, b, c, b-c);
}