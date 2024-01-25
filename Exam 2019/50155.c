#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define oo 1e9
 
int min(int a, int b) { return (a < b) ? a : b; }
 
signed main() {
    int a,b,c,d,e,f,g;
    scanf("%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g);
    if(a==e && b==f && g>=c || d==0) {
        printf("0");
        return 0;
    }
    if((a*b*d+e*f*g) >= a*b*g) printf("%d", min(c, (a*b*d+e*f*g)/(a*b)));
    else printf("%d", min(c, (a*b*d)/(a*b-e*f)));
}