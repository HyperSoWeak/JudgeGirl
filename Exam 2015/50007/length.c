#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
int toInch(int length[3]) {
    return length[0]*36 + length[1]*12 + length[2];
}
void toLength(int length[3], int inch) {
    length[0] = inch/36;
    length[1] = (inch%36)/12;
    length[2] = inch%12;
}
void init(int length[3]) {
    rep(i,0,3) length[i] = 0;
}
void add(int length[3], int i) {
    toLength(length, toInch(length)+i);
}
void sum(int lengtha[3], int lengthb[3], int lengthc[3]) {
    toLength(lengthc, toInch(lengtha)+toInch(lengthb));
}
void diff(int lengtha[3], int lengthb[3], int lengthc[3]) {
    toLength(lengthc, toInch(lengtha)-toInch(lengthb));
}