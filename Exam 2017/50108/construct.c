#include <stdlib.h>
#include "construct.h"
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define MAXLENGTH 5

int cmp(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}
 
int findKth(int seq[], int a, int b) {
    int len = b - a + 1;
    if(len < MAXLENGTH) return -1;
 
    int tmp[16384];
    rep(i,0,len) tmp[i] = seq[a+i];
    qsort(tmp, len, sizeof(tmp[0]), cmp);
 
    rep1(i,a,b) if(seq[i] == tmp[MAXLENGTH-1]) return i;
    return -1;
}
 
Node *NewNode(int value, Node *left, Node *right) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;
    node->left = left;
    node->right = right;
    return node;
}
 
Node *GenList(int seq[], int a, int b) {
    if(a > b) return NULL;
    return NewNode(
        seq[b],
        GenList(seq, a, b-1),
        NULL
    );
}
 
Node *GenTree(int seq[], int a, int b) {
    if(a > b) return NULL;
 
    int kth = findKth(seq, a, b);
    if(kth == -1) return GenList(seq, a, b);
    else return NewNode(
        seq[kth],
        GenTree(seq, a, kth-1),
        GenTree(seq, kth+1, b)
    );
}
 
Node* ConstructTree(int sequence[], int N) {
    return GenTree(sequence, 0, N-1);
}