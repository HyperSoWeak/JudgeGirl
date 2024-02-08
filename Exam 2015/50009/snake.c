int snake(int *ptr, int *row, int *column) {
    int c = 1;
    ptr++;
    while(*(ptr-1) == (*ptr)-1) {
        c++;
        ptr++;
    }
 
    if(*ptr == 0) { // row = 1
        *row = 1;
        *column = c;
        return 1;
    }
 
    *column = c, c = 0;
    int r = 1;
    while(*ptr != 0) {
        int num;
        if(r%2 == 0) num = r * (*column) + c;
        else num = (r+1) * (*column) - 1 - c;
 
        if(*ptr != num) { // err
            *row = r;
            *column = (r%2) ? *column-1-c : c;
            return 0;
        }
 
        c++;
        if(c == *column) {
            c = 0;
            r++;
        }
        ptr++;
    }
 
    if(c != 0) { // err
        *row = r;
        *column = (r%2) ? *column-1-c : c;
        return 0;
    }
 
    *row = r;
    return 1;
}