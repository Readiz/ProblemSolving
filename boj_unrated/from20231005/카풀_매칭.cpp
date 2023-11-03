#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define X first
#define Y second

void solve() {
    int N, M; scanf("%d %d", &N, &M); // N: 승객, M: 기사
    vector<int> to(N);
    for(auto& item: to) scanf("%d", &item);
    vector<pair<int,int>> can(M);
    for(auto& item: can) scanf("%d %d", &item.X, &item.Y);
    sort(to.begin(), to.end());
    sort(can.begin(), can.end());

    priority_queue<int, vector<int>, greater<>> pq;
    int can_idx = 0;
    int ans = 0;
    for(auto& t: to) {
        for(; can_idx < M; ++can_idx) {
            if (can[can_idx].X <= t) {
                pq.push(can[can_idx].Y);
            } else {
                break;
            }
        }
        while(pq.size() && pq.top() < t) pq.pop();
        if (pq.size()) {
            pq.pop();
            ++ans;
        }
    }
    printf("%d\n", ans);
}

int main() {
    int TC; scanf("%d", &TC);
    while(TC--) solve();   

    return 0;
}