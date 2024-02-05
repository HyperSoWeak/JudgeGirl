#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define oo 1e9
 
int max(int a, int b) { return (a > b)? a : b; }
int min(int a, int b) { return (a < b)? a : b; }
 
int main() {
    int n,a;
    while(scanf("%d",&n)!=EOF) {
        int maxn=-oo, minn=oo, flag=0;
        while(n--) {
            if(scanf("%d",&a)==EOF) {
                flag = 1;
                break;
            }
            maxn = max(maxn,a);
            minn = min(minn,a);
        }
        if(flag) {
            printf("%d\n",minn);
            return 0;
        } else printf("%d\n",maxn);
    }
}