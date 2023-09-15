#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int N; scanf("%d", &N);
    vector<int> v(N+1);
    for(int i = 1; i <= N; ++i) scanf("%d", &v[i]);

    // Knapsack
    int DP[1001] = {0,}; // 카드 i개 샀을 때 최대 가격
    for(int i = 1; i <= N; ++i) {
        for(int j = i; j <= N; ++j) {
            DP[j] = max(DP[j], DP[j - i] + v[i]);
        }
    }

    printf("%d\n", DP[N]);
    return 0;
}