#include <bits/stdc++.h>
using namespace std;

int DP[10][1001];
int main() {
    int N;
    scanf("%d", &N);

    for(int i = 0; i < 10; ++i) {
        DP[i][0] = 1;
    }

    for(int n = 1; n <= N; ++n) {
        for(int K = 0; K < 10; ++K) { // n번째 수가 K일 때 수 세기
            int& T = DP[K][n];
            for(int k = 0; k <= K; ++k) {
                T += DP[k][n - 1];
            }
            T %= 10007;
        }
    }

    printf("%d\n", DP[9][N]);
    return 0;
}