#include <stdbool.h>
 
bool isOnSale(int ID, int onSaleItemID[]) {
    for(int i=0; onSaleItemID[i]!=0; ++i) {
        if(onSaleItemID[i] == ID) return true;
    }
    return false;
}
 
int findIdx(int ID, int itemID[]) {
    for(int i=0; itemID[i]!=0; ++i) {
        if(itemID[i] == ID) return i;
    }
    return -1;
}
 
double payment(int itemID[], double price[], int orderItemID[], int orderQuantity[], int onSaleItemID[]) {
    double total = 0;
    for(int i=0; orderItemID[i]!=0; ++i) {
        int ID = orderItemID[i];
        int idx = findIdx(ID, itemID);
        if(idx == -1) continue;
        double p = price[idx];
        if(isOnSale(ID, onSaleItemID)) p *= 0.8;
        total += p * orderQuantity[i];
    }
    if(total < 490.0) total += 80.0;
    return total;
}