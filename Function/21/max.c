#include "max.h"
int max(int array[5][5]) {
    int ans = -1e9;
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            if(array[i][j] > ans) ans = array[i][j];
    return ans;
}