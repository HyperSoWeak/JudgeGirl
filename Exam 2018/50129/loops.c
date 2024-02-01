#include<stdbool.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))
#define oo 1e9
 
void loops(int N, int *A, int *B[], int ans[4]) {
    bool vis[1000005] = {0};
    ans[0] = -oo, ans[1] = oo;
 
    rep(i,0,N) {
        if(vis[i]) continue;
 
        int now = i, len = 0;
        int maxn = -oo, minn = oo;
 
        while(!vis[now]) {
            vis[now] = true;
            len++;
            maxn = max(maxn, A[now]);
            minn = min(minn, A[now]);
            now = B[now] - A;
        }
 
        if(len>ans[0]) {
            ans[0] = len;
            ans[2] = maxn;
        } else if(len==ans[0]) ans[2] = max(ans[2], maxn);
 
        if(len<ans[1]) {
            ans[1] = len;
            ans[3] = minn;
        } else if(len==ans[1]) ans[3] = min(ans[3], minn);
    }
}