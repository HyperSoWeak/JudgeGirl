#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>
#include<math.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))
#define oo 1e9
 
typedef struct Node {
    int val, height;
    struct Node *left, *right;
} Node;
 
typedef struct Data {
    int val, layer;
} Data;
 
int cmp(const void *a, const void *b) {
    const Data *A = (Data *)a;
    const Data *B = (Data *)b;
    return A->layer - B->layer;
}
 
Node *NewNode(int val, int height, Node *left, Node *right) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->val = val;
    node->height = height;
    node->left = left;
    node->right = right;
    return node;
}
 
void InsertNode(Node *root, Node *node) {
    if(node->val < root->val) {
        if(root->left == NULL) root->left = node;
        else InsertNode(root->left, node);
    } else {
        if(root->right == NULL) root->right = node;
        else InsertNode(root->right, node);
    }
}
 
Node *FindNode(Node *root, int val) {
    while(root->val != val) {
        if(val < root->val) root = root->left;
        else root = root->right;
    }
    return root;
}
 
Node *FindLca(Node *root, int a, int b) {
    if(a < root->val && b < root->val) {
        return FindLca(root->left, a, b);
    } else if(a > root->val && b > root->val) {
        return FindLca(root->right, a, b);
    } else return root;
}
 
int Dis(Node *root, int a, int b) {
    Node *A = FindNode(root, a);
    Node *B = FindNode(root, b);
    Node *lca = FindLca(root, a, b);
    return A->height + B->height - 2*lca->height;
}
 
signed main() {
    int n, p, a, b;
    Data data[1005];
    scanf("%d", &n);
    rep(i,0,n) scanf("%d %d", &data[i].val, &data[i].layer);
 
    qsort(data, n, sizeof(data[0]), cmp);
    Node *root = NewNode(data[0].val, data[0].layer, NULL, NULL);
    rep(i,1,n) InsertNode(root, NewNode(data[i].val, data[i].layer, NULL, NULL));
 
    scanf("%d", &p);
    rep(i,0,p) {
        scanf("%d %d", &a, &b);
        printf("%d\n", Dis(root, a, b));
    }
}