#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>
#include<math.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))
#define OO 1e9
#define ERR 2e9+7
 
signed main() {
    char kb[5][15] = {
        "------------",
        "-qwertyuiop-",
        "-asdfghjkl--",
        "-zxcvbnm----",
        "------------",
    };
    int dx[] = {0,-1,-1,0,1,1};
    int dy[] = {1,1,0,-1,-1,0};
 
    char c;
    int x, y;
    scanf(" %c", &c);
    rep1(i,1,10) rep1(j,1,10) {
        if(kb[i][j] == c) {
            x = i, y = j;
            break;
        }
    }
 
    printf("%c\n", c);
    int dir;
    while(scanf("%d", &dir) != EOF) {
        int nx = x+dx[dir];
        int ny = y+dy[dir];
        if(kb[nx][ny] != '-') {
            printf("%c\n", kb[nx][ny]);
            x = nx, y = ny;
        }
    }
}