#include "book.h"
#include "date.h"
 
int isLeap(int year) {
    return (year%4==0 && year%100!=0) || year%400==0;
}
 
int days(struct Date a) {
    int d[13] = {0,31,0,31,30,31,30,31,31,30,31,30,31};
    d[2] = isLeap(a.year) ? 29 : 28;
 
    int ans = 0;
    for(int y=1000; y<a.year; y++) {
        if(isLeap(y)) ans += 366;
        else ans += 365;
    }
 
    for(int m=1; m<a.month; m++) ans += d[m];
    ans += a.day;
 
    return ans;
}
 
int daysBtw(struct Date a, struct Date b) {
    return days(b) - days(a) + 1;
}
 
int typeToDays(enum Type t) {
    switch (t) {
        case NOVEL:    return 90;
        case COMICS:   return 10;
        case MANUAL:   return 100;
        case TEXTBOOK: return 5;
    }
}
 
int X(unsigned int n) {
    while((n&1)==0) n>>=1;
    n>>=1;
    int cnt = 0;
    while((n&1)==0) {
        n>>=1;
        cnt++;
    }
    return cnt;
}
 
int library_fine(struct Book book, struct Date date_borrowed, struct Date date_returned) {
    int days = daysBtw(date_borrowed, date_returned);
    int limit = typeToDays(book.type);
    if(days <= limit) return 0;
    else return (days-limit) * X(book.importance);
}