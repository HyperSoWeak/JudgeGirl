#include<stdio.h>
#include<stdlib.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
 
int dgt(int n) {
    int ans = 0;
    while(n) {
        ans++;
        n /= 10;
    }
    return ans;
}
 
int main() {
    int k, L, n;
    scanf("%d %d", &k, &L);
    int r = L;
    while(scanf("%d", &n) != EOF) {
        int t = (n%k)*dgt(n);
        if(t <= r) {
            rep(i,0,n%k) printf("%d", n);
            r -= t;
        } else if(t <= L) {
            printf("\n");
            rep(i,0,n%k) printf("%d", n);
            r = L-t;
        }
    }
}