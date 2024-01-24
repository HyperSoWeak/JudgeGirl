#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>
#include<math.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))
#define OO 1e9
#define ERR 2e9+7
#define MAXN 100005
 
void Merge(int a[], int l, int mid, int r) {
    int lenA = mid - l;
    int lenB = r - mid;
    int A[lenA], B[lenB];
 
    rep(i,0,lenA) A[i] = a[l+i];
    rep(i,0,lenB) B[i] = a[mid+i];
 
    int idx=l, ai=0, bi=0;
    while(ai<lenA && bi<lenB) {
        if(A[ai] < B[bi]) a[idx++] = A[ai++];
        else a[idx++] = B[bi++];
    }
    while(ai<lenA) a[idx++] = A[ai++];
    while(bi<lenB) a[idx++] = B[bi++];
}
 
void PrintArr(int a[], int l, int r) {
    rep(i,l,r) printf("%d%c", a[i], " \n"[i==r-1]);
}
 
void MergeSort(int a[], int l, int r) {
    if(l >= r-1) {
        PrintArr(a, l, r);
        return;
    }
    PrintArr(a, l, r);
    int mid = (l+r)/2;
    MergeSort(a, l, mid);
    MergeSort(a, mid, r);
    Merge(a, l, mid, r);
    PrintArr(a, l, r);
}
 
signed main() {
    int n = 0, a[MAXN];
    while(scanf("%d", &a[n]) != EOF) n++;
    MergeSort(a, 0, n);
}