#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[8];
int P[8];
int last[8];

void dfs(int cur, int selcnt) {
    if (selcnt == M) {
        int flag = true;
        for(int i = 0; i < M; ++i) {
            if (P[i] != last[i]) {
                flag = false;
                break;
            }
        }
        if (flag) return;
        for(int i = 0; i < M; ++i) {
            printf("%d ", P[i]);
            last[i] = P[i];
        }
        printf("\n");
        return;
    }

    for(int i = cur; i < N; ++i) {
        P[selcnt] = A[i];
        dfs(cur, selcnt + 1); // 선택 case
        // dfs(cur, selcnt); // 선택 x case
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; ++i) scanf("%d", &A[i]);
    sort(A, A + N);

    dfs(0, 0);


    return 0;
}