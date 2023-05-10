#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit() { freopen("C_input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif
#define MAX_SIZE 100000

int Stack[MAX_SIZE] = {0, };
int StackSize = 0;
void push(int num) {
    Stack[StackSize++] = num;
}
int pop() {
    return Stack[--StackSize];
}

int N, M;
int K;
int friendUsedCount[MAX_SIZE] = {0, };

class Friend {
    bool* available;
public:
    Friend() {
    }
    void init(int size) {
        available = new bool[size];
    }
    void deinit() {
        delete[] available;
    }
    void addDays(int day) {
        available[day] = true;
    }
    bool isAvaliable(int day) {
        return available[day];
    }
};

bool DFS(int days, Friend friends[]) {
    if (days == M) return true;

    for (int i = 0; i < N; i++) {
        if (friendUsedCount[i] + 1 < M / 2 && friends[i].isAvaliable(days)) {
            push(i);
            friendUsedCount[i]++;
            bool r = DFS(days + 1, friends);
            if (r) {
                return true;
            }
            friendUsedCount[i]--;
            pop();
        }
    }

    return false;
}

bool DFSStart(Friend friends[]) {
    for (int i = 0; i < N; i++) {
        if (friendUsedCount[i] + 1 < M / 2 && friends[i].isAvaliable(0)) {
            push(i);
            friendUsedCount[i]++;
            bool r = DFS(1, friends);
            if (r) {
                return true;
            }
            friendUsedCount[i]--;
            pop();
        }
    }
    return false;
}

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    int tc;
    scanf("%d", &tc);
    for (int TC = 0; TC < tc; TC++) {
        StackSize = 0;
        scanf("%d %d", &N, &M);
        Friend* friends = new Friend[N];
        for (int j = 0; j < N; j++) {
            friends[j].init(M);
            friendUsedCount[j] = 0;
        }
        for (int j = 0; j < M; j++) {
            scanf("%d", &K);
            for (int i = 0; i < K; i++) {
                int tmp;
                scanf("%d", &tmp);
                friends[tmp - 1].addDays(j);
            }
        }
        bool r = DFSStart(friends);
        if (r) {
            printf("YES\n");
            for (int i = 0; i < StackSize; i++) {
                printf("%d ", Stack[i] + 1);
            }
            printf("\n");
        } else {
            printf("NO\n");
        }
        for (int j = 0; j < N; j++) {
            friends[j].deinit();
        }
        delete[] friends;
    }
    return 0;
MAIN_END
