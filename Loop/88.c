#include<stdio.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
 
int abs(int x) { return x<0 ? -x : x; }
int min(int x, int y) { return x<y ? x : y; }
int max(int x, int y) { return x>y ? x : y; }
 
int gcd(int x, int y) {
    while(x%y != 0) {
        int r = x%y;
        x = y;
        y = r;
    }
    return abs(y);
}
int lcm(int x, int y) { return x*y/gcd(x,y); }
 
int main() {
    int a=0, b=0, n[256]={0};
    char x[5], y[5];
    scanf("%s %s", x, y);
    rep(i,0,4) n[x[i]]++;
    rep(i,0,4)
        if(n[y[i]] > 0) b++;
    rep(i,0,4)
        if(x[i] == y[i]) { a++; b--; }
    printf("%dA%dB", a, b);
}