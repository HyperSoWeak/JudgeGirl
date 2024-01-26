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
#define ERR 2e9+7
#define MAXC 5000
 
typedef struct Queue {
    int size;
    int capacity;
    int head;
    int tail;
    int elements[MAXC];
} Queue;
 
bool QisEmpty(const Queue *q) {
    return q->size == 0;
}
 
int Qfront(const Queue *q) {
    if(QisEmpty(q)) return ERR;
    return q->elements[q->head];
}
 
bool Qpop(Queue *q) {
    if(QisEmpty(q)) return false;
    q->head = (q->head + 1) % q->capacity;
    q->size -= 1;
    return true;
}
 
void Qpush(Queue *q, int data) {
    if(QisEmpty(q)) {
        q->tail = q->head;
        q->size += 1;
        q->elements[q->tail] = data;
        return;
    }
    q->tail = (q->tail + 1) % q->capacity;
    q->size += 1;
    q->elements[q->tail] = data;
}
 
signed main() {
    Queue q[3];
    rep(i,0,3) q[i].capacity = MAXC;
    int x;
    while(scanf("%d", &x) != EOF) {
        Qpush(&q[x%3], x);
        if(q[0].size >= 3 && q[1].size >= 1 && q[2].size >= 1) {
            rep(i,0,3) {
                printf("%d ", Qfront(&q[0]));
                Qpop(&q[0]);
            }
            printf("%d %d\n", Qfront(&q[1]), Qfront(&q[2]));
            Qpop(&q[1]);
            Qpop(&q[2]);
        }
    }
}