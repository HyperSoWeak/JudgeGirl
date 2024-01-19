#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) (a)>(b) ? (a) : (b)
#define min(a,b) (a)<(b) ? (a) : (b)
#define ll long long
#define oo 1e9
 
int t[100000][10];
 
signed main() {
    int S, C, k;
    scanf("%d%d", &S, &C);
    while(scanf("%d", &k) != EOF) {
        int f = (77*k + 2222) % S;
        // remove
        bool flag = false;
        rep(i,0,C) if(t[f][i] == k) {
            t[f][i] = 0;
            flag = true;
            printf("%d %d\n", k, f);
            break;
        }
        if(flag) continue;
        // insert
        rep(i,0,C) if(t[f][i] == 0) {
            t[f][i] = k;
            break;
        }
    }
}