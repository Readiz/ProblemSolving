#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

struct Problem {
    int t;
    int cost;
};

int main() {
    int N, T; scanf("%d%d", &N, &T);
    vector<Problem> problems(N+1);
    int sumCost = 0;
    for(int i = 1; i <= N; ++i) {
        int a, b; scanf("%d %d", &a, &b);
        problems[i].t = a;
        problems[i].cost = b;
        sumCost += b;
    }

    int DP[1001] = {0, }; // i일 동안 문제를 풀었을 때 최대로 면한 벌금액
    
    int maxCost = 0;
    for(int i = 1; i <= N; ++i) {
        for(int j = T; j >= problems[i].t; --j) {
            DP[j] = max(DP[j], DP[j - problems[i].t] + problems[i].cost);
            maxCost = max(maxCost, DP[j]);
        }
    }
    printf("%d\n", sumCost - maxCost);

    return 0;
}