#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))
#define ll long long
#define oo 1e9
 
int rec(int sum, int num, int now, int k, int N, int M, int a[20], int b[20]) {
    if(sum > M) return 0;
    int ans = 0;
    if(sum <= M && num >= k) ans++;
    rep(i,now,N) {
        if(b[i] == 0) {
            b[i] = 1;
            ans += rec(sum+a[i], num+1, i+1, k, N, M, a, b);
            b[i] = 0;
        }
    }
    return ans;
}
 
signed main() {
    int k, N, M, a[20], b[20];
    scanf("%d%d%d", &k, &N, &M);
    rep(i,0,N) {
        scanf("%d", &a[i]);
        b[i] = 0;
    }
    printf("%d", rec(0, 0, 0, k, N, M, a, b));
}