#include<stdio.h>
 
int main() {
    int s, f, t, a, b, c;
    scanf("%d %d %d", &s, &f, &t);
    c = s-t;
    b = (f-8*c-2*t)/2;
    a = t-b;
    printf("%d\n%d\n%d", a, b, c);
}