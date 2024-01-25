#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define oo 1e9
 
signed main() {
    int k,n,cnt[3]={0},f=-1,s=-1,ans=0;
    scanf("%d",&k);
    while(scanf("%d",&n) != EOF) {
        cnt[n%3]++;
        //printf("%d ",n%3);
        if(n>f) s=f, f=n;
        else if(n>s) s=n;
        if(cnt[0]>=k && cnt[1]>=k && cnt[2]>=k) {
            //printf("%d\n",s);
            ans += s;
            f=-1, s=-1;
            rep(i,0,3) cnt[i]=0;
        }
    }
    if(s==-1 && f!=-1) ans += f;
    else if(s!=-1) ans += s;
    printf("%d",ans);
}