#include <stdio.h>
#include "multiply.h"
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
 
void multiplyMatrix(void ** arrayA, void ** arrayB, void ** arrayC) {
    A **Aptr = (A **)arrayA;
    B **Bptr = (B **)arrayB;
    C **Cptr = (C **)arrayC;
 
    for(; *Aptr!=NULL; Aptr++, Bptr++, Cptr++) {
        rep(i,0,ROW) rep(j,0,ROW) {
            (**Cptr)[i][j] = 0;
            rep(k,0,COL) (**Cptr)[i][j] += (**Aptr)[i][k] * (**Bptr)[k][j];
        }
    }
}