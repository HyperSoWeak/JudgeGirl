#include "fill_array.h"
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define oo 1e9
 
void fill_array(int *ptr[], int n) {
    int *a = ptr[0];
    int len = ptr[n-1] - ptr[0] + 1;
    //printf("%d\n", len);
    int pointed[100000] = {0};
 
    rep(i,0,n) {
        *ptr[i] = i;
        pointed[ptr[i]-a] = 1;
    }
 
    int add;
    rep(i,0,len) {
        if(pointed[i]) add = a[i];
        else a[i] = add;
    }
    for(int i=len-1; i>=0; --i) {
        if(pointed[i]) add = a[i];
        else a[i] += add;
    }
}