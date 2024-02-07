#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
 
void game_of_cell(int grid[50][50],int outcome[50][50],int N) {
    int tran[3][9] = { // [prev][cnt]
        {0,0,0,2,0,0,0,0,0},
        {1,1,2,1,1,1,1,1,1},
        {0,0,2,2,1,1,1,1,1}
    };
    int dx[] = {1,1,1,0,0,-1,-1,-1};
    int dy[] = {1,0,-1,1,-1,1,0,-1};
    int m[52][52] = {0};
    rep(x,0,50) rep(y,0,50) m[x+1][y+1] = grid[x][y];
    while(N--) {
        int cnt[52][52] = {0};
        rep1(x,1,50) rep1(y,1,50) {
            rep(i,0,8) cnt[x][y] += m[x+dx[i]][y+dy[i]] / 2;
        }
        rep1(x,1,50) rep1(y,1,50) m[x][y] = tran[m[x][y]][cnt[x][y]];
    }
    rep(x,0,50) rep(y,0,50) outcome[x][y] = m[x+1][y+1];
}