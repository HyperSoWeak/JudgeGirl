#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))
#define ll long long
#define oo 1e9
#define MAXN 300005
 
int N, M, key, A[MAXN];
 
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
 
int GetLargest(int i) {
    int largest = 0;
    int l = i*2;
    int r = i*2 + 1;
    if(l <= N && A[l] > A[i]) largest = l;
    else largest = i;
    if(r <= N && A[r] > A[largest]) largest = r;
    return largest;
}
 
void MaxHeapify(int i) {
    int largest = GetLargest(i);
    while(largest != i) {
        swap(&A[i], &A[largest]);
        i = largest;
        largest = GetLargest(i);
    }
}
 
void BuildMaxHeap() {
    for(int i=N/2; i>=1; --i) MaxHeapify(i);
}
 
int HeapExtractMax() {
    int maxn = A[1];
    A[1] = A[N];
    N--;
    MaxHeapify(1);
    return maxn;
}
 
void MaxHeapInsert(int key) {
    N++;
    int i = N;
    A[i] = key;
    while(i>1 && A[i/2]<A[i]) {
        swap(&A[i], &A[i/2]);
        i = i/2;
    }
}
 
signed main() {
    scanf("%d", &N);
    rep1(i,1,N) scanf("%d", &A[i]);
    BuildMaxHeap(A, N);
    rep1(i,1,N) printf("%d%c", A[i], " \n"[i==N]);
    scanf("%d", &M);
    bool first = true;
    while(M--) {
        scanf("%d", &key);
        if(key == -1) {
            if(!first) printf(" ");
            first = false;
            printf("%d", HeapExtractMax());
        } else MaxHeapInsert(key);
    }
}