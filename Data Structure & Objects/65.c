#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>
 
typedef enum Type {
    NUM,
    OP,
    VAR
} Type;
 
typedef struct Node {
    Type type;
    int num;
    char op;
    char var[32];
    struct Node *left, *right;
} Node;
 
typedef struct Variable {
    char name[32];
    int value;
} Variable;
 
char expr[1024], *eptr, buf[1024];
int varNum = 0;
Variable v[64];
 
char Peek() {
    while(isspace(*eptr)) eptr++;
    return *eptr;
}
 
void Fetch(char c) {
    assert(Peek() == c);
    eptr++;
}
 
Node *Parser() {
    char c = Peek();
    Node *node = (Node *)malloc(sizeof(Node));
    node->left = NULL;
    node->right = NULL;
 
    if(c == '(') {
        node->type = OP;
        Fetch('(');
        node->op = Peek();
        Fetch(node->op);
        node->left = Parser();
        node->right = Parser();
        Fetch(')');
    } else if(isdigit(c)) {
        node->type = NUM;
        sscanf(eptr, "%d", &node->num);
        while(isdigit(*eptr)) eptr++;
    } else {
        node->type = VAR;
        sscanf(eptr, "%s", node->var);
        while(isdigit(*eptr) || isalpha(*eptr) || *eptr == '_') eptr++;
    }
    return node;
}
 
int Compute(Node *n) {
    if(n == NULL) return 0;
 
    if(n->type == NUM) return n->num;
 
    if(n->type == OP) {
        int l = Compute(n->left);
        int r = Compute(n->right);
 
        switch(n->op) {
            case '+': return l + r;
            case '-': return l - r;
            case '*': return l * r;
            case '/': return l / r;
        }
    }
 
    if(n->type == VAR) {
        for(int i=0; i<varNum; ++i) {
            if(!strcmp(v[i].name, n->var)) return v[i].value;
        }
    }
}
 
signed main() {
    fgets(expr, 1024, stdin);
    eptr = expr;
    Node *root = Parser();
 
    while(fgets(buf, 1024, stdin)) {
        if(sscanf(buf, "%s %*s %d", v[varNum].name, &v[varNum].value) == 2)
            varNum++;
    }
 
    printf("%d\n", Compute(root));
}