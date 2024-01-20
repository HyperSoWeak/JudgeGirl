#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define MAXN 2005
 
void dividePolynomial(int f[], int g[]) {
    int q[MAXN], qi=0;
    int fl=f[0]+1, gl=g[0]+1;
    rep1(i,1,fl-gl+1) {
        q[qi] = f[i] / g[1];
        rep(j,1,gl) f[i+j] -= g[1+j]*q[qi];
        qi++;
    }
    int fi=fl-gl+2;
    while(f[fi]==0) fi++;
    g[0] = fl-fi;
    if(g[0]<0) {
        g[0] = 0;
        g[1] = 0;
    } else rep(i,0,g[0]+1) g[i+1] = f[fi+i];
    f[0] = qi-1;
    rep(i,0,qi) f[i+1] = q[i];
}