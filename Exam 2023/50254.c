#include<stdio.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
 
int main() {
    int n,p,cnt=1;
    scanf("%d", &n);
    p = (n>0);
    while(scanf("%d", &n) != EOF) {
        if(p==(n>0)) cnt++;
        else {
            if(!p) printf("-");
            printf("%d ", cnt);
            cnt = 1;
            p = (n>0);
        }
    }
    if(!p) printf("-");
    printf("%d ", cnt);
}