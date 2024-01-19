#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))
#define ll long long
#define oo 1e9
#define MAXLEN 128
 
int abs(int x) { return x < 0 ? -x : x; }
 
signed main() {
    char a[MAXLEN], b[MAXLEN];
    int n;
    scanf("%d", &n);
    while(n--) {
        scanf("%s%s", a, b);
        int la = strlen(a);
        int lb = strlen(b);
        if(abs(la-lb) >= 2) {
            printf("no\n");
            continue;
        }
        if(strcmp(a, b) == 0) {
            printf("yes\n");
            continue;
        }
 
        bool yes = true;
        if(la == lb) {
            bool happened = false;
            rep(i,0,la) {
                if(a[i]!=b[i]) {
                    if(happened) {
                        yes = false;
                        break;
                    }
                    if(a[i]==b[i+1] && a[i+1]==b[i]) {
                        happened = true;
                        i++;
                    } else {
                        yes = false;
                        break;
                    }
                }
            }
        } else {
            int happened = 0;
            if(la > lb) {
                rep(i,0,lb) {
                    if(a[i+happened] != b[i]) {
                        if(happened) {
                            yes = false;
                            break;
                        } else {
                            happened = 1;
                            if(a[i+happened] != b[i]) {
                                yes = false;
                                break;
                            }
                        }
                    }
                }
            } else {
                rep(i,0,la) {
                    if(b[i+happened] != a[i]) {
                        if(happened) {
                            yes = false;
                            break;
                        } else {
                            happened = 1;
                            if(b[i+happened] != a[i]) {
                                yes = false;
                                break;
                            }
                        }
                    }
                }
            }   
        }
 
        if(yes) printf("yes\n");
        else printf("no\n");
    }
}