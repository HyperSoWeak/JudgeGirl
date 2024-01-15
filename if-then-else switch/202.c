#include<stdio.h>
 
int abs(int x) { return x<0 ? -x : x; }
 
int gcd(int a, int b) {
    while(a%b != 0) {
        int r = a%b;
        a = b;
        b = r;
    }
    return abs(b);
}
 
int main() {
    /*
    int a, b;
    while(scanf("%d%d", &a, &b)) {
        printf("%d\n", gcd(a, b));
    }
    */
 
    int a,b,c,d,e,f,g,x,y,z;
    scanf("%d %d %d %d %d %d %d",&a,&b,&c,&d,&e,&f,&g);
    int b2 = a>0 ? a*c+b : a*c-b;
    int f2 = e>0 ? e*g+f : e*g-f;
    switch(d) {
        case 0: //add
            y = b2*g + f2*c;
            z = c*g;
            break;
        case 1: //subtract
            y = b2*g - f2*c;
            z = c*g;
            break;
        case 2: //multiply
            y = b2*f2;
            z = c*g; 
            break;
        case 3: //divide
            y = b2*g;
            z = c*f2;
            break;
    }
    y = y>0&&z>0 || y<0&&z<0 ? abs(y) : -abs(y);
    z = abs(z);
    //printf("test: %d, %d\n", y, z);
    // simplify
    int r = abs(gcd(y,z));
    y/=r; z/=r;
    x = y/z;
    y = abs(y%z);
    if(y == 0) z = 1;
 
    printf("%d\n%d\n%d", x, y, z);
}
 
//    y
// x ---
//    z