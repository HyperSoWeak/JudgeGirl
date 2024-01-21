#include <stdio.h>
#include "permute.h"
#define rep(i,a,b) for(int i=a; i<b; ++i)
 
void permute(int *ptrArray[MAX], int *ptrPerms[MAX]) {
    int *pA[MAX];
    int n = 0;
    while(ptrArray[n] != NULL) {
        pA[n] = ptrArray[n];
        n++;
    }
    int idx = 0;
    while(ptrPerms[idx] != NULL) {
        rep(i,0,n) ptrArray[i] = pA[ptrPerms[idx][i]];
        rep(i,0,n) pA[i] = ptrArray[i];
        idx++;
    }
}