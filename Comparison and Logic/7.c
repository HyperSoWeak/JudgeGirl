#include<stdio.h>
 
int main() {
    int x;
    scanf("%d", &x);
    printf("%d", !(x%3==0 && x%5==0 && x%7!=0));
}