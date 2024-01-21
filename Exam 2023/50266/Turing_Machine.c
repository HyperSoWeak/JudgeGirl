void Turing_Machine(int *head, int K) {
    int state = 0;
    int trans[3][4] = {
        {2,1,2,1},
        {2,0,2,0},
        {1,0,1,0},
    };
    int moves[3][4] = {
        {1,1,1,1},
        {-1,1,-1,1},
        {0,-1,1,0},
    };
    while(K--) {
        int value = *head;
        *head = (state + value) % 4;
        head += moves[state][value];
        state = trans[state][value];
    }
}