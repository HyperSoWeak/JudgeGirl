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
    int M,N,X1,Y1,E1,N1,F1,X2,Y2,E2,N2,F2,s1=0,s2=0,t=0;
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d",&M,&N,&X1,&Y1,&E1,&N1,&F1,&X2,&Y2,&E2,&N2,&F2);
    while(true) {
        if(X1==X2 && Y1==Y2) {
            printf("robots explode at time %d", t);
            return 0;
        }
        if(F1<=0 && F2<=0) {
            printf("robots will not explode");
            return 0;
        }
        if(F1>0) {
            if(s1<N1) Y1 = (Y1+1>=N)? 0 : Y1+1;
            else X1 = (X1+1>=M)? 0 : X1+1;
        }
        if(F2>0) {
            if(s2<E2) X2 = (X2+1>=M)? 0 : X2+1;
            else Y2 = (Y2+1>=N)? 0 : Y2+1;
        }
        s1++, s2++, t++, F1--, F2--;
        if(s1 == E1+N1) s1=0;
        if(s2 == E2+N2) s2=0;
    }
}