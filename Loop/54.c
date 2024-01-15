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
 
int power(int x, int n) {
    int ans = 1;
    rep(i,0,n) ans*=x;
    return ans;
}
 
int main() {
    char n[10], m[10];
    scanf("%s %s", n, m);
    int ans = 0;
    rep(i,0,6) {
        if(n[0]==m[i] && n[1]==m[i+1]) ans++;
    }
    printf("%d\n", ans);
}