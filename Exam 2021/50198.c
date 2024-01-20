#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define ll long long int
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
 
bool isValid(ll x) {
    int a=-1, b=-1;
    while(x>0) {
        int c=x%10;
        if(a==-1) a=c;
        else if(c!=a && b==-1) b=c;
        else if(c!=a && c!=b) return false;
        x/=10;
    }
    return true;
}
 
int main() {
    ll a,b,x;
    while(scanf("%lld%lld%lld",&a,&b,&x) != EOF) {
        while(!isValid(x)) x = (a*x)%b;
        printf("%lld\n", x);
    }
}