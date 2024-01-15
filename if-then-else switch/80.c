#include<stdio.h>
#include<stdlib.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
 
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
void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}
 
int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}
 
int main() {
    int n,x1,x2,x3,y1,y2,y3,a[3];
    scanf("%d",&n);
    while(n--) {
        scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
        a[0] = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
        a[1] = (x2-x3)*(x2-x3) + (y2-y3)*(y2-y3);
        a[2] = (x1-x3)*(x1-x3) + (y1-y3)*(y1-y3);
        qsort(a, 3, sizeof(a[0]), cmp);
        if(a[0]==a[1] || a[1]==a[2]) printf("isosceles\n");
        else if(a[0]+a[1] < a[2]) printf("obtuse\n");
        else if(a[0]+a[1] > a[2]) printf("acute\n");
        else printf("right\n");
    }
}