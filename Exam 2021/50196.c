#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
 
int main() {
    int n, ans=0, c=0, d=1;
    while(scanf("%d", &n) != EOF) {
        if(n>=1 && n<=7) c = c*10+n;
        else {
            d*=c, c=0;
            if(n != 9) {
                ans+=d, d=1;
                if(n == 0) {
                    printf("%d\n", ans);
                    return 0;
                }
            }
        }
    }
}