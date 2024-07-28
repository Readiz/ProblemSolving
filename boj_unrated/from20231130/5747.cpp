#include <bits/stdc++.h>
using namespace std;

int N;
int A[100];
int B[100];

void solve() {
    for(int i = 0; i < N; ++i) scanf("%d", &A[i]);
    for(int i = 0; i < N; ++i) scanf("%d", &B[i]);
    int oddA = 0, evenA = 0;
    int oddB = 0, evenB = 0;
    for(int i = 0; i < N; ++i) {
        if (A[i] % 2 == 0) ++evenA;
        else ++oddA;
        if (B[i] % 2 == 0) ++evenB;
        else ++oddB;
    }
    // 짝수에 홀수를 매핑시킨다.
    int v1 = min(oddA, evenB);
    oddA -= v1;
    evenB -= v1;
    int v2 = min(oddB, evenA);
    oddB -= v2;
    evenA -= v2;
    // odd + odd 최소
    // even + even 최소
    // odd + even 최대
    printf("%d\n", oddA + evenA);
}

int main() {
    while(true) {
        scanf("%d", &N);
        if (N == 0) break;
        solve();
    }

    return 0;
}