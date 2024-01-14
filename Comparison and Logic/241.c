#include<stdio.h>
#include<stdlib.h>
 
int main() {
    int x1,y1,x2,y2,x3,y3,x4,y4;
    scanf("%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
    int a = (x1-x2)*y1 - (y1-y2)*x1;
    int b = (x2-x3)*y2 - (y2-y3)*x2;
    int c = (x3-x4)*y3 - (y3-y4)*x3;
    int d = (x4-x1)*y4 - (y4-y1)*x4;
    if(a>=0 && b>=0 && c>=0 && d>=0) printf("1");
    else printf("0");
}