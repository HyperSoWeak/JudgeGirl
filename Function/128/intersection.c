#include "intersection.h"
void intersection(int map[100][100], int result[4]) {
    int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};
    for(int i=0; i<4; ++i) result[i] = 0;
    for(int i=0; i<100; ++i) {
        for(int j=0; j<100; ++j) {
            if(map[i][j] != 1) continue;
            int cnt = 0;
            for(int k=0; k<4; ++k) {
                int x = i+dx[k], y = j+dy[k];
                if(x<0 || y<0 || x>=100 || y>=100) continue;
                if(map[x][y] == 1) cnt++;
            }
            if(cnt==2 && 
                ((i+1<100 && i-1>=0 && (map[i+1][j]==map[i-1][j]==1)) || 
                (j+1<100 && j-1>=0 && (map[i][j+1]==map[i][j-1]==1)))
            ) continue;
            if(cnt==0) continue;
            result[4-cnt]++;
        }
    }
}