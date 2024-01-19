#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) (a)>(b) ? (a) : (b)
#define min(a,b) (a)<(b) ? (a) : (b)
#define ll long long
#define oo 1e9
 
typedef struct Food {
    char name[70];
    int len;
    char ing[10][70];
} Food;
 
int cmp(const void *a, const void *b) {
    const char *aa = (const char *)a;
    const char *bb = (const char *)b;
    return strcmp(aa, bb);
}
 
signed main() {
    Food f[100];
    int n, m;
    char a[70], b[70];
    scanf("%d", &n);
    rep(i,0,n) {
        scanf("%s %d", f[i].name, &f[i].len);
        rep(j,0,f[i].len) scanf("%s", f[i].ing[j]);
        qsort(f[i].ing, f[i].len, sizeof(f[i].ing[0]), cmp);
    }
    scanf("%d", &m);
    while(m--) {
        scanf("%s %s", a, b);
        int i1 = 0, i2 = 0;
        for(; i1<n; ++i1) if(strcmp(f[i1].name, a) == 0) break;
        for(; i2<n; ++i2) if(strcmp(f[i2].name, b) == 0) break;
        int idx = 0, a[10];
        rep(i,0,f[i1].len) {
            rep(j,0,f[i2].len) {
                if(strcmp(f[i1].ing[i], f[i2].ing[j]) == 0) {
                    a[idx++] = i;
                    break;
                }
            }
        }
        if(idx == 0) printf("nothing\n");
        else rep(i,0,idx) printf("%s%c", f[i1].ing[a[i]], " \n"[i==idx-1]);
    }
}