#include<stdio.h>
 
signed main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        int cnt = 0;
        while(n > 0) {
            if(n & 1) cnt++;
            n >>= 1;
        }
        printf("%d\n", cnt);
    }
}