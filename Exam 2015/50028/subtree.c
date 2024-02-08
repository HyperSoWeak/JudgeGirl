#include "subtree.h"
#include <stdlib.h>
#include <stdbool.h>
 
bool find(Node *n, int label[], int k, int *cnt) {
    if(n == NULL) return false;
 
    bool left = find(n->left, label, k, cnt);
    bool right = find(n->right, label, k, cnt);
 
    if(left && right && n->label!=k) {
        label[*cnt] = n->label;
        (*cnt)++;
    }
 
    if(left || right || n->label==k) return true;
    return false;
}
 
int getNode(Node *root, int label[], int k) {
    int cnt = 0;
    find(root, label, k, &cnt);
    return cnt;
}