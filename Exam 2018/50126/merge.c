#include<stdio.h>
#include<stdbool.h>
 
void merge(int A[], int B[], int* a[], int* b[]) {
    int ai=0, bi=0;
    int **last = NULL;
    bool isA;
 
    do {
        if(A[ai] < B[bi]) {
            if(last != NULL) *last = &A[ai];
            last = &a[ai++];
            isA = true;
        } else {
            if(last != NULL) *last = &B[bi];
            last = &b[bi++];
            isA = false;
        }
    } while(*last != NULL);
    *last = isA ? &B[bi] : &A[ai];
}