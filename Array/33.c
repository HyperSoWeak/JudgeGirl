#include<stdio.h>
#include<stdlib.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
 
int main() {
    int n, a[105][105]={0}, ans[5];
    int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};
    scanf("%d", &n);
    rep1(i,1,n)
        rep1(j,1,n)
            scanf("%d", &a[i][j]);
    rep1(i,1,n) {
        rep1(j,1,n) {
            if(a[i][j] != 1) continue;
            int cnt = 0;
            rep(k,0,4) {
                int x = i+dx[k], y = j+dy[k];
                if(a[x][y] == 1) cnt++;
            }
            if(cnt==2 && ((a[i+1][j]==a[i-1][j]==1) || (a[i][j+1]==a[i][j-1]==1))) continue;
            ans[cnt]++;
        }
    }
    for(int i=4; i>0; --i) printf("%d\n", ans[i]);
}