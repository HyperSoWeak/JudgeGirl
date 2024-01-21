#include <stdbool.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
 
void count_collision(int *ptr[], int A[], int n, int a, int b, int c) {
    bool used[c];
    rep(i,0,c) {
        used[i] = 0;
        A[i] = 0;
    }
    rep(x,0,n) {
        int f = (a * x + b) % c;
        ptr[x] = A + f;
        if(used[f]) A[f]++;
        else used[f] = 1;
    }
}