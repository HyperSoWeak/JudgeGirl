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
 
int main() {
    int k;
    scanf("%d", &k);
    rep1(i,1,9)
        rep1(j,max(0,i-k),min(9,i+k))
            rep1(m,max(0,j-k),min(9,j+k))
                rep1(n,max(0,m-k),min(9,m+k))
                    printf("%d%d%d%d\n",i,j,m,n);
}