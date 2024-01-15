#include<stdio.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define int long long
 
typedef struct Point { int x, y; } Point;
typedef Point Vector;
int dot(Vector a, Vector b) { return a.x*b.x + a.y*b.y; }
int cross(Vector a, Vector b) { return a.x*b.y - a.y*b.x; }
int vecLen(Vector a) { return a.x*a.x + a.y*a.y; }
 
signed main() {
    char type[4][15] = {"other", "rectangle", "diamond", "square"};
    int n,x1,y1,x2,y2,x3,y3,x4,y4;
    scanf("%lld",&n);
    while(n--) {
        scanf("%lld%lld%lld%lld%lld%lld%lld%lld",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
        Vector v1 = {x1-x4, y1-y4};
        Vector v2 = {x2-x4, y2-y4};
        Vector v3 = {x3-x4, y3-y4};
        Vector e1,e2,e3,e4;
        if(cross(v1,v2)*cross(v1,v3) < 0) {
            e1.x=x2-x4, e1.y=y2-y4;
            e2.x=x1-x2, e2.y=y1-y2;
            e3.x=x3-x1, e3.y=y3-y1;
            e4.x=x4-x3, e4.y=y4-y3;
        } else if(cross(v2,v1)*cross(v2,v3) < 0) {
            e1.x=x1-x4, e1.y=y1-y4;
            e2.x=x2-x1, e2.y=y2-y1;
            e3.x=x3-x2, e3.y=y3-y2;
            e4.x=x4-x3, e4.y=y4-y3;
        } else {
            e1.x=x1-x4, e1.y=y1-y4;
            e2.x=x3-x1, e2.y=y3-y1;
            e3.x=x2-x3, e3.y=y2-y3;
            e4.x=x4-x2, e4.y=y4-y2;
        }
        int k=0;
        if(vecLen(e1)==vecLen(e2) && vecLen(e1)==vecLen(e3) && vecLen(e1)==vecLen(e4)) k+=2;
        if(dot(e1,e2)==0 && dot(e2,e3)==0 && dot(e3,e4)==0) k++;
        printf("%s\n", type[k]);
    }
}