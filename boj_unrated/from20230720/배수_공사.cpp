#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int N, X; scanf("%d %d", &N, &X);
    int len[101] = {0, };
    int capa[101] = {0, };
    for(int i = 1; i <= N; ++i) scanf("%d %d", &len[i], &capa[i]);
    
    assert(X <= 10000);
    assert(N <= 100);

    ll DP[101][10001] = {0, }; // i번째 파이프까지 썼을때 길이 j에서의 경우의 수
    for(int i = 1; i <= N; ++i) {
        for(int k = 1; k <= capa[i]; ++k) {
            if (k*len[i] <= X) {
                DP[i][k*len[i]] += 1;
            } else {
                break;
            }
        }
        for(int j = 0; j <= X; ++j) {
            DP[i][j] += DP[i-1][j];
            for(int k = 1; k <= capa[i]; ++k) {
                if (j - k*len[i] >= 0) {
                    DP[i][j] += DP[i-1][j - k*len[i]];
                } else {
                    break;
                }
            }
        }
    }
    printf("%lld\n", DP[N][X]);

    return 0;
}