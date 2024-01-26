#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define oo 1e9
 
int main() {
    int n,cnt=0,zero=0,sum=0;
    while(scanf("%d", &n) != EOF) {
        cnt++;
        zero += (n==0);
        sum += ((cnt%2)*2-1) * n;
        sum %= 11;
    }
    printf("%d\n%d\n%d\n%d", cnt, n%2==0, zero, sum%11==0);
}