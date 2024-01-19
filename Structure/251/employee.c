#include "employee.h"
 
int relation(Employee *employee1, Employee *employee2) {
    Employee *e = employee1;
    Employee *isBoss[32];
    int n = 0;
 
    while(e->boss != e) {
        e = e->boss;
        if(e == employee2) return 1;
    }
 
    e = employee2;
    while(e->boss != e) {
        e = e->boss;
        isBoss[n++] = e;
        if(e == employee1) return 2;
    }
 
    e = employee1;
    while(e->boss != e) {
        e = e->boss;
        for(int i=0; i<n; i++) if(isBoss[i] == e) return 3;
    }
 
    return 4;
}