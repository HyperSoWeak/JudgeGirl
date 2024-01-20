#include <stddef.h>
 
void sparseMatrixMult(int** A, int** B) {
    for(int ai=0; A[ai]!=NULL; ai++) {
        int ar = A[ai][0];
        for(int bi=0; B[bi]!=NULL; bi++) {
            int bc = B[bi][0];
 
            int sum = 0;
 
            for(int aj=1,ac=A[ai][aj],av=A[ai][aj+1]; A[ai][aj]!=-1; aj+=2,ac=A[ai][aj],av=A[ai][aj+1]) {
                for(int bj=1,br=B[bi][bj],bv=B[bi][bj+1]; B[bi][bj]!=-1; bj+=2,br=B[bi][bj],bv=B[bi][bj+1]) {
                    if(br == ac) {
                        sum += av * bv;
                        break;
                    }
                }
            }
 
            if(sum) printf("%d %d %d\n", ar, bc, sum);
        }
    }
}