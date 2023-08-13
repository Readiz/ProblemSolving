#include <bits/stdc++.h>
using namespace std;

int A[100000];
int main() {
    int N, K; scanf("%d %d", &N, &K);
    for(int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    int cur = 0;
    for(int i = 0; i < K; ++i) {
        cur += A[i];
    }
    int last = 0;
    int max = cur;
    for(int i = 1; i < N - K + 1; ++i) {
        cur = cur + A[i + K - 1] - A[last];
        if (max < cur) max = cur;
        last++;
    }
    printf("%d\n", max);

    return 0;
}