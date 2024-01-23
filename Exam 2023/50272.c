#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>
#include<math.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))
#define oo 1e9
#define ERR -(2e9+7)
#define ll long long
 
 
 
void PrintThree(ll n) {
    const char num[10][10] = {
        "", "one", "two", "three", "four",
        "five", "six", "seven", "eight", "nine"
    };
    const char ten[10][10] = {
        "", "", "twent", "thirt", "fort",
        "fift", "sixt", "sevent", "eight", "ninet"
    };
    const char eletwe[3][10] = { "", "eleven", "twelve" };
    const char hundred[2][10] = { "", " hundred " };
    const char hyphen[2][5] = { "", "y-" };
    const char teen[2][5] = { "", "een" };
 
    int a = n/100, b = (n%100)/10, c = n%10;
    int bc = n%100;
 
    printf("%s%s%s%s%s%s%s%s",
        num[a],
        hundred[a != 0],
        ten[b],
        hyphen[b > 1],
        ten[(b==1 && c>=3) * c],
        teen[b==1 && c>=3],
        num[(b!=1) * c],
        eletwe[(bc==11 || bc==12) * c]
    );
}
 
void Solve(ll p, ll t, ll *n) {
    const char thou[7][15] = {
        "", " thousand ", " million ", " billion ",
        " trillion ", " quadrillion ", " quintillion "
    };
 
    ll three = (*n) / t;
    PrintThree(three);
    printf("%s", thou[(three!=0) * p]);
    (*n) %= t;
}
 
signed main() {
    ll n;
    scanf("%lld", &n);
    ll t[7] = {1,1e3,1e6,1e9,1e12,1e15,1e18};
    Solve(6,t[6],&n);
    Solve(5,t[5],&n);
    Solve(4,t[4],&n);
    Solve(3,t[3],&n);
    Solve(2,t[2],&n);
    Solve(1,t[1],&n);
    Solve(0,t[0],&n);
}