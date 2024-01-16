#include<stdio.h>
#include<stdbool.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
 
bool check(int m[3][3], int x) {
    rep(i,0,3) {
        if(m[i][0]==x && m[i][1]==x && m[i][2]==x) return true;
        if(m[0][i]==x && m[1][i]==x && m[2][i]==x) return true;
    }
    if(m[0][0]==x && m[1][1]==x && m[2][2]==x) return true;
    if(m[0][2]==x && m[1][1]==x && m[2][0]==x) return true;
    return false;
}
 
int main() {
    int n,x,y,m[3][3]={{0,0,0},{0,0,0},{0,0,0}},turn=1;
    scanf("%d",&n);
    while(n--) {
        scanf("%d%d",&x,&y);
        if(x<0 || y<0 || x>2 || y>2 || m[x][y]!=0) continue;
        m[x][y] = turn;
        turn*=-1;
    }
    if(check(m, 1)) printf("Black wins.");
    else if(check(m, -1)) printf("White wins.");
    else printf("There is a draw.");
}