#include <stdio.h>
#include "complex.h"
 
void init(complex *c, float a, float b) {
    c->re = a;
    c->im = b;
}
 
void complex_print(complex *x) {
    printf("%.3f", x->re);
    if(x->im >= 0) printf("+");
    printf("%.3fi\n", x->im);
}
 
complex complex_add(complex *x, complex *y) {
    complex ans = {
        .re = x->re + y->re,
        .im = x->im + y->im,
    };
    return ans;
}
 
complex complex_sub(complex *x, complex *y) {
    complex ans = {
        .re = x->re - y->re,
        .im = x->im - y->im,
    };
    return ans;
}
 
complex complex_mul(complex *x, complex *y) {
    complex ans = {
        .re = x->re * y->re - x->im * y->im,
        .im = x->re * y->im + x->im * y->re,
    };
    return ans;
}