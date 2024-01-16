#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define oo 1e9
 
int main() {
    int a[1005], n;
    scanf("%d", &n);
    rep(i,0,n) scanf("%d", &a[i]);
    for(int i=n-1; i>=0; --i) {
        printf("%d", a[i]);
        if(i) printf(" ");
    }
}