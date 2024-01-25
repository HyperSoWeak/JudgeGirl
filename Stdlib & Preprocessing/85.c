#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>
#include<math.h>
#define int long long
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))
#define OO 1e9
#define ERR 2e9+7
#define MAXN 1000005
 
int a[MAXN];
 
void Merge(int a[], int l, int mid, int r) {
    int lenA = mid - l + 1;
    int lenB = r - mid;
    int A[lenA], B[lenB];
 
    rep(i,0,lenA) A[i] = a[l+i];
    rep(i,0,lenB) B[i] = a[mid+1+i];
 
    int idx=l, ai=0, bi=0;
    while(ai<lenA && bi<lenB) {
        if(A[ai] < B[bi]) a[idx++] = A[ai++];
        else a[idx++] = B[bi++];
    }
    while(ai<lenA) a[idx++] = A[ai++];
    while(bi<lenB) a[idx++] = B[bi++];
}
 
void MergeSort(int a[], int l, int r) {
    if(l >= r) return;
    int mid = (l+r)/2;
    MergeSort(a, l, mid);
    MergeSort(a, mid+1, r);
    Merge(a, l, mid, r);
}
 
signed main() {
    int n, y, m, d;
    scanf("%lld", &n);
    rep(i,0,n) {
        scanf("%lld%lld%lld", &y, &m, &d);
        a[i] = y*10000 + m*100 + d;
    }
    MergeSort(a, 0, n-1);
    rep(i,0,n) {
        printf("%lld %lld %lld\n", a[i]/10000, (a[i]%10000)/100, a[i]%100);
    }
}