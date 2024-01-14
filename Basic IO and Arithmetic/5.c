#include<stdio.h>
 
int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int x = 2 * (a*b + b*c + c*a);
    int y = a*b*c;
    printf("%d\n%d", x, y);
}