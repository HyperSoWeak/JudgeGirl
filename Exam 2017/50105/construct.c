#include <stdlib.h>
#include "construct.h"
 
int FindBalance(int T[], int l, int r) {
    int n = r-l+1;
    long long sum = 0, bf = 0;
    for(int i=0; i<n; ++i) {
        sum += T[l+i];
        bf += T[l+i] * i;
    }
    if(sum == 0) return -2;
    if(bf%sum == 0 && bf/sum < n) return l + bf/sum;
    else return -1; // Not found
}
 
Node *NewNode(int value, Node *left, Node *right) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;
    node->left = left;
    node->right = right;
    return node;
}
 
Node *BuildList(int T[], int l, int r) {
    if(l == r) return NewNode(T[r], NULL, NULL);
    return NewNode(T[r], BuildList(T, l, r-1), NULL);
}
 
Node *BuildTree(int T[], int l, int r) {
    int n = r-l+1;
    if(n <= 0) return NULL;
    if(n < 3) return BuildList(T, l, r);
 
    int bp = FindBalance(T, l, r);
    if(bp == -1) return BuildList(T, l, r);
 
    return NewNode(
        T[bp],
        BuildTree(T, l, bp-1),
        BuildTree(T, bp+1, r)
    );
}
 
Node *ConstructTree(int T[], int N) {
    return BuildTree(T, 0, N-1);
}