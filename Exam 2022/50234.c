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
#define MAXN 105
#define KEY 0
#define IDX 1
 
int heap[MAXN*MAXN][2], size;
 
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
 
int GetLargest(int i) {
    int largest;
    int l = i * 2;
    int r = i * 2 + 1;
    if(l <= size && heap[l][KEY] > heap[i][KEY]) largest = l;
    else largest = i;
    if(r <= size && heap[r][KEY] > heap[largest][KEY]) largest = r;
    return largest;
}
 
void MaxHeapify(int i) {
    int largest = GetLargest(i);
    while(largest != i) {
        swap(&heap[largest][KEY], &heap[i][KEY]);
        swap(&heap[largest][IDX], &heap[i][IDX]);
        i = largest;
        largest = GetLargest(i);
    }
}
 
void BuildMaxHeap() {
    for(int i=size/2; i>=1; --i) MaxHeapify(i);
}
 
int GetTop(int x) {
    if(size < 1) return -1;
    return heap[1][x];
}
 
void PopTop() {
    heap[1][KEY] = heap[size][KEY];
    heap[1][IDX] = heap[size][IDX];
    size--;
    MaxHeapify(1);
}
 
bool IsEmpty() {
    return size == 0;
}
 
void Insert(int key, int idx) {
    size++;
    int i = size;
    heap[i][KEY] = key;
    heap[i][IDX] = idx; 
    while(i>1 && heap[i][KEY]>heap[i/2][KEY]) {
        swap(&heap[i][KEY], &heap[i/2][KEY]);
        swap(&heap[i][IDX], &heap[i/2][IDX]);
        i = i/2;
    }
}
 
int GetKey(int x, int y, int t[MAXN][MAXN][MAXN], int h[MAXN][MAXN]) {
    if(h[x][y] <= 0) return -1;
    return t[h[x][y]][x][y];
}
 
signed main() {
    int n, t[MAXN][MAXN][MAXN], h[MAXN][MAXN];
    scanf("%d", &n);
    size = n*n;
    rep(i,0,n) rep(x,0,i+1) rep(y,0,i+1) scanf("%d", &t[n-i][x][y]);
    rep(x,0,n) rep(y,0,n) {
        h[x][y] = n - max(x, y);
        int idx = x * n + y + 1;
        heap[idx][KEY] = GetKey(x, y, t, h);
        heap[idx][IDX] = idx;
    }
    BuildMaxHeap();
    bool first = true;
    while(!IsEmpty()) {
        if(first) first = false;
        else printf(" ");
        printf("%d", GetTop(KEY));
        int idx = GetTop(IDX);
        PopTop();
        int x = (idx-1) / n;
        int y = (idx-1) % n;
        h[x][y]--;
        int key = GetKey(x, y, t, h);
        if(key != -1) Insert(key, idx);
    }
}