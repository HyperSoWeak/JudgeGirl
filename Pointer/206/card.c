#include <stdio.h>
#include "card.h"
 
void shuffle(int *deck[]) {
    int index = 0;
    int *a[10000];
    while(deck[index] != NULL) {
        a[index] = deck[index];
        index++;
    }
    int n = (index+1)/2;
    for(int i=0; i<n; i++) {
        deck[i*2] = a[i];
    }
    for(int i=n; i<index; i++) {
        deck[(i-n)*2+1] = a[i];
    }
}
 
 
void print(int *deck[]) {
    if(deck[0] == NULL) return;
    int index = 0;
    while(deck[index+1] != NULL) {
        printf("%d ", *deck[index]);
        index++;
    }
    printf("%d ", *deck[index]);
}