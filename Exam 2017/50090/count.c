#include<stdio.h>
#include<stdlib.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
 
typedef struct Idk {
    int *ptr;
    int cnt;
} Idk;
 
int cmp(const void *a, const void *b) {
    const Idk *A = (const Idk *)a;
    const Idk *B = (const Idk *)b;
    if(A->cnt == B->cnt) return *(A->ptr) - *(B->ptr);
    return A->cnt - B->cnt;
}
 
void count(int **p[]) {
    Idk a[512];
    int n = 0, ai = 0;
    while(p[n] != NULL) {
        int *ptr = *p[n];
 
        int find = 0;
        rep(i,0,ai) {
            if(a[i].ptr == ptr) {
                a[i].cnt++;
                find = 1;
                break;
            }
        }
        if(!find) {
            Idk idk = {
                .ptr = ptr,
                .cnt = 1,
            };
            a[ai++] = idk;
        }
 
        n++;
    }
 
    qsort(a, ai, sizeof(Idk), cmp);
 
    rep(i,0,ai) {
        printf("%d %d\n", *a[i].ptr, a[i].cnt);
    }
}