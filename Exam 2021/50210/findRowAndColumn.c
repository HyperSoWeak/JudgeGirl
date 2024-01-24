#include <stdio.h>
void findRowAndColumn(int **ptr, int *Row, int *Col, int **start, int *ansRow, int *ansCol) {
    int i = 0;
    while(ptr[i] != NULL) {
        int x = ptr[i] - start[i];
        ansRow[i] = x / Col[i];
        ansCol[i] = x % Col[i];
        i++;
    }
}