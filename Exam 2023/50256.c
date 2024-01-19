#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))
#define ll long long
#define oo 1e9
 
typedef struct Rect {
    int x1;
    int y1;
    int x2;
    int y2;
} Rect;
 
Rect Overlap(Rect a, Rect b) {
    Rect c = {
        .x1 = max(a.x1, b.x1),
        .y1 = max(a.y1, b.y1),
        .x2 = min(a.x2, b.x2),
        .y2 = min(a.y2, b.y2),
    };
    Rect empty = {0,0,0,0};
    if(c.x1 >= c.x2 || c.y1 >= c.y2) return empty;
    else return c;
}
 
int Area(Rect a) {
    return (a.x2-a.x1) * (a.y2-a.y1);
}
 
void ReadRect(Rect *a) {
    int x, y;
    scanf("%d %d %d %d", &a->x1, &a->y1, &x, &y);
    a->x2 = a->x1 + x;
    a->y2 = a->y1 + y;
}
 
void PrintRect(const Rect a) {
    printf("%d %d %d %d\n", a.x1, a.y1, a.x2, a.y2);
}
 
signed main() {
    int n;
    scanf("%d", &n);
    Rect a, b;
    ReadRect(&a);
    int ans = Area(a);
    rep(i,1,n) {
        ReadRect(&b);
        Rect c = Overlap(a, b);
        ans += Area(b) - Area(c);
        a = b;
    }
    printf("%d", ans);
}