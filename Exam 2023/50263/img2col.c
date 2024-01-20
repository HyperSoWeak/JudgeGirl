#include "image2column.h"
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
 
void img2col(int h, int w, int k, int imgMatrix[MAXH][MAXW], int colMatrix[MAXK * MAXK][MAXW * MAXH]) {
    int idx = 0;
    rep(x,0,h-k+1) rep(y,0,w-k+1) {
        rep(i,0,k) rep(j,0,k) colMatrix[i*k+j][idx] = imgMatrix[x+i][y+j];
        idx++;
    }
}