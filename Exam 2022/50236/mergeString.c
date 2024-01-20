#include <stddef.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))
#define ll long long
#define oo 1e9
 
void mergeString(char** P, char L[26], char* A) {
    int n = 0;
    while(P[n] != NULL) n++;
    int C[128]; // cost
    rep(i,0,26) C[L[i]] = i;
    int ai = 0, idx[205] = {0};
 
    while(1) {
        int minn = oo, mini, finish = 0;
        rep(i,0,n) {
            char p = P[i][idx[i]];
            if(p == '\0') {
                finish++;
                continue;
            }
            if(C[p] < minn) {
                minn = C[p];
                mini = i;
            }
        }
        if(finish == n) return;
 
        A[ai++] = P[mini][idx[mini]++];
    }
}