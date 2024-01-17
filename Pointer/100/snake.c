#include <stdlib.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
 
typedef struct Data {
    int value;
    int *ptr;
} Data;
 
int cmp(const void *A, const void *B) {
    Data *a = (Data *)A;
    Data *b = (Data *)B;
    if(a->value < b->value) return -1;
    else return 1;
}
 
void snake(const int *ptr_array[100][100], int m) {
    Data a[10000];
    rep(i,0,m) rep(j,0,m) {
        a[i*m+j].value = *ptr_array[i][j];
        a[i*m+j].ptr = ptr_array[i][j];
    }
    qsort(a, m*m, sizeof(Data), cmp);
    rep(i,0,m) rep(j,0,m) {
        ptr_array[i][i%2 ? m-j-1 : j] = a[i*m+j].ptr;
    }
}