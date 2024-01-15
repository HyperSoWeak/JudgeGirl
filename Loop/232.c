#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
 
int md[13] = {0,31,0,31,30,31,30,31,31,30,31,30,31};
int ps[13] = {0};
 
bool isLeap(int y) {
    return y%4==0 && y%100!=0 || y%400==0;
}
 
int days(int m, int d) {
    return ps[m-1]+d-1;
}
 
int cal(int y, int m, int d, int a) {
    if(m>12 || m<1) return -1;
    if(d>md[m] || d<1) return -2;
    return (a+days(m,d)) % 7;
}
 
int main() {
    int y,a,n,m,d;
    scanf("%d%d%d",&y,&a,&n);
    md[2] = isLeap(y) ? 29 : 28;
    rep(i,1,13) ps[i] = ps[i-1] + md[i];
    while(n--) {
        scanf("%d%d",&m,&d);
        printf("%d\n",cal(y,m,d,a));
    }
}