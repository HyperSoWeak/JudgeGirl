#include<stdio.h>
 
int sum(int d, int n) {
    if(d == n) return d*d;
    return d*d + sum(d+1, n);
}
 
signed main() {
    int n;
    scanf("%d", &n);
    printf("%d", sum(1, n));
}