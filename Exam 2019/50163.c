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
#define oo 1e9
#define MAXN 1000
 
void PrintSeat1(int s) {
    printf("%d %d %d\n", s/100+1, (s%100)/5+1, s%5+1);
}
 
void PrintSeat2(int s, int t) {
    printf("%d %d %d ", s/100+1, (s%100)/5+1, s%5+1);
    printf("%d %d %d\n", t/100+1, (t%100)/5+1, t%5+1);
}
 
signed main() {
    bool vis[MAXN * 20 * 5] = {0};
    int last1 = 0, last2 = 0;
    int n, q;
    scanf("%d", &n);
    while(scanf("%d", &q) != EOF) {
        if(q == 1) {
            int s = last1;
            while(vis[s]) s++;
            PrintSeat1(s);
            vis[s] = 1;
            last1 = s+1;
            last2 = max(last2, s+1);
        } else {
            int s = last2;
            while(true) {
                int num = s%5 + 1;
                if(!vis[s] && !vis[s+1] &&
                   (num==1 || num==2 || num==4)) break;
                s++;
            }
 
            if(s < n*100) {
                PrintSeat2(s, s+1);
                vis[s] = vis[s+1] = 1;
                last2 = s+2;
            } else {
                s = last1;
                while(vis[s]) s++;
                int t = s+1;
                while(vis[t]) t++;
                PrintSeat2(s, t);
                vis[s] = vis[t] = 1;
                last1 = t+1;
                last2 = max(last2, t+1);
            }
        }
    }
}