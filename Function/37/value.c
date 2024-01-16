#include "value.h"
 
int gcd(int x, int y) {
    while(x%y != 0) {
        int r = x%y;
        x = y;
        y = r;
    }
    return y;
}
 
int value(int type, int width, int height, int length) {
    int p;
    switch(type) {
        case 79: p = 30; break;
        case 47: p = 10; break;
        case 29: p = 4; break;
        case 82: p = 5; break;
        case 26: p = 3; break;
        case 22: p = 9; break;
        default: return -1;
    }
    if(width<=0 || height<=0 || length<=0) return -2;
    int r = gcd(width, gcd(height, length));
    return r*r*r*p*width*height*length;
}