#include <stdio.h>
#include <stdbool.h>
 
void sumOfIntegers(const int *ptrArray[], int answer[], int *numberOfBlocks) {
    *numberOfBlocks = 0;
    int start = 0;
 
    for(int i=0; ; ++i) {
        if(ptrArray[i]==NULL) {
            i++;
            (*numberOfBlocks)++;
            if(ptrArray[i]==NULL) break;
            start = i;
        }
 
        bool find = false;
        for(int j=start; j<i; ++j) {
            if(ptrArray[i] == ptrArray[j]) {
                find = true;
                break;
            }
        }
 
        if(!find) answer[*numberOfBlocks] += *ptrArray[i];
    }
}