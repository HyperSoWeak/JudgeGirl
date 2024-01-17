#include "evaluate_f.h"
 
int evaluate_f(int *iptr[], int n, int *index) {
  int maxn = -1e9;
  for(int i = 0; i < n; i++) {
    int f = 4 * (*iptr[i]) - 6 * (*(iptr[i]+1));
    if(f > maxn) {
      maxn = f;
      *index = i;
    }
  }
  return maxn;
}