#define R_distance rDis
#define G_distance gDis
#define B_distance bDis
#define G_origin go
#define G_destination gd
#define startStation ss
#define endStation es
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))
 
int abs(int a) { return a>0 ? a : -a; }
 
int swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
 
int stationDistance(int R_distance[],int G_distance[],int B_distance[],int G_origin,int G_destination,int startStation[],int endStation[]) {
    int gLen = 0, gl;
    for(gl=0; gDis[gl]!=0; ++gl) gLen += gDis[gl];
 
    int ans = 0;
    if(ss[0] == es[0]) {
        if(ss[1] > es[1]) swap(&ss[1], &es[1]);
        if(ss[0]==0) rep1(i,ss[1]-1,es[1]-2) ans += rDis[i];
        else if(ss[0]==1) rep1(i,ss[1]-1,es[1]-2) ans += gDis[i];
        else rep1(i,ss[1]-1,es[1]-2) ans += bDis[i];
        return ans;
    }
 
    if(ss[0] > es[0]) {
        swap(&ss[0], &es[0]);
        swap(&ss[1], &es[1]);
    }
 
    if(es[0]-ss[0] == 1) {
        if(ss[0] == 0) {
            rep1(i,min(ss[1],go)-1,max(ss[1],go)-2) ans += rDis[i];
            rep1(i,0,es[1]-2) ans += gDis[i];
        } else {
            rep1(i,ss[1]-1,gl-1) ans += gDis[i];
            rep1(i,min(es[1],gd)-1,max(es[1],gd)-2) ans += bDis[i];
        }
        return ans;
    }
 
    rep1(i,min(ss[1],go)-1,max(ss[1],go)-2) ans += rDis[i];
    ans += gLen;
    rep1(i,min(es[1],gd)-1,max(es[1],gd)-2) ans += bDis[i];
    return ans;
}