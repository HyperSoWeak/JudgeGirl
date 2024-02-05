#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) (a)>(b) ? (a) : (b)
#define min(a,b) (a)<(b) ? (a) : (b)
#define ll long long
#define oo 1e9
 
signed main() {
    int n, m, k, x=0, y=0;
    scanf("%d%d", &n, &m);
    printf("0\n0\n");
    while(scanf("%d", &k) != EOF) {
        int r = k%5;
        if(r==0) continue;
        switch(r) {
            case 1:
                if(x+k < n) x += k;
                else continue;
                break;
            case 2:
                if(x-k >= 0) x -= k;
                else continue;
                break;
            case 3:
                if(y+k < m) y += k;
                else continue;
                break;
            case 4:
                if(y-k >= 0) y -= k;
                else continue;
                break;
        }
        printf("%d\n%d\n", x, y);
    }
}