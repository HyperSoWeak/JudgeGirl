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
#define OO 1e9
#define ERR 2e9+7
 
typedef struct Line {
    double a, b, c;
} Line;
typedef struct Point {
    double x, y;
} Point;
 
double det(double x1, double y1, double x2, double y2) {
    return x1 * y2 - x2 * y1;
}
 
Point Intersection(Line x, Line y) {
    double d  = det(x.a, x.b, y.a, y.b);
    double dx = det(x.c, x.b, y.c, y.b);
    double dy = det(x.a, x.c, y.a, y.c);
 
    Point ans = {
        .x = dx/d,
        .y = dy/d,
    };
    return ans;
}
 
void ReadLine(Line *x) {
    scanf("%lf%lf%lf", &(*x).a, &(*x).b, &(*x).c);
}
 
double GetDistance(Point a, Point b) {
    return sqrt((a.x-b.x) * (a.x-b.x) + (a.y-b.y) * (a.y-b.y));
}
 
signed main() {
    int n;
    Line x, y;
    Point p[250];
    scanf("%d", &n);
    ReadLine(&x);
    Line first = x;
    rep(i,1,n) {
        ReadLine(&y);
        p[i] = Intersection(x, y);
        x = y;
    }
    p[0] = Intersection(y, first);
 
    double ans = 0;
    rep(i,0,n-1) {
        ans += GetDistance(p[i], p[i+1]);
    }
    ans += GetDistance(p[n-1], p[0]);
 
    printf("%.3lf", ans);
}