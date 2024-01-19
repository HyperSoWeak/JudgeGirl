#include<stdio.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
 
int max(int a, int b) { return a>b? a : b; }
int squ(int n) { return n*n; }
 
int main() {
    int w,a,b,c,d,e;
    scanf("%d%d%d%d%d%d",&w,&a,&b,&c,&d,&e);
    if(b==0) printf("%d", squ(w)+squ(a+max(d,e)*2+c+2));
    else printf("%d", squ(w)+squ(a+d*2+b+e*2+c+2));
}