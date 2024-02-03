#include <stdlib.h>
#include "BuildTree.h"
#define rep(i,a,b) for(int i=a; i<b; i++)
 
int GetLen(Node *list) {
    int len = 0;
    while(list != NULL) {
        list = list->left;
        len++;
    }
    return len;
}
 
Node *SplitList(Node *list) { // return the right half
    if(list == NULL) return NULL;
    int len = GetLen(list);
    rep(i,0,(len-1)/2) list = list->left;
    Node *tmp = list->left;
    list->left = NULL;
    return tmp;
}
 
Node* BuildTree(Node* list1, Node* list2) {
    if(list1 == NULL && list2 == NULL) return NULL;
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;
 
    if(list2->val < list1->val) {
        Node *tmp = list1;
        list1 = list2;
        list2 = tmp;
    }
 
    Node *root = list1;
    list1 = list1->left;
    Node *l1r = SplitList(list1);
    Node *l2r = SplitList(list2);
 
    root->left = BuildTree(list1, list2);
    root->right = BuildTree(l1r, l2r);
    return root;
}