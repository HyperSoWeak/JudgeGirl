#include <stdbool.h>
#define rep(i,a,b) for(int i=a; i<b; ++i)
 
bool isLeap(int y) {
    return (y%4 == 0 && y%100 != 0) || y%400 == 0;
}
 
void count_day(int year, int day, int month, int results[7]) {
    int d[13] = {0,31,0,31,30,31,30,31,31,30,31,30,31};
    if(isLeap(year)) d[2] = 29;
    else d[2] = 28;
    rep(i,1,month) day += d[i];
    day %= 7;
    rep(i,0,d[month]) results[(day+i)%7]++;
}