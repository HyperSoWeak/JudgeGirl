#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
 
bool isLeap(int y) {
    return y%4==0 && y%100!=0 || y%400==0;
}
 
int main() {
    int md[13] = {0,31,0,31,30,31,30,31,31,30,31,30,31};
    int y,m,d;
    scanf("%d%d%d",&y,&m,&d);
    if(m>12 || m<1 || d>6 || d<0) {
        printf("invalid");
        return 0;
    }
    md[2] = isLeap(y) ? 29 : 28;
    printf(" Su Mo Tu We Th Fr Sa\n");
    printf("=====================\n");
    rep(i,0,d) printf("   ");
    rep1(i,1,md[m]) {
        printf("%3d",i);
        if((d+i)%7 == 0) printf("\n");
    }
    if((d+md[m])%7 != 0) printf("\n");
    printf("=====================\n");
}