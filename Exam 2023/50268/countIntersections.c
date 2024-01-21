#include <stdio.h>
#include "countIntersections.h"
 
int countIntersections(int* ptrArray[]) {
    int cnt = 0;
    int *maxptr = ptrArray;
    for(int i=0; ptrArray[i]!=NULL; ++i) {
        *ptrArray[i] = 1;
        for(int *ptr=ptrArray[i]; ptr<maxptr; ptr++)
            if(*ptr) cnt++;
        if(ptrArray[i] > maxptr) maxptr = ptrArray[i];
    }
    return cnt;
}