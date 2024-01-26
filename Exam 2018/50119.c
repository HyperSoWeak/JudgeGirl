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
    int x,a,b,c,y,d,e,f,n;
    scanf("%d%d%d%d",&x,&a,&b,&c);
    scanf("%d%d%d%d",&y,&d,&e,&f);
    scanf("%d",&n);
    while(n--) {
        int X = x%3, Y = y%3, cnt = 1;
        while(X==Y) {
            x = (a*x+b)%c;
            y = (d*y+e)%f;
            X = x%3, Y = y%3;
            cnt++;
        }
        printf("%d %d\n", ((X==1&&Y==2) || (X==2&&Y==0) || (X==0&&Y==1)), cnt);
        x = (a*x+b)%c;
        y = (d*y+e)%f;
    }
}