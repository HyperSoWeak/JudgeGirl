#include<stdio.h>
#include<stdlib.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
 
int main() {
    int a[] = {200000,40000,10000,4000,1000,200};
    int sp[3], fp[3], n, ans=0;
    scanf("%d %d %d", &sp[0], &sp[1], &sp[2]);
    scanf("%d %d %d", &fp[0], &fp[1], &fp[2]);
    while(scanf("%d", &n) != EOF) {
        rep(i,0,3) {
            if(n == sp[i]) ans+=2000000;
            for(int j=100000000, k=0; k<6; j/=10, k++) {
                if(n%j == fp[i]%j) {
                    ans+=a[k];
                    break;
                }
            }
        }
    }
    printf("%d\n", ans);
}