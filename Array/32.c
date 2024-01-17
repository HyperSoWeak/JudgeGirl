#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) (a)>(b) ? (a) : (b)
#define min(a,b) (a)<(b) ? (a) : (b)
#define ll long long
#define oo 1e9
 
typedef struct Palindrome {
    int head, len;
} Palindrome;
 
signed main() {
    int a[105], n=0, idx=0, d[105];
    rep(i,0,105) d[i] = -1;
    Palindrome p[10005];
    while(scanf("%d", &a[n++]) != EOF) continue;
    n--;
    rep(i,0,n) {
        rep(j,i,n) {
            int l = j-i+1;
            bool f = true;
            rep(k,0,l/2) {
                if(a[i+k] != a[i+l-k-1]) {
                    f = false;
                    break;
                }
            }
            if(f) {
                p[idx].head = i, p[idx].len = l;
                if(d[i] == -1) d[i] = idx;
                idx++;
            }
        }
    }
    int maxl = -1, maxi;
    rep(i,0,idx) {
        int h2 = p[i].head+p[i].len;
        if(h2 >= n) continue;
        int i2 = d[h2];
        while(p[i2].head == h2) {
            int l = p[i].len+p[i2].len;
            if(l >= maxl) {
                maxl = l;
                maxi = p[i].head;
            }
            i2++;
        }
    }
    rep(i,maxi,maxi+maxl) printf("%d%c", a[i], " \n"[i==maxi+maxl-1]);
}