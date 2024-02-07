#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) (a)>(b) ? (a) : (b)
#define min(a,b) (a)<(b) ? (a) : (b)
#define ll long long
#define oo 1e9
 
int abs(int x) { return x < 0 ? -x : x; }
 
signed main() {
    int L, X, Y, n, x1, y1, x2, y2;
    char a[100][100];
    rep(i,0,100) rep(j,0,100) a[i][j] = 0;
    scanf("%d%d%d", &L, &Y, &X);
    rep1(p,1,L) {
        scanf("%d%d%d", &n, &x1, &y1);
        if(x1>=X || y1>=Y || x1<0 || y1<0) {
            printf("ERROR %d 1", p);
            return 0;
        }
        rep(i,1,n) {
            scanf("%d%d", &x2, &y2);
            int xmax = max(x1,x2), xmin = min(x1,x2);
            int ymax = max(y1,y2), ymin = min(y1,y2);
            if(x2>=X || y2>=Y || x2<0 || y2<0) {
                printf("ERROR %d %d", p ,i+1);
                return 0;
            }
            if(x1==x2) rep1(j,ymin,ymax) a[x1][j] = 1;
            else if(y1==y2) rep1(j,xmin,xmax) a[j][y1] = 1;
            else if(xmax-xmin == ymax-ymin) {
                if(x1==xmin&&y1==ymin || x1==xmax&&y1==ymax)
                    rep1(i,0,xmax-xmin) a[xmin+i][ymin+i] = 1;
                else rep1(i,0,xmax-xmin) a[xmax-i][ymin+i] = 1;
            } else {
                printf("ERROR %d %d", p ,i+1);
                return 0;
            }
            x1 = x2, y1 = y2;
        }
    }
    for(int i=Y-1; i>=0; --i) {
        rep(j,0,X) printf("%d", a[j][i]);
        printf("\n");
    }
}