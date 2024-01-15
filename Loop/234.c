#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) (a)>(b) ? (a) : (b)
#define min(a,b) (a)<(b) ? (a) : (b)
#define oo 1e9
 
int abs(int x) { return x < 0 ? -x : x; }
 
int f(int x, int a, int b, int c) {
    return x*x*x + a*x*x + b*x + c;
}
 
signed main() {
    int a, b, c, cnt=0, ans[3];
    scanf("%d%d%d", &a, &b, &c);
    if(c==0 && b==0 && a==0) {
        printf("0 0 0");
        return 0;
    } else if(c==0 && b==0) {
        if(a>0) printf("0 0 %d", a);
        else printf("%d 0 0", a);
        return 0;
    } else if(c==0) {
        ans[cnt++] = 0;
        int b2 = abs(b);
        rep1(i,-b2,b2) {
            if(i!=0 && b2%i==0 && f(-i,a,b,c)==0) {
                ans[cnt++] = i;
                break;
            }
        }
        ans[cnt++] = a-ans[1];
    } else {
        int c2 = abs(c);
        rep1(i,-c2,c2) {
            if(i!=0 && c2%i==0 && f(-i,a,b,c)==0) {
                ans[cnt++] = i;
            }
        }
    }
    if(cnt==1) ans[1] = ans[0], ans[2] = ans[0];
    else if(cnt==2) ans[2] = a-ans[0]-ans[1];
    rep(i,0,3) {
        rep(j,0,i) {
            if(ans[j]>ans[i]) {
                int t = ans[j];
                ans[j] = ans[i];
                ans[i] = t;
            }
        }
    }
    printf("%d %d %d", ans[0], ans[1], ans[2]);
}