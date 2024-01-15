#include<stdio.h>
 
int main() {
    int s, f, t, a, b, c;
    scanf("%d %d %d", &s, &f, &t);
    c = s-t;
    if((f-8*c-2*t)%2 != 0) {
        printf("0");
        return 0;
    }
    b = (f-8*c-2*t)/2;
    a = t-b;
    if(a<0 || b<0 || c<0) {
        printf("0");
        return 0;
    }
    printf("%d\n%d\n%d", a, b, c);
}