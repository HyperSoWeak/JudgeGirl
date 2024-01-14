#include<stdio.h>
 
int main() {
    int x;
    scanf("%d", &x);
    int a = x/100;
    int b = (x%100)/10;
    int c = x%10;
    printf("%d\n%d\n%d", a, b, c);
}