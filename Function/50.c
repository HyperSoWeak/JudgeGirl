#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) (a)>(b) ? (a) : (b)
#define min(a,b) (a)<(b) ? (a) : (b)
#define ll long long
#define oo 1e9
 
typedef struct Rect{
    int x1,y1,x2,y2;
} Rect;
 
Rect Intersection(Rect a, Rect b) {
    Rect c, e={0,0,0,0};
    c.x1 = max(min(a.x1,a.x2),min(b.x1,b.x2));
    c.x2 = min(max(a.x1,a.x2),max(b.x1,b.x2));
    c.y1 = max(min(a.y1,a.y2),min(b.y1,b.y2));
    c.y2 = min(max(a.y1,a.y2),max(b.y1,b.y2));
    if(c.x1>=c.x2 || c.y1>=c.y2) return e;
    else return c;
}
 
int Area(Rect a) {
    return (a.x2-a.x1)*(a.y2-a.y1);
}
 
signed main() {
    Rect a,b,c;
    scanf("%d%d%d%d",&a.x1,&a.y1,&a.x2,&a.y2);
    scanf("%d%d%d%d",&b.x1,&b.y1,&b.x2,&b.y2);
    scanf("%d%d%d%d",&c.x1,&c.y1,&c.x2,&c.y2);
    Rect ab = Intersection(a,b);
    Rect bc = Intersection(b,c);
    Rect ac = Intersection(a,c);
    Rect abc = Intersection(ab,c);
    printf("%d",Area(a)+Area(b)+Area(c)-Area(ab)-Area(bc)-Area(ac)+Area(abc));
}