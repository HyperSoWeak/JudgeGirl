#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
 
void prepare_array(int buffer[], int *array[], int row, int column[]) {
    int idx = 0;
    rep(i,0,row) {
        array[i] = &buffer[idx];
        idx += column[i];
    }
}