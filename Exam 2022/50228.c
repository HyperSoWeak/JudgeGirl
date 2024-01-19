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
#define MAXN 100005
 
signed main() {
    int n, a, b, asum=-1, alen=-1, afirst=-1;
    scanf("%d", &n);
    scanf("%d", &a);
    int sum=a, len=1, first=a, dis=oo;
    rep(i,1,n) {
        scanf("%d", &b);
        int d = b-a;
        if(d != dis) {
            if(sum>asum || (sum==asum && (len>alen || (len==alen && first>afirst)))) {
                asum = sum;
                alen = len;
                afirst = first;
            }
            dis = d;
            sum = a+b;
            len = 2;
            first = a;
        } else {
            sum += b;
            len++;
        }
        a = b;
    }
    if(sum>asum || (sum==asum && (len>alen || (len==alen && first>afirst)))) {
        asum = sum;
        alen = len;
        afirst = first;
    }
    printf("%d %d %d", asum, alen, afirst);
}