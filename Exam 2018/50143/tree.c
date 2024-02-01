#include <stdlib.h>
#include "tree.h"
 
Node *NewNode(int val, Node *left, Node *right) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->val = val;
    node->left = left;
    node->right = right;
    return node;
}
 
Node *treeAND(Node *root1, Node *root2) {
    if(root1 == NULL || root2 == NULL) return NULL;
    return NewNode(
        root1->val * root2->val,
        treeAND(root1->left, root2->left),
        treeAND(root1->right, root2->right)
    );
}
 
Node *treeOR(Node *root1, Node *root2) {
    if(root1 == NULL) return root2;
    if(root2 == NULL) return root1;
    return NewNode(
        root1->val + root2->val,
        treeOR(root1->left, root2->left),
        treeOR(root1->right, root2->right)
    );
}