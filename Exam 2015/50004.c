#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define oo 1e9
 
int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }
 
bool win(int m[6][6]) {
    rep1(i,1,4) rep1(j,1,4) {
        if(m[i][j] != ((i-1)*4+j)%16) return false;
    }
    return true;
}
 
signed main() {
    int m[6][6], a;
    int dx[] = {1,0,-1,0};
    int dy[] = {0,1,0,-1};
    rep(i,0,6) rep(j,0,6) m[i][j] = -1;
    rep1(i,1,4) rep1(j,1,4) scanf("%d", &m[i][j]);
    while(scanf("%d", &a)) {
        if(a == 0) {
            rep1(i,1,4) rep1(j,1,4) printf("%d%c",m[i][j]," \n"[j==4]);
            printf("0");
            return 0;
        }
        bool f = false;
        rep1(i,1,4) {
            rep1(j,1,4) {
                if(m[i][j] == a) {
                    rep(k,0,4) {
                        int x=i+dx[k], y=j+dy[k];
                        if(m[x][y] == 0) {
                            m[x][y] = m[i][j];
                            m[i][j] = 0;
                            break;
                        }
                    }
                    f = true;
                    break;
                }
            }
            if(f) break;
        }
        if(win(m)) {
            rep1(i,1,4) rep1(j,1,4) printf("%d%c",m[i][j]," \n"[j==4]);
            printf("1 %d", a);
            return 0;
        }
    }
}