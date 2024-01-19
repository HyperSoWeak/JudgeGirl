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
    int value;
    struct Node *left, *right;
} Node;
 
char ex[4096], *eptr;
 
char peek() { return *eptr; }
 
void fetch(char c) {
    assert(peek() == c);
    eptr++;
}
 
Node *NewNode(int value, Node *left, Node *right) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;
    node->left = left;
    node->right = right;
    return node;
}
 
Node *parser() {
    char c = peek();
    Node *L, *R;
    if(c == '(') {
        fetch('(');
        L = parser();
        fetch(',');
        R = parser();
        fetch(')');
        return NewNode(L->value + R->value, L, R);
    } else {
        int num;
        sscanf(eptr, "%d", &num);
        while(isdigit(*eptr) || *eptr == '-') eptr++;
        return NewNode(num, NULL, NULL);
    }
}
 
void traversal(Node *n, bool HLHR) {
    if(n == NULL) return;
 
    if(HLHR) {
        printf("%d\n", n->value);
        traversal(n->left, !HLHR);
        printf("%d\n", n->value);
        traversal(n->right, !HLHR);
    } else {
        printf("%d\n", n->value);
        traversal(n->right, !HLHR);
        printf("%d\n", n->value);
        traversal(n->left, !HLHR);
    }
}
 
signed main() {
    scanf("%s", ex);
    eptr = ex;
    Node *root = parser();
    traversal(root, true);
}