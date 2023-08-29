#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int TG; scanf("%d", &TG);
    int N; scanf("%d", &N);
    vector<int> cost(N+1);
    vector<int> guest(N+1);

    for(int i = 1; i <= N; ++i) scanf("%d %d", &cost[i], &guest[i]);

    int DP[100001] = {0, };
    for(int i = 1; i <= N; ++i) {
        for(int c = cost[i]; c <= 100000; ++c) {
            DP[c] = max(DP[c], DP[c - cost[i]] + guest[i]);
        }
    }
    for(int c = 0; c <= 100000; ++c) {
        if (DP[c] >= TG) {
            printf("%d\n", c);
            return 0;
        }
    }
    printf("-1\n");

    return 0;
}