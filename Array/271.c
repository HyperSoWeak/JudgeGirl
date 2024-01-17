#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define oo 1e9
 
int main() {
    int a[105], b[105], m, n;
    scanf("%d", &m);
    for(int i=m-1; i>=0; --i) scanf("%d", &a[i]);
    scanf("%d", &n);
    for(int i=n-1; i>=0; --i) scanf("%d", &b[i]);
    for(int i=n+m-2; i>=0; --i) {
        int sum = 0;
        rep1(j,0,i) if(j<m && i-j<n) sum += a[j]*b[i-j];
        printf("%d", sum);
        if(i) printf(" ");
    }
}