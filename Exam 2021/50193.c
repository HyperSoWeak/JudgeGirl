#include<stdio.h>
#include<stdlib.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
 
// math
int abs(int x) { return x<0 ? -x : x; }
int mmin(int x, int y) { return x<y ? x : y; }
int mmax(int x, int y) { return x>y ? x : y; }
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
 
// utils
void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}
 
// 2D Vector
typedef struct Point { int x, y; } Point;
int dot(Point a, Point b) { return a.x*b.x + a.y*b.y; }
int cross(Point a, Point b) { return a.x*b.y - a.y*b.x; }
int vecLen2(Point a) { return a.x*a.x + a.y*a.y; }
 
 
// qsort
int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}
 
int toSec(int a) {
    return (a/10000)*3600 + ((a/100)%100)*60 + a%100;
}
 
int diff(int a, int b) {
    return abs(toSec(a)-toSec(b));
}
 
int main() {
    int a, b, ans=100000000;
    scanf("%d", &a);
    while(scanf("%d", &b) != EOF) {
        ans = mmin(ans, diff(a, b));
        a = b;
    }
    printf("%d\n", ans);
}