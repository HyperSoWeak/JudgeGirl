#include "fraction.h"
#define LL long long
 
LL gcd(LL a, LL b) {
    while(a%b != 0) {
        LL r = a % b;
        a = b;
        b = r;
    }
    return b;
}
 
Frac simp(Frac x) {
    int r = gcd(x.a, x.b);
    x.a /= r;
    x.b /= r;
    return x;
}
 
Frac normal(LL a, LL b) {
    int r = gcd(a, b);
    Frac ans = {
        .a = a / r,
        .b = b / r,
    };
    return ans;
}
 
Frac add(Frac x, Frac y) {
    Frac ans = {
        .a = x.a*y.b + x.b*y.a,
        .b = x.b*y.b,
    };
    return simp(ans);
}
 
Frac subtract(Frac x, Frac y) {
    y.a *= -1;
    return add(x, y);
}
 
Frac multipy(Frac x, Frac y) {
    Frac ans = {
        .a = x.a*y.a,
        .b = x.b*y.b,
    };
    return simp(ans);
}
 
Frac divide(Frac x, Frac y) {
    int tmp = y.a;
    y.a = y.b;
    y.b = tmp;
    return multipy(x, y);
}