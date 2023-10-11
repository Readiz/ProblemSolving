#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int N, K; scanf("%d%d", &N, &K);    
    priority_queue<int> pq[12];
    for(int i = 0; i < N; ++i) {
        int a, b; scanf("%d%d", &a, &b);
        pq[a].push(b);
    }
    for(int k = 0; k < K; ++k) {
        for(int p = 1; p <= 11; ++p) {
            if (pq[p].size()) {
                int t = pq[p].top(); pq[p].pop();
                if (t > 1) {
                    pq[p].push(--t);
                }
            }
        }
    }
    int ans = 0;
    for(int p = 1; p <= 11; ++p) {
        if (pq[p].size()) {
            ans += pq[p].top();
        }
    }
    printf("%d\n", ans);
    return 0;
}