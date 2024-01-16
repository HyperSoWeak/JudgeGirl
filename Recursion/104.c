#include<stdio.h>
#include<stdbool.h>
 
int DA, DB, DC;
int EA, EB, EC;
int FA, FB, FC;
 
bool solve(int a, int b, int c, int n) {
    if(a==0 && b==0 && c==0) return true;
    if(a<0 || b<0 || c<0) return false;
 
    if(n<=0 && solve(a-DA,b-DB,c-DC,0)) return true;
    if(n<=1 && solve(a-EA,b-EB,c-EC,1)) return true;
    if(n<=2 && solve(a-FA,b-FB,c-FC,2)) return true;
 
    return false;
}
 
void loop(int n) {
    if(n==0) return;
 
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("%s\n", solve(a,b,c,0) ? "yes" : "no");
 
    loop(n-1);
}
 
signed main() {
    scanf("%d%d%d", &DA, &DB, &DC);
    scanf("%d%d%d", &EA, &EB, &EC);
    scanf("%d%d%d", &FA, &FB, &FC);
    int n;
    scanf("%d", &n);
    loop(n);
}