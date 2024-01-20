#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
 
int main() {
    char s[1024];
    while(scanf("%s", s) != EOF) {
        int len = strlen(s);
        int n = 0, f = 0;
        for(int i=0; i<len; ++i) {
            if(isdigit(s[i])) {
                f = 1;
                n = n*10+s[i]-'0';
            } else if(f) {
                printf("%d\n", n);
                n = 0, f = 0;
            }
        }
        if(f) printf("%d\n", n);
    }
}