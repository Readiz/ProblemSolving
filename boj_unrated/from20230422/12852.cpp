#include <bits/stdc++.h>
using namespace std;

int DP[1'000'001];
int Prev[1'000'001];
int main() {
    int N;
    scanf("%d", &N);

    if (N == 1) {
        printf("0\n1\n");
        return 0;
    }

    Prev[N] = N;
    DP[N] = 0;
    if (N % 3 == 0) {
        DP[N/3] = 1;
        Prev[N/3] = N;
    }
    if (N % 2 == 0) {
        DP[N/2] = 1;
        Prev[N/2] = N;
    }
    DP[N-1] = 1;
    Prev[N-1] = N;

    for(int i = N-1; i >= 2; --i) {
        if (DP[i] == 0) continue;
        int cStep = DP[i];
        if (i % 3 == 0) {
            if (DP[i/3] == 0 || cStep + 1 < DP[i/3]) {
                DP[i/3] = cStep + 1;
                Prev[i/3] = i;
            }
        }
        if (i % 2 == 0) {
            if (DP[i/2] == 0 || cStep + 1 < DP[i/2]) {
                DP[i/2] = cStep + 1;
                Prev[i/2] = i;
            }
        }
        if (DP[i-1] == 0 || cStep + 1 < DP[i-1]) {
            DP[i-1] = cStep + 1;
            Prev[i-1] = i;
        }
    }

    printf("%d\n", DP[1]);

    int i = 1;
    stack<int> S;
    while(Prev[i] != i) {
        S.push(i);
        i = Prev[i];
    }
    S.push(i);

    while(S.size()) {
        printf("%d ", S.top());
        S.pop();
    }
    printf("\n");

    return 0;
}