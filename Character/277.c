#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) (a)>(b) ? (a) : (b)
#define min(a,b) (a)<(b) ? (a) : (b)
#define ll long long
#define oo 1e9
 
signed main() {
    bool t[10][7] = {
        {1,1,1,0,1,1,1}, //0
        {0,0,1,0,0,1,0}, //1
        {1,0,1,1,1,0,1}, //2
        {1,0,1,1,0,1,1}, //3
        {0,1,1,1,0,1,0}, //4
        {1,1,0,1,0,1,1}, //5
        {1,1,0,1,1,1,1}, //6
        {1,1,1,0,0,1,0}, //7
        {1,1,1,1,1,1,1}, //8
        {1,1,1,1,0,1,0}  //9
    };
    char s[15];
    int w, h;
    while(scanf("%s%d%d", &s, &w, &h) != EOF) {
        rep(i,0,strlen(s)) {
            if(t[s[i]-48][0]) {
                printf(" ");
                rep(j,0,w-3) printf("%d", s[i]-48);
                printf("  ");
            } else {
                rep(j,0,w) printf(" ");
            }
        }
        printf("\n");
        rep(k,0,(h-3)/2) {
            rep(i,0,strlen(s)) {
                if(t[s[i]-48][1]) printf("%d", s[i]-48);
                else printf(" ");
                rep(j,0,w-3) printf(" ");
                if(t[s[i]-48][2]) printf("%d ", s[i]-48);
                else printf("  ");
            }
            printf("\n");
        }
        rep(i,0,strlen(s)) {
            if(t[s[i]-48][3]) {
                printf(" ");
                rep(j,0,w-3) printf("%d", s[i]-48);
                printf("  ");
            } else {
                rep(j,0,w) printf(" ");
            }
        }
        printf("\n");
        rep(k,0,(h-3)/2) {
            rep(i,0,strlen(s)) {
                if(t[s[i]-48][4]) printf("%d", s[i]-48);
                else printf(" ");
                rep(j,0,w-3) printf(" ");
                if(t[s[i]-48][5]) printf("%d ", s[i]-48);
                else printf("  ");
            }
            printf("\n");
        }
        rep(i,0,strlen(s)) {
            if(t[s[i]-48][6]) {
                printf(" ");
                rep(j,0,w-3) printf("%d", s[i]-48);
                printf("  ");
            } else {
                rep(j,0,w) printf(" ");
            }
        }
        printf("\n");
    }
}