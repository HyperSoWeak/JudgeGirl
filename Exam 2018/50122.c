#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))
#define oo 1e9
#define ll long long
#define MAXN 100
#define MAXM MAXN*MAXN
 
signed main() {
    int dx[] = {-2,-1,1,2,2,1,-1,-2};
    int dy[] = {1,2,2,1,-1,-2,-2,-1};
    int n, m, x[MAXM], y[MAXM], idx = 0;
    int ac = 0, vis[MAXN][MAXN] = {0}, cnt[MAXM] = {0};
    scanf("%d%d", &n, &m);
    rep(i,0,m) {
        scanf("%d%d", &x[i], &y[i]);
        vis[x[i]][y[i]] = (i+1)*10000;
        ac++;
    }
    int notcnt = 0;
    while(notcnt < m) {
        int p = 9, pi;
        rep(i,0,8) {
            int nx = x[idx]+dx[i];
            int ny = y[idx]+dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
            if(vis[nx][ny] == 0) {
                int pcnt = 0;
                rep(j,0,8) {
                    int cx = nx+dx[j];
                    int cy = ny+dy[j];
                    if(cx<0 || cx>=n || cy<0 || cy>=n) continue;
                    if(vis[cx][cy] == 0) pcnt++;
                }
                if(pcnt < p) {
                    p = pcnt;
                    pi = i;
                }
            }
        }
        if(p == 9) {
            idx = (idx+1) % m;
            notcnt++;
            continue;
        }
        cnt[idx]++;
        x[idx] += dx[pi], y[idx] += dy[pi];
        vis[x[idx]][y[idx]] = (idx+1)*10000 + cnt[idx];
        ac++;
        idx = (idx+1) % m;
        notcnt = 0;
    }
    rep(i,0,n) rep(j,0,n) printf("%d%c", vis[i][j], " \n"[j==n-1]);
}