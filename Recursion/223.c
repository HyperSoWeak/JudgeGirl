#include<stdio.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
 
int dx[] = {-1,1,1,-1};
int dy[] = {-1,-1,1,1};
 
void tile(int size, int type, int x, int y) {
    if(size == 2) {
        printf("%d %d %d\n", type+1, x, y);
        return;
    }
    tile(size/2, type, x, y);
    rep(i,0,4) {
        if((i+2)%4 == type) continue;
        tile(size/2, i, x+dx[i]*size/4, y+dy[i]*size/4);
    }
}
 
signed main() {
    int l, m;
    scanf("%d%d", &l, &m);
    for(int s=m; s<l; s*=2) tile(s*2, 0, l-s, l-s);
}