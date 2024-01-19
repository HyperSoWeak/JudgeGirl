#include<stdio.h>
 
int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int i=1, a=0;
    for(int j=n+m-1; a+j<k; a+=j, j-=2, i++) continue;
    int x=i, y=i;
    if(k-a > m-i+1) x += k-(a+(m-i+1));
    else y += k-a-1;
    printf("%d %d\n", x, y);
}