#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) (a)>(b) ? (a) : (b)
#define min(a,b) (a)<(b) ? (a) : (b)
#define ll long long
#define oo 1e9
#define PI 3.1415926
 
signed main() {
    int n, m, r;
    char A[2005], s[55];
    rep(i,0,2005) A[i] = ' ';
    scanf("%d%d", &n, &m);
    while(m--) {
        scanf("%s%d", &s, &r);
        rep(i,0,strlen(s)) {
            if(A[r+i] == ' ') A[r+i] = s[i];
            else A[r+i] = (A[r+i]+s[i]) / 2;
        }
    }
    A[n-1] = '\0';
    printf("%s", A);
}