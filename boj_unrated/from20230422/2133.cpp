#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll DP[31];

int main() {

    DP[0] = 1;
    DP[2] = 3;
    DP[4] = 11;

    int N;
    scanf("%d", &N);
    if (N == 0) {
        printf("0\n");
        return 0;
    }

    for(int n = 6; n <= N; n+=2) {
        DP[n] = DP[n-2] * 3;
        for(int d = 4; n - d >= 0; d+=2) {
            DP[n] += DP[n-d] * 2;
        }
    }

    printf("%lld\n", DP[N]);

    return 0;
}