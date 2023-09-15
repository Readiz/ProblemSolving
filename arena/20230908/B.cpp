

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int N, M; scanf("%d%d", &N, &M);    
    vector<int> A(N);
    vector<int> B(M);
    for(int i = 0; i < N; ++i) scanf("%d", &A[i]);
    for(int i = 0; i < M; ++i) scanf("%d", &B[i]);
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int cntA = 1, cntB = 1;
    int lastA = A[0]; int lastB = B[0];
    for(int i = 1; i < N; ++i) {
        if (A[i] - lastA >= 100) {
            cntA++;
            lastA = A[i];
        }
    }
    for(int i = 1; i < M; ++i) {
        if (B[i] - lastB >= 360) {
            cntB++;
            lastB = B[i];
        }
    }
    printf("%d %d\n", cntA, cntB);
    return 0;
}