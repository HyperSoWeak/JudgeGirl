#include<stdio.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
 
int abs(int x) { return x<0 ? -x : x; }
int min(int x, int y) { return x<y ? x : y; }
int max(int x, int y) { return x>y ? x : y; }
 
int gcd(int a, int b) {
    while(a%b != 0) {
        int r = a%b;
        a = b;
        b = r;
    }
    return abs(b);
}
int lcm(int a, int b) { return a*b/gcd(a,b); }
 
int main() {
    int a,b,c,d;
    while(scanf("%d%d%d%d",&a,&b,&c,&d) != EOF) {
        int r = lcm(lcm(lcm(a,b),c),d);
        printf("%d\n",r/a);
    }
}