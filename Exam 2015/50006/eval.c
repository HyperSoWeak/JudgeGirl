#define OperatorErr -2147483646
#define DivByZeroErr -2147483647
 
int eval(int exp[]) {
    int n = exp[0];
    int ans = 0, num, op = 1;
    int i = 1;
    while(i <= n) {
        num = exp[i++];
        while(i <= n && exp[i] >= 3) {
            if(exp[i] > 4) return OperatorErr;
            if(exp[i++] == 3) num *= exp[i++];
            else {
                if(exp[i] == 0) return DivByZeroErr;
                num /= exp[i++];
            }
        }
        if(op == 1) ans += num;
        else if(op == 2) ans -= num;
        else return OperatorErr;
        if(i <= n) op = exp[i++];
    }
    return ans;
}