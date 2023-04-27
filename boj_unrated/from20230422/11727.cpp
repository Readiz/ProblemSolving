#include <bits/stdc++.h>
using namespace std;

int DP[1001] = {0, 1, 3};

int main() {
    int N;
    scanf("%d", &N);

    for(int i = 3; i <= N; ++i) {
        DP[i] = DP[i-1] + (DP[i-2] << 1);
        DP[i] %= 10007;
    }

    printf("%d\n", DP[N]);

    return 0;
}