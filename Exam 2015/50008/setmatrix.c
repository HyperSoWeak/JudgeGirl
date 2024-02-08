#include <stdio.h>
 
void processSetMatrix(int ***ptr) {
    for(int i=0; ptr[i]!=NULL; ++i) {
        for(int j=0; ptr[i][j]!=NULL; ++j) {
            for(int k=0; ptr[i][j][k]!=0; ++k) {
                if(!(i==0 && j==0 && k==0)) printf(" ");
                printf("%d", ptr[i][j][k]);
            }
        }
    }
}