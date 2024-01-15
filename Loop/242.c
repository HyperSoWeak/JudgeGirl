#include<stdio.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) (a)>(b) ? (a) : (b)
#define min(a,b) (a)<(b) ? (a) : (b)
#define ll long long
#define oo 1e18
 
typedef struct Rect{
    ll x1,y1,x2,y2;
} Rect;
typedef struct Circle{
    ll x,y,r;
} Circle;
 
Rect Intersection(Rect a, Rect b) {
    Rect c, e={oo,oo,oo,oo};
    c.x1 = max(min(a.x1,a.x2),min(b.x1,b.x2));
    c.x2 = min(max(a.x1,a.x2),max(b.x1,b.x2));
    c.y1 = max(min(a.y1,a.y2),min(b.y1,b.y2));
    c.y2 = min(max(a.y1,a.y2),max(b.y1,b.y2));
    if(c.x1>c.x2 || c.y1>c.y2) return e;
    else return c;
}
ll sq(ll n) { return n*n; }
 
ll Count(Rect x, Circle a[3]) {
    if(x.x1==oo && x.y1==oo && x.x2==oo && x.y2==oo) return 0;
    int ans = 0;
    rep1(i, x.x1, x.x2) {
        rep1(j, x.y1, x.y2) {
            int cnt = 0;
            rep(k,0,3) if(sq(a[k].x-i) + sq(a[k].y-j) <= sq(a[k].r)) cnt++;
            if(cnt==1 || cnt==3) ans++;
        }
    }
    return ans;
}
 
signed main() {
    int n;
    scanf("%d",&n);
    while(n--) {
        Circle a[3];
        scanf("%lld%lld%lld", &a[0].x, &a[0].y, &a[0].r);
        scanf("%lld%lld%lld", &a[1].x, &a[1].y, &a[1].r);
        scanf("%lld%lld%lld", &a[2].x, &a[2].y, &a[2].r);
        Rect x[7] = {
            {a[0].x-a[0].r, a[0].y-a[0].r, a[0].x+a[0].r, a[0].y+a[0].r},
            {a[1].x-a[1].r, a[1].y-a[1].r, a[1].x+a[1].r, a[1].y+a[1].r},
            {a[2].x-a[2].r, a[2].y-a[2].r, a[2].x+a[2].r, a[2].y+a[2].r}
        };
        x[4] = Intersection(x[0],x[1]);
        x[5] = Intersection(x[1],x[2]);
        x[6] = Intersection(x[0],x[2]);
        x[3] = Intersection(x[4],x[2]);
 
        int ans = 0;
        rep(p,0,7) {
            if(p<=3) ans += Count(x[p], a);
            else ans -= Count(x[p], a);
        }
        printf("%d\n", ans);
    }
}