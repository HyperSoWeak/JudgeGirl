#include<stdio.h>
 
int main() {
    int a,b,c,d,e;
    scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
    int A = a-2*e;
    int B = b-2*e;
    int C = c-2*e;
    int s = 2*(a*b+b*c+c*a) + 8*d*(A+B+C);
    int v = a*b*c - 2*d*(A*B + B*C + C*A);
    printf("%d\n%d", s, v);
}