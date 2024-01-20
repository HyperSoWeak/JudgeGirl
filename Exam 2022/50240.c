#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))
#define OO 1e9
#define ERR 2e9+7
#define MAXHS 10005
#define MAXN 100
 
typedef struct Str {
    char s[105];
    int x, y;
} Str;
 
void SwapStr(Str *x, Str *y) {
    Str t = *x;
    *x = *y;
    *y = t;
}
 
int HS = 0; // HeapSize
Str A[MAXHS];
 
int GetLargest(int i) {
    int largest;
    int l = (i << 1);
    int r = (i << 1) + 1;
    if(l <= HS && strcmp(A[l].s,A[i].s) > 0) largest = l;
    else largest = i;
    if(r <= HS && strcmp(A[r].s,A[largest].s) > 0) largest = r;
    return largest;
}
 
void MaxHeapify(int i) {
    int largest = GetLargest(i);
    while(largest != i) {
        SwapStr(&A[i], &A[largest]);
        i = largest;
        largest = GetLargest(i);
    }
}
 
Str ExtractMaxHeap() {
    //if(HS < 1) return ERR;
    Str res = A[1];
    A[1] = A[HS];
    HS--;
    MaxHeapify(1);
    return res;
}
 
void InsertMaxHeap(Str key) {
    HS++;
    int i = HS;
    A[i] = key;
    while(i > 1 && strcmp(A[i/2].s,A[i].s) < 0) {
        SwapStr(&A[i/2], &A[i]);
        i /= 2;
    }
}
 
int N, M;
int h[MAXN][MAXN] = 0;
char t[MAXN][MAXN][MAXN];
 
Str GetStr(int x, int y) {
    Str res = {
        .s = "\0",
        .x = x,
        .y = y,
    };
 
    // end of tower
    if(h[x][y] == M) return res;
 
    int i = 0;
    do {
        res.s[i++] = t[h[x][y]][x][y];
    } while(t[h[x][y]++][x][y] != '\0');
 
    return res;
}
 
void PrintStr(Str s) {
    printf("%s, (%d, %d)\n", s.s, s.x, s.y);
}
 
signed main() {    
    scanf("%d%d", &N, &M);
    rep(k,0,M) rep(i,0,N) {
        scanf("%s", t[k][i]);
        rep(j,0,N) if(t[k][i][j]=='0') t[k][i][j] = '\0';
    }
 
    rep(i,0,N) rep(j,0,N) {
        InsertMaxHeap(GetStr(i, j));
    }
 
    while(HS > 0) {
        Str now = ExtractMaxHeap();
        printf("%s\n", now.s);
        Str key = GetStr(now.x, now.y);
        if(key.s[0] != '\0') InsertMaxHeap(key);
    }   
}