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
 
int dgt;
 
int compute(int n) {
    int ans = 0;
    dgt = 0;
    while(n>0) {
        int k = n%10;
        ans += k;
        n /= 10;
        dgt++;
    }
    return ans;
}
 
int main() {
    int n, maxn=-1, num=0, mindgt=1000000000;
    while(scanf("%d", &n) != EOF) {
        int ans = compute(n);
        if(ans>maxn || (ans==maxn && dgt<mindgt) || (ans==maxn && dgt==mindgt && n>num)) { 
            maxn = ans;
            num = n;
            mindgt = dgt;
        }
    }
    printf("%d\n", num);
}