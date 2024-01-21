#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))
 
typedef struct Rect {
    int x1, y1, x2, y2;
} Rect;
 
Rect Inter(Rect a, Rect b) {
    Rect ans = {
        .x1 = max(a.x1,b.x1),
        .y1 = max(a.y1,b.y1),
        .x2 = min(a.x2,b.x2),
        .y2 = min(a.y2,b.y2),
    };
    return ans;
}
 
int Area(Rect a) {
    return (a.x2+1-a.x1)*(a.y2+1-a.y1);
}
 
int calRectArea(int N, int M, int* ptrMat, int* ptrLeft[], int* ptrRight[]) {
    Rect x;
    int ans = 0;
    rep(i,0,M) {
        int a = ptrLeft[i] - ptrMat;
        int b = ptrRight[i] - ptrMat;
        Rect y = {
            .x1 = a/N, .y1 = a%N,
            .x2 = b/N, .y2 = b%N,
        };
        ans += Area(y);
        if(i!=0) ans -= Area(Inter(x,y));
        x = y;
    }
    return ans;
}