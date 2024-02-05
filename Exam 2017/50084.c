#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define rep1(i,a,b) for(int i=(a); i<=(b); ++i)
#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))
#define ll long long
#define oo 1e9
#define MAXJ 505
#define MAXM 505
 
signed main() {
    int M, J, Jready[MAXJ], numTask[MAXJ], totalTask=0;
    int machine[MAXJ][505], time[MAXJ][505];
    scanf("%d%d", &M, &J);
    rep(j,0,J) {
        scanf("%d%d", &Jready[j], &numTask[j]);
        rep(t,0,numTask[j]) scanf("%d%d", &machine[j][t], &time[j][t]);
        totalTask += numTask[j];
    }
    int curTask[MAXJ] = {0};
    int Mready[MAXM] = {0};
    rep(t,0,totalTask) {
        int minTime=oo, minJob=-1, minMachine=-1;
        rep(j,0,J) {
            if(curTask[j] >= numTask[j]) continue;
            int task = curTask[j];
            int endTime = max(Mready[machine[j][task]], Jready[j]) + time[j][task];
            if(endTime < minTime) {
                minTime = endTime;
                minJob = j;
                minMachine = machine[j][task];
            }
        }
        Jready[minJob] = minTime;
        Mready[minMachine] = minTime;
        curTask[minJob]++;
    }
    rep(j,0,J) printf("%d\n", Jready[j]);
}