#include <bits/stdc++.h>
using namespace std;

int A[100010];
int main() {
    int N, K; scanf("%d %d", &N, &K);
    long long pSum = 0;
    for(int i = 0, j = 0; i < N; ++i, ++j) {
        scanf("%d", &A[i]);
        if (j < K) pSum += A[i];
    }
    long long maxSum = pSum;
    for(int i = K; i < N; ++i) {
        pSum -= A[i - K];
        pSum += A[i];
        if (pSum > maxSum) maxSum = pSum;
    }

    printf("%lld", maxSum);

    return 0;
}