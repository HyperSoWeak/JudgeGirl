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
#define ll long long
#define oo 1e9
#define MAXN 100
 
int N, K, M, m;
ll club[MAXN] = {0};
bool used[MAXN] = {0};
 
bool solve(int id, int cnt, ll uni) {
    if(cnt == 0) return true;
 
    for(int i=id; i<N && N-i>=cnt; i++) {
        if((uni & club[i]) == 0) {
            if(solve(i+1, cnt-1, uni|club[i])) {
                used[i] = true;
                return true;
            }
        }
    }
 
    return false;
}
 
signed main() {
    scanf("%d%d", &N, &K);
    rep(i,0,N) {
        scanf("%d", &M);
        rep(j,0,M) {
            scanf("%d", &m);
            club[i] |= (1ll<<m);
        }
    }
 
    solve(0, K, 0);
    rep(i,0,N) if(used[i]) printf("%d\n", i);
}