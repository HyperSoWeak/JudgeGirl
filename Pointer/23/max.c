#include "max.h"
int max(int *iptr[], int n) {
    int maxn = -1e9;
    for(int i = 0; i < n; i++) {
        if(*iptr[i] > maxn) maxn = *iptr[i];
    }
    return maxn;
}